# rx8-pcm-pipeline — Ghidra export/annotation pipeline

Scripts that export the SH-2E ROM from Ghidra, annotate/label it, and validate the
result. **Paths resolve to this repo's promoted layout via `paths.py`** — the legacy
`input/Tuning-merged` workspace is no longer required:

| legacy key | this repo |
|---|---|
| `decompiled/` | `reverse-engineered/decompiled/60E15120_N3J1E/` (asm/issues/non-instruction ranges split out to `reverse-engineered/disassembly/60E15120_N3J1E/`) |
| `metadata/` | `data/labels/60E15120_N3J1E/` |
| `source_review/`, `cross_ecu/`, `math_units/`, `lookup_family/`, `readability/`, `backups/` | `docs/investigations/60E15120_N3J1E/<same>/` |
| `named/` | `reverse-engineered/decompiled/60E15120_N3J1E/named/` |
| `design/`, `hardware/` | `docs/architecture/design/`, `docs/architecture/hardware/` |
| `processor/`, `scripts/` (Java) | `utilities/tools/ghidra/processor/`, `utilities/tools/ghidra/scripts/` |
| `reference_project/`, `ghidra_project/` | `${GHIDRA_WORK:-input/ghidra-work}/...` — Ghidra project DBs are **not committed** |
| `Mazda_RX8_PCM_ReverseEngineering/…`, `RX8Defs/…`, `Rx8Man/…` | `submodules/…` (read-only; the current defs generator is `utilities/scripts/defs-merge/extend_defs_all_roms.py`, which writes only to `data/definitions/`) |

Every script starts with `from paths import b, base, rom_file, ROOT` (or equivalent)
and then uses the old `b/'decompiled/...'` style unchanged. Run the pure-python
steps from the **repo root**.

## Usage

- Validators (no Ghidra needed; all PASS):
  `python utilities/scripts/rx8-pcm-pipeline/validate_export.py`,
  `validate_reports.py`, `verify_readability.py`, `verify_math_units.py`.
- Full rebuild (needs Ghidra 12.1.3 + JDK 21+): `GHIDRA_HOME=... bash
  utilities/scripts/rx8-pcm-pipeline/rebuild.sh NEW_PROJECT_NAME` — re-exports the
  ROM into `reverse-engineered/`, then runs all annotation/review/validation passes.
- Label passes: `review_*_labels.py` write `data/labels/60E15120_N3J1E/*_labels.json`
  + append to `docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_*.tsv`;
  `annotate_source_review.py` / `integrate_reviewed_names.py` apply them to the
  synchronized views (with backups under `docs/investigations/60E15120_N3J1E/backups/`).
- `refine_comment_merge.py` (runs last, before the validators) canonicalizes the
  stacked review comment blocks across `functions/`, `firmware_decompiled.c` and
  `named/firmware_named.c`: one block order in all three views, no duplicate lines,
  and machine-generated cross-ECU/math-units lines dropped when the function's
  `[ADDITIONAL SOURCE REVIEW]` block already states the same fact. Idempotent;
  stats in `docs/investigations/60E15120_N3J1E/labeling/comment_merge/validation.json`.

## Report map check

`validate_reports.py` reads the memory map (§4.1) of every `*_report.md` and
checks it row by row; the same rules are in the script's module docstring.

**Scope.** A row is in map scope when its heading, or any enclosing heading,
mentions "memory map" (subsections inherit it), or when it sits under a bold
`**Functions**` / `**RAM**` / `**ROM tables**` sub-label.

**Classification.** The address in the first cell is read in any form and
classified by its own value, never by the heading:

| Address | Class | What is checked |
|---|---|---|
| `0xffffe000` and up | peripheral I/O window | counted, no alias check |
| `0xffff0000`–`0xffffdfff` | RAM cell | the name must resolve (see below) |
| below `0xffff0000`, a function entry | function | the name must match the index, an accepted function alias or a label record |
| any other ROM address | table / descriptor / axis / pool | range check only (contents are covered by `extract_maps.py` and the defs passes) |

Accepted row forms:

| Form | Example |
|------|---------|
| plain address | `0x0002f890` |
| wrapped in code/bold/italics | `` `0x0002f890` ``, `**0x0002f890**` |
| any 0x width / leading zeros | `0x563de` |
| symbol-led register cell | `` `PEDR_W` 0xfffff754 `` |
| grouped cells in one row | `0xffffa6a0/a6a2`, `0xffffa700 … 0xffffa70f` |
| cell with no alias yet | `DAT_ffff8038` (rule 6: `DAT_` = unnamed, address only) |

**Name resolution.** `accepted_function_aliases.tsv`, `accepted_ram_aliases.tsv`,
`metadata/integrated_names.json` (the `DAT_<addr>` id map) and the per-subsystem
label records under `data/labels/<rom-id>/` (`function_aliases`, `functions`,
`ram_aliases`), plus `function_index.tsv` for function entries.

**Accounting.** Per report, `map_rows = fn_checked + ram_checked + data_rows +
io_rows` is asserted, so a row the check cannot classify fails the run instead of
being skipped. Grouped rows (`grouped_rows`) and unnamed `DAT_` cells
(`unnamed_rows`) are counted, not failed.

**Debt ledger.** `report_map_baseline.json` declares, per report, the addresses
that have no backing yet — `ram` (no tracked alias exists) and `ram_conflict` (a
tracked alias exists but disagrees; also listed in `label_conflicts`). Declaration
counts into `declared_unbacked`. The ledger may only shrink: an entry whose
address now resolves, whose conflict is gone, or that names a report that no
longer exists fails the run as stale.

Run it after any report edit, together with the other validators above.
