"""Minimal SH-2E (SH7055) CPU core for the HEE emulator.

Exactness matters: this is a hand-written interpreter, not QEMU/Unicorn (those
model SH-4 and over-accept instructions). Only the opcode subset observed in the
RX-8 PCM disassembly is implemented (encodings per docs/learnings.md); anything
else raises UnknownOpcode so a run stops loudly instead of mis-executing.

Big-endian. Delay slots are handled: a branch at pc executes the instruction at
pc+2 before transferring control.
"""


class UnknownOpcode(Exception):
    def __init__(self, pc, opcode):
        super().__init__(f"unknown opcode 0x{opcode:04x} at 0x{pc:08x}")
        self.pc = pc
        self.opcode = opcode


def _se8(v):
    return v - 256 if v & 0x80 else v


def _se12(v):
    return v - 4096 if v & 0x800 else v


def _se16(v):
    return v - 65536 if v & 0x8000 else v


class SH2E:
    def __init__(self, bus, trace=None):
        self.bus = bus
        self.r = [0] * 16
        self.pc = 0
        self.pr = 0
        self.sr = 0  # bit 0 = T
        self.fr = [0.0] * 16  # FPU bank (single bank sufficient for observed code)
        self.trace = trace  # optional list collecting executed PCs
        self.icount = 0

    # -- memory helpers (bus handles ROM/RAM/MMIO) --
    def r8(self, a): return self.bus.read8(a)
    def r16(self, a): return self.bus.read16(a)
    def r32(self, a): return self.bus.read32(a)
    def w8(self, a, v): self.bus.write8(a, v & 0xFF)
    def w16(self, a, v): self.bus.write16(a, v & 0xFFFF)
    def w32(self, a, v): self.bus.write32(a, v & 0xFFFFFFFF)

    def reset(self, pc, sp):
        self.pc = pc & 0xFFFFFFFF
        self.r[15] = sp & 0xFFFFFFFF
        self.pr = 0
        self.sr = 0
        self.icount = 0

    def interrupt(self, vector_addr):
        """Jump to an interrupt vector (vector_addr = address holding the handler PC)."""
        self.pr = self.pc
        self.pc = self.r32(vector_addr)

    @property
    def T(self):
        return self.sr & 1

    @T.setter
    def T(self, v):
        self.sr = (self.sr & ~1) | (1 if v else 0)

    def step(self):
        """Execute one instruction (including its delay slot if it is a branch)."""
        pc = self.pc
        op = self.r16(pc)
        if self.trace is not None:
            self.trace.append(pc)
        self._exec(pc, op)
        self.icount += 1

    def _exec(self, pc, op):
        hi = op >> 12
        n = (op >> 8) & 0xF
        m = (op >> 4) & 0xF
        lo = op & 0xF

        # --- control flow ---
        if op == 0x0009:  # nop
            self.pc = pc + 2
            return
        if op == 0x000B:  # rts
            target = self.pr
            self._exec(pc + 2, self.r16(pc + 2))  # delay slot
            self.pc = target
            return
        if hi == 0xA:  # bra disp12
            target = (pc + 4 + _se12(op & 0xFFF) * 2) & 0xFFFFFFFF
            self._exec(pc + 2, self.r16(pc + 2))
            self.pc = target
            return
        if hi == 0xB:  # bsr
            target = (pc + 4 + _se12(op & 0xFFF) * 2) & 0xFFFFFFFF
            self._exec(pc + 2, self.r16(pc + 2))
            self.pr = (pc + 4) & 0xFFFFFFFF
            self.pc = target
            return
        if op & 0xFF00 == 0x8D00:  # bt disp8
            if self.T:
                target = (pc + 4 + _se8(op & 0xFF) * 2) & 0xFFFFFFFF
                self._exec(pc + 2, self.r16(pc + 2))
                self.pc = target
                return
            self.pc = pc + 2
            return
        if op & 0xFF00 == 0x8F00:  # bf disp8
            if not self.T:
                target = (pc + 4 + _se8(op & 0xFF) * 2) & 0xFFFFFFFF
                self._exec(pc + 2, self.r16(pc + 2))
                self.pc = target
                return
            self.pc = pc + 2
            return
        if hi == 0x4 and lo == 0xB:  # jsr @rN
            target = self.r[n]
            self._exec(pc + 2, self.r16(pc + 2))
            self.pr = (pc + 4) & 0xFFFFFFFF
            self.pc = target
            return

        # --- moves ---
        if hi == 0xE:  # mov #imm,rN
            self.r[n] = _se8(op & 0xFF) & 0xFFFFFFFF
            self.pc = pc + 2
            return
        if hi == 0x6 and lo == 0x3:  # mov rM,rN
            self.r[n] = self.r[m]
            self.pc = pc + 2
            return
        if hi == 0xD:  # mov.l @(disp,PC),rN
            ea = ((pc + 4) & ~3) + (op & 0xFF) * 4
            self.r[n] = self.r32(ea)
            self.pc = pc + 2
            return
        if hi == 0x9:  # mov.w @(disp,PC),rN (sign-extended)
            ea = pc + 4 + (op & 0xFF) * 2
            self.r[n] = _se16(self.r16(ea)) & 0xFFFFFFFF
            self.pc = pc + 2
            return
        if hi == 0xC:  # mova @(disp,PC),rN
            self.r[n] = ((pc + 4) & ~3) + (op & 0xFF) * 4
            self.pc = pc + 2
            return
        if hi == 0x2 and lo == 0x1:  # mov.l rM,@rN
            self.w32(self.r[n], self.r[m])
            self.pc = pc + 2
            return
        if hi == 0x2 and lo == 0x2:  # mov.w rM,@rN
            self.w16(self.r[n], self.r[m])
            self.pc = pc + 2
            return
        if hi == 0x2 and lo == 0x6:  # mov.b rM,@rN
            self.w8(self.r[n], self.r[m])
            self.pc = pc + 2
            return
        if hi == 0x6 and lo == 0x2:  # mov.l @rM,rN
            self.r[n] = self.r32(self.r[m])
            self.pc = pc + 2
            return
        if hi == 0x6 and lo == 0x6:  # mov.l @rM+,rN
            self.r[n] = self.r32(self.r[m])
            self.r[m] = (self.r[m] + 4) & 0xFFFFFFFF
            self.pc = pc + 2
            return
        if hi == 0x4 and lo == 0x2 and n == 0xF:  # sts.l pr,@-r15
            self.r[15] = (self.r[15] - 4) & 0xFFFFFFFF
            self.w32(self.r[15], self.pr)
            self.pc = pc + 2
            return
        if hi == 0x7:  # add #imm,rN
            self.r[n] = (self.r[n] + _se8(op & 0xFF)) & 0xFFFFFFFF
            self.pc = pc + 2
            return
        if op & 0xFF0F == 0x8808:  # cmp/eq #imm,rN
            self.T = 1 if (self.r[n] & 0xFF) == (op & 0xFF) else 0
            self.pc = pc + 2
            return

        # --- FPU subset (single bank, 32-bit floats) ---
        if hi == 0xF:
            fn = n
            fm = m
            fop = lo
            if fop == 0x8:  # fmov.s @rM,frN
                self.fr[fn] = self._f32(self.r32(self.r[fm]))
                self.pc = pc + 2
                return
            if fop == 0xA:  # fmov.s frM,@rN
                self.w32(self.r[fn], self._bits(self.fr[fm]))
                self.pc = pc + 2
                return
            if fop == 0xC:  # fmov frM,frN
                self.fr[fn] = self.fr[fm]
                self.pc = pc + 2
                return
            if fop == 0x0:  # fadd frM,frN
                self.fr[fn] = self.fr[fn] + self.fr[fm]
                self.pc = pc + 2
                return
            if fop == 0x1:  # fsub
                self.fr[fn] = self.fr[fn] - self.fr[fm]
                self.pc = pc + 2
                return
            if fop == 0x2:  # fmul
                self.fr[fn] = self.fr[fn] * self.fr[fm]
                self.pc = pc + 2
                return
            if fop == 0x5:  # fcmp/gt frM,frN : T = frN > frM
                self.T = 1 if self.fr[fn] > self.fr[fm] else 0
                self.pc = pc + 2
                return

        raise UnknownOpcode(pc, op)

    @staticmethod
    def _bits(f):
        import struct
        return struct.unpack("<I", struct.pack("<f", f))[0]

    @staticmethod
    def _f32(bits):
        import struct
        return struct.unpack("<f", struct.pack("<I", bits))[0]
