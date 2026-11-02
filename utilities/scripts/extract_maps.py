#!/usr/bin/env python3
"""Extract all lookup-table descriptors from an RX-8 PCM ROM into data/maps/.

Scans the ROM for 2D and 3D Denso lookup descriptors and dumps every table
(axis + data) to data/maps/<rom-id>/ as JSON (full fidelity) + CSV (human
readable) + a TSV index. Records the source ROM SHA-256 in the manifest.

Descriptor formats (big-endian, verified against ROM bytes and lookup code):
  2D base (12 B, >HBBII):  n:u16  type:u8  reserved:u8  axis_ptr:u32  data_ptr:u32
  2D scaled (20 B):        base + multiplier:f32 + offset:f32
  3D base (20 B, >HHIIIB+pad): nx:u16 ny:u16 ax:u32 ay:u32 data:u32 type:u8 pad:3
  3D scaled (28 B):        base + multiplier:f32 + offset:f32

Type codes (dispatch tables 0x2098/0x210c -> handler names in symbols.tsv):
  0 = float32 (4 B)   4 = uint8 (1 B)   8 = uint16 (2 B)   12 = int8 (1 B)   16 = int16 (2 B)

Companion: extract_scalars.py locates literal-pool scalar constants (not
descriptor tables) into data/maps/<rom-id>/scalars.{json,tsv}.

Usage:
  python utilities/scripts/extract_maps.py <rom.bin> [--rom-id ID] [--out data/maps]
  python utilities/scripts/extract_maps.py --list   # list stock ROMs in the submodule
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

ROM_END = 0x80000     # 512 KiB


def detect_cal_start(rom: bytes) -> int:
    """Auto-detect cal region start via the 'Copr.DENSO' header string.

    Every ROM has a cal header block containing 'Copr.DENSO' (e.g. 0x6c034
    in 60E15120, 0x6d339 in 60E0FB00, 0x71539 in 60E32000). The 0x1000-aligned
    block containing the first match above 0x60000 is the cal region start.
    """
    import re
    for m in re.finditer(rb'Copr\.DENSO', rom):
        addr = m.start()
        if addr > 0x60000:
            return addr & ~0xFFF
    return 0x6C000  # fallback for known layout


TYPE_NAMES = {0: "float32", 4: "uint8", 8: "uint16", 12: "int8", 16: "int16"}
TYPE_SIZES = {0: 4, 4: 1, 8: 2, 12: 1, 16: 2}
VALID_TYPES = set(TYPE_NAMES.keys())


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def read_axis_f32(rom: bytes, addr: int, count: int) -> list[float]:
    return [struct.unpack_from(">f", rom, addr + i * 4)[0] for i in range(count)]


def read_data(rom: bytes, addr: int, count: int, type_code: int) -> list:
    fmt, size = {0: (">f", 4), 4: (">B", 1), 8: (">H", 2), 12: (">b", 1), 16: (">h", 2)}[type_code]
    return [struct.unpack_from(fmt, rom, addr + i * size)[0] for i in range(count)]


def read_data_2d(rom: bytes, addr: int, nx: int, ny: int, type_code: int) -> list[list]:
    """Read 3D table data as rows (ny rows of nx elements)."""
    fmt, size = {0: (">f", 4), 4: (">B", 1), 8: (">H", 2), 12: (">b", 1), 16: (">h", 2)}[type_code]
    rows = []
    for y in range(ny):
        row = [struct.unpack_from(fmt, rom, addr + (y * nx + x) * size)[0] for x in range(nx)]
        rows.append(row)
    return rows


def is_monotonic(vals: list[float]) -> bool:
    return all(vals[i] <= vals[i + 1] for i in range(len(vals) - 1))


def scan_descriptors(rom: bytes, cal_start: int) -> list[dict]:
    """Scan for all valid 2D/3D descriptors in the ROM."""
    found = []
    scan_start = max(0x40, cal_start - 0x8000)  # descriptors live up to 32KB before cal data
    scan_end = cal_start
    for addr in range(scan_start, scan_end, 4):
        b = rom[addr:addr + 20]
        if len(b) < 12:
            break

        # Try 3D first (more specific: has type at offset 16 + zero pad)
        is_3d = False
        is_2d = False
        if len(b) >= 20:
            nx, ny = struct.unpack_from(">HH", b, 0)
            ax, ay, dp = struct.unpack_from(">III", b, 4)
            typ = b[16]
            pad = b[17:20]
            if (1 <= nx <= 256 and 1 <= ny <= 256 and typ in VALID_TYPES
                    and pad == b"\x00\x00\x00"
                    and cal_start <= ax < ROM_END and cal_start <= ay < ROM_END
                    and cal_start <= dp < ROM_END
                    and ax + nx * 4 <= ROM_END and ay + ny * 4 <= ROM_END
                    and dp + nx * ny * TYPE_SIZES[typ] <= ROM_END):
                is_3d = True

        # Try 2D: reserved byte must be 0, type in valid set
        n, typ2, res = struct.unpack_from(">HBB", b, 0)
        axis, dp2 = struct.unpack_from(">II", b, 4)
        if (res == 0 and typ2 in VALID_TYPES and 1 <= n <= 1024
                and cal_start <= axis < ROM_END and cal_start <= dp2 < ROM_END
                and axis + n * 4 <= ROM_END and dp2 + n * TYPE_SIZES[typ2] <= ROM_END):
            is_2d = True

        if is_3d and not is_2d:
            nx, ny = struct.unpack_from(">HH", b, 0)
            ax, ay, dp = struct.unpack_from(">III", b, 4)
            typ = b[16]
            # Check for scaled variant (multiplier+offset after base)
            scaled = False
            if addr + 28 <= len(rom):
                mult, off = struct.unpack_from(">ff", rom, addr + 20)
                # Heuristic: scaled if the next 8 bytes look like reasonable float scale/offset
                if abs(mult) < 1e6 and abs(off) < 1e6 and (mult != 0.0 or off != 0.0):
                    scaled = True
            found.append({
                "descriptor": addr, "dimension": 3, "nx": nx, "ny": ny,
                "axis_x": ax, "axis_y": ay, "data": dp, "type_code": typ,
                "scaled": scaled, "raw_hex": b[:20].hex(),
            })
        elif is_2d and not is_3d:
            n, typ2, res = struct.unpack_from(">HBB", b, 0)
            axis, dp2 = struct.unpack_from(">II", b, 4)
            # Check for scaled variant
            scaled = False
            if addr + 20 <= len(rom):
                mult, off = struct.unpack_from(">ff", rom, addr + 12)
                if abs(mult) < 1e6 and abs(off) < 1e6 and (mult != 0.0 or off != 0.0):
                    scaled = True
            found.append({
                "descriptor": addr, "dimension": 2, "n": n,
                "axis": axis, "data": dp2, "type_code": typ2,
                "scaled": scaled, "raw_hex": b[:12].hex(),
            })
        # If both match, prefer 3D (the 2D parse of a 3D descriptor has res != 0
        # in almost all cases; if res==0 and type matches, it's genuinely ambiguous
        # but rare — skip to avoid duplicates, log it)
        elif is_2d and is_3d:
            found.append({
                "descriptor": addr, "dimension": "ambiguous", 
                "raw_hex": b[:20].hex(),
            })

    return found


def extract_table(rom: bytes, desc: dict) -> dict | None:
    """Extract axis + data values for a descriptor. Returns None if invalid."""
    d = dict(desc)
    d["type_name"] = TYPE_NAMES.get(d["type_code"], "unknown")
    d["elem_size"] = TYPE_SIZES.get(d["type_code"], 0)

    if d["dimension"] == 2:
        n = d["n"]
        try:
            d["axis_values"] = read_axis_f32(rom, d["axis"], n)
            d["data_values"] = read_data(rom, d["data"], n, d["type_code"])
        except struct.error:
            return None
        d["axis_monotonic"] = is_monotonic(d["axis_values"])
        d["data_bytes"] = n * d["elem_size"]
        d["axis_bytes"] = n * 4
    elif d["dimension"] == 3:
        nx, ny = d["nx"], d["ny"]
        try:
            d["axis_x_values"] = read_axis_f32(rom, d["axis_x"], nx)
            d["axis_y_values"] = read_axis_f32(rom, d["axis_y"], ny)
            d["data_values"] = read_data_2d(rom, d["data"], nx, ny, d["type_code"])
        except struct.error:
            return None
        d["axis_x_monotonic"] = is_monotonic(d["axis_x_values"])
        d["axis_y_monotonic"] = is_monotonic(d["axis_y_values"])
        d["data_bytes"] = nx * ny * d["elem_size"]
        d["axis_x_bytes"] = nx * 4
        d["axis_y_bytes"] = ny * 4
    else:
        return None

    return d


def fmt_addr(a: int) -> str:
    return f"0x{a:06x}"


def write_outputs(tables: list[dict], rom_path: Path, rom_id: str, rom_sha: str, out_dir: Path):
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "tables").mkdir(exist_ok=True)

    index_rows = []
    for t in tables:
        desc_addr = t["descriptor"]
        name = f"tbl_{desc_addr:06x}"
        # JSON: full fidelity
        json_path = out_dir / "tables" / f"{name}.json"
        json_path.write_text(json.dumps(t, indent=2, default=str) + "\n")

        # CSV: human readable
        csv_path = out_dir / "tables" / f"{name}.csv"
        with csv_path.open("w", newline="") as f:
            w = csv.writer(f)
            if t["dimension"] == 2:
                w.writerow(["axis", "value"])
                for a, v in zip(t["axis_values"], t["data_values"]):
                    w.writerow([a, v])
            else:
                # 3D: header row = X axis, first col = Y axis
                w.writerow(["y\\x"] + t["axis_x_values"])
                for yi, row in enumerate(t["data_values"]):
                    w.writerow([t["axis_y_values"][yi]] + row)

        if t["dimension"] == 2:
            index_rows.append({
                "name": name,
                "descriptor": fmt_addr(desc_addr),
                "dimension": 2,
                "count": t["n"],
                "type": t["type_name"],
                "axis_addr": fmt_addr(t["axis"]),
                "data_addr": fmt_addr(t["data"]),
                "axis_monotonic": t["axis_monotonic"],
                "scaled": t["scaled"],
            })
        else:
            index_rows.append({
                "name": name,
                "descriptor": fmt_addr(desc_addr),
                "dimension": 3,
                "count": f"{t['nx']}x{t['ny']}",
                "type": t["type_name"],
                "axis_x_addr": fmt_addr(t["axis_x"]),
                "axis_y_addr": fmt_addr(t["axis_y"]),
                "data_addr": fmt_addr(t["data"]),
                "axis_x_monotonic": t["axis_x_monotonic"],
                "axis_y_monotonic": t["axis_y_monotonic"],
                "scaled": t["scaled"],
            })

    # TSV index (unified field set for 2D + 3D)
    if index_rows:
        fields = ["name", "descriptor", "dimension", "count", "type",
                  "axis_addr", "axis_x_addr", "axis_y_addr", "data_addr",
                  "axis_monotonic", "axis_x_monotonic", "axis_y_monotonic", "scaled"]
        with (out_dir / "index.tsv").open("w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=fields, delimiter="	", extrasaction="ignore")
            w.writeheader()
            w.writerows(index_rows)

    # Manifest
    manifest = {
        "rom_id": rom_id,
        "rom_path": str(rom_path),
        "rom_sha256": rom_sha,
        "rom_size": len(rom_path.read_bytes()),
        "extracted_at": __import__("datetime").datetime.now(__import__("datetime").timezone.utc).isoformat(),
        "total_tables": len(tables),
        "by_dimension": {
            "2D": sum(1 for t in tables if t["dimension"] == 2),
            "3D": sum(1 for t in tables if t["dimension"] == 3),
        },
        "by_type": {},
        "ambiguous": sum(1 for t in tables if t["dimension"] == "ambiguous"),
        "non_monotonic_axes": sum(
            1 for t in tables
            if t["dimension"] == 2 and not t.get("axis_monotonic", True)
        ) + sum(
            1 for t in tables
            if t["dimension"] == 3 and not (t.get("axis_x_monotonic", True) and t.get("axis_y_monotonic", True))
        ),
    }
    for t in tables:
        tn = t.get("type_name", "unknown")
        manifest["by_type"][tn] = manifest["by_type"].get(tn, 0) + 1

    (out_dir / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    return manifest


def main():
    ap = argparse.ArgumentParser(description="Extract lookup tables from an RX-8 PCM ROM")
    ap.add_argument("rom", nargs="?", help="Path to .bin ROM file")
    ap.add_argument("--rom-id", help="ROM identifier (default: filename stem)")
    ap.add_argument("--out", default=str(REPO / "data" / "maps"), help="Output base directory")
    ap.add_argument("--list", action="store_true", help="List stock ROMs in submodule")
    args = ap.parse_args()

    if args.list:
        for p in sorted(STOCK_DIR.glob("*.bin")):
            print(f"{p.stem}  ({p.stat().st_size} bytes)  sha256={sha256_of(p)[:16]}...")
        return

    if not args.rom:
        ap.error("rom path required (or use --list)")

    rom_path = Path(args.rom)
    if not rom_path.exists():
        # Try resolving via submodule
        alt = STOCK_DIR / rom_path.name
        if alt.exists():
            rom_path = alt
        else:
            ap.error(f"ROM not found: {args.rom}")

    rom_id = args.rom_id or rom_path.stem
    rom = rom_path.read_bytes()
    rom_sha = sha256_of(rom_path)

    print(f"ROM: {rom_path}")
    print(f"  id={rom_id}  size={len(rom)} (0x{len(rom):x})  sha256={rom_sha}")

    cal_start = detect_cal_start(rom)
    print(f"  cal region starts at 0x{cal_start:06x}")
    descs = scan_descriptors(rom, cal_start)
    # Resolve overlaps: descriptors are packed consecutively; if one starts
    # inside another span, the later one is a false positive.
    descs.sort(key=lambda d: d["descriptor"])
    resolved = []
    next_free = 0
    for d in descs:
        if d["descriptor"] < next_free:
            continue
        span = 20 if d["dimension"] == 3 else 12  # base span; scaled variants handled by scanning every 4B
        next_free = d["descriptor"] + span
        resolved.append(d)
    dropped = len(descs) - len(resolved)
    if dropped:
        print(f"Dropped {dropped} overlapping false positives")
    descs = resolved
    print(f"Scanned up to 0x{cal_start:05x}: {len(descs)} candidate descriptors")

    tables = []
    skipped = 0
    for d in descs:
        t = extract_table(rom, d)
        if t is None:
            skipped += 1
            continue
        tables.append(t)

    tables.sort(key=lambda t: t["descriptor"])
    print(f"Extracted {len(tables)} tables ({skipped} skipped)")

    out_dir = Path(args.out) / rom_id
    manifest = write_outputs(tables, rom_path, rom_id, rom_sha, out_dir)
    print(f"\nOutput: {out_dir}")
    print(f"  2D: {manifest['by_dimension']['2D']}  3D: {manifest['by_dimension']['3D']}  "
          f"ambiguous: {manifest['ambiguous']}  non-monotonic: {manifest['non_monotonic_axes']}")
    print(f"  by type: {manifest['by_type']}")
    print(f"  manifest: {out_dir / 'manifest.json'}")

    # Show first/last few
    print("\nFirst 5:")
    for t in tables[:5]:
        if t["dimension"] == 2:
            print(f"  2D {fmt_addr(t['descriptor'])} n={t['n']} type={t['type_name']} "
                  f"axis={fmt_addr(t['axis'])} data={fmt_addr(t['data'])} mono={t['axis_monotonic']}")
        elif t["dimension"] == 3:
            print(f"  3D {fmt_addr(t['descriptor'])} {t['nx']}x{t['ny']} type={t['type_name']} "
                  f"ax={fmt_addr(t['axis_x'])} ay={fmt_addr(t['axis_y'])} data={fmt_addr(t['data'])}")
        else:
            print(f"  ??? {fmt_addr(t['descriptor'])} {t['raw_hex']}")
    print("Last 5:")
    for t in tables[-5:]:
        if t["dimension"] == 2:
            print(f"  2D {fmt_addr(t['descriptor'])} n={t['n']} type={t['type_name']} "
                  f"axis={fmt_addr(t['axis'])} data={fmt_addr(t['data'])} mono={t['axis_monotonic']}")
        elif t["dimension"] == 3:
            print(f"  3D {fmt_addr(t['descriptor'])} {t['nx']}x{t['ny']} type={t['type_name']} "
                  f"ax={fmt_addr(t['axis_x'])} ay={fmt_addr(t['axis_y'])} data={fmt_addr(t['data'])}")


if __name__ == "__main__":
    main()
