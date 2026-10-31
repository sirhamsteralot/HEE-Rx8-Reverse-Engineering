"""Debugger for the HEE emulator: breakpoints, watchpoints, stepping, inspection.

Mirrors what the original MCU offers via its UBC (User Break Controller) plus the
Renesas debugger: execution breakpoints, memory read/write watchpoints, single
step, continue, register/memory dump, and disassembly at PC (via the corpus table
opdec.OPMNEM, so it prints the same mnemonics as the Ghidra listing).

Used by the CLI (`debug.py`) and the UI (`ui.py` /api/debug endpoints).
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from opdec import OPMNEM  # noqa: E402


class Breakpoint:
    def __init__(self, addr, kind="exec", size=2, on="write"):
        self.addr = addr & 0xFFFFFFFF
        self.kind = kind      # "exec" | "mem"
        self.size = size
        self.on = on          # mem: "read" | "write" | "rw"
        self.enabled = True
        self.hit_count = 0

    def matches(self, pc, addr=None, is_write=None, is_read=None):
        if self.kind == "exec":
            return pc == self.addr
        if addr is None:
            return False
        in_range = self.addr <= addr < self.addr + self.size or addr < self.addr <= addr + self.size
        if not in_range:
            return False
        if self.on == "write":
            return is_write
        if self.on == "read":
            return is_read
        return True


class DebugSession:
    def __init__(self, prof, bus, cpu):
        self.prof = prof
        self.bus = bus
        self.cpu = cpu
        self.breaks = []
        self.stopped_reason = None
        bus.debugger = self  # lets the UBC peripheral signal hardware breaks
        self._install_hooks()

    # -- hook bus accesses for watchpoints --
    def _install_hooks(self):
        dbg = self
        bus = self.bus
        for name, is_write in (("read8", False), ("read16", False), ("read32", False),
                               ("write8", True), ("write16", True), ("write32", True)):
            orig = getattr(bus, name)

            def make(orig, is_write, name):
                size = int(name[-1]) // 8

                def hooked(a, *args):
                    v = orig(a, *args)
                    dbg._on_access(a, size, is_write, False)
                    return v
                return hooked
            setattr(bus, name, make(orig, is_write, name))

    def _on_access(self, addr, size, is_write, _):
        for b in self.breaks:
            if b.kind == "mem" and b.enabled and b.matches(None, addr, is_write, not is_write):
                b.hit_count += 1
                self.stopped_reason = f"watchpoint {'write' if is_write else 'read'} at 0x{addr:08x} (bp#{self.breaks.index(b)})"
                return

    # -- breakpoint management --
    def add_break(self, addr, kind="exec", size=2, on="write"):
        b = Breakpoint(addr, kind, size, on)
        self.breaks.append(b)
        return self.breaks.index(b)

    def del_break(self, idx):
        del self.breaks[idx]

    def check_pc(self, pc):
        for i, b in enumerate(self.breaks):
            if b.kind == "exec" and b.enabled and b.matches(pc):
                b.hit_count += 1
                self.stopped_reason = f"breakpoint at 0x{pc:08x} (bp#{i})"
                return True
        return False

    # -- execution control --
    def step(self, n=1):
        for _ in range(n):
            self.stopped_reason = None
            pc = self.cpu.pc
            self.cpu.step()
            self.bus.tick(1)
            if self.stopped_reason or self.check_pc(self.cpu.pc):
                break
        return self.stopped_reason

    def continue_(self, max_cycles):
        """Run until a breakpoint/watchpoint fires or the cycle budget ends."""
        self.stopped_reason = None
        for _ in range(max_cycles):
            if self.check_pc(self.cpu.pc):
                return self.stopped_reason
            self.cpu.step()
            self.bus.tick(1)
            if self.stopped_reason:
                return self.stopped_reason
        return self.stopped_reason or f"cycle limit {max_cycles} reached"

    # -- inspection --
    def regs(self):
        c = self.cpu
        out = {f"r{i}": c.r[i] for i in range(16)}
        out.update({"pc": c.pc, "pr": c.pr, "sr": c.sr, "T": c.T,
                    "gbr": c.gbr, "vbr": c.vbr, "mach": c.mach, "macl": c.macl,
                    "fpscr": c.fpscr, "fpul": c.fpul})
        out.update({f"fr{i}": c.fr[i] for i in range(16)})
        return out

    def mem(self, addr, n=4, size=4):
        rd = {1: self.bus.read8, 2: self.bus.read16, 4: self.bus.read32}[size]
        return [rd(addr + i * size) for i in range(n)]

    def disasm(self, addr, n=8):
        lines = []
        pc = addr
        for _ in range(n):
            op = self.bus.read16(pc)
            e = OPMNEM.get(op)
            mn, ops = e if e else ("???", "")
            lines.append(f"0x{pc:08x}: 0x{op:04x}  {mn} {ops}")
            pc += 2
        return lines

    def state(self):
        return {"pc": self.cpu.pc, "icount": self.cpu.icount,
                "stopped": self.stopped_reason,
                "breaks": [{"i": i, "addr": hex(b.addr), "kind": b.kind,
                            "on": b.on, "hits": b.hit_count, "enabled": b.enabled}
                           for i, b in enumerate(self.breaks)]}
