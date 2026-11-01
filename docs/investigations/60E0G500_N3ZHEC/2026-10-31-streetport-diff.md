# Investigation: streetport tuned ROMs vs stock base — 60E0G500 / N3ZHEC

- **Date:** 2026-10-31
- **Status:** done (byte-level); function mapping pending disassembly of 60E0G500
  — resolved 2026-10-31 by [2026-10-31-pipeline-export.md](2026-10-31-pipeline-export.md);
  cross-ROM names applied to the export 2026-11-01 (ROADMAP D item 3, see
  [cross_rom_mode22_pid_handlers.md](../60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md))
- **Inputs (SHA-256 in `binaries/manifest.csv`):**
  - base: `binaries/dumps/aron-N3ZHEC-2026-10-31.bin` (stock, fw `60E0G500`, cal `N3ZHEC`)
  - tuned: `aron-N3ZHEC-streetportv1_24_approx_{5500,9500,10000}max-2026-10-31.bin`
    (user-tuned "streetport v1.24" variants; per `data/tunes/aron/README.txt` the
    5500max one is the one to flash)

## Findings

1. **The tune is calibration-only — zero code bytes changed.** All 3 tuned ROMs
   differ from stock exclusively at addresses ≥ 0x6c000 (the descriptor/calibration
   region per `docs/architecture/design/README.md` §1): 1,198–1,412 bytes each.
   No code patch, no code cave — safe class of modification.
2. **Rev limiter location:** the three variants differ from each other in only
   2 bytes at **0x6d54d–0x6d54e**, inside a float32 BE at **0x6d54c**:
   - stock: `0x460CA000` = **9000.0**
   - 5500max: `0x45ABE000` ≈ **5488** (≈5500 rpm)
   - 9500max: `0x46147000` ≈ **9488** (≈9500 rpm)
   - 10000max: `0x461C4000` ≈ **9993** (≈10000 rpm)
   → the "approx_Nmax" in the filenames is this float32 rev-limit calibration at
   0x6d54c. (For comparison, the RX8Club patcher found the rev-limit cal at 0x6da4c
   in 60E0FC00 — per-ROM address, as expected.)
   5500max vs 9500/10000max differ in 218 bytes across 0x6d54c–0x72af2 (knock/timing/
   fuel maps around the new limiter); 9500 vs 10000 differ only in the limiter word.
3. **Thread inline defs verified against this ROM:** all 19 `<table>` addresses in
   `docs/references/rx8club-inline-defs.tsv` (posted for N3ZHEC) contain plausible
   data in `aron-N3ZHEC-2026-10-31.bin` — e.g. fan enable ECT `0x42C20000` = 96.0 °C,
   hysteresis `0x40400000` = 3.0, lambda rich/lean limits ≈ 0.85/1.05
   (`0x3F59999A`/`0x3F866666`), CL fuel-correction tables of repeating 0x27/0x23
   bytes. The TSV is a trustworthy cross-check source for this ROM.

## Open questions / next steps

- Map the changed cal ranges to table descriptors (parse descriptors in
  0x6c000–0x7ffff) and name them via the 60E0G500 XML defs — note the pinned
  `submodules/RX8Defs` has a **newer** `ECUFlash/60E0G500.xml` (63,606 B, 1,210
  tables) than our copied one (61,849 B, 1,210 tables, older commit).
- Run the pipeline against 60E0G500 to get function labels (currently only
  60E15120_N3J1E is labeled); then map 0x6d54c's consumer (rev-limit function).
- Emulator profile `60E0G500_N3ZHEC` added (`utilities/scripts/emu/profiles/`).

## Evidence

Byte diffs computed 2026-10-31 by direct comparison of the four ROMs (script inline
in session); hashes in `binaries/manifest.csv`; thread addresses in
`docs/references/rx8club-inline-defs.tsv`.
