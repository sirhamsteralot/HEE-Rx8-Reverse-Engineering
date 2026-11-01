#!/usr/bin/env python3
"""ROADMAP group D backlog item: apply the cross-ROM label sets to a decompiled
export (currently: 60E0G500_N3ZHEC, the only non-base ROM with an export).

Rename sources, all propagated from the base ROM 60E15120_N3J1E by evidence:
  - docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_function_aliases.tsv
    rows for the target ROM (unique_exact_bytes function matches; alias inherited
    at the match confidence) — applied as-is (high confidence, plain alias).
  - the Mode 22 cross-ROM map (data/labels/cross_rom_mode22_pid_handlers.tsv):
    data-table labels for the dispatch table and sub-PID table (DAT_ -> tbl_...,
    also written to named/lookup_aliases.tsv), and the one pid_match-only handler
    (0x57e66, PID 0xc116) which has no C identifier in this export (mid-function
    address) — recorded in the provenance TSV only, with a candidate_ prefix.

The script rewrites, in place, only text artifacts of the export (never the ROM):
  reverse-engineered/decompiled/<ROM>/function_index.tsv   (name column)
  reverse-engineered/decompiled/<ROM>/callgraph.tsv        (callee_name column)
  reverse-engineered/decompiled/<ROM>/symbols.tsv          (name column)
  reverse-engineered/decompiled/<ROM>/functions/*.c        (identifiers outside comments)
  reverse-engineered/decompiled/<ROM>/firmware_decompiled.c (same + header)
and writes the synchronized named view:
  reverse-engineered/decompiled/<ROM>/named/firmware_named.c
  reverse-engineered/decompiled/<ROM>/named/lookup_aliases.tsv
  reverse-engineered/decompiled/<ROM>/named/README.md
  reverse-engineered/decompiled/<ROM>/named/validation.json
plus provenance:
  data/labels/<ROM>/cross_rom_renames_applied.tsv
  data/labels/cross_rom/mode22/<rom-file>.tsv   (per-ROM Mode 22 PID map, all 14 ROMs)
and a pre-change backup zip (LFS-routed by .gitattributes):
  docs/investigations/<ROM>/backups/pre_crossrom_names.zip

Safety asserts: ROM SHA-256 unchanged vs data/labels/<ROM>/input.json; every
function body still occurs intact in the canonical C; each renamed function's
new name appears as a definition in its file; all new names are unique, valid C
identifiers, and do not collide with pre-existing export names; the transform
skips comments (same rule as integrate_reviewed_names.py).

Run from the repo root:  python utilities/scripts/apply_cross_rom_labels.py
"""
from pathlib import Path
import csv, hashlib, json, re, zipfile

ROOT = Path(__file__).resolve().parents[2]
ROM_ID = "60E0G500_N3ZHEC"
ROM_KEY = "dumps/aron-N3ZHEC-2026-10-31.bin"  # key in the cross-ROM TSVs
DEC = ROOT / "reverse-engineered" / "decompiled" / ROM_ID
INV = ROOT / "docs" / "investigations" / ROM_ID
LABELS = ROOT / "data" / "labels" / ROM_ID
ALIASES_TSV = ROOT / "docs" / "investigations" / "60E15120_N3J1E" / "cross_ecu" / "cross_rom_function_aliases.tsv"
MODE22_TSV = ROOT / "data" / "labels" / "cross_rom_mode22_pid_handlers.tsv"

# --- Mode 22 additions not covered by the byte-match alias TSV ---
# dispatch table 0x5f8b0 / sub-PID table 0x5fd56 (pool-ref + count-byte verified)
TABLE_LABELS = {
    "0005f8b0": ("tbl_diag22_dispatch_records_0005f8b0",
                 "Mode 22 dispatch table in this ROM: u32 pool ref 0x57fec + count byte 0x5fd54=99 (pool ref 0x57ff8); 99 x 12-byte records; dispatcher 0x57ef0 dynamically swept 99/99"),
    "0005fd56": ("tbl_diag22_subpid_supported_bits_0005fd56",
                 "sub-PID supported-bit table = count byte + 2; u32 pool ref 0x581f0; 36 x 6-byte records, same PID list as base 0x5f5b2"),
}
# pid_match-only handler: no C identifier (mid-function address) -> provenance only
PID_MATCH_HANDLERS = {
    "00057e66": ("candidate_diag22_pidc116_dtc_state_machine",
                 "pid_match: PID 0xc116, same response_len; dump dispatcher 0x57ef0 dynamically reaches 0x57e66 for PID 0xc116 (99/99 sweep); base handler 0x576c2 = diag22_pidc116_dtc_state_machine"),
}


