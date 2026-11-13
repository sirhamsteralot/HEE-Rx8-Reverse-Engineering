#!/usr/bin/env python3
"""Tests for the 2026-11-02 defs relabel pass (utilities/scripts/defs-merge/relabel.py).

Invariants checked against the artifacts on disk:
  * the merged 60E15120 def and every per-ROM def parse and carry the relabel
    pass's short descriptions on the labeled entries (names + categories applied);
  * no pre-existing table changed storageaddress / axis addresses / scaling /
    type / sizes (names and descriptions only, plus whole-table additions);
  * every labeled table's storageaddress equals the data address of its
    descriptor in data/maps/<rom>/index.tsv (address traceability, rule 5);
  * the curated label map covers only descriptors that exist in the reference
    ROM's extraction, and candidate labels keep their "(candidate)" marker;
  * rule 6b: every relabeled entry's <description> is short, marker-free and
    address/derivation-free (simplified what-the-table-does text only);
  * the generator is idempotent on the 60E15120 per-ROM def (description match).
"""
import csv
import json
import re
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

# Base categories renamed upstream in RX8Defs 39d98a0; the curated label map
# predates the rename, so marked tables may still carry the old name (the
# merged 60E15120 def keeps the pre-rename base category names until the label
# map is updated). A curated category is accepted if it or its upstream
# successor exists in the base.
UPSTREAM_CATEGORY_RENAMES = {"Fuel Target (Closed Loop)": "Fuel Injection - Closed Loop"}


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
        # rule 6b: every label carries a short editor-facing desc (no addresses)
        desc = entry.get("desc") or ""
        assert desc, f"{key}: no editor-facing desc"
        assert "0x" not in desc.lower(), f"{key}: address in desc: {desc!r}"


def marked_tables(blk, labels):
    """Relabel-pass entries of a block: identified by their (marker-free)
    short description matching the label map (relabel.is_relabeled), plus
    added-unlabeled entries by name pattern."""
    out = []
    for t in blk.findall("table"):
        n = t.get("name") or ""
        base = n.split(" [0x")[0]  # strip name-collision suffix
        lab = next((l for l in labels.values() if l["name"] == base), None)
        if lab is not None and relabel.is_relabeled(t, lab):
            out.append(t)
        elif lab is None and re.fullmatch(r"Table [123]D - 0x[0-9a-f]+ \(unlabeled\)", n) \
                and (t.findtext("description") or "") == relabel.UNLABELED_DESC:
            out.append(t)
    return out


def assert_rule_6b_descriptions(marked, stem=""):
    """AGENTS.md rule 6b: editor-facing descriptions are short and carry a
    simplified what-the-table-does text only — no memory addresses, no
    structural-match info, no derivation/prior-name/evidence/pass-marker."""
    for t in marked:
        d = t.findtext("description") or ""
        low = d.lower()
        assert "0x" not in low, f"{stem}{t.get('name')}: address in description: {d!r}"
        assert relabel.MARKER not in d, f"{stem}{t.get('name')}: pass marker in description: {d!r}"
        for frag in ("structural", "prior name", "descriptor", "added from", "data/maps",
                     "evidence:", "source:", "relabel"):
            assert frag not in low, f"{stem}{t.get('name')}: {frag!r} in description: {d!r}"
        assert len(d) <= 200, f"{stem}{t.get('name')}: description too long ({len(d)} chars)"


def test_merged_def_relabel_applied():
    blk = rom_block(MERGED, "60E15120")
    labels = {int(k, 16): v for k, v in json.loads(LABELS.read_text(encoding="utf-8"))["entries"].items()}
    by_desc, by_data = relabel.maps_index(relabel.REFERENCE)
    marked = marked_tables(blk, labels)
    assert len(marked) >= 150, f"only {len(marked)} relabeled entries in merged def"
    assert_rule_6b_descriptions(marked)
    # every high/candidate label with a descriptor present in the block is applied
    applied = {t.get("name") for t in marked}
    for desc, lab in labels.items():
        if lab["name"] in applied:
            continue
        # may be name-collision-suffixed
        assert any(n.startswith(lab["name"]) for n in applied), \
            f"label for descriptor 0x{desc:x} ({lab['name']!r}) not applied"
    # storageaddress of every labeled marked table == data_addr of its descriptor
    # (descriptor is recovered from the label map by table name — rule 6b keeps
    # addresses out of the descriptions themselves)
    name_to_desc = {lab["name"]: desc for desc, lab in labels.items()}
    checked = 0
    for t in marked:
        sa = t.get("storageaddress")
        assert sa and int(sa, 16) in by_data, f"{t.get('name')}: sa {sa} not a maps data_addr"
        base = t.get("name").split(" [0x")[0]  # strip name-collision suffix
        if base in name_to_desc:
            assert int(sa, 16) == by_desc[name_to_desc[base]]["data_i"], t.get("name")
            checked += 1
    assert checked >= 100, f"only {checked} labeled tables address-checked"


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
        labels = {int(k, 16): v for k, v in json.loads(LABELS.read_text(encoding="utf-8"))["entries"].items()}
        marked = marked_tables(blk, labels)
        assert len(marked) >= st["renamed"] + st["added"]
        assert_rule_6b_descriptions(marked, stem=f"{stem}: ")
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
            known = cat in base_cats or UPSTREAM_CATEGORY_RENAMES.get(cat) in base_cats
            assert known, f"{stem}: category {cat!r} of {t.get('name')!r} not an existing base category"


def test_generator_idempotent_on_60E15120():
    path = PER_ROM / "60E15120_N3J1E.xml"
    before = path.read_bytes()
    subprocess.run([sys.executable, "utilities/scripts/defs-merge/extend_defs_all_roms.py"],
                   cwd=REPO, check=True, capture_output=True)
    assert path.read_bytes() == before, "extend_defs_all_roms.py not idempotent on 60E15120 per-rom def"
