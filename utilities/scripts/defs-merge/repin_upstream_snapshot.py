#!/usr/bin/env python3
"""Re-pin the local upstream snapshot to the pinned RX8Defs submodule commit.

  data/definitions/romraider/upstream-rx8defs/rx8_defs.xml

is a *locally modified* copy of the pinned submodule file
(submodules/RX8Defs @ the gitlink commit): the blob is copied verbatim, then
the stock-only modification is re-applied (the one-time G-ROM_FLEX flex-fuel
strip, data/definitions/README.md "Stock-only defs" — 'Flex Fuel' category
tables, comments wrapping them, and the whole G-ROM_FLEX <rom> block, removed
by byte-preserving line splices so every other byte stays identical to the
upstream blob). The d95b0be/39d98a0 DTC-switch + immobilizer + category-rename
splice is *not* re-applied here: the new pin is a descendant of those commits,
so its blob already carries them; splice_upstream_dtc_immo.py is run
afterwards as a verifier (no-op expected) and writes the per-pin pass record
(upstream_splice_<pin>.json).

The previous snapshot blob stays retrievable via git history (rule 4b archive);
provenance_hashes.json's "RX8Defs/RomRaider/rx8_defs.xml" entry is updated to
the SHA-256 of the pinned upstream blob at the new commit.

Idempotent: re-running on an already re-pinned tree rewrites identical bytes and
leaves provenance_hashes.json unchanged.

Run from the repo root:
  python utilities/scripts/defs-merge/repin_upstream_snapshot.py [--check]
"""

from pathlib import Path
import hashlib
import json
import subprocess
import sys
import xml.etree.ElementTree as E
import xml.parsers.expat as expat

ROOT = Path(__file__).resolve().parents[3]
SUB = ROOT / "submodules" / "RX8Defs"
SNAPSHOT = ROOT / "data" / "definitions" / "romraider" / "upstream-rx8defs" / "rx8_defs.xml"
PROVENANCE = ROOT / "data" / "labels" / "60E15120_N3J1E" / "provenance_hashes.json"
UPSTREAM_REL = "RomRaider/rx8_defs.xml"
PROV_KEY = "RX8Defs/RomRaider/rx8_defs.xml"

FLEX_CATEGORY = "Flex Fuel"
FLEX_ROM_XMLID = "G-ROM_FLEX"


def git(repo, *args):
    return subprocess.check_output(["git", "-C", str(repo), *args]).decode("utf-8-sig").strip()


def pinned_commit():
    """Submodule HEAD must equal the gitlink committed in this branch, so the
    snapshot always matches the pin CI and tests see."""
    head = git(SUB, "rev-parse", "HEAD")
    gitlink = git(ROOT, "ls-tree", "HEAD", "submodules/RX8Defs").split()[2]
    assert head == gitlink, f"submodule HEAD {head} != gitlink {gitlink} — check out the pinned commit first"
    return head


def blob(pin):
    return subprocess.check_output(["git", "-C", str(SUB), "show", f"{pin}:{UPSTREAM_REL}"])


def flex_spans(lines):
    """Line spans (0-indexed, inclusive) to delete: top-level 'Flex Fuel'
    tables, comments wrapping a flex table, and the G-ROM_FLEX <rom> block."""
    text = "\n".join(lines)
    spans = []
    rom_stack = []
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
                table_start, table_attrs = line, dict(attrs)
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
                rom_stack[-1][1] = xmlid_buf.strip()
            xmlid_buf = None

    def char_data(data):
        nonlocal xmlid_buf
        if xmlid_buf is not None:
            xmlid_buf += data

    def comment(data):
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

    spans.sort()
    merged = []
    for s, e in spans:
        if merged and s <= merged[-1][1] + 1:
            merged[-1][1] = max(merged[-1][1], e)
        else:
            merged.append([s, e])
    return [tuple(m) for m in merged]


def strip_flex(raw):
    """raw snapshot bytes -> (stripped bytes, n_spans). Byte-preserving:
    BOM / line endings / all other bytes untouched."""
    bom = raw.startswith(b"\xef\xbb\xbf")
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = [ln.rstrip("\r") for ln in text.split("\n")]
    spans = flex_spans(lines)
    if not spans:
        return raw, 0
    out = lines[:]
    for s, e in sorted(spans, reverse=True):
        del out[s:e + 1]
    new_text = "\n".join(out)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    return (b"\xef\xbb\xbf" if bom else b"") + new_text.encode("utf-8"), len(spans)


def main():
    check = "--check" in sys.argv[1:]
    pin = pinned_commit()
    raw = blob(pin)
    stripped, n_spans = strip_flex(raw)

    # verify the artifact we are about to write: parses, no flex content left
    back = E.fromstring(stripped.decode("utf-8-sig"))
    assert not any(t.get("category") == FLEX_CATEGORY for t in back.iter("table"))
    assert not any(r.findtext("romid/xmlid") == FLEX_ROM_XMLID for r in back.findall("rom"))

    digest = hashlib.sha256(raw).hexdigest()
    print(f"pin {pin}: blob sha256 {digest}, flex strip {n_spans} span(s)")

    if check:
        current = SNAPSHOT.read_bytes()
        print(f"check: snapshot {'already re-pinned' if current == stripped else 'WOULD be rewritten'}")
        return 0 if current == stripped else 1

    if SNAPSHOT.read_bytes() != stripped:
        SNAPSHOT.write_bytes(stripped)
        print(f"wrote {SNAPSHOT.relative_to(ROOT)} ({len(stripped)} bytes)")
    else:
        print(f"snapshot already at pin {pin[:8]} — unchanged")

    prov = json.loads(PROVENANCE.read_text(encoding="utf-8"))
    if prov.get(PROV_KEY) != digest:
        prov[PROV_KEY] = digest
        PROVENANCE.write_text(json.dumps(prov, indent=2) + "\n", encoding="utf-8")
        print(f"provenance_hashes.json: {PROV_KEY} -> {digest}")
    else:
        print("provenance_hashes.json already up to date")
    return 0


if __name__ == "__main__":
    sys.exit(main())
