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

## External-review re-verification (rx8tune feedback, 2026-11-16)

Binary-level re-checks of the three disputed points (rule 7):

- `0x1008` disassembly `0x1008-0x102a` decoded instruction by instruction (delay
  slots matter: plain `bf` at `0x1024` does NOT execute `0x1026` when taken):
  `r4 = u16@0x7fb00`; if `r4 == (u16)~u16@0x7fb02` AND `r4 != 0xffff` (pool
  `0x1034`) return `r4`, else return 0. Pools `0x102c` = `0x7fb00`, `0x1030` =
  `0x7fb02`, `0x1034` = `0xffff` byte-verified. Ghidra's decompiled `return 2`
  is the constant-folded result for the stock hole, not the general behavior.
  Emulator: `harness.call(0x1008)` -> r0 = 2 with the stock hole `00 02 / FF FD`.
- `0x1d78` callgraph: callees are exactly `{0x1008, 0x11fa}` — no erase path.
  A scan of every PC-relative pool reference in `0x1000-0x1ffb` (committed
  disassembly) finds only HCAN0 `0xffffe400` and SYSC `0xffffed00`; no
  flash-control register (`0xffffe800-0xffffe803`) is referenced in the block.
- App-side 0xB1 path ROM bytes: `0x5ec84` = `b1 00 00 00 00 05 65 e8` (service
  record -> `0x565e8`); `0x5f0f4` = `00 b2 00 01 00 05 63 50 ff fc` (sub-record
  id `0x00B2`, 1 data byte, handler `0x56350`, mask `0xfffc`); `0x5f040` session
  table index 1 = `0x85`; `0x1bec` = `0xfff82000` (= -`0x7e000`, the 0x34 field
  offset); N3YLEE `0x5e728` = `00 b2 00 01 00 05 59 90 ff fc` -> `0x55990`;
  N3YLEE function matches `0x55c28`/`0x55990`/`0x55a1e`/`0x55b14` in
  `data/labels/cross_rom_function_matches.tsv`.
- CVN-hole pair `0x7fb00`/`0x7fb02` dumped for all 11 corpus ROMs + our
  `60E0G500_N3ZHEC` dump: build A holds `0001/fffe`, `0002/fffd`, `0004/fffb`,
  `0005/fffa`, `0007/fff8` (+ ASCII `_UDS` at `0x7fb04`); build B ROMs hold
  `ffff/ffff` (erased) -> `0x1008` returns 0 there, still < 100.

Dynamic validation (re-runnable: `python -m pytest tests/test_sbl_bootloader.py`,
7 tests; captured log:
[`dynamic_sbl_loop_log.txt`](dynamic_sbl_loop_log.txt)):

- SBL loop `0x1378` entered trampoline-style (SP = `0xffffdfa0`) and driven over
  the virtual CAN port: `10 85` -> `50 85`; `27 01` -> `67 01 55 aa 55` (seed
  flag `0xffffdfb2` = 1); `27 02 4d ac cd` -> `67 02` (unlock `0xffffdfb1` = 1,
  seed flag cleared); `b1 00 b2 00` -> `f1 00 b2` with `0xffffdfb3` = 1 /
  `0xffffdfb4` = 0 (one download armed, no erase); `3e 01` -> `7e`; `11 01` ->
  `51` then halt at `0x1a44` with SR mask `0xf0`; WDT OVF (`TCSR 0xffffec10`
  bit 7) sets within 400k cycles.
- `0x34` handler (direct calls, request buffer at `0xffffd3f0`): count `0x400`
  -> `74 04 01` (stage `0xffff6000`, remaining `0x400`, marker index `0xffffdfc5`
  = 1); count `0x401` -> `7f 34 31`; count `0x7000` from addr 0 -> `74`; count
  `0x7400` -> `7f 34 31` (staged end must stay below `0xffffd3f0`).
- `0x36` handler: block `0x100` -> `7f 36 72`; block `0x400` without marker ->
  `7f 36 72` (and `0xffffdfb4` cleared).
- After `11 01` halt + reset (vector 0): trace `0x8b8` -> `0x4e0` -> warm
  `0x1298` -> `0x1038(0)` -> app `0xd204`; cold `0x6c8` and SBL `0x1378` NOT
  taken — the warm path returns to the app when the app image is intact.
- App side: `0x56428` -> 0 with 12.5 V injected on AN14 (real ADC path); the
  app `0x27` key network `0x5609e` ported to Python is accepted by the ROM's own
  verifier for 3 seeds (bit-exact).
- Emulator limit hit while driving the app over CAN end-to-end: the OS tick
  never fires (E6), so the diag-init task bodies (`0x67f10`, `0x67d44`,
  `0x55cae`, `0x55c88`) and the CAN/scheduler chain must be pumped by hand; the
  app `0xB1` handler was therefore validated at handler level with its latch
  inputs set via harness `ram=`, not over CAN end-to-end.

## Validation runs

- `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py` — PASS (run from repo root, 2026-11-16).
- `python -m pytest tests/` — PASS incl. the new `tests/test_sbl_bootloader.py`
  (2026-11-16).
