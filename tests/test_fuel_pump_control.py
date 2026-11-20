#!/usr/bin/env python3
"""Tests for the fuel pump control label record (ROADMAP group C fuel pump
control subsystem).

Covers data/labels/60E15120_N3J1E/fuel_pump_control_labels.json:

  * every function alias address exists in the decompiled function index;
  * the cited literal-pool words and instruction words match the raw ROM
    bytes (SHA-256 pinned) at the exact addresses named in the evidence
    strings (rule-7 binary-level verification);
  * the port data registers named in the evidence exist in symbols.tsv;
  * the accepted source-review TSV rows mirror the JSON aliases.

Neighboring relay outputs mapped while tracing (PD7 starter, PE0 DBW, PJ7 A/C
clutch) are out of scope here — see docs/subsystem-logic/fuel_pump_control_report.md
§4.6 and tests/test_starting_cranking.py, tests/test_throttle_dbw.py,
tests/test_ac_compressor_clutch.py.

Run: python -m pytest tests/test_fuel_pump_control.py
"""
import csv
import hashlib
import json
import struct
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "fuel_pump_control_labels.json"
ROM = (
    REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
    / "60E15120_N3J1E.bin"
)
FUNC_INDEX = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "function_index.tsv"
SYMBOLS = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "symbols.tsv"
FN_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_function_aliases.tsv"
RAM_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_ram_aliases.tsv"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"


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


def w16(rom, addr):
    return struct.unpack(">H", rom[addr:addr + 2])[0]


def w32(rom, addr):
    return struct.unpack(">I", rom[addr:addr + 4])[0]


def test_function_aliases_exist_in_index(record, func_addresses):
    for addr in record["function_aliases"]:
        assert int(addr, 16) in func_addresses, f"0x{addr} not a function entry"


def test_port_registers_in_symbols():
    with SYMBOLS.open(encoding="utf-8", errors="replace", newline="") as fh:
        syms = {r["address"]: r["name"] for r in csv.DictReader(fh, delimiter="\t")}
    assert syms["fffff754"] == "PEDR_W"
    assert syms["fffff746"] == "PDDR_W"
    assert syms["fffff76c"] == "PJDR_W"


def test_0x2f890_pe2_drive_pools_and_instructions(rom):
    # PEDR bit 0x4 (PE2) = (0xffffbdd8 == 1): cell pool, reg pool, helper pool, mask imm, cmp
    assert w16(rom, 0x2F930) == 0xBDD8          # DAT_ffffbdd8 cell (low half pool)
    assert w16(rom, 0x2F932) == 0xF754          # PEDR_W low half
    assert w32(rom, 0x2F93C) == 0x00004BBC      # ref_setRegister_REG_BIT_VAL
    assert w16(rom, 0x2F8B0) == 0xE504          # mov #0x4,r5  (mask 0x4)
    assert w16(rom, 0x2F8A2) == 0x8801          # cmp/eq #1,r0
    assert w16(rom, 0x2F894) == 0x954B          # mov.w @(pool),r5 (SR mask 0xe0)


def test_0x2f8ce_pe2_pe1_pools_and_instructions(rom):
    # PE2 via diag gate 0x5c204, PE1 direct from 0xffffbdbc
    assert w32(rom, 0x2F944) == 0x00005C204     # FUN_0005c204 diag override
    assert w16(rom, 0x2F934) == 0xBDBC          # DAT_ffffbdbc cell
    assert w16(rom, 0x2F8EA) == 0xE504          # mov #0x4,r5 (PE2 mask)
    assert w16(rom, 0x2F912) == 0xE502          # mov #0x2,r5 (PE1 mask)


def test_0x2fc00_bdd8_calc_pools_and_thresholds(rom):
    # flag cells + counter cells + ROM thresholds cited in the evidence
    assert w16(rom, 0x2FCD0) == 0xAA68          # key-on flag 0xffffaa68
    assert w16(rom, 0x2FCD2) == 0xA42C          # injectors_off 0xffffa42c
    assert w32(rom, 0x2FCE0) == 0xFFFFBDDA      # key-on tick counter (mov.l pool)
    assert w32(rom, 0x2FCE4) == 0xFFFFBDDE      # injectors-off counter (mov.l pool)
    assert w32(rom, 0x2FCE8) == 0xFFFFBDE0      # injectors-off flag (mov.l pool)
    assert w32(rom, 0x2FCD8) == 0xFFFFBDDC      # free-running counter (mov.l pool)
    assert w16(rom, 0x2FCCE) == 0xBDD8          # result flag 0xffffbdd8 (mov.w pool)
    assert w32(rom, 0x2FCDC) == 0x00002460      # saturating-increment helper
    assert w16(rom, 0x7BC58) == 0x001F          # threshold 31
    assert w16(rom, 0x7BC5C) == 0x003E          # threshold 62


def test_tsv_rows_mirror_json(record):
    with FN_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        fn_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        ram_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, e in record["function_aliases"].items():
        assert fn_rows.get("%08x" % int(addr, 16)) == e["alias"]
    for addr, e in record["ram_aliases"].items():
        assert ram_rows.get(addr) == e["alias"]
