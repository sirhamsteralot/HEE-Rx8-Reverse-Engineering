# AGENTS.md — working rules for this repo

Instructions for AI agents (and humans) working on the HEE Mazda RX-8 PCM
reverse-engineering effort. Read `README.md` first. Practices here incorporate the
prior effort's workspace rules (preserved at `docs/references/prior-effort-agents.md`)
and session log (`docs/learnings.md`).

## Repo map (put things where they belong)

- `input/` — raw, uncommitted intake (bins, prior efforts, cloned repos, tool installs). Never `git add` its contents; promote verified artifacts out of it.
- `submodules/` — upstream repos (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering`) as git submodules, **read-only context only**. Never work, edit, or commit inside them; our promoted copies live in `binaries/`, `data/`, `reverse-engineered/`, etc. To move to a newer upstream commit, update deliberately and commit the gitlink bump in this repo (`git submodule update --remote` is a shared-state action — get approval first).
- `binaries/` — immutable dumps only: `stock-roms/` (upstream `<firmware-id>_<cal-id>.bin` names kept), `captures/` (RAM/EEPROM/IC reads), `manifest.csv` (SHA-256 + provenance, recursive). Never edit or "fix" a binary in place.
- `reverse-engineered/disassembly/` — addressed disassembly exports per ROM (`<rom-id>/`), plus `archives/` (Ghidra `.gar`, via LFS). Live `.gpr/.rep` project DBs stay in `input/`; commit archives + exports instead.
- `reverse-engineered/decompiled/<rom-id>/` — decompiler C export, per-function files, indexes (`function_index.tsv`, `callgraph.tsv`, `symbols.tsv`), and synchronized named views (`named/`).
- `reverse-engineered/reimplementation/` — clean, compilable C (C11, strict warnings) plus its host tests.
- `docs/investigations/<rom-id>/` — per-ROM investigation evidence: root `*_report.md` subsystem reports, `reviews/`, `cross_ecu/`, `source_review/`, `math_units/`, `lookup_family/`, `readability/`, `defs-merge/`, `rx8defs-analysis/`, `backups/` (pre-change zips, LFS), README.
- `docs/architecture/` — memory maps, `hardware/` (text pinout `mazda-rx-8-pcm-pinout-series-1.md` derived from ground-truth `docs/references/13Electrical.pdf`, plus `pcm_connections.tsv`, wiring review), `design/` (firmware design doc + stats).
- `docs/references/` — reference PDFs with trust notes, upstream repo links, prior-effort docs.
- `docs/learnings.md` — accumulated session know-how (SH-2E encodings, pipeline pitfalls, patcher patterns).
- `data/definitions/` — RomRaider/ECUFlash XML ECU definitions (upstream vs reviewed vs merged, provenance in README).
- `data/labels/<rom-id>/` — label/alias TSVs, rename maps, `validation.json` records, provenance (`input.json`).
- `utilities/scripts/` — `hash_binaries.py`, `rx8-pcm-pipeline/` (Ghidra pipeline; expects legacy layout under `input/Tuning-merged`), `patchers/` (ROM patchers — write NEW output files only), `defs-merge/`.
- `utilities/tools/ghidra/` — headless Java scripts (`scripts/`) and the SH-2E processor config (`processor/`).
- `tests/` — repo-level harnesses; host unit tests for reimplemented code live next to the code in `reverse-engineered/reimplementation/`.

If an artifact doesn't fit, propose a new folder in the commit message rather than
dumping it at the root.

## Hard rules

1. **Provenance first.** Any file added under `binaries/` gets a row in
   `binaries/manifest.csv`. Regenerate with `python utilities/scripts/hash_binaries.py`,
   verify with `--check`.
2. **Binaries are immutable.** Never patch, re-save, or "fix" bytes in a `.bin` in
   `binaries/`. Patchers must write new output files and assert the input hash is
   unchanged. If a change seems to require touching a binary, stop and report.
3. **Never commit secrets or personal data** (VINs etc.); redact derived files and
   note the redaction.
4. **`input/` stays uncommitted** (`.gitignore` covers `input/*` except its README).
4b. **`submodules/` is read-only context.** Don't create branches, edit files, or
    commit inside a submodule from this repo. Reference submodule files by path +
    upstream commit hash in docs; never copy from them into tracked folders without
    provenance notes (promotion rules in `input/README.md` still apply).
5. **Address traceability.** Tie every symbol to its original address
   (`0x08001234`) in code, docs, and commit messages.
6. **Evidence discipline (label ladder).** `FUN_xxxxxxxx` = unnamed, address only;
   `ref_` = inherited from a reference ROM project (a hypothesis, maybe misspelled —
   don't "fix" without new evidence); `CAL_` = from XML annotations, not independently
   verified; `tbl_` = lookup descriptor pointer, not cell storage; `inferred_` = RAM
   meaning derived from a table axis; `candidate_` = unproven. Never upgrade a label
   because it's plausible. Distinguish firmware dataflow from physical pin routing;
   package-pin ↔ connector-terminal is board routing unless traced.
7. **Binary-level verification is mandatory** before claiming a review pass done:
   re-check labels against the raw ROM/disassembly (literal pools incl. shared pools,
   `mov.w`/`mov.l`/`mov #imm`/base+offset idioms, GPIO reg+mask+helper, descriptor
   bytes), then run the pipeline verifiers (`validate_export.py`,
   `validate_reports.py`, `verify_readability.py`, `verify_math_units.py` from
   `utilities/scripts/rx8-pcm-pipeline/`). Record what was checked/corrected in the
   review folder's README/`REVIEW_NOTES` + `validation.json`. Never let a label stand
   on decompiled C alone.
8. **Reports follow the 10-section subsystem format** (template:
   `docs/investigations/60E15120_N3J1E/knock_control_report.md`): header with ROM
   SHA-256 + static-analysis disclaimer, executive summary, pseudocode, tables,
   labeling applied, corrections, files, validation, **mandatory memory map
   (function + RAM address tables)**, limits. Detailed evidence goes in the matching
   `reviews/<subsystem>/` folder. Validation proves what it lists — never write
   "verified working" beyond what a validation artifact covers.
9. **No drive-by changes.** Match existing style (kebab-case filenames, ISO dates,
   `0x` addresses; upstream binary names excepted). Don't reformat untouched files.
10. **Safety.** Nothing here flashes a vehicle without an explicit bench-validation
    note; flag risky steps in your summary. Pushes to remotes need explicit approval.

## Workflow for a typical task

1. Read `README.md`, this file, and `docs/learnings.md`; check
   `docs/investigations/` for existing work on the topic.
2. Land raw material in `input/` (never committed); inventory additions in the
   investigation doc.
3. Create/update the investigation doc with goal + plan.
4. Do the analysis; place artifacts per the repo map.
5. Verify at the binary level (rule 7) and add/update tests.
6. Update the investigation doc with findings, evidence (hashes, addresses), and
   open questions.
7. Commit with a clear imperative message referencing the investigation doc and
   addresses.

## Commit style

- Subject: imperative, ≤72 chars. Body: why, plus links to investigation docs and key
  addresses. One logical change per commit. Never rewrite history.

## Verification

- `python utilities/scripts/hash_binaries.py --check` after touching `binaries/`.
- Host tests for reimplemented code:
  `cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off reverse-engineered/reimplementation/rx8_math.c reverse-engineered/reimplementation/test_rx8_math.c -lm -o /tmp/t && /tmp/t`
  (same pattern for `rx8_apv.c`). Host tests do not validate SH FPU rounding.
- `python -m pytest tests/` for repo-level harnesses.
