#!/usr/bin/env python3
"""Audit an RX8Defs submodule pin move and record it machine-readably.

Compares the pinned submodule commit (submodules/RX8Defs @ gitlink, e.g.
d4140dc) against the previous synced pin (PREVIOUS_PIN, 39d98a0) on
RomRaider/rx8_defs.xml and records:

  * the table-level delta (renames, category moves, duplicate removals) as
    window-tagged records appended to
    docs/investigations/60E15120_N3J1E/labeling/defs-merge/upstream_changes.json
    (the pre-existing untagged records are the merge_review.py ten-commit
    window and are left untouched);
  * the collision audit over our own defs (merged def, reviewed copy, upstream
    snapshot, per-rom/*.xml) at the new pin: storageaddresses mapped to >1
    table in a <rom> block -> axis_conflicts.json; our def table names that the
    upstream block at the new pin no longer carries (renamed/removed upstream)
    while the address still exists there under another name ->
    inheritance_issues.json (alias pairs to cross-reference); coverage of the
    upstream-removed override addresses in our regenerated per-ROM defs;
  * a label-map cross-check: defs_table_labels.json / renamed_table_evidence.json
    / candidate_promotions.json entries naming any renamed table;
  * a full machine record
    docs/investigations/60E15120_N3J1E/labeling/defs-merge/upstream_pin_audit_<pin>.json.

New findings are tagged "pin": <new pin>; re-running replaces this pin's
records and leaves other pins' / legacy records untouched, so the script is
idempotent (tests/test_defs_upstream_pin.py re-runs it and asserts the
committed JSONs are unchanged).

Run from the repo root:
  python utilities/scripts/defs-merge/upstream_pin_audit.py [--old <sha>] [--check]
--check reports what would change without writing (exit 1 if anything).
"""

from pathlib import Path
from collections import Counter, defaultdict
import json
import subprocess
import sys
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
SUB = ROOT / "submodules" / "RX8Defs"
DEFS = ROOT / "data" / "definitions"
DEFS_RR = DEFS / "romraider"
DOCS = ROOT / "docs" / "investigations" / "60E15120_N3J1E" / "labeling"
DEFS_MERGE = DOCS / "defs-merge"
RX8DEFS_ANALYSIS = DOCS / "rx8defs-analysis"
LABELS = ROOT / "data" / "labels" / "60E15120_N3J1E"

UPSTREAM_REL = "RomRaider/rx8_defs.xml"
PREVIOUS_PIN = "39d98a0a87faa1ea3225f7122a1ac2b9d620ff9f"

UPSTREAM_CHANGES = DEFS_MERGE / "upstream_changes.json"
AXIS_CONFLICTS = DEFS_MERGE / "axis_conflicts.json"
INHERITANCE_ISSUES = DEFS_MERGE / "inheritance_issues.json"

OUR_DEF_FILES = (
    [DEFS_RR / "rx8defs-merged-60E15120.xml",
     DEFS_RR / "reviewed-rx8defs-copy" / "rx8_defs.xml",
     DEFS_RR / "upstream-rx8defs" / "rx8_defs.xml"]
    + sorted((DEFS_RR / "per-rom").glob("*.xml"))
)


def git(repo, *args):
    return subprocess.check_output(["git", "-C", str(repo), *args]).decode("utf-8-sig").strip()


def new_pin():
    head = git(SUB, "rev-parse", "HEAD")
    gitlink = git(ROOT, "ls-tree", "HEAD", "submodules/RX8Defs").split()[2]
    assert head == gitlink, f"submodule HEAD {head} != gitlink {gitlink}"
    return head


def blob_root(pin):
    raw = subprocess.check_output(["git", "-C", str(SUB), "show", f"{pin}:{UPSTREAM_REL}"])
    return E.fromstring(raw.decode("utf-8-sig"))


def block_label(rom):
    for rid in rom.findall("romid"):
        v = (rid.findtext("xmlid") or "").strip()
        if v:
            return v
    return (rom.findtext("romid/internalidstring") or "?").strip()


def blocks(root):
    return {block_label(r).lower(): r for r in root.findall("rom")}


def tabs(rom):
    out = []
    for t in rom.findall("table"):
        out.append({
            "name": t.get("name"), "category": t.get("category"),
            "storageaddress": (t.get("storageaddress") or "").lower() or None,
            "type": t.get("type"), "storagetype": t.get("storagetype"),
            "size": t.get("size"), "sizex": t.get("sizex"), "sizey": t.get("sizey"),
        })
    return out


