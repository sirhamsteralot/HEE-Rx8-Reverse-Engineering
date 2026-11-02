"""Knock-retard state machine: ROM functions 0x13a60/0x13b40 vs the host
reimplementation reverse-engineered/reimplementation/rx8_knock.c (float32
Python port below mirrors the C line by line).

Validated against the ROM pinned in the emulator profile
(60E15120_N3J1E; SHA-256 in binaries/../submodule manifest / emu profile).
The ROM's own 2-D lookups (0x2068) supply the table values fed to the port,
so the comparison covers the decision/pacing/clamp logic, not the lookup
interpolation. Run: python -m pytest tests/test_knock_retard_dynamic.py
"""
import os
import struct
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

# RAM cells (see knock_control_report.md section 8 memory map)
RETARD = 0xFFFFA734        # knock_retard_ffffa734 (float)
RETARD_MIRROR = 0xFFFFA738
RECOVERY_TARGET = 0xFFFFA744
ACTIVE = 0xFFFFA73C        # knock_active_ffffa73c
ENABLE = 0xFFFFA73D        # knock_enable_ffffa73d
HEALTHY = 0xFFFFA73E       # knock_sensors_healthy_ffffa73e
ACTIVE_PREV = 0xFFFFA74C   # knock_active_previous_ffffa74c
COUNTER_A = 0xFFFFA74A
COUNTER_B = 0xFFFFA74B
ATTACK_COND = 0xFFFFC05C   # knock_attack_condition_ffffc05c
TRANSIENT = 0xFFFFC05D     # knock_transient_flag_ffffc05d
RPM = 0xFFFFB548           # engine_speed_rpm_ffffb548 (float)
ALT_SEL = 0xFFFFB534       # DAT_ffffb534: alt clamp-min table when ==1
ALT_GT4 = 0xFFFFBC3D       # DAT_ffffbc3d: alt table needs value > 4
LEARNED = 0xFFFF8038       # 8-byte checksummed float cell (0x3dc22)

# ROM functions / tables
ATTACK_FN = 0x13A60        # knock_retard_attack (void, RAM only)
RECOVER_FN = 0x13B40       # knock_retard_slow_recovery (void, RAM only)
LOOKUP2D = 0x2068          # lookup_2d_descriptor_scaled(fr4=axis, r4=desc) -> fr0
TBL_FAILSAFE = 0x6AFA4     # tbl_knock_recovery_target_0006afa4
TBL_LEARNED = 0x6AFB8      # tbl_knock_learned_retard_scale_0006afb8
TBL_CLAMP_MIN = 0x6AF68    # tbl_knock_retard_clamp_min_0006af68
TBL_CLAMP_MIN_ALT = 0x6AF7C
TBL_CLAMP_MAX = 0x6AF90    # tbl_knock_retard_clamp_max_0006af90


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def ref_clamp(v, lo, hi):  # rx8_clamp_float @0x2404, as in test_phase1_dynamic
    v, lo, hi = f32(v), f32(lo), f32(hi)
    if not (v > lo):
        return lo
    return v if hi > v else hi


def add_u8_sat(a, b):  # rx8_add_u8_saturate @0x2478
    s = (a & 0xFF) + (b & 0xFF)
    return 0xFF if s > 0xFE else s


# --- float32 port of reverse-engineered/reimplementation/rx8_knock.c --------

def ref_attack(retard, active_prev, enable, healthy, active, attack_cond,
               failsafe, learned, clamp_min, clamp_max):
    """Returns (retard, mirror, recovery_target_or_None, active_previous)."""
    recovery_target = None  # None = ROM does not write 0xffffa744 on this path
    prev = active
    if enable == 0:
        target = 0.0
    elif healthy == 0:
        target = failsafe
        recovery_target = target
    else:
        target = retard
        if active_prev == 0:
            if active == 1:
                target = learned
                recovery_target = target
        elif active == 1 and attack_cond == 1:
            target = f32(f32(retard) - 1.0)
    retard = ref_clamp(target, clamp_min, clamp_max)
    return retard, retard, recovery_target, prev


