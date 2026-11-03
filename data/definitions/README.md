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

## Literal-pool scalars exposed as editable entries (2026-11-02, ROADMAP D11)

`utilities/scripts/defs-merge/extend_defs_all_roms.py` now injects two 1-cell
`type="1D" size="1" storagetype="float"` tables (RomRaider renders these as
scalars) into every per-ROM def that has a block:

- **Scalar - Stoich AFR (literal pool)** — the 14.7 stoich constant
  (0x416b3333; N3J1E @0x3E7EC, mova @0x3e6ec in FUN_0003e560).
- **Scalar - Fuel Load Scale (literal pool)** — 0.07196
  (N3J1E @0x78170 → `fuel_load_scale_ffffbed0`).

`storageaddress` is the per-ROM literal address from
`data/maps/cross_rom_scalars.json` (extract_scalars.py), **asserted against the
ROM bytes** (f32 decode == expected value) at generation time, and re-checked by
`tests/test_extract_scalars.py::test_per_rom_defs_expose_scalars`. Editing these
in RomRaider/VersaTuner changes the λ→AFR conversion and the base load→fuel
scale respectively. Caveat: both addresses are inside the app-flash checksum
range (ROADMAP D3, 0x2000–0x7ffff), so a changed value needs the checksum/CVN
path handled. ROMs without an upstream
block (60E0E500, 60E1C500) have no per-ROM def and thus no scalar entries.
ECUFlash defs remain upstream-only for 60E0G500 (documented gap).

### Changing fuel stoichiometry — which scalar does what

The injection math is done in **lambda** (1.0 = stoich); the two scalars sit on
different axes and must be changed **together** for a fixed different-stoich
fuel:

| Entry | What it changes | For new stoich S |
|---|---|---|
| `Scalar - Stoich AFR (literal pool)` (14.7) | λ↔AFR conversion in the AFR-domain logic: catalyst/fuel-correction model (`fuel_correction_sum_ffffc644`, PID 0x3c), AFR words/diagnostics. NOT in the injection-volume path (single use, FUN_0003e560). | set to S (e.g. 9.76 for E85) |
| `Scalar - Fuel Load Scale (literal pool)` (0.07196) | the load→fuel-**volume** bridge in the injection path (`bed0 = load × 0.07196` → `beb0`, 0x306e8 → pulse times). This is what changes open-loop fuel quantity; its value embeds 1/stoich × fuel density (unit interpretation still candidate — verify on a wideband). | scale by 14.7/S (E85: ×1.506 → ≈0.1084) |

Leave the maps (`tbl_06ac88` base fuel map, `tbl_069e9c` open-loop target) alone —
they command λ multipliers, which are fuel-agnostic, and closed loop self-corrects
via the O2 sensor in λ regardless. For **varying** ethanol blends, don't hardcode:
use the flex stoich table (G-ROM_FLEX "Table 2D - Stoich Fuel Ratio" @0x6C444,
ethanol-indexed). Both scalar addresses are inside the D3 checksum range, so a
changed value needs the checksum/CVN path handled.

## Relabel / regroup pass (2026-11-02, ROADMAP D item 5)

The reviewed 60E15120 def and all per-ROM defs were relabeled from the
subsystem RE passes (knock / fueling / load / ignition / OS): 112 lookup
descriptors carry curated editor names, subsystem categories (the RomRaider
grouping) and dated evidence notes in
[`data/labels/60E15120_N3J1E/defs_table_labels.json`](../labels/60E15120_N3J1E/defs_table_labels.json).
Editor-facing `<description>` entries stay short per AGENTS.md rule 6b — a
simplified what-the-table-does sentence (only when accurately known; candidate
labels get a "not fully verified" note), no addresses or derivation details;
provenance stays in the label map.
In the merged 60E15120 block **78 tables were renamed + regrouped and 96
extracted-but-unmapped tables added** (879 → 975); cross-ROM, 263 renamed +
245 added across the 8 ROMs whose upstream blocks join their `data/maps`
extraction (60E32000_N3M5E/N3N5EB skipped — upstream block layout mismatch,
recorded in `coverage.json`). Only names/categories/descriptions changed plus
whole-table additions; no storageaddress, axis, scaling or cell was modified
(invariant-checked by `tests/test_defs_relabel.py`). Regenerate with
`utilities/scripts/defs-merge/relabel_merged_def.py` (merged def) and
`utilities/scripts/defs-merge/extend_defs_all_roms.py` (per-ROM defs);
pass log + investigation doc:
[`docs/investigations/60E15120_N3J1E/defs-merge/relabel_2026-11-02.md`](../docs/investigations/60E15120_N3J1E/defs-merge/relabel_2026-11-02.md).

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

- `storageaddress="0x000000"` entries are upstream placeholders (unmapped
  DTC-enable bytes), not real addresses.
- DTC enable/disable tables are named with the standard 5-char OBD code since
  2026-11-03: `DTC P0420 Enable/Disable #1` (was `DTC 0420 ...`; `C167` was a
  high-nibble misread and is now `DTC U0167 ...` — 0xC0>>6 = U per SAE J2012).
  Decode + SAE descriptions: [`data/dtc/pcodes.tsv`](../dtc/pcodes.tsv);
  details in [dtc_control_report.md §5b](../../docs/investigations/60E15120_N3J1E/dtc_control_report.md).
- ROM identification is by the 8-byte fw id at 0x2000, asserted per ROM by the
  generator script; cal-id strings at 0x6c000 exist only in some ROMs
  (register item D1/D7).
