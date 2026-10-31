"""SH7055 peripheral stubs for the HEE emulator.

Each peripheral is configured from the active profile (base address, size, and a
config dict), so different RX-8 markets/models can instantiate different
peripheral sets (see profiles/). Register maps per docs/references/Sh7055h.pdf;
addresses cross-checked against our own symbols.tsv.
"""


class Peripheral:
    def __init__(self, base, size, config):
        self.base = base
        self.size = size
        self.config = config or {}
        self.bus = None

    def attach(self, bus):
        self.bus = bus

    def read(self, off, size):
        return 0

    def write(self, off, size, value):
        pass

    def tick(self, cycles):
        pass

    def reset(self):
        pass


class RegisterFile(Peripheral):
    """Generic MMIO register file (reads return stored values; writes logged by bus)."""

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.regs = bytearray(size)

    def read(self, off, size):
        return int.from_bytes(self.regs[off:off + size], "big")

    def write(self, off, size, value):
        self.regs[off:off + size] = (value & ((1 << (size * 8)) - 1)).to_bytes(size, "big")


class WDT(Peripheral):
    """SH7055 watchdog: TCSR 0xffffec10, TCNT 0xffffec11, RSTCSR 0xffffec12.

    TCNT counts up each tick; on 0xFF->0x00 wrap, TCSR OVF (0x80) sets and, if
    enabled, the overflow vector fires (config "overflow_vector" = address of the
    vector slot; null = fall back to reset vector). Writes need key 0xA5 in the
    high byte (firmware writes 0xa53c to service)."""

    TCSR, TCNT, RSTCSR = 0, 1, 2

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.tcsr = 0x00
        self.tcnt = 0x00
        self.overflow_vector = self.config.get("overflow_vector")      # vector slot addr
        self.overflow_handler = self.config.get("overflow_handler")    # direct handler addr (0x31c)
        self.enabled = bool(self.config.get("enabled", True))

    def read(self, off, size):
        if off == self.TCSR:
            return self.tcsr
        if off == self.TCNT:
            return self.tcnt
        return 0

    def write(self, off, size, value):
        if size == 1 and (value >> 8 if size == 2 else 0):
            pass
        if off == self.TCSR and size == 1:
            # keyed write arrives as 16-bit 0xA5xx on the word at TCSR; handle both
            pass
        if off == self.TCSR:
            if size == 2 and (value >> 8) == 0xA5:
                low = value & 0xFF
                self.tcsr = low & 0x7F  # OVF (0x80) cleared by writing 0 with key
                if not (low & 0x80):
                    self.tcsr &= 0x7F
            elif size == 1:
                self.tcsr = value & 0x7F
        elif off == self.TCNT:
            if size == 2 and (value >> 8) == 0xA5:
                self.tcnt = value & 0xFF
            elif size == 1:
                self.tcnt = value
        elif off == self.RSTCSR:
            pass

    def tick(self, cycles):
        if not self.enabled:
            return
        for _ in range(cycles):
            self.tcnt = (self.tcnt + 1) & 0xFF
            if self.tcnt == 0:  # wrapped
                self.tcsr |= 0x80  # OVF flag; firmware polls TCSR and calls 0x31c itself
                if self.bus is not None and hasattr(self.bus, "cpu"):
                    if self.overflow_handler is not None:
                        # opt-in direct jump (test harness); 0x31c is a subroutine
                        # (ends rts, clobbers r0-r4) - not a real interrupt entry
                        self.bus.cpu.pr = self.bus.cpu.pc
                        self.bus.cpu.pc = self.overflow_handler & 0xFFFFFFFF
                    elif self.overflow_vector is not None:
                        self.bus.cpu.interrupt(self.overflow_vector)
                    # else: OVF flag only, no PC redirect (real HW: interrupt
                    # acceptance depends on SR mask + IPR; firmware polls)


