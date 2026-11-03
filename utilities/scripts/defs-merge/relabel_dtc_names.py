#!/usr/bin/env python3
"""Rename the DTC enable/disable tables in rx8defs-merged-60E15120.xml from the
raw 4-hex form to the standard 5-char OBD code ("DTC 0420 ..." -> "DTC P0420 ...",
"DTC C167 ..." -> "DTC U0167 ..."), in EVERY active <rom> block so RomRaider's
name-based inheritance between base and child blocks keeps working.

Decode rule (SAE J2012 / ISO 15031-6; the ROM stores the two mode-03 response
bytes as BE u16): byte0 bits 7-6 -> letter (P/C/B/U), bits 5-4 -> second digit,
low 12 bits -> last 3 digits. Mapping + SAE descriptions: data/dtc/pcodes.tsv;
helper module: dtc_names.py. Evidence: dtc_control_report.md §2/§5 (ROM code
table 0x7e560, mode-03 emission 0x667c8) + §5b of the 2026-11-03 pass.

Within a block, duplicate codes (P0300 occupies slots 0 and 1) get distinct
"[additional site 0xADDR]" suffixes — same rule as repair_dtc_tables() in
extend_defs_all_roms.py — so the rename introduces no new duplicate names.
Commented-out blocks are left untouched. DTC entries that already carry a
<description> (the 2026-09-30 "not independently verified" annotations) get it
replaced by the short rule-6b form (rule 6c); DTC identity is now verified at
ROM-binary level.

Surgical splice like relabel_merged_def.py: only changed <table> elements are
re-serialized and spliced over their original line spans; every other byte of
the file is untouched (verified by re-parse + address-multiset comparison).

Run from the repo root:
  python utilities/scripts/defs-merge/relabel_dtc_names.py [--dry-run]
Writes stats to
docs/investigations/60E15120_N3J1E/defs-merge/dtc_pcode_labels_2026-11-03.json
"""
from pathlib import Path
import copy
import json
import sys
import xml.etree.ElementTree as E
import xml.parsers.expat as expat

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import dtc_names

MERGED = ROOT / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
STATS_OUT = ROOT / "docs" / "investigations" / "60E15120_N3J1E" / "defs-merge" / "dtc_pcode_labels_2026-11-03.json"


def table_spans(text):
    """(start_line, end_line, attrs, rom_depth_key) of every <table> element in
    `text` via expat (line numbers accurate). rom_key is the 0-indexed line of
    the innermost enclosing <rom> start tag (None outside any <rom>)."""
    spans = []
    depth = 0
    cur = None
    rom_stack = []

    def start_el(name, attrs):
        nonlocal depth, cur
        if name == "rom":
            rom_stack.append(p.CurrentLineNumber - 1)
        if name == "table":
            if depth == 0:
                cur = (p.CurrentLineNumber - 1, dict(attrs), rom_stack[-1] if rom_stack else None)
            depth += 1

    def end_el(name):
        nonlocal depth, cur
        if name == "table":
            depth -= 1
            if depth == 0 and cur is not None:
                spans.append((cur[0], p.CurrentLineNumber - 1, cur[1], cur[2]))
                cur = None
        elif name == "rom" and rom_stack:
            rom_stack.pop()

    p = expat.ParserCreate()
    p.StartElementHandler = start_el
    p.EndElementHandler = end_el
    p.Parse(text, True)
    return spans


def serialize(el, indent="    "):
    el = copy.deepcopy(el)
    E.indent(el, space=indent)
    el.tail = None
    txt = E.tostring(el, encoding="unicode")
    lines = txt.split("\n")
    return "\n".join(indent + ln if ln.strip() else ln for ln in lines)