def compute_delta(old_root, new_root, window):
    """Table-level delta per block. Returns (records, rename_map, removed_with_addr).

    Address-carrying tables (ROM-block overrides) are paired per
    storageaddress in document order; base-block tables (no address) are
    paired by name (category moves) and by the rename map learned from the
    address-paired blocks. Leftovers are removals (duplicate cleanup).
    """
    ob, nb = blocks(old_root), blocks(new_root)
    records = []
    rename_map = {}
    removed_with_addr = []

    # pass 1: address-paired renames/removals (also builds the rename map)
    for key in sorted(set(ob) & set(nb)):
        blk = block_label(ob[key])
        o_by_addr, n_by_addr = defaultdict(list), defaultdict(list)
        for t in tabs(ob[key]):
            if t["storageaddress"]:
                o_by_addr[t["storageaddress"]].append(t)
        for t in tabs(nb[key]):
            if t["storageaddress"]:
                n_by_addr[t["storageaddress"]].append(t)
        for addr in sorted(o_by_addr):
            oc = Counter(t["name"] for t in o_by_addr[addr])
            nc = Counter(t["name"] for t in n_by_addr.get(addr, []))
            removed, added = list((oc - nc).elements()), list((nc - oc).elements())
            if removed and added:
                assert len(removed) == len(added), (blk, addr, removed, added)
                for r, a in zip(removed, added):
                    ot = next(t for t in o_by_addr[addr] if t["name"] == r)
                    nt = next(t for t in n_by_addr[addr] if t["name"] == a)
                    if r in rename_map:
                        assert rename_map[r] == a, (r, rename_map[r], a)
                    else:
                        rename_map[r] = a
                    records.append({
                        "window": window, "rom": blk, "kind": "renamed",
                        "name_before": r, "name_after": a, "storageaddress": addr,
                        "category_before": ot["category"], "category_after": nt["category"],
                    })
            elif removed and not added:
                for r in removed:
                    removed_with_addr.append({"rom": blk, "name": r, "storageaddress": addr})
                    records.append({
                        "window": window, "rom": blk, "kind": "removed_duplicate",
                        "name_before": r, "name_after": None, "storageaddress": addr,
                        "category_before": next(t for t in o_by_addr[addr] if t["name"] == r)["category"],
                        "category_after": None,
                    })

    # pass 2: base block (no addresses) — category moves by (name, category)
    # signature, renames via the map learned from the ROM blocks
    for key in sorted(set(ob) & set(nb)):
        blk = block_label(ob[key])
        ot_all, nt_all = tabs(ob[key]), tabs(nb[key])
        if any(t["storageaddress"] for t in ot_all):
            continue  # ROM blocks handled above
        o_by_name = defaultdict(list)
        n_by_name = defaultdict(list)
        for t in ot_all:
            o_by_name[t["name"]].append(t)
        for t in nt_all:
            n_by_name[t["name"]].append(t)
        for name in sorted(set(o_by_name) & set(n_by_name)):
            ot, nt = o_by_name[name][0], n_by_name[name][0]
            if nt["category"] != ot["category"]:
                records.append({
                    "window": window, "rom": blk, "kind": "category_moved",
                    "name_before": name, "name_after": name, "storageaddress": None,
                    "category_before": ot["category"], "category_after": nt["category"],
                })
        for r in sorted(set(o_by_name) - set(n_by_name)):
            ot = o_by_name[r][0]
            if r in rename_map:
                a = rename_map[r]
                nt = n_by_name[a][0]
                records.append({
                    "window": window, "rom": blk, "kind": "renamed",
                    "name_before": r, "name_after": a, "storageaddress": None,
                    "category_before": ot["category"], "category_after": nt["category"],
                })
            else:
                records.append({
                    "window": window, "rom": blk, "kind": "removed_duplicate",
                    "name_before": r, "name_after": None, "storageaddress": None,
                    "category_before": ot["category"], "category_after": None,
                })
        for a in sorted(set(n_by_name) - set(o_by_name)):
            if a not in rename_map.values():
                records.append({
                    "window": window, "rom": blk, "kind": "added",
                    "name_before": None, "name_after": a, "storageaddress": None,
                    "category_before": None, "category_after": n_by_name[a][0]["category"],
                })
    records.sort(key=lambda r: (r["rom"], r["kind"], r["name_before"] or "", r["storageaddress"] or ""))
    return records, rename_map, removed_with_addr


