"""E2RAM non-volatile storage codec: emulator validation of 0x23844
e2ram_block_decode and 0x244bc e2ram_block_encode (60E15120_N3J1E).

Boots the profile once, sets the codec's documented RAM input globals, and
harness-calls the ROM functions; expected values are the affine steps verified
in the ROM literal pools (see tests/test_e2ram_nv_storage.py).
Run: python -m pytest tests/test_e2ram_nv_storage_dynamic.py
"""
import math
import os
import struct
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

E2RAM_DECODE = 0x23844
E2RAM_ENCODE = 0x244BC


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return harness.bits(f32(x))


def rf(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]


def wf(bus, a, v):
    bus.write32(a, bits(v))


def rvf(bus, addr, val):
    """Checksummed float readValue cell (like the 0xffff8038 learned cell)."""
    v = bits(val)
    bus.write32(addr, v)
    s0, s1 = (v >> 16) & 0xFFFF, v & 0xFFFF
    bus.write16(addr + 4, (~(s1 + s0)) & 0xFFFF)


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def test_block_decode(booted):
    _, bus, cpu = booted
    for a in range(0xFFFFB47A, 0xFFFFB49D):
        bus.write8(a, 0)
    for a in range(0xFFFFB526, 0xFFFFB534):
        bus.write8(a, 0)
    harness.call(bus, cpu, E2RAM_DECODE)     # init unpacker (prev=0, out=0)
    bus.write16(0xFFFFB47A, 1000)
    bus.write16(0xFFFFB47C, 2000)
    bus.write8(0xFFFFB488, 200)
    bus.write8(0xFFFFB489, 0x85)             # sign bit set
    bus.write8(0xFFFFB48A, 0xA5)
    bus.write16(0xFFFFB498, 5000)
    bus.write8(0xFFFFB47E, 0x11); bus.write8(0xFFFFB480, 0x22)
    harness.call(bus, cpu, E2RAM_DECODE)
    harness.call(bus, cpu, E2RAM_DECODE)     # unpacker latches on stable byte
    assert bits(rf(bus, 0xFFFFB4B0)) == bits(f32(1000 * 0.030517578125))
    assert bits(rf(bus, 0xFFFFB4B4)) == bits(f32(2000 * 0.030517578125))
    assert bits(rf(bus, 0xFFFFB4B8)) == bits(f32(200 * 0.078125))
    assert bits(rf(bus, 0xFFFFB4BC)) == bits(f32(-(123 * 0.78125)))
    assert bits(rf(bus, 0xFFFFB4C0)) == bits(f32(5000 * 7.62939453125e-05))
    assert bus.read8(0xFFFFB4CC) == 0x11 and bus.read8(0xFFFFB4CE) == 0x22
    # 0xa5 = bits 0,2,5,7 -> first flag group (7 bits) = 1,0,1,0,0,1,0
    assert [bus.read8(a) for a in range(0xFFFFB4EC, 0xFFFFB4F3)] == [1, 0, 1, 0, 0, 1, 0]


def test_block_encode(booted):
    _, bus, cpu = booted
    wf(bus, 0xFFFFB40C, 30.517578125)
    wf(bus, 0xFFFFB414, -5.0)
    wf(bus, 0xFFFFB594, 0.00030517578125)
    rvf(bus, 0xFFFF807C, 2.0)
    rvf(bus, 0xFFFF8084, 4.0)
    bus.write8(0xFFFFA9C4, 0x55)
    wf(bus, 0xFFFFB548, 3000.0)
    bus.write8(0xFFFFAA68, 1)                # fault bit 0
    for a in range(0xFFFFB442, 0xFFFFB46D):
        bus.write8(a, 0)
    harness.call(bus, cpu, E2RAM_ENCODE)
    u16 = lambda a: bus.read16(a)
    assert u16(0xFFFFB442) == 1000 == u16(0xFFFFB444)
    assert struct.unpack(">h", struct.pack(">H", u16(0xFFFFB446)))[0] == -164
    assert u16(0xFFFFB448) == 1
    assert u16(0xFFFFB44A) == math.trunc(2.0 / 0.030517578125 + 0.5) == 66
    assert u16(0xFFFFB44C) == math.trunc(4.0 / 0.030517578125 + 0.5) == 131
    assert bus.read8(0xFFFFB44E) == 0x55
    assert bus.read8(0xFFFFB459) & 1 == 1    # aa68 fault bit packed
    assert u16(0xFFFFB464) == 15360          # 3000 rpm / 0.1953125
