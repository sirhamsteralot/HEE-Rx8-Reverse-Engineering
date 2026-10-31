# binaries/

Immutable dumps of the HEE target (Mazda RX-8 PCM). Nothing here is ever
edited, patched, or "fixed" in place.

## What lives where

- **Upstream stock ROMs and prior captures are NOT duplicated here** — they live in
  the read-only submodule `submodules/Mazda_RX8_PCM_ReverseEngineering`
  (pinned at `492193ba8548869b91915be55133d85ab7a8722a`):
  - `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/` — 10 stock ROMs,
    upstream `<firmware-id>_<cal-id>.bin` names (e.g. `60E15120_N3J1E.bin`,
    SHA-256 `a7cd953c…`, see `data/labels/60E15120_N3J1E/input.json`)
  - `submodules/Mazda_RX8_PCM_ReverseEngineering/Data_binaries/` — RAM capture,
    EEPROM dump, immobilizer IC read, and a `60E0FC00.bin` copy (byte-identical
    to the stock ROM)
- **`binaries/` itself is for our own acquisitions only** (new dumps from our own
  units), with `manifest.csv` = SHA-256 + provenance for every file.

## Naming conventions

- Own acquisitions: `<source>-<version>-<date>.<ext>`, e.g. `bench-ecu-v2-2026-11-02.bin`.
- If an own acquisition is byte-identical to a submodule file, reference the
  submodule path instead of duplicating it.

## Rules

- Regenerate the manifest after adding files:
  `python ../utilities/scripts/hash_binaries.py` (writes `manifest.csv`),
  `python ../utilities/scripts/hash_binaries.py --check` (verify only).
  Fill in `source` / `acquired_with` / `date` columns by hand; the script preserves them.
- `.bin` files go through Git LFS (`.gitattributes`). Very large captures may stay
  out of git with only their SHA-256 in the manifest.
- Redact personal data (VINs) from any derived file; note redactions in the
  investigation doc.
