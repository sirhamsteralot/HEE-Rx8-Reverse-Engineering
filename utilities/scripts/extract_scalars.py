#!/usr/bin/env python3
"""Extract verified literal-pool scalar constants from an RX-8 PCM ROM into data/maps/.

Companion to extract_maps.py: the descriptor scan only finds lookup *tables*.
Single float32 constants that live in shared literal pools (referenced by
literal pointers, e.g. 0x30830 -> 0x78170) are scalars, not tables, so this
script locates them by their exact big-endian bit pattern and dumps every
occurrence to data/maps/<rom-id>/ as scalars.json + scalars.tsv.

Seed list (SEEDS below) is curated from binary-verified evidence in
docs/investigations/60E15120_N3J1E/reviews/load_fueling_model/validation.json
and reviews/fueling/REVIEW_NOTES.md §10 (each seed's reference address in
60E15120_N3J1E was re-read from the untouched ROM). When run on the reference
ROM the script asserts every documented reference address is found, so a ROM
layout change fails loudly instead of silently mis-mapping.

Usage:
  python utilities/scripts/extract_scalars.py <rom.bin> [--rom-id ID] [--out data/maps]
  python utilities/scripts/extract_scalars.py --all    # all stock ROMs + own dump + cross-ROM report
  python utilities/scripts/extract_scalars.py --list
"""
import argparse
import csv
import hashlib
import json
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
STOCK_DIR = REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
OWN_DUMPS = REPO / "binaries" / "dumps"

REFERENCE_ROM = "60E15120_N3J1E"

