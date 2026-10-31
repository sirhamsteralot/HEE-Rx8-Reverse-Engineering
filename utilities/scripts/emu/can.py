"""RCAN (HCAN) peripheral model for the SH7055 + virtual bus hookup.

Register map per reverse-engineered/decompiled/<rom>/symbols.tsv (HCAN0 block at
0xffffe400, HCAN1 at 0xffffe600) and the firmware's own mailbox helpers:
- FUN_0000cee8 (mailbox register address: +0x200 for mb > 0x1f = HCAN1)
- FUN_0000cf12 (mailbox bitmask = ROM table at 0xd914 = 1 << ((mb+8) & 0xf))
- ref_HCANRegisterInit__ (0xcb42): pending regs are write-1-to-clear
  (writes TXACK=0xfeff, RXPR=0xffff, RFPR=0xffff, UMSR=0xffff, IRR=0xff13)
- FUN_00001e94/0x1eb2 + 0x9c0/0x9de: MCR bit0 (reset) handshake with GSR bit3
- FUN_000010fe: RXPR bit set -> if UMSR bit clear, clear RXPR and copy MD out
- ref_txCAN_EventBased (0x99b0): TXACK=mask, payload -> MD, TXPR=mask (request)

The ROM's own CAN driver runs in emulation; this peripheral models the mailbox
registers it touches and provides:
- inject(can_id, data): a frame "from the car/tester" into the matching RX
  mailbox (ID field in MC[4..7]), setting RXPR/RFPR/IRR like hardware.
- tx_log: every frame the firmware transmits (a TXPR write moves the mailbox
  payload out and sets TXACK), e.g. UDS responses on 0x7e8.

Register-level fidelity is refined against Sh7055h.pdf as needed; unknown
reads return the stored value and are logged for triage.
"""
from peripherals import RegisterFile


def mailbox_mask(mb):
    """Bit of RXPR/TXPR/... for mailbox mb — matches ROM table at 0xd914."""
    return 1 << ((mb + 8) & 0xF)


