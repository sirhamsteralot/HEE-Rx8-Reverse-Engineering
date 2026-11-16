# investigations/

Per-ROM evidence and labeling investigations — one folder per ROM ID. The
shared-logic **subsystem documentation** (one `*_report.md` per subsystem,
written against the reference ROM `60E15120_N3J1E`) lives separately in
[`docs/subsystem-logic/`](../subsystem-logic/README.md); this tree holds the
per-ROM material listed below. [`TEMPLATE.md`](TEMPLATE.md) (the generic
investigation template) and this `README.md` (the index) live here.

Each ROM folder is split into two kinds of material:

- **Reports & evidence** — `*_report.md` files describe what a subsystem of
  the firmware *does* (control logic, task structure, dispatch tables, memory
  maps); ROM-specific ones (differences vs the shared logic: address shifts,
  calibration-specific findings) sit at the folder root. Per-subsystem
  evidence folders live in `reviews/`. These are the documents to read first.
- **`labeling/`** — investigations whose purpose was *labeling things*: the
  alias/cross-ROM/defs passes that renamed functions, RAM cells, tables and
  editor definitions (`cross_ecu/`, `source_review/`, `math_units/`,
  `lookup_family/`, `readability/`, `comment_merge/`, `defs-merge/`,
  `rx8defs-analysis/`), the labeling-only reports (`thunk_audit_report.md`,
  `decompiler_triage_report.md`, `calibration_extraction_report.md`, …), and
  labeling review notes in `labeling/reviews/`. See
  [`60E15120_N3J1E/labeling/README.md`](60E15120_N3J1E/labeling/README.md) for
  the full index.

- `60E15120_N3J1E/` — full analysis of ROM `60E15120_N3J1E.bin`
  (SHA-256 `a7cd953c…`, see `binaries/manifest.csv`): subsystem reports at the
  root ([`fueling_control_report.md`](60E15120_N3J1E/fueling_control_report.md),
  [`intake_solenoids_report.md`](60E15120_N3J1E/intake_solenoids_report.md), [`load_fueling_report.md`](60E15120_N3J1E/load_fueling_report.md)); shared-logic subsystem reports (e.g. [knock control](../subsystem-logic/knock_control_report.md)) live in [`docs/subsystem-logic/`](../subsystem-logic/README.md),
  detailed subsystem evidence in `reviews/`, labeling passes in
  [`labeling/`](60E15120_N3J1E/labeling/README.md), pre-change backups in
  `backups/` (LFS zips).
- `60E0G500_N3ZHEC/` — pipeline export + cross-ROM label propagation for
  `binaries/dumps/60E0G500_N3ZHEC.bin` (fw 60E0G500 / cal N3ZHEC,
  SHA-256 `a33f79a4…`, see `binaries/manifest.csv`):
  defs-merge records in [`labeling/defs-merge/`](60E0G500_N3ZHEC/labeling/defs-merge/README.md),
  pre-change backups in `backups/` (LFS zips).

## Rules

- New ROM or new major question → new dated folder/file from [`TEMPLATE.md`](TEMPLATE.md).
- Subsystem/logic reports whose logic is shared across ROM bins (the default
  assumption until proven otherwise) go to
  [`docs/subsystem-logic/`](../subsystem-logic/README.md) and link the per-ROM
  difference documents; only ROM-specific findings get a report at the ROM
  folder root. Labeling passes and labeling review notes go under `labeling/`.
- Reports: 10-section format with mandatory memory map (function + RAM address
  tables) and a plain-language §1a (see AGENTS.md rule 8) — template
  [`60E15120_N3J1E/fueling_control_report.md`](60E15120_N3J1E/fueling_control_report.md);
  shared-logic subsystem reports in [`docs/subsystem-logic/`](../subsystem-logic/README.md)
  use the human-first template instead. Reports state current findings — the
  single changelog prose allowed is one changelog table at the very top of the
  document (date, what changed, version); git history records how they
  changed.
- Every review folder carries a [`README.md`](README.md), a sceptical `REVIEW_NOTES.md` where
  warranted, and a `validation.json`; record binary-level verification results there.
- Inputs are cited by SHA-256 (from `binaries/manifest.csv`) and upstream commits by
  hash where applicable.