def main():
    dry = "--dry-run" in sys.argv
    raw = MERGED.read_bytes()
    bom = raw.startswith(b"\xef\xbb\xbf")
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = [ln.rstrip("\r") for ln in text.split("\n")]
    frag_text = "\n".join(lines)

    spans = table_spans(frag_text)
    # plan new names per (rom block, code, suffix): within-block duplicates of a
    # code (P0300 slots 0/1) get " [additional site 0xADDR]" on 2nd+ occurrence
    seen = {}
    plan = {}  # span index -> new name
    for i, (s, e, attrs, rom_key) in enumerate(spans):
        name = attrs.get("name") or ""
        parsed = dtc_names.parse_dtc_name(name)
        if parsed is None:
            continue
        code, suffix, site = parsed
        base = f"DTC {dtc_names.obd_code(code)} Enable/Disable {suffix}"
        key = (rom_key, code, suffix)
        seen[key] = seen.get(key, 0) + 1
        if site:
            # already carries an "[additional site ...]" suffix: keep it verbatim
            plan[i] = f"{base}{site}"
        elif seen[key] == 1:
            plan[i] = base
        else:
            addr = attrs.get("storageaddress")
            # within-block duplicate code (P0300 slots 0/1); base-block entries
            # carry no address — keep the pre-existing duplicate as-is there
            plan[i] = f"{base} [additional site 0x{int(addr, 16):X}]" if addr and addr != "0x0" else base

    edits = []
    stats = {"renamed": 0, "suffixed": 0, "descriptions_replaced": 0, "details": []}
    addr_before = []
    for i, (s, e, attrs, rom_key) in enumerate(spans):
        name = attrs.get("name") or ""
        parsed = dtc_names.parse_dtc_name(name)
        if parsed is None or i not in plan:
            continue
        code, suffix, site = parsed
        new_name = plan[i]
        addr_before.append(attrs.get("storageaddress"))
        frag = E.fromstring("<root>" + "\n".join(lines[s:e + 1]) + "</root>")[0]
        d = frag.find("description")
        new_desc = dtc_names.dtc_description(code, suffix) if d is not None else None
        if new_name == name and (d is None or d.text == new_desc):
            continue  # already in final form (idempotent re-run)
        frag.set("name", new_name)
        if d is not None:
            if d.text != new_desc:
                stats["descriptions_replaced"] += 1
            d.text = new_desc
        edits.append((s, e, serialize(frag)))
        if new_name != name:
            stats["renamed"] += 1
        if new_name != f"DTC {dtc_names.obd_code(code)} Enable/Disable {suffix}":
            stats["suffixed"] += 1
        stats["details"].append({"old": name, "new": new_name,
                                 "storageaddress": attrs.get("storageaddress")})

    if dry:
        print(f"dry run: would rename {stats['renamed']} DTC tables "
              f"({stats['suffixed']} site-suffixed, {stats['descriptions_replaced']} descriptions replaced)")
        return

    out_lines = lines[:]
    for s, e, txt in sorted(edits, key=lambda x: x[0], reverse=True):
        out_lines[s:e + 1] = txt.split("\n")
    new_text = "\n".join(out_lines)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    MERGED.write_bytes((b"\xef\xbb\xbf" if bom else b"") + new_text.encode("utf-8"))

    # verify: re-parse; DTC names all 5-char, addresses untouched, no duplicate
    # name count increase per block
    before_root = E.fromstring(text)
    back = E.parse(MERGED).getroot()
    addr_after = []

    def block_stats(root):
        out = {}
        for rom in root.findall("rom"):
            xid = rom.findtext("romid/xmlid")
            names = [t.get("name") for t in rom.findall("table")]
            dup_count = len(names) - len(set(names))
            out[xid] = dup_count
        return out

    dup_before = block_stats(before_root)
    dup_after = block_stats(back)
    for xid, d in dup_after.items():
        assert d <= dup_before.get(xid, 0), f"block {xid}: duplicate names grew {dup_before.get(xid)} -> {d}"
    for rom in back.findall("rom"):
        for t in rom.findall("table"):
            n = t.get("name") or ""
            if dtc_names.parse_dtc_name(n) is not None:
                assert n[4] in "PCBU", f"unprefixed DTC name left: {n}"
                addr_after.append(t.get("storageaddress"))
    assert sorted(a for a in addr_before if a) == sorted(a for a in addr_after if a), \
        "storageaddress multiset changed"
    stats.update({"file": str(MERGED.relative_to(ROOT)), "pass": __doc__.splitlines()[0],
                  "bom": bom, "crlf": nl == b"\r\n"})
    if stats["renamed"] or stats["descriptions_replaced"]:
        # cumulative run log: keep earlier runs, append this one
        doc = {"file": str(MERGED.relative_to(ROOT)), "pass": __doc__.splitlines()[0],
               "runs": []}
        if STATS_OUT.exists():
            try:
                prev = json.loads(STATS_OUT.read_text(encoding="utf-8"))
                doc["runs"] = prev.get("runs") or [prev]
            except Exception:
                pass
        doc["runs"].append(stats)
        STATS_OUT.write_text(json.dumps(doc, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
        print(f"OK: renamed {stats['renamed']} DTC tables ({stats['suffixed']} site-suffixed, "
              f"{stats['descriptions_replaced']} descriptions replaced); stats -> {STATS_OUT.relative_to(ROOT)}")
    else:
        print(f"normalization-only run (nothing to change); stats file left untouched: {STATS_OUT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
