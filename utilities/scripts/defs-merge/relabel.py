#!/usr/bin/env python3
"""Shared library for the defs relabel pass (2026-11-02).

Applies the curated table labels (data/labels/60E15120_N3J1E/defs_table_labels.json,
built by build_table_labels.py) to a RomRaider <rom> block:

  * tables whose lookup descriptor has a label get the new editor name, the
    subsystem category (the RomRaider grouping), and a dated <description>
    addendum carrying the evidence + source report; the prior name is kept in
    the description for provenance. Renamed entries are made self-contained
    (type/scaling/axes copied from the base-chain template of the same old
    name) so RomRaider's name-based inheritance keeps working.
  * extracted tables (data/maps/<rom>/index.tsv) that are missing from the
    block are ADDED as self-contained entries (geometry + scaling from the
    ROM descriptor bytes), labeled when the reference ROM has a label.

Cross-ROM: for non-reference ROMs the reference descriptor is mapped to the
ROM's own descriptor by the same structural key diff_maps.py uses
(dimension, counts, type_code, axis values) over data/maps/<rom>/tables/*.json;
the applied description records that provenance (label ladder: structural
match, not byte equality of cells).

Nothing here changes a storageaddress, axis address, scaling or ROM byte; only
names/categories/descriptions, plus whole-table additions for previously
unmapped descriptors.

Used by relabel_merged_def.py (surgical splice into rx8defs-merged-60E15120.xml)
and by extend_defs_all_roms.py (per-ROM def overlay at generation time).
"""
from pathlib import Path
import copy, csv, json, re
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
LABELS_JSON = ROOT / "data" / "labels" / "60E15120_N3J1E" / "defs_table_labels.json"
MAPS = ROOT / "data" / "maps"
REFERENCE = "60E15120_N3J1E"
MARKER = "RE relabel 2026-11-02"

DESC_RE = re.compile(r"Lookup descriptor 0x([0-9a-fA-F]+)")
STORAGETYPE = {0: "float", 4: "uint8", 8: "uint16", 12: "int8", 16: "int16"}
TYPE_SIZES = {0: 4, 4: 1, 8: 2, 12: 1, 16: 2}

# ROM inventory: stem -> path (own dumps + stock ROMs), identified by fw id
_ROM_FILES = None