def audit_defs(new_root, pin, rename_map):
    """Collision audit over our own def files at the new pin.

    conflicts: storageaddresses mapped to >1 table inside one of our <rom>
    blocks, deduped across files (each per-ROM def embeds the same base chain,
    so the same upstream duplicate would otherwise repeat per file).
    aliases: our def tables at an address that upstream renamed in this window
    (upstream name at the address is a rename target) while our name differs —
    the alias pairs to cross-reference in the docs.
    """
    nb = blocks(new_root)
    rename_targets = set(rename_map.values())
    conflicts = {}
    aliases = []
    for path in OUR_DEF_FILES:
        rel = path.relative_to(ROOT).as_posix()
        root = E.parse(path).getroot()
        for rom in root.findall("rom"):
            blk = block_label(rom)
            by_addr = defaultdict(list)
            for t in rom.findall("table"):
                sa = (t.get("storageaddress") or "").lower()
                if sa:
                    by_addr[sa].append(t.get("name"))
            for sa in sorted(by_addr):
                if len(by_addr[sa]) > 1:
                    key = (blk, sa)
                    up = nb.get(blk.lower())
                    up_dup = False
                    if up is not None:
                        u = Counter((t.get("storageaddress") or "").lower() for t in up.findall("table"))
                        up_dup = u.get(sa, 0) > 1
                    c = conflicts.setdefault(key, {
                        "pin": pin, "rom": blk, "storageaddress": sa,
                        "names": sorted(set(by_addr[sa])), "count": len(by_addr[sa]),
                        "duplicate_also_upstream_at_pin": up_dup, "files": [],
                    })
                    if rel not in c["files"]:
                        c["files"].append(rel)
            # alias pairs vs the upstream block at the pin
            up = nb.get(blk.lower())
            if up is None:
                continue
            up_by_addr = defaultdict(list)
            for t in up.findall("table"):
                sa = (t.get("storageaddress") or "").lower()
                if sa:
                    up_by_addr[sa].append(t.get("name"))
            for t in rom.findall("table"):
                sa = (t.get("storageaddress") or "").lower()
                name = t.get("name")
                if sa and sa in up_by_addr:
                    for up_name in sorted(set(up_by_addr[sa])):
                        if up_name in rename_targets and up_name != name:
                            aliases.append({
                                "pin": pin, "file": rel,
                                "rom": blk, "issue": "upstream_pin_rename_alias",
                                "name": name, "storageaddress": sa,
                                "upstream_name_at_address": up_name,
                            })
    seen, out = set(), []
    for a in aliases:
        k = (a["file"], a["rom"], a["name"], a["storageaddress"], a["upstream_name_at_address"])
        if k not in seen:
            seen.add(k)
            out.append(a)
    cl = sorted(conflicts.values(), key=lambda c: (c["rom"], c["storageaddress"]))
    out.sort(key=lambda a: (a["file"], a["rom"], a["storageaddress"], a["name"]))
    return cl, out


def orphaned_overrides(new_root, delta, pin):
    """Base-block tables removed at this pin while ROM-block overrides still
    carry the same name: RomRaider's name-based inheritance no longer finds a
    base template for those overrides (mirrors upstream)."""
    removed_base = {r["name_before"] for r in delta
                    if r["kind"] == "removed_duplicate" and r["storageaddress"] is None}
    out = []
    if not removed_base:
        return out
    for rom in new_root.findall("rom"):
        blk = block_label(rom)
        for t in rom.findall("table"):
            if t.get("name") in removed_base:
                out.append({
                    "pin": pin, "rom": blk, "issue": "base_template_removed_at_pin",
                    "name": t.get("name"),
                    "storageaddress": (t.get("storageaddress") or "").lower() or None,
                    "note": "block override keeps this name but the RX8Base template was "
                            "removed in this window; mirrors the upstream pin",
                })
    out.sort(key=lambda a: (a["rom"], a["name"], a["storageaddress"] or ""))
    return out


def coverage_of_removed(removed_with_addr, pin):
    """For each upstream-removed override address, is it still covered by the
    regenerated per-ROM def (re-added by the relabel pass from the ROM
    extraction) or not present in this ROM's maps at all?"""
    out = []
    per_rom = {block_label(E.parse(p).getroot().findall("rom")[-1]).lower(): p
               for p in sorted((DEFS_RR / "per-rom").glob("*.xml"))}
    for r in sorted(removed_with_addr, key=lambda r: (r["rom"], r["storageaddress"])):
        path = per_rom.get(r["rom"].lower())
        entry = {"pin": pin, "rom": r["rom"], "name": r["name"],
                 "storageaddress": r["storageaddress"], "per_rom_def": None, "covered": None}
        if path is not None:
            entry["per_rom_def"] = path.relative_to(ROOT).as_posix()
            root = E.parse(path).getroot()
            blk = root.findall("rom")[-1]
            hit = [t.get("name") for t in blk.findall("table")
                   if (t.get("storageaddress") or "").lower() == r["storageaddress"]]
            entry["covered"] = bool(hit)
            entry["covering_names"] = sorted(set(hit))
        out.append(entry)
    return out


