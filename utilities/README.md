# utilities/

Scripts and tool configurations for acquiring, hashing, analyzing, patching, and
verifying HEE artifacts.

## Layout

- `scripts/hash_binaries.py` — writes/verifies `binaries/manifest.csv` (`--check`).
- `scripts/rx8-pcm-pipeline/` — the Ghidra export/annotation pipeline
  (`rebuild.sh NEW_PROJECT_NAME`, `prepare_metadata.py`, `validate_export.py`,
  `validate_reports.py`, review passes, …). **These scripts encode the legacy
  workspace layout** (`../..` = `input/Tuning-merged`); run them with that tree
  present. Requires Ghidra 12.1.3 (`GHIDRA_HOME`), JDK 21+, Python 3, a C compiler.
- `scripts/patchers/` — ROM patchers + docs (`patch_intake_rpm_window.py`,
  `patch_limiter_behavior.py`, `G_ROM_ImmoDefWriter.py`, `PATCHER_*.md`). They write
  **new** output `.bin` files with JSON reports; input SHA-256 is asserted unchanged.
  Static validation only — never flash without bench validation.
- `scripts/defs-merge/` — RomRaider definition merge/review scripts
  (`merge_review.py`, `annotate_source.py`).
- `tools/ghidra/scripts/` — Ghidra headless Java scripts (`SetupTarget.java`, …).
- `tools/ghidra/processor/` — local **SH-2E** Sleigh processor config
  (`sh-2e.ldefs/.slaspec/.sla`); install into
  `$GHIDRA_HOME/Ghidra/Processors/SuperH/data/languages/` and compile with
  `support/sleigh`. Do **not** use stock SH-2A (over-accepts instructions).

## Rules

- Every script: usage in docstring/`--help`, meaningful exit codes, no hardcoded
  personal paths. Python 3, stdlib-only unless a `requirements.txt` is added here.
- Scripts reading `binaries/` verify against `binaries/manifest.csv` first.
- Patchers: byte-match locate (unique match required), patch only the located span,
  write new output, emit JSON report, never touch stock ROMs.
- Keep a short usage note at the top of each script and link it from the relevant
  investigation doc.