class CANController(RegisterFile):
    # register offsets within the 0x200 block (HCAN0 at 0xffffe400)
    MCR, GSR, BCR = 0x00, 0x01, 0x02
    MBCR, TXPR, TXCR, TXACK, ABACK, RXPR, RFPR, IRR, MBIMR, IMR = (
        0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x12, 0x14, 0x16)
    REC, TEC, UMSR, LAFML, LAFMH = 0x18, 0x19, 0x1A, 0x1C, 0x1E
    MC_BASE, MD_BASE = 0x20, 0xB0  # 8 bytes per mailbox
    W1C16 = (TXACK, ABACK, RXPR, RFPR, UMSR)  # write-1-to-clear 16-bit pending regs

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.diag_req = int(str(self.config.get("diag_req", "0x7e0")), 0)
        self.diag_resp = int(str(self.config.get("diag_resp", "0x7e8")), 0)
        self.rx_irq_bit = int(str(self.config.get("rx_irq_bit", "0x01")), 0)  # IRR bit for RX
        self.tx_log = []      # (cycle, can_id, data)
        self.rx_frames = []   # frames injected from outside
        # power-on reset state: CAN in reset mode (MCR bit0=1, GSR bit3=1)
        self.regs[self.MCR] = 0x01
        self.regs[self.GSR] = 0x08

    # -- mailbox helpers --
    def _mc(self, mb):
        return self.MC_BASE + (mb & 0x1F) * 8

    def _md(self, mb):
        off = self.MD_BASE + (mb & 0xF) * 8
        return off + 0x200 if mb > 0x1F else off  # mb > 0x1f lands in HCAN1 block

    def _mailbox_id(self, mb):
        """Mailbox ID from MC[4..7]. FUN_00001ed0 (0x1ed0) stores a standard ID
        as MC[4] = (id<<5) & 0xff, MC[5] = (id<<5) >> 8 (byte pair, low first);
        extended: MC[4..7] hold the 29-bit ID per param_5 packing."""
        o = self._mc(mb)
        ext = self.regs[o + 3] & 0x08
        if ext:
            return int.from_bytes(self.regs[o + 4:o + 8], "big") & 0x1FFFFFFF
        return ((self.regs[o + 5] << 8) | self.regs[o + 4]) >> 5

    def find_rx_mailbox(self, can_id):
        for mb in range(16):
            if self._mailbox_id(mb) == can_id:
                return mb
        return int(str(self.config.get("rx_mailbox", "14")), 0)

    # -- bus interface --
    def read(self, off, size):
        return int.from_bytes(self.regs[off:off + size], "big")

    def write(self, off, size, value):
        value &= (1 << (size * 8)) - 1
        if off == self.MCR:
            self.regs[off:off + size] = value.to_bytes(size, "big")
            # GSR bit3 (0x08) = reset status, follows MCR bit0 (FUN_00001e94/0x1eb2)
            self.regs[self.GSR] = (self.regs[self.GSR] & ~0x08) | (0x08 if value & 1 else 0)
            return
        if off in self.W1C16 and size == 2:
            old = int.from_bytes(self.regs[off:off + 2], "big")
            self.regs[off:off + 2] = (old & ~value & 0xFFFF).to_bytes(2, "big")
            return
        if off == self.IRR and size == 2:
            old = int.from_bytes(self.regs[off:off + 2], "big")
            self.regs[off:off + 2] = (old & ~value & 0xFFFF).to_bytes(2, "big")
            return
        if off == self.TXPR and size == 2:
            old = int.from_bytes(self.regs[off:off + 2], "big")
            for mb in range(16):
                bit = mailbox_mask(mb)
                if value & bit:
                    self._transmit(mb)
            self.regs[off:off + 2] = (old & ~value & 0xFFFF).to_bytes(2, "big")
            return
        self.regs[off:off + size] = value.to_bytes(size, "big")

    def _transmit(self, mb):
        """TXPR bit written: mailbox payload leaves the ECU (UDS response etc.)."""
        mo, do = self._mc(mb), self._md(mb)
        can_id = self._mailbox_id(mb)
        dlc = self.regs[mo] & 0x0F  # MC[0] holds DLC (set by FUN_00001ed0 param_3)
        data = bytes(self.regs[do:do + 8])[:dlc]
        self.note_tx(can_id, data)
        old = int.from_bytes(self.regs[self.TXACK:self.TXACK + 2], "big")
        self.regs[self.TXACK:self.TXACK + 2] = (old | mailbox_mask(mb)).to_bytes(2, "big")

    # -- external bus --
    def inject(self, can_id, data):
        """External frame into the emulated bus (e.g. from the OBD TCP port)."""
        data = bytes(data)
        mb = self.find_rx_mailbox(can_id)
        mo, do = self._mc(mb), self._md(mb)
        self.regs[mo] = len(data) & 0x0F  # MC[0] = DLC
        self.regs[do:do + 8] = data.ljust(8, b"\x00")
        m = mailbox_mask(mb)
        for reg in (self.RXPR, self.RFPR):
            old = int.from_bytes(self.regs[reg:reg + 2], "big")
            self.regs[reg:reg + 2] = (old | m).to_bytes(2, "big")
        old = int.from_bytes(self.regs[self.UMSR:self.UMSR + 2], "big")  # mailbox free
        self.regs[self.UMSR:self.UMSR + 2] = (old & ~m & 0xFFFF).to_bytes(2, "big")
        old = int.from_bytes(self.regs[self.IRR:self.IRR + 2], "big")
        self.regs[self.IRR:self.IRR + 2] = (old | self.rx_irq_bit).to_bytes(2, "big")
        self.rx_frames.append((self.bus.cycle if self.bus else 0, can_id, data))

    def note_tx(self, can_id, data):
        self.tx_log.append((self.bus.cycle if self.bus else 0, can_id, bytes(data)))
