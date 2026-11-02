# reverse-engineered/reimplementation/

Clean, compilable C11 reconstructions of ROM routines from
`60E15120_N3J1E` (SH-2E), each with a host unit test next to it. These are hand
reconstructions from the disassembly, not recovered original source; the ROM
address of every reconstructed routine is in the file header comments.
Emulator cross-checks (float32 Python ports of these files vs the real ROM via
`utilities/scripts/emu/harness.py`) live in `tests/` — see
[`tests/README.md`](../../tests/README.md) and
[`docs/architecture/emulator-re-guide.md`](../../docs/architecture/emulator-re-guide.md)
§5.

## Modules

| Module | ROM addresses | Covers |
|---|---|---|
| `rx8_math.c` / `rx8_math.h` | 0x23b0, 0x23dc, 0x23e4, 0x23f4, 0x2404, 0x2478 | float filter/abs/max/min/clamp helpers + saturating u8 add |
| `rx8_apv.c` / `rx8_apv.h` | 0x24c0 (via 0x43a86), 0x31bec, 0xaa90 | APV position scaling, signed fraction, per-channel tick split |
| `rx8_knock.c` / `rx8_knock.h` | 0x13a60, 0x13b40 (clamp 0x13bd2 via `rx8_clamp_float`) | knock-retard state machine: attack/edge/hold target selection, slow-recovery pacing. See [`docs/investigations/60E15120_N3J1E/knock_control_report.md`](../../docs/investigations/60E15120_N3J1E/knock_control_report.md) |

## Build and run host tests

```sh
cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off \
  reverse-engineered/reimplementation/rx8_math.c \
  reverse-engineered/reimplementation/rx8_knock.c \
  reverse-engineered/reimplementation/test_rx8_knock.c -lm -o /tmp/t && /tmp/t
```

(no FP contraction so host results stay comparable to the emulator's float32
port; host tests do not validate SH-2E FPU exception modes, denormal behavior,
or instruction-level rounding — the `tests/` cross-checks cover that against
the real ROM.)

Emulator cross-checks: `python -m pytest tests/test_phase1_dynamic.py
tests/test_knock_retard_dynamic.py` from the repo root (ROM pinned by
`utilities/scripts/emu/profiles/60E15120_N3J1E.json`; needs the submodule ROMs
and, for tests touching `binaries/`, `git lfs pull`).
