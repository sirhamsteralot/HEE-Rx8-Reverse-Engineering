# tests/

Verification that reimplemented/derived behavior matches the original binaries.

## Current coverage

- Host unit tests for reimplemented helpers live next to the code:
  - `reverse-engineered/reimplementation/test_rx8_math.c`
  - `reverse-engineered/reimplementation/test_rx8_apv.c`
  - `reverse-engineered/reimplementation/test_rx8_knock.c` (knock-retard state
    machine 0x13a60/0x13b40; build with `rx8_math.c` + `rx8_knock.c`)

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
- Pipeline validators run from the **repo root** (paths resolve via
  `utilities/scripts/rx8-pcm-pipeline/paths.py` to the promoted layout; the
  legacy `input/Tuning-merged` tree is not needed):
  `utilities/scripts/rx8-pcm-pipeline/validate_export.py` (ROM hash, instruction
  bytes, matches, linkage), `validate_reports.py` (report sections, ROM hash, every
  address in report memory maps vs index/TSVs/ROM), `verify_readability.py`,
  `verify_math_units.py`. All four PASS as of 2026-10-31. Ghidra-dependent steps
  in `rebuild.sh` additionally need `GHIDRA_HOME` + JDK.

## Rules

- Tests state which binary SHA-256 (from `binaries/manifest.csv` or the submodule
  gitlink) they validate against.
- Golden data goes in `tests/fixtures/` with provenance comments.
- Repo-level harnesses run with `python -m pytest tests/` from the repo root.
  Currently: `tests/test_emu.py` (emulator: profiles, bus, CPU, WDT, GPIO
  heartbeat, real-ROM boot smoke), `tests/test_decode_corpus.py` (opcode table
  vs the full disassembly corpus), `tests/test_phase1.py` (boot, golden trace,
  ISO-TP/CAN/OBD port, UI session, debugger/UBC), `tests/test_phase1_dynamic.py`
  (dynamic reproduction of static findings via `emu/harness.py`: math helpers vs
  the reimplementation, knock clamp 0x13bd2, injector map 0xd7d4→ATU-II 8A-8F,
  ADC read path, RCAN RX/TX, Mode 22 dispatch), `tests/test_agent_tools.py`
  (`hee.py` CLI), `tests/test_extract_maps.py` (calibration descriptor scanner),
  `tests/test_emu_fidelity.py` (E1 f32 rounding, E7 div1/rotcr, interrupt
  masking), `tests/test_compare_traces_renesas.py` (Renesas TSV trace loader),
  `tests/test_knock_retard_dynamic.py` (knock-retard state machine 0x13a60/0x13b40
  vs the `rx8_knock.c` reimplementation, ROM lookups 0x2068 feeding the port).
  68 tests as of 2026-11-02 (in this environment 4 fail pre-existing because the
  Git LFS object for `binaries/dumps/60E0G500_N3ZHEC.bin` is not pulled; they
  fail identically on `main`).
- Host C tests need a machine with a working C toolchain (the current Windows
  box has MSVC cl.exe but no VC headers, and no mingw gcc) — until then the
  emulator cross-check uses a float32 Python port of the reimplementation.
