#!/usr/bin/env python3
"""Clean editor-facing <description> text in the owned RomRaider defs (AGENTS.md rule 6b).

Rule 6b: a <description> is user-facing text — a simplified what-the-table-does
sentence only. It must not carry memory addresses, derivation, pass markers,
evidence/report references, checksum/bench-validation process notes, or generator
assertions ("asserted against ROM bytes by this script"). Provenance lives in the
label map, TSVs and investigation docs, not in the XML the end user reads.

This module removes, from every <table><description>:
  * bracketed provenance blocks (dated pass/analysis/review markers, JSON dumps);
  * sentences containing addresses, descriptor/dispatch details, evidence or report
    references, function/PID/mova names, checksum/rule-10 notes, etc.;
  * DTC "Enable/Disable" tables get a fixed one-line user-facing description
    (the old "[2026-11-01 DTC repair] Address derived from this ROM's own DTC
    layout ..." text was pure provenance);
  * descriptions left empty are removed.

What remains is the plain-language what-it-does text (e.g. "Used to correct the max
primary injector amount based on barometric pressure ..."); tables with no
remaining text and no verified purpose keep none. Already-clean descriptions
(incl. the relabel pass's label-map descriptions) pass through byte-identical, so
relabel.is_relabeled idempotency is unaffected.

Used two ways:
  * imported by extend_defs_all_roms.py — clean_block() runs on every emitted
    per-ROM def at generation time;
  * standalone — clean_file() applies a byte-preserving line splice to the owned
    multi-ROM files (merged 60E15120 def, reviewed copy, upstream snapshot; the
    per-ROM defs are regenerated, so this is a no-op guard on them).

Idempotent. Run from the repo root:

  python utilities/scripts/defs-merge/clean_descriptions.py [--check] [paths ...]
"""

from pathlib import Path
import re
import sys
import xml.etree.ElementTree as E
import xml.parsers.expat as expat

ROOT = Path(__file__).resolve().parents[3]

DEFAULT_PATHS = [
    ROOT / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml",
    ROOT / "data" / "definitions" / "romraider" / "reviewed-rx8defs-copy" / "rx8_defs.xml",
    ROOT / "data" / "definitions" / "romraider" / "upstream-rx8defs" / "rx8_defs.xml",
] + sorted((ROOT / "data" / "definitions" / "romraider" / "per-rom").glob("*.xml"))

DTC_NAME_RE = re.compile(r"^DTC ([0-9A-Fa-f]{4}) Enable/Disable (#\d)")

# bracketed blocks that are provenance: dated markers, JSON dumps, process keywords
BRACKET_RE = re.compile(r"\[[^\]]*\]")
BRACKET_BAD_RE = re.compile(r"20\d\d-\d\d-\d\d|\{|^\s*\[(?:analysis|review|repair|correction|dtc)\b", re.I)

# sentences containing any of these are provenance, not what-the-table-does
BAD_SENTENCE_RE = re.compile(
    r"0x[0-9a-fA-F]+"                          # memory addresses
    r"|\b(?=[0-9a-f]*\d)[0-9a-fA-F]{5,8}\b"     # bare hex ids with a digit (6a354, 0000e910)
    r"|\bdescriptors?\b|\bdispatch\b|\bcorrespondence\b|\bevidence\b|\basserted\b"
    r"|rom address|by this script|\bfun_\b|\bmova\b|\bpid\b|rule 10"
    r"|bench|checksum|\bcvn\b|verified against|referencing function|lookup path"
    r"|\.md\b|\.json\b|\.tsv\b|\breport\b|\bsee \b|g-rom|literal|extract"
    r"|community definition|consult|not independently|address derived"
    r"|code table|enable block|this rom|slot \d|correction:|\bbasis\b"
    r"|storage|axis pointer|raw_|wrapper|20\d\d-\d\d-\d\d"
    r"|upstream rename|prior name|puvar\d*|rpm-indexed|do not infer"
    r"|axis labels? inferred|inferred from",
    re.I)


def dtc_description(code, block):
    """Short user-facing description for a 'DTC xxxx Enable/Disable #N' table."""
    return f"Enable/disable flag for diagnostic trouble code DTC {code} (block {block})."