def ref_recover(retard, counter_a, counter_b, active, attack_cond, transient,
                clamp_min, clamp_max):
    """Returns (retard, counter_a, counter_b)."""
    target = retard
    if active == 1 and attack_cond == 0:
        if transient == 0:
            counter_b = 0
            if 0x3D < counter_a:
                target = f32(f32(retard) + 0.35)
                counter_a = 0
            counter_a = add_u8_sat(counter_a, 1)
        else:
            counter_a = 0
            if 0x3D < counter_b:
                counter_b = 0
                target = f32(f32(retard) + 0.35)
            counter_b = add_u8_sat(counter_b, 1)
    else:
        counter_a = 0
        counter_b = 0
    retard = ref_clamp(target, clamp_min, clamp_max)
    return retard, counter_a, counter_b


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def rom_lookup(bus, cpu, desc, value):
    """ROM's own lookup_2d_descriptor_scaled 0x2068 -> float result."""
    _, r, _ = harness.call(bus, cpu, LOOKUP2D, r_args=(desc,), fr_args=(value,))
    return r


def set_state(bus, *, retard, enable=1, healthy=1, active=1, prev=1,
              attack=0, transient=0, counter_a=0, counter_b=0, rpm=3000.0,
              alt_sel=0, alt_gt4=0, target_sentinel=0x7F7FFFFF):
    bus.write32(RETARD, harness.bits(f32(retard)))
    bus.write32(RETARD_MIRROR, harness.bits(f32(retard)))
    bus.write32(RECOVERY_TARGET, target_sentinel)
    bus.write8(ENABLE, enable)
    bus.write8(HEALTHY, healthy)
    bus.write8(ACTIVE, active)
    bus.write8(ACTIVE_PREV, prev)
    bus.write8(ATTACK_COND, attack)
    bus.write8(TRANSIENT, transient)
    bus.write8(COUNTER_A, counter_a)
    bus.write8(COUNTER_B, counter_b)
    bus.write32(RPM, harness.bits(f32(rpm)))
    bus.write8(ALT_SEL, alt_sel)
    bus.write8(ALT_GT4, alt_gt4)


def set_learned(bus, value):
    """Fill the checksummed float cell at 0xffff8038 (read by 0x3dc22)."""
    v = harness.bits(f32(value))
    bus.write32(LEARNED, v)
    s0, s1 = (v >> 16) & 0xFFFF, v & 0xFFFF
    bus.write16(LEARNED + 4, (~(s1 + s0)) & 0xFFFF)  # (short)~(s1+s0) == s2


def read_retard(bus):
    return struct.unpack(">f", struct.pack(">I", bus.read32(RETARD)))[0]


def test_attack_paths_vs_reimplementation(booted):
    """0x13a60: disabled / unhealthy / activation edge / attack / hold."""
    _, bus, cpu = booted
    rpm = 3000.0
    clamp_min = rom_lookup(bus, cpu, TBL_CLAMP_MIN, rpm)
    clamp_max = rom_lookup(bus, cpu, TBL_CLAMP_MAX, rpm)
    failsafe = rom_lookup(bus, cpu, TBL_FAILSAFE, rpm)
    assert clamp_min == -10.0 and clamp_max == 0.0 and failsafe == -10.0

    # attack step: -3.0 -> -4.0, mirror + previous-active latch updated,
    # recovery_target cell NOT written (sentinel survives)
    set_state(bus, retard=-3.0, attack=1)
    harness.call(bus, cpu, ATTACK_FN)
    exp_retard, exp_mirror, exp_target, exp_prev = ref_attack(
        -3.0, 1, 1, 1, 1, 1, failsafe, 0.0, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard) == harness.bits(-4.0)
    assert struct.unpack(">f", struct.pack(">I", bus.read32(RETARD_MIRROR)))[0] == exp_mirror
    assert bus.read32(RECOVERY_TARGET) == 0x7F7FFFFF  # untouched
    assert bus.read8(ACTIVE_PREV) == exp_prev == 1

    # attack clamps at the min table: -9.5 - 1.0 -> -10.0
    set_state(bus, retard=-9.5, attack=1)
    harness.call(bus, cpu, ATTACK_FN)
    assert read_retard(bus) == -10.0

    # disabled -> target 0 -> clamped to [min,max] = 0
    set_state(bus, retard=-3.0, enable=0)
    harness.call(bus, cpu, ATTACK_FN)
    assert read_retard(bus) == 0.0

    # sensors unhealthy -> fail-safe table value, written to 0xffffa744
    set_state(bus, retard=-3.0, healthy=0)
    harness.call(bus, cpu, ATTACK_FN)
    exp_retard, _, exp_target, _ = ref_attack(
        -3.0, 1, 1, 0, 1, 0, failsafe, 0.0, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard)
    assert struct.unpack(">f", struct.pack(">I", bus.read32(RECOVERY_TARGET)))[0] == exp_target

    # activation edge (prev=0, active=1) -> learned value through tbl 0x6afb8
    learned = -2.8
    set_learned(bus, learned)
    learned_target = rom_lookup(bus, cpu, TBL_LEARNED, learned)
    set_state(bus, retard=-3.0, prev=0, active=1)
    harness.call(bus, cpu, ATTACK_FN)
    exp_retard, _, exp_target, _ = ref_attack(
        -3.0, 0, 1, 1, 1, 0, failsafe, learned_target, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard)
    assert struct.unpack(">f", struct.pack(">I", bus.read32(RECOVERY_TARGET)))[0] == exp_target
    assert bus.read8(ACTIVE_PREV) == 1  # latched entry value of active

    # hold: active, no attack condition -> retard unchanged
    set_state(bus, retard=-3.0, attack=0)
    harness.call(bus, cpu, ATTACK_FN)
    assert read_retard(bus) == -3.0


