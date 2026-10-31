"""Emulator fidelity regression tests (ROADMAP group B, 2026-10-31).

Covers the 2026-10-31 hardening pass:
- E7: ROTCR direction (was aliased to ROTCL) + full DIV1 Q/M algorithm
  (SR bits 8/9) validated against the ROM's own division routine as oracle.
- E1: FPU results rounded to float32 (SH-2E FR registers are single precision).
- Interrupt masking: pending interrupts delivered when SR.I is lowered.

Run: python -m pytest tests/test_emu_fidelity.py
"""
import os
import struct
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu"))

import emu  # noqa: E402
import harness  # noqa: E402
import sh2e  # noqa: E402
from sh2e import SH2E  # noqa: E402

PROFILE = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu", "profiles", "60E15120_N3J1E.json")


class FakeBus:
    def __init__(self):
        self.mem = bytearray(0x10000)
        self.cycle = 0

    def read8(self, a): return self.mem[a & 0xFFFF]
    def read16(self, a): return int.from_bytes(self.mem[(a & 0xFFFF):(a & 0xFFFF) + 2], "big")
    def read32(self, a): return int.from_bytes(self.mem[(a & 0xFFFF):(a & 0xFFFF) + 4], "big")
    def write8(self, a, v): self.mem[a & 0xFFFF] = v & 0xFF
    def write16(self, a, v): self.mem[(a & 0xFFFF):(a & 0xFFFF) + 2] = (v & 0xFFFF).to_bytes(2, "big")
    def write32(self, a, v): self.mem[(a & 0xFFFF):(a & 0xFFFF) + 4] = (v & 0xFFFFFFFF).to_bytes(4, "big")
    def tick(self, n): pass


def s32(v): return v - (1 << 32) if v & 0x80000000 else v


# --- E7: ROTCR / ROTCL -------------------------------------------------------

def test_rotcr_rotate_right_through_carry():
    cpu = SH2E(FakeBus())
    cpu.r[1] = 1; cpu.T = 0
    cpu._exec(0x1000, 0x4125)  # rotcr r1
    assert cpu.r[1] == 0 and cpu.T == 1          # LSB(1) -> T, T(0) -> MSB
    cpu.r[1] = 0x80000000; cpu.T = 1
    cpu._exec(0x1000, 0x4125)
    assert cpu.r[1] == 0xC0000000 and cpu.T == 0  # T(1) -> MSB, MSB -> shifted out


def test_rotcl_rotate_left_through_carry():
    cpu = SH2E(FakeBus())
    cpu.r[1] = 0x80000000; cpu.T = 0
    cpu._exec(0x1000, 0x4124)  # rotcl r1
    assert cpu.r[1] == 0 and cpu.T == 1
    cpu.r[1] = 1; cpu.T = 1
    cpu._exec(0x1000, 0x4124)
    assert cpu.r[1] == 3 and cpu.T == 0


# --- E7: DIV1 full Q/M algorithm, ROM division routine as oracle -------------

@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    assert cpu.pc == 0x3DAC
    return prof, bus, cpu


@pytest.mark.parametrize("d,v", [(100, 7), (1000, 3), (123456789, 1000),
                                 (2147483647, 2), (5, 10), (999999, 13), (0x7EADBEEF, 0x1234)])
def test_rom_division_quotient(booted, d, v):
    """ref_LongFunc (0x2158) signed divide: r4 must hold the truncated quotient.
    Validates the full DIV1 Q/M implementation against the ROM itself."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x2158, r_args=(d & 0xFFFFFFFF, v & 0xFFFFFFFF))
    q = abs(d) // abs(v)
    if (d < 0) != (v < 0):
        q = -q
    assert s32(cpu.r[4]) == q, f"{d}/{v}: r4={s32(cpu.r[4])} expected {q}"


def test_div1_qm_bits_in_sr():
    """DIV0S must set Q=SR bit8, M=SR bit9, T=M^Q (Sh7055h.pdf fig 2.2)."""
    cpu = SH2E(FakeBus())
    cpu.r[3] = 0x80000000   # Rn negative -> Q=1
    cpu.r[5] = 7            # Rm positive -> M=0
    cpu._exec(0x1000, 0x2357)  # div0s r5,r3
    assert cpu.Q == 1 and cpu.M == 0 and cpu.T == 1
    assert (cpu.sr >> 8) & 1 == 1 and (cpu.sr >> 9) & 1 == 0


# --- E1: FPU float32 rounding -------------------------------------------------

def test_fpu_results_rounded_to_f32():
    cpu = SH2E(FakeBus())
    # 0.1 + 0.2 in double = 0.30000000000000004; in f32 = 0.3 (0x3e99999a)
    cpu.fr[1] = harness.f32(0.1)
    cpu.fr[2] = harness.f32(0.2)
    cpu._exec(0x1000, 0xF120)  # fadd fr2,fr1 -> fr1 += fr2
    # result must be exactly the f32-rounded value, not the host double
    assert cpu.fr[1] == harness.f32(harness.f32(0.1) + harness.f32(0.2))
    assert sh2e._bits(cpu.fr[1]) == 0x3E99999A


# --- interrupt masking / pending delivery -------------------------------------

def test_masked_interrupt_deferred_until_mask_lowered():
    cpu = SH2E(FakeBus())
    cpu.vbr = 0
    # IVT[0x100] -> handler at 0x5000
    struct.pack_into(">I", cpu.bus.mem, 0x100, 0x5000)
    cpu.r[15] = 0x8000
    cpu.sr = 0x00F0  # mask = 15: priority-10 interrupt must be deferred
    cpu.interrupt(0x100, priority=10)
    assert cpu.pc != 0x5000 and len(cpu.pending) == 1
    # lower the mask (as ldc r0,sr with r0=0 would) and deliver pending
    cpu.r[0] = 0x0000
    cpu._op_ldc(0x1000, 0x0000, ["r0", "sr"])
    assert cpu.pc == 0x5000 and not cpu.pending


def test_unmasked_interrupt_fires_immediately():
    cpu = SH2E(FakeBus())
    cpu.vbr = 0
    struct.pack_into(">I", cpu.bus.mem, 0x100, 0x5000)
    cpu.r[15] = 0x8000
    cpu.sr = 0x0000
    cpu.interrupt(0x100, priority=10)
    assert cpu.pc == 0x5000
