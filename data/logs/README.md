# data/logs/

Real-car data logs (golden fixtures for the emulator's virtual OBD port and for
validating static findings against observed behavior).

## Layout

- `nr666p/` — VersaTuner logs from Yannick's NR666P RX-8 (CSV columns: absolute
  load, actual/desired λ, coolant temp, RPM, leading/trailing timing advance,
  IAT, knock retard, LTFT) + one raw `.vtlog` (Git LFS).
- `rx8-666p/` — OBD-II generic PID logs from the "666p" RX-8 (AFR measured, ECT,
  engine load %, RPM, IAT, MAF g/s, O2 λ, relative throttle %, timing advance).

Files duplicated across the two source zips were deduplicated by SHA-256.

## Rules

- One log per file, original filename kept; provenance (car, tool, date) in a
  sidecar note or the investigation doc. `.vtlog`/large logs go through Git LFS.
- No personal data (VINs etc.); redact if present.
- Use as golden inputs for `utilities/scripts/emu/` runs (see
  `docs/architecture/emulated-obd.md`).
