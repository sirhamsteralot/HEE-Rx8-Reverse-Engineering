# Thunk audit — review notes (60E15120_N3J1E)

Companion evidence for [`../../thunk_audit_report.md`](../../thunk_audit_report.md).
Label records: [`../../../../data/labels/60E15120_N3J1E/thunk_audit_labels.json`](../../../../../data/labels/60E15120_N3J1E/thunk_audit_labels.json)
(applied rows: `source_review/accepted_function_aliases.tsv`).

## What was checked (binary level, raw ROM re-read)

- ROM SHA-256 asserted unchanged on every run of
  `utilities/scripts/rx8-pcm-pipeline/review_thunk_audit_labels.py`
  (`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`).
- All 53 `thunk`-named rows in
  [`../rx8defs-analysis/function_labels.tsv`](../../rx8defs-analysis/function_labels.tsv)
  re-decoded word-by-word from `60E15120_N3J1E.bin` (big-endian SH-2E):
  14 × 4-byte `bra`, 37 × 6-byte `mov.l @(pool,pc),r3; jmp @r3; nop`,
  1 × 14-byte `jsr @r14` (0x35d36), 1 × conditional tail-jump (0x5fd3c).
- Every bra target decoded from the displacement word; every pool_jmp target
  read as a big-endian u32 at `((addr+4)&~3)+(w&0xff)*4`; each target asserted
  to be a `function_index.tsv` entry.
- 0x35d36: r14 written exactly once in caller 0x35a8c (0x35a94,
  `mov.l @(0x35b74,pc),r14`), pool 0x35b74 = 0x00037ea4; 14 dispatch arms
  `bra 0x00035d36`; 14 body bytes byte-identical to 60E0FC00 0x36456.
- 0x5fd3c cross-checked against the DTC thunk-cluster record
  (`dtc_thunk_labels.json`): kept as `dtc_set_fault_xdefault`.
- Script re-run twice: second run adds/replaces 0 rows (idempotent).

## Validation artifacts recorded

- `python3 utilities/scripts/rx8-pcm-pipeline/review_thunk_audit_labels.py`
  → `{"thunk_rows": 53, "classes": {"bra": 14, "pool_jmp": 37, "jsr_reg": 1,
  "other": 1}, "added_function_aliases": 50, "replaced_function_aliases": 1}`
  (first run; 0/0 on re-run).
- `python -m pytest tests/test_thunk_audit.py` → 7 passed.
- Full suite `python -m pytest tests/` → 193 passed, 1 failed:
  `tests/test_extract_scalars.py::test_generated_outputs_exist_and_are_consistent`
  fails on a pre-existing non-UTF-8 byte (0xa7) in
  `data/maps/60E15120_N3J1E/scalars.tsv` — the byte is present in `main`'s
  committed file and the file is untouched by this change (verified against
  `git show HEAD:...`); not caused by this pass.
- Pipeline validators from repo root: `validate_export.py` exit 0,
  `validate_reports.py` PASS, `verify_claims.py` PASS, `verify_readability.py`
  exit 0, `verify_math_units.py` exit 0.
- `source_review/validation.json` updated (554 function annotations, basis
  `source_review_thunk_audit` added).

## Notes / limits

- `annotate_source_review.py` / `integrate_reviewed_names.py` as committed
  crash on read with the legacy non-UTF-8 bytes that existed in the tracked
  TSVs/export; three cp1252 0x97 bytes in the source-review TSV rows were
  fixed (rows, not parsers) and the two steps were run with
  `errors='surrogateescape'` so all other legacy bytes survive byte-exact.
  Remaining non-UTF-8 bytes live in the export C files and
  `data/maps/.../scalars.tsv` — pre-existing, owned by the label-consistency
  audit item, not touched here beyond the TSV rows.
- No emulator/dynamic run of the trampolines in this pass (static only).
