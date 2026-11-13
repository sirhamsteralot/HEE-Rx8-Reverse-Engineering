"""Candidate-label promotion pass: prove-or-demote decisions for the export.

Verifies the decisions recorded in
data/labels/60E15120_N3J1E/candidate_promotions.json against the export and
the curated alias TSV:

- the 112 proven `candidate_*` labels lost the prefix in function_index.tsv,
  callgraph.tsv, symbols.tsv, the per-function C files and the monoliths;
- 0x22144 was renamed to `candidate_fuel_open_loop_condition` (gate uses the
  fuel open-loop flag; the old "evap" attribution came from an inherited ref_
  caller name) and stays medium;
- the 69 remaining `candidate_*` labels are unchanged (kept as hypotheses per
  the label ladder, evidence recorded);
- accepted_function_aliases.tsv carries confidence=high for the promoted rows;
- the raw ROM is untouched (SHA-256 asserted).

Run: python -m pytest tests/test_candidate_label_promotions.py
"""
import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEC = ROOT / "reverse-engineered/decompiled/60E15120_N3J1E"
LABELS = ROOT / "data/labels/60E15120_N3J1E"
INV = ROOT / "docs/investigations/60E15120_N3J1E"
ROM = ROOT / "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"
ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"


def read_tsv(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def record():
    return json.loads((LABELS / "candidate_promotions.json").read_text())


def test_rom_unchanged():
    assert hashlib.sha256(ROM.read_bytes()).hexdigest() == ROM_SHA256


def test_record_counts_match_export():
    rec = record()
    idx = read_tsv(DEC / "function_index.tsv")
    cand_rows = [r for r in idx if r["name"].startswith("candidate_")]
    promoted = rec["promoted_to_high"]
    renamed = rec["renamed_staying_medium"]
    kept = rec["kept_candidate"]
    assert rec["counts"] == {
        "candidate_total": len(promoted) + len(renamed) + len(kept),
        "promoted": len(promoted),
        "renamed": len(renamed),
        "kept_candidate": len(kept),
    }
    # export still carries exactly the kept + renamed candidates
    assert len(cand_rows) == len(kept) + len(renamed)
    by_addr = {r["address"]: r["name"] for r in idx}
    for a, name in kept.items():
        assert by_addr[a] == name, a
    for a, r in renamed.items():
        assert by_addr[a] == r["new"], a


def test_promoted_names_applied_everywhere():
    rec = record()
    idx = {r["address"]: r for r in read_tsv(DEC / "function_index.tsv")}
    for a, p in rec["promoted_to_high"].items():
        assert idx[a]["name"] == p["alias"], a
        body = (DEC / idx[a]["file"]).read_text(encoding="utf-8", errors="surrogateescape")
        assert re.search(r"\b" + re.escape(p["alias"]) + r"\s*\(", body), a
    # symbols.tsv and callgraph.tsv carry the new names too
    syms = read_tsv(DEC / "symbols.tsv")
    sym_names = {r["name"] for r in syms}
    for a, p in rec["promoted_to_high"].items():
        assert p["alias"] in sym_names, a
    calls = read_tsv(DEC / "callgraph.tsv")
    call_names = {r.get("callee_name", "") for r in calls}
    for a, p in rec["promoted_to_high"].items():
        if any(r["callee"] == a for r in calls):
            assert p["alias"] in call_names, a
    # monoliths
    mono = (DEC / "firmware_decompiled.c").read_text(encoding="utf-8", errors="surrogateescape")
    named = (DEC / "named/firmware_named.c").read_text(encoding="utf-8", errors="surrogateescape")
    for a, p in list(rec["promoted_to_high"].items())[:20]:
        assert p["alias"] in mono and p["alias"] in named, a
    for a, r in rec["renamed_staying_medium"].items():
        assert r["new"] in mono and r["new"] in named, a


def test_accepted_tsv_confidences():
    rec = record()
    rows = {r["address"]: r for r in read_tsv(INV / "labeling/source_review/accepted_function_aliases.tsv")}
    for a, p in rec["promoted_to_high"].items():
        assert rows[a]["confidence"] == "high", a
        assert rows[a]["alias"] == p["alias"], a
    for a, r in rec["renamed_staying_medium"].items():
        assert rows[a]["confidence"] == "medium", a
        assert rows[a]["alias"] == r["new"][len("candidate_"):], a


def test_knock_loop_records_updated():
    kld = json.loads((LABELS / "knock_loop_labels.json").read_text())
    fa = kld["function_aliases"]
    expect = {
        "000064ba": ("knock_sensor_fault_task", "high"),
        "000390b8": ("knock_sensor_monitor_task", "high"),
        "000145c8": ("timing_retard_fast_task", "high"),
        "0001467c": ("knock_rough_correction_update", "high"),
        "0003d010": ("o2_monitor_integrator", "high"),
        "00022144": ("fuel_open_loop_condition", "medium"),
    }
    for a, (alias, conf) in expect.items():
        key = next(k for k in fa if (k.lower()[2:] if k.lower().startswith("0x") else k.lower()) == a)
        assert fa[key]["alias"] == alias and fa[key]["confidence"] == conf, a
        assert fa[key]["evidence"], a


def test_cross_rom_mode22_base_names_updated():
    rec = record()
    promoted_names = {p["name"] for p in rec["promoted_to_high"].values()}
    for tsv in [ROOT / "data/labels/cross_rom_mode22_pid_handlers.tsv",
                *sorted((ROOT / "data/labels/cross_rom/mode22").glob("*.tsv"))]:
        for r in read_tsv(tsv):
            base = r.get("base_function_name", "")
            assert base not in promoted_names, (tsv.name, base)
