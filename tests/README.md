# tests/

Verification that reimplemented/derived behavior matches the original binaries.

## Current coverage

- Host unit tests for reimplemented helpers live next to the code:
  - `reverse-engineered/reimplementation/test_rx8_math.c`
  - `reverse-engineered/reimplementation/test_rx8_apv.c`

  Build/run (C11, strict warnings, no FP contraction so results are comparable):

  ```sh
  cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off \
    reverse-engineered/reimplementation/rx8_math.c \
    reverse-engineered/reimplementation/test_rx8_math.c -lm -o /tmp/rx8_math_test
  /tmp/rx8_math_test
  ```

  Host tests do **not** validate SH-2E FPU rounding/exception behavior.
- `docs/investigations/60E15120_N3J1E/lookup_family/test_lookup_family.c` — lookup
  interpolation family test from the prior effort.
- Pipeline validators (run with the legacy workspace in `input/Tuning-merged`):
  `utilities/scripts/rx8-pcm-pipeline/validate_export.py` (ROM hash, instruction
  bytes, matches, linkage), `validate_reports.py` (report sections, ROM hash, every
  address in report memory maps vs index/TSVs/ROM), `verify_readability.py`,
  `verify_math_units.py`.

## Rules

- Tests state which binary SHA-256 (from `binaries/manifest.csv` or the submodule
  gitlink) they validate against.
- Golden data goes in `tests/fixtures/` with provenance comments.
- Repo-level harnesses run with `python -m pytest tests/` from the repo root.
  Currently: `tests/test_emu.py` (emulator: profiles, bus, CPU, WDT, GPIO
  heartbeat, real-ROM boot smoke).
