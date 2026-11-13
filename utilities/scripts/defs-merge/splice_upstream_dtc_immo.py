#!/usr/bin/env python3
"""Splice the upstream RX8Defs DTC switch rework (`d95b0be`) and the 60E15120
immobilizer patch-address fix (`39d98a0`) into the reviewed merged def
(data/definitions/romraider/rx8defs-merged-60E15120.xml), keeping the local
P-code DTC names applied by relabel_dtc_names.py.

Decision (splice, not rebase): the merged def's RX8Base is the reviewed
ff5ab4f/944062e content (renamed tables, cleaned descriptions, flex-fuel
stripped); a whole-block rebase onto `39d98a0` would drag in unrelated
renames/category moves that are tracked separately. So only the two upstream
changes that are ROM-proven wrong/stale in our file are spliced:

  1. DTC enable/disable tables in every active <rom> block that are still in
     the old form (category="DTCs", type="1D"): #1 -> category
     "DTC - MIL Illuminate", type="Switch" with states Enabled=01 /
     Disabled=00; #2 -> "DTC - OBD Report" same; #3 -> category
     "DTC - Unknown", stays 1D. Matches the ROM-verified banks on
     60E15120_N3J1E (0x7e678 MIL + aging, 0x7e704 Mode 03 list / freeze frame,
     0x7e790 feature bitmask — dtc_control_report.md). Table names, storage
     addresses and descriptions are kept; block-level overrides that carry
     only name+storageaddress stay bare and inherit the new form from RX8Base
     (RomRaider name-based inheritance), exactly like upstream.
  2. The 60E15120 block's two "Immobilizer Disable" tables are replaced by the
     pinned upstream (`submodules/RX8Defs` @ 39d98a0) elements: storageaddress
     0x34da8 -> 0x34b10 and 0x351f4 -> 0x34f5c, plus the regenerated patch
     blob. Binary-level verification (AGENTS.md rule 7) runs inside this
     script: the immo start pattern B56E000960D0600C88008D1100098801 must sit
     at the new storageaddress in 60E15120_N3J1E.bin, the switch's "off"
     state must equal the ROM bytes there, and the with-RKE site must be
     offset+0x44c with the original "33 20" bytes.

Surgical splice like relabel_dtc_names.py: only changed <table> elements are
re-serialized over their original line spans (expat line numbers); every other
byte of the file is untouched. Commented-out blocks are not seen by expat and
stay untouched. Idempotent: tables already in the new form and the corrected
immo addresses are left as-is; re-run = no-op (stats JSON only rewritten on a
fresh run).

Run from the repo root:
  python utilities/scripts/defs-merge/splice_upstream_dtc_immo.py [--dry-run]
Writes stats to
docs/investigations/60E15120_N3J1E/defs-merge/upstream_splice_39d98a0.json
"""
from pathlib import Path
import copy
import json
import sys
import xml.etree.ElementTree as E
import xml.parsers.expat as expat

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import dtc_names  # noqa: E402
import relabel  # noqa: E402  (rom_files() inventory)

MERGED = ROOT / "data" / "definitions" / "romraider" / "rx8defs-merged-60E15120.xml"
UPSTREAM_RR = ROOT / "submodules" / "RX8Defs" / "RomRaider" / "rx8_defs.xml"
STATS_OUT = ROOT / "docs" / "investigations" / "60E15120_N3J1E" / "defs-merge" / "upstream_splice_39d98a0.json"
TARGET_XMLID = "60E15120"

# upstream d95b0be form per enable/disable suffix
DTC_NEW_FORM = {
    "#1": {"category": "DTC - MIL Illuminate", "type": "Switch"},
    "#2": {"category": "DTC - OBD Report", "type": "Switch"},
    "#3": {"category": "DTC - Unknown", "type": "1D"},
}
SWITCH_STATES = (("Enabled", "01"), ("Disabled", "00"))

