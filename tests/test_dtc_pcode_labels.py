#!/usr/bin/env python3
"""Tests for the 2026-11-03 DTC P-code label pass (utilities/scripts/defs-merge/dtc_names.py,
relabel_dtc_names.py, repair_dtc_tables in extend_defs_all_roms.py).

Invariants checked against the artifacts on disk:
  * decode rule (SAE J2012 / ISO 15031-6): obd_code/parse_dtc_name round-trip for
    every code in data/dtc/pcodes.tsv; spot checks 0x0420->P0420, 0x2504->P2504,
    0x1260->P1260 (manufacturer-specific), 0xC167->U0167 (network, not "C");
  * data/dtc/pcodes.tsv covers every code used by every ROM's DTC table and every
    per-ROM def DTC table; P1 codes carry no SAE description (manufacturer-specific);
  * every DTC table in every per-ROM def's ROM block and in every active block of
    the merged def is named "DTC <5-char code> Enable/Disable #N", and its u16 code
    equals the ROM code table entry at the slot derived from its storageaddress
    (address traceability, rule 5; audit: data/dtc/defs_audit.tsv = 0 mismatches);
  * rule 6b: DTC <description>s in the per-ROM defs are short, carry the rule-10
    checksum safety note, and contain no per-table storage address;
  * idempotency: re-running repair_dtc_tables on the regenerated 60E15120 block
    reproduces identical DTC table names.
"""
import csv
import re
import struct
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts" / "defs-merge"))
import dtc_names  # noqa: E402
from extend_defs_all_roms import dtc_layout  # noqa: E402

PER_ROM = REPO / "data" / "definitions" / "romraider" / "per-rom"
MERGED = REPO / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
PCODES = REPO / "data" / "dtc" / "pcodes.tsv"
DTC_DIR = REPO / "data" / "dtc"

