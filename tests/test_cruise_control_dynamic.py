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


# --- follow-up pass (reviews/cruise_control/dynamic_validation_log.txt) ---

GEAR_CAND = 0x2C324
GEAR_LATCH = 0x2C3B2
BAND_PRODUCER = 0x4DE1C
ENABLE_FLAG = 0x4C896
TP_PCT = 0x193C4
SET_SPEED_LATCH = 0x32614
CTRL_LAW = 0x2D638


def test_gear_float_band_producer(booted):
    """0x4de1c writes 0xffffcf1c = float(gear 0xffffbc3d) on this ROM
    (config byte ROM[0x7d07f] = 0 disables the switch-code band map)."""
    _, bus, cpu = booted
    for gear in range(7):
        bus.write8(0xFFFFBC3D, gear)
        for i in range(6):
            bus.write8(0xFFFFCF47 + i, 0)
        harness.call(bus, cpu, BAND_PRODUCER)
        assert rf(bus, 0xFFFFCF1C) == float(gear)
        # pressing a switch flag must NOT change cf1c while cfg byte = 0
        bus.write8(0xFFFFCF49, 1)
        harness.call(bus, cpu, BAND_PRODUCER)
        assert rf(bus, 0xFFFFCF1C) == float(gear)
        bus.write8(0xFFFFCF49, 0)


def test_gear_ratio_chain(booted):
    """0x2c324 candidate gear from rpm/vss ratio; 0x2c3b2 latches after >0xb."""
    _, bus, cpu = booted
    bus.write8(0xFFFFB534, 1)
    bus.write8(0xFFFFB53A, 0)
    wf(bus, 0xFFFFBBB4, 80.0)          # 80 km/h
    wf(bus, 0xFFFFB548, 80.0 * 71.9)    # ratio 71.9 -> gear 2
    harness.call(bus, cpu, GEAR_CAND)
    assert bus.read8(0xFFFFBC3C) == 2
    for _ in range(20):
        harness.call(bus, cpu, GEAR_LATCH)
    assert bus.read8(0xFFFFBC3D) == 2
    bus.write8(0xFFFFB53A, 1)          # neutral -> gear 0
    harness.call(bus, cpu, GEAR_LATCH)
    assert bus.read8(0xFFFFBC3D) == 0
    bus.write8(0xFFFFB53A, 0)


def test_bcf8_is_percent_output_pedal_override(booted):
    """0x4c896: cf34 = cruise_on && bcf8 >= TP% 0xffffa9b4 (pedal override);
    0x193c4: a9bc = min(max(a9b4, bcf8), c028) in the same percent domain."""
    _, bus, cpu = booted
    bus.write8(0xFFFFBCED, 1)
    wf(bus, 0xFFFFA9B4, 80.0)
    wf(bus, 0xFFFFBCF8, 50.0)
    harness.call(bus, cpu, ENABLE_FLAG)
    assert bus.read8(0xFFFFCF34) == 0
    assert rf(bus, 0xFFFFCF18) == 50.0
    wf(bus, 0xFFFFBCF8, 90.0)
    harness.call(bus, cpu, ENABLE_FLAG)
    assert bus.read8(0xFFFFCF34) == 1
    # demand mix: TP%=30, cruise output 70, limiter 100 -> a9bc = 70
    bus.write8(0xFFFFCC9B, 0); bus.write8(0xFFFFCC9C, 0); bus.write8(0xFFFFA914, 0)
    wf(bus, 0xFFFFA9B4, 30.0); wf(bus, 0xFFFFBCF8, 70.0); wf(bus, 0xFFFFC028, 100.0)
    wf(bus, 0xFFFFA9D0, 0.0); wf(bus, 0xFFFFA9D4, 0.0)
    harness.call(bus, cpu, TP_PCT)
    assert rf(bus, 0xFFFFA9BC) == 70.0


def test_set_speed_latch_kmh(booted):
    """0x32614 latches the set speed IN KM/H into learned cell 0xffff866c,
    clamp [27, 200]; target 0xffffbfa4 clamped to the same range."""
    _, bus, cpu = booted
    bus.write8(0xFFFFBD49, 0)          # cap 200 km/h
    bus.write8(0xFFFFBFB4, 1)          # latch-current-speed path
    bus.write8(0xFFFFBCE9, 0); bus.write8(0xFFFFBFC4, 0)
    for vss, exp in ((80.0, 80.0), (250.0, 200.0), (10.0, 27.0)):
        wf(bus, 0xFFFFBFA0, vss)
        wf(bus, 0xFFFFBFA4, 0.0)
        wf(bus, 0xFFFF866C, 0.0)
        harness.call(bus, cpu, SET_SPEED_LATCH)
        assert rf(bus, 0xFFFF866C) == exp
        assert rf(bus, 0xFFFFBFA4) == exp


def test_control_law_output_percent_domain(booted):
    """0x2d638: bd00 = clamp(bd04*bd18*0.01, -100, 100) from gear band x speed
    error - percent-domain output, not km/h."""
    _, bus, cpu = booted
    bus.write8(0xFFFFBCED, 1); bus.write8(0xFFFFBD3E, 1)
    wf(bus, 0xFFFFBFA0, 100.0); wf(bus, 0xFFFFBFA4, 90.0)   # error +10 km/h
    wf(bus, 0xFFFFCF1C, 3.0)                                # gear 3 band
    wf(bus, 0xFFFFBCF8, 50.0); wf(bus, 0xFFFFA9B4, 20.0)
    bus.write8(0xFFFFBBC8, 0xFD); bus.write8(0xFFFFBBC9, 0xFD)
    harness.call(bus, cpu, CTRL_LAW)
    out = rf(bus, 0xFFFFBD00)
    assert -100.0 <= out <= 100.0
    assert out != 0.0    # law engages on the speed error in percent domain
