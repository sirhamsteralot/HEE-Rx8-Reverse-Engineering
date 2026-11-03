# data/

Machine-readable artifacts extracted from (or describing) HEE binaries.

## Layout

- `definitions/` — ECU tuning definitions (RomRaider/ECUFlash XML): per-ROM defs, the
  reviewed merged 60E15120 def, upstream snapshots. See
  [`definitions/README.md`](definitions/README.md) for layout, provenance and the
  D8 dedupe record.
- `labels/<rom-id>/` — label/alias records for a ROM: `calibration_labels.tsv`,
  `*_labels.json`, `integrated_names.json`, `accepted_*_aliases.tsv`, `input.json`
  (ROM hash/IDs), `validation.json` records, export logs. `CAL_DTC_xxxx_…` rows keep the upstream XML name in
  `original_name`; the defs use the standard OBD code (`DTC P0420 Enable/Disable #1`) — mapping in [`dtc/pcodes.tsv`](dtc/pcodes.tsv).
- `dtc/` — extracted DTC tables per ROM (`<rom-id>.tsv`, with the standard 5-char
  `obd_code`), the defs audit (`defs_audit.tsv`), the code→OBD-code mapping with SAE
  J2012 + Mazda workshop-manual descriptions (`pcodes.tsv`), and the parsed Mazda
  manual DTC table (`mazda_dtc_table.tsv`); see [`dtc/README.md`](dtc/README.md).
- `logs/` — real-car data logs (see [`logs/README.md`](logs/README.md)): `nr666p/` (VersaTuner),
  `rx8-666p/` (OBD-II PIDs). Golden fixtures for the emulator's virtual OBD port.
- `tunes/` — third-party tune artifacts (see [`tunes/README.md`](tunes/README.md)): `.vtune`
  containers, tune notes and table pastes. Context only, never flashed.

## Rules

- Definition edits must cite evidence (unique ROM data/axis-pointer match, descriptor
  dispatch/wrapper calls); repairs target one ROM — never generalize across
  calibration blocks. XML defs are editor metadata; ROM addresses/bytes are never
  changed by definition work.
- One artifact per file, `kebab-case`, with a header comment or sidecar meta file
  stating source binary SHA-256 (from `binaries/manifest.csv`), address range, and
  extraction method. Exact values, units noted.
- No personal data (VINs); redact and document.
