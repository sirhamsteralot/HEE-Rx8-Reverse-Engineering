#!/usr/bin/env python3
"""Tests for the immobilizer label records.

Covers:
  * data/labels/60E15120_N3J1E/immobilizer_labels.json — every function alias
    address exists in the decompiled function index; the immobilizer start
    patterns and the cited CAN mailbox descriptors + literal-pool words
    match the raw ROM bytes (SHA-256 pinned);
  * data/labels/60E0G500_N3ZHEC/immobilizer_labels.json — same checks against
    our own dump binaries/dumps/60E0G500_N3ZHEC.bin;
  * data/labels/cross_rom/immobilizer_function_map.json — every mapped
    (rom, base -> target) pair is backed by a unique_exact_bytes row in
    data/labels/cross_rom_function_matches.tsv.

Run: python -m pytest tests/test_immobilizer_labels.py
"""
import csv
import hashlib
import json
import struct
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL_REF = REPO / "data" / "labels" / "60E15120_N3J1E" / "immobilizer_labels.json"
LBL_G500 = REPO / "data" / "labels" / "60E0G500_N3ZHEC" / "immobilizer_labels.json"
LBL_CROSS = REPO / "data" / "labels" / "cross_rom" / "immobilizer_function_map.json"
MATCHES = REPO / "data" / "labels" / "cross_rom_function_matches.tsv"
ROM_REF = (
    REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
    / "60E15120_N3J1E.bin"
)
ROM_G500 = REPO / "binaries" / "dumps" / "60E0G500_N3ZHEC.bin"
FUNC_INDEX = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "function_index.tsv"

SHA_REF = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"
SHA_G500 = "a33f79a4f1c47007fd95a667ef8a8e14740eb8522c0b26a4fc1022db7fd85db2"


@pytest.fixture(scope="module")
def record_ref():
    return json.loads(LBL_REF.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def record_g500():
    return json.loads(LBL_G500.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def record_cross():
    return json.loads(LBL_CROSS.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def rom_ref():
    data = ROM_REF.read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA_REF
    return data


@pytest.fixture(scope="module")
def rom_g500():
    data = ROM_G500.read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA_G500
    return data


@pytest.fixture(scope="module")
def func_addresses():
    with FUNC_INDEX.open(encoding="utf-8", errors="replace", newline="") as fh:
        return {int(r["address"], 16) for r in csv.DictReader(fh, delimiter="\t")}


def test_reference_function_aliases_exist_in_index(record_ref, func_addresses):
    for addr in record_ref["function_aliases"]:
        assert int(addr, 16) in func_addresses, f"0x{addr} not a function entry"


def test_reference_start_patterns_match_rom_bytes(record_ref, rom_ref):
    pat = record_ref["rom_code_patterns"]["0x34b10"]
    assert rom_ref[0x34B10:0x34B10 + 16].hex().upper() == pat["pattern_hex"]
    assert rom_ref[0x34F5C:0x34F5C + 2].hex().upper() == "3320"  # cmp/eq r2,r3 (with-RKE site)


def test_reference_can_descriptors_match_rom(record_ref, rom_ref):
    rx = record_ref["can_ids"]["rx_keyless_module"]
    tx = record_ref["can_ids"]["tx_keyless_module"]
    for desc_addr, rec in ((0x4E26C, rx), (0x4DFAC, tx)):
        cid = struct.unpack(">I", rom_ref[desc_addr:desc_addr + 4])[0]
        buf = struct.unpack(">I", rom_ref[desc_addr + 8:desc_addr + 12])[0]
        assert cid == int(rec["can_id"], 16)
        assert buf == int(rec["buffer_ram"], 16)
        assert rom_ref[desc_addr + 5] == rec["mailbox"]
        assert rom_ref[desc_addr + 6] == rec["dlc"]


def test_reference_cited_pool_words_match_rom(record_ref, rom_ref):
    # 0x355f0 command-decode pool
    words = {0x356B6: 0xC4BF, 0x356B8: 0xC4BB, 0x356BA: 0xC4BA, 0x356BC: 0xC4B9,
             0x356BE: 0x0090, 0x356C0: 0x00C9, 0x356C2: 0x00FF}
    for addr, expect in words.items():
        assert struct.unpack(">H", rom_ref[addr:addr + 2])[0] == expect, hex(addr)
    for addr, expect in ((0x356C8, 0xFFFFC21E), (0x356CC, 0xFFFFC221), (0x356D0, 0xFFFFC204)):
        assert struct.unpack(">I", rom_ref[addr:addr + 4])[0] == expect, hex(addr)
    # 0xe2d4 fuel-cut bitmask build: c1d0 / a430 pool words
    for addr, expect in ((0xE406, 0xC1D0), (0xE43C, 0xC1D0), (0xE43E, 0xA430)):
        assert struct.unpack(">H", rom_ref[addr:addr + 2])[0] == expect, hex(addr)
    # 0x11c4 immo diag-bit clear: pool long = 0xffffdfa0
    assert struct.unpack(">I", rom_ref[0x1284:0x1288])[0] == 0xFFFFDFA0


def test_g500_start_pattern_and_descriptors_match_own_dump(record_g500, rom_g500):
    pat = record_g500["rom_code_patterns"]["0x35af8"]
    assert rom_g500[0x35AF8:0x35AF8 + 16].hex().upper() == pat["pattern_hex"]
    assert rom_g500[0x35F44:0x35F44 + 2].hex().upper() == "3320"
    rx = record_g500["can_ids"]["rx_keyless_module"]
    tx = record_g500["can_ids"]["tx_keyless_module"]
    for desc_addr, rec in ((0x4EA18, rx), (0x4E758, tx)):
        cid = struct.unpack(">I", rom_g500[desc_addr:desc_addr + 4])[0]
        buf = struct.unpack(">I", rom_g500[desc_addr + 8:desc_addr + 12])[0]
        assert cid == int(rec["can_id"], 16)
        assert buf == int(rec["buffer_ram"], 16)


def test_cross_rom_map_backed_by_matches_tsv(record_cross):
    rows = set()
    with MATCHES.open(encoding="utf-8", errors="replace", newline="") as fh:
        for r in csv.DictReader(fh, delimiter="\t"):
            if r["method"] == "unique_exact_bytes":
                rows.add((r["rom"], r["base_address"], r["target_address"]))
    mapped = 0
    for rom, entries in record_cross["roms"].items():
        for base, tgt in entries.items():
            assert (rom, base, tgt) in rows, f"{rom} {base} -> {tgt} not in matches TSV"
            mapped += 1
    assert mapped > 200, "cross-ROM immo map suspiciously small"


def test_cross_rom_map_covers_all_dumped_roms(record_cross):
    # 10 upstream stock ROMs + our own 60E0G500 dump
    assert len(record_cross["roms"]) == 11
    assert "60E15120_N3J1E.bin" in record_cross["roms"]
    assert "dumps/60E0G500_N3ZHEC.bin" in record_cross["roms"]


def test_g500_function_map_matches_tsv(record_g500):
    rows = set()
    with MATCHES.open(encoding="utf-8", errors="replace", newline="") as fh:
        for r in csv.DictReader(fh, delimiter="\t"):
            if r["rom"] == "dumps/60E0G500_N3ZHEC.bin" and r["method"] == "unique_exact_bytes":
                rows.add((r["base_address"], r["target_address"]))
    for base, tgt in record_g500["function_map_60E15120_to_60E0G500_N3ZHEC"].items():
        if base == "note":
            continue
        assert (base, tgt) in rows, f"{base} -> {tgt} not in matches TSV for 60E0G500"