# immo start pattern used by upstream G_ROM_ImmoDefWriter.py; the def
# storageaddress is the pattern offset, with-RKE = offset + 0x44c
# (upstream-sync-validation.md section 3)
IMMO_PATTERN = bytes.fromhex("B56E000960D0600C88008D1100098801")
IMMO_RKE_DELTA = 0x44C
IMMO_RKE_ORIG = bytes.fromhex("3320")  # "off" bytes of the With-RKE switch


def table_spans(text):
    """(start_line, end_line, attrs, rom_fw) of every <table> element in
    `text` via expat; rom_fw is the <internalidstring> (firmware id, e.g.
    "60E15120") of the innermost enclosing <rom> (None outside any <rom> —
    commented-out blocks never reach expat). The block's <xmlid> is a cal
    string (N3J1E), not the fw id, so internalidstring is the reliable key."""
    spans = []
    depth = 0
    cur = None
    rom_stack = []
    rom_fw = {}
    fw_buf = []

    def start_el(name, attrs):
        nonlocal depth, cur
        if name == "rom":
            rom_stack.append(p.CurrentLineNumber - 1)
        elif name == "internalidstring" and rom_stack:
            fw_buf.append("")
        if name == "table":
            if depth == 0:
                key = rom_stack[-1] if rom_stack else None
                cur = (p.CurrentLineNumber - 1, dict(attrs),
                       rom_fw.get(key) if key is not None else None)
            depth += 1

    def char_data(data):
        if fw_buf:
            fw_buf[-1] += data

    def end_el(name):
        nonlocal depth, cur
        if name == "internalidstring" and fw_buf:
            if rom_stack:
                # blocks carry two <romid>s (fw id first, cal string second);
                # keep the first — the firmware id at internalidaddress 0x2000
                rom_fw.setdefault(rom_stack[-1], fw_buf[-1].strip())
            fw_buf.pop()
        elif name == "table":
            depth -= 1
            if depth == 0 and cur is not None:
                spans.append((cur[0], p.CurrentLineNumber - 1, cur[1], cur[2]))
                cur = None
        elif name == "rom" and rom_stack:
            rom_stack.pop()

    p = expat.ParserCreate()
    p.StartElementHandler = start_el
    p.CharacterDataHandler = char_data
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


def upstream_immo_elements():
    """The pinned upstream 60E15120 block's two Immobilizer tables, after
    binary-level verification against the 60E15120 ROM (rule 7)."""
    rom_path = relabel.rom_files().get("60E15120_N3J1E")
    assert rom_path is not None, "60E15120_N3J1E ROM not found in the inventory"
    rom = rom_path.read_bytes()
    up = E.parse(UPSTREAM_RR).getroot()
    blk = None
    for r in up.findall("rom"):
        if r.findtext("romid/xmlid") == TARGET_XMLID:
            blk = r
    assert blk is not None, "no 60E15120 block in pinned upstream defs"
    out = {}
    for t in blk.findall("table"):
        if "Immobilizer Disable" in (t.get("name") or ""):
            out[t.get("name")] = copy.deepcopy(t)
    assert len(out) == 2, out.keys()
    no_rke = out["Immobilizer Disable - Without RKE Installed"]
    with_rke = out["Immobilizer Disable - With RKE Installed"]
    sa = int(no_rke.get("storageaddress"), 16)
    # rule 7: the pattern must sit exactly at the def's storageaddress
    hits = []
    i = rom.find(IMMO_PATTERN, 0x2000)
    while i >= 0:
        hits.append(i)
        i = rom.find(IMMO_PATTERN, i + 1)
    assert hits == [sa], f"immo pattern at {[hex(h) for h in hits]}, def says {sa:#x}"
    # the switch "off" state must equal the ROM bytes at that address
    off = next((s for s in no_rke.findall("state") if s.get("name") == "off"), None)
    assert off is not None, "upstream Without-RKE switch has no off state"
    off_bytes = bytes(int(x, 16) for x in off.get("data").split())
    assert rom[sa:sa + len(off_bytes)] == off_bytes, "off state != ROM bytes at storageaddress"
    # with-RKE site: offset + 0x44c, original "33 20" bytes there
    sa_rke = int(with_rke.get("storageaddress"), 16)
    assert sa_rke == sa + IMMO_RKE_DELTA, (hex(sa_rke), hex(sa))
    assert rom[sa_rke:sa_rke + 2] == IMMO_RKE_ORIG, \
        f"ROM at with-RKE site {sa_rke:#x} is {rom[sa_rke:sa_rke+2].hex()}, expected 3320"
    return out, {"rom": rom_path.relative_to(ROOT).as_posix(), "pattern_offset": f"0x{sa:X}",
                 "with_rke_offset": f"0x{sa_rke:X}", "off_state_matches_rom_bytes": True}