def rows(p):
    with p.open(newline="") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def write_rows(p, rs, fields):
    with p.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter="\t", lineterminator="\n")
        w.writeheader()
        w.writerows(rs)


# --- safety: ROM untouched, hash matches provenance ---
rom_path = ROOT / "binaries" / "dumps" / "aron-N3ZHEC-2026-10-31.bin"
rom_sha_before = hashlib.sha256(rom_path.read_bytes()).hexdigest()
info = json.loads((LABELS / "input.json").read_text())
assert rom_sha_before == info["sha256"], "ROM hash mismatch vs input.json"

# --- build the rename map ---
index = rows(DEC / "function_index.tsv")
byaddr = {r["address"]: r for r in index}
syms = rows(DEC / "symbols.tsv")
sym_by_addr = {r["address"]: r for r in syms}
existing_names = {r["name"] for r in index} | {r["name"] for r in syms}

fn_map = {}  # old C identifier -> new name
prov = []    # provenance rows
for r in rows(ALIASES_TSV):
    if r["rom"] != ROM_KEY:
        continue
    addr, alias = r["target_address"], r["alias"]
    old = byaddr.get(addr, {}).get("name")
    if old is None:
        prov.append({"address": addr, "old_name": "", "new_name": "", "source": "cross_rom_function_aliases",
                     "confidence": r["confidence"], "applied": "skipped (not a function start in export)"})
        continue
    if old == alias:
        continue
    fn_map[old] = alias
    prov.append({"address": addr, "old_name": old, "new_name": alias, "source": "cross_rom_function_aliases (unique_exact_bytes)",
                 "confidence": r["confidence"], "applied": "yes"})

for addr, (alias, evidence) in TABLE_LABELS.items():
    old = sym_by_addr.get(addr, {}).get("name", "DAT_" + addr)
    fn_map[old] = alias
    prov.append({"address": addr, "old_name": old, "new_name": alias, "source": "cross_rom_mode22_pid_handlers (table location)",
                 "confidence": "high", "applied": "yes", "evidence": evidence})
for addr, (alias, evidence) in PID_MATCH_HANDLERS.items():
    prov.append({"address": addr, "old_name": "(no C identifier — mid-function address)", "new_name": alias,
                 "source": "cross_rom_mode22_pid_handlers (pid_match)", "confidence": "pid_match",
                 "applied": "provenance only (no symbol to rename)", "evidence": evidence})

# validity / collision asserts
assert len(set(fn_map.values())) == len(fn_map), "alias collision in rename map"
ident = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
for old, new in fn_map.items():
    assert ident.match(new), new
    assert new not in existing_names or new == old, f"collision with existing name: {new}"
assert len(fn_map) > 200, "suspiciously few renames"

pattern = re.compile(r"\b(?:" + "|".join(re.escape(k) for k in sorted(fn_map, key=len, reverse=True)) + r")\b")


def transform(s):
    parts = re.split(r"(/\*.*?\*/|//[^\n]*)", s, flags=re.S)
    for i in range(0, len(parts), 2):
        parts[i] = pattern.sub(lambda m: fn_map[m[0]], parts[i])
    return "".join(parts)


# --- backup the export before touching it ---
backup = INV / "backups" / "pre_crossrom_names.zip"
backup.parent.mkdir(exist_ok=True)
if not backup.exists():
    with zipfile.ZipFile(backup, "w", zipfile.ZIP_DEFLATED) as z:
        for p in DEC.rglob("*"):
            if p.is_file():
                z.write(p, str(p.relative_to(DEC)))

# --- transform individual function files ---
changed = 0
for r in index:
    p = DEC / r["file"]
    old_text = p.read_text()
    new_text = transform(old_text)
    if new_text != old_text:
        p.write_text(new_text)
        changed += 1
    # every function body still defines its (possibly renamed) name
    new_name = fn_map.get(r["name"], r["name"])
    assert re.search(r"\b" + re.escape(new_name) + r"\s*\(", new_text), r["address"]

# --- canonical listing ---
canon_p = DEC / "firmware_decompiled.c"
s = transform(canon_p.read_text())
# fix the export header ROM name (was left as the base ROM's name) and mark integration
s = s.replace("/* Decompiled from 60E15120_N3J1E.bin using Ghidra.",
              "/* Decompiled from 60E0G500 (N3ZHEC, binaries/dumps/aron-N3ZHEC-2026-10-31.bin) using Ghidra.", 1)
