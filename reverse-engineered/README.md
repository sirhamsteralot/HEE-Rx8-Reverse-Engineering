# reverse-engineered/

All reverse-engineering output for HEE ROMs, organized per ROM ID.

| Path | Contents |
|---|---|
| `disassembly/<rom-id>/` | Addressed disassembly export (instruction bytes), `decompiler_issues.tsv`, `non_instruction_ranges.tsv`. |
| `disassembly/archives/` | Ghidra `.gar` project archives (Git LFS). Live `.gpr/.rep` project DBs stay in `input/` — commit archives + exports, not databases. |
| `decompiled/<rom-id>/` | Decompiler C export: `firmware_decompiled.c`, per-function `functions/`, indexes (`function_index.tsv`, `callgraph.tsv`, `symbols.tsv`, `analysis_summary.json`), plus synchronized readable view in `named/`. |
| `reimplementation/` | Clean, compilable C11 reimplementations (`rx8_math.c`, `rx8_apv.c` + headers) with host tests (`test_*.c`). Build: `cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off … -lm`. |

## Rules

- Always reference the original address (`0x08001234`) in symbol names, comments,
  and commit messages so work traces back to `binaries/`.
- Label discipline: `FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_` prefixes
  carry evidence strength — never upgrade without new evidence (see `AGENTS.md`).
- If you rename functions/globals, update **all** synchronized views
  (`decompiled/`, `named/`) and the rename map in `data/labels/<rom-id>/`
  (`integrated_names.json`); keep a pre-change backup zip under the ROM's
  investigation folder (`docs/investigations/<rom-id>/backups/`).
- The saved Ghidra database lags behind review annotations — the C export carries
  the newest names. Manual Ghidra findings must be written back into
  `data/labels/` TSVs or a review folder, not left only in the database.
- Ghidra C is a reading aid (`undefined*`, `CONCAT`/`SUB`/`ABS`, register-derived
  params are not valid C). Reimplemented code must compile clean and be verified
  against the disassembly.
- One subsystem per commit, small reviewable diffs.
