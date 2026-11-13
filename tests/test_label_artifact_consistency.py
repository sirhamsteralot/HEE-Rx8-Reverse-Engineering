#!/usr/bin/env python3
"""Cross-artifact consistency of the 60E15120_N3J1E label records.

Locks in the label-artifact audit: the accepted source-review TSVs and every
per-subsystem labels JSON under data/labels/60E15120_N3J1E/ must agree in
both directions.

  * TSV -> JSON: every accepted_ram_aliases.tsv / accepted_function_aliases.tsv
    / accepted_lookup_aliases.tsv row appears in at least one labels JSON
    (ram_aliases / function_aliases / lookup_aliases dicts, or a `functions`
    list with an address field) with the same alias.
  * JSON -> TSV: every labels-JSON alias entry has a TSV row for the same
    address with the same alias (this is verify_claims.py check 4 as a test).
  * Evidence: every TSV row and every JSON alias entry carries a non-empty
    evidence string (RAM TSV anchoring in the raw ROM is separately proven by
    tests/test_source_review_ram_aliases.py).
  * Row shape: every TSV row has all its columns (the 4-field RAM rows that
    broke annotate_source_review.py are fixed rows, this guards them).
  * symbols.tsv covers every accepted RAM address.

Run: python -m pytest tests/test_label_artifact_consistency.py
"""
import csv
import json
import re
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
SR = REPO / "docs/investigations/60E15120_N3J1E/labeling/source_review"
LABELS = REPO / "data/labels/60E15120_N3J1E"
SYMBOLS = REPO / "reverse-engineered/decompiled/60E15120_N3J1E/symbols.tsv"


def _read_tsv(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def _read_raw_rows(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        return list(csv.reader(fh, delimiter="\t"))


def _hex8(s):
    m = re.search(r"([0-9a-f]{8})$", s.lower())
    return m.group(1) if m else None


@pytest.fixture(scope="module")
def ram_tsv():
    return _read_tsv(SR / "accepted_ram_aliases.tsv")


@pytest.fixture(scope="module")
def fn_tsv():
    return _read_tsv(SR / "accepted_function_aliases.tsv")


@pytest.fixture(scope="module")
def lkp_tsv():
    return _read_tsv(SR / "accepted_lookup_aliases.tsv")


@pytest.fixture(scope="module")
def json_index():
    """addr -> (alias, has_evidence) across all labels JSONs, per kind.
    kind 'function' also covers `functions` lists with address fields."""
    idx = {"ram": {}, "function": {}, "lookup": {}}
    for jp in sorted(LABELS.glob("*.json")):
        try:
            data = json.loads(jp.read_text(errors="surrogateescape"))
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        for addr, entry in data.get("ram_aliases", {}).items():
            if isinstance(entry, dict):
                idx["ram"].setdefault(addr.lower(), set()).add(
                    (entry.get("alias"), bool((entry.get("evidence") or "").strip())))
        for addr, entry in data.get("function_aliases", {}).items():
            if isinstance(entry, dict):
                idx["function"].setdefault(addr.lower(), set()).add(
                    (entry.get("alias"), bool((entry.get("evidence") or "").strip())))
        for entry in data.get("functions", []):
            if isinstance(entry, dict) and entry.get("address"):
                idx["function"].setdefault(entry["address"].lower(), set()).add(
                    (entry.get("alias"), bool((entry.get("evidence") or "").strip())))
        for key, entry in data.get("lookup_aliases", {}).items():
            h = _hex8(key)
            if not h:
                continue
            if isinstance(entry, dict):
                idx["lookup"].setdefault(h, set()).add(
                    (entry.get("alias"), bool((entry.get("evidence") or "").strip())))
            else:
                idx["lookup"].setdefault(h, set()).add((entry, False))
    return idx


def test_ram_tsv_row_shape_and_evidence():
    rows = _read_raw_rows(SR / "accepted_ram_aliases.tsv")
    assert rows[0] == ["address", "alias", "type", "reader", "evidence"]
    for r in rows[1:]:
        assert len(r) == 5, f"4-field row survived: {r}"
        assert r[4].strip(), f"empty evidence: {r[0]}"


def test_lookup_and_function_tsv_evidence():
    for name, ncols in (("accepted_lookup_aliases.tsv", 4), ("accepted_function_aliases.tsv", 4)):
        rows = _read_raw_rows(SR / name)
        for r in rows[1:]:
            assert len(r) == ncols, f"short row in {name}: {r}"
            assert r[ncols - 1].strip(), f"empty evidence in {name}: {r[0]}"


def test_tsv_rows_present_in_labels_jsons(ram_tsv, fn_tsv, lkp_tsv, json_index):
    missing = []
    for r in ram_tsv:
        a = r["address"].lower()
        if a not in json_index["ram"] or (r["alias"], True) not in json_index["ram"][a] \
                and not any(al == r["alias"] for al, _ in json_index["ram"].get(a, set())):
            missing.append(("ram", a, r["alias"]))
    for r in fn_tsv:
        a = r["address"].lower()
        if not any(al == r["alias"] for al, _ in json_index["function"].get(a, set())):
            missing.append(("function", a, r["alias"]))
    for r in lkp_tsv:
        h = _hex8(r["original"])
        if not any(al == r["alias"] for al, _ in json_index["lookup"].get(h, set())):
            missing.append(("lookup", r["original"], r["alias"]))
    assert not missing, f"TSV rows with no matching labels-JSON entry: {missing[:10]}"


def test_json_entries_have_tsv_counterpart_and_evidence(json_index, ram_tsv, fn_tsv, lkp_tsv):
    ram_alias = {r["address"].lower(): r["alias"] for r in ram_tsv}
    fn_alias = {r["address"].lower(): r["alias"] for r in fn_tsv}
    lkp_alias = {_hex8(r["original"]): r["alias"] for r in lkp_tsv}
    tsvs = {"ram": ram_alias, "function": fn_alias, "lookup": lkp_alias}
    failures = []
    for kind, entries in json_index.items():
        for addr, pairs in entries.items():
            for alias, has_ev in pairs:
                if not has_ev:
                    failures.append(f"{kind} {addr} alias {alias!r}: no evidence in any JSON")
                if tsvs[kind].get(addr) != alias:
                    failures.append(f"{kind} {addr} alias {alias!r}: TSV says {tsvs[kind].get(addr)!r}")
    assert not failures, failures[:10]


def test_symbols_tsv_covers_all_ram_rows(ram_tsv):
    with SYMBOLS.open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        sym_addrs = {r["address"].lower() for r in csv.DictReader(fh, delimiter="\t")}
    missing = [r["address"] for r in ram_tsv if r["address"].lower() not in sym_addrs]
    assert not missing, f"RAM TSV rows missing from symbols.tsv: {missing}"