header = ("/* [CROSS-ROM NAMES APPLIED 2026-11-01]\n"
          " * Names propagated from 60E15120_N3J1E by unique-exact-byte function matches\n"
          " * (cross_ecu/cross_rom_function_aliases.tsv) + the Mode 22 cross-ROM map\n"
          " * (data/labels/cross_rom_mode22_pid_handlers.tsv); provenance:\n"
          " * data/labels/60E0G500_N3ZHEC/cross_rom_renames_applied.tsv.\n"
          " * Address suffixes preserve identity; this is analysis C, not buildable firmware.\n"
          " * Saved Ghidra database has not been updated.\n */\n")
if "[CROSS-ROM NAMES APPLIED" not in s:
    s = header + s
canon_p.write_text(s)

# bodies intact in the canonical listing
for r in index:
    body = (DEC / r["file"]).read_text()
    anchor = "/* ROM address: 0x" + r["address"] + ";"
    assert body[body.index(anchor):].strip() in s, r["address"]

# --- index / callgraph / symbols ---
for r in index:
    if r["name"] in fn_map:
        r["name"] = fn_map[r["name"]]
write_rows(DEC / "function_index.tsv", index, list(index[0].keys()))
calls = rows(DEC / "callgraph.tsv")
for r in calls:
    old = byaddr.get(r["callee"], {}).get("name", "FUN_" + r["callee"])
    if old in fn_map:
        r["callee_name"] = fn_map[old]
write_rows(DEC / "callgraph.tsv", calls, list(calls[0].keys()))
for r in syms:
    if r["name"] in fn_map:
        r["name"] = fn_map[r["name"]]
write_rows(DEC / "symbols.tsv", syms, list(syms[0].keys()))

# --- named view ---
named = DEC / "named"
named.mkdir(exist_ok=True)
(named / "firmware_named.c").write_text(s)
lookup_fields = ["original", "alias", "basis", "evidence"]
lookup_rows = []
for p in prov:
    if p["source"].startswith("cross_rom_mode22_pid_handlers (table"):
        lookup_rows.append({"original": p["old_name"], "alias": p["new_name"],
                            "basis": "cross-ROM Mode 22 map (pool ref + self-consistent count byte)",
                            "evidence": p.get("evidence", "")})
write_rows(named / "lookup_aliases.tsv", lookup_rows, lookup_fields)
(named / "README.md").write_text(
    "# named view — 60E0G500_N3ZHEC\n\n"
    "Synchronized copy of `firmware_decompiled.c` after applying the cross-ROM\n"
    "names (see the [CROSS-ROM NAMES APPLIED] header). Provenance:\n"
    "`data/labels/60E0G500_N3ZHEC/cross_rom_renames_applied.tsv`;\n"
    "table aliases: `lookup_aliases.tsv` here. Report:\n"
    "`docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md`.\n")

# --- provenance + validation ---
write_rows(LABELS / "cross_rom_renames_applied.tsv", prov,
           ["address", "old_name", "new_name", "source", "confidence", "applied", "evidence"])
rom_sha_after = hashlib.sha256(rom_path.read_bytes()).hexdigest()
assert rom_sha_after == rom_sha_before
validation = {
    "date": "2026-11-01", "rom": ROM_ID, "rom_file": ROM_KEY, "rom_sha256": rom_sha_after,
    "renames_applied": sum(1 for p in prov if p["applied"] == "yes"),
    "provenance_only": sum(1 for p in prov if p["applied"].startswith("provenance")),
    "skipped": sum(1 for p in prov if p["applied"].startswith("skipped")),
    "individual_files_changed": changed,
    "checks": ["ROM sha256 unchanged", "all function bodies intact in firmware_decompiled.c",
               "renamed definitions present in their files", "new names unique + valid C identifiers",
               "no collision with pre-existing export names", "comments not rewritten",
               "backup: docs/investigations/60E0G500_N3ZHEC/backups/pre_crossrom_names.zip"],
    "backup": "docs/investigations/60E0G500_N3ZHEC/backups/pre_crossrom_names.zip",
    "ghidra_database_updated": False,
}
(named / "validation.json").write_text(json.dumps(validation, indent=1) + "\n")

# --- per-ROM Mode 22 label TSVs for all 14 ROMs (future exports consume these) ---
outdir = ROOT / "data" / "labels" / "cross_rom" / "mode22"
outdir.mkdir(parents=True, exist_ok=True)
m22 = rows(MODE22_TSV)
by_rom = {}
for r in m22:
    by_rom.setdefault(r["rom"], []).append(r)
for rom_name, rs in by_rom.items():
    write_rows(outdir / (rom_name.replace("/", "__") + ".tsv"), rs, list(rs[0].keys()))

print(json.dumps({"renames_applied": validation["renames_applied"],
                  "provenance_only": validation["provenance_only"],
                  "skipped": validation["skipped"],
                  "files_changed": changed,
                  "per_rom_mode22_tsvs": len(by_rom)}, indent=1))