def test_attack_alt_clamp_min_table(booted):
    """0x13bd2 inside 0x13a60: DAT_ffffb534==1 && DAT_ffffbc3d>4 selects the
    alt min table 0x6af7c (at 3000 rpm: -5 deg, not -10)."""
    _, bus, cpu = booted
    rpm = 3000.0
    alt_min = rom_lookup(bus, cpu, TBL_CLAMP_MIN_ALT, rpm)
    clamp_max = rom_lookup(bus, cpu, TBL_CLAMP_MAX, rpm)
    assert alt_min == -5.0
    set_state(bus, retard=-9.5, attack=1, alt_sel=1, alt_gt4=5)
    harness.call(bus, cpu, ATTACK_FN)
    exp = ref_clamp(f32(-9.5 - 1.0), alt_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp) == harness.bits(-5.0)


def test_recovery_pacing_vs_reimplementation(booted):
    """0x13b40: +0.35 deg per 62 counts, saturating u8 counters, transient
    selects counter B; inactive resets both."""
    _, bus, cpu = booted
    rpm = 3000.0
    clamp_min = rom_lookup(bus, cpu, TBL_CLAMP_MIN, rpm)
    clamp_max = rom_lookup(bus, cpu, TBL_CLAMP_MAX, rpm)

    # counter_a = 61: no step yet, counter -> 62, counter_b zeroed
    set_state(bus, retard=-3.0, active=1, attack=0, transient=0,
              counter_a=61, counter_b=7)
    harness.call(bus, cpu, RECOVER_FN)
    exp_retard, exp_a, exp_b = ref_recover(-3.0, 61, 7, 1, 0, 0, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard) == harness.bits(-3.0)
    assert bus.read8(COUNTER_A) == exp_a == 62
    assert bus.read8(COUNTER_B) == exp_b == 0

    # counter_a = 62 (> 0x3d): step +0.35 deg, counter restarts at 1
    set_state(bus, retard=-3.0, active=1, attack=0, transient=0, counter_a=62)
    harness.call(bus, cpu, RECOVER_FN)
    exp_retard, exp_a, exp_b = ref_recover(-3.0, 62, 0, 1, 0, 0, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard)
    assert harness.bits(exp_retard) == harness.bits(f32(-3.0 + 0.35))
    assert bus.read8(COUNTER_A) == exp_a == 1

    # transient flag: counter_b paces, counter_a zeroed
    set_state(bus, retard=-3.0, active=1, attack=0, transient=1,
              counter_a=9, counter_b=62)
    harness.call(bus, cpu, RECOVER_FN)
    exp_retard, exp_a, exp_b = ref_recover(-3.0, 9, 62, 1, 0, 1, clamp_min, clamp_max)
    assert harness.bits(read_retard(bus)) == harness.bits(exp_retard)
    assert bus.read8(COUNTER_A) == exp_a == 0
    assert bus.read8(COUNTER_B) == exp_b == 1

    # recovery step clamps at max table (0 deg)
    set_state(bus, retard=-0.2, active=1, attack=0, counter_a=62)
    harness.call(bus, cpu, RECOVER_FN)
    assert read_retard(bus) == 0.0

    # inactive: both counters reset, retard held
    set_state(bus, retard=-3.0, active=0, counter_a=30, counter_b=40)
    harness.call(bus, cpu, RECOVER_FN)
    assert read_retard(bus) == -3.0
    assert bus.read8(COUNTER_A) == 0 and bus.read8(COUNTER_B) == 0
