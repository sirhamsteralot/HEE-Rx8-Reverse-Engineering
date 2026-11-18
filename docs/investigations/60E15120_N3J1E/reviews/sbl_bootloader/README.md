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

## On-car handshake feedback (rx8tune/Fullburn Studio session, 2026-11-18)

Source: uncommitted intake `input/feedback-for-hee-handshake-on-car.md` — a
guarded, read-only handshake on a real PCM (calibration `N3YLEE00013SN0A0`,
RX-8 Series 1 Japanese market; the chassis number in the intake note is
redacted here per repo rule 3). The N3YLEE-family SBL block is byte-identical
to the reference ROM at the functions below (bytes compared 2026-11-18:
`0x16dc`–`0x1706`, `0x1858`–`0x1978`, `0x1a50`–`0x1abe`).

Observed on the car, and the binary mechanism for each:

- `B1 00 B2 00` -> `7F B1 22` in the default session and `7F B1 33` in session
  `85` without unlock: the app `0xB1` sub-handler `0x56350` gates on the session
  index (`0xffffd1cf`, NRC `0x22`) and the app unlock level
  (`0xffffd1d0` via `0x55ed4`, NRC `0x33`). With the app `27 01`/`27 02`
  (algorithm `0x5609e`) done first, `B1 00 B2 00` -> `F1 00 B2` — the
  app-side boot request is confirmed on hardware.
- Straight after `F1 00 B2`, the SBL answered `22 D1 00` -> `62 D1 00 85`
  (before any `10 85`), `27 01` -> `67 01 00 00 00` (zero seed, not
  `55 AA 55`), and `27 02 4D AC CD` -> `7F 27 22`. Mechanism, byte-verified in
  the disassembly + pools: the handover `0x564d4` calls `0x1038` with `r4 = 1`
  (pool `0x564f2`, delay slot `mov #1,r4`, SR |= 0xf0 first; the only
  param-1 caller), `0x1038` calls `0x16dc(param)` (pool `0x107e`), and
  `0x16dc` (`0x16dc`–`0x1706`, pools `0x17d4`–`0x17e8`) clears
  `0xffffdfb0/b1/b2/b3/b4/b5` and then — only for param == 1 — sets
  `0xffffdfb0 = 1` (session), `0xffffdfb1 = 1` (unlock), `0xffffdfb3 = 1`
  (download armed). `0x1a50` returns the session latch as the DID `0xd100`
  data byte (`0x1aa4`–`0x1ab6`), and `0x1858` returns the zero seed when
  `0xffffdfb1 == 1` (`0x18dc`–`0x18ec`) versus `55 AA 55` otherwise
  (`0x1908`–`0x1914`); `27 02` with no seed flag outstanding gives NRC `0x22`.
  So the handover deliberately arrives open and download-armed — the
  authorization is inherited through the param-1 convention, not by sharing
  the app cells `0xffffd1cf`/`0xffffd1d0` (those stay app-side; the app gates
  at `0x56350` had to pass before `0xffffd1dc = 3` was set).
- `11 01` -> `51`, then the application answered again after ~1.05 s: the SBL
  `0x11` handler `0x19ce` answers bare `0x51`, halts at `0x1a44` with SR |= 0xf0,
  the unserviced WDT overflows, and the warm reset path re-enters the app —
  confirmed on hardware (and in the emulator, §4.5 of the report).
- The fixed seed `55 AA 55` / key `4D AC CD` is offered on every SBL entry
  except the param-1 handover: warm boot `0x1298` -> `0x1038(0)` (including the
  erased-flash fallback that selects the loop when `u32@0x7fffc`/`u32@0x2000`
  read `0xffffffff`), `10 81` (`0x17f0` -> `0x16dc(0)` at `0x182c`), and the
  loop's own periodic relock (`0x1428` jsr `0x16dc(0)` when the `0x11cc`
  counter reaches `0x5f6`, pool `0x143a`). The erased boot words only choose
  SBL-loop vs app target; they do not gate the seed.

