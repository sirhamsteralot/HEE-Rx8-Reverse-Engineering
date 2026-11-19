#!/usr/bin/env python3
"""Dynamic (SH-2E emulator) verification of the fuel pump control drive paths
against the real ROM code of 60E15120_N3J1E.

Covers the chain labeled in
data/labels/60E15120_N3J1E/fuel_pump_control_labels.json:

  * 0x2f890 / 0x2f8ce: PEDR bit 0x4 (PE2) = fuel_pump_relay_request
    0xffffbdd8 (direct / diag-gated), PEDR bit 0x2 (PE1) = 0xffffbdbc;
  * 0x2fc00: 0xffffbdd8 = key_on 0xffffaa68 && (grace counters) - high at
    key-on/cranking/running, low at key-off;
  * 0x3a0ec: PDDR bit 0x80 (PD7) = 0xffffcfb6, PEDR bit 0x1 (PE0) =
    (0xffffcfb7 == 0);
  * 0x532d0: 0xffffd15c cranking_in_progress (feeds PD7 via cfbc/cfb6);
  * 0x2e800: PJDR bit 0x80 (PJ7) = ac_clutch_relay_drive 0xffffbd68
    (A/C relay, not the fuel pump).

Run: python -m pytest tests/test_fuel_pump_control_dynamic.py
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

PEDR = 0xFFFFF754
PDDR = 0xFFFFF746
PJDR = 0xFFFFF76C

# RAM cells (see fuel_pump_control_labels.json)
BDD8 = 0xFFFFBDD8      # fuel_pump_relay_request
BDBC = 0xFFFFBDBC      # fuel_pump_speed_request
AA68 = 0xFFFFAA68      # key-on flag
AA62 = 0xFFFFAA62      # cranking_active
A428 = 0xFFFFA428      # engine_running
A42C = 0xFFFFA42C      # injectors_off
B548 = 0xFFFFB548      # engine_speed_rpm (float)
BBB4 = 0xFFFFBBB4      # vehicle_speed
CFB6 = 0xFFFFCFB6
CFB7 = 0xFFFFCFB7
D15C = 0xFFFFD15C
BD68 = 0xFFFFBD68      # ac_clutch_relay_drive


def fbits(x):
    return struct.unpack(">I", struct.pack(">f", x))[0]


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def pe2(bus):
    return (bus.read16(PEDR) >> 2) & 1


def pe1(bus):
    return (bus.read16(PEDR) >> 1) & 1


def pe0(bus):
    return bus.read16(PEDR) & 1


def pd7(bus):
    return (bus.read16(PDDR) >> 7) & 1


def pj7(bus):
    return (bus.read16(PJDR) >> 7) & 1


def test_pe2_drive_direct(booted):
    """0x2f890: PEDR bit 0x4 = (0xffffbdd8 == 1)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x2F890, ram={BDD8: (1, 1)})
    assert pe2(bus) == 1
    harness.call(bus, cpu, 0x2F890, ram={BDD8: (1, 0)})
    assert pe2(bus) == 0


def test_pe2_pe1_drive_diag_gated(booted):
    """0x2f8ce: PE2 = (0x5c204(bdd8)==1) [normal mode passes through],
    PE1 = (0xffffbdbc == 1)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x2F8CE, ram={BDD8: (1, 1), BDBC: (1, 1)})
    assert pe2(bus) == 1 and pe1(bus) == 1
    harness.call(bus, cpu, 0x2F8CE, ram={BDD8: (1, 0), BDBC: (1, 0)})
    assert pe2(bus) == 0 and pe1(bus) == 0


def test_pump_request_calc_key_on_off(booted):
    """0x2fc00: with key-on (aa68=1) and fresh counters, bdd8 = 1 -> PE2 on;
    with key-off (aa68=0), bdd8 = 0 -> PE2 off."""
    _, bus, cpu = booted
    ram = {AA68: (1, 1), A42C: (1, 0), 0xFFFFBDDA: (2, 0), 0xFFFFBDDC: (2, 0),
           0xFFFFBDE0: (1, 0), 0xFFFFBDDE: (2, 0)}
    harness.call(bus, cpu, 0x2FC00, ram=ram)
    assert bus.read8(BDD8) == 1
    harness.call(bus, cpu, 0x2F890)
    assert pe2(bus) == 1
    harness.call(bus, cpu, 0x2FC00, ram={AA68: (1, 0)})
    assert bus.read8(BDD8) == 0
    harness.call(bus, cpu, 0x2F890)
    assert pe2(bus) == 0


def test_pd7_pe0_pair(booted):
    """0x3a0ec: PD7 = (cfb6==1); PE0 = (cfb7==0)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 1), CFB7: (1, 0)})
    assert pd7(bus) == 1 and pe0(bus) == 1
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 1)})
    assert pd7(bus) == 0 and pe0(bus) == 0


def test_cranking_in_progress_flag(booted):
    """0x532d0: d15c = vspeed~0 && cranking && engine_running && E2 ctr<0xea."""
    _, bus, cpu = booted
    ram = {BBB4: (4, 0), AA62: (1, 1), A428: (1, 1), B548: (4, fbits(400.0)),
           0xFFFF86E8: (2, 0)}
    harness.call(bus, cpu, 0x532D0, ram=ram)
    assert bus.read8(D15C) == 1
    harness.call(bus, cpu, 0x532D0, ram={AA62: (1, 0)})  # not cranking
    assert bus.read8(D15C) == 0


def test_pj7_is_ac_clutch_not_fuel_pump(booted):
    """0x2e800: PJ7 = (0xffffbd68 == 1) - the A/C clutch relay drive."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x2E800, ram={BD68: (1, 1)})
    assert pj7(bus) == 1
    harness.call(bus, cpu, 0x2E800, ram={BD68: (1, 0)})
    assert pj7(bus) == 0
