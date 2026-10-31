"""Memory bus for the HEE emulator: ROM / RAM / volatile-I/O regions from the
active profile, MMIO dispatched to peripheral objects, all writes traced."""


class Region:
    def __init__(self, start, end, kind, data=None):
        self.start = start
        self.end = end  # exclusive
        self.kind = kind  # "rom" | "ram" | "io"
        self.data = bytearray(data) if data is not None else bytearray(end - start)

    def contains(self, addr, size):
        return self.start <= addr and addr + size <= self.end


class Bus:
    def __init__(self, memory_map, rom_bytes=None):
        self.regions = []
        if "rom" in memory_map:
            s, e = memory_map["rom"]
            self.regions.append(Region(s, e, "rom", rom_bytes))
        if "ram" in memory_map:
            s, e = memory_map["ram"]
            self.regions.append(Region(s, e, "ram"))
        if "io" in memory_map:
            s, e = memory_map["io"]
            self.regions.append(Region(s, e, "io"))
        self.peripherals = []  # list of (start, end, peripheral)
        self.mmio_log = []     # (cycle, pc, addr, value, size)
        self.rom_writes_blocked = 0  # CPU stores to flash are ignored on real HW
        self.read_overrides = {int(k): v for k, v in memory_map.get("io_read_overrides", {}).items()}
        self.cycle = 0
        self.pc = 0

    def add_peripheral(self, base, size, periph):
        self.peripherals.append((base, base + size, periph))
        periph.attach(self)

    def _region(self, addr, size):
        for reg in self.regions:
            if reg.contains(addr, size):
                return reg
        return None

    def _periph(self, addr):
        for start, end, p in self.peripherals:
            if start <= addr < end:
                return start, p
        return None, None

    # -- reads --
    def read8(self, a):
        if a in self.read_overrides:
            return self.read_overrides[a] & 0xFF
        base, p = self._periph(a)
        if p is not None:
            return p.read(a - base, 1)
        reg = self._region(a, 1)
        if reg is None:
            return 0
        return reg.data[a - reg.start]

    def read16(self, a):
        if a in self.read_overrides:
            return self.read_overrides[a] & 0xFFFF
        base, p = self._periph(a)
        if p is not None:
            return p.read(a - base, 2)
        reg = self._region(a, 2)
        if reg is None:
            return 0
        return int.from_bytes(reg.data[a - reg.start:a - reg.start + 2], "big")

    def read32(self, a):
        if a in self.read_overrides:
            return self.read_overrides[a] & 0xFFFFFFFF
        if (a & ~1) in self.read_overrides and a & 1 == 0:
            pass
        base, p = self._periph(a)
        if p is not None:
            return p.read(a - base, 4)
        reg = self._region(a, 4)
        if reg is None:
            return 0
        return int.from_bytes(reg.data[a - reg.start:a - reg.start + 4], "big")

    # -- writes --
    def write8(self, a, v):
        base, p = self._periph(a)
        if p is not None:
            p.write(a - base, 1, v)
            self.mmio_log.append((self.cycle, self.pc, a, v, 1))
            return
        reg = self._region(a, 1)
        if reg is None:
            return
        if reg.kind == "rom":  # flash: CPU stores ignored (needs program sequence)
            self.rom_writes_blocked += 1
            return
        reg.data[a - reg.start] = v & 0xFF

    def write16(self, a, v):
        base, p = self._periph(a)
        if p is not None:
            p.write(a - base, 2, v)
            self.mmio_log.append((self.cycle, self.pc, a, v, 2))
            return
        reg = self._region(a, 2)
        if reg is None:
            return
        if reg.kind == "rom":
            self.rom_writes_blocked += 1
            return
        reg.data[a - reg.start:a - reg.start + 2] = (v & 0xFFFF).to_bytes(2, "big")

    def write32(self, a, v):
        base, p = self._periph(a)
        if p is not None:
            p.write(a - base, 4, v)
            self.mmio_log.append((self.cycle, self.pc, a, v, 4))
            return
        reg = self._region(a, 4)
        if reg is None:
            return
        if reg.kind == "rom":
            self.rom_writes_blocked += 1
            return
        reg.data[a - reg.start:a - reg.start + 4] = (v & 0xFFFFFFFF).to_bytes(4, "big")

    def tick(self, cycles=1):
        self.cycle += cycles
        for _, _, p in self.peripherals:
            p.tick(cycles)
