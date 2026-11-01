# data/

Machine-readable artifacts extracted from (or describing) HEE binaries.

## Layout

- `definitions/` — ECU tuning definitions; see [`definitions/README.md`](definitions/README.md)
  for provenance, upstream commit citations, per-ROM defs and the D8 dedupe record.
  Upstream originals live in `submodules/RX8Defs/` (pinned `1b3aea2…`); local copies
  exist only where they differ from the pinned tree.
  - `definitions/romraider/per-rom/` — one standalone RomRaider def per dumped ROM (all 14; generated, see `coverage.json`).
  - `definitions/romraider/upstream-rx8defs/` — upstream `equinox311/RX8Defs` RomRaider defs snapshot @ `ff5ab4f` (merge base).
  - `definitions/romraider/reviewed-rx8defs-copy/` — locally reviewed defs from the prior effort's working copy.
  - `definitions/romraider/rx8defs-merged-60E15120.xml` — merged/reviewed definition for ROM `60E15120_N3J1E` (merge records in `docs/investigations/60E15120_N3J1E/defs-merge/`).
- `labels/<rom-id>/` — label/alias records for a ROM: `calibration_labels.tsv`,
  `*_labels.json`, `integrated_names.json`, `accepted_*_aliases.tsv`, `input.json`
  (ROM hash/IDs), `validation.json` records, export logs.
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
