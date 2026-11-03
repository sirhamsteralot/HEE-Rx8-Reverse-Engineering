#!/usr/bin/env python3
"""Apply the 2026-11-02 relabel pass to the 60E15120 <rom> block of
data/definitions/romraider/rx8defs-merged-60E15120.xml.

Surgical splice: only the <table> elements that the pass renames or adds are
re-serialized and spliced over their original line spans; every other byte of
the file is left untouched (verified by re-parsing + git diff). The pass itself
lives in relabel.py (shared with extend_defs_all_roms.py for the per-ROM
defs).

Idempotent: entries already carrying the relabel marker keep their
name/category/addresses and only get their description re-normalized to the
short rule-6b form; the pass log (stats JSON) is only rewritten on a fresh
renaming run.

Run from the repo root:
  python utilities/scripts/defs-merge/relabel_merged_def.py [--dry-run]
Writes the stats JSON to
docs/investigations/60E15120_N3J1E/defs-merge/relabel_2026-11-02.json
"""
from pathlib import Path
import json, sys
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import relabel

MERGED = ROOT / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
STATS_OUT = ROOT / "docs" / "investigations" / "60E15120_N3J1E" / "defs-merge" / "relabel_2026-11-02.json"
TARGET_XMLID = "60E15120"


def find_block_lines(lines):
    """Locate the <rom> block whose first romid xmlid is TARGET_XMLID.
    Returns (start, end) line indexes inclusive, where lines[start] is the
    '<rom ...>' line and lines[end] is its '</rom>' line."""
    for i, ln in enumerate(lines):
        if "<rom " in ln or ln.strip().startswith("<rom>"):
            # look ahead a few lines for the xmlid
            for j in range(i + 1, min(i + 12, len(lines))):
                if f"<xmlid>{TARGET_XMLID}</xmlid>" in lines[j]:
                    # find the first closing </rom> (indent varies in this file)
                    for k in range(j, len(lines)):
                        if lines[k].strip() == "</rom>":
                            return i, k
                    raise SystemExit(f"no </rom> found after line {i}")
    raise SystemExit(f"rom block {TARGET_XMLID} not found")


def table_spans(lines, start, end):
    """Spans (start_line, end_line) of the top-level <table> elements of the
    block, in document order, via expat (accurate line numbers; comments and
    attribute contents are not miscounted). Lines are 0-indexed."""
    import xml.parsers.expat as expat
    frag_text = "\n".join(lines[start:end + 1])
    spans = []
    depth = 0
    span_start = None

    def start_el(name, attrs):
        nonlocal depth, span_start
        if name == "table":
            if depth == 0:
                span_start = p.CurrentLineNumber - 1 + start  # absolute 0-indexed line
            depth += 1

    def end_el(name):
        nonlocal depth, span_start
        if name == "table":
            depth -= 1
            if depth == 0 and span_start is not None:
                spans.append((span_start, p.CurrentLineNumber - 1 + start))
                span_start = None

    p = expat.ParserCreate()
    p.StartElementHandler = start_el
    p.EndElementHandler = end_el
    p.Parse(frag_text, True)
    return spans


def serialize(el, indent="    "):
    el = copy_el(el)
    E.indent(el, space=indent)
    el.tail = None
    txt = E.tostring(el, encoding="unicode")
    lines = txt.split("\n")
    return "\n".join(indent + ln if ln.strip() else ln for ln in lines)


def copy_el(el):
    import copy
    return copy.deepcopy(el)


def main():
    dry = "--dry-run" in sys.argv
    raw = MERGED.read_bytes()
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = text.split("\n")
    # normalize away possible \r for processing, restore on write
    lines = [ln.rstrip("\r") for ln in lines]

    start, end = find_block_lines(lines)
    frag_text = "\n".join(lines[start:end + 1])
    frag = E.fromstring("<root>" + frag_text + "</root>")
    block = frag[0]
    assert block.findtext("romid/xmlid") == TARGET_XMLID

    # blks for template lookup: parse whole file
    whole = E.parse(MERGED).getroot()
    blks = {x.findtext("romid/xmlid").lower(): x for x in whole.findall("rom")}

    old_els = block.findall("table")
    spans = table_spans(lines, start, end)
    assert len(spans) == len(old_els), (len(spans), len(old_els))

    stats = relabel.apply_to_block(block, blks, relabel.REFERENCE)
    new_els = block.findall("table")
    n_old = len(old_els)
    assert len(new_els) >= n_old

    # splice replacements (same index) and additions (append before </rom>)
    edits = []  # (start_line, end_line, new_text or None-for-insert)
    for i in range(n_old):
        if new_els[i] is not old_els[i]:
            s, e = spans[i]
            edits.append((s, e, serialize(new_els[i])))
    added_text = ""
    for el in new_els[n_old:]:
        added_text += serialize(el) + "\n"
    if added_text:
        edits.append((end, end, None, added_text))  # insert before </rom> line

    if dry:
        print(f"dry run: would replace {sum(1 for e in edits if len(e) == 3)} tables, "
              f"add {len(new_els) - n_old}; stats: renamed={stats['renamed']} added={stats['added']} "
              f"regrouped={stats['regrouped']} skipped_marker={stats['skipped_marker']} no_label={stats['no_label']}")
        return

    # apply edits bottom-up
    out_lines = lines[:]
    for e in sorted(edits, key=lambda x: x[0], reverse=True):
        if len(e) == 4:
            s, _, _, ins = e
            out_lines[s:s] = [ins.rstrip("\n")]
        else:
            s, e2, txt = e
            out_lines[s:e2 + 1] = txt.split("\n")

    new_text = "\n".join(out_lines)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    MERGED.write_bytes(b"\xef\xbb\xbf" + new_text.encode("utf-8"))

    # verify: re-parse, check invariants
    back = E.parse(MERGED).getroot()
    blk = None
    for r in back.findall("rom"):
        if r.findtext("romid/xmlid") == TARGET_XMLID:
            blk = r
    names = [t.get("name") for t in blk.findall("table")]
    assert len(names) == len(set(names)), "duplicate names after relabel"
    n_marker = sum(1 for t in blk.findall("table") if relabel.MARKER in (t.findtext("description") or ""))
    print(f"OK: block tables {len(old_els)} -> {len(names)}; renamed={stats['renamed']} "
          f"added={stats['added']} regrouped={stats['regrouped']} marker_entries={n_marker}")
    if stats["renamed"] or stats["added"]:
        # fresh pass: (re)write the pass log. On a normalization-only re-run
        # (everything already marked) the original stats file is kept.
        STATS_OUT.write_text(json.dumps({
            "file": str(MERGED.relative_to(ROOT)), "rom_block": TARGET_XMLID,
            "marker": relabel.MARKER, "stats": {k: v for k, v in stats.items() if k != "details"},
            "details": stats["details"],
        }, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
        print(f"stats -> {STATS_OUT.relative_to(ROOT)}")
    else:
        print(f"normalization-only run (skipped_marker={stats['skipped_marker']}); "
              f"stats file left untouched: {STATS_OUT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
