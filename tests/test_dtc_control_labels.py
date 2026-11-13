#!/usr/bin/env python3
"""Tests for the DTC-control RAM label record
(data/labels/60E15120_N3J1E/dtc_control_labels.json).

The ten RAM aliases in that record were promoted from the
[ADDITIONAL SOURCE REVIEW] header comments in the decompiled export into a
per-subsystem labels JSON (they previously existed only in
source_review/accepted_ram_aliases.tsv and dtc_engine_labels.tsv).

Invariants checked against the artifacts on disk:
  * the JSON carries exactly the ten DTC-control RAM addresses, each with
    alias/type/reader/evidence;
  * every JSON ram_aliases entry has a matching row (same address + alias) in
    docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_ram_aliases.tsv
    (labels-JSON -> accepted-TSV coverage, as verify_claims.py checks) and in
    data/labels/60E15120_N3J1E/dtc_engine_labels.tsv;
  * rule 7 binary-level verification: for each entry, the cited reader
    function's body in the disassembly references the RAM address through a
    PC-relative literal pool (mov.l 32-bit pool word, or mov.w pool word that
    sign-extends to the address), and the pool bytes in the raw ROM
    (SHA-256 pinned) hold that address.
"""
import csv
import hashlib
import json
import re
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LABELS = REPO / "data" / "labels" / "60E15120_N3J1E" / "dtc_control_labels.json"
RAM_TSV = (
    REPO
    / "docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_ram_aliases.tsv"
)
ENGINE_TSV = REPO / "data" / "labels" / "60E15120_N3J1E" / "dtc_engine_labels.tsv"
ROM = (
    REPO
    / "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"
)
ASM = (
    REPO
    / "reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm"
)
FUNC_INDEX = REPO / "reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

EXPECTED = {
    "ffff87b0": "dtc_master_table_21",
    "ffff8900": "dtc_master_current_index",
    "ffffd286": "mil_lamp_flag",
    "ffffd3c0": "dtc_first_stored_code",
    "ffffd3c2": "dtc_eval_state_cache",
    "ffffd458": "dtc_eval_state_array",
    "ffffd4e4": "dtc_transition_state_array",
    "ffffd5fc": "dtc_state_array",
    "ffffd688": "dtc_eval_enable",
    "ffffd930": "dtc_status_bits",
}

POOL_REF = re.compile(r"@\((0x[0-9a-f]+),pc\)")
ASM_LINE = re.compile(r"^([0-9a-f]{8})  ([0-9a-f]{4})  (.*)$")


@pytest.fixture(scope="module")
def record():
    return json.loads(LABELS.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def rom():
    data = ROM.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ROM_SHA256, "ROM hash changed"
    return data


@pytest.fixture(scope="module")
def disasm_lines():
    lines = {}
    for raw in ASM.read_text(encoding="utf-8", errors="replace").splitlines():
        m = ASM_LINE.match(raw)
        if m:
            lines[int(m.group(1), 16)] = m.group(3).strip()
    return lines


@pytest.fixture(scope="module")
def func_starts():
    with FUNC_INDEX.open(encoding="utf-8", errors="replace", newline="") as fh:
        return sorted(int(r["address"], 16) for r in csv.DictReader(fh, delimiter="\t"))


def test_record_has_exactly_the_ten_ram_aliases(record):
    ram = record["ram_aliases"]
    assert set(ram) == set(EXPECTED), set(ram) ^ set(EXPECTED)
    for addr, alias in EXPECTED.items():
        entry = ram[addr]
        assert entry["alias"] == alias
        assert entry["type"] and entry["reader"] and entry["evidence"].strip()


def test_every_entry_matches_accepted_ram_aliases_tsv(record):
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        tsv = {r["address"].lower(): r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, entry in record["ram_aliases"].items():
        assert addr in tsv, f"{addr} not in accepted_ram_aliases.tsv"
        assert tsv[addr] == entry["alias"], f"{addr}: JSON {entry['alias']!r} != TSV {tsv[addr]!r}"


def test_every_entry_present_in_dtc_engine_labels_tsv():
    with ENGINE_TSV.open(encoding="utf-8", errors="replace", newline="") as fh:
        rows = {r["address"].lower().replace("0x", ""): r for r in csv.DictReader(fh, delimiter="\t")}
    for addr, alias in EXPECTED.items():
        assert addr in rows, f"0x{addr} missing from dtc_engine_labels.tsv"
        assert rows[addr]["label"] == alias
        assert rows[addr]["kind"] == "RAM"
        assert rows[addr]["evidence"].strip()


def _reader_references(disasm_lines, func_starts, rom, reader, want):
    """True if the function at `reader` loads `want` via a PC-relative pool."""
    import bisect

    start = int(reader, 16)
    k = bisect.bisect_right(func_starts, start)
    end = func_starts[k] if k < len(func_starts) else len(rom)
    addr = start
    while addr < end:
        mn = disasm_lines.get(addr)
        if mn is None:  # literal-pool word inside the function range
            addr += 2
            continue
        if mn.startswith("mov.l") or mn.startswith("mov.w"):
            for m in POOL_REF.finditer(mn):
                pool = int(m.group(1), 16)
                if mn.startswith("mov.l"):
                    val = int.from_bytes(rom[pool : pool + 4], "big")
                else:
                    w = int.from_bytes(rom[pool : pool + 2], "big")
                    val = (w - 0x10000 if w >= 0x8000 else w) & 0xFFFFFFFF
                if val == want:
                    return True
        addr += 2
    return False


@pytest.mark.parametrize("addr", sorted(EXPECTED))
def test_reader_literal_pool_verified_in_raw_rom(record, rom, disasm_lines, func_starts, addr):
    entry = record["ram_aliases"][addr]
    want = int(addr, 16)
    assert _reader_references(
        disasm_lines, func_starts, rom, entry["reader"].lower(), want
    ), f"reader {entry['reader']} does not reference 0x{addr} via a ROM literal pool"