def rom_files():
    global _ROM_FILES
    if _ROM_FILES is None:
        _ROM_FILES = {}
        for base in (ROOT / "binaries" / "dumps", ROOT / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"):
            if not base.is_dir():
                continue
            for p in sorted(base.glob("*.bin")):
                _ROM_FILES[p.stem] = p
    return _ROM_FILES


def rom_bytes(rom_id):
    return rom_files()[rom_id].read_bytes()


def load_labels():
    d = json.loads(LABELS_JSON.read_text(encoding="utf-8"))
    return {int(k, 16): v for k, v in d["entries"].items()}


def maps_index(rom_id):
    """descriptor int -> row; also data_addr int -> row."""
    by_desc, by_data = {}, {}
    with open(MAPS / rom_id / "index.tsv", newline="", encoding="utf-8") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            row["descriptor_i"] = int(row["descriptor"], 16)
            row["data_i"] = int(row["data_addr"], 16)
            by_desc[row["descriptor_i"]] = row
            by_data[row["data_i"]] = row
    return by_desc, by_data


def table_json(rom_id, name):
    return json.loads((MAPS / rom_id / "tables" / f"{name}.json").read_text(encoding="utf-8"))


def _table_key(t):
    """Same structural key as utilities/scripts/diff_maps.py."""
    ax = tuple(t.get("axis_x_values") or [])
    ay = tuple(t.get("axis_y_values") or [])
    axs = tuple(t.get("axis_values") or [])
    return (t["dimension"], tuple(t.get("counts") or [t.get("nx"), t.get("ny")]),
            t["type_code"], ax or axs, ay)


_SM_CACHE = None


def structural_matches():
    """{rom_id: {rom_descriptor: ref_descriptor}} for all ROMs under data/maps.

    Match by structural key (dim, counts, type, axes); when several reference
    descriptors share a key (e.g. the three max-injection-angle tables), require
    data_values equality and assign injectively (each ref descriptor used at
    most once); ambiguous leftovers stay unmapped rather than mislabeled.
    """
    global _SM_CACHE
    if _SM_CACHE is not None:
        return _SM_CACHE
    ref_idx, _ = maps_index(REFERENCE)
    ref_keys = {}
    ref_data = {}
    for desc, row in ref_idx.items():
        t = table_json(REFERENCE, row["name"])
        ref_keys.setdefault(_table_key(t), []).append(desc)
        ref_data[desc] = t.get("data_values")
    out = {}
    for d in sorted(MAPS.iterdir()):
        if not d.is_dir() or d.name == REFERENCE or not (d / "index.tsv").exists():
            continue
        rom_id = d.name
        idx, _ = maps_index(rom_id)
        m = {}
        used_ref = set()
        for desc, row in sorted(idx.items()):
            t = table_json(rom_id, row["name"])
            cands = [r for r in ref_keys.get(_table_key(t), [])
                     if r not in used_ref and ref_data[r] == t.get("data_values")]
            if len(cands) == 1:
                m[desc] = cands[0]
                used_ref.add(cands[0])
            elif len(cands) == 0:
                # unique key with differing cells: still the same table structurally
                k = _table_key(t)
                if k in ref_keys and len(ref_keys[k]) == 1:
                    m[desc] = ref_keys[k][0]
                    used_ref.add(ref_keys[k][0])
        out[rom_id] = m
    _SM_CACHE = out
    return out


def _desc_of(table_el):
    d = table_el.findtext("description") or ""
    m = DESC_RE.search(d)
    if m:
        return int(m.group(1), 16)
    sa = table_el.get("storageaddress")
    return None


def find_template(old_name, block, blks):
    """Base-chain table with this name (RomRaider resolves overrides by name,
    child first). Returns a deep copy or None."""
    cur, seen = block, set()
    while cur is not None:
        key = (cur.findtext("romid/xmlid") or "").lower()
        for t in cur.findall("table"):
            if t.get("name") == old_name and t.get("type") in ("2D", "3D", "1D"):
                return copy.deepcopy(t)
        base = cur.get("base")
        cur = blks.get(base.lower()) if base else None
        if cur is not None and (cur.findtext("romid/xmlid") or "").lower() in seen:
            break
        if cur is not None:
            seen.add((cur.findtext("romid/xmlid") or "").lower())
    return None


def _fmt_addr(a):
    return f"0x{a:X}"


def _axis_addrs(row):
    ax = row.get("axis_x_addr") or ""
    ay = row.get("axis_y_addr") or ""
    a = row.get("axis_addr") or ""
    return (int(ax, 16) if ax else None, int(ay, 16) if ay else None, int(a, 16) if a else None)


def _set_axes(el, row):
    ax, ay, a = _axis_addrs(row)
    for child in el.findall("table"):
        typ = child.get("type")
        if typ == "X Axis" and ax is not None:
            child.set("storageaddress", _fmt_addr(ax))
        elif typ == "Y Axis":
            child.set("storageaddress", _fmt_addr(ay if ay is not None else (a or 0)))


def _append_desc(el, text):
    d = el.find("description")
    if d is None:
        d = E.SubElement(el, "description")
    d.text = (d.text or "") + "\n" + text if d.text else text


def _label_desc(label, desc, old_name, rom_id, rom_desc):
    # Concise editor-facing description (AGENTS.md rule 6b): no source/evidence
    # dumps here — provenance lives in defs_table_labels.json + the
    # investigation doc. Keep: marker, semantics note, descriptor address,
    # prior name.
    prov = (f"descriptor 0x{desc:x}" if rom_id == REFERENCE else
            f"structural match to {REFERENCE} descriptor 0x{desc:x}; this ROM descriptor 0x{rom_desc:x}")
    parts = [f"[{MARKER}]", label.get("note", "").strip() or label["name"], prov]
    if old_name:
        parts.append(f"prior name '{old_name}'")
    return " ".join(p for p in parts if p)


def _scaling_from_rom(rom, row):
    """<scaling> element from the descriptor bytes (scaled mult/off) or raw."""
    desc = row["descriptor_i"]
    dim = int(row["dimension"])
    t = table_json(row["_rom"], row["name"])
    typ = t["type_code"]
    if typ == 0:
        return E.Element("scaling", {"expression": "x", "to_byte": "x", "format": "0.00"})
    if t.get("scaled"):
        off = 12 if dim == 2 else 20
        mult, add = __import__("struct").unpack_from(">ff", rom, desc + off)
        return E.Element("scaling", {
            "expression": f"(x * {mult!r}) + {add!r}",
            "to_byte": f"(x - {add!r}) / {mult!r}", "format": "0.00"})
    return E.Element("scaling", {"expression": "x", "to_byte": "x"})


def _self_contained(row, rom, name, category, desc_text):
    """Build a full 2D/3D <table> element from a maps index row + ROM bytes."""
    t = table_json(row["_rom"], row["name"])
    dim = int(row["dimension"])
    typ = t["type_code"]
    el = E.Element("table", {
        "name": name, "category": category,
        "type": f"{dim}D", "storagetype": STORAGETYPE[typ], "endian": "big",
    })
    if dim == 2:
        el.set("sizey", str(t.get("nx") or t.get("counts", [0])[0]))
    else:
        el.set("sizex", str(t["nx"])); el.set("sizey", str(t["ny"]))
    el.set("storageaddress", _fmt_addr(row["data_i"]))
    el.append(_scaling_from_rom(rom, row))
    ax, ay, a = _axis_addrs(row)
    if dim == 3 and ax is not None:
        xa = E.SubElement(el, "table", {"name": "Unknown", "type": "X Axis", "storagetype": "float",
                                         "endian": "big", "storageaddress": _fmt_addr(ax)})
        E.SubElement(xa, "scaling", {"expression": "x", "to_byte": "x"})
    if ay is not None:
        ya = E.SubElement(el, "table", {"name": "Unknown", "type": "Y Axis", "storagetype": "float",
                                         "endian": "big", "storageaddress": _fmt_addr(ay)})
        E.SubElement(ya, "scaling", {"expression": "x", "to_byte": "x"})
    elif a is not None:
        ya = E.SubElement(el, "table", {"name": "Unknown", "type": "Y Axis", "storagetype": "float",
                                         "endian": "big", "storageaddress": _fmt_addr(a)})
        E.SubElement(ya, "scaling", {"expression": "x", "to_byte": "x"})
    d = E.SubElement(el, "description")
    d.text = desc_text
    return el


def _unique_name(base, desc, existing):
    name = base
    if name in existing:
        name = f"{base} [0x{desc:x}]"
    n = 2
    while name in existing:
        name = f"{base} [0x{desc:x}] #{n}"
        n += 1
    return name


def apply_to_block(block, blks, rom_id, stats=None):
    """Relabel `block` (a <rom> element) in place for ROM `rom_id`.

    blks: all <rom> elements of the same file (for base-chain template lookup),
    keyed by lowercase xmlid — see extend_defs_all_roms.blocks().
    Returns stats dict. Idempotent: entries already carrying MARKER are skipped.
    """
    labels = load_labels()
    by_desc, by_data = maps_index(rom_id)
    for row in by_desc.values():
        row["_rom"] = rom_id
    rom = rom_bytes(rom_id)
    if rom_id == REFERENCE:
        desc_map = {d: d for d in by_desc}          # own descriptor
        label_of = {d: labels.get(d) for d in by_desc}  # direct
    else:
        sm = structural_matches().get(rom_id, {})
        desc_map = sm                                  # rom_desc -> ref_desc
        label_of = {rd: labels.get(ref) for rd, ref in sm.items()}

    st = {"renamed": 0, "regrouped": 0, "annotated": 0, "added": 0, "skipped_marker": 0,
          "no_label": 0, "details": []}
    if stats is not None:
        stats.update(st)

    existing_names = {t.get("name") for t in block.findall("table")}
    _names_pre = [t.get("name") for t in block.findall("table")]
    pre_dup = {n for n in _names_pre if _names_pre.count(n) > 1}

    # join reliability: the block's storageaddresses must land in this ROM's
    # maps (data or descriptor addresses); otherwise the upstream block belongs
    # to a different layout (60E32000 upstream block matches neither N3M5E nor
    # N3N5EB) and adding/renaming would create duplicates -> skip the ROM.
    sa_tables = [t for t in block.findall("table") if t.get("storageaddress")]
    joined = sum(1 for t in sa_tables
                 if int(t.get("storageaddress"), 16) in by_data
                 or int(t.get("storageaddress"), 16) in by_desc)
    join_rate = joined / max(1, len(sa_tables))
    st["block_tables"] = len(sa_tables)
    st["join_rate"] = round(join_rate, 3)
    if join_rate < 0.5 and rom_id != REFERENCE:
        st["skipped"] = "block storageaddresses do not join this ROM's data/maps (upstream block layout mismatch); no relabel applied"
        return st

    # --- pass 1: existing tables ------------------------------------------------
    for t in list(block.findall("table")):
        d = t.findtext("description") or ""
        desc = None
        m = DESC_RE.search(d)
        if m:
            desc = int(m.group(1), 16)
        else:
            sa = t.get("storageaddress")
            if sa:
                a = int(sa, 16)
                if a in by_data:
                    desc = by_data[a]["descriptor_i"]
                elif a in by_desc:
                    desc = a
        if desc is None:
            continue
        row = by_desc.get(desc)
        if row is None:
            continue
        label = label_of.get(desc)
        if MARKER in d:
            st["skipped_marker"] += 1
            continue
        old_name = t.get("name")
        if label is None:
            st["no_label"] += 1
            continue
        # rename + regroup, self-contained via base template of the old name
        tmpl = find_template(old_name, block, blks)
        new_name = label["name"]
        if new_name != old_name:
            new_name = _unique_name(new_name, desc, existing_names)
        if tmpl is not None:
            new_el = tmpl
            new_el.set("name", new_name)
            if label.get("category"):
                new_el.set("category", label["category"])
            new_el.set("storageaddress", _fmt_addr(row["data_i"]))
            _set_axes(new_el, row)
            # keep the existing 2026-09-18 description, append ours
            old_desc = t.findtext("description")
            new_el_desc = new_el.find("description")
            if old_desc:
                if new_el_desc is None:
                    new_el_desc = E.SubElement(new_el, "description")
                new_el_desc.text = old_desc + "\n" + (new_el_desc.text or "")
            _append_desc(new_el, _label_desc(label, desc_map.get(desc, desc), old_name, rom_id, desc))
        else:
            new_el = _self_contained(row, rom, new_name, label.get("category") or "Unknown",
                                     _label_desc(label, desc_map.get(desc, desc), old_name, rom_id, desc))
        idx = list(block).index(t)
        block.remove(t)
        block.insert(idx, new_el)
        existing_names.discard(old_name)
        existing_names.add(new_name)
        st["renamed"] += 1
        if label.get("category"):
            st["regrouped"] += 1
        st["details"].append({"descriptor": f"0x{desc:x}", "old": old_name, "new": new_name,
                              "category": label.get("category"), "action": "renamed"})

    # --- pass 2: extracted tables missing from the block -> add them ------------
    present_desc, present_data = set(), set()
    for t in block.findall("table"):
        d = t.findtext("description") or ""
        m = DESC_RE.search(d)
        if m:
            present_desc.add(int(m.group(1), 16))
        sa = t.get("storageaddress")
        if sa:
            a = int(sa, 16)
            if a in by_data:
                present_desc.add(by_data[a]["descriptor_i"])
                present_data.add(a)
            if a in by_desc:
                present_desc.add(a)
                present_data.add(by_desc[a]["data_i"])
    for desc, row in sorted(by_desc.items()):
        if desc in present_desc or row["data_i"] in present_data:
            continue
        label = label_of.get(desc)
        if label is not None and MARKER in json.dumps(label):
            pass
        if label is not None:
            name = _unique_name(label["name"], desc, existing_names)
            cat = label.get("category") or "Unknown"
        else:
            dim = int(row["dimension"])
            name = f"Table {dim}D - 0x{desc:x} (unlabeled)"
            cat = f"Unknown {dim}D"
        desc_text = (f"[{MARKER}] added from data/maps/{rom_id} extraction: descriptor 0x{desc:x}, "
                     f"data 0x{row['data_i']:x}, dim {row['dimension']}, count {row['count']}, "
                     f"type {row['type']}, scaled={row['scaled']}"
                     + (f"; {_label_desc(label, desc_map.get(desc, desc), None, rom_id, desc)}" if label
                        else "; unlabeled"))
        el = _self_contained(row, rom, name, cat, desc_text)
        block.append(el)
        existing_names.add(name)
        st["added"] += 1
        st["details"].append({"descriptor": f"0x{desc:x}", "new": name, "category": cat,
                              "action": "added", "labeled": label is not None})

    # uniqueness: the relabel must not introduce NEW duplicate names (some
    # upstream blocks already carry pre-existing duplicates)
    names = [t.get("name") for t in block.findall("table")]
    dup = {n for n in names if names.count(n) > 1}
    new_dup = dup - pre_dup
    assert not new_dup, f"{rom_id}: relabel introduced duplicate table names: {new_dup}"
    st["preexisting_duplicate_names"] = sorted(dup)
    return st
