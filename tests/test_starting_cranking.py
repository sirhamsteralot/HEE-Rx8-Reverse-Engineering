#!/usr/bin/env python3
"""Tests for the starting / cranking label record (starter relay PD7).

Covers data/labels/60E15120_N3J1E/starting_cranking_labels.json (split out of
fuel_pump_control_labels.json per the report scope-discipline rule — the PD7
starter relay chain was mapped while tracing the fuel pump port banks;
ROADMAP C item 31):

  * every function alias address exists in the decompiled function index;
  * the cited literal-pool words match the raw ROM bytes (SHA-256 pinned) at
    the exact addresses named in the evidence strings (rule-7 binary-level
    verification);
  * the port data registers named in the evidence exist in symbols.tsv;
  * the accepted source-review TSV rows mirror the JSON aliases;
  * dynamic (SH-2E emulator): PD7 follows 0xffffcfb6 via 0x3a0ec, and
    0xffffd15c (cranking_in_progress) is computed by 0x532d0.

Run: python -m pytest tests/test_starting_cranking.py
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
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "starting_cranking_labels.json"
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

PEDR = 0xFFFFF754
PDDR = 0xFFFFF746

CFB6 = 0xFFFFCFB6      # pd7_relay_flag
CFB7 = 0xFFFFCFB7      # pe0_relay_flag (PE0 half: throttle_dbw_labels.json)
D15C = 0xFFFFD15C      # cranking_in_progress
AA62 = 0xFFFFAA62      # cranking_active
A428 = 0xFFFFA428      # engine_running
B548 = 0xFFFFB548      # engine_speed_rpm (float)
BBB4 = 0xFFFFBBB4      # vehicle_speed


def fbits(x):
    return struct.unpack(">I", struct.pack(">f", x))[0]


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


def w32(rom, addr):
    return struct.unpack(">I", rom[addr:addr + 4])[0]


def pd7(bus):
    return (bus.read16(PDDR) >> 7) & 1


def test_function_aliases_exist_in_index(record, func_addresses):
    for addr in record["function_aliases"]:
        assert int(addr, 16) in func_addresses, f"0x{addr} not a function entry"


def test_port_registers_in_symbols():
    with SYMBOLS.open(encoding="utf-8", errors="replace", newline="") as fh:
        syms = {r["address"]: r["name"] for r in csv.DictReader(fh, delimiter="\t")}
    assert syms["fffff754"] == "PEDR_W"
    assert syms["fffff746"] == "PDDR_W"


def test_0x3a0ec_pd7_pe0_pools_and_instructions(rom):
    # PD7 = (0xffffcfb6==1) mask 0x80 on PDDR; PE0 = (0xffffcfb7==0) mask 0x1 on PEDR
    # (the PE0 half of 0x3a0ec is the DBW relay — throttle_dbw_labels.json)
    assert w16(rom, 0x3A1AA) == 0xCFB6
    assert w16(rom, 0x3A1AC) == 0x0080          # mask 0x80
    assert w16(rom, 0x3A1AE) == 0xF746          # PDDR_W low half
    assert w16(rom, 0x3A1B0) == 0xCFB7
    assert w16(rom, 0x3A1B2) == 0xF754          # PEDR_W low half
    assert w32(rom, 0x3A1BC) == 0x00004BBC      # helper 0x4bbc
    assert w16(rom, 0x3A13C) == 0xE501          # mov #0x1,r5 (PE0 mask)


def test_pd7_drive_dynamic(booted):
    """0x3a0ec: PDDR bit 0x80 (PD7) = (0xffffcfb6 == 1) — starter relay."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 1), CFB7: (1, 0)})
    assert pd7(bus) == 1
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 1)})
    assert pd7(bus) == 0


def test_cranking_in_progress_flag(booted):
    """0x532d0: d15c = vspeed~0 && cranking && engine_running && E2 ctr<0xea."""
    _, bus, cpu = booted
    ram = {BBB4: (4, 0), AA62: (1, 1), A428: (1, 1), B548: (4, fbits(400.0)),
           0xFFFF86E8: (2, 0)}
    harness.call(bus, cpu, 0x532D0, ram=ram)
    assert bus.read8(D15C) == 1
    harness.call(bus, cpu, 0x532D0, ram={AA62: (1, 0)})  # not cranking
    assert bus.read8(D15C) == 0


def test_tsv_rows_mirror_json(record):
    with FN_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        fn_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        ram_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, e in record["function_aliases"].items():
        assert fn_rows.get("%08x" % int(addr, 16)) == e["alias"]
    for addr, e in record["ram_aliases"].items():
        assert ram_rows.get(addr) == e["alias"]