class GPIO(Peripheral):
    """Port data/direction registers. Writes to the configured heartbeat pin
    (default port B bit 15 = external watchdog heartbeat, see
    service_wdt_overflow_and_toggle_pb15 at 0x31c) are logged as events."""

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.regs = bytearray(size)
        self.heartbeat = self.config.get("heartbeat", {"port_reg_offset": 0x38, "bit": 15})
        self.heartbeats = []  # (cycle, new_value_bit)

    def read(self, off, size):
        return int.from_bytes(self.regs[off:off + size], "big")

    def write(self, off, size, value):
        old = int.from_bytes(self.regs[off:off + size], "big")
        self.regs[off:off + size] = (value & ((1 << (size * 8)) - 1)).to_bytes(size, "big")
        hb = self.heartbeat
        if off <= hb["port_reg_offset"] < off + size:
            bit = 1 << hb["bit"]
            if (old & bit) != (value & bit):
                self.heartbeats.append((self.bus.cycle if self.bus else 0, (value & bit) >> hb["bit"]))


class ADC(Peripheral):
    """SH7055 ADC with scripted per-channel results (sensor injection).

    Register map (symbols.tsv, base 0xfffff800): ADDRnH/L at offset 2n for
    n <= 11, ADCSR0/ADCR0 at 0x18/0x19, ADDR12+ at 0x20+2(n-12), ADCSRn/ADCRn
    at 0x18+0x20n / 0x19+0x20n. The firmware starts a scan (ADCRn |= 0x20),
    busy-waits on ADCSRn bit 7 (ADF), then reads ADDRnH (ref_sensorADCRead
    0x6884; e.g. ADDR3H=MAF, ADDR6H=APV, ADDR10H=knock, ADDR28H=ECT, ADDR29H=IAT).

    Model: ADCRn write with ADST (0x20) schedules the bank; the next tick sets
    ADF in ADCSRn so the busy-wait exits. ADDRn reads return the scripted
    16-bit channel value ("AN<n>" in config.channels), high byte at ADDRnH.
    """

    ADCSR = [0x18, 0x38, 0x58]
    ADCR = [0x19, 0x39, 0x59]

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.regs = bytearray(size)
        self.channels = {k: int(v) & 0xFFFF for k, v in self.config.get("channels", {}).items()}
        self._pending = set()

    @staticmethod
    def addr_off(n):
        """Offset of ADDRnH within the ADC block (symbols.tsv): ADDR0-11 at
        2n, ADCSR0/ADCR0 at 0x18/0x19, ADDR12-23 at 0x20+2(n-12),
        ADCSR1/ADCR1 at 0x38/0x39, ADDR24-31 at 0x40+2(n-24),
        ADCSR2/ADCR2 at 0x58/0x59."""
        if n < 12:
            return 2 * n
        if n < 24:
            return 0x20 + 2 * (n - 12)
        return 0x40 + 2 * (n - 24)

    def _channel_raw(self, n):
        return self.channels.get("AN%d" % n, 0) & 0xFFFF

    def read(self, off, size):
        # ADCSR/ADCR first (their offsets overlap the ADDR numbering)
        if off in self.ADCSR or off in self.ADCR or off + size - 1 in self.ADCSR or off + size - 1 in self.ADCR:
            if 0 <= off < self.size:
                return int.from_bytes(self.regs[off:off + size], "big")
            return 0
        # ADDR result registers serve scripted channel values
        for n in range(32):
            o = self.addr_off(n)
            if off == o:  # ADDRnH (optionally read as word -> full 16-bit result)
                raw = self._channel_raw(n)
                return (raw >> 8) & 0xFF if size == 1 else raw
            if off == o + 1 and size == 1:  # ADDRnL
                return self._channel_raw(n) & 0xFF
        if 0 <= off < self.size:
            return int.from_bytes(self.regs[off:off + size], "big")
        return 0

    def write(self, off, size, value):
        value &= (1 << (size * 8)) - 1
        if 0 <= off < self.size:
            self.regs[off:off + size] = value.to_bytes(size, "big")
        for bank, adcr in enumerate(self.ADCR):
            if off == adcr and (value & 0x20):  # ADST: conversion start
                self._pending.add(bank)

    def tick(self, cycles):
        if self._pending:
            for bank in self._pending:
                self.regs[self.ADCSR[bank]] |= 0x80  # ADF: conversion done
            self._pending.clear()


