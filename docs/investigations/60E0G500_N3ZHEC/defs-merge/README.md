# 60E0G500 / N3ZHEC — ECU definition mapping (ROADMAP D item 4) — 2026-11-01

Which tuning definitions apply to the four 60E0G500 dumps in `binaries/dumps/`
(stock `aron-N3ZHEC-2026-10-31.bin`, SHA-256 `a33f79a4…` per
`binaries/manifest.csv`, fw id `60E0G500` at 0x2000; plus the three
streetport-v1.24 tuned variants). Cross-ROM method and results for all 14 ROMs:
[`../60E15120_N3J1E/cross_ecu/cross_rom_defs_coverage.md`](../../60E15120_N3J1E/cross_ecu/cross_rom_defs_coverage.md);
machine-readable record: [`data/definitions/coverage.json`](../../../../data/definitions/coverage.json).

## Applicable definitions

- **RomRaider**: upstream block `60E0G500` (base `Rx8Base` → `RX8Base`, 1052
  tables) in `submodules/RX8Defs/RomRaider/rx8_defs.xml` @ pinned
  `1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc` — block has **814** top-level tables.
  Standalone per-ROM defs emitted:
  `data/definitions/romraider/per-rom/aron-N3ZHEC-2026-10-31.xml` (stock) and one
  per tuned variant (same block; tuned tables may have moved — verify per-table
  against the ROM before any write).
- **ECUFlash**: `submodules/RX8Defs/ECUFlash/60E0G500.xml` @ `1b3aea2…`
  (**1210 tables**, last upstream change `aaac6f3` 2023-08-11, blob
  `c4a3c37e41eddc1e92c29716b087bb9d9c2090fd`) + `ECUFlash/RX8BASE.xml`
  (1743 tables, blob `05a7943e…`). Referenced in place — our former local copies
  under `data/definitions/ecuflash/` were blob-identical to the pinned submodule
  (CRLF/LF-only raw difference) and were deleted 2026-11-01 under AGENTS.md rule 4b
  (register item **D8**, closed). See [`data/definitions/README.md`](../../../../data/definitions/README.md).

## Validation

See [validation.json](validation.json) (generated 2026-11-01 by
`utilities/scripts/defs-merge/extend_defs_all_roms.py` + this check): fw id at
0x2000 of each dump, manifest hash match, emitted XML re-parse with block/table
counts, all `storageaddress` within 0x2000–0x7ffff or the 0x000000 placeholder,
ECUFlash table count 1210, dedupe blob evidence.

No ROM byte or submodule file was modified; defs are editor metadata only.
