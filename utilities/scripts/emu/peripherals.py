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
                self.tcsr |= 0x80
                if self.bus is not None and hasattr(self.bus, "cpu"):
                    if self.overflow_handler is not None:
                        self.bus.cpu.pr = self.bus.cpu.pc
                        self.bus.cpu.pc = self.overflow_handler & 0xFFFFFFFF
                    else:
                        vec = self.overflow_vector if self.overflow_vector is not None else 0
                        self.bus.cpu.interrupt(vec)


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
    """ADC with scripted channel values from the profile (sensor injection).
    Register 0xfffff80c observed in the APV path (docs/architecture/hardware)."""

    def __init__(self, base, size, config):
        super().__init__(base, size, config)
        self.channels = self.config.get("channels", {})  # name -> raw int

    def read(self, off, size):
        # offset 0x0c = ADDRA-ish result register in our observed usage
        name = self.config.get("result_channel")
        if name and name in self.channels:
            return self.channels[name]
        return 0

    def write(self, off, size, value):
        pass


class ATU2(RegisterFile):
    """ATU-II timer stub. Injector output pulse registers are logged by the bus;
    config may name them for decoding later (injector channel map: ROM 0xd7d4 ->
    ATU-II 8A-8F)."""


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
    "gpio": GPIO,
    "adc": ADC,
    "atu2": ATU2,
    "sci": SCI,
    "can": CAN,
    "regfile": RegisterFile,
    "ubc": UBC,
}
