#!/usr/bin/env python3
"""Generate or verify binaries/manifest.csv (SHA-256 provenance for dumps).

Usage:
    python utilities/scripts/hash_binaries.py           # rewrite manifest.csv
    python utilities/scripts/hash_binaries.py --check   # verify manifest matches files

Scans binaries/ for files (skipping README.md and manifest.csv itself) and records
filename, size, sha256, plus optional source/acquired_with/date columns which you can
fill in manually afterwards -- the script preserves existing values for known files.
"""
import csv
import hashlib
import sys
from pathlib import Path

BINARIES_DIR = Path(__file__).resolve().parents[2] / "binaries"
MANIFEST = BINARIES_DIR / "manifest.csv"
SKIP = {"README.md", "manifest.csv"}
HEADER = ["filename", "size_bytes", "sha256", "source", "acquired_with", "date"]


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def existing_rows() -> dict:
    if not MANIFEST.exists():
        return {}
    with MANIFEST.open(newline="", encoding="utf-8") as f:
        return {row["filename"]: row for row in csv.DictReader(f)}


def main() -> int:
    check_only = "--check" in sys.argv[1:]
    old = existing_rows()
    files = sorted(p for p in BINARIES_DIR.iterdir() if p.is_file() and p.name not in SKIP)

    rows = []
    for p in files:
        prev = old.get(p.name, {})
        rows.append({
            "filename": p.name,
            "size_bytes": p.stat().st_size,
            "sha256": sha256_of(p),
            "source": prev.get("source", ""),
            "acquired_with": prev.get("acquired_with", ""),
            "date": prev.get("date", ""),
        })

    if check_only:
        problems = []
        for row in rows:
            prev = old.get(row["filename"])
            if prev is None:
                problems.append(f"{row['filename']}: not in manifest")
            elif prev.get("sha256") != row["sha256"] or prev.get("size_bytes") != str(row["size_bytes"]):
                problems.append(f"{row['filename']}: hash/size mismatch vs manifest")
        for name in old:
            if name not in {r["filename"] for r in rows}:
                problems.append(f"{name}: in manifest but missing from binaries/")
        if problems:
            print("manifest check FAILED:")
            for p in problems:
                print(" -", p)
            return 1
        print(f"manifest OK ({len(rows)} file(s))")
        return 0

    with MANIFEST.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=HEADER)
        w.writeheader()
        w.writerows(rows)
    print(f"wrote {MANIFEST} ({len(rows)} file(s))")
    return 0


if __name__ == "__main__":
    sys.exit(main())
