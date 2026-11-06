"""O2 sensor response monitor: emulator validation of 0x3f924
o2_channel_filter_update, 0x3fb9e o2_response_monitor_accumulate, 0x4128e
o2_response_monitor_evaluate (60E15120_N3J1E).

Boots the profile once, sets the callees' documented RAM input globals, and
harness-calls the ROM functions; expected values come from ROM constants /
the ROM's own lookup helpers (0x20dc lookup_3d, 0x213c lookup_3d_raw_u16).
Run: python -m pytest tests/test_o2_sensor_monitor_dynamic.py
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

LOOKUP3D = 0x20DC
LOOKUP3D_RAW_U16 = 0x213C
O2_FILTER = 0x3F924
O2_ACCUM = 0x3FB9E
O2_EVAL = 0x4128E


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return harness.bits(f32(x))


def rf(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]


def wf(bus, a, v):
    bus.write32(a, bits(v))


def rom_filter(current, previous, k, snap=1e-5):
    """float32 port of rx8_first_order_filter 0x23b0: the ROM computes
    current + (previous-current)*(1-k) with a fused fmac (single rounding)."""
    cur, prev, kk = f32(current), f32(previous), f32(k)
    t1 = f32(prev - cur)
    t2 = f32(1.0 - kk)
    filtered = f32(cur + t1 * t2)
    sn = f32(snap)
    return cur if sn > abs(cur - filtered) else filtered


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def rom_lookup3d(bus, cpu, desc, x, y):
    return harness.call(bus, cpu, LOOKUP3D, r_args=(desc,), fr_args=(x, y))[1]


def test_channel_filter(booted):
    _, bus, cpu = booted
    wf(bus, 0xFFFFAA6C, 2.0)      # diag_afr_word_a
    wf(bus, 0xFFFFADEC, 1.1)      # lambda_actual
    for a in (0xFFFFC708, 0xFFFFC70C, 0xFFFFC710, 0xFFFFC714):
        wf(bus, a, 0.0)
    harness.call(bus, cpu, O2_FILTER)
    assert rf(bus, 0xFFFFC708) == 2.0                                   # k = 1.0
    assert bits(rf(bus, 0xFFFFC70C)) == bits(rom_filter(2.0, 0.0, 0.5))
    assert bits(rf(bus, 0xFFFFC710)) == bits(rom_filter(1.1, 0.0, 0.1))
    assert bits(rf(bus, 0xFFFFC714)) == bits(rom_filter(1.1, 0.0, 0.03125))
    harness.call(bus, cpu, O2_FILTER)
    assert bits(rf(bus, 0xFFFFC70C)) == bits(rom_filter(2.0, 1.0, 0.5))  # = 1.5


def test_accumulate_window_publish(booted):
    _, bus, cpu = booted
    bus.write8(0xFFFFD1C5, 0)          # DTC setting enabled
    wf(bus, 0xFFFFC0B4, 0.3)           # engine load
    wf(bus, 0xFFFFB548, 2000.0)        # rpm
    # window completion on the first call: c904 = 2 counts down to 0
    bus.write8(0xFFFFC908, 1)
    bus.write16(0xFFFFC904, 2)
    wf(bus, 0xFFFFC728, 100.0); wf(bus, 0xFFFFC758, 50.0)
    wf(bus, 0xFFFFC734, 0.0);   wf(bus, 0xFFFFC764, 0.0)
    wf(bus, 0xFFFFC740, 10.0);  wf(bus, 0xFFFFC770, 4.0)
    wf(bus, 0xFFFFC74C, 0.0);   wf(bus, 0xFFFFC77C, 0.0)
    harness.call(bus, cpu, O2_ACCUM)
    assert bus.read8(0xFFFFC701) == 1
    assert bits(rf(bus, 0xFFFFC6F0)) == bits(f32(50.0 / 100.0)) == bits(0.5)
    assert bits(rf(bus, 0xFFFFC780)) == bits(f32(4.0 / 10.0)) == bits(0.4)
    # every-2nd-run window reload: c908 = 1, c7b2 = raw-u16 lookup of 0x6b66c
    bus.write16(0xFFFFC8FC, 0)
    bus.write8(0xFFFFC908, 0)
    harness.call(bus, cpu, O2_ACCUM)
    harness.call(bus, cpu, O2_ACCUM)
    assert bus.read8(0xFFFFC908) == 1
    exp = harness.call(bus, cpu, LOOKUP3D_RAW_U16, r_args=(0x6B66C,), fr_args=(0.3, 2000.0))[0]
    assert bus.read16(0xFFFFC7B2) == exp == 18


def test_evaluate_decision(booted):
    _, bus, cpu = booted
    bus.write8(0xFFFFC908, 1)
    bus.write8(0xFFFFD1C5, 0)
    bus.write8(0xFFFFC704, 1); bus.write8(0xFFFFAE21, 1)
    bus.write8(0xFFFFC701, 1)
    wf(bus, 0xFFFFC0B4, 0.3); wf(bus, 0xFFFFB548, 2000.0)
    bus.write16(0xFFFFC7DA, 0)
    for a in (0xFFFFC7A0, 0xFFFFC7A4, 0xFFFFC7A8, 0xFFFFC7AC):
        wf(bus, a, 0.0)
    for a in (0xFFFFC6F8, 0xFFFFC6FC, 0xFFFFC798, 0xFFFFC79C):
        wf(bus, a, 0.0)
    for a in range(0xFFFFC7E6, 0xFFFFC7EE):
        bus.write8(a, 0)
    bus.write8(0xFFFFC702, 0); bus.write8(0xFFFFC703, 0)
    wf(bus, 0xFFFFC6F0, 0.5); wf(bus, 0xFFFFC6F4, 0.0)
    wf(bus, 0xFFFFC780, 0.0); wf(bus, 0xFFFFC784, 0.0)
    harness.call(bus, cpu, O2_EVAL)
    exp = [rom_lookup3d(bus, cpu, d, 0.3, 2000.0)
           for d in (0x6B680, 0x6B69C, 0x6B6B8, 0x6B6D4)]
    got = [rf(bus, a) for a in (0xFFFFC6F8, 0xFFFFC6FC, 0xFFFFC798, 0xFFFFC79C)]
    assert [bits(v) for v in got] == [bits(v) for v in exp]
    assert exp[2] == exp[3] == -1.0     # 1x1 constant descriptors (0 * mult + off -1)
    assert [bus.read8(0xFFFFC7E6 + i) for i in range(4)] == [1, 0, 1, 1]   # fail flags
    assert [bus.read8(0xFFFFC7EA + i) for i in range(4)] == [0, 1, 0, 0]   # pass flags
    assert bus.read8(0xFFFFC702) == 0 and bus.read8(0xFFFFC703) == 1       # pending path
    # all four ratios above threshold -> confirmed cell
    for a in range(0xFFFFC7E6, 0xFFFFC7EE):
        bus.write8(a, 0)
    bus.write8(0xFFFFC702, 0); bus.write8(0xFFFFC703, 0)
    for a in (0xFFFFC6F0, 0xFFFFC6F4, 0xFFFFC780, 0xFFFFC784):
        wf(bus, a, 0.5)
    harness.call(bus, cpu, O2_EVAL)
    assert bus.read8(0xFFFFC702) == 1 and bus.read8(0xFFFFC703) == 0
    assert [bus.read8(0xFFFFC7E6 + i) for i in range(4)] == [1, 1, 1, 1]
