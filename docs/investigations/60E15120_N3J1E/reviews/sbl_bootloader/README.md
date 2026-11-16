# SBL bootloader review — evidence notes (reference ROM 60E15120_N3J1E)

Evidence for [`docs/subsystem-logic/sbl_bootloader_report.md`](../../../../subsystem-logic/sbl_bootloader_report.md)
and [`data/labels/60E15120_N3J1E/sbl_bootloader_labels.json`](../../../../../data/labels/60E15120_N3J1E/sbl_bootloader_labels.json).
ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, verified
unchanged; no binary was modified.

## Binary-level checks performed this session (rule 7)

- Vector table `0x0–0x3f` re-read from raw ROM: `0x0` = `0x000008b8`, `0x4` =
  `0xffffdfa0`, `0x8` = `0x000008b8`, exception slots `0x10–0x37` = `0x000008b4`,
  `0x38`/`0x3c` = `0xffffffff`.
- Erased gap `0xb0e–0xfdf` verified all-`0xff` in this ROM and in all 11 corpus
  ROMs (`data/labels/cross_rom/sbl_first_8k.json`).
- 32-B block `0xfe0–0xfff` dumped for all 11 ROMs; constant prefix
  `7aff ffff 5079 7730 1141 ffff` + 12x`00` + `2797`, 4-B stamp at `0xffa–0xffd`
  (8 distinct values = 2 code builds x 4 stamps), trailing `0000`.
- `*SBL_END` marker at `0x1ff4` (build A) / `0x1fbc` (build B); warm entry
  `u32@0x1000` = `0x1298` / `0x12b4`; app entry `u32@0x7fff8` = `0xd204` /
  `0xd49c` / `0xd494`; IVT tail `u32@0x7fffc` = `0x2000` in all 11.
- SBL service dispatch resolved from the `0x1378` literal pool words at
  addresses `0x14f4` through `0x1610`: `0x28`->`0x170a`, `0x85`->`0x1774`, `0x10`->`0x17f0`,
  `0x27`->`0x1858`, `0x3e`->`0x197a`, `0x11`->`0x19ce`, `0x22`->`0x1a50`,
  `0x3b`->`0x1ac0`, `0x34`->`0x1ad6`, `0x36`->`0x1c04`, `0x37`->`0x1d30`,
  `0xb1`->`0x1d78`, default ->`0x1e34`.
- Handover pools re-read: `0x1082` = `0x1378`, `0x1084` = `0x1090`,
  `0x1088` = `0x7fffc`, `0x108c` = `0x7fff8`, `0x1098` = `0xffffdfa0`,
  `0x594` = `0x40`, `0x58e` = `0x1000`; ROM `0x1000` = `0x00001298`,
  `0x7fff8` = `0x0000d204`, `0x7fffc` = `0x00002000`.
- Seed/key magic re-verified per the UDS report §12.2: seed `55 AA 55`, key
  `4D AC CD` in `0x1858`.

## Dynamic check

Emulator boot from vector 0, 200,000 cycles, profile `60E15120_N3J1E`: the
normal boot never enters `0x1378` (SBL loop) or `0x6c8` (cold loop); the trace
excerpt is in [`../boot_handover/boot_trace_excerpt.txt`](../boot_handover/boot_trace_excerpt.txt).

## Validation runs

- `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py` — PASS (run from repo root, 2026-11-16).
- `python -m pytest tests/` — PASS (2026-11-16).
