#!/usr/bin/env python3
"""Dynamic (SH-2E emulator) verification of the fuel pump control drive paths
against the real ROM code of 60E15120_N3J1E.

Covers the chain labeled in
data/labels/60E15120_N3J1E/fuel_pump_control_labels.json:

  * 0x2f890 / 0x2f8ce: PEDR bit 0x4 (PE2) = fuel_pump_relay_request
    0xffffbdd8 (direct / diag-gated), PEDR bit 0x2 (PE1) = 0xffffbdbc;
  * 0x2fc00: 0xffffbdd8 = key_on 0xffffaa68 && (grace counters) - high at
    key-on/cranking/running, low at key-off.

Neighboring relay outputs mapped while tracing (PD7 starter, PE0 DBW, PJ7 A/C
clutch) are out of scope here - see docs/subsystem-logic/fuel_pump_control_report.md
§4.6 and tests/test_starting_cranking.py, tests/test_throttle_dbw.py,
tests/test_ac_compressor_clutch.py.

Run: python -m pytest tests/test_fuel_pump_control_dynamic.py
"""
import os
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

PEDR = 0xFFFFF754

# RAM cells (see fuel_pump_control_labels.json)
BDD8 = 0xFFFFBDD8      # fuel_pump_relay_request
BDBC = 0xFFFFBDBC      # fuel_pump_speed_request
AA68 = 0xFFFFAA68      # key-on flag
A42C = 0xFFFFA42C      # injectors_off


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def pe2(bus):
    return (bus.read16(PEDR) >> 2) & 1


def pe1(bus):
    return (bus.read16(PEDR) >> 1) & 1


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
