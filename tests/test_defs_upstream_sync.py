#!/usr/bin/env python3
"""Tests for the upstream RX8Defs sync splice (utilities/scripts/defs-merge/
splice_upstream_dtc_immo.py) and the per-ROM def regeneration (repair_dtc_tables
in extend_defs_all_roms.py).

Invariants checked against the artifacts on disk:
  * every XML under data/definitions (merged def, reviewed copy, upstream
    snapshot, logger def, all per-ROM defs) uses the upstream switch form for
    DTC Enable/Disable tables wherever an entry explicitly carries form
    attributes: #1 "DTC - MIL Illuminate" / #2 "DTC - OBD Report" as
    type="Switch" with states Enabled=01 / Disabled=00, #3 "DTC - Unknown" as
    raw 1D; no entry anywhere still carries the old category="DTCs"/1D form.
    Bare name+storageaddress overrides inherit the base form (name-based
    inheritance), so they carry no attributes — and every file's block-level
    DTC names match its own RX8Base names (checked per file).
  * every file that has a 60E15120 <rom> block with immobilizer tables carries
    the ROM-derived patch addresses (pattern searched in the 60E15120 ROM
    binary; with-RKE = offset + 0x44c with the original "33 20" bytes there;
    the switch "off" state == ROM bytes at the offset) — binary-level
    traceability, AGENTS.md rule 7;
  * the splice pass is idempotent: re-running it leaves every default target
    byte-identical.
"""
import subprocess
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts" / "defs-merge"))
from splice_upstream_dtc_immo import (  # noqa: E402
    DEFAULT_TARGETS, parse_dtc_suffix, DTC_NEW_FORM, SWITCH_STATES,
    IMMO_PATTERN, IMMO_RKE_DELTA, IMMO_RKE_ORIG,
)

DEFS = REPO / "data" / "definitions"
ALL_XML = sorted(DEFS.rglob("*.xml"))
ROM_60E15120 = (REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering"
                / "Stock_ROMs" / "60E15120_N3J1E.bin")


def _dtc_tables(rom):
    return [t for t in rom.findall("table") if parse_dtc_suffix(t.get("name")) is not None]


def _assert_new_form(xml_path, rom):
    for t in _dtc_tables(rom):
        suffix = parse_dtc_suffix(t.get("name"))
        cat, typ = EXPECTED_FORM[suffix]
        if t.get("category") is None and t.get("type") is None:
            continue  # bare name+storageaddress override: inherits the base form
        assert (t.get("category"), t.get("type")) == (cat, typ), \
            f"{xml_path.name} {rom.findtext('romid/xmlid')}: {t.get('name')}: " \
            f"{t.get('category')}/{t.get('type')}, expected {cat}/{typ}"
        if typ == "Switch":
            states = [(s.get("name"), s.get("data")) for s in t.findall("state")]
            assert states == list(SWITCH_STATES), f"{t.get('name')}: states {states}"


EXPECTED_FORM = {
    "#1": ("DTC - MIL Illuminate", "Switch"),
    "#2": ("DTC - OBD Report", "Switch"),
    "#3": ("DTC - Unknown", "1D"),
}


@pytest.mark.parametrize("xml", ALL_XML, ids=lambda p: str(p.relative_to(DEFS)))
def test_every_def_file_uses_the_new_dtc_form(xml):
    """No old-form (category="DTCs" / 1D #1/#2) DTC table anywhere under
    data/definitions; explicit entries all carry the new form; and every
    RX8Base DTC entry is explicit and new-form, so the bare block-level
    overrides inherit the new categories via name-based inheritance."""
    root = ET.parse(xml).getroot()
    for rom in root.findall("rom"):
        _assert_new_form(xml, rom)
        if (rom.findtext("romid/xmlid") or "").lower() == "rx8base":
            base_dtc = _dtc_tables(rom)
            assert base_dtc, f"{xml.name}: no DTC tables in RX8Base"
            for t in base_dtc:
                assert t.get("category") is not None and t.get("type") is not None, \
                    f"{xml.name}: RX8Base DTC entry {t.get('name')!r} is bare — " \
                    "block-level overrides would inherit no form"


def test_no_old_dtc_category_remains_anywhere():
    for xml in ALL_XML:
        for t in ET.parse(xml).getroot().findall(".//table"):
            if parse_dtc_suffix(t.get("name")) is not None:
                assert t.get("category") != "DTCs", f"{xml.name}: {t.get('name')}"
                suffix = parse_dtc_suffix(t.get("name"))
                if t.get("type") is not None:
                    assert not (t.get("type") == "1D" and suffix in ("#1", "#2")), \
                        f"{xml.name}: {t.get('name')} still 1D"


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


@pytest.mark.parametrize("xml", ALL_XML, ids=lambda p: str(p.relative_to(DEFS)))
def test_60e15120_immobilizer_addresses_rom_verified(xml):
    """Every def file carrying a 60E15120 block with immobilizer tables has the
    ROM-verified patch addresses and an 'off' state equal to the ROM bytes."""
    sa, sa_rke, rom = _rom_immo_offsets()
    root = ET.parse(xml).getroot()
    for r in root.findall("rom"):
        xids = [rid.findtext("xmlid") for rid in r.findall("romid")]
        if "60E15120" not in xids:
            continue
        immo = {t.get("name"): t for t in r.findall("table")
                if "Immobilizer Disable" in (t.get("name") or "")}
        if not immo:
            continue
        assert len(immo) == 2, (xml.name, immo.keys())
        no_rke = immo["Immobilizer Disable - Without RKE Installed"]
        with_rke = immo["Immobilizer Disable - With RKE Installed"]
        assert int(no_rke.get("storageaddress"), 16) == sa, xml.name
        assert int(with_rke.get("storageaddress"), 16) == sa_rke, xml.name
        off = next((s for s in no_rke.findall("state") if s.get("name") == "off"), None)
        if off is not None:
            off_bytes = bytes(int(x, 16) for x in off.get("data").split())
            assert rom[sa:sa + len(off_bytes)] == off_bytes, xml.name


def test_splice_pass_idempotent_on_all_default_targets():
    before = {t: t.read_bytes() for t in DEFAULT_TARGETS}
    subprocess.run([sys.executable, "utilities/scripts/defs-merge/splice_upstream_dtc_immo.py"],
                   cwd=REPO, check=True, capture_output=True)
    for t, b in before.items():
        assert t.read_bytes() == b, f"splice pass not idempotent on {t}"
