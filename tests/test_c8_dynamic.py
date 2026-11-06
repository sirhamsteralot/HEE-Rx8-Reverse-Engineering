"""ROADMAP C item 11 (dynamic-validation bullet): emulator validation of the
seven large control bodies labeled in C item 8 (PR #33), 60E15120_N3J1E.

Pattern: tests/test_knock_retard_dynamic.py — boot the profile once, set the
callees' documented RAM input globals explicitly (harness `ram=`/bus writes;
no sensor faking), harness.call() the ROM function, and compare against
expected values computed from ROM constants / the ROM's own lookup helpers
(0x2068 lookup_2d, 0x20dc lookup_3d, 0x213c lookup_3d_raw_u16).

Covered: 0x3f924 o2_channel_filter_update, 0x3fb9e o2_response_monitor_accumulate,
0x4128e o2_response_monitor_evaluate, 0x4c828 cruise_switch_code_decode,
0x4ca7e cruise_speed_error_filter_stage, 0x2d83c cruise_set_speed_adjust_integrator,
0x2df62 cruise_set_speed_apply, 0x23844 e2ram_block_decode, 0x244bc
e2ram_block_encode, 0x1506c idle_target_rpm_calculate, 0x2a4f8
hcan_mailbox_config_compare.

Run: python -m pytest tests/test_c8_dynamic.py
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
ROM_PATH = os.path.join(
    os.path.dirname(__file__), "..", "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Stock_ROMs", "60E15120_N3J1E.bin")
ROM = open(ROM_PATH, "rb").read()

LOOKUP2D = 0x2068           # lookup_2d_descriptor_scaled(fr4=axis, r4=desc) -> fr0
LOOKUP3D = 0x20DC           # lookup_3d_descriptor_scaled(fr4=x, fr5=y, r4=desc) -> fr0
LOOKUP3D_RAW_U16 = 0x213C   # rx8_lookup_3d_raw_u16(fr4=x, fr5=y, r4=desc) -> r0

O2_FILTER = 0x3F924
O2_ACCUM = 0x3FB9E
O2_EVAL = 0x4128E
SW_DECODE = 0x4C828
CRUISE_FILTER = 0x4CA7E
CRUISE_INTEGR = 0x2D83C
CRUISE_APPLY = 0x2DF62
E2RAM_DECODE = 0x23844
E2RAM_ENCODE = 0x244BC
IDLE_CALC = 0x1506C
CAN_COMPARE = 0x2A4F8


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


def rvf(bus, addr, val):
    """Checksummed float readValue cell (like the 0xffff8038 learned cell)."""
    v = bits(val)
    bus.write32(addr, v)
    s0, s1 = (v >> 16) & 0xFFFF, v & 0xFFFF
    bus.write16(addr + 4, (~(s1 + s0)) & 0xFFFF)


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def rom_lookup2d(bus, cpu, desc, x):
    return harness.call(bus, cpu, LOOKUP2D, r_args=(desc,), fr_args=(x,))[1]


def rom_lookup3d(bus, cpu, desc, x, y):
    return harness.call(bus, cpu, LOOKUP3D, r_args=(desc,), fr_args=(x, y))[1]


def rom_filter(current, previous, k, snap=1e-5):
    """float32 port of rx8_first_order_filter 0x23b0: the ROM computes
    current + (previous-current)*(1-k) with a fused fmac (product+sum in
    double, single rounding), then snaps to current within snap."""
    cur, prev, kk = f32(current), f32(previous), f32(k)
    t1 = f32(prev - cur)
    t2 = f32(1.0 - kk)
    filtered = f32(cur + t1 * t2)  # fmac: single rounding
    sn = f32(snap)
    return cur if sn > abs(cur - filtered) else filtered


# ---------------------------------------------------------------- O2 monitor

def test_o2_channel_filter(booted):
    """0x3f924: four first-order filters of the AFR word / lambda."""
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
    harness.call(bus, cpu, O2_FILTER)  # second call: state advances
    assert bits(rf(bus, 0xFFFFC70C)) == bits(rom_filter(2.0, 1.0, 0.5))  # = 1.5


def test_o2_accumulate_window_publish(booted):
    """0x3fb9e: window-complete ratio publish (c701 = 1, c6f0 = c758/c728 with
    the 1e-5 guard) on a fresh state, then the every-2nd-run window reload
    (c7b2 = raw-u16 3-D lookup of load x rpm via tbl 0x6b66c)."""
    _, bus, cpu = booted
    bus.write8(0xFFFFD1C5, 0)          # DTC setting enabled
    wf(bus, 0xFFFFC0B4, 0.3)           # engine load
    wf(bus, 0xFFFFB548, 2000.0)        # rpm
    # force window completion on the first call: c904 = 2 counts down to 0
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


def test_o2_evaluate_decision(booted):
    """0x4128e: running-average thresholds from the four descriptors
    (0x6b6b8/0x6b6d4 are 1x1 constants -> -1.0), per-channel pass/fail flags,
    and the all-fail -> confirmed (c702) / any-pass -> pending (c703) cells."""
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
    # thresholds = running avg, first step = raw lookup value
    exp = [rom_lookup3d(bus, cpu, d, 0.3, 2000.0)
           for d in (0x6B680, 0x6B69C, 0x6B6B8, 0x6B6D4)]
    got = [rf(bus, a) for a in (0xFFFFC6F8, 0xFFFFC6FC, 0xFFFFC798, 0xFFFFC79C)]
    assert [bits(v) for v in got] == [bits(v) for v in exp]
    assert exp[2] == exp[3] == -1.0     # 1x1 constant descriptors (0 * mult + off -1)
    # ch0 ratio 0.5 > 0.0 -> fail; ch1..3 ratio 0.0: pass vs 0.0, fail vs -1.0
    assert [bus.read8(0xFFFFC7E6 + i) for i in range(4)] == [1, 0, 1, 1]
    assert [bus.read8(0xFFFFC7EA + i) for i in range(4)] == [0, 1, 0, 0]
    assert bus.read8(0xFFFFC702) == 0 and bus.read8(0xFFFFC703) == 1  # pending path
    # all four ratios above threshold -> confirmed cell
    for a in range(0xFFFFC7E6, 0xFFFFC7EE):
        bus.write8(a, 0)
    bus.write8(0xFFFFC702, 0); bus.write8(0xFFFFC703, 0)
    for a in (0xFFFFC6F0, 0xFFFFC6F4, 0xFFFFC780, 0xFFFFC784):
        wf(bus, a, 0.5)
    harness.call(bus, cpu, O2_EVAL)
    assert bus.read8(0xFFFFC702) == 1 and bus.read8(0xFFFFC703) == 0
    assert [bus.read8(0xFFFFC7E6 + i) for i in range(4)] == [1, 1, 1, 1]


# ---------------------------------------------------------------- cruise

def test_cruise_switch_decode(booted):
    """0x4c828: switch code 0xffffbaed (1..6) -> one flag in 0xffffcf47..4c."""
    _, bus, cpu = booted
    for a in range(0xFFFFCF47, 0xFFFFCF4D):
        bus.write8(a, 0)
    bus.write8(0xFFFFBAED, 3)
    harness.call(bus, cpu, SW_DECODE)
    assert [bus.read8(a) for a in range(0xFFFFCF47, 0xFFFFCF4D)] == [0, 0, 1, 0, 0, 0]
    bus.write8(0xFFFFBAED, 6)
    harness.call(bus, cpu, SW_DECODE)
    assert [bus.read8(a) for a in range(0xFFFFCF47, 0xFFFFCF4D)] == [0, 0, 0, 0, 0, 1]


def test_cruise_error_filter_stage(booted):
    """0x4ca7e: mean12 clamped to +/-15, rate-limited +/-1 per run, then
    first-order filter k=0.1; output cef4 = cef0 + vss-offset table."""
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
    assert rf(bus, 0xFFFFCEE8) == 15.0                    # clamp
    assert rf(bus, 0xFFFFCEEC) == 1.0                     # rate limit +1
    assert bits(rf(bus, 0xFFFFCEF0)) == bits(rom_filter(1.0, 0.0, 0.1))  # k=0.1
    off = rom_lookup2d(bus, cpu, 0x6BC70, 200.0)          # per-switch offset tbl
    assert bits(rf(bus, 0xFFFFCEF4)) == bits(f32(rf(bus, 0xFFFFCEF0) + off))
    # negative side clamps at -15
    wf(bus, 0xFFFFCEE4, -100.0); wf(bus, 0xFFFFCEEC, 0.0); wf(bus, 0xFFFFCEF0, 0.0)
    bus.write8(0xFFFFCF65, 0)
    harness.call(bus, cpu, CRUISE_FILTER)
    assert rf(bus, 0xFFFFCEE8) == -15.0


def test_cruise_integrator(booted):
    """0x2d83c: with cruise enabled and |vss error| >= 8 and bccc < 1 the
    counter bd10 increments per call; bd20 = bd10 (affine 1.0); the four
    ramp cells bd24..bd30 equal the ROM's own 3-D lookups (speed x band)."""
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
    assert 0.0 <= rf(bus, 0xFFFFBD08) <= 100.0               # adjust stays clamped


