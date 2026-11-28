#!/usr/bin/env python3
"""Tests for the misfire detection label record and its raw-bin verification.

Covers data/labels/60E15120_N3J1E/misfire_detection_labels.json:

  * every function alias address exists in the decompiled function index and
    carries the folded-back name;
  * every RAM alias address carries its folded name in symbols.tsv, and both
    monoliths carry the folded function/RAM names;
  * the accepted source-review TSV rows mirror the JSON aliases;
  * the cited literal-pool words, instruction words, float constants and table
    descriptors match the raw ROM bytes (SHA-256 pinned) — rule-7 binary-level
    verification, same anchors as verify_misfire_chain.py;
  * the 0x27fb4 arm polarity: neutral flag OR load floor (bt/s at 0x27fdc
    skips the load compare), not AND;
  * regeneration tests (rule 6d): re-running the label generator and the
    verifier leaves the committed artifacts byte-identical.

Run: python -m pytest tests/test_misfire_detection.py
"""
import csv
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "misfire_detection_labels.json"
ROM = (
    REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
    / "60E15120_N3J1E.bin"
)
FUNC_INDEX = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "function_index.tsv"
SYMBOLS = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "symbols.tsv"
MONOLITH = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "firmware_decompiled.c"
NAMED_MONOLITH = (REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E"
                  / "named" / "firmware_named.c")
FN_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_function_aliases.tsv"
RAM_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_ram_aliases.tsv"
PIPELINE = REPO / "utilities" / "scripts" / "rx8-pcm-pipeline"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"