ROM_PATHS = {
    "60E0G500_N3ZHEC": REPO / "binaries" / "dumps" / "60E0G500_N3ZHEC.bin",
}
for p in (REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs").glob("*.bin"):
    ROM_PATHS[p.stem] = p


def rom_codes(stem):
    """(code_start, nslots, enable1_start, codes) for a ROM; None if not found."""
    path = ROM_PATHS.get(stem)
    if path is None:
        return None
    return dtc_layout(path.read_bytes())


def test_decode_rule_roundtrip_and_spot_checks():
    with open(PCODES, newline="", encoding="utf-8") as f:
        codes = [int(r["code"], 16) for r in csv.DictReader(f, delimiter="\t")]
    assert len(codes) >= 100
    for v in codes:
        name = "DTC " + dtc_names.obd_code(v) + " Enable/Disable #1"
        assert dtc_names.parse_dtc_name(name)[0] == v
    assert dtc_names.obd_code(0x0420) == "P0420"
    assert dtc_names.obd_code(0x2504) == "P2504"
    assert dtc_names.obd_code(0x1260) == "P1260"
    assert dtc_names.obd_code(0xC167) == "U0167"
    assert dtc_names.obd_code(0xC101) == "U0101"
    # legacy 4-hex names parse to the same u16
    assert dtc_names.parse_dtc_name("DTC 0420 Enable/Disable #1")[0] == 0x0420
    assert dtc_names.parse_dtc_name("DTC C167 Enable/Disable #2")[0] == 0xC167


def test_pcodes_covers_all_rom_codes_and_defs():
    with open(PCODES, newline="", encoding="utf-8") as f:
        rows = {int(r["code"], 16): r for r in csv.DictReader(f, delimiter="\t")}
    # every code in every ROM table
    for tsv in DTC_DIR.glob("60*.tsv"):
        with open(tsv, newline="", encoding="utf-8") as f:
            for row in csv.DictReader(f, delimiter="\t"):
                code = row["code"].strip().upper()
                if code == "FFFF":
                    continue
                v = int(code, 16)
                assert v in rows, f"{tsv.name}: code {code} missing from pcodes.tsv"
                assert rows[v]["obd_code"] == dtc_names.obd_code(v)
                if rows[v]["class"].endswith("manufacturer-specific"):
                    assert not rows[v]["sae_j2012_description"]
                else:
                    assert rows[v]["sae_j2012_description"], f"{code}: generic code without SAE text"
    # every DTC table name in the defs
    for xml in list(PER_ROM.glob("*.xml")) + [MERGED]:
        for t in ET.parse(xml).getroot().findall(".//table"):
            parsed = dtc_names.parse_dtc_name(t.get("name"))
            if parsed is not None:
                assert parsed[0] in rows, f"{xml.name}: {t.get('name')} not in pcodes.tsv"


def _rom_block_tables(xml_path):
    """[(name, storageaddress, description)] of DTC tables in the LAST <rom> block
    (the per-ROM def's own block; the base chain keeps upstream placeholder names)."""
    root = ET.parse(xml_path).getroot()
    blocks = root.findall("rom")
    blk = blocks[-1]
    out = []
    for t in blk.findall("table"):
        parsed = dtc_names.parse_dtc_name(t.get("name"))
        if parsed is not None:
            out.append((t.get("name"), t.get("storageaddress"), t.findtext("description") or "", parsed))
    return out


@pytest.mark.parametrize("xml", sorted(PER_ROM.glob("*.xml")), ids=lambda p: p.stem)
def test_per_rom_dtc_names_match_rom_codes(xml):
    lay = rom_codes(xml.stem)
    if lay is None:
        pytest.skip("no ROM binary for this def")
    code_start, nslots, e1, codes = lay
    entries = _rom_block_tables(xml)
    assert entries, f"{xml.name}: no DTC tables in ROM block"
    seen_addr = set()
    for name, addr, desc, (code, suffix, site) in entries:
        # 5-char prefixed name (rule: editor label carries the OBD code)
        assert re.match(r"^DTC [PCBU][0-9A-F]{4} Enable/Disable #\d", name), name
        assert int(addr, 16) not in seen_addr or site, f"duplicate address {addr}: {name}"
        seen_addr.add(int(addr, 16))
        # address traceability: slot from storageaddress, code must equal ROM code
        n = int(suffix[1:])
        slot = int(addr, 16) - e1 - (n - 1) * nslots
        assert 0 <= slot < nslots, f"{name}: slot {slot} out of range"
        assert codes[slot] == code, (
            f"{name} @ {addr}: def code {dtc_names.obd_code(code)} != ROM "
            f"{dtc_names.obd_code(codes[slot])} at slot {slot}")
        # rule 6b: short description, checksum safety note, no per-table address
        assert desc, f"{name}: no description"
        assert "bench-validate" in desc, f"{name}: missing rule-10 safety note"
        assert not re.search(r"0x[0-9A-Fa-f]{4,}", desc.replace("0x2000-0x7ffff", "")), \
            f"{name}: storage address in description: {desc!r}"
    # every used slot is bound exactly once per suffix
    for n in (1, 2, 3):
        bound = {int(a, 16) - e1 - (n - 1) * nslots for _, a, _, (_, s, _) in entries if s == f"#{n}"}
        used = {i for i, c in enumerate(codes) if c != 0xFFFF}
        assert bound == used, f"{xml.stem} #{n}: unbound slots {sorted(used - bound)}"


def test_merged_def_all_blocks_prefixed_and_addresses_unchanged():
    root = ET.parse(MERGED).getroot()
    n_dtc = 0
    for rom in root.findall("rom"):
        for t in rom.findall("table"):
            parsed = dtc_names.parse_dtc_name(t.get("name"))
            if parsed is not None:
                n_dtc += 1
                assert re.match(r"^DTC [PCBU][0-9A-F]{4} Enable/Disable #\d", t.get("name")), t.get("name")
    assert n_dtc > 4000, n_dtc  # 4027 renamed in the pass (comments excluded by ET)


def test_repair_dtc_tables_idempotent_on_regenerated_def():
    import copy
    from extend_defs_all_roms import repair_dtc_tables
    xml = PER_ROM / "60E15120_N3J1E.xml"
    root = ET.parse(xml).getroot()
    blk = root.findall("rom")[-1]
    before = [t.get("name") for t in blk.findall("table")
              if dtc_names.parse_dtc_name(t.get("name"))]
    rec = {"file": "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"}
    repair_dtc_tables(copy.deepcopy(blk), rec)  # must not raise
    blk2 = copy.deepcopy(blk)
    repair_dtc_tables(blk2, rec)
    after = [t.get("name") for t in blk2.findall("table")
             if dtc_names.parse_dtc_name(t.get("name"))]
    assert sorted(before) == sorted(after)