def test_cruise_set_speed_apply(booted):
    """0x2df62: bcf8 = clamp(bd00 + bd08, 0, 100) when cruise gates pass,
    else bcf8 = 0."""
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


# ---------------------------------------------------------------- E2RAM codec

def test_e2ram_block_decode(booted):
    """0x23844: affine u16/u8 decodes of the raw payload, signed byte, raw
    byte copies, and the 7-byte bit-unpack (0x24b00) into stored_dtc flags."""
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


def test_e2ram_block_encode(booted):
    """0x244bc: saturating affine encodes into the staging block (trunc((x)/step
    + 0.5)), signed encode for negative values, readValue cells, pedal volts,
    rpm step 0.1953125, and the packed fault bits."""
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


# ---------------------------------------------------------------- idle

def test_idle_target_rpm(booted):
    """0x1506c: base Idle Target table 0x69370 selected (b534=1), coolant
    axis -> a800 = lookup (1700 @ -40C, 810 @ 80C, 1450 @ 20C); max-chain
    into a7b0; 850 rpm floor when the idle latch a7b7 is set; override
    d26a=1 writes d244 straight to a7f4."""
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
    # 850 rpm floor with a7b7 = 1: coolant 80 -> max-chain 820 -> floored 850
    wf(bus, 0xFFFFA990, 80.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 850.0
    wf(bus, 0xFFFFA990, -40.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 1700.0
    # override path
    bus.write8(0xFFFFD26A, 1)
    wf(bus, 0xFFFFD244, 777.0)
    harness.call(bus, cpu, IDLE_CALC)
    assert rf(bus, 0xFFFFA7F4) == 777.0
    bus.write8(0xFFFFD26A, 0)


# ---------------------------------------------------------------- CAN compare

def _u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def _can_expected_regs(block, count, mbcr, mbimr):
    """Expected live HCAN register image that 0x2a4f8 builds from the 16-byte
    descriptor records (MC[k] of mailbox mb at base+0x20+mb*8+(k-1); standard
    id: MC[5]=(id&0xff)<<5, MC[6]=id>>3; extended: MC[5..8] as in the code).
    BCR=0x803e, IMR=0xfcfe, MCR=0, LAFM=0. MBCR/MBIMR are the values the ROM's
    own build loops produce (captured at the compare sites 0x2a5c6/0x2a5d4
    for ch0, 0x2a65e/0x2a66c for ch1)."""
    regs = {0x00: (1, 0), 0x02: (2, 0x803E), 0x04: (2, mbcr), 0x14: (2, mbimr),
            0x16: (2, 0xFCFE), 0x1C: (2, 0), 0x1E: (2, 0)}
    for i in range(count):
        rec = block + i * 16
        mb = ROM[rec + 5] & 0xF
        mc = 0x20 + mb * 8
        regs[mc + 0] = (1, ROM[rec + 6])                 # MC[1] = control
        rid = _u32(rec)
        if ROM[rec + 7] == 0:                            # standard 11-bit
            regs[mc + 4] = (1, (ROM[rec + 7] * 8 + ((rid & 0xFF) << 5)) & 0xFF)
            regs[mc + 5] = (1, (rid >> 3) & 0xFF)
        else:                                            # extended 29-bit
            regs[mc + 4] = (1, ((rid >> 0x12 & 7) * 0x20 + (rid >> 0x10 & 3)
                                + ROM[rec + 7] * 8) & 0xFF)
            regs[mc + 5] = (1, (rid >> 0x15) & 0xFF)
            regs[mc + 6] = (1, rid & 0xFF)
            regs[mc + 7] = (1, (rid >> 8) & 0xFF)
    return regs


def _apply(bus, base, regs):
    for off, (size, v) in regs.items():
        (bus.write8 if size == 1 else bus.write16)(base + off, v)


def test_hcan_mailbox_config_compare(booted):
    """0x2a4f8(channel, recs): returns 0 when the live HCAN registers match the
    descriptor block, nonzero on any perturbed register — both channels."""
    _, bus, cpu = booted
    regs0 = _can_expected_regs(0x4E01C, 16, 0x0100, 0x0100)
    _apply(bus, 0xFFFFE400, regs0)
    r0, _, _ = harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))
    assert r0 == 0                                   # full match
    old = bus.read8(0xFFFFE428)                      # MC[1] of mailbox 1
    bus.write8(0xFFFFE428, old ^ 0xFF)
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))[0] != 0
    bus.write8(0xFFFFE428, old)
    bus.write16(0xFFFFE402, 0)                       # BCR wrong
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))[0] != 0
    _apply(bus, 0xFFFFE400, regs0)

    regs1 = _can_expected_regs(0x4E21C, 6, 0x0100, 0x09FF)
    _apply(bus, 0xFFFFE600, regs1)
    r0, _, _ = harness.call(bus, cpu, CAN_COMPARE, r_args=(1, 0x4E21C))
    assert r0 == 0
    bus.write16(0xFFFFE616, 0)                       # IMR wrong on HCAN1
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(1, 0x4E21C))[0] != 0
