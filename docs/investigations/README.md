# investigations/

One folder per ROM ID:

- `60E15120_N3J1E/` — full analysis of ROM `60E15120_N3J1E.bin`
  (SHA-256 `a7cd953c…`, see `binaries/manifest.csv`): subsystem reports
  (`knock_control_report.md`, `fueling_control_report.md`,
  `intake_solenoids_report.md`, `load_fueling_report.md`), detailed evidence in
  `reviews/`, `cross_ecu/`, `source_review/`, `math_units/`, `lookup_family/`,
  `readability/`, defs-merge records in `defs-merge/` + `rx8defs-analysis/`,
  pre-change backups in `backups/` (LFS zips).
- `60E0G500_N3ZHEC/` — pipeline export + cross-ROM label propagation for
  `binaries/dumps/60E0G500_N3ZHEC.bin` (fw 60E0G500 / cal N3ZHEC,
  SHA-256 `a33f79a4…`, see `binaries/manifest.csv`):
  defs-merge records in [defs-merge/](60E0G500_N3ZHEC/defs-merge/README.md),
  pre-change backups in `backups/` (LFS zips).

## Rules

- New ROM or new major question → new dated folder/file from [`TEMPLATE.md`](TEMPLATE.md).
- Reports: 10-section format with mandatory memory map (function + RAM address
  tables) and a plain-language §1a (see AGENTS.md rule 8) — template
  [`60E15120_N3J1E/knock_control_report.md`](60E15120_N3J1E/knock_control_report.md). Reports state
  current findings — don't append dated change-log addenda (git history records
  how they changed).
- Every review folder carries a [`README.md`](README.md), a sceptical `REVIEW_NOTES.md` where
  warranted, and a `validation.json`; record binary-level verification results there.
- Inputs are cited by SHA-256 (from `binaries/manifest.csv`) and upstream commits by
  hash where applicable.
