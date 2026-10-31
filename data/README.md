# data/

Machine-readable artifacts extracted from the HEE binaries. Data lives here, not
buried in prose, so it can be diffed, graphed, and consumed by utilities.

## Suggested layout

- `maps/` — fuel, ignition, boost, and other lookup tables (CSV/JSON + axis definitions).
- `tables/` — DTC lists, PID/UDS service IDs, routine IDs, scaling formulas.
- `strings/` — extracted string tables with addresses.
- `checksums/` — checksum/CRC parameters and seed-key algorithm constants discovered.

## Rules

- One artifact per file, `kebab-case`, with a short header comment (or sidecar
  `<name>.meta.md`) stating source binary SHA-256, address range, and extraction method.
- Prefer JSON or CSV; keep values exact (no rounding) and note units.
- Never include personal data (VINs etc.); redact and document the redaction.