def clean_description(text, name=""):
    """Return cleaned description text, or None if nothing user-facing remains.

    Idempotent: already-clean text is returned unchanged.
    """
    m = DTC_NAME_RE.match(name or "")
    if m:
        return dtc_description(m.group(1).upper(), m.group(2))
    if not text or not text.strip():
        return None
    t = BRACKET_RE.sub(lambda mo: " " if BRACKET_BAD_RE.search(mo.group(0)) else mo.group(0), text)
    parts = re.split(r"\n+|(?<=[.!?])\s+", t)
    keep = [p.strip() for p in parts if p.strip() and not BAD_SENTENCE_RE.search(p)]
    out = re.sub(r"\s+", " ", " ".join(keep)).strip()
    return out or None


def clean_block(block):
    """ElementTree version: clean every <description> under a <rom> block; returns
    the number of descriptions changed or removed."""
    n = 0
    for t in block.iter("table"):
        d = t.find("description")
        if d is None:
            continue
        cleaned = clean_description(d.text or "", t.get("name") or "")
        if cleaned is None:
            if (d.text or "").strip():
                t.remove(d)
                n += 1
        elif cleaned != d.text:
            d.text = cleaned
            n += 1
    return n


def _escape(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")


def clean_file(path, check=False):
    """Byte-preserving line splice: rewrite only the <description> spans whose
    cleaned text differs (BOM/CRLF and all other bytes untouched). Returns the
    number of description spans changed."""
    raw = path.read_bytes()
    bom = raw.startswith(b"\xef\xbb\xbf")
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = [ln.rstrip("\r") for ln in text.split("\n")]

    edits = []  # (start_line, end_line, replacement_lines or None for delete)
    table_stack = []      # (name, ) of enclosing <table> elements
    desc_start = None
    desc_name = ""
    desc_text = []

    def start_el(name, attrs):
        nonlocal desc_start, desc_name, desc_text
        if name == "table":
            table_stack.append(attrs.get("name") or "")
        elif name == "description" and table_stack:
            desc_start = p.CurrentLineNumber - 1
            desc_name = table_stack[-1]
            desc_text = []

    def end_el(name):
        nonlocal desc_start, desc_text
        if name == "table" and table_stack:
            table_stack.pop()
        elif name == "description" and desc_start is not None:
            end = p.CurrentLineNumber - 1
            original = "".join(desc_text)
            cleaned = clean_description(original, desc_name)
            if cleaned is None:
                if original.strip():
                    edits.append((desc_start, end, None))
            elif cleaned != original:
                indent = re.match(r"\s*", lines[desc_start]).group(0)
                edits.append((desc_start, end, [f"{indent}<description>{_escape(cleaned)}</description>"]))
            desc_start = None

    def char_data(data):
        if desc_start is not None:
            desc_text.append(data)

    p = expat.ParserCreate()
    p.StartElementHandler = start_el
    p.EndElementHandler = end_el
    p.CharacterDataHandler = char_data
    p.Parse("\n".join(lines), True)

    if not edits:
        return 0
    if check:
        print(f"{path.relative_to(ROOT)}: would clean {len(edits)} description(s)")
        return len(edits)

    out = lines[:]
    for s, e, repl in sorted(edits, key=lambda x: x[0], reverse=True):
        out[s:e + 1] = repl if repl is not None else []
    new_text = "\n".join(out)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    path.write_bytes((b"\xef\xbb\xbf" if bom else b"") + new_text.encode("utf-8"))

    # verify the artifact still parses
    E.parse(path)
    print(f"{path.relative_to(ROOT)}: cleaned {len(edits)} description(s)")
    return len(edits)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    check = "--check" in sys.argv
    paths = [Path(a) if Path(a).is_absolute() else ROOT / a for a in args] or DEFAULT_PATHS
    total = sum(clean_file(p, check=check) for p in paths)
    if check:
        print(f"check: {total} description(s) would be cleaned across {len(paths)} file(s)")
        return 1 if total else 0
    print(f"done: {total} description(s) cleaned across {len(paths)} file(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