# Each seed: exact big-endian float32 bits, the address(es) verified in the
# reference ROM 60E15120_N3J1E, and the evidence trail (referencing function /
# literal pointer / RAM cell). Values are decoded from the bits, not restated.
SEEDS = [
    {
        "name": "stoich_afr",
        "bits": "416b3333",
        "ref_addrs": [0x3e7ec],
        "subsystem": "fueling",
        "ram_alias": "diag_afr_word_a_ffffaa6c (lambda->AFR conversion)",
        "evidence": "14.7 stoichiometric AFR literal @0x3e7ec, referenced by mova @0x3e6ec in FUN_0003e560; used as diag_afr_word_a * fVar4 * 14.7 in the fuel-correction/catalyst model (feeds fuel_correction_sum_ffffc644, PID 0x3c). Exactly one occurrence per ROM (verified all 11). This is the single-value 'base AFR' scalar (VersaTuner 'Air Fuel Ratio Base'); per-operating-point AFR lives in maps tbl_06ac88/tbl_069e9c.",
    },
    {
        "name": "fuel_load_scale",
        "bits": "3d935fc4",
        "ref_addrs": [0x78170],
        "subsystem": "fueling",
        "ram_alias": "fuel_load_scale_ffffbed0",
        "evidence": "engine_load * 0.07196 in ref_calcFuelVolumeRequest (0x306e8) via literal pointer 0x30830 -> pool 0x78170; multiplied into final fuel volume beb0 = beac * bed0. Verified in reviews/load_fueling_model/validation.json rom_literal_checks.",
    },
    {
        "name": "load_cell_scale",
        "bits": "3f226e98",
        "ref_addrs": [0x7a088],
        "subsystem": "load",
        "ram_alias": "engine_load_ffffc0b4 (via load_unfiltered_ffffc0b0)",
        "evidence": "air_per_rev * 0.6345 in ref_airPerStroke via literal pointer 0x33b70 -> pool 0x7a088; 0.6345 = 1/(1.308 L * 1.205 g/L) VolEf cell units (ROADMAP D5). Verified in validation.json.",
    },
    {
        "name": "air_per_rev_factor",
        "bits": "42700000",
        "ref_addrs": [0x1a4e8],
        "subsystem": "load",
        "ram_alias": "air_per_rev_ffffaa3c",
        "evidence": "air_per_rev = min(maf * 60.0 / rpm, 5.0) at 0x1a418; 60.0 literal @0x1a4e8 (s/rev conversion). Verified in validation.json.",
    },
    {
        "name": "air_per_rev_clamp",
        "bits": "40a00000",
        "ref_addrs": [0x1a4f4],
        "subsystem": "load",
        "ram_alias": None,
        "evidence": "min(..., 5.0) clamp of air_per_rev at 0x1a418; 5.0 literal @0x1a4f4. Verified in validation.json.",
    },
    {
        "name": "kelvin_offset",
        "bits": "43888000",
        "ref_addrs": [0x1a194],
        "subsystem": "load",
        "ram_alias": None,
        "evidence": "(IAT + 273) in the density/pressure model at 0x2fdb0/0x314d0; 273.0 literal @0x1a194. Verified in validation.json.",
    },
    {
        "name": "kelvin_ref",
        "bits": "43928000",
        "ref_addrs": [0x1a198],
        "subsystem": "load",
        "ram_alias": None,
        "evidence": "293.0/(x+273) Kelvin ratio literal @0x1a198 (0x43928000; corrected from an earlier 295 note 2026-10-29). Verified in validation.json export_doc_fixes.",
    },
    {
        "name": "std_atm_kpa",
        "bits": "42caaa7e",
        "ref_addrs": [0x1a1a0],
        "subsystem": "load",
        "ram_alias": None,
        "evidence": "101.333 kPa standard-atmosphere literal @0x1a1a0 in the baro/density normalization (0x314d0). Verified in validation.json.",
    },
    {
        "name": "baro_scale_kpa",
        "bits": "41ca999a",
        "ref_addrs": [0x7abf8],
        "subsystem": "load",
        "ram_alias": "baro_kpa_ffffad14",
        "evidence": "baro = raw * 25.325 + 0.0182 kPa at 0xd144 -> RAM 0xffffad14; 25.325 literal @0x7abf8 (unique occurrence). Re-read from ROM bytes.",
    },
    {
        "name": "maf_adc_scale",
        "bits": "38a00000",
        "ref_addrs": [0x7310, 0x7418, 0x7490],
        "subsystem": "load",
        "ram_alias": "maf_adc_raw_ffff9eea",
        "evidence": "raw_adc * 5/65536 (0x38a00000) in maf_sensor_scaling 0x7438's literal pool (pool entries 0x7310/0x7418/0x7490). Verified in reviews/fueling/REVIEW_NOTES.md §10.",
    },
    {
        "name": "blend_weight_decay",
        "bits": "3d889a02",
        "ref_addrs": [0x7132c, 0x71330],
        "subsystem": "fueling",
        "ram_alias": "fuel_blend_weight_ffffb11c / timing_blend_weight_ffffb118",
        "evidence": "open-loop blend decay -0.0667/call in 0x200c6; exact bits 0x3d889a02 (not 0x3d888889) @0x7132c/0x71330. Verified in reviews/fueling/REVIEW_NOTES.md §10.",
    },
    {
        "name": "pid0043_load_scale",
        "bits": "3b808080",
        "ref_addrs": [0x55824],
        "subsystem": "diagnostics",
        "ram_alias": "diag22_pid0043_engine_load_g_rev (0x56b8a)",
        "evidence": "engine_load * 1/255 reported as Mode 22 PID 0x43 (0x56b8a); 1/255 = 0x3b808080 @0x55824 (unique). Verified in reviews/fueling/REVIEW_NOTES.md §10 + ROADMAP D5.",
    },
    {
        "name": "injector_flow_primary_cc_min",
        "bits": "43b8bc6a",
        "ref_addrs": [0x78184],
        "subsystem": "fueling",
        "ram_alias": None,
        "evidence": "primary injector flow 369.472 cc/min literal @0x78184 in the per-injector split (0x2fd3e/0x2fea8 chain). Verified in validation.json (0x43b8bc6a_as_literal).",
    },
    {
        "name": "injector_flow_secondary_cc_min",
        "bits": "43edf70a",
        "ref_addrs": [0x7818c, 0x78194],
        "subsystem": "fueling",
        "ram_alias": None,
        "evidence": "secondary injector flow 475.93 cc/min literal @0x7818c/0x78194 (two pool copies) in the per-injector split. Verified in validation.json (0x43edf70a_as_literal).",
    },
]


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def find_pattern(rom: bytes, bits: bytes) -> list[int]:
    addrs = []
    i = rom.find(bits)
    while i != -1:
        addrs.append(i)
        i = rom.find(bits, i + 1)
    return addrs


def fmt_addr(a: int) -> str:
    return f"0x{a:06x}"


