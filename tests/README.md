# tests/

Verification harness proving that reimplemented behavior matches the original HEE
binary's observed behavior.

## Ideas

- Unit tests for reimplemented functions in `reverse-engineered/reimplementation/`,
  with golden inputs/outputs captured from the original (address + binary hash noted).
- Round-trip tests: checksum/CRC implementations vs. known-good values from dumps.
- Map/table extraction tests: re-extract from binary and diff against `data/`.

## Rules

- Tests must state which binary SHA-256 (from `binaries/manifest.csv`) they were
  validated against.
- Golden data goes in `tests/fixtures/` with provenance comments.
- Run with `python -m pytest tests/` from the repo root.
