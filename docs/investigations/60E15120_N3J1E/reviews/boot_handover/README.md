# Boot handover review — evidence notes (reference ROM 60E15120_N3J1E)

Evidence for [`docs/subsystem-logic/boot_handover_report.md`](../../../../subsystem-logic/boot_handover_report.md)
and [`data/labels/60E15120_N3J1E/boot_handover_labels.json`](../../../../../data/labels/60E15120_N3J1E/boot_handover_labels.json).
ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, verified
unchanged; no binary was modified.

## Binary-level checks performed this session (rule 7)

- Handover chain pools re-read from raw ROM: `0x1348` = `0x1038` (warm entry
  `0x1298` calls `0x1038` with param 0), `0x1082` = `0x1378`, `0x1084` = `0x1090`,
  `0x1088` = `0x7fffc`, `0x108c` = `0x7fff8`, `0x1098` = `0xffffdfa0`,
  `0x594` = `0x40`; ROM `0x1000` = `0x1298`, `0x7fff8` = `0xd204`,
  `0x7fffc` = `0x2000`.
- App entry `0xd204` pools: `0xd2c0` = `0x7fc50` (VBR), `0xd2c4` = `0x40001`
  (FPSCR), `0xd2c8` = `0xd730`, `0xd2cc` = `0x4c7a`, `0xd2d0` = `0x9e68`;
  `0xd730` = `0xffff768c`.
- Task table at `0x4990` re-read (19 x 16-B records `{param, stack, entry,
  mask}`): no entry is `0x61a8`; record 0 entry = `0x62a0`.
- `0x61a8` reference scan: zero u32 occurrences in the whole ROM; one u16 pool
  word `0x25164` = `0x61a8`, loaded by `mov.w` at `0x25094`/`0x250b0` inside
  `0x2508c`; `0x2508c` <- thunk `0x21b84` (u32 ref `0x21be4`) <- `0x1102a`
  (callgraph); `0x1102a`'s only callgraph caller is `0x61a8`.
- `0xffff9f38` consumers: `0x567a` (IVT offset `0x204` -> trampoline `0x2b00`,
  handler pool `0x2b10` = `0x567a`) and `0x57c6` (`alternator_pwm_service`,
  IVT offset `0x224` -> trampoline `0x2b78`, pool `0x2b88` = `0x57c6`).
- CVN caller chain from `callgraph.tsv`: `0x5a3f4` <- `0x1122a` <- `0x62a0`
  (task[0]); `0x5a714` <- `0x5a3f4`; `0x5a3d8` <- `0x113b8` <- `0x6366` and
  `0x3de70`.
- Cross-ROM handover fields (all 11 ROMs) in
  [`data/labels/cross_rom/sbl_first_8k.json`](../../../../../data/labels/cross_rom/sbl_first_8k.json).

## Dynamic checks

- Boot from vector 0, 200,000 cycles: waypoint steps — `0x8b8`@0, `0x8cc`@2,
  `0x8f6`@25, `0x4e0`@112, `0x572`@117, `0x170`@130, `0x5b0`@686, `0x40`@2434,
  `0x1298`@2437, `0x1038`@2440, `0x1364`@2444, `0x109c`@2457, `0x16dc`@2818,
  `0x1090`@2853, SBL->app transition `0x1094` -> `0xd204`@2856, `0x4c7a`@2864,
  `0x9e68`@2869, `0x3ad8`@130230, `0x3e10`@130250, final pc `0x3dac` (idle).
  Full excerpt: [`boot_trace_excerpt.txt`](boot_trace_excerpt.txt).
- Second run, 2,000,000 cycles after boot, with ATU-II crank input set to
  900 rpm: `0x61a8`, `0x1102a`, `0x2508c`, `0x62a0`, `0x1122a`, `0x5a3f4` all
  hit 0 times — the crank-synchronous OS tick never fires in the emulator, so
  no task dispatches (consistent with the OS scheduling deep dive report).

## Validation runs

- `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py` — PASS (run from repo root, 2026-11-16).
- `python -m pytest tests/` — PASS (2026-11-16).
