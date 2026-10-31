"""CAN controller peripheral (SH7055 RCAN subset) + virtual bus hookup.

The ROM's own CAN driver runs in emulation; this peripheral models the mailbox
registers it touches (generic register file) and provides:
- inject(can_id, data): a frame "from the car/tester" into the RX mailbox,
  raising the configured RX handler (like the WDT overflow hook).
- tx_log: every frame the firmware transmits (e.g. UDS responses on 0x7E8),
  captured for the OBD port / assertions.

Register-level fidelity is refined against Sh7055h.pdf as needed; unknown
reads return 0 and are logged for triage.
"""
from peripherals import RegisterFile


class CANController(RegisterFile):
    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.diag_req = int(str(self.config.get("diag_req", "0x7e0")), 0)
        self.diag_resp = int(str(self.config.get("diag_resp", "0x7e8")), 0)
        self.rx_handler = self.config.get("rx_handler")  # direct handler addr or None
        self.tx_log = []      # (cycle, can_id, data)
        self.rx_frames = []   # frames injected from outside

    def inject(self, can_id, data):
        """External frame into the emulated bus (e.g. from the OBD TCP port)."""
        self.rx_frames.append((self.bus.cycle if self.bus else 0, can_id, bytes(data)))
        if self.rx_handler and self.bus is not None and hasattr(self.bus, "cpu"):
            self.bus.cpu.pr = self.bus.cpu.pc
            self.bus.cpu.pc = self.rx_handler & 0xFFFFFFFF

    def note_tx(self, can_id, data):
        self.tx_log.append((self.bus.cycle if self.bus else 0, can_id, bytes(data)))
