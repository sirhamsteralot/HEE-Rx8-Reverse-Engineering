#!/usr/bin/env python3
"""Tests for the A/C compressor clutch relay label record.

Covers data/labels/60E15120_N3J1E/ac_compressor_clutch_labels.json (split out
of fuel_pump_control_labels.json per the report scope-discipline rule — PJ7
was mapped while tracing the fuel pump port banks but is the A/C clutch
relay, harness candidate 5AA; ROADMAP C item 92):

  * every function alias address exists in the decompiled function index;
  * the cited literal-pool words and float constants match the raw ROM bytes
    (SHA-256 pinned) at the exact addresses named in the evidence strings
    (rule-7 binary-level verification);
  * the port data register named in the evidence exists in symbols.tsv;
  * the accepted source-review TSV rows mirror the JSON aliases;
  * dynamic (SH-2E emulator): PJDR bit 0x80 follows 0xffffbd68.

Run: python -m pytest tests/test_ac_compressor_clutch.py
"""
import csv
import hashlib
import json
import os
import struct
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "ac_compressor_clutch_labels.json"
ROM = (
    REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
    / "60E15120_N3J1E.bin"
)
FUNC_INDEX = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "function_index.tsv"
SYMBOLS = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "symbols.tsv"
FN_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_function_aliases.tsv"
RAM_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_ram_aliases.tsv"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

PJDR = 0xFFFFF76C
BD68 = 0xFFFFBD68      # ac_clutch_relay_drive


@pytest.fixture(scope="module")
def record():
    return json.loads(LBL.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def rom():
    data = ROM.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ROM_SHA256, "ROM hash changed"
    return data


@pytest.fixture(scope="module")
def func_addresses():
    with FUNC_INDEX.open(encoding="utf-8", errors="replace", newline="") as fh:
        return {int(r["address"], 16) for r in csv.DictReader(fh, delimiter="\t")}


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def w16(rom, addr):
    return struct.unpack(">H", rom[addr:addr + 2])[0]


def pj7(bus):
    return (bus.read16(PJDR) >> 7) & 1


def test_function_aliases_exist_in_index(record, func_addresses):
    for addr in record["function_aliases"]:
        assert int(addr, 16) in func_addresses, f"0x{addr} not a function entry"


def test_port_register_in_symbols():
    with SYMBOLS.open(encoding="utf-8", errors="replace", newline="") as fh:
        syms = {r["address"]: r["name"] for r in csv.DictReader(fh, delimiter="\t")}
    assert syms["fffff76c"] == "PJDR_W"


def test_0x2e89c_ac_clutch_flag_pools_and_thresholds(rom):
    # ref_calculateACClutchOn__ 0x2e89c pools: rpm, bd68, bd69
    assert w16(rom, 0x2E968) == 0xB548          # engine_speed_rpm_ffffb548
    assert w16(rom, 0x2E96A) == 0xBD68          # ac_clutch_relay_drive cell
    assert w16(rom, 0x2E96C) == 0xBD69          # ac_clutch_on_ffffbd69
    assert struct.unpack(">f", rom[0x774C0:0x774C4])[0] == 600.0
    assert struct.unpack(">f", rom[0x774C4:0x774C8])[0] == 7800.0


def test_pj7_drive_dynamic(booted):
    """0x2e800: PJDR bit 0x80 (PJ7) = (0xffffbd68 == 1) - the A/C clutch relay
    drive, not the fuel pump."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x2E800, ram={BD68: (1, 1)})
    assert pj7(bus) == 1
    harness.call(bus, cpu, 0x2E800, ram={BD68: (1, 0)})
    assert pj7(bus) == 0


def test_tsv_rows_mirror_json(record):
    with FN_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        fn_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        ram_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, e in record["function_aliases"].items():
        assert fn_rows.get("%08x" % int(addr, 16)) == e["alias"]
    for addr, e in record["ram_aliases"].items():
        assert ram_rows.get(addr) == e["alias"]
