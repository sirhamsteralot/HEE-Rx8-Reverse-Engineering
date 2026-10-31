#!/usr/bin/env python3
"""Cross-ROM calibration diff: match tables across ROMs by shape+axis, compare data.

Tables are matched across ROMs by (dimension, counts, type_code, axis values).
Tables with identical axes and shape are considered the "same" calibration;
their data values are compared and differences reported.

Usage:
  python utilities/scripts/diff_maps.py [--maps-dir data/maps] [--ref 60E15120_N3J1E]
"""
import argparse
import csv
import json
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
MAPS = REPO / "data" / "maps"


def load_index(rom_id: str) -> dict:
    """Load index.tsv for a ROM, return {descriptor_addr: row}."""
    path = MAPS / rom_id / "index.tsv"
    with path.open() as f:
        return {row["descriptor"]: row for row in csv.DictReader(f, delimiter="\t")}


def load_table(rom_id: str, desc_addr: str) -> dict:
    a = desc_addr.replace("0x", "")
    with (MAPS / rom_id / "tables" / f"tbl_{a}.json").open() as f:
        return json.load(f)


def table_key(t: dict) -> tuple:
    """Structural key for matching tables across ROMs: shape + axes."""
    if t["dimension"] == 2:
        axis = tuple(round(v, 4) for v in t["axis_values"])
        return (2, t["n"], t["type_code"], axis)
    else:
        ax = tuple(round(v, 4) for v in t["axis_x_values"])
        ay = tuple(round(v, 4) for v in t["axis_y_values"])
        return (3, t["nx"], t["ny"], t["type_code"], ax, ay)


def main():
    ap = argparse.ArgumentParser(description="Cross-ROM calibration diff")
    ap.add_argument("--maps-dir", default=str(MAPS))
    ap.add_argument("--ref", default="60E15120_N3J1E", help="Reference ROM id")
    ap.add_argument("--out", help="Output JSON path (default: <maps-dir>/cross_rom_diff.json)")
    args = ap.parse_args()

    maps_dir = Path(args.maps_dir)
    rom_ids = sorted(p.name for p in maps_dir.iterdir() if (p / "index.tsv").exists())
    print(f"ROMs: {rom_ids}")
    print(f"Reference: {args.ref}")

    # Build structural key -> list of (rom_id, desc_addr) for each ROM
    ref_tables = load_index(args.ref)
    ref_keys: dict[tuple, str] = {}
    for desc, row in ref_tables.items():
        t = load_table(args.ref, desc)
        key = table_key(t)
        ref_keys[key] = desc

    print(f"\nReference {args.ref}: {len(ref_keys)} unique table shapes")

    # For each other ROM, match tables to reference by structural key
    results = {}
    for rom_id in rom_ids:
        if rom_id == args.ref:
            continue
        idx = load_index(rom_id)
        rom_keys: dict[tuple, str] = {}
        for desc, row in idx.items():
            t = load_table(rom_id, desc)
            key = table_key(t)
            rom_keys[key] = desc

        matched = 0
        unmatched_ref = 0
        unmatched_rom = 0
        diffs = []
        for key, ref_desc in ref_keys.items():
            if key not in rom_keys:
                unmatched_ref += 1
                continue
            matched += 1
            rom_desc = rom_keys[key]
            rt = load_table(args.ref, ref_desc)
            ot = load_table(rom_id, rom_desc)
            # Compare data values
            if rt["dimension"] == 2:
                rv, ov = rt["data_values"], ot["data_values"]
                ndiff = sum(1 for a, b in zip(rv, ov) if a != b)
                maxdiff = max((abs(float(a) - float(b)) for a, b in zip(rv, ov)), default=0)
            else:
                ndiff = 0
                maxdiff = 0.0
                for rrow, orow in zip(rt["data_values"], ot["data_values"]):
                    for a, b in zip(rrow, orow):
                        if a != b:
                            ndiff += 1
                        maxdiff = max(maxdiff, abs(float(a) - float(b)))
            if ndiff > 0:
                diffs.append({
                    "ref_descriptor": ref_desc,
                    "rom_descriptor": rom_desc,
                    "dimension": rt["dimension"],
                    "count": rt.get("n") or f'{rt["nx"]}x{rt["ny"]}',
                    "type": rt["type_name"],
                    "cells_differing": ndiff,
                    "max_abs_diff": maxdiff,
                })
        unmatched_rom = len(rom_keys) - matched
        results[rom_id] = {
            "matched": matched,
            "unmatched_ref": unmatched_ref,
            "unmatched_rom": unmatched_rom,
            "tables_with_diffs": len(diffs),
            "total_diff_cells": sum(d["cells_differing"] for d in diffs),
            "diffs": sorted(diffs, key=lambda d: -d["cells_differing"]),
        }
        print(f"\n  {rom_id}: matched={matched} unmatched_ref={unmatched_ref} "
              f"unmatched_rom={unmatched_rom} tables_with_diffs={len(diffs)} "
              f"diff_cells={sum(d['cells_differing'] for d in diffs)}")

    out_path = Path(args.out) if args.out else maps_dir / "cross_rom_diff.json"
    report = {
        "reference": args.ref,
        "roms": rom_ids,
        "per_rom": results,
    }
    out_path.write_text(json.dumps(report, indent=2, default=str) + "\n")
    print(f"\nReport: {out_path}")

    # Show top diffs for each ROM
    for rom_id, r in results.items():
        if r["diffs"]:
            print(f"\n  Top 5 diffs in {rom_id}:")
            for d in r["diffs"][:5]:
                print(f"    ref={d['ref_descriptor']} rom={d['rom_descriptor']} "
                      f"{d['dimension']}D {d['count']} {d['type']}: "
                      f"{d['cells_differing']} cells differ, max={d['max_abs_diff']:.4g}")


if __name__ == "__main__":
    main()
