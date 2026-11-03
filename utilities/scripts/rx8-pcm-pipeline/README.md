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
  + append to `docs/investigations/60E15120_N3J1E/source_review/accepted_*.tsv`;
  `annotate_source_review.py` / `integrate_reviewed_names.py` apply them to the
  synchronized views (with backups under `docs/investigations/60E15120_N3J1E/backups/`).
