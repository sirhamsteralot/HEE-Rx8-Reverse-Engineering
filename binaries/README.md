# binaries/

Immutable firmware dumps and captures of the HEE target (Mazda RX-8 PCM).
Nothing here is ever edited, patched, or "fixed" in place.

## Layout

- `stock-roms/` — full 512 KiB PCM flash dumps. **Upstream names are kept**
  (`<firmware-id>_<cal-id>.bin`, e.g. `60E15120_N3J1E.bin`) so they match the
  RomRaider XML definitions.
- `captures/` — smaller reads: RAM captures, EEPROM dumps, immobilizer IC reads.
- `manifest.csv` — SHA-256 + size + provenance for every file, recursive.

## Naming conventions

- Stock ROMs: keep the upstream `<firmware-id>_<cal-id>.bin` name.
- Captures and any new acquisition: `<source>-<version>-<date>.<ext>`,
  e.g. `bench-ecu-v2-2026-11-02.bin`.

## Rules

- Regenerate the manifest after adding files:
  `python ../utilities/scripts/hash_binaries.py` (writes `manifest.csv`),
  `python ../utilities/scripts/hash_binaries.py --check` (verify only).
  Fill in `source` / `acquired_with` / `date` columns by hand; the script preserves them.
- Known duplicate: `Data_binaries/60E0FC00.bin` in the prior workspace was
  byte-identical (SHA-256 `476ddcbe…`) to `stock-roms/60E0FC00.bin`, so only the
  stock-roms copy is kept.
- `.bin` files go through Git LFS (`.gitattributes`). Very large captures may stay
  out of git with only their SHA-256 in the manifest.
- Redact personal data (VINs) from any derived file; note redactions in the
  investigation doc.
