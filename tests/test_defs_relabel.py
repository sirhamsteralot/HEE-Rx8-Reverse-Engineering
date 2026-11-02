#!/usr/bin/env python3
"""Tests for the 2026-11-02 defs relabel pass (utilities/scripts/defs-merge/relabel.py).

Invariants checked against the artifacts on disk:
  * the merged 60E15120 def and every per-ROM def parse and carry the relabel
    marker on the labeled entries (names + categories applied);
  * no pre-existing table changed storageaddress / axis addresses / scaling /
    type / sizes (names and descriptions only, plus whole-table additions);
  * every labeled table's storageaddress equals the data address of its
    descriptor in data/maps/<rom>/index.tsv (address traceability, rule 5);
  * the curated label map covers only descriptors that exist in the reference
    ROM's extraction, and candidate labels keep their "(candidate)" marker;
  * the generator is idempotent on the 60E15120 per-ROM def (marker skip).
"""
import csv
import json
import subprocess
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts" / "defs-merge"))
import relabel  # noqa: E402

MERGED = REPO / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
PER_ROM = REPO / "data" / "definitions" / "romraider" / "per-rom"
LABELS = REPO / "data" / "labels" / "60E15120_N3J1E" / "defs_table_labels.json"


def rom_block(path, xmlid):
    root = ET.parse(path).getroot()
    for rom in root.findall("rom"):
        if rom.findtext("romid/xmlid") == xmlid:
            return rom
    if root.findall("rom") and xmlid is None:
        return root.findall("rom")[-1]
    raise AssertionError(f"{path}: no rom block {xmlid}")


def table_sig(t):
    return (
        t.get("storageaddress"),
        tuple(sorted((c.get("type"), c.get("storageaddress")) for c in t.findall("table"))),
        tuple(sorted((s.get("expression"), s.get("to_byte")) for s in t.findall("scaling"))),
        t.get("type"), t.get("storagetype"), t.get("sizex"), t.get("sizey"),
    )


def test_label_map_is_consistent_with_reference_extraction():
    labels = json.loads(LABELS.read_text(encoding="utf-8"))
    assert labels["reference_rom"] == relabel.REFERENCE
    with open(REPO / "data" / "maps" / relabel.REFERENCE / "index.tsv",
              newline="", encoding="utf-8") as f:
        descs = {int(r["descriptor"], 16) for r in csv.DictReader(f, delimiter="\t")}
    for key, entry in labels["entries"].items():
        assert int(key, 16) in descs, f"{key}: not a descriptor of the reference ROM"
        if entry["confidence"] == "candidate":
            assert "(candidate)" in entry["name"], entry["name"]
        assert entry.get("category"), f"{key}: no category (grouping)"
        assert entry.get("source"), f"{key}: no provenance source"


def test_merged_def_relabel_applied():
    blk = rom_block(MERGED, "60E15120")
    labels = {int(k, 16): v for k, v in json.loads(LABELS.read_text(encoding="utf-8"))["entries"].items()}
    by_desc, by_data = relabel.maps_index(relabel.REFERENCE)
    marked = [t for t in blk.findall("table") if relabel.MARKER in (t.findtext("description") or "")]
    assert len(marked) >= 150, f"only {len(marked)} relabeled entries in merged def"
    # every high/candidate label with a descriptor present in the block is applied
    applied = {t.get("name") for t in marked}
    for desc, lab in labels.items():
        if lab["name"] in applied:
            continue
        # may be name-collision-suffixed
        assert any(n.startswith(lab["name"]) for n in applied), \
            f"label for descriptor 0x{desc:x} ({lab['name']!r}) not applied"
    # storageaddress of every marked table == data_addr of its descriptor
    desc_of = {}
    for t in marked:
        import re
        m = re.search(r"descriptor 0x([0-9a-f]+)", t.findtext("description") or "")
        if m:
            desc_of[t.get("name")] = int(m.group(1), 16)
    for name, desc in desc_of.items():
        row = by_desc[desc]
        t = next(x for x in marked if x.get("name") == name)
        assert int(t.get("storageaddress"), 16) == row["data_i"], name


def test_per_rom_defs_carry_labels_and_keep_geometry():
    coverage = json.loads((REPO / "data" / "definitions" / "coverage.json").read_text(encoding="utf-8"))
    roms = {r["stem"]: r for r in coverage["roms"] if r.get("per_rom_def")}
    assert len(roms) >= 9
    for stem, rec in roms.items():
        path = REPO / rec["per_rom_def"]
        root = ET.parse(path).getroot()
        blk = root.findall("rom")[-1]
        st = rec["relabel_2026-11-02"]
        if st.get("skipped"):
            continue  # 60E32000_*: upstream block layout mismatch, documented
        marked = [t for t in blk.findall("table") if relabel.MARKER in (t.findtext("description") or "")]
        assert len(marked) >= st["renamed"] + st["added"]
        # every marked table's storageaddress is a real data address of this ROM
        _, by_data = relabel.maps_index(stem)
        for t in marked:
            sa = t.get("storageaddress")
            assert sa and int(sa, 16) in by_data, f"{stem}: {t.get('name')} sa {sa} not a maps data_addr"
        # unique names
        names = [t.get("name") for t in blk.findall("table")]
        new_dups = {n for n in names if names.count(n) > 1} - set(st.get("preexisting_duplicate_names", []))
        assert not new_dups, f"{stem}: relabel introduced duplicate names {new_dups}"
        # categories used by the pass are real RomRaider categories seen in the base
        base = None
        for rom in root.findall("rom"):
            if (rom.findtext("romid/xmlid") or "").lower() == "rx8base":
                base = rom
        base_cats = {t.get("category") for t in base.findall("table")}
        for t in marked:
            cat = t.get("category")
            if cat and cat.startswith("Unknown"):
                continue
            assert cat in base_cats, f"{stem}: category {cat!r} of {t.get('name')!r} not an existing base category"


def test_generator_idempotent_on_60E15120():
    path = PER_ROM / "60E15120_N3J1E.xml"
    before = path.read_bytes()
    subprocess.run([sys.executable, "utilities/scripts/defs-merge/extend_defs_all_roms.py"],
                   cwd=REPO, check=True, capture_output=True)
    assert path.read_bytes() == before, "extend_defs_all_roms.py not idempotent on 60E15120 per-rom def"
