# Cross-ROM ECU definition coverage

ROADMAP **D item 4** (extend `data/definitions/` from 60E15120_N3J1E to all ROMs,
incl. 60E0G500) + register item **D8** (defs dedupe vs the pinned submodule).
Machine-readable record: [`data/definitions/coverage.json`](../../../../../data/definitions/coverage.json);
generator: `utilities/scripts/defs-merge/extend_defs_all_roms.py` (run from repo root).

## Method

All 11 dumped ROMs (1 in `binaries/dumps/`, 10 in
`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/`) were identified by the
8-byte ASCII firmware ID at file offset **0x2000** (asserted; cal strings at
0x6c000 exist only in some ROMs — register D1/D7). Our own dumps were additionally
SHA-256-checked against `binaries/manifest.csv`. Each fw id was mapped to a
`<rom>` block of the upstream RomRaider defs
`submodules/RX8Defs/RomRaider/rx8_defs.xml` at the pinned submodule commit
**`39d98a0a87faa1ea3225f7122a1ac2b9d620ff9f`**; 60E15120 uses the locally reviewed
block from `data/definitions/romraider/rx8defs-merged-60E15120.xml` instead
(merge records: [defs-merge/README.md](../defs-merge/README.md)). For every ROM a
standalone per-ROM def (base chain + rom block + provenance comment) was emitted to
`data/definitions/romraider/per-rom/<rom-stem>.xml` and re-parsed after writing;
every table `storageaddress` was asserted in-range (0x2000–0x7ffff, or 0x000000 =
upstream placeholder for unmapped DTC-enable bytes).

## Results — 11 ROMs

| ROM | fw id @0x2000 | RomRaider block | tables | per-ROM def | status |
|-----|---------------|-----------------|--------|-------------|--------|
| `60E0G500_N3ZHEC.bin` | 60E0G500 | 60E0G500 | 814 (+RX8Base 1052) | [per-rom/60E0G500_N3ZHEC.xml](../../../../../data/definitions/romraider/per-rom/60E0G500_N3ZHEC.xml) | OK |
| `60E0E500.bin` | 60E0E500 | — | — | — | no upstream block |
| `60E0E700_N3YLEE.bin` | 60E0E700 | 60E0E700 | 743 (+RX8Base 1052) | [per-rom/60E0E700_N3YLEE.xml](../../../../../data/definitions/romraider/per-rom/60E0E700_N3YLEE.xml) | OK |
| `60E0FB00.bin` | 60E0FB00 | 60E0FB00 | 732 (+RX8Base 1052) | [per-rom/60E0FB00.xml](../../../../../data/definitions/romraider/per-rom/60E0FB00.xml) | OK |
| `60E0FC00.bin` | 60E0FC00 | 60E0FC00 | 907 (+RX8Base 1052) | [per-rom/60E0FC00.xml](../../../../../data/definitions/romraider/per-rom/60E0FC00.xml) | OK |
| `60E15120_N3J1E.bin` | 60E15120 | 60E15120 | 637 (+RX8Base 1052) | [per-rom/60E15120_N3J1E.xml](../../../../../data/definitions/romraider/per-rom/60E15120_N3J1E.xml) | OK |
| `60E1B900.bin` | 60E1B900 | 60E1B900 | 707 (+RX8Base 1052) | [per-rom/60E1B900.xml](../../../../../data/definitions/romraider/per-rom/60E1B900.xml) | OK |
| `60E1C500_N3J6EB.bin` | 60E1C500 | — | — | — | no upstream block (commented out upstream @ `251f54f`) |
| `60E1D400.bin` | 60E1D400 | 60E1D400 | 827 (+RX8Base 1052) | [per-rom/60E1D400.xml](../../../../../data/definitions/romraider/per-rom/60E1D400.xml) | OK |
| `60E32000_N3M5E.bin` | 60E32000 | 60E32000 | 266 (+RX8Base 1052) | [per-rom/60E32000_N3M5E.xml](../../../../../data/definitions/romraider/per-rom/60E32000_N3M5E.xml) | OK |
| `60E32000_N3N5EB.bin` | 60E32000 | 60E32000 | 266 (+RX8Base 1052) | [per-rom/60E32000_N3N5EB.xml](../../../../../data/definitions/romraider/per-rom/60E32000_N3N5EB.xml) | OK |

- **9 of 11 ROMs** now have a standalone RomRaider def. Gaps: **60E0E500** (no
  upstream block at all) and **60E1C500_N3J6EB** (block present upstream but
  commented out, commit `251f54f` "THESE DEFS ARE NOT CORRECT BUT CLOSE").
- **ECUFlash**: upstream ships ECUFlash defs only for 60E0G500
  (`submodules/RX8Defs/ECUFlash/60E0G500.xml`, 1210 tables, last change
  `aaac6f3` 2023-08-11) + base `RX8BASE.xml` (1743 tables). The 60E0G500 factory
  dump (stock N3ZHEC) references it; no copies kept (see D8).

## D8 dedupe

Four local copies under `data/definitions/` were git-blob-identical to files in the
pinned submodule (raw bytes differed only in CRLF/LF) and were **deleted** per
AGENTS.md rule 4b; the submodule path + pinned commit is the reference now:

| deleted copy | blob | pinned reference |
|--------------|------|------------------|
| `ecuflash/60E0G500.xml` | `c4a3c37e…` | `submodules/RX8Defs/ECUFlash/60E0G500.xml` @ `39d98a0…` |
| `ecuflash/RX8BASE.xml` | `05a7943e…` | `submodules/RX8Defs/ECUFlash/RX8BASE.xml` @ `39d98a0…` |
| `romraider/upstream-rx8defs/logger_rx8_defs.xml` | `ba8edef8…` | `submodules/RX8Defs/RomRaider/logger_rx8_defs.xml` @ `39d98a0…` |
| `romraider/reviewed-rx8defs-copy/logger_rx8_defs.xml` | `ba8edef8…` | same (reviewed copy was unmodified) |

`romraider/upstream-rx8defs/rx8_defs.xml` was **kept**: its blob `35ddcf31…` equals
upstream commit `ff5ab4f` (2026-09-29), not the pinned HEAD (`82e5724d…` @
`39d98a0`), because the reviewed 60E15120 merge was built against `ff5ab4f`.
Side effect: the earlier note "the pinned submodule has a newer ECUFlash XML" is
settled — content is identical (1210 tables both); the size difference was line
endings only. Full provenance: [`data/definitions/README.md`](../../../../../data/definitions/README.md).

## Validation

- Script asserts per ROM: size == 512 KiB, fw id regex, manifest hash (own dumps),
  romid `internalidaddress` == 0x2000 and `internalidstring` == fw id, all
  `storageaddress` in 0x2000–0x7ffff or 0x000000, emitted XML re-parses with
  expected block/table counts. All pass (11/11 ROMs, 9 defs, 2 gaps).
- No ROM binary, submodule file, or existing definition was modified; only new files
  under `data/definitions/` were written and four duplicate XMLs removed.
- XML defs are editor metadata; they never change ROM bytes (AGENTS.md rule 2).

**Related:** [60E0G500_N3ZHEC defs-merge](../../../60E0G500_N3ZHEC/labeling/defs-merge/README.md) ·
[60E15120_N3J1E defs-merge](../defs-merge/README.md) ·
[cross-ROM Mode 22 PID handlers](cross_rom_mode22_pid_handlers.md) ·
[cross-ROM function aliases](cross_rom_differential_labeling.md)
