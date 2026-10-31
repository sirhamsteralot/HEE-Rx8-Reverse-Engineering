"""SH-2E (SH7055) CPU core for the HEE emulator.

Hand-written, exact interpreter (not QEMU/Unicorn — those model SH-4). Dispatch
table `opdec.OPMNEM` is generated from the real disassembly by `gen_opdec.py` and
validated instruction-by-instruction in `tests/test_decode_corpus.py`. Opcodes
outside the table raise UnknownOpcode, so a run stops loudly instead of
mis-executing. Branch targets are computed from the opcode's displacement bits.

Big-endian; delay slots handled (a branch at pc executes the instruction at
pc+2 before transferring control). Encodings per docs/learnings.md + SH-2E manual.
"""
import re
import struct

from opdec import OPMNEM


class UnknownOpcode(Exception):
    def __init__(self, pc, opcode):
        super().__init__(f"unknown opcode 0x{opcode:04x} at 0x{pc:08x}")
        self.pc = pc
        self.opcode = opcode


def _se8(v): return v - 256 if v & 0x80 else v
def _se12(v): return v - 4096 if v & 0x800 else v


def _f32(bits): return struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0]
def _bits(f): return struct.unpack("<I", struct.pack("<f", f))[0]

_REG = re.compile(r"^r(\d+)$")
_FREG = re.compile(r"^fr(\d+)$")
_IMM = re.compile(r"^#(-?0x[0-9a-fA-F]+|-?\d+)$")
_DISP_PC = re.compile(r"^@\((0x[0-9a-fA-F]+),pc\)$")
_DISP_REG = re.compile(r"^@\((0x[0-9a-fA-F]+),r(\d+)\)$")
_R0_REG = re.compile(r"^@\(r0,r(\d+)\)$")


def _is_imm(tok):
    return bool(re.match(r"^#?-?(0x[0-9a-fA-F]+|\d+)$", tok))


def _imm(tok):
    """'#0x42' / '0x80' / '#-4' -> signed int (Ghidra sometimes omits '#')."""
    t = tok.lstrip("#")
    neg = t.startswith("-")
    if neg: t = t[1:]
    v = int(t, 0)
    return -v if neg else v


def _reg(tok):
    m = _REG.match(tok)
    return int(m.group(1)) if m else None


def _freg(tok):
    m = _FREG.match(tok)
    return int(m.group(1)) if m else None


