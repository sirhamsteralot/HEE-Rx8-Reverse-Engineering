#!/usr/bin/env python3
"""DTC code <-> editor-name helpers for the defs (2026-11-03 P-code label pass).

The ROM's DTC code table (per slot, BE u16 — see
docs/investigations/60E15120_N3J1E/dtc_control_report.md §2/§8) stores exactly
the two OBD mode-03 response bytes of the DTC. SAE J2012 / ISO 15031-6 decode:

  byte0 bits 7-6 -> system letter  (00 P, 01 C, 10 B, 11 U)
  byte0 bits 5-4 -> second digit   (0/2 = SAE generic, 1/3 = manufacturer-specific)
  low 12 bits    -> last three hex digits

so u16 0x0420 -> P0420 (catalyst efficiency below threshold, bank 1), 0x2504 ->
P2504, 0x1260 -> P1260 (manufacturer-specific), 0xC167 -> U0167 (network — the
old def label "C167" was a misread of the high hex nibble; 0xC0>>6 = U).

Editor table names become "DTC P0420 Enable/Disable #1" etc. The 4-hex -> 5-char
mapping plus the SAE J2012 description per code lives in data/dtc/pcodes.tsv
(cross-checked against tekseport/obd2-codes and foerbsnavi/OBDex, 2026-11-03);
P1 codes have no SAE definition and are marked manufacturer-specific.

Used by extend_defs_all_roms.py (per-ROM def generation, repair_dtc_tables) and
by relabel_dtc_names.py (merged-def rename). Tests: tests/test_dtc_pcode_labels.py.
"""
from pathlib import Path
import csv
import re

ROOT = Path(__file__).resolve().parents[3]
PCODES_TSV = ROOT / "data" / "dtc" / "pcodes.tsv"

# Matches both the legacy "DTC 0420 ..." names and the relabeled "DTC P0420 ..."
# (any system letter) so re-runs clean up either form.
DTC_NAME_RE = re.compile(
    r"^DTC ([PCBU]?)([0-9A-Fa-f]{4}) Enable/Disable (#\d)( \[additional site 0x[0-9A-Fa-f]+\])?$")

# Per-gate meaning of the three enable/disable bytes (verified in
# dtc_control_report.md §3a: #1 gates evaluation/aging + MIL, #2 gates the
# Mode 03 stored list + freeze frame, #3 is a feature bitmask).
GATE_DESC = {
    "#1": "#1 gate: 1 = fault is evaluated and ages; can light the check-engine lamp.",
    "#2": "#2 gate: 1 = stored fault is reported to scanners (Mode 03 list, freeze frame).",
    "#3": "#3 is a feature bitmask, not on/off (0x02 set path, 0x04/0x08 force store, "
          "0x10 heal-clear, 0x20 reportable).",
}
SAFETY = ("Byte sits inside the checksummed flash range (0x2000-0x7ffff) - "
          "bench-validate before flashing (AGENTS.md rule 10).")


def obd_code(u16):
    """BE u16 DTC as stored in the ROM -> 5-char OBD code ('P0420', 'U0167')."""
    b0 = (u16 >> 8) & 0xFF
    letter = "PCBU"[(b0 >> 6) & 3]
    digit = (b0 >> 4) & 3
    return f"{letter}{digit}{u16 & 0xFFF:03X}"


def parse_dtc_name(name):
    """'DTC P0420 Enable/Disable #1 [additional site 0x...]' -> (u16 code, '#N', suffix)
    or None if not a DTC enable/disable table name (either naming form).
    Round-trips with obd_code(): parse_dtc_name("DTC " + obd_code(v) + ...) -> v.
    The 4-char form is always legacy raw-hex; the 5-char letter form is decoded
    back to the u16 (letter -> bits 7-6, first digit -> bits 5-4)."""
    m = DTC_NAME_RE.match(name or "")
    if not m:
        return None
    letter, hex4, suffix, site = m.group(1), m.group(2), m.group(3), m.group(4) or ""
    if letter:
        b0 = ("PCBU".index(letter) << 6) | (int(hex4[0], 16) << 4)
        code = (b0 << 8) | int(hex4[1:], 16)
    else:
        code = int(hex4, 16)
    return code, suffix, site


def load_pcodes():
    """{u16 code: {'obd_code', 'class', 'sae_j2012_description'}} from data/dtc/pcodes.tsv."""
    out = {}
    with open(PCODES_TSV, newline="", encoding="utf-8") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            v = int(row["code"], 16)
            out[v] = {
                "obd_code": row["obd_code"],
                "class": row["class"],
                "sae_j2012_description": row.get("sae_j2012_description") or "",
            }
    return out


def dtc_table_name(code, suffix_no, dup_addr=None):
    """Editor name for one enable/disable table: 'DTC P0420 Enable/Disable #1'
    (+ '[additional site 0x...]' for duplicate codes, e.g. P0300 slots 0/1)."""
    name = f"DTC {obd_code(code)} Enable/Disable {suffix_no}"
    if dup_addr is not None:
        name += f" [additional site 0x{dup_addr:X}]"
    return name


def dtc_description(code, suffix_no):
    """Short editor-facing <description> (AGENTS.md rule 6b): the DTC's standard
    meaning when SAE-defined, what this switch byte does, and the rule-10
    checksum safety note (the only permitted address-range text)."""
    pc = load_pcodes().get(code)
    c5 = pc["obd_code"] if pc else obd_code(code)
    if pc and pc["class"].endswith("manufacturer-specific"):
        head = f"DTC {c5} (manufacturer-specific code, no SAE J2012 definition)."
    elif pc and pc["sae_j2012_description"]:
        head = f"DTC {c5} - {pc['sae_j2012_description']}."
    else:
        head = f"DTC {c5}."
    return f"{head} {GATE_DESC[suffix_no]} {SAFETY}"