def _ws_normalized(el):
    """Deep copy with whitespace-only text/tails stripped, for comparison."""
    el = copy.deepcopy(el)
    for x in el.iter():
        if x.text is not None and not x.text.strip():
            x.text = None
        if x.tail is not None and not x.tail.strip():
            x.tail = None
    return el


def convert_dtc_table(frag, suffix):
    """Convert one old-form DTC table element to the upstream new form.
    Returns True if the element changed."""
    new = DTC_NEW_FORM[suffix]
    if frag.get("category") == new["category"] and frag.get("type") == new["type"]:
        return False  # already spliced (idempotent)
    assert frag.get("category") in (None, "DTCs"), frag.get("category")
    assert frag.get("type") in (None, "1D"), frag.get("type")
    frag.set("category", new["category"])
    frag.set("type", new["type"])
    if new["type"] == "Switch":
        for a in ("endian", "expression", "to_byte", "size"):
            frag.attrib.pop(a, None)
        frag.set("storagetype", "uint8")
        for s in list(frag.findall("state")):
            frag.remove(s)
        # states after the description (upstream order: description, states)
        d = frag.find("description")
        idx = list(frag).index(d) + 1 if d is not None else 0
        for name, data in SWITCH_STATES:
            st = E.Element("state", {"name": name, "data": data})
            frag.insert(idx, st)
            idx += 1
    return True