class ATU2(RegisterFile):
    """ATU-II timer: register file + channel-10B compare tick (CMI10B) + crank
    input capture.

    - tick: when TSTR3 starts ch10 (bit 2) and TCNT10B reaches OCR10B, TSR10
      CMFB (bit 2) sets and, if TIER10 bit 2 is enabled, the tick vector fires
      (config "tick_vector", e.g. 0x2c8 -> CMI10B handler; IVT per Sh7055h.pdf
      table 7.3). This is the OS scheduler tick (ref_setInterruptTimer 0x7778).
    - crank: set_rpm(rpm) drives a virtual crank wheel; each edge captures the
      free-running TCNT10AH into ICR10AH/ICR0AH (the registers the firmware's
      crank path reads: 0x77f0 / 0xcf96). 1 count = 1 cycle (E7: not real time).
    - Injector outputs (DCNT8A-P at 0x40-0x5e, GR1A-H) are plain registers;
      writes are logged by the bus MMIO log (channel map ROM 0xd7d4).
    """

    TSTR1, TSTR2, TSTR3 = 0x00, 0x01, 0x02
    ICR0AH, ICR0AL = 0x34, 0x36
    TCNT10AH, TCNT10AL = 0x2C0, 0x2C2
    TCNT10B = 0x2C4
    ICR10AH, ICR10AL = 0x2D0, 0x2D2
    OCR10AH, OCR10AL = 0x2D4, 0x2D6
    OCR10B = 0x2D8
    TSR10, TIER10 = 0x2E8, 0x2EA
    CH10_TSTR3_BIT = 0x01   # TSTR3 bit0 starts channel 10 (observed TSTR3=0x01 at boot)
    CMFB = 0x04             # TSR10/TIER10 bit 2 = CMI10B

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.tick_vector = self.config.get("tick_vector")  # IVT slot addr or None
        self._tcnt10ah = 0
        self._tcnt10b = 0
        self._crank_period = 0      # cycles between crank edges (0 = stopped)
        self._next_edge = 0
        self.crank_edges = []       # (cycle, captured value)

    def set_rpm(self, rpm):
        # firmware rpm = 1.2e8 / sum(6 periods); 1 count/cycle -> period = 2e7/rpm
        self._crank_period = int(2e7 / rpm) if rpm > 0 else 0
        self._next_edge = (self.bus.cycle if self.bus else 0) + self._crank_period

    def _w16(self, off, v):
        self.regs[off:off + 2] = (v & 0xFFFF).to_bytes(2, "big")

    def _fire(self, vector):
        cpu = getattr(self.bus, "cpu", None)
        if cpu is not None and vector is not None:
            cpu.interrupt(int(str(vector), 0) if isinstance(vector, str) else vector)

    def tick(self, cycles):
        tstr3 = self.regs[self.TSTR3]
        if tstr3 & self.CH10_TSTR3_BIT:
            ocr10b = self.regs[self.OCR10B]
            for _ in range(cycles):
                self._tcnt10b = (self._tcnt10b + 1) & 0xFF
                self._tcnt10ah = (self._tcnt10ah + 1) & 0xFFFF
                if ocr10b and self._tcnt10b >= ocr10b:
                    self._tcnt10b = 0
                    self.regs[self.TSR10] |= self.CMFB
                    if int.from_bytes(self.regs[self.TIER10:self.TIER10 + 2], "big") & self.CMFB:
                        self._fire(self.tick_vector)
        else:
            self._tcnt10ah = (self._tcnt10ah + cycles) & 0xFFFF
        # crank wheel edges -> input capture registers
        if self._crank_period:
            now = self.bus.cycle if self.bus else 0
            while now >= self._next_edge:
                cap = self._tcnt10ah
                self._w16(self.ICR10AH, cap)
                self._w16(self.ICR0AH, cap)
                self.crank_edges.append((now, cap))
                self._next_edge += self._crank_period


