"""Idle target RPM calculation: emulator validation of 0x1506c
idle_target_rpm_calculate (60E15120_N3J1E).

Boots the profile once, sets the documented RAM input globals, and
harness-calls the ROM function; expected values come from the Idle Target
table 0x69370 via the ROM's own lookup_2d 0x2068.
Run: python -m pytest tests/test_idle_target_control_dynamic.py
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
IDLE_CALC = 0x1506C


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return harness.bits(f32(x))


def rf(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]


def wf(bus, a, v):
    bus.write32(a, bits(v))


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def rom_lookup2d(bus, cpu, desc, x):
    return harness.call(bus, cpu, LOOKUP2D, r_args=(desc,), fr_args=(x,))[1]


def test_idle_target_rpm(booted):
    _, bus, cpu = booted
    bus.write8(0xFFFFA428, 1)        # engine running
    bus.write8(0xFFFFA42C, 0)        # injectors on
    bus.write16(0xFFFFA424, 0x500)   # running timer > 0x4e2
    bus.write16(0xFFFFA804, 0x300)   # > 0x271
    wf(bus, 0xFFFFA7C8, 13.5)         # filtered battery > 12.0
    bus.write8(0xFFFFA7B7, 1); bus.write16(0xFFFFA806, 0x500)
    bus.write8(0xFFFFB534, 1); bus.write8(0xFFFFB53C, 0)
    bus.write16(0xFFFFA818, 0); bus.write16(0xFFFFA81A, 0)
    wf(bus, 0xFFFFA7CC, 500.0)
    wf(bus, 0xFFFFBBB4, 0.0)
    bus.write16(0xFFFFA81C, 0)
    wf(bus, 0xFFFFA7AC, 0.0)
    bus.write8(0xFFFFD26A, 0)
    for coolant, exp in ((-40.0, 1700.0), (20.0, 1450.0), (80.0, 810.0)):
        wf(bus, 0xFFFFA990, coolant)
        harness.call(bus, cpu, IDLE_CALC)
        assert bits(rf(bus, 0xFFFFA800)) == bits(exp)
        assert bits(rf(bus, 0xFFFFA800)) == bits(rom_lookup2d(bus, cpu, 0x69370, coolant))
    # 850 rpm floor with the idle latch set: coolant 80 -> max-chain 820 -> 850
    wf(bus, 0xFFFFA990, 80.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 850.0
    wf(bus, 0xFFFFA990, -40.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 1700.0
    # override path: d26a = 1 writes d244 straight to the output
    bus.write8(0xFFFFD26A, 1)
    wf(bus, 0xFFFFD244, 777.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 777.0
    bus.write8(0xFFFFD26A, 0)
