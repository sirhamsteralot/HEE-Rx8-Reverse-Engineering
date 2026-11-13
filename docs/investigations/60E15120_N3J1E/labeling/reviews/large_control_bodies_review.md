# Review of the five large-control-bodies reports

Double-check of the reports covering the seven largest previously unlabeled
control bodies. ROM 60E15120_N3J1E, SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1` (re-hashed during
this review, matches the report headers).

Reports reviewed: [`o2_sensor_monitor_report.md`](../../o2_sensor_monitor_report.md),
[`cruise_control_report.md`](../../cruise_control_report.md),
[`e2ram_nv_storage_report.md`](../../e2ram_nv_storage_report.md),
[`idle_target_control_report.md`](../../idle_target_control_report.md),
[`can_mailbox_config_report.md`](../../can_mailbox_config_report.md).

## Format checks (all five reports)

- Header carries target ROM path + SHA-256 + static-analysis disclaimer, and a
  `**Related reports:**` line with working `.md` links (every link target
  verified to exist on disk; no bare `.md` code spans).
- Sections 1, 1a (plain language), 2 (pseudocode), 3 (tables), 4 (labeling),
  5 (corrections), 6 (files), 7 (validation), 8 (memory map 8.1/8.2/8.3),
  9 (limits) all present; `validate_reports.py` re-run: PASS (fn/ram/rom
  addresses in each report's memory map checked vs index/TSVs/ROM).
- Label artifacts consistent: per-body label JSONs (`data/labels/60E15120_N3J1E/{o2_sensor_monitor,cruise_control,e2ram_nv_storage,idle_target_control,can_mailbox_config}_labels.json`)
  covers exactly the 15 function + 17 RAM rows of
  `labeling/source_review/accepted_{function,ram}_aliases.tsv`, which match
  `function_index.tsv` / `symbols.tsv` (asserted by
  the label-artifact checks live in each per-subsystem static test file
  (`tests/test_o2_sensor_monitor.py`, `test_cruise_control.py`,
  `test_e2ram_nv_storage.py`, `test_idle_target_control.py`,
  `test_can_mailbox_config.py`).

## Binary-level re-verification (independent of the reports' own test, re-read from ROM + disassembly)

- Call sites: pool words and jsr/mov pairs at 0x38f72→0x38f74 (pool 0x390b0 =
  0x3fb9e), 0x38f78→0x38f7a (pool = 0x4128e), 0x2e6c6 (pool 0x2e7dc = 0x4ca7e),
  0x2e63c (pool 0x2e790 = 0x2d83c), 0x167fa (pool 0x168ac = 0x1506c),
  0x2376e/0x23796 (pools 0x237bc = 0x23844 / 0x237c8 = 0x244bc), 0xda3e/0xda4e
  (jsr @r13, pool 0xdb20 = 0x2a4f8), 0x1174c→0x2e692, 0x11536→0x2e5c6,
  0x6504→0x11744. Task table: rec[10].entry = 0x64f6 @0x4a38, rec[18] = 0x64e8
  @0x4ab8.
- O2 monitor: descriptors 0x6b66c (9×9, axes 0x7ad48/0x7ad6c, data 0x7ad90),
  0x6b680/0x6b69c (9×9 u16), 0x6b6b8/0x6b6d4 (1×1 u16 constants — see
  correction below); tolerance 1e-5 (0x3727c5ac) at pool 0x41220 via mova at
  0x41140/0x41156/0x4116a/0x4117e; Mode-06 encoders 0x58262/0x5831c read
  0xffffc6f0/0xffffc6f4 via mov.w pools 0x582ea/0x5840a; fault chain
  id2slot[0x1c] @0x7df7a = 0x1b → code @0x7e596 = 0x0133 (P0133).
- Cruise: 3.2f (0x404ccccd) at 0x7d0c8/0x7d0cc via ptr pools 0x4ce14/0x4ce1c;
  2-D descriptors 0x6bc40–0x6bc70 and 0x6bbe0–0x6bc34 (n=10, vss 0–200),
  0x6a880–0x6a8b0 (n=31, delta −16..16), 3-D 0x6a8d0–0x6a920 (10×5, speed
  20–200 @0x77198 × band 2–6 @0x771c0, data 0x771d4+).
- E2RAM: magic write mov.w via pool 0x23734 (0xa55a) at 0x236ec to 0xffffb440
  (r14 from pool 0x23726 = 0xb440); checksum loop 0x236f0–0x236fe with r6 =
  0x1b (set at 0x236de), store at +0x36 (0x23708); write jsr pool 0x23738 =
  0xb886 with r5 = 0x1c; ok-flag pool 0x23728 = 0xb43b; load-side magic
  compare vs pool 0x236ac = 0x5aa5 at 0x23638-0x2363a; codec step floats in
  pools 0x23918/0x24004/0x23938/0x2393c/0x2452c/0x24684/0x24b3c/0x24b40 (see
  correction below); 0x242ae makes 18 calls to 0x66a00; 0x23f4e replays via
  pool 0x24008 = 0x5fd38.
- Idle: descriptors 0x6935c (n=11 typ 8 @0x6dcb0/0x6dcdc), 0x69370 (n=7,
  coolant −40…80 °C @0x6dcf4, u16 rpm 1700→810 @0x6dd10), 0x693d4/0x693e8/
  0x693fc/0x69410; 500.0 floor float at pool 0x15354.
- CAN: first mailbox record at 0x4e01c = `0000 0201 00 01 08 00 ffffbaf4
  0100 0000` (id 0x201, mb 1, ctrl 0x08, buffer 0xffffbaf4); BCR compare vs
  0x803e (pool 0x2a5f0 = 0x0000803e), IMR vs 0xfcfe (pool 0x2a6f0 at
  0x2a686/0x2a698); MBCR bit build `(mb+8)&0xf`; counts 0x10/0x6; HCAN
  register symbols all present in `symbols.tsv`.

## Corrections made in this review

1. `o2_sensor_monitor_report.md` §3 claimed all four threshold descriptors are
   9×9 load×rpm tables with an unresolved "ax @?". ROM bytes + `data/maps/
   60E15120_N3J1E/index.tsv` (tbl_06b6b8/tbl_06b6d4 = 1x1) show 0x6b6b8/0x6b6d4
   are 1×1 u16 constants (data 0, mult 0.000152587890625, off −1.0 → −1.0);
   0x6b680/0x6b69c are the 9×9 ones (axes @0x7ae34/0x7ae58, data @0x7ae7c).
   §3 table corrected; regression asserts added to
   the per-subsystem static test files.
2. `e2ram_nv_storage_report.md` §2/§3 mislabeled the decimal values of two
   literal-pool floats: 0x38a00000 = 7.62939453125e-05 (report said 0.0048828)
   and 0x39a00000 = 0.00030517578125 (report said 0.00048828); both pool words
   verified at mova sites 0x23f10/0x24554. The "readValue_float(16.0)" default
   is not binary-locatable in the codec pools (the export shows 0x41700000 =
   15.0); the specific value was dropped from the pseudocode. §3's float list
   replaced with the pool-verified set (adds 0x3b800000, 0x3e480000; drops
   0x3f800000, which is not referenced from the codec pools). Regression
   asserts added.
3. §6 of four reports said "(renamed by integrate_reviewed_names.py)" — the
   script renames symbols in place; filenames keep the `FUN_` prefix. Wording
   corrected.
4. `can_mailbox_config_report.md` §2 gave the BCR compare value as 0x83e; the
   pool word is 0x0000803e (0x803e), confirmed dynamically (the ROM's own
   setup writes 0x803e). Corrected.

## Dynamic validation

the per-subsystem dynamic tests (`tests/test_o2_sensor_monitor_dynamic.py`,
`tests/test_cruise_control_dynamic.py`, `tests/test_e2ram_nv_storage_dynamic.py`,
`tests/test_idle_target_control_dynamic.py`, `tests/test_can_mailbox_config_dynamic.py`) - 11 passed - harness-call each of the seven bodies
in the emulator after boot and checks outputs against ROM constants / the
ROM's own lookup helpers:

- 0x3f924 filter: exact float32 results (fmac semantics) for k = 1.0/0.5/0.1/0.03125.
- 0x3fb9e accumulate: window reload c7b2 == raw-u16 3-D lookup (18 @ load 0.3,
  2000 rpm); window-complete publish c701 = 1, c6f0 = c758/c728 = 0.5.
- 0x4128e evaluate: thresholds == ROM 3-D lookups, with 0x6b6b8/0x6b6d4
  dynamically confirmed as 1×1 constants = −1.0; pass/fail flags; pending
  (c703) vs confirmed (c702) decision cells. The id→slot→code P0133 chain is
  static-verified; the DTC engine's RAM write needs more enable bits than the
  test sets, so the set_fault side effect itself was not asserted.
- 0x4c828 switch decode (code 3 → cf49, code 6 → cf4c), 0x4ca7e filter stage
  (±15 clamp, ±1 rate limit, k=0.1 filter, cef4 = cef0 + vss-offset lookup),
  0x2d83c integrator (bd10 counter, bd24..bd34 == ROM 3-D lookups), 0x2df62
  apply (clamp [0,100]: 110→100, 90, −10→0, gate-off→0).
- 0x23844/0x244bc E2RAM codec: affine decodes/encodes bit-exact (incl. signed
  encode, readValue checksum cells, rpm step, fault-bit packing).
- 0x1506c idle: a800 == lookup_2d(0x69370, coolant) (1700/1450/810 rpm),
  850 rpm floor with the idle latch, d26a override path.
- 0x2a4f8 CAN compare: r0 == 0 when the live HCAN registers match the
  descriptor-built image (both channels), r0 != 0 on MC[1]/BCR/IMR
  corruption.

Emulator fix required for this pass: `sh2e.py` operand regexes now accept the
disassembler's spaced `@( r0,rN )` form (131 sites in the ROM); this also
closed two former decode gaps in the task-handler tests (task[13]/[16] now
run to taskEnd + idle). Boot trace re-diffed vs the golden fixture: MATCH
(319,731 steps). A Renesas Simulator Debugger differential run is still
pending (tool not installed). Full suite: 138 passed.

## Test layout

Tests are standalone per subsystem, each runnable on its own
(`python -m pytest tests/test_<subsystem>.py`): static binary checks
(call-site pool words, descriptors, literals, DTC chain, task table) plus the
label-artifact consistency checks (function_index.tsv / symbols.tsv / accepted
TSVs / labels JSON subset + totals) live in `tests/test_o2_sensor_monitor.py`,
`test_cruise_control.py`, `test_e2ram_nv_storage.py`, `test_idle_target_control.py`,
`test_can_mailbox_config.py` (20 passed); emulator validation lives in the
`tests/test_<subsystem>_dynamic.py` counterparts (11 passed). One typo was
found and fixed during the split (3.2f pool word is 0x404ccccd).

## Validators / tests re-run (repo root)

- `validate_export.py`, `validate_reports.py`, `verify_readability.py`,
  `verify_math_units.py`, `verify_claims.py` — all exit 0
  (`validate_export`/`verify_readability` report the informational
  `semantic_equivalence_verified`/`whole_firmware_compilable` = false, same as
  without a Ghidra DB; ROM hash + 3,355 function files + instruction
  bytes verified). Run with the documented latin-1 locale
  (`LC_ALL=aa_DJ.iso88591 PYTHONUTF8=0 PYTHONCOERCECLOCALE=0`).
- `python -m pytest tests/` — 138 passed.
- Per-subsystem static tests (label artifacts + ROM-byte anchors) — 20 passed.
- ROM untouched (SHA-256 re-verified).

## Limits of this review

- The idle report's battery-gate constants (0.03125, 13.016 V, 12.0 V) match
  the decompiled export but are not present as float pool words in the 0x1506c/
  0x167c0 pool region (likely built via FP ops); left as export-derived.
- Still open per subsystem (report §9 Limits): E2RAM payload attribution +
  save cadence, CAN record bytes +12..+15, idle flag meanings + 0x5ca94
  output, O2 channel meanings. (The cruise 0xffffbcf8 units / 0xffffcf1c
  producer / 0xffffcf51–0xcf5b consumer questions are resolved in
  [`cruise_control/`](../../reviews/cruise_control/README.md) —
  [`cruise_control_report.md`](../../cruise_control_report.md) §9.)
