# AGENTS.md — working rules for this repo

Instructions for AI agents (and humans) contributing to the HEE Mazda RX-8
reverse-engineering effort. Read `README.md` first for project context.

## Repo map (put things where they belong)

- `input/` — raw, uncommitted intake drop zone (bins, prior efforts, cloned repos,
  sources). Never `git add` its contents; promote verified artifacts out of it.
- `binaries/` — original, untouched dumps only. Never edit or "fix" a binary in place.
- `reverse-engineered/disassembly/` — annotated disassembly exports and disassembler project notes.
- `reverse-engineered/decompiled/` — decompiler output.
- `reverse-engineered/reimplementation/` — clean-room source code that builds standalone.
- `docs/investigations/` — one dated markdown file per investigation, started from `TEMPLATE.md`.
- `docs/architecture/` — memory maps, pinouts, bus/message catalogs.
- `docs/references/` — external material with source URLs and access dates.
- `data/` — extracted machine-readable artifacts (JSON/YAML/CSV): maps, tables, DTCs, strings.
- `utilities/scripts/`, `utilities/tools/` — analysis/verification scripts and tool configs.
- `tests/` — behavioral tests comparing reimplementation vs. observed original behavior.

If a new artifact doesn't fit any folder, propose a new one in the PR/commit message
rather than dumping it at the root.

## Hard rules

1. **Provenance first.** Any file added to `binaries/` must be accompanied by a row in
   `binaries/manifest.csv` (name, size, SHA-256, source, date, tool used). Regenerate
   with `python utilities/scripts/hash_binaries.py`.
2. **Never commit secrets or personal data** (VINs, addresses, keys tied to a person).
   If a dump contains a VIN, note it in the investigation doc and redact from committed data files.
3. **Address traceability.** In code and docs, tie every symbol to its original address
   (`0x08001234`) so findings can be traced back to the binary.
4. **Investigation before deep work.** Open a `docs/investigations/YYYY-MM-DD-<topic>.md`
   file (from `TEMPLATE.md`) before starting a new subsystem; update it as you go.
5. **Binaries >5 MB go to Git LFS** (see `.gitattributes`); otherwise keep the raw file
   out and store only its hash.
6. **Safety.** Never produce or run anything intended to flash a vehicle from this repo
   without an explicit bench-validation note in the investigation doc. Flag risky steps
   in your summary.
7. **No drive-by changes.** Don't reformat or "clean up" files you didn't touch. Match
   existing style (kebab-case filenames, ISO dates, `0x`-prefixed addresses).
8. **`input/` stays uncommitted.** It holds third-party repos and raw dumps — keep
   `git status` clean by never tracking it (`.gitignore` already covers `input/*`).
   Promote verified material into `binaries/`, `docs/references/`, `data/`, etc.
   with provenance instead of referencing files inside `input/`.

## Workflow for a typical task

1. Read `README.md` and this file; check `docs/investigations/` for existing work on
   the topic to avoid duplication.
2. Land raw material (bins, prior efforts, cloned repos) in `input/` — never commit
   it — and inventory what you added in the investigation doc.
3. Create/update the investigation doc with goal + plan.
4. Do the analysis; put artifacts in the correct folder per the repo map.
5. Add/update tests in `tests/` when behavior is reimplemented.
6. Update the investigation doc with findings, evidence (hashes, addresses, captures),
   and open questions.
7. Commit with a clear imperative message; reference investigation doc and addresses in
   the body when relevant.

## Commit style

- Subject: imperative, ≤72 chars, e.g. `Add CAN message catalog for idle control`.
- Body: why, plus links to investigation docs and key addresses.
- One logical change per commit.

## Verification

- Run `python -m pytest tests/` (or the harness in `tests/README.md`) after changing
  reimplemented code.
- Run `python utilities/scripts/hash_binaries.py --check` after touching `binaries/`
  to confirm the manifest matches.
