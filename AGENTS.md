# AGENTS.md — working rules for this repo

Instructions for AI agents (and humans) working on the HEE Mazda RX-8 PCM
reverse-engineering effort. Read [`README.md`](README.md) first, plus
[`docs/learnings.md`](docs/learnings.md).

## Repo map (put things where they belong)

- `input/` — raw, uncommitted intake (ROM dumps, cloned repos, saved pages, tool installs). Never `git add` its contents; promote verified artifacts out of it.
- `submodules/` — upstream repos (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering`), **read-only context**. Never work, edit, or commit inside them; reference files by path + pinned commit hash. Don't duplicate submodule content into tracked folders — if a file is byte-identical, reference it instead. Updating a gitlink (`git submodule update --remote`) is a shared-state action — get approval first.
- `binaries/` — immutable dumps of **our own acquisitions** only, with `manifest.csv` (recursive SHA-256 + provenance). Upstream ROMs/captures are referenced via `submodules/Mazda_RX8_PCM_ReverseEngineering/{Stock_ROMs,Data_binaries}/`, never duplicated.
- `reverse-engineered/` — `disassembly/<rom-id>/` (addressed asm), `decompiled/<rom-id>/` (C export, per-function files, indexes, `named/` views), `reimplementation/` (compilable C11 + host tests). Live Ghidra `.gpr/.rep` project DBs are never committed; `.gar` archives stay in the submodule.
- `docs/investigations/<rom-id>/` — per-ROM evidence: root `*_report.md` subsystem reports, `reviews/`, `cross_ecu/`, `source_review/`, `math_units/`, `lookup_family/`, `readability/`, `defs-merge/`, `rx8defs-analysis/`, `backups/` (pre-change zips, LFS).
- `docs/architecture/` — memory maps, `hardware/` (pinout + wiring), `design/` (firmware design doc), emulator docs incl. **`emulator-re-guide.md` — how to test firmware in the simulator with the real-car datalogs; read it before any emulator-based validation work**.
- `docs/references/` — reference PDFs with trust notes and upstream repo links.
- [`docs/learnings.md`](docs/learnings.md) — session know-how (SH-2E encodings, pipeline pitfalls, patcher patterns).
- `data/definitions/` — RomRaider/ECUFlash XML ECU definitions (provenance in its README).
- `data/labels/<rom-id>/` — label/alias TSVs + JSON, `validation.json` records, provenance (`input.json`).
- `data/maps/<rom-id>/` — extracted calibration: tables (`extract_maps.py`) **and** literal-pool scalars (`extract_scalars.py`); cross-ROM reports `cross_rom_diff.json` / `cross_rom_scalars.json`. See [`data/maps/README.md`](data/maps/README.md).
- `utilities/scripts/` — `emu/` (SH-2E emulator, one JSON profile per ROM/market/model in `emu/profiles/`), `rx8-pcm-pipeline/` (Ghidra pipeline; paths resolve via its `paths.py`; project DBs go to `${GHIDRA_WORK:-input/ghidra-work}`, not committed), `patchers/` (ROM patchers — write NEW output files only), `defs-merge/`, `extract_maps.py` + `diff_maps.py` + `extract_scalars.py`, `hash_binaries.py`.
- `utilities/tools/ghidra/` — headless Java scripts (`scripts/`) and the SH-2E processor config (`processor/`).
- `tests/` — repo-level pytest harnesses; host tests for reimplemented code live next to the code in `reverse-engineered/reimplementation/`.

If an artifact doesn't fit, propose a new folder in the commit message rather than
dumping it at the root.

## Hard rules

1. **Provenance first.** Any file added under `binaries/` gets a row in
   `binaries/manifest.csv` — regenerate with `python utilities/scripts/hash_binaries.py`,
   verify with `--check`.
2. **Binaries are immutable.** Never patch, re-save, or "fix" bytes in a `.bin` in
   `binaries/`. Patchers must write *new* output files and assert the input hash is
   unchanged. If a change seems to require touching a binary, stop and report.
3. **Never commit secrets or personal data** (VINs etc.); redact derived files and
   note the redaction.
4. **`input/` stays uncommitted** (`.gitignore` covers `input/*` except its README).
4b. **`submodules/` is read-only context.** See the repo map. Local modifications of
    upstream files are fine to keep, with provenance notes (promotion rules in
    [`input/README.md`](input/README.md) still apply).
5. **Address traceability.** Tie every symbol to its original address
   (`0x08001234`) in code, docs, and commit messages.
6. **Evidence discipline (label ladder).** `FUN_xxxxxxxx` = unnamed, address only;
   `ref_` = inherited from a reference ROM project (a hypothesis, maybe misspelled —
   don't "fix" without new evidence); `CAL_` = from XML annotations, not
   independently verified; `tbl_` = lookup descriptor pointer, not cell storage;
   `inferred_` = RAM meaning derived from a table axis; `candidate_` = unproven.
   Never upgrade a label because it's plausible. Distinguish firmware dataflow from
   physical pin routing; package-pin ↔ connector-terminal is board routing unless
   traced.
6b. **Concise editor-def descriptions.** A table `<description>` in
   `data/definitions/` is a short, user-facing what-the-table-does sentence — only
   when we accurately know that (candidate labels get a "not fully verified" note).
   No memory addresses, structural-match information, derivation or prior-name
   dumps, dated pass markers, or checksum/bench-validation notes: provenance lives
   in the label map (`data/labels/<rom-id>/defs_table_labels.json`), TSVs and the
   investigation docs.
6c. **Editor-def passes: keep provenance out of the XML, keep passes re-runnable.**
   - Never use `<description>` as a processing tag; detect already-processed entries
     by content/name against the label map (`is_relabeled` in
     `utilities/scripts/defs-merge/relabel.py`).
   - Per-ROM defs are fully regenerated (`extend_defs_all_roms.py`); the merged def is
     spliced in place (`relabel_merged_def.py`), and its pass-log stats JSON is only
     rewritten on a fresh renaming run — re-running a pass to re-normalize
     descriptions is safe.
   - When a pass rewrites a touched table's description, replace the whole
     description on that entry; untouched entries keep theirs (rule 9).
7. **Binary-level verification is mandatory** before claiming a review pass done:
   re-check labels against the raw ROM/disassembly (literal pools incl. shared pools,
   `mov.w`/`mov.l`/`mov #imm`/base+offset idioms, GPIO reg+mask+helper, descriptor
   bytes), then run the pipeline verifiers (`validate_export.py`,
   `validate_reports.py`, `verify_readability.py`, `verify_math_units.py` from
   `utilities/scripts/rx8-pcm-pipeline/`). Record what was checked in the review
   folder's `README`/`REVIEW_NOTES` + `validation.json`. Never let a label stand on
   decompiled C alone.
8. **Reports follow the 10-section subsystem format** (template:
   [`docs/investigations/60E15120_N3J1E/knock_control_report.md`](docs/investigations/60E15120_N3J1E/knock_control_report.md)):
   header with ROM SHA-256 + static-analysis disclaimer, executive summary followed
   by a **plain-language §1a** (what the subsystem does, what the numbers mean), then
   pseudocode, tables, labeling applied, corrections, files, validation, **mandatory
   memory map (function + RAM address tables)**, limits. Detailed evidence goes in
   the matching `reviews/<subsystem>/` folder; link upstream/downstream reports in a
   `**Related reports:**` header line instead of re-deriving their content.
   Validation proves what it lists — never write "verified working" beyond what a
   validation artifact covers. **Cross-reference everywhere**: link every mentioned
   `.md` file, never leave it as a bare code span. If a dependency is missing, mark
   the report FURTHER INVESTIGATION NEEDED at the top and add a ROADMAP item.
9. **No drive-by changes.** Match existing style (kebab-case filenames, ISO dates,
   `0x` addresses; upstream binary names excepted). Don't reformat untouched files.
10. **Safety.** Nothing here flashes a vehicle without an explicit bench-validation
    note; flag risky steps in your summary. Pushing a work-unit branch and opening a
    PR is the standard authorized delivery flow; any other push (to `main`, tags,
    shared branches, force-push) needs explicit approval first.

## Branch & PR workflow (how work is delivered)

`main` is review-gated: **never commit directly to `main`**. Every work unit gets
its own branch and is delivered as a pull request for the user to review and merge.

- **Branch naming:** `<type>/<kebab-case-slug>` with types `feat/` (code/tooling),
  `research/` (investigation, labeling, reports), `docs/` (documentation only),
  `fix/` (bugfix). Always branch from the current `main`; one branch per work unit —
  don't bundle unrelated units.
- **Commits:** one logical change per commit, imperative subject ≤72 chars, body
  with why + doc links + key addresses (see "Commit style").
- **Push + open a PR when the unit is done and verified** (rule 7 + the Verification
  section): `git push -u origin <branch>`, then open a PR against `main` (`gh pr
  create`, the GitHub web UI, or `connector_github_app.create_pull_request`). PR
  title follows the commit-subject style; body: plain-language summary first (2–5
  sentences a non-specialist can read: what changes, why, and what it deliberately
  does *not* do), then what + why, doc links, key `0x` addresses, validation
  artifacts, the ROADMAP item(s) closed, and open questions.
- **Review & merge:** the user reviews and merges (merge commit or squash — the
  reviewer's choice). Agents never merge, never push to `main`, never force-push.
  After a merge, delete the branch and re-sync: `git checkout main && git pull`.
- Anything not intended for the repo stays on a scratch branch and is never pushed.

## Workflow for a typical task

1. Read [`README.md`](README.md), [`ROADMAP.md`](ROADMAP.md), this file, and
   [`docs/learnings.md`](docs/learnings.md); check
   [`docs/investigations/`](docs/investigations/README.md) for existing work on the
   topic. For simulator-based validation (boot, datalog replay, UDS/OBD, harness
   calls), also read [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md).
2. Land raw material in `input/` (never committed); inventory additions in the
   investigation doc.
3. Create/update the investigation doc with goal + plan.
4. Do the analysis; place artifacts per the repo map.
5. Verify at the binary level (rule 7) and add/update tests.
6. Update the investigation doc with findings, evidence (hashes, addresses), and
   open questions.
7. Commit on the work-unit branch; once verified, push and open a PR (see
   "Branch & PR workflow").

## Commit style

- Subject: imperative, ≤72 chars. Body: why, plus links to investigation docs and
  key addresses. One logical change per commit. Never rewrite history.
- PRs: title in the same imperative style; body per "Branch & PR workflow", linking
  the ROADMAP item(s) the PR closes.

## Agent tooling

- **In-session agents do NOT need MCP** — you have local repo access. For
  simulator-based validation follow
  [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md)
  first (working commands, sensor/replay wiring, watch addresses, golden-log loop),
  then drive the tools directly:
  - `python utilities/scripts/hee.py <tool> '<json args>'` (list: `--list`) — one-shot
    calls (`hee_boot`, `hee_state`, `hee_labels`, `hee_disasm_rom`, `hee_diff_roms`,
    `hee_manifest_check`, …); sessions are per-process, so use `debug.py`/`ui.py` for
    multi-step debugging.
  - or import the emulator modules under `utilities/scripts/emu/` and call
    `emu.build()/run()`, `debugger.DebugSession`, `harness.call()` (direct ROM-function
    calls for dynamic validation).
- **MCP plugin** `.vibe/plugins/hee-re/` (skill `hee-reverse-engineering`) exists for
  *external* agents / platforms; it is not required for local work.

## Verification

- `python utilities/scripts/hash_binaries.py --check` after touching `binaries/`.
- Emulator changes (`utilities/scripts/emu/`): `python -m pytest tests/` (incl.
  `test_phase1_dynamic.py`, which executes ROM functions via `harness.py`) plus a
  differential trace run against the Renesas Simulator Debugger (SH7055) via
  `utilities/scripts/emu/compare_traces.py`. When the Renesas tool is absent, run
  the self-check `compare_traces.py <fresh trace> tests/fixtures/boot-60E15120_N3J1E-200k.trace`
  (must report MATCH) and record that external validation is pending in the
  investigation doc.
- Host tests for reimplemented code:
  `cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off reverse-engineered/reimplementation/rx8_math.c reverse-engineered/reimplementation/test_rx8_math.c -lm -o /tmp/t && /tmp/t`
  (same pattern for `rx8_apv.c`/`rx8_knock.c`). Host tests do not validate SH FPU
  rounding.
- `python -m pytest tests/` for repo-level harnesses.
- Pipeline validators run from the **repo root** (paths resolve via
  `utilities/scripts/rx8-pcm-pipeline/paths.py`): `validate_export.py` (ROM hash +
  instruction bytes + matches), `validate_reports.py` (report sections, ROM hash,
  every address in report memory maps vs index/TSVs/ROM), `verify_readability.py`,
  `verify_math_units.py`. The Ghidra-dependent steps in `rebuild.sh` need `GHIDRA_HOME`
  (Ghidra 12.1.3) and a JDK; project DBs are not committed.