@pytest.fixture(scope="module")
def record():
    return json.loads(LBL.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def rom():
    data = ROM.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ROM_SHA256, "ROM hash changed"
    return data


def _read_tsv(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def test_function_aliases_in_index_with_folded_name(record):
    index = {r["address"]: r["name"] for r in _read_tsv(FUNC_INDEX)}
    for addr, entry in record["function_aliases"].items():
        assert addr in index, "function %s not in index" % addr
        want = ("candidate_" if entry["confidence"] == "medium" else "") + entry["alias"]
        assert index[addr] == want, "%s: index has %s, want %s" % (addr, index[addr], want)


def test_ram_aliases_in_symbols(record):
    # symbols.tsv keeps the address suffix on RAM names (name or name_<addr>)
    syms = {r["address"]: r["name"] for r in _read_tsv(SYMBOLS)}
    for addr, entry in record["ram_aliases"].items():
        assert addr in syms, "RAM 0x%s not in symbols.tsv" % addr
        accepted = {entry["alias"], entry["alias"] + "_" + addr}
        assert syms[addr] in accepted, "0x%s: symbols.tsv has %s, want %s" % (
            addr, syms[addr], entry["alias"])


def test_monoliths_carry_folded_names(record):
    """The fold-back must reach both monoliths, not only the per-function files."""
    needles = ["crank_edge_period_update", "misfire_monitor_tick"]
    needles += [
        record["ram_aliases"][a]["alias"]
        for a in ("ffffa390", "ffffcb60", "ffffba04")
    ]
    for path in (MONOLITH, NAMED_MONOLITH):
        text = path.read_text(encoding="utf-8", errors="surrogateescape")
        missing = [n for n in needles if n not in text]
        assert not missing, "%s lacks %s" % (path.name, missing)


def test_tsv_mirrors_json(record):
    fn_rows = {r["address"]: r for r in _read_tsv(FN_TSV)}
    ram_rows = {r["address"]: r for r in _read_tsv(RAM_TSV)}
    for addr, entry in record["function_aliases"].items():
        assert addr in fn_rows and fn_rows[addr]["alias"] == entry["alias"], addr
        assert fn_rows[addr]["evidence"], addr
    for addr, entry in record["ram_aliases"].items():
        assert addr in ram_rows and ram_rows[addr]["alias"] == entry["alias"], addr
        assert ram_rows[addr]["evidence"], addr


# (address, expected word) — anchors re-read from the raw ROM; the full set of
# 214 checks lives in verify_misfire_chain.py / rawbin_reverify_log.txt.
POOL_ANCHORS = [
    (0x28058, 0xB660), (0x2805C, 0xB53A), (0x28060, 0xB69C), (0x28062, 0xB6C6),
    (0x28064, 0xBA78), (0x28066, 0xBA40), (0x2806C, 0x0006A6B8),
    (0x28074, 0xFFFFBA28), (0x28078, 0xFFFFBA24),
    (0x447AC, 0x0005FD3C), (0x44D54, 0x0005FD3C),
    (0x44AD0, 0x0006B9F4), (0x44AD8, 0x0006BA00),
    (0x44694, 0x0006B9C0), (0x2861C, 0x0006A630), (0x28720, 0x0006A644),
    (0x2862C, 0x0006A5E0), (0x28630, 0x0006A5F4),
    (0x289CC, 0x00003920),
    (0x5F9E4, 0x0007E55A),
    (0xD00A, 0xF434), (0xD11C, 0xFFFFA390),
    (0x26B08, 0xB688), (0x26B0A, 0xB68A), (0x26B0C, 0xB68C), (0x26B0E, 0xB68E),
    (0x27020, 0x00075474),
]


def test_pool_anchors_match_rom(rom):
    for addr, want in POOL_ANCHORS:
        got16 = struct.unpack(">H", rom[addr:addr + 2])[0]
        got32 = struct.unpack(">I", rom[addr:addr + 4])[0]
        assert got32 == want or got16 == want, "0x%x: got %#x/%#010x want %#x" % (addr, got16, got32, want)


INSTRUCTION_ANCHORS = [
    (0x27FDA, 0x8801),  # cmp/eq 0x1,r0 on 0xffffb53a
    (0x27FDC, 0x8D05),  # bt/s 0x27fea — neutral skips the load compare
    (0x27FE4, 0xF035),  # fcmp/gt fr3,fr0 (load vs ba28)
    (0x2800A, 0xF235),  # fcmp/gt (ba40 > ba78)
    (0x287B0, 0x430B),  # jsr @r3 (SR mask raise) in 0x287aa
    (0x28994, 0x432B),  # tail jmp @r3 (SR restore) in 0x287aa
]


def test_instruction_anchors_match_rom(rom):
    for addr, want in INSTRUCTION_ANCHORS:
        got = struct.unpack(">H", rom[addr:addr + 2])[0]
        assert got == want, "0x%x: got %#06x want %#06x" % (addr, got, want)


def test_arm_polarity_is_or_not_and(rom):
    """0x27fb4: bt/s at 0x27fdc jumps over the load compare when b53a==1, so the
    load floor applies only when NOT neutral — the two conditions are OR-ed."""
    assert struct.unpack(">H", rom[0x27FDA:0x27FDC])[0] == 0x8801  # cmp/eq 0x1,r0
    assert struct.unpack(">H", rom[0x27FDC:0x27FDE])[0] == 0x8D05  # bt/s
    # the load compare sits in the not-taken fall-through path
    assert struct.unpack(">H", rom[0x27FE4:0x27FE6])[0] == 0xF035  # fcmp/gt


def test_float_and_dtc_anchors(rom):
    def f32(a):
        return struct.unpack(">f", rom[a:a + 4])[0]
    assert f32(0x75474) == 11.0          # supply gate (0x26fc0)
    assert f32(0x7BF58) == 4000.0        # sustained-window rpm bound (0x44436)
    assert f32(0xD124) == 6666666.0      # sector-period scale (0xcf96)
    assert struct.unpack(">H", rom[0x7E55A:0x7E55C])[0] == 0x0300
    assert struct.unpack(">H", rom[0x7E55C:0x7E55E])[0] == 0x0301
    assert struct.unpack(">H", rom[0x7E55E:0x7E560])[0] == 0x0302
    assert struct.unpack(">H", rom[0x7E560:0x7E562])[0] == 0x0300  # DTC slot 0
    assert struct.unpack(">H", rom[0x7E562:0x7E564])[0] == 0x0300  # DTC slot 1


def test_generators_idempotent_on_committed_artifacts():
    """Rule 6d: re-running the label pass and the verifier must leave the
    committed artifacts byte-identical."""
    watched = [
        LBL,
        FN_TSV,
        RAM_TSV,
        REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "validation.json",
        REPO / "docs" / "investigations" / "60E15120_N3J1E" / "reviews" / "misfire_detection" / "rawbin_reverify_log.txt",
    ]
    before = {p: p.read_bytes() for p in watched}
    subprocess.run([sys.executable, str(PIPELINE / "review_misfire_detection_labels.py")],
                   cwd=REPO, capture_output=True, check=True)
    subprocess.run([sys.executable, str(PIPELINE / "verify_misfire_chain.py"), "--write"],
                   cwd=REPO, capture_output=True, check=True)
    for path, data in before.items():
        assert path.read_bytes() == data, f"{path.name}: generator not idempotent"