class DMAC(Peripheral):
    """SH7055 DMAC (base 0xffffecb0): DMAOR at 0x00, then per channel n:
    SARn at 0x10+0x10n, DARn at 0x14+0x10n, DMATCRn at 0x18+0x10n,
    CHCRn at 0x1c+0x10n (per symbols.tsv / Sh7055h.pdf 10.2).

    Model: writing CHCRn with DE (bit0) set performs the transfer immediately
    (byte units from SARn to DARn, DMATCRn counts, source/dest incremented),
    then sets TE (bit1) and clears DE - the firmware polls TE (e.g. the boot
    wait loop at 0xd5fa on CHCR0)."""

    DMAOR = 0x00

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.regs = bytearray(size)
        self.transfers = []  # (cycle, ch, sar, dar, count)

    def read(self, off, size):
        return int.from_bytes(self.regs[off:off + size], "big")

    def write(self, off, size, value):
        value &= (1 << (size * 8)) - 1
        self.regs[off:off + size] = value.to_bytes(size, "big")
        # CHCRn is the last word of each 0x10 channel block
        ch, rel = divmod(off - 0x10, 0x10)
        if 0 <= ch < 4 and rel == 0xC and size == 4 and (value & 0x1):
            self._do_transfer(ch)

    def _do_transfer(self, ch):
        o = 0x10 + 0x10 * ch
        sar = int.from_bytes(self.regs[o:o + 4], "big")
        dar = int.from_bytes(self.regs[o + 4:o + 8], "big")
        cnt = int.from_bytes(self.regs[o + 8:o + 12], "big") & 0xFFFF
        bus = self.bus
        for i in range(cnt):
            if bus is not None:
                bus.write8((dar + i) & 0xFFFFFFFF, bus.read8((sar + i) & 0xFFFFFFFF))
        self.transfers.append((bus.cycle if bus else 0, ch, sar, dar, cnt))
        chcr = int.from_bytes(self.regs[o + 0xC:o + 0x10], "big")
        chcr = (chcr | 0x2) & ~0x1  # TE=1, DE=0
        self.regs[o + 0xC:o + 0x10] = chcr.to_bytes(4, "big")


class SCI(RegisterFile):
    """Serial comm stub (diagnostic/UDS transport in real hardware)."""


class CAN(RegisterFile):
    """CAN controller stub (UDS 0x10/0x23/0x27/0x34/0x36/0x37, Mode 22 PIDs)."""


class UBC(RegisterFile):
    """SH7055 User Break Controller (hardware breakpoints, like the real MCU).

    Channels: BARA/BAMRA (address+mask), BBRA/BBRB, BRCR. When PC matches
    BARA & BAMRA (and BRCR enables the channel), the real MCU raises the UBC
    break; here we notify the DebugSession (bus.debugger) or fire the
    configured break vector. Register base per Sh7055h.pdf (_note: refine).
    """

    # offsets within the UBC register block (channel A at 0x00, B at 0x10, BRCR at 0x20)
    BARA, BAMRA, BBRA, BBRB, BRCR = 0x00, 0x04, 0x08, 0x0C, 0x20

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.break_vector = self.config.get("break_vector")  # None -> notify debugger

    def tick(self, cycles):
        cpu = getattr(self.bus, "cpu", None)
        if cpu is None:
            return
        bara = int.from_bytes(self.regs[self.BARA:self.BARA + 4], "big")
        bamra = int.from_bytes(self.regs[self.BAMRA:self.BAMRA + 4], "big")
        bbra = int.from_bytes(self.regs[self.BBRA:self.BBRA + 4], "big")
        bbrma = int.from_bytes(self.regs[self.BBRB:self.BBRB + 4], "big")
        brcr = int.from_bytes(self.regs[self.BRCR:self.BRCR + 4], "big")
        pc = cpu.pc
        hit = None
        if brcr & 0x1 and (pc & bamra) == (bara & bamra):  # channel A, PC match
            hit = "UBC-A"
        elif brcr & 0x2 and (pc & bbrma) == (bbra & bbrma):  # channel B
            hit = "UBC-B"
        if hit:
            dbg = getattr(self.bus, "debugger", None)
            if dbg is not None:
                dbg.stopped_reason = f"{hit} hardware breakpoint at 0x{pc:08x}"
            elif self.break_vector is not None:
                cpu.interrupt(self.break_vector)


TYPES = {
    "wdt": WDT,
    "dmac": DMAC,
    "gpio": GPIO,
    "adc": ADC,
    "atu2": ATU2,
    "sci": SCI,
    "can": CAN,
    "regfile": RegisterFile,
    "ubc": UBC,
}
