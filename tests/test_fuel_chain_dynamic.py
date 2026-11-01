"""Group C deepening: dynamic verification of the load/fuel chain in the
emulator against the real ROM code (ROADMAP group C item 'deepen
fueling_control_report.md' — 'dynamically verify the fuel chain via
harness.py').

Covers the chain verified statically in
docs/investigations/60E15120_N3J1E/load_fueling_report.md + the
fueling_control_report.md 2026-10-31 addendum:

- 0x1a418 candidate_maf_per_rotation_calc: maf_per_rotation_ffffaa3c =
  min(mass_air_flow x 60.0 / rpm, 5.0)  (60.0 @0x1a4e8, 5.0 @0x1a4f4)
- 0x33a6c ref_airPerStroke: engine_load_raw_ffffc0b0 = aa3c x 0.6345
  (f32 0x3f226e98 @0x7a088 via pool 0x33b70)
- 0x33ad2 calculate_engine_load: c0b4 = min(first_order_filter(c0b0, c0b4,
  0.2, 1e-5), c0b8); forced 0.525 when engine_stopped_latch
- 0x55748 diag_encode_load_g_rev (PID 0x43 encode): raw = round(c0b4 x 255)

Run: python -m pytest tests/test_fuel_chain_dynamic.py
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

# RAM cells (see load_fueling_report.md / fueling_control_report.md memory maps)
MAF_G_S = 0xFFFFA9EC          # mass_air_flow_ffffa9ec
RPM = 0xFFFFB548              # engine_speed_rpm_ffffb548
MAF_MODE = 0xFFFFAA4C         # maf_filter_mode_ffffaa4c (1 = use raw MAF)
AIR_PER_REV = 0xFFFFAA3C      # maf_per_rotation_ffffaa3c
LOAD_RAW = 0xFFFFC0B0         # engine_load_raw_ffffc0b0
LOAD = 0xFFFFC0B4             # engine_load_ffffc0b4
LOAD_MAX = 0xFFFFC0B8         # engine_load_max_ffffc0b8
FAST_FLAG = 0xFFFFC0C4        # load_filter_fast_flag_ffffc0c4 (u8)
INJ_OFF_PREV = 0xFFFFC0C5     # injectors_off_previous_ffffc0c5 (u8)
STOPPED = 0xFFFFA41C          # engine_stopped_latch_ffffa41c (u8)
INJ_OFF = 0xFFFFA42C          # engine_injectors_off_ffffa42c (u8)

F32_0p6345 = 0x3F226E98       # ROM 0x7a088


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def rd_float(bus, addr):
    return struct.unpack(">f", struct.pack(">I", bus.read32(addr)))[0]


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def test_maf_per_rotation_calc(booted):
    """0x1a418: aa3c = min(maf*60/rpm, 5.0) with raw-MAF mode (aa4c=1)."""
    _, bus, cpu = booted
    ram = {MAF_G_S: (4, harness.bits(100.0)), RPM: (4, harness.bits(3000.0)),
           MAF_MODE: (1, 1)}
    harness.call(bus, cpu, 0x1A418, ram=ram)
    assert rd_float(bus, AIR_PER_REV) == f32(100.0 * f32(60.0 / 3000.0)) == 2.0
    # cap at 5.0 g/rev: 1000 g/s at 1000 rpm -> 60 g/rev -> clamped to 5.0
    ram = {MAF_G_S: (4, harness.bits(1000.0)), RPM: (4, harness.bits(1000.0)),
           MAF_MODE: (1, 1)}
    harness.call(bus, cpu, 0x1A418, ram=ram)
    assert rd_float(bus, AIR_PER_REV) == 5.0


def test_air_per_stroke_scale(booted):
    """0x33a6c: c0b0 = aa3c * 0.6345 (VolEf factor, ROM 0x7a088)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x33A6C, ram={AIR_PER_REV: (4, harness.bits(1.0))})
    assert rd_float(bus, LOAD_RAW) == f32(0.6345000267028809)
    assert bus.read32(LOAD_RAW) == F32_0p6345  # bit-exact vs the ROM constant


def test_engine_load_filter_and_clamp(booted):
    """0x33ad2: c0b4 = min(filter(c0b0, prev, 0.2, 1e-5), c0b8); 0.525 if stopped."""
    _, bus, cpu = booted
    ram = {LOAD_RAW: (4, harness.bits(0.8)), LOAD: (4, harness.bits(0.5)),
           LOAD_MAX: (4, harness.bits(1.2)), FAST_FLAG: (1, 0),
           INJ_OFF_PREV: (1, 1), STOPPED: (1, 0), INJ_OFF: (1, 0)}
    harness.call(bus, cpu, 0x33AD2, ram=ram)
    # filter(0.8, 0.5, 0.2, 1e-5) = 0.8 + 0.8*(0.5-0.8) = 0.56; min(0.56, 1.2) = 0.56
    assert rd_float(bus, LOAD) == f32(0.56)
    # clamp by c0b8: with prev == raw the filter passes 2.0 through, then
    # min(2.0, 1.2) clamps -> c0b4 = c0b8
    ram[LOAD_RAW] = (4, harness.bits(2.0))
    ram[LOAD] = (4, harness.bits(2.0))
    ram[LOAD_MAX] = (4, harness.bits(1.2))
    harness.call(bus, cpu, 0x33AD2, ram=ram)
    assert rd_float(bus, LOAD) == f32(1.2)
    # stopped latch forces 0.525
    ram[STOPPED] = (1, 1)
    harness.call(bus, cpu, 0x33AD2, ram=ram)
    assert rd_float(bus, LOAD) == f32(0.525)


def test_pid0043_encode(booted):
    """0x55748 (PID 0x43 handler 0x56b8a's callee): raw = round(c0b4 * 255)."""
    _, bus, cpu = booted
    r0, _, _ = harness.call(bus, cpu, 0x55748, ram={LOAD: (4, harness.bits(0.42))})
    assert r0 == 107  # 0.42 / (1/255) = 107.1 -> 107 (matches the 2026-10-31 sweep)
    r0, _, _ = harness.call(bus, cpu, 0x55748, ram={LOAD: (4, harness.bits(1.0))})
    assert r0 == 255