class SH2E:
    def __init__(self, bus, trace=None):
        self.bus = bus
        self.r = [0] * 16
        self.pc = 0
        self.pr = 0
        self.sr = 0          # bit0 = T, bit3 = S, bits4-7 = I3-I0, bit8 = Q, bit9 = M
        self.gbr = 0
        self.vbr = 0
        self.mach = 0
        self.macl = 0
        self.fpscr = 0
        self.fpul = 0
        self.fr = [0.0] * 16
        self.trace = trace
        self.icount = 0
        self.stopped = False
        self.pending = []  # [(priority, vector_offset)] deferred while masked

    # -- bus helpers --
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

    def interrupt(self, vector_offset, priority=None):
        """Accept an interrupt: push SR+PC on the stack, set the SR mask to the
        interrupt's priority level, branch to IVT[VBR + vector_offset]
        (SH-2E manual 6.1.3/7.2.5). vector_offset is relative to VBR.

        SH-2E masking: an interrupt is accepted only if its priority level is
        strictly greater than the current SR I3-I0 mask (manual 7.2.5); otherwise
        it stays pending and is delivered when the mask is lowered (ldc/rte).
        Unprioritized interrupts (priority=None, e.g. NMI/reset) always fire."""
        if priority is not None and ((priority & 0xF) << 4) <= (self.sr & 0xF0):
            self.pending.append((priority & 0xF, vector_offset))
            self.pending.sort(key=lambda p: -p[0])
            return
        self._take_interrupt(vector_offset, priority)

    def _take_interrupt(self, vector_offset, priority):
        self.r[15] = (self.r[15] - 8) & 0xFFFFFFFF
        self.w32(self.r[15], self.sr)
        self.w32(self.r[15] + 4, self.pc)
        if priority is not None:
            self.sr = (self.sr & ~0xF0) | ((priority & 0xF) << 4)
        self.pc = self.r32((self.vbr + vector_offset) & 0xFFFFFFFF)

    def _deliver_pending(self):
        """Deliver the highest-priority pending interrupt whose level now
        exceeds the SR mask (called after ldc/rte lower the mask)."""
        while self.pending:
            pri, vec = self.pending[0]
            if (pri << 4) > (self.sr & 0xF0):
                self.pending.pop(0)
                self._take_interrupt(vec, pri)
                return True
            break
        return False

    @property
    def T(self): return self.sr & 1

    @T.setter
    def T(self, v): self.sr = (self.sr & ~1) | (1 if v else 0)

    # Q (SR bit 8) and M (SR bit 9) — used by DIV0U/DIV0S/DIV1 (Sh7055h.pdf fig 2.2)
    @property
    def Q(self): return (self.sr >> 8) & 1

    @Q.setter
    def Q(self, v): self.sr = (self.sr & ~(1 << 8)) | ((1 if v else 0) << 8)

    @property
    def M(self): return (self.sr >> 9) & 1

    @M.setter
    def M(self, v): self.sr = (self.sr & ~(1 << 9)) | ((1 if v else 0) << 9)

    def step(self):
        pc = self.pc
        op = self.r16(pc)
        if self.trace is not None:
            self.trace.append(pc)
        self._exec(pc, op)
        self.icount += 1

    def _branch(self, pc, target):
        self._exec(pc + 2, self.r16(pc + 2))  # delay slot
        self.pc = target & 0xFFFFFFFF

    # -- main dispatch --
    def _exec(self, pc, op):
        entry = OPMNEM.get(op)
        if entry is None:
            raise UnknownOpcode(pc, op)
        mn, ops = entry
        toks = [t.strip() for t in re.split(r",(?![^()]*\))", ops)] if ops else []
        h = getattr(self, "_op_" + mn.replace("/", "").replace(".", "").replace("#", "imm"), None)
        if h is None:
            raise UnknownOpcode(pc, op)
        h(pc, op, toks)

    def _next(self, pc): self.pc = (pc + 2) & 0xFFFFFFFF

    # -- helpers to resolve operands --
    def _ea_disp_pc(self, pc, tok, scale):
        m = _DISP_PC.match(tok)
        disp = int(m.group(1), 16)
        if scale == 4:
            return ((pc + 4) & ~3) + disp * 4
        return pc + 4 + disp * 2

    # ================= system / control =================
    def _op_nop(self, pc, op, t): self._next(pc)
    def _op_sett(self, pc, op, t): self.T = 1; self._next(pc)
    def _op_clrt(self, pc, op, t): self.T = 0; self._next(pc)

    def _op_rts(self, pc, op, t): self._branch(pc, self.pr)

    def _op_rte(self, pc, op, t):
        self.sr = self.r32(self.r[15])
        target = self.r32((self.r[15] + 4) & 0xFFFFFFFF)
        self.r[15] = (self.r[15] + 8) & 0xFFFFFFFF
        self._branch(pc, target)
        self._deliver_pending()

    def _op_bra(self, pc, op, t): self._branch(pc, pc + 4 + _se12(op & 0xFFF) * 2)
    def _op_bsr(self, pc, op, t):
        self.pr = (pc + 4) & 0xFFFFFFFF
        self._branch(pc, pc + 4 + _se12(op & 0xFFF) * 2)

    def _op_bt(self, pc, op, t):
        if self.T: self.pc = (pc + 4 + _se8(op & 0xFF) * 2) & 0xFFFFFFFF
        else: self._next(pc)

    def _op_bf(self, pc, op, t):
        if not self.T: self.pc = (pc + 4 + _se8(op & 0xFF) * 2) & 0xFFFFFFFF
        else: self._next(pc)

    def _op_bts(self, pc, op, t):
        if self.T: self._branch(pc, pc + 4 + _se8(op & 0xFF) * 2)
        else: self._next(pc)

    def _op_bfs(self, pc, op, t):
        if not self.T: self._branch(pc, pc + 4 + _se8(op & 0xFF) * 2)
        else: self._next(pc)

    def _op_jmp(self, pc, op, t): self._branch(pc, self.r[(op >> 8) & 0xF])
    def _op_jsr(self, pc, op, t):
        self.pr = (pc + 4) & 0xFFFFFFFF
        self._branch(pc, self.r[(op >> 8) & 0xF])

    def _op_movt(self, pc, op, t): self.r[_reg(t[0])] = self.T; self._next(pc)

    # ================= data transfer =================
    def _load_store(self, pc, op, t, is_store, size):
        """t = [src_or_addr, dst] in asm operand order; normalize."""
        if size == "b": rd, wr = self.r8, self.w8
        elif size == "w": rd, wr = self.r16, self.w16
        else: rd, wr = self.r32, self.w32

        a, b = t[0], t[1]
        pc_rel = False
        # load forms: '@...,rN'
        if a.startswith("@"):
            dst = _reg(b)
            if _DISP_PC.match(a):
                # corpus token holds the resolved EA for the listing's pc; recompute
                # from the opcode's own disp bits so loops/relocations stay correct
                if size == "l":
                    addr = (((pc + 4) & ~3) + (op & 0xFF) * 4) & 0xFFFFFFFF
                else:
                    addr = (pc + 4 + (op & 0xFF) * 2) & 0xFFFFFFFF
                pc_rel = True
            elif _DISP_REG.match(a):
                m = _DISP_REG.match(a)
                addr = (self.r[int(m.group(2))] + int(m.group(1), 16)) & 0xFFFFFFFF
            elif _R0_REG.match(a):
                addr = (self.r[0] + self.r[int(_R0_REG.match(a).group(1))]) & 0xFFFFFFFF
            elif a.endswith("+"):
                base = _reg(a[1:-1])
                addr = self.r[base]
                self.r[base] = (self.r[base] + (1 if size == "b" else 2 if size == "w" else 4)) & 0xFFFFFFFF
            else:
                addr = self.r[_reg(a[1:])]
            v = rd(addr)
            if size == "b": v &= 0xFF
            if size == "w" and pc_rel and (v & 0x8000):
                # mov.w @(disp,pc) sign-extends (learnings.md); register forms zero-extend
                self.r[dst] = (v - 65536) & 0xFFFFFFFF
                self._next(pc)
                return
            if size == "w": v &= 0xFFFF
            self.r[dst] = v & 0xFFFFFFFF
            self._next(pc)
            return
        # store forms: 'rM,@...'
        src = _reg(a)
        if _DISP_PC.match(b):
            raise UnknownOpcode(pc, op)  # no pc-relative stores on SH-2E
        if _DISP_REG.match(b):
            m = _DISP_REG.match(b)
            addr = (self.r[int(m.group(2))] + int(m.group(1), 16)) & 0xFFFFFFFF
        elif _R0_REG.match(b):
            addr = (self.r[0] + self.r[int(_R0_REG.match(b).group(1))]) & 0xFFFFFFFF
        elif b == "@-r15" or re.fullmatch(r"@-r\d+", b):
            dst = _reg(b[2:])
            self.r[dst] = (self.r[dst] - (4 if size == "l" else 2 if size == "w" else 1)) & 0xFFFFFFFF
            addr = self.r[dst]
        elif b.endswith("+"):
            raise UnknownOpcode(pc, op)
        else:
            addr = self.r[_reg(b[1:])]
        wr(addr, self.r[src])
        self._next(pc)

    def _op_movb(self, pc, op, t): self._load_store(pc, op, t, False, "b")
    def _op_movw(self, pc, op, t): self._load_store(pc, op, t, False, "w")
    def _op_movl(self, pc, op, t): self._load_store(pc, op, t, False, "l")

    def _op_mov(self, pc, op, t):
        if _is_imm(t[0]):
            self.r[_reg(t[1])] = _se8(_imm(t[0]) & 0xFF) & 0xFFFFFFFF if abs(_imm(t[0])) < 256 else _imm(t[0]) & 0xFFFFFFFF
        else:
            self.r[_reg(t[1])] = self.r[_reg(t[0])]
        self._next(pc)

    def _op_mova(self, pc, op, t):
        self.r[_reg(t[1])] = (((pc + 4) & ~3) + (op & 0xFF) * 4) & 0xFFFFFFFF
        self._next(pc)

    # ================= arithmetic / logic =================
    def _op_add(self, pc, op, t):
        if _is_imm(t[0]):
            self.r[_reg(t[1])] = (self.r[_reg(t[1])] + _se8(_imm(t[0]) & 0xFF)) & 0xFFFFFFFF
        else:
            self.r[_reg(t[1])] = (self.r[_reg(t[1])] + self.r[_reg(t[0])]) & 0xFFFFFFFF
        self._next(pc)

    def _op_addc(self, pc, op, t):
        n, m = _reg(t[1]), _reg(t[0])
        old = self.r[n]
        s = old + self.r[m] + self.T
        self.r[n] = s & 0xFFFFFFFF
        self.T = 1 if s > 0xFFFFFFFF else 0
        self._next(pc)

    def _op_addv(self, pc, op, t):
        n, m = _reg(t[1]), _reg(t[0])
        s = self.r[n] + self.r[m]
        self.r[n] = s & 0xFFFFFFFF
        self.T = 1 if (not (~(self.r[n] ^ self.r[m]) & (self.r[n] ^ s) & 0x80000000)) and False else (
            1 if ((self.r[n] ^ s) & (self.r[m] ^ s) & 0x80000000) else 0)
        self._next(pc)

    def _op_sub(self, pc, op, t):
        self.r[_reg(t[1])] = (self.r[_reg(t[1])] - self.r[_reg(t[0])]) & 0xFFFFFFFF
        self._next(pc)

    def _op_subc(self, pc, op, t):
        n, m = _reg(t[1]), _reg(t[0])
        d = self.r[n] - self.r[m] - self.T
        self.r[n] = d & 0xFFFFFFFF
        self.T = 1 if d < 0 else 0
        self._next(pc)

    def _op_neg(self, pc, op, t):
        self.r[_reg(t[1])] = (-self.r[_reg(t[0])]) & 0xFFFFFFFF
        self._next(pc)

    def _op_not(self, pc, op, t):
        self.r[_reg(t[1])] = (~self.r[_reg(t[0])]) & 0xFFFFFFFF
        self._next(pc)

    def _bin_logic(self, pc, f):
        pass

    def _op_and(self, pc, op, t):
        if _is_imm(t[0]):
            self.r[_reg(t[1])] &= _imm(t[0])
        else:
            self.r[_reg(t[1])] &= self.r[_reg(t[0])]
        self.r[_reg(t[1])] &= 0xFFFFFFFF
        self._next(pc)

    def _op_or(self, pc, op, t):
        if _is_imm(t[0]):
            self.r[_reg(t[1])] |= _imm(t[0])
        else:
            self.r[_reg(t[1])] |= self.r[_reg(t[0])]
        self.r[_reg(t[1])] &= 0xFFFFFFFF
        self._next(pc)

    def _op_xor(self, pc, op, t):
        if _is_imm(t[0]):
            self.r[_reg(t[1])] ^= _imm(t[0])
        else:
            self.r[_reg(t[1])] ^= self.r[_reg(t[0])]
        self.r[_reg(t[1])] &= 0xFFFFFFFF
        self._next(pc)

    def _op_tst(self, pc, op, t):
        if _is_imm(t[0]):
            self.T = 1 if (self.r[_reg(t[1])] & _imm(t[0])) == 0 else 0
        else:
            self.T = 1 if (self.r[_reg(t[1])] & self.r[_reg(t[0])]) == 0 else 0
        self._next(pc)

    def _op_swapb(self, pc, op, t):
        n, m = _reg(t[1]), _reg(t[0])
        v = self.r[m]
        self.r[n] = ((v & 0x00FF00FF) << 8 | (v & 0xFF00FF00) >> 8) & 0xFFFFFFFF
        self._next(pc)

    def _op_swapw(self, pc, op, t):
        n, m = _reg(t[1]), _reg(t[0])
        v = self.r[m]
        self.r[n] = ((v & 0xFFFF) << 16 | (v >> 16)) & 0xFFFFFFFF
        self._next(pc)

    def _op_extub(self, pc, op, t): self.r[_reg(t[1])] = self.r[_reg(t[0])] & 0xFF; self._next(pc)
    def _op_extuw(self, pc, op, t): self.r[_reg(t[1])] = self.r[_reg(t[0])] & 0xFFFF; self._next(pc)

    def _op_extsb(self, pc, op, t):
        v = self.r[_reg(t[0])] & 0xFF
        self.r[_reg(t[1])] = (v - 256 if v & 0x80 else v) & 0xFFFFFFFF
        self._next(pc)

    def _op_extsw(self, pc, op, t):
        v = self.r[_reg(t[0])] & 0xFFFF
        self.r[_reg(t[1])] = (v - 65536 if v & 0x8000 else v) & 0xFFFFFFFF
        self._next(pc)

    # ================= compare =================
    def _s32(self, v): return v - 0x100000000 if v & 0x80000000 else v

    def _op_cmpeq(self, pc, op, t):
        if _is_imm(t[0]):
            self.T = 1 if (self.r[_reg(t[1])] & 0xFF) == (_imm(t[0]) & 0xFF) else 0
        else:
            self.T = 1 if self.r[_reg(t[1])] == self.r[_reg(t[0])] else 0
        self._next(pc)

    def _op_cmpge(self, pc, op, t): self.T = 1 if self._s32(self.r[_reg(t[1])]) >= self._s32(self.r[_reg(t[0])]) else 0; self._next(pc)
    def _op_cmpgt(self, pc, op, t): self.T = 1 if self._s32(self.r[_reg(t[1])]) > self._s32(self.r[_reg(t[0])]) else 0; self._next(pc)
    def _op_cmphi(self, pc, op, t): self.T = 1 if self.r[_reg(t[1])] > self.r[_reg(t[0])] else 0; self._next(pc)
    def _op_cmphs(self, pc, op, t): self.T = 1 if self.r[_reg(t[1])] >= self.r[_reg(t[0])] else 0; self._next(pc)
    def _op_cmppl(self, pc, op, t): self.T = 1 if self._s32(self.r[_reg(t[0])]) > 0 else 0; self._next(pc)
    def _op_cmppz(self, pc, op, t): self.T = 1 if self._s32(self.r[_reg(t[0])]) >= 0 else 0; self._next(pc)

    # ================= shifts / rotates =================
    def _shift(self, pc, n, count, kind):
        v = self.r[n]
        if kind == "shll":
            self.T = (v >> 31) & 1
            self.r[n] = (v << count) & 0xFFFFFFFF
        elif kind == "shlr":
            self.T = v & 1
            self.r[n] = (v & 0xFFFFFFFF) >> count
        elif kind == "shar":
            self.T = v & 1
            sv = self._s32(v)
            self.r[n] = (sv >> count) & 0xFFFFFFFF
        elif kind == "shal":
            self.T = (v >> 31) & 1
            self.r[n] = (v << count) & 0xFFFFFFFF
        elif kind == "rotl":
            c = count % 32
            self.T = (v >> (31 - c + 1)) & 1 if c else self.T
            self.r[n] = ((v << c) | (v >> (32 - c))) & 0xFFFFFFFF if c else v
        elif kind == "rotr":
            c = count % 32
            self.T = (v >> (c - 1)) & 1 if c else self.T
            self.r[n] = ((v >> c) | (v << (32 - c))) & 0xFFFFFFFF if c else v
        elif kind == "rotcl":
            c = count % 32
            old_t = self.T
            if c:
                self.T = (v >> (32 - c)) & 1
                self.r[n] = ((v << c) | (old_t << (c - 1)) | (v >> (32 - c))) & 0xFFFFFFFF if c > 1 else ((v << 1) | old_t) & 0xFFFFFFFF
            else:
                self.r[n] = v
        elif kind == "rotcr":
            # ROTCR: rotate right through carry. T -> MSB, LSB -> T. (SH-2 only
            # encodes count=1; general c handled for completeness.)
            c = count % 32
            old_t = self.T
            if c:
                self.T = (v >> (c - 1)) & 1
                self.r[n] = ((v >> c) | (old_t << (32 - c))) & 0xFFFFFFFF
            else:
                self.r[n] = v
        self._next(pc)

    def _op_shll(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "shll")
    def _op_shll2(self, pc, op, t): self._shift(pc, _reg(t[0]), 2, "shll")
    def _op_shll8(self, pc, op, t): self._shift(pc, _reg(t[0]), 8, "shll")
    def _op_shll16(self, pc, op, t): self._shift(pc, _reg(t[0]), 16, "shll")
    def _op_shlr(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "shlr")
    def _op_shlr2(self, pc, op, t): self._shift(pc, _reg(t[0]), 2, "shlr")
    def _op_shlr8(self, pc, op, t): self._shift(pc, _reg(t[0]), 8, "shlr")
    def _op_shlr16(self, pc, op, t): self._shift(pc, _reg(t[0]), 16, "shlr")
    def _op_shar(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "shar")
    def _op_shal(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "shal")
    def _op_rotl(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "rotl")
    def _op_rotr(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "rotr")
    def _op_rotcr(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "rotcr")  # rotate through carry, right
    def _op_rotcl(self, pc, op, t): self._shift(pc, _reg(t[0]), 1, "rotcl")

    def _op_dt(self, pc, op, t):
        n = _reg(t[0])
        self.r[n] = (self.r[n] - 1) & 0xFFFFFFFF
        self.T = 1 if self.r[n] == 0 else 0
        self._next(pc)

    # ================= multiply / divide =================
    def _op_mull(self, pc, op, t):
        self.r[_reg(t[1])] = (self.r[_reg(t[1])] & 0xFFFF) * (self.r[_reg(t[0])] & 0xFFFF) & 0xFFFFFFFF
        self._next(pc)

    def _op_muluw(self, pc, op, t):
        self.r[_reg(t[1])] = (self.r[_reg(t[1])] & 0xFFFF) * (self.r[_reg(t[0])] & 0xFFFF)
        self._next(pc)

    def _op_mulsw(self, pc, op, t):
        a = self.r[_reg(t[1])] & 0xFFFF
        b = self.r[_reg(t[0])] & 0xFFFF
        a = a - 65536 if a & 0x8000 else a
        b = b - 65536 if b & 0x8000 else b
        self.r[_reg(t[1])] = (a * b) & 0xFFFFFFFF
        self._next(pc)

    def _op_dmulsl(self, pc, op, t):
        a, b = self._s32(self.r[_reg(t[1])]), self._s32(self.r[_reg(t[0])])
        p = a * b
        self.macl = p & 0xFFFFFFFF
        self.mach = (p >> 32) & 0xFFFFFFFF
        self._next(pc)

    def _op_div0u(self, pc, op, t):
        # DIV0U: M=0, Q=0, T=0 (Sh7055h.pdf table 2.13)
        self.Q = 0; self.M = 0; self.T = 0
        self._next(pc)

    def _op_div0s(self, pc, op, t):
        # DIV0S: MSB(Rn) -> Q, MSB(Rm) -> M, M^Q -> T
        self.Q = (self.r[_reg(t[1])] >> 31) & 1
        self.M = (self.r[_reg(t[0])] >> 31) & 1
        self.T = self.M ^ self.Q
        self._next(pc)

    def _op_div1(self, pc, op, t):
        # DIV1 — full Q/M algorithm per Renesas SH instruction set reference
        # (shared-ptr.com/sh_insns.html, "void DIV1"): single-step non-restoring
        # division. old_q = Q; Q = MSB(Rn); Rn = (Rn<<1)|T; conditional add/sub
        # with borrow/carry detect; Q updated from borrow/carry; T = (Q == M).
        n, m = _reg(t[1]), _reg(t[0])
        r = self.r
        old_q = self.Q
        self.Q = (r[n] >> 31) & 1
        rm = r[m]
        r[n] = ((r[n] << 1) | self.T) & 0xFFFFFFFF
        if old_q == 0:
            if self.M == 0:
                tmp0 = r[n]; r[n] = (r[n] - rm) & 0xFFFFFFFF
                borrow = 1 if r[n] > tmp0 else 0
                if self.Q == 0: self.Q = borrow
                else: self.Q = 1 if borrow == 0 else 0
            else:
                tmp0 = r[n]; r[n] = (r[n] + rm) & 0xFFFFFFFF
                carry = 1 if r[n] < tmp0 else 0
                if self.Q == 0: self.Q = 1 if carry == 0 else 0
                else: self.Q = carry
        else:
            if self.M == 0:
                tmp0 = r[n]; r[n] = (r[n] + rm) & 0xFFFFFFFF
                carry = 1 if r[n] < tmp0 else 0
                if self.Q == 0: self.Q = carry
                else: self.Q = 1 if carry == 0 else 0
            else:
                tmp0 = r[n]; r[n] = (r[n] - rm) & 0xFFFFFFFF
                borrow = 1 if r[n] > tmp0 else 0
                if self.Q == 0: self.Q = 1 if borrow == 0 else 0
                else: self.Q = borrow
        self.T = 1 if self.Q == self.M else 0
        self._next(pc)

    # ================= system regs =================
    def _sts_val(self, regname):
        return {"sr": self.sr, "gbr": self.gbr, "vbr": self.vbr,
                "mach": self.mach, "macl": self.macl, "pr": self.pr,
                "fpscr": self.fpscr, "fpul": self.fpul}[regname]

    def _op_stc(self, pc, op, t):
        self.r[_reg(t[1])] = self._sts_val(t[0]) & 0xFFFFFFFF
        self._next(pc)

    def _op_stcl(self, pc, op, t):
        # 'gbr,@-r15' etc
        regname = t[0]
        self.r[15] = (self.r[15] - 4) & 0xFFFFFFFF
        self.w32(self.r[15], self._sts_val(regname))
        self._next(pc)

    def _op_sts(self, pc, op, t):
        self.r[_reg(t[1])] = self._sts_val(t[0]) & 0xFFFFFFFF
        self._next(pc)

    def _op_stsl(self, pc, op, t):
        self.r[15] = (self.r[15] - 4) & 0xFFFFFFFF
        self.w32(self.r[15], self._sts_val(t[0]))
        self._next(pc)

    def _lds_val_set(self, regname, v):
        if regname == "sr": self.sr = v & 0xFFFFFFFF
        elif regname == "gbr": self.gbr = v
        elif regname == "vbr": self.vbr = v
        elif regname == "mach": self.mach = v
        elif regname == "macl": self.macl = v
        elif regname == "pr": self.pr = v
        elif regname == "fpscr": self.fpscr = v
        elif regname == "fpul": self.fpul = v

    def _op_ldc(self, pc, op, t):
        self._lds_val_set(t[1], self.r[_reg(t[0])])
        self._next(pc)
        if t[1].lower() == "sr":
            self._deliver_pending()

    def _op_ldcl(self, pc, op, t):
        # '@r15+,gbr'
        v = self.r32(self.r[15])
        self.r[15] = (self.r[15] + 4) & 0xFFFFFFFF
        self._lds_val_set(t[1], v)
        self._next(pc)

    def _op_lds(self, pc, op, t):
        self._lds_val_set(t[1], self.r[_reg(t[0])])
        self._next(pc)

    def _op_ldsl(self, pc, op, t):
        v = self.r32(self.r[15])
        self.r[15] = (self.r[15] + 4) & 0xFFFFFFFF
        self._lds_val_set(t[1], v)
        self._next(pc)

    # ================= FPU =================
    # SH-2E FR registers are 32-bit single precision: every arithmetic result
    # is rounded to float32 (E1 fix). Loads from memory are already f32.
    def _fr(self, v):
        return _f32(_bits(float(v)))

    def _op_fmovs(self, pc, op, t):
        a, b = t[0], t[1]
        if a.startswith("@"):  # load: fmov.s @ea, FRn
            dst = _freg(b)
            if a.endswith("+"):  # @rN+
                base = _reg(a[1:-1])
                addr = self.r[base]
                self.r[base] = (self.r[base] + 4) & 0xFFFFFFFF
            elif _DISP_REG.match(a):
                m = _DISP_REG.match(a)
                addr = (self.r[int(m.group(2))] + int(m.group(1), 16)) & 0xFFFFFFFF
            elif _R0_REG.match(a):
                addr = (self.r[0] + self.r[int(_R0_REG.match(a).group(1))]) & 0xFFFFFFFF
            else:  # @rN
                addr = self.r[_reg(a[1:])]
            self.fr[dst] = _f32(self.r32(addr))
        else:  # store: fmov.s FRn, @ea
            src = _freg(a)
            if b.endswith("+"):  # @rN+
                base = _reg(b[1:-1])
                addr = self.r[base]
                self.r[base] = (self.r[base] + 4) & 0xFFFFFFFF
            elif b.startswith("@-"):  # @-rN
                base = _reg(b[2:])
                self.r[base] = (self.r[base] - 4) & 0xFFFFFFFF
                addr = self.r[base]
            elif _DISP_REG.match(b):
                m = _DISP_REG.match(b)
                addr = (self.r[int(m.group(2))] + int(m.group(1), 16)) & 0xFFFFFFFF
            elif _R0_REG.match(b):
                addr = (self.r[0] + self.r[int(_R0_REG.match(b).group(1))]) & 0xFFFFFFFF
            else:  # @rN
                addr = self.r[_reg(b[1:])]
            self.w32(addr, _bits(self.fr[src]))
        self._next(pc)

    def _op_fmov(self, pc, op, t):
        self.fr[_freg(t[1])] = self.fr[_freg(t[0])]
        self._next(pc)

    def _op_fadd(self, pc, op, t): self.fr[_freg(t[1])] = self._fr(self.fr[_freg(t[1])] + self.fr[_freg(t[0])]); self._next(pc)
    def _op_fsub(self, pc, op, t): self.fr[_freg(t[1])] = self._fr(self.fr[_freg(t[1])] - self.fr[_freg(t[0])]); self._next(pc)
    def _op_fmul(self, pc, op, t): self.fr[_freg(t[1])] = self._fr(self.fr[_freg(t[1])] * self.fr[_freg(t[0])]); self._next(pc)

    def _op_fdiv(self, pc, op, t):
        # SH FPU follows IEEE: x/0 = +/-inf, 0/0 = NaN (no Python exception)
        import math
        a, b = self.fr[_freg(t[1])], self.fr[_freg(t[0])]
        if b == 0.0:
            if a == 0.0 or math.isnan(a) or math.isnan(b):
                self.fr[_freg(t[1])] = math.nan
            else:
                self.fr[_freg(t[1])] = math.copysign(math.inf, a) * math.copysign(1.0, b)
        else:
            self.fr[_freg(t[1])] = self._fr(a / b)
        self._next(pc)

    def _op_fcmpeq(self, pc, op, t):
        self.T = 1 if self.fr[_freg(t[1])] == self.fr[_freg(t[0])] else 0
        self._next(pc)

    def _op_fcmpgt(self, pc, op, t):
        self.T = 1 if self.fr[_freg(t[1])] > self.fr[_freg(t[0])] else 0
        self._next(pc)

    def _op_fldi0(self, pc, op, t): self.fr[_freg(t[0])] = 0.0; self._next(pc)
    def _op_fldi1(self, pc, op, t): self.fr[_freg(t[0])] = 1.0; self._next(pc)

    def _op_fabs(self, pc, op, t):
        self.fr[_freg(t[0])] = self._fr(abs(self.fr[_freg(t[0])])); self._next(pc)

    def _op_fneg(self, pc, op, t): self.fr[_freg(t[0])] = self._fr(-self.fr[_freg(t[0])]); self._next(pc)

    def _op_flds(self, pc, op, t):  # flds FRn,FPUL
        self.fpul = _bits(self.fr[_freg(t[0])]); self._next(pc)

    def _op_fsts(self, pc, op, t):  # fsts FPUL,FRn
        self.fr[_freg(t[1])] = _f32(self.fpul); self._next(pc)

    def _op_float(self, pc, op, t):  # float FPUL,FRn
        import math
        self.fr[_freg(t[1])] = self._fr(float(struct.unpack("<i", struct.pack("<I", self.fpul))[0]))
        self._next(pc)

    def _op_ftrc(self, pc, op, t):  # ftrc FRn,FPUL
        v = self.fr[_freg(t[0])]
        self.fpul = int(v) & 0xFFFFFFFF
        self._next(pc)

    def _op_fmac(self, pc, op, t):  # fmac fr0,frM,frN : frN += fr0*frM (single rounding on SH-2E)
        self.fr[_freg(t[2])] = self._fr(self.fr[_freg(t[2])] + self.fr[0] * self.fr[_freg(t[1])])
        self._next(pc)