def extract_rom(rom: bytes, rom_id: str, rom_path: Path, rom_sha: str, out_dir: Path,
                strict_ref: bool = True) -> dict:
    """Locate every seed's bit pattern in this ROM; write scalars.json/.tsv."""
    scalars = []
    for seed in SEEDS:
        bits = bytes.fromhex(seed["bits"])
        value = struct.unpack(">f", bits)[0]
        addrs = find_pattern(rom, bits)
        if rom_id == REFERENCE_ROM and strict_ref:
            missing = [a for a in seed["ref_addrs"] if a not in addrs]
            if missing:
                raise AssertionError(
                    f"reference ROM {REFERENCE_ROM}: seed {seed['name']} missing "
                    f"documented addresses {[hex(a) for a in missing]} — layout changed?")
        scalars.append({
            "name": seed["name"],
            "value": value,
            "bits_hex": seed["bits"],
            "type": "float32",
            "addresses": [fmt_addr(a) for a in addrs],
            "addresses_int": addrs,
            "ref_addrs": [fmt_addr(a) for a in seed["ref_addrs"]],
            "ref_addrs_confirmed": (all(a in addrs for a in seed["ref_addrs"])
                                    if rom_id == REFERENCE_ROM else None),
            "subsystem": seed["subsystem"],
            "ram_alias": seed["ram_alias"],
            "evidence": seed["evidence"],
        })

    out_dir.mkdir(parents=True, exist_ok=True)
    record = {
        "rom_id": rom_id,
        "rom_path": str(rom_path),
        "rom_sha256": rom_sha,
        "rom_size": len(rom),
        "extracted_at": __import__("datetime").datetime.now(__import__("datetime").timezone.utc).isoformat(),
        "reference_rom": REFERENCE_ROM,
        "note": "Literal-pool float32 scalars (not descriptor tables — see extract_maps.py). "
                "Addresses are every ROM occurrence of the exact bit pattern; ref_addrs are the "
                "addresses binary-verified in the reference ROM. Seeds curated from "
                "docs/investigations/60E15120_N3J1E/reviews/load_fueling_model/validation.json.",
        "total_scalars": len(scalars),
        "scalars": [{k: v for k, v in s.items() if k != "addresses_int"} for s in scalars],
    }
    (out_dir / "scalars.json").write_text(json.dumps(record, indent=2, default=str) + "\n")

    fields = ["name", "value", "bits_hex", "type", "addresses", "ref_addrs",
              "ref_addrs_confirmed", "subsystem", "ram_alias", "evidence"]
    with (out_dir / "scalars.tsv").open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter="\t", extrasaction="ignore")
        w.writeheader()
        for s in scalars:
            row = dict(s)
            row["addresses"] = ";".join(row["addresses"])
            row["ref_addrs"] = ";".join(row["ref_addrs"])
            row.pop("addresses_int", None)
            w.writerow(row)
    return record


def all_roms() -> list[tuple[str, Path]]:
    out = [(p.stem, p) for p in sorted(STOCK_DIR.glob("*.bin"))]
    for p in sorted(OWN_DUMPS.glob("*.bin")):
        out.append((p.stem, p))
    return out


def main():
    ap = argparse.ArgumentParser(description="Extract verified literal-pool scalars from an RX-8 PCM ROM")
    ap.add_argument("rom", nargs="?", help="Path to .bin ROM file")
    ap.add_argument("--rom-id", help="ROM identifier (default: filename stem)")
    ap.add_argument("--out", default=str(REPO / "data" / "maps"), help="Output base directory")
    ap.add_argument("--all", action="store_true", help="Process all stock ROMs + own dump, write cross_rom_scalars.json")
    ap.add_argument("--list", action="store_true", help="List ROMs that --all would process")
    args = ap.parse_args()

    if args.list:
        for rom_id, p in all_roms():
            print(f"{rom_id}  {p}  sha256={sha256_of(p)[:16]}...")
        return

    if args.all:
        maps = Path(args.out)
        cross = {"reference": REFERENCE_ROM, "note":
                 "Per-ROM addresses of each seed scalar's exact float32 bit pattern. "
                 "value is identical wherever present (same bits); 'present' flags ROMs "
                 "where the pattern was not found (layout difference or different cal).",
                 "scalars": {}}
        for rom_id, rom_path in all_roms():
            rom = rom_path.read_bytes()
            rec = extract_rom(rom, rom_id, rom_path, sha256_of(rom_path), maps / rom_id)
            print(f"{rom_id}: {rec['total_scalars']} scalars -> {maps / rom_id / 'scalars.json'}")
            for s in rec["scalars"]:
                entry = cross["scalars"].setdefault(s["name"], {
                    "value": s["value"], "bits_hex": s["bits_hex"], "type": s["type"],
                    "subsystem": s["subsystem"], "ram_alias": s["ram_alias"],
                    "evidence": s["evidence"], "per_rom": {}})
                entry["per_rom"][rom_id] = {
                    "present": bool(s["addresses"]),
                    "addresses": s["addresses"],
                    "rom_sha256": rec["rom_sha256"],
                }
                if rom_id == REFERENCE_ROM:
                    entry["ref_addrs"] = s["ref_addrs"]
        (maps / "cross_rom_scalars.json").write_text(json.dumps(cross, indent=2, default=str) + "\n")
        print(f"\nCross-ROM report: {maps / 'cross_rom_scalars.json'}")
        return

    if not args.rom:
        ap.error("rom path required (or use --all / --list)")
    rom_path = Path(args.rom)
    if not rom_path.exists():
        alt = STOCK_DIR / rom_path.name
        if alt.exists():
            rom_path = alt
        else:
            ap.error(f"ROM not found: {args.rom}")
    rom_id = args.rom_id or rom_path.stem
    rom = rom_path.read_bytes()
    rec = extract_rom(rom, rom_id, rom_path, sha256_of(rom_path), Path(args.out) / rom_id)
    print(f"ROM {rom_id}: {rec['total_scalars']} scalars -> {Path(args.out) / rom_id / 'scalars.json'}")
    for s in rec["scalars"]:
        print(f"  {s['name']:<32} {s['value']!r:<24} {s['bits_hex']}  at {', '.join(s['addresses'][:6])}"
              + (" ..." if len(s["addresses"]) > 6 else ""))


if __name__ == "__main__":
    main()
