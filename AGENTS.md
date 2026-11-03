# AGENTS.md — working rules for this repo

Instructions for AI agents (and humans) working on the HEE Mazda RX-8 PCM
reverse-engineering effort. Read [`README.md`](README.md) first. Practices here incorporate the
prior effort's workspace rules (preserved at [`docs/references/prior-effort-agents.md`](docs/references/prior-effort-agents.md))
and session log ([`docs/learnings.md`](docs/learnings.md)).

## Repo map (put things where they belong)

- `input/` — raw, uncommitted intake (bins, prior efforts, cloned repos, tool installs). Never `git add` its contents; promote verified artifacts out of it.
- `submodules/` — upstream repos (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering`) as git submodules, **read-only context only**. Never work, edit, or commit inside them; our promoted copies live in `binaries/`, `data/`, `reverse-engineered/`, etc. To move to a newer upstream commit, update deliberately and commit the gitlink bump in this repo (`git submodule update --remote` is a shared-state action — get approval first).
- `binaries/` — immutable dumps of **our own acquisitions** only, with `manifest.csv` (SHA-256 + provenance, recursive). Never edit or "fix" a binary in place. Upstream ROMs/captures are referenced via `submodules/Mazda_RX8_PCM_ReverseEngineering/{Stock_ROMs,Data_binaries}/` — do not duplicate them here.
- `reverse-engineered/disassembly/` — addressed disassembly exports per ROM (`<rom-id>/`). Ghidra `.gar` archives live in the submodule's `Ghidra_Archives/` — reference, don't copy. Live `.gpr/.rep` project DBs are not committed anywhere.
- `reverse-engineered/decompiled/<rom-id>/` — decompiler C export, per-function files, indexes (`function_index.tsv`, `callgraph.tsv`, `symbols.tsv`), and synchronized named views (`named/`).
- `reverse-engineered/reimplementation/` — clean, compilable C (C11, strict warnings) plus its host tests.
- `docs/investigations/<rom-id>/` — per-ROM investigation evidence: root `*_report.md` subsystem reports, `reviews/`, `cross_ecu/`, `source_review/`, `math_units/`, `lookup_family/`, `readability/`, `defs-merge/`, `rx8defs-analysis/`, `backups/` (pre-change zips, LFS), README.
- `docs/architecture/` — memory maps, `hardware/` (text pinout `mazda-rx-8-pcm-pinout-series-1.md` derived from ground-truth `docs/references/13Electrical.pdf`, plus `pcm_connections.tsv`, wiring review), `design/` (firmware design doc + stats), emulator docs: `emulator-ui.md`, `emulated-obd.md`, and **`emulator-re-guide.md` — how to test firmware in the simulator with the real-car datalogs (sensor/replay input, watch/OBD output, harness.py function calls, golden-log loop); read it before emulator-based validation work**.
- `docs/references/` — reference PDFs with trust notes, upstream repo links, prior-effort docs.
- [`docs/learnings.md`](docs/learnings.md) — accumulated session know-how (SH-2E encodings, pipeline pitfalls, patcher patterns).
- `data/definitions/` — RomRaider/ECUFlash XML ECU definitions (upstream vs reviewed vs merged, provenance in README).
- `data/labels/<rom-id>/` — label/alias TSVs, rename maps, `validation.json` records, provenance (`input.json`).
- `data/maps/<rom-id>/` — extracted calibration per ROM: tables (`manifest.json` + `index.tsv` + `tables/*.json`/`*.csv`, from `utilities/scripts/extract_maps.py`) **and** literal-pool scalars (`scalars.json`/`scalars.tsv`, from `utilities/scripts/extract_scalars.py`); cross-ROM reports `data/maps/cross_rom_diff.json` (`diff_maps.py`) and `data/maps/cross_rom_scalars.json` (`extract_scalars.py --all`). See [`data/maps/README.md`](data/maps/README.md).
- `utilities/scripts/` — `hash_binaries.py`, `rx8-pcm-pipeline/` (Ghidra pipeline; paths resolve via its `paths.py` shim to this repo's promoted layout — `reverse-engineered/`, `docs/investigations/`, `data/labels/` — no legacy `input/Tuning-merged` tree needed; Ghidra project DBs go to `${GHIDRA_WORK:-input/ghidra-work}` and are not committed), `patchers/` (ROM patchers — write NEW output files only), `defs-merge/`, `extract_maps.py` + `diff_maps.py` (descriptor scan → `data/maps/`, cross-ROM diff) + `extract_scalars.py` (literal-pool scalar scan → `data/maps/<rom-id>/scalars.*`, cross-ROM scalar report), `emu/` (config-driven SH-2E emulator; one JSON profile per ROM/market/model in `emu/profiles/`).
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
    upstream commit hash in docs. **Don't duplicate submodule content into tracked
    folders** — if a file is byte-identical to one in a submodule, delete our copy
    and reference `submodules/<name>/<path>` (pinned commit) instead. Local
    modifications of upstream files are fine to keep, with provenance notes
    (promotion rules in [`input/README.md`](input/README.md) still apply).
5. **Address traceability.** Tie every symbol to its original address
   (`0x08001234`) in code, docs, and commit messages.
6. **Evidence discipline (label ladder).** `FUN_xxxxxxxx` = unnamed, address only;
   `ref_` = inherited from a reference ROM project (a hypothesis, maybe misspelled —
   don't "fix" without new evidence); `CAL_` = from XML annotations, not independently
   verified; `tbl_` = lookup descriptor pointer, not cell storage; `inferred_` = RAM
   meaning derived from a table axis; `candidate_` = unproven. Never upgrade a label
   because it's plausible. Distinguish firmware dataflow from physical pin routing;
   package-pin ↔ connector-terminal is board routing unless traced.
6b. **Concise editor-def descriptions.** Table `<description>` entries in the XML defs
   (`data/definitions/`) stay short: a simplified description of what the table does —
   only when we accurately know that (candidate labels get a "not fully verified" note
   instead). No memory addresses, no structural-match information, no derivation or
   prior-name dumps, no dated pass markers — provenance lives in the label map
   (`data/labels/<rom-id>/defs_table_labels.json`), TSVs and the investigation docs.
   Safety warnings required by rule 10 (checksum range, bench-validation) are the
   exception and stay.
6c. **Editor-def passes: keep provenance out of the XML, keep passes re-runnable.**
   Learned on the 2026-11-02 defs relabel pass (PR #18 review):
   - `<description>` is user-facing text — never use it as a processing tag. Detect
     already-processed entries by content/name against the label map (see
     `is_relabeled` in `utilities/scripts/defs-merge/relabel.py`), and in tests map
     tables to descriptors via the label map by name — don't regex `0x…` addresses out
     of descriptions (rule 6b keeps them out of there).
   - Per-ROM defs are fully regenerated (`utilities/scripts/defs-merge/extend_defs_all_roms.py`);
     the merged def is spliced in place (`relabel_merged_def.py`), and its pass-log stats
     JSON is only rewritten on a fresh renaming run — so re-running a pass to re-normalize
     descriptions is safe and doesn't clobber the log.
   - When a pass rewrites a touched table's description, replace the whole description on
     that entry (dropping any carried-over analysis block); untouched entries keep their
     pre-existing descriptions (rule 9).
7. **Binary-level verification is mandatory** before claiming a review pass done:
   re-check labels against the raw ROM/disassembly (literal pools incl. shared pools,
   `mov.w`/`mov.l`/`mov #imm`/base+offset idioms, GPIO reg+mask+helper, descriptor
   bytes), then run the pipeline verifiers (`validate_export.py`,
   `validate_reports.py`, `verify_readability.py`, `verify_math_units.py` from
   `utilities/scripts/rx8-pcm-pipeline/`). Record what was checked/corrected in the
   review folder's README/`REVIEW_NOTES` + `validation.json`. Never let a label stand
   on decompiled C alone.
8. **Reports follow the 10-section subsystem format** (template:
   [`docs/investigations/60E15120_N3J1E/knock_control_report.md`](docs/investigations/60E15120_N3J1E/knock_control_report.md)): header with ROM
   SHA-256 + static-analysis disclaimer, executive summary **followed by a
   plain-language summary (section 1a)** — explain in simple terms what the
   subsystem does and what the numbers mean (e.g. ROM maps vs. actually applied
   values, OBD/datalog values vs. commanded values); style example:
   `ignition_timing_report.md` §1a. Then: pseudocode, tables,
   labeling applied, corrections, files, validation, **mandatory memory map
   (function + RAM address tables)**, limits. Detailed evidence goes in the matching
   `reviews/<subsystem>/` folder. Validation proves what it lists — never write
   "verified working" beyond what a validation artifact covers.
   **Cross-reference everywhere**: when any doc mentions another `.md` file,
   link it (`[text](relative/path.md)`) — never leave it as a bare code span.
   Reports additionally carry a `**Related reports:**` line in the header linking
   upstream/downstream subsystem reports instead of re-deriving their content
   (e.g. the fueling chain consumes engine load → link
   [`load_fueling_report.md`](docs/investigations/60E15120_N3J1E/load_fueling_report.md);
   see the links in the `60E15120_N3J1E/*_report.md` headers: load →
   fueling/ignition/intake, knock → ignition, P3 calibration extraction → all
   table lists). If a dependency is missing, that's a sign the report is shallow
   — mark it FURTHER INVESTIGATION NEEDED at the top and add a ROADMAP backlog
   item.
9. **No drive-by changes.** Match existing style (kebab-case filenames, ISO dates,
   `0x` addresses; upstream binary names excepted). Don't reformat untouched files.
10. **Safety.** Nothing here flashes a vehicle without an explicit bench-validation
    note; flag risky steps in your summary. Pushing a work-unit branch and opening a
    PR is the standard authorized delivery flow (see "Branch & PR workflow" below);
    any other push (to `main`, tags, shared branches, force-push) still needs
    explicit approval first.

## Branch & PR workflow (how work is delivered)

`main` is review-gated by convention: **never commit directly to `main`**. Every
work unit (feature, research pass, docs change) gets its own branch and is
delivered as a pull request for the user to review and merge.

- **Branch naming:** `<type>/<kebab-case-slug>` with types `feat/` (code/tooling),
  `research/` (investigation, labeling, reports), `docs/` (documentation only),
  `fix/` (bugfix). E.g. `research/group-c-uds-remainder`. Always branch from the
  current `main` (`git checkout -b <type>/<slug> main`); one branch per work unit —
  don't bundle unrelated units.
- **Commits on the branch:** follow "Commit style" below (one logical change per
  commit, imperative subject ≤72 chars, body with why + doc links + addresses).
- **Push + open a PR when the unit is done and verified** (rule 7 + the Verification
  section): `git push -u origin <branch>`, then open a PR against `main` — use
  `gh pr create` if the CLI is installed, the GitHub web UI, or
  `connector_github_app.create_pull_request` (`owner`/`repo`/`head`/`base`/`title`/
  `body`). PR title follows the commit-subject style; PR body: what + why, links to
  the investigation doc(s), key `0x` addresses, validation artifacts (test /
  validator output, trace diffs), the ROADMAP item(s) closed, and open questions.
- **PR bodies open with a plain-language summary.** First 2–5 sentences that a
  non-specialist can read: what the PR changes, why, and what it deliberately does
  *not* do (e.g. "this renames functions in one ROM's decompiled C from
  byte-exact matches; it does not touch ROM binaries or the emulator"). Only then
  the technical detail (addresses, artifacts, validation). A reviewer or future
  reader must get the gist from the first paragraph without opening a file.
- **Review & merge:** the user reviews and merges (merge commit or squash — the
  reviewer's choice). Agents never merge, never push to `main`, never force-push.
  After a merge, delete the branch and re-sync: `git checkout main && git pull`.
- Anything not intended for the repo (local experiments) stays on a scratch branch
  and is never pushed; pushing anything other than a work-unit branch (tags,
  `main`, shared branches) needs explicit approval (rule 10).

## Workflow for a typical task

1. Read [`README.md`](README.md), [`ROADMAP.md`](ROADMAP.md), this file, and [`docs/learnings.md`](docs/learnings.md); check
   `docs/investigations/` for existing work on the topic. If the task involves
   running/validating firmware in the simulator (boot, datalog replay, UDS/OBD
   queries, function-level checks), also read
   [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md).
2. Land raw material in `input/` (never committed); inventory additions in the
   investigation doc.
3. Create/update the investigation doc with goal + plan.
4. Do the analysis; place artifacts per the repo map.
5. Verify at the binary level (rule 7) and add/update tests.
6. Update the investigation doc with findings, evidence (hashes, addresses), and
   open questions.
7. Commit on the work-unit branch with a clear imperative message referencing the
   investigation doc and addresses; once the unit is verified, push the branch and
   open a PR for review (see "Branch & PR workflow" above).

## Commit style

- Subject: imperative, ≤72 chars. Body: why, plus links to investigation docs and key
  addresses. One logical change per commit. Never rewrite history.
- PRs: title in the same imperative style; body = what + why + doc links + key
  addresses + validation artifacts + open questions (see "Branch & PR workflow"),
  and link the ROADMAP item(s) the PR closes.

## Agent tooling (how agents use the emulator/RE data)

- **In-session agents (like you) do NOT need MCP** — you have local repo access.
  For any simulator-based validation (boot, datalog replay, OBD/UDS, harness
  calls), follow [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md) first — it has the
  working commands, sensor/replay wiring, watch addresses, and the
  golden-log comparison loop.
  Drive the tools directly:
  - `python utilities/scripts/hee.py <tool> '<json args>'` (list: `--list`) —
    one-shot tool calls: `hee_rom_list`, `hee_rom_info`, `hee_boot`, `hee_state`,
    `hee_labels`, `hee_disasm_rom`, `hee_diff_roms`, `hee_manifest_check`, …
    (sessions are per-process; for multi-step debugging use `debug.py`/`ui.py`).
  - or from `run_typescript`: import the emulator modules under
    `utilities/scripts/emu/` and call `emu.build()/run()`, `debugger.DebugSession`,
    `harness.call()` (direct ROM-function calls for dynamic validation), etc.
- **MCP plugin** `.vibe/plugins/hee-re/` (`mcp.json` + `mcp_server.py`, same
  `call_tool`) exists for *external* agents / platforms and Vibe tool exposure;
  it is not required for local work. Skill `hee-reverse-engineering` (in the
  plugin) documents the RE workflows for agents.

## Verification

- `python utilities/scripts/hash_binaries.py --check` after touching `binaries/`.
- Emulator changes (`utilities/scripts/emu/`): `python -m pytest tests/` (all
  harnesses, incl. `test_phase1_dynamic.py` which executes ROM functions via
  `harness.py` — see [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md) §5) plus a
  differential trace run against the Renesas Simulator
  Debugger (SH7055) on the Windows machine via
  `utilities/scripts/emu/compare_traces.py` — see [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md).
  The Renesas tool is not installed on every machine: when absent, run the
  self-check `compare_traces.py <fresh trace> tests/fixtures/boot-60E15120_N3J1E-200k.trace`
  (must report MATCH) and record that external validation is still pending in the
  investigation doc.
- Host tests for reimplemented code:
  `cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off reverse-engineered/reimplementation/rx8_math.c reverse-engineered/reimplementation/test_rx8_math.c -lm -o /tmp/t && /tmp/t`
  (same pattern for `rx8_apv.c`). Host tests do not validate SH FPU rounding.
- `python -m pytest tests/` for repo-level harnesses.
- Pipeline validators run from the **repo root** (paths resolve via
  `utilities/scripts/rx8-pcm-pipeline/paths.py`): `python
  utilities/scripts/rx8-pcm-pipeline/validate_export.py` (ROM hash + instruction
  bytes + matches), `validate_reports.py` (report sections, ROM hash, every
  address in report memory maps vs index/TSVs/ROM), `verify_readability.py`,
  `verify_math_units.py`. The Ghidra-dependent steps in `rebuild.sh` still need
  `GHIDRA_HOME` (Ghidra 12.1.3) and a JDK; project DBs are not committed.
