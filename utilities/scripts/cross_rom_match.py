#!/usr/bin/env python3
"""Group D item 1: differential function labeling across all stock ROMs +
own dumps by byte-matching 60E15120_N3J1E function bodies ROM-to-ROM.

For every target ROM, each base function body (function_index body_bytes, bytes
re-read from the base ROM) is searched for a UNIQUE exact occurrence in the
target ROM (same method as metadata/matched_functions.tsv: unique_exact_bytes).
Matched functions inherit the base ROM's accepted aliases
(source_review/accepted_function_aliases.tsv) into a per-ROM alias TSV.

Outputs (new files, nothing existing is modified):
  - data/labels/cross_rom_function_matches.tsv   (one row per base->target match)
  - docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_function_aliases.tsv
  - data/labels/cross_rom_match_summary.json

Run from the repo root:  python utilities/scripts/cross_rom_match.py
"""
from pathlib import Path
import csv, hashlib, json
from collections import Counter, defaultdict

ROOT = Path(__file__).resolve().parents[2]
BASE_ROM_ID = "60E15120_N3J1E"
LABELS = ROOT / "data" / "labels" / BASE_ROM_ID
DEC = ROOT / "reverse-engineered" / "decompiled" / BASE_ROM_ID
STOCK = ROOT / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
DUMPS = ROOT / "binaries" / "dumps"
INV = ROOT / "docs" / "investigations" / BASE_ROM_ID

base_rom = (STOCK / (BASE_ROM_ID + ".bin")).read_bytes()
BASE_SHA = hashlib.sha256(base_rom).hexdigest()
info = json.loads((LABELS / "input.json").read_text())
assert BASE_SHA == info["sha256"], "base ROM hash mismatch"

index = list(csv.DictReader((DEC / "function_index.tsv").open(newline=""), delimiter="\t"))
aliases = {r["address"]: r for r in csv.DictReader(
    (INV / "source_review" / "accepted_function_aliases.tsv").open(newline=""), delimiter="\t")}

targets = {}
for p in sorted(STOCK.glob("*.bin")):
    targets[p.name] = p.read_bytes()
for p in sorted(DUMPS.glob("*.bin")):
    targets["dumps/" + p.name] = p.read_bytes()

match_rows = []
alias_rows = []
summary = {}
for rom_name, rom in targets.items():
    n_match = 0
    n_alias = 0
    seen_targets = Counter()
    for r in index:
        a = int(r["address"], 16)
        n = int(r["body_bytes"])
        if n == 0:
            continue
        body = base_rom[a:a + n]
        i = rom.find(body)
        if i < 0 or rom.find(body, i + 1) >= 0:
            continue  # no unique exact match
        seen_targets[i] += 1
        match_rows.append({"rom": rom_name, "base_address": r["address"],
                           "base_name": r["name"], "target_address": "%08x" % i,
                           "size": str(n), "method": "unique_exact_bytes"})
        n_match += 1
        al = aliases.get(r["address"])
        if al:
            alias_rows.append({"rom": rom_name, "target_address": "%08x" % i,
                               "alias": al["alias"], "base_address": r["address"],
                               "confidence": al["confidence"]})
            n_alias += 1
    summary[rom_name] = {"sha256": hashlib.sha256(rom).hexdigest(), "size": len(rom),
                         "functions_matched": n_match, "aliases_propagated": n_alias,
                         "base_functions": len(index)}

def write_tsv(path, fieldnames, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames, delimiter="\t")
        w.writeheader()
        w.writerows(rows)

write_tsv(ROOT / "data" / "labels" / "cross_rom_function_matches.tsv",
          ["rom", "base_address", "base_name", "target_address", "size", "method"], match_rows)
write_tsv(INV / "cross_ecu" / "cross_rom_function_aliases.tsv",
          ["rom", "target_address", "alias", "base_address", "confidence"], alias_rows)
out = {"date": "2026-10-31", "base_rom": BASE_ROM_ID, "base_sha256": BASE_SHA,
       "method": "unique exact byte match of function_index body_bytes in target ROM",
       "summary": summary, "outputs": ["data/labels/cross_rom_function_matches.tsv",
                                       "docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_function_aliases.tsv"]}
(ROOT / "data" / "labels" / "cross_rom_match_summary.json").write_text(json.dumps(out, indent=2) + "\n")
print(json.dumps({"roms": len(targets), "match_rows": len(match_rows), "alias_rows": len(alias_rows),
                  "per_rom": {k: (v["functions_matched"], v["aliases_propagated"]) for k, v in summary.items()}}, indent=2))
