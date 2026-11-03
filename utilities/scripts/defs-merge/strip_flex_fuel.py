#!/usr/bin/env python3
"""Strip upstream flex-fuel content from the owned RomRaider defs (stock-only policy).

Removes, via byte-preserving line splices (BOM / CRLF / all other bytes and comments
untouched):

  * every top-level <table category="Flex Fuel"> in any <rom> block — the G-ROM_FLEX-only
    tables that the RX8Base chain hands to every ROM, incl. 'Table 2D - Stoich Fuel Ratio'
    @0x6C444 (in a stock ROM that address is tbl_068f94's data, not a stoich table);
  * comment spans wrapping such a flex table (e.g. the commented-out 'Table 2D - Cranking
    Fuel Multiplier' line in the RX8Base block);
  * the whole <rom> block whose romid xmlid is G-ROM_FLEX (flex-fuel variant ROM; no
    binary in this repo, and nothing bases on it — verified by grep 'base="G-ROM_FLEX"').

Evidence: all 14 dumped ROMs are stock/non-flex — each carries exactly one 14.7 stoich
literal (0x416b3333) and no ethanol-indexed 1/AFR table was found in any of them
(calibration_extraction_report.md section 6a flex-fuel cross-check;
defs-merge/inheritance_issues.json lists the G-ROM_FLEX inheritance as unresolved).
Policy + provenance: data/definitions/README.md 'Stock-only defs'.

Idempotent. Run from the repo root:

  python utilities/scripts/defs-merge/strip_flex_fuel.py [--check] [paths ...]

Defaults to the owned defs (merged 60E15120 def, reviewed copy, upstream ff5ab4f
snapshot, and all per-ROM defs — the latter are regenerated stock-only by
extend_defs_all_roms.py, so this is a no-op guard on them). --check reports what would
change (exit 1 if anything would) without writing.
"""

from pathlib import Path
import sys
import xml.etree.ElementTree as E
import xml.parsers.expat as expat

ROOT = Path(__file__).resolve().parents[3]

FLEX_CATEGORY = "Flex Fuel"
FLEX_ROM_XMLID = "G-ROM_FLEX"

DEFAULT_PATHS = [
    ROOT / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml",
    ROOT / "data" / "definitions" / "romraider" / "reviewed-rx8defs-copy" / "rx8_defs.xml",
    ROOT / "data" / "definitions" / "romraider" / "upstream-rx8defs" / "rx8_defs.xml",
] + sorted((ROOT / "data" / "definitions" / "romraider" / "per-rom").glob("*.xml"))


def flex_spans(lines):
    """Line spans (0-indexed, inclusive) to delete: top-level 'Flex Fuel' tables,
    comments wrapping a flex table, and the G-ROM_FLEX <rom> block."""
    text = "\n".join(lines)
    spans = []
    rom_stack = []          # (start_line, xmlid or None)
    table_depth = 0
    table_start = None
    table_attrs = None
    xmlid_buf = None

    def start_el(name, attrs):
        nonlocal table_depth, table_start, table_attrs, xmlid_buf
        line = p.CurrentLineNumber - 1
        if name == "rom":
            rom_stack.append([line, None])
        elif name == "table":
            if table_depth == 0:
                table_start, table_attrs = line, attrs
            table_depth += 1
        elif name == "xmlid":
            xmlid_buf = ""

    def end_el(name):
        nonlocal table_depth, table_start, table_attrs, xmlid_buf
        line = p.CurrentLineNumber - 1
        if name == "rom":
            start, xmlid = rom_stack.pop()
            if xmlid == FLEX_ROM_XMLID:
                spans.append((start, line))
        elif name == "table":
            table_depth -= 1
            if table_depth == 0 and table_attrs is not None:
                if table_attrs.get("category") == FLEX_CATEGORY:
                    spans.append((table_start, line))
                table_start = table_attrs = None
        elif name == "xmlid":
            if rom_stack and xmlid_buf is not None:
                rom_stack[-1][1] = xmlid_buf
            xmlid_buf = None

    def char_data(data):
        nonlocal xmlid_buf
        if xmlid_buf is not None:
            xmlid_buf += data

    def comment(data):
        # line of the comment's end; walk back to its '<!--'
        end = p.CurrentLineNumber - 1
        if f'category="{FLEX_CATEGORY}"' in data and "<table" in data:
            start = end
            while start > 0 and "<!--" not in lines[start]:
                start -= 1
            spans.append((start, end))

    p = expat.ParserCreate()
    p.StartElementHandler = start_el
    p.EndElementHandler = end_el
    p.CharacterDataHandler = char_data
    p.CommentHandler = comment
    p.Parse(text, True)

    # merge overlapping spans, sort
    spans.sort()
    merged = []
    for s, e in spans:
        if merged and s <= merged[-1][1] + 1:
            merged[-1][1] = max(merged[-1][1], e)
        else:
            merged.append([s, e])
    return [tuple(m) for m in merged]


def strip_file(path, check=False):
    raw = path.read_bytes()
    bom = raw.startswith(b"\xef\xbb\xbf")
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = [ln.rstrip("\r") for ln in text.split("\n")]

    spans = flex_spans(lines)
    if not spans:
        return 0
    if check:
        n = sum(e - s + 1 for s, e in spans)
        print(f"{path.relative_to(ROOT)}: would remove {len(spans)} span(s), {n} line(s)")
        return len(spans)

    out = lines[:]
    for s, e in sorted(spans, reverse=True):
        del out[s:e + 1]
    new_text = "\n".join(out)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    path.write_bytes((b"\xef\xbb\xbf" if bom else b"") + new_text.encode("utf-8"))

    # verify the artifact: parses, no flex table, no G-ROM_FLEX block
    back = E.parse(path).getroot()
    assert not any(t.get("category") == FLEX_CATEGORY for t in back.iter("table")), path
    assert not any(r.findtext("romid/xmlid") == FLEX_ROM_XMLID for r in back.findall("rom")), path
    n = sum(e - s + 1 for s, e in spans)
    print(f"{path.relative_to(ROOT)}: removed {len(spans)} span(s), {n} line(s)")
    return len(spans)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    check = "--check" in sys.argv
    paths = [Path(a) if Path(a).is_absolute() else ROOT / a for a in args] or DEFAULT_PATHS
    total = sum(strip_file(p, check=check) for p in paths)
    if check:
        print(f"check: {total} span(s) would be removed across {len(paths)} file(s)")
        return 1 if total else 0
    print(f"done: {total} span(s) removed across {len(paths)} file(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
