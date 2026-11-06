"""Cruise control: emulator validation of 0x4c828 cruise_switch_code_decode,
0x4ca7e cruise_speed_error_filter_stage, 0x2d83c
cruise_set_speed_adjust_integrator, 0x2df62 cruise_set_speed_apply
(60E15120_N3J1E).

Boots the profile once, sets the callees' documented RAM input globals, and
harness-calls the ROM functions; expected values come from ROM constants /
the ROM's own lookup helpers (0x2068 lookup_2d, 0x20dc lookup_3d).
Run: python -m pytest tests/test_cruise_control_dynamic.py
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

LOOKUP2D = 0x2068
LOOKUP3D = 0x20DC
SW_DECODE = 0x4C828
CRUISE_FILTER = 0x4CA7E
CRUISE_INTEGR = 0x2D83C
CRUISE_APPLY = 0x2DF62


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return harness.bits(f32(x))


def rf(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]


def wf(bus, a, v):
    bus.write32(a, bits(v))


def rv8(bus, addr, val):
    """Checksummed 8-bit readValue cell (ref_readValue_8bit_ADDRESS_VAL)."""
    bus.write8(addr, val & 0xFF)
    bus.write8(addr + 1, (~val) & 0xFF)


def rom_filter(current, previous, k, snap=1e-5):
    cur, prev, kk = f32(current), f32(previous), f32(k)
    t1 = f32(prev - cur)
    t2 = f32(1.0 - kk)
    filtered = f32(cur + t1 * t2)
    return cur if f32(snap) > abs(cur - filtered) else filtered


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def rom_lookup2d(bus, cpu, desc, x):
    return harness.call(bus, cpu, LOOKUP2D, r_args=(desc,), fr_args=(x,))[1]


def rom_lookup3d(bus, cpu, desc, x, y):
    return harness.call(bus, cpu, LOOKUP3D, r_args=(desc,), fr_args=(x, y))[1]


def test_switch_decode(booted):
    _, bus, cpu = booted
    for a in range(0xFFFFCF47, 0xFFFFCF4D):
        bus.write8(a, 0)
    bus.write8(0xFFFFBAED, 3)
    harness.call(bus, cpu, SW_DECODE)
    assert [bus.read8(a) for a in range(0xFFFFCF47, 0xFFFFCF4D)] == [0, 0, 1, 0, 0, 0]
    bus.write8(0xFFFFBAED, 6)
    harness.call(bus, cpu, SW_DECODE)
    assert [bus.read8(a) for a in range(0xFFFFCF47, 0xFFFFCF4D)] == [0, 0, 0, 0, 0, 1]


def test_error_filter_stage(booted):
    _, bus, cpu = booted
    bus.write8(0xFFFFCF4D, 0); bus.write8(0xFFFFCF4E, 0)
    bus.write8(0xFFFFCF65, 0); bus.write8(0xFFFFCF64, 0)
    bus.write8(0xFFFFBFB9, 0); bus.write8(0xFFFFBFB5, 0)
    for a in range(0xFFFFCF47, 0xFFFFCF4D):
        bus.write8(a, 0)
    for a in (0xFFFFCF34, 0xFFFFCF3A, 0xFFFFCF3C, 0xFFFFCF3E, 0xFFFFCF40):
        bus.write8(a, 0)
    wf(bus, 0xFFFFBBB4, 200.0)     # vehicle speed
    wf(bus, 0xFFFFCEE4, 100.0)     # mean12 = 100
    wf(bus, 0xFFFFCEEC, 0.0); wf(bus, 0xFFFFCEF0, 0.0)
    harness.call(bus, cpu, CRUISE_FILTER)
    assert rf(bus, 0xFFFFCEE8) == 15.0                               # clamp
    assert rf(bus, 0xFFFFCEEC) == 1.0                                # rate limit +1
    assert bits(rf(bus, 0xFFFFCEF0)) == bits(rom_filter(1.0, 0.0, 0.1))
    off = rom_lookup2d(bus, cpu, 0x6BC70, 200.0)                     # per-switch offset tbl
    assert bits(rf(bus, 0xFFFFCEF4)) == bits(f32(rf(bus, 0xFFFFCEF0) + off))
    wf(bus, 0xFFFFCEE4, -100.0); wf(bus, 0xFFFFCEEC, 0.0); wf(bus, 0xFFFFCEF0, 0.0)
    bus.write8(0xFFFFCF65, 0)
    harness.call(bus, cpu, CRUISE_FILTER)
    assert rf(bus, 0xFFFFCEE8) == -15.0


def test_integrator(booted):
    _, bus, cpu = booted
    for a in (0xFFFFBFBA, 0xFFFFBFB9, 0xFFFFBFB5):
        bus.write8(a, 0)
    bus.write8(0xFFFFBCED, 1); bus.write8(0xFFFFBD3E, 1)
    wf(bus, 0xFFFFBFA0, 110.0); wf(bus, 0xFFFFBFA4, 100.0)   # bd1c = 10 >= 8
    wf(bus, 0xFFFFBCCC, 0.0)                                  # < 1.0
    wf(bus, 0xFFFFA9B4, 100.0); wf(bus, 0xFFFFBCF8, 100.0)
    wf(bus, 0xFFFFCF1C, 3.0)                                  # band
    bus.write16(0xFFFFBD10, 0)
    for _ in range(3):
        harness.call(bus, cpu, CRUISE_INTEGR)
    assert bus.read16(0xFFFFBD10) == 3
    assert bits(rf(bus, 0xFFFFBD20)) == bits(3.0)
    exp = [rom_lookup3d(bus, cpu, d, x, 3.0) for d, x in
           ((0x6A8D0, 110.0), (0x6A8E4, 100.0), (0x6A8F8, 100.0), (0x6A90C, 110.0))]
    exp.append(rom_lookup3d(bus, cpu, 0x6A920, 3.0, 3.0))
    got = [rf(bus, a) for a in (0xFFFFBD24, 0xFFFFBD28, 0xFFFFBD2C, 0xFFFFBD30, 0xFFFFBD34)]
    assert [bits(v) for v in got] == [bits(v) for v in exp]
    assert 0.0 <= rf(bus, 0xFFFFBD08) <= 100.0


def test_set_speed_apply(booted):
    _, bus, cpu = booted
    bus.write8(0xFFFFBCED, 1); bus.write8(0xFFFFBD3E, 1)
    bus.write8(0xFFFFBCEB, 0); bus.write8(0xFFFFB53A, 0)
    rv8(bus, 0xFFFF8664, 1)
    bus.write8(0xFFFFAA68, 1)
    wf(bus, 0xFFFFBD00, 60.0); wf(bus, 0xFFFFBD08, 50.0)
    harness.call(bus, cpu, CRUISE_APPLY)
    assert rf(bus, 0xFFFFBCF8) == 100.0      # 110 clamped
    wf(bus, 0xFFFFBD08, 30.0)
    harness.call(bus, cpu, CRUISE_APPLY)
    assert rf(bus, 0xFFFFBCF8) == 90.0
    wf(bus, 0xFFFFBD08, -70.0)
    harness.call(bus, cpu, CRUISE_APPLY)
    assert rf(bus, 0xFFFFBCF8) == 0.0        # -10 clamped
    bus.write8(0xFFFFBCED, 0)                # gate off -> 0
    harness.call(bus, cpu, CRUISE_APPLY)
    assert rf(bus, 0xFFFFBCF8) == 0.0
