#!/usr/bin/env python3
"""Tests for the upstream RX8Defs sync splice into the reviewed merged def
(utilities/scripts/defs-merge/splice_upstream_dtc_immo.py) and the per-ROM
def regeneration (repair_dtc_tables in extend_defs_all_roms.py).

Invariants checked against the artifacts on disk:
  * every DTC Enable/Disable table that explicitly carries form attributes is
    in the upstream switch form: #1 "DTC - MIL Illuminate" / #2 "DTC - OBD
    Report" as type="Switch" with states Enabled=01 / Disabled=00, #3
    "DTC - Unknown" as raw 1D — in the merged def's RX8Base and every per-ROM
    def's ROM block (bare name+storageaddress overrides inherit from the base);
  * the 60E15120 immobilizer patch addresses in the merged def and in
    per-rom/60E15120_N3J1E.xml equal the ROM-derived immo start-pattern offset
    (pattern searched in the ROM binary, with-RKE = offset + 0x44c with the
    original "33 20" bytes there, switch "off" state == ROM bytes at the
    offset) — binary-level traceability, AGENTS.md rule 7;
  * the splice pass is idempotent: re-running it leaves the merged def
    byte-identical.
"""
import subprocess
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts" / "defs-merge"))
import dtc_names  # noqa: E402

MERGED = REPO / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
PER_ROM = REPO / "data" / "definitions" / "romraider" / "per-rom"
ROM_60E15120 = (REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering"
                / "Stock_ROMs" / "60E15120_N3J1E.bin")

IMMO_PATTERN = bytes.fromhex("B56E000960D0600C88008D1100098801")
IMMO_RKE_DELTA = 0x44C
IMMO_RKE_ORIG = bytes.fromhex("3320")

EXPECTED_FORM = {
    "#1": ("DTC - MIL Illuminate", "Switch"),
    "#2": ("DTC - OBD Report", "Switch"),
    "#3": ("DTC - Unknown", "1D"),
}
SWITCH_STATES = [("Enabled", "01"), ("Disabled", "00")]


def _dtc_tables(rom):
    return [t for t in rom.findall("table")
            if dtc_names.parse_dtc_name(t.get("name")) is not None]


def _assert_new_form(xml_path, rom):
    for t in _dtc_tables(rom):
        parsed = dtc_names.parse_dtc_name(t.get("name"))
        cat, typ = EXPECTED_FORM[parsed[1]]
        if t.get("category") is None and t.get("type") is None:
            continue  # bare name+storageaddress override: inherits the base form
        assert (t.get("category"), t.get("type")) == (cat, typ), \
            f"{xml_path.name} {rom.findtext('romid/xmlid')}: {t.get('name')}: " \
            f"{t.get('category')}/{t.get('type')}, expected {cat}/{typ}"
        if typ == "Switch":
            states = [(s.get("name"), s.get("data")) for s in t.findall("state")]
            assert states == SWITCH_STATES, f"{t.get('name')}: states {states}"


def test_merged_def_dtc_switch_form_all_blocks():
    root = ET.parse(MERGED).getroot()
    n = 0
    for rom in root.findall("rom"):
        tables = _dtc_tables(rom)
        n += len(tables)
        _assert_new_form(MERGED, rom)
    assert n > 3700, n


@pytest.mark.parametrize("xml", sorted(PER_ROM.glob("*.xml")), ids=lambda p: p.stem)
def test_per_rom_def_dtc_switch_form(xml):
    root = ET.parse(xml).getroot()
    blocks = root.findall("rom")
    assert blocks
    _assert_new_form(xml, blocks[-1])  # the ROM block; base chain checked via merged
    base = next((r for r in blocks if (r.findtext("romid/xmlid") or "").lower() == "rx8base"), None)
    if base is not None:
        _assert_new_form(xml, base)


def _rom_immo_offsets():
    rom = ROM_60E15120.read_bytes()
    hits = []
    i = rom.find(IMMO_PATTERN, 0x2000)
    while i >= 0:
        hits.append(i)
        i = rom.find(IMMO_PATTERN, i + 1)
    assert len(hits) == 1, f"immo pattern hits: {[hex(h) for h in hits]}"
    sa = hits[0]
    assert rom[sa + IMMO_RKE_DELTA:sa + IMMO_RKE_DELTA + 2] == IMMO_RKE_ORIG
    return sa, sa + IMMO_RKE_DELTA, rom


def _immo_of(rom):
    return {t.get("name"): t for t in rom.findall("table")
            if "Immobilizer Disable" in (t.get("name") or "")}


@pytest.mark.parametrize("path", [MERGED, PER_ROM / "60E15120_N3J1E.xml"],
                         ids=["merged", "per-rom"])
def test_60e15120_immobilizer_addresses_rom_verified(path):
    sa, sa_rke, rom = _rom_immo_offsets()
    root = ET.parse(path).getroot()
    blk = None
    for r in root.findall("rom"):
        xids = [rid.findtext("xmlid") for rid in r.findall("romid")]
        if "60E15120" in xids:
            blk = r
    assert blk is not None, f"{path.name}: no 60E15120 block"
    immo = _immo_of(blk)
    assert len(immo) == 2
    no_rke = immo["Immobilizer Disable - Without RKE Installed"]
    with_rke = immo["Immobilizer Disable - With RKE Installed"]
    assert int(no_rke.get("storageaddress"), 16) == sa
    assert int(with_rke.get("storageaddress"), 16) == sa_rke
    # the switch "off" state must be the ROM's own bytes at the patch site
    off = next((s for s in no_rke.findall("state") if s.get("name") == "off"), None)
    assert off is not None
    off_bytes = bytes(int(x, 16) for x in off.get("data").split())
    assert rom[sa:sa + len(off_bytes)] == off_bytes


def test_splice_pass_idempotent_on_merged_def():
    before = MERGED.read_bytes()
    subprocess.run([sys.executable, "utilities/scripts/defs-merge/splice_upstream_dtc_immo.py"],
                   cwd=REPO, check=True, capture_output=True)
    assert MERGED.read_bytes() == before, "splice_upstream_dtc_immo.py not idempotent on merged def"