def label_map_check(rename_map):
    """Do our curated label records name any table the upstream pin renamed?"""
    names = set(rename_map) | set(rename_map.values())
    hits = {}
    lj = json.loads((LABELS / "defs_table_labels.json").read_text(encoding="utf-8"))
    hits["defs_table_labels.json"] = sorted(
        f"{k}: {v['name']}" for k, v in lj["entries"].items() if v.get("name") in names)
    for f in (DEFS_MERGE / "renamed_table_evidence.json",):
        d = json.loads(f.read_text(encoding="utf-8"))
        hits[f.name] = sorted(x["name"] for x in d if x.get("name") in names)
    cp = json.loads((LABELS / "candidate_promotions.json").read_text(encoding="utf-8"))
    found = []
    for k, v in cp.items():
        if isinstance(v, dict) and v.get("name") in names:
            found.append(f"{k}: {v['name']}")
        elif isinstance(v, list):
            found += [x.get("name", "") for x in v if isinstance(x, dict) and x.get("name") in names]
    hits["candidate_promotions.json"] = sorted(set(found))
    return hits


def _read_json(path):
    raw = path.read_bytes()
    nl = "\r\n" if b"\r\n" in raw else "\n"
    return json.loads(raw.decode("utf-8-sig")), nl


def _write_json(path, data, nl):
    text = json.dumps(data, indent=1, ensure_ascii=False) + "\n"
    if nl == "\r\n":
        text = text.replace("\n", "\r\n")
    path.write_bytes(text.encode("utf-8"))


def main():
    args = sys.argv[1:]
    check = "--check" in args
    old = PREVIOUS_PIN
    if "--old" in args:
        old = args[args.index("--old") + 1]
    pin = new_pin()
    short = git(SUB, "rev-parse", "--short=7", "HEAD")
    window = f"{old[:8]}..{short}"

    # only rx8_defs.xml moved between the pins
    changed_files = git(SUB, "diff", "--name-only", old, pin).splitlines()
    assert changed_files == [UPSTREAM_REL], changed_files

    old_root, new_root = blob_root(old), blob_root(pin)
    delta, rename_map, removed = compute_delta(old_root, new_root, window)
    conflicts, aliases = audit_defs(new_root, pin, rename_map)
    aliases = aliases + orphaned_overrides(new_root, delta, pin)
    aliases.sort(key=lambda a: (a.get("file", ""), a["rom"], a["storageaddress"] or "", a["name"]))
    coverage = coverage_of_removed(removed, pin)
    labels = label_map_check(rename_map)

    audit = {
        "pass": "upstream RX8Defs pin audit",
        "old_pin": old, "new_pin": pin, "new_pin_short": short, "window": window,
        "changed_files": changed_files,
        "delta_summary": {
            k: sum(1 for r in delta if r["kind"] == k)
            for k in ("renamed", "category_moved", "removed_duplicate", "added")
        },
        "rename_map": rename_map,
        "delta": delta,
        "collisions": conflicts,
        "rename_aliases": aliases,
        "removed_override_coverage": coverage,
        "label_map_check": labels,
    }
    audit_out = DEFS_MERGE / f"upstream_pin_audit_{short}.json"

    # upstream_changes.json: append the window records once
    uc, uc_nl = _read_json(UPSTREAM_CHANGES)
    window_done = any(r.get("window") == window for r in uc)
    uc_new = uc if window_done else uc + delta
    # conflict/issue records: replace this pin's records
    ac, ac_nl = _read_json(AXIS_CONFLICTS)
    ac_new = [r for r in ac if r.get("pin") != pin] + conflicts
    ii, ii_nl = _read_json(INHERITANCE_ISSUES)
    ii_new = [r for r in ii if r.get("pin") != pin] + aliases

    changed = (uc_new != uc) or (ac_new != ac) or (ii_new != ii)
    print(f"pin {short} (window {window}): delta={audit['delta_summary']}, "
          f"collisions={len(conflicts)}, rename_aliases={len(aliases)}, "
          f"removed_overrides={len(coverage)} covered={sum(1 for c in coverage if c['covered'])}, "
          f"label_map_hits={ {k: len(v) for k, v in labels.items()} }")
    if check:
        print(f"check: records {'would change' if changed else 'unchanged'}; "
              f"audit record would be rewritten to {audit_out.name}")
        return 1 if changed else 0

    if uc_new != uc:
        _write_json(UPSTREAM_CHANGES, uc_new, uc_nl)
        print(f"appended {len(delta)} window records -> {UPSTREAM_CHANGES.relative_to(ROOT)}")
    if ac_new != ac:
        _write_json(AXIS_CONFLICTS, ac_new, ac_nl)
        print(f"axis_conflicts.json: {len(ac)} -> {len(ac_new)}")
    if ii_new != ii:
        _write_json(INHERITANCE_ISSUES, ii_new, ii_nl)
        print(f"inheritance_issues.json: {len(ii)} -> {len(ii_new)}")
    _write_json(audit_out, audit, "\r\n")
    print(f"audit record -> {audit_out.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
