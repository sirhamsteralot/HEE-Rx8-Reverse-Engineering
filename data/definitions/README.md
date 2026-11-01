# data/definitions/ — ECU tuning definitions (RomRaider + ECUFlash XML)

Editor metadata only: nothing here changes ROM bytes (AGENTS.md rule 2). All
upstream originals live in the read-only submodule `submodules/RX8Defs`
(equinox311/RX8Defs), pinned at **`1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc`**
("Fixed 60E1D400 DTC defs", 2026-10-20). We keep local copies only where they
differ from the pinned tree (see "D8 dedupe" below); everything else is
referenced by submodule path + commit.

## Layout

- `romraider/per-rom/<rom-stem>.xml` — **one standalone RomRaider definition per
  dumped ROM** (14 ROMs: `binaries/dumps/*.bin` + `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/*.bin`).
  Each file carries its base chain (RX8Base + intermediates) plus the ROM's
  `<rom>` block and a provenance comment (ROM SHA-256, fw id at 0x2000, block
  source, upstream commit). Generated 2026-11-01 by
  [`utilities/scripts/defs-merge/extend_defs_all_roms.py`](../../utilities/scripts/defs-merge/extend_defs_all_roms.py)
  (ROADMAP D item 4); regenerate with `python utilities/scripts/defs-merge/extend_defs_all_roms.py`
  from the repo root. Machine-readable mapping + validation:
  [`coverage.json`](coverage.json).
- `coverage.json` — per-ROM: file, SHA-256, fw id (offset 0x2000), cal strings
  (0x6c000 area), RomRaider block + base chain + table counts, emitted def path,
  ECUFlash reference, status. 12 of 14 ROMs have a block; gaps: **60E0E500**
  (no upstream block) and **60E1C500** (block exists upstream but is commented
  out, commit `251f54f` — "NOT CORRECT BUT CLOSE").
- `romraider/rx8defs-merged-60E15120.xml` — merged/reviewed definition for ROM
  `60E15120_N3J1E` (upstream base `ff5ab4f` + local reviewed copy based on
  `944062e`); merge records in
  [`docs/investigations/60E15120_N3J1E/defs-merge/`](../../docs/investigations/60E15120_N3J1E/defs-merge/README.md).
  The per-ROM `per-rom/60E15120_N3J1E.xml` uses this reviewed block.
- `romraider/upstream-rx8defs/rx8_defs.xml` — upstream RomRaider defs snapshot,
  git blob `35ddcf316573a092006db5d33c60238ab9a43ea2` = upstream commit
  **`ff5ab4f`** (2026-09-29). Kept (not deleted under rule 4b) because the pinned
  HEAD carries a *newer* blob (`29afd000…` @ `1b3aea2`) and the 60E15120 merge
  was built against `ff5ab4f`; do not mix the two.
- `romraider/reviewed-rx8defs-copy/rx8_defs.xml` — prior effort's locally reviewed
  copy (base `944062e` + annotations; blob `0cd7ec8d…`, not an upstream blob).
- `romraider/reviewed-rx8defs-copy/logger_60E15120_reviewed.xml` — reviewed
  RomRaider *logger* defs for 60E15120 (blob `9b96b2db…`, local).

## Upstream references (no local copy — use these)

| Need | Reference |
|------|-----------|
| RomRaider defs, all ROM blocks (pinned) | `submodules/RX8Defs/RomRaider/rx8_defs.xml` @ `1b3aea2…` (last change `1b3aea2` 2026-10-20, blob `29afd000…`) |
| RomRaider logger defs (pinned) | `submodules/RX8Defs/RomRaider/logger_rx8_defs.xml` @ `1b3aea2…` (last change `607d1a3` 2025-11-30, blob `ba8edef8…`) |
| ECUFlash def for 60E0G500 (1210 tables) | `submodules/RX8Defs/ECUFlash/60E0G500.xml` @ `1b3aea2…` (last change `aaac6f3` 2023-08-11, blob `c4a3c37e…`) |
| ECUFlash base (1743 tables) | `submodules/RX8Defs/ECUFlash/RX8BASE.xml` @ `1b3aea2…` (blob `05a7943e…`) |

ECUFlash defs exist upstream only for 60E0G500; no ECUFlash def exists for the
other 13 ROMs (documented gap, not an omission here).

## D8 dedupe (closed 2026-11-01)

Four local copies were git-blob-identical to files in the pinned submodule
(raw bytes differed only in CRLF/LF line endings) and were deleted per
AGENTS.md rule 4b; use the submodule references above instead:

| Deleted local copy | Blob | Pinned submodule file |
|--------------------|------|----------------------|
| `ecuflash/60E0G500.xml` | `c4a3c37e…` | `submodules/RX8Defs/ECUFlash/60E0G500.xml` @ `1b3aea2…` |
| `ecuflash/RX8BASE.xml` | `05a7943e…` | `submodules/RX8Defs/ECUFlash/RX8BASE.xml` @ `1b3aea2…` |
| `romraider/upstream-rx8defs/logger_rx8_defs.xml` | `ba8edef8…` | `submodules/RX8Defs/RomRaider/logger_rx8_defs.xml` @ `1b3aea2…` |
| `romraider/reviewed-rx8defs-copy/logger_rx8_defs.xml` | `ba8edef8…` | same (reviewed copy was unmodified) |

This also settles the ROADMAP note "the pinned submodule has a newer ECUFlash
XML": it does not — both are 1,210 tables and blob-identical after line-ending
normalization; the 61,849 B vs 63,606 B size difference was CRLF vs LF only.
Evidence: `coverage.json` `dedupe_d8` (regenerate to re-verify).

## Caveats

- The three `aron-N3ZHEC-streetportv1_24_*` dumps are user-tuned variants of
  fw 60E0G500: they share the 60E0G500 block, but a tune may have moved table
  contents — verify per-table against the ROM before any write. Stock defs
  describe the stock layout.
- `storageaddress="0x000000"` entries are upstream placeholders (unmapped
  DTC-enable bytes), not real addresses.
- ROM identification is by the 8-byte fw id at 0x2000, asserted per ROM by the
  generator script; cal-id strings at 0x6c000 exist only in some ROMs
  (register item D1/D7).