def main():
    dry = "--dry-run" in sys.argv
    raw = MERGED.read_bytes()
    bom = raw.startswith(b"\xef\xbb\xbf")
    nl = b"\r\n" if b"\r\n" in raw else b"\n"
    text = raw.decode("utf-8-sig")
    lines = [ln.rstrip("\r") for ln in text.split("\n")]
    frag_text = "\n".join(lines)

    up_immo, immo_evidence = upstream_immo_elements()

    spans = table_spans(frag_text)
    edits = []
    stats = {"dtc_converted": {"#1": 0, "#2": 0, "#3": 0}, "immo_replaced": 0,
             "details": [], "immo_evidence": immo_evidence}
    names_before, addr_before = [], []
    for s, e, attrs, rom_fw in spans:
        name = attrs.get("name") or ""
        parsed = dtc_names.parse_dtc_name(name)
        if parsed is not None:
            names_before.append(name)
            addr_before.append(attrs.get("storageaddress"))
            # only entries that explicitly carry the old form (category/type
            # attributes) are converted; bare name+storageaddress overrides
            # stay bare and inherit the new form from RX8Base, like upstream
            if attrs.get("category") == "DTCs" or attrs.get("type") == "1D":
                frag = E.fromstring("<root>" + "\n".join(lines[s:e + 1]) + "</root>")[0]
                if convert_dtc_table(frag, parsed[1]):
                    stats["dtc_converted"][parsed[1]] += 1
                    edits.append((s, e, serialize(frag)))
                    stats["details"].append({"block": rom_fw, "name": name,
                                             "category": frag.get("category"), "type": frag.get("type")})
        elif rom_fw == TARGET_XMLID and "Immobilizer Disable" in name:
            up = up_immo.get(name)
            assert up is not None, f"upstream 60E15120 block missing {name!r}"
            frag = E.fromstring("<root>" + "\n".join(lines[s:e + 1]) + "</root>")[0]
            if frag.get("storageaddress") == up.get("storageaddress") and \
                    E.tostring(_ws_normalized(frag)) == E.tostring(_ws_normalized(up)):
                continue  # already spliced
            new_el = copy.deepcopy(up)
            edits.append((s, e, serialize(new_el)))
            stats["immo_replaced"] += 1
            stats["details"].append({"block": rom_fw, "name": name,
                                     "storageaddress": f"{frag.get('storageaddress')} -> {up.get('storageaddress')}"})

    if dry:
        print(f"dry run: would convert {stats['dtc_converted']} DTC tables, "
              f"replace {stats['immo_replaced']} immobilizer tables")
        return

    out_lines = lines[:]
    for s, e, txt in sorted(edits, key=lambda x: x[0], reverse=True):
        out_lines[s:e + 1] = txt.split("\n")
    new_text = "\n".join(out_lines)
    if nl == b"\r\n":
        new_text = new_text.replace("\n", "\r\n")
    MERGED.write_bytes((b"\xef\xbb\xbf" if bom else b"") + new_text.encode("utf-8"))

    # verify: re-parse; every DTC table in an active block is in the new form,
    # names/addresses unchanged except the two immo addresses, no new dups
    back = E.parse(MERGED).getroot()
    names_after, addr_after = [], []
    for rom in back.findall("rom"):
        xid = rom.findtext("romid/xmlid")
        for t in rom.findall("table"):
            n = t.get("name") or ""
            parsed = dtc_names.parse_dtc_name(n)
            if parsed is not None:
                names_after.append(n)
                addr_after.append(t.get("storageaddress"))
                new = DTC_NEW_FORM[parsed[1]]
                if t.get("category") is None and t.get("type") is None:
                    continue  # bare name+storageaddress override: inherits the new form
                assert t.get("category") == new["category"] and t.get("type") == new["type"], \
                    f"DTC table not in new form: {xid} {n} {t.get('category')} {t.get('type')}"
                if new["type"] == "Switch":
                    states = [(s.get("name"), s.get("data")) for s in t.findall("state")]
                    assert states == list(SWITCH_STATES), f"{n}: states {states}"
    assert names_after == names_before, "DTC names changed"
    # DTC storage addresses untouched; only the two immo addresses may differ
    assert sorted(a for a in addr_before if a) == sorted(a for a in addr_after if a), \
        "DTC storageaddress multiset changed"
    before_root = E.fromstring(text)
    for rom_b, rom_a in zip(before_root.findall("rom"), back.findall("rom")):
        xid = rom_a.findtext("romid/xmlid")
        dup_b = len([t.get("name") for t in rom_b.findall("table")]) - \
            len({t.get("name") for t in rom_b.findall("table")})
        dup_a = len([t.get("name") for t in rom_a.findall("table")]) - \
            len({t.get("name") for t in rom_a.findall("table")})
        assert dup_a <= dup_b, f"block {xid}: duplicate names grew {dup_b} -> {dup_a}"
    # immo addresses now ROM-verified values
    for rom in back.findall("rom"):
        if rom.findtext("romid/xmlid") == TARGET_XMLID:
            immo = {t.get("name"): t.get("storageaddress") for t in rom.findall("table")
                    if "Immobilizer Disable" in (t.get("name") or "")}
            assert int(immo["Immobilizer Disable - Without RKE Installed"], 16) == \
                int(immo_evidence["pattern_offset"], 16)
            assert int(immo["Immobilizer Disable - With RKE Installed"], 16) == \
                int(immo_evidence["with_rke_offset"], 16)

    stats.update({"file": str(MERGED.relative_to(ROOT)), "pass": __doc__.splitlines()[0],
                  "bom": bom, "crlf": nl == b"\r\n"})
    if edits:
        STATS_OUT.write_text(json.dumps(stats, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
        print(f"OK: converted {stats['dtc_converted']} DTC tables, replaced {stats['immo_replaced']} "
              f"immobilizer tables; stats -> {STATS_OUT.relative_to(ROOT)}")
    else:
        print(f"normalization-only run (nothing to change); stats file left untouched: {STATS_OUT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