Dynamic reproduction (re-runnable: `python -m pytest tests/test_sbl_bootloader.py`,
9 tests; log [`dynamic_handover_oncar_log.txt`](dynamic_handover_oncar_log.txt)):
`harness.call(0x16dc, r4=1)` then the loop `0x1378` over the virtual CAN port
gives `22 d1 00` -> `62 d1 00 85`, `10 85` -> `50 85`, `27 01` ->
`67 01 00 00 00`, `27 02 4d ac cd` -> `7f 27 22`, `10 81` -> `50 81` (relock:
all six latches cleared), then `22 d1 00` -> `62 d1 00 81` and `27 01` ->
`67 01 55 aa 55` again — the on-car trace frame-for-frame.

## Validation runs (2026-11-18)

- `python -m pytest tests/test_sbl_bootloader.py` — 9 passed.
- `validate_reports.py`, `verify_claims.py` — PASS (run from repo root,
  2026-11-18); full `python -m pytest tests/` re-run recorded in the subsystem
  report §4.5.

## Follow-up: loop-tail relock semantics (0x141a–0x1450), 2026-11-18

Question from the same on-car feedback: what resets the `0x11cc` counter, how
long is `0x5f6` passes in real time, and what the `r12` condition means.

Binary reading (disasm + pools byte-verified):

- The u16 at `0xffffdfa0` is the loop-pass counter. `0x11cc` (`0x11cc`–`0x11f8`,
  pools `0x1278`/`0x1284`/`0x1288`/`0x128c`/`0x1290`) services the WDT each pass
  (TCSR `0xffffec10` = `0xa53c`, toggles bit 15 of `0xfffff738`) and, while OVF
  is clear, increments the counter (saturating at `0xffff`), then returns it.
- `0x11c4` zeroes the counter: once before the loop (`0x137a`; the loop head is
  `0x1388`, back-edge `0x1548`), on every successfully reassembled frame
  (`0x13c8` single frame, `0x13e4` first frame, `0x140a` every consecutive
  frame), and after every service dispatch (`0x1544`). Received-but-invalid
  frames (bad PCI, sequence error) do not reset it.
- Tail: `r12` = multi-frame ISO-TP in progress (set at `0x13e2` on first frame).
  If `r12 == 0` and counter `>= 0x5f6` (pool `0x143a`) → `jsr 0x16dc(0)` at
  `0x1428`: relock, all six latches cleared. If `r12 != 0` and counter
  `>= 0x2e` (`0x1382`) → `jsr 0x11c4` + `r12 = 0` at `0x1448`: abort only the
  in-progress transfer, latches survive.

So: (1) yes, anything that gets a frame reassembled and dispatched resets the
counter — `3E` tester present included — it is an inactivity timeout, not a
fixed lifetime; (3) the relock fires only while no multi-frame transfer is in
progress (`r12 == 0`, i.e. CAN-idle), while during a transfer the tighter
`0x2e` inter-frame timeout applies. (2) Emulator measurement: ~256 cycles per
idle pass; relock at 1,526 passes ≈ 390,000 cycles after the last processed
frame; inter-frame abort at 46 passes ≈ 12,000 cycles. Wall clock depends on
the PCM clock (not pinned down in this repo): at 40 MHz ≈ 9.8 ms / 0.29 ms,
at 20 MHz ≈ 19.5 ms / 0.59 ms. Consequence for a kernel upload: a full
`0x7000`-byte upload (28 × `0x400` blocks) is not bounded by one relock
window — frames must only keep arriving within the inter-frame window, and a
mid-upload relock is recoverable (`10 85`, fixed `27 01/02`, `B1 00 B2 00`,
restart `34`/`36`).

Dynamic (re-runnable, 11 tests; log
[`dynamic_handover_oncar_log.txt`](dynamic_handover_oncar_log.txt)):
`test_sbl_relock_is_inactivity_timeout` — `3E 01` every 100k cycles keeps the
latches for 1M cycles (counter stays `< 0x5f6`); idle afterwards relocks at
`>= 0x5f6` after ~390k cycles, then `22 D1 00` → `81` and `27 01` → `55 AA 55`
again. `test_sbl_multiframe_interframe_timeout_aborts_transfer_only` — FF with
no CF aborts at `>= 0x2e` (~12k cycles, latches intact); CFs every 5k cycles
reset the counter and the block completes (`7F 36 72` for a `0x20` block).
