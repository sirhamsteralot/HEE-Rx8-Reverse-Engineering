# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling as much as possible of the Mazda RX-8
(Series 1) PCM firmware (Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB
RAM), building on the prior effort and this session's tooling. Statuses are as of
2026-10-31; **done** items are kept for context, open items are the work list.

## Baseline (done, from prior effort)

- Full static export of ROM `60E15120_N3J1E.bin`: 3,355 functions decompiled, 0
  failures, 154 with warnings (`reverse-engineered/decompiled/60E15120_N3J1E/analysis_summary.json`).
- Memory map (`docs/architecture/design/README.md` §1): vectors 0x0–0x3ff, code
  0x40–0x68e3e, descriptors/calibration 0x6c000–0x7ffff, RAM 0xffff6000–0xffffdfff,
  volatile I/O 0xffffe000–0xffffffff. Firmware ID at 0x2000, cal ID at 0x6c046.
- Labeled subsystems (10-section reports + reviews): knock control, fueling chain,
  intake solenoids, load/fueling model, limiter (`docs/investigations/60E15120_N3J1E/`).
- Ghidra SH-2E pipeline (`utilities/scripts/rx8-pcm-pipeline/`), labels
  (`data/labels/60E15120_N3J1E/`), XML definitions (`data/definitions/`), 10 stock
  ROMs via the pinned submodule.

## Phase 1 — Simulation suite (DONE 2026-10-31, core)

Delivered in `utilities/scripts/emu/` (profiles per ROM/market/model in
`emu/profiles/`):

- Corpus-validated SH-2E CPU core: dispatch table `opdec.py` generated from the real
  disassembly (`gen_opdec.py`), validated 100% against all 168,592 instructions
  (`tests/test_decode_corpus.py`); delay slots, FPU subset, sign-extending
  `mov.w @(disp,pc)`. Unknown opcodes stop loudly.
- Full clean boot of `60E15120_N3J1E`: 50M+ instructions, 0 unknown-opcode faults,
  195k MMIO writes, WDT serviced live (PB15 heartbeat 3.9k/1M cycles, handler 0x31c).
- Bus with ROM/RAM/IO regions, MMIO write log, per-profile `io_read_overrides`;
  peripherals: WDT (keyed 0xA5 writes, overflow → handler), GPIO (+PB15 heartbeat
  log), ADC (scripted sensors), ATU-II/SCI/CAN stubs, **UBC** hardware-break model.
- Golden 200k-instruction boot PC trace (`tests/fixtures/`) reproduces byte-exact.
- Debugger: breakpoints, read/write watchpoints, step/continue, regs/mem/disasm —
  CLI `debug.py` + UI `/api/debug` (`debugger.py`).
- Virtual OBD-II/UDS port: `isotp.py` (unit-tested), `can.py` (inject/tx_log),
  `obd_port.py` (localhost ISO-TP TCP bridging to emulated CAN 0x7E0/0x7E8).
- Interactive UI: `ui.py` + `ui.html` on 127.0.0.1:8080 — sensor inputs, run/step/
  reset, watched outputs (engine load RAM 0xffffc0b4, heartbeats), drive-cycle
  replay of `data/logs/*.csv` (verified: 666p track log drives rpm/load per row).
- Agent tooling: `utilities/scripts/hee.py` CLI (direct, no MCP needed in-session)
  + `.vibe/plugins/hee-re/` MCP plugin for external agents (20 `heeRe.*` tools,
  shared `call_tool`) + `hee-reverse-engineering` skill.
- **24/24 tests pass** (`tests/test_emu.py`, `test_decode_corpus.py`, `test_phase1.py`,
  `test_agent_tools.py`).

### Phase 1 open items (validation & fidelity hardening — these are the E-items below)

- Renesas Simulator Debugger cross-check on the Windows machine
  (`compare_traces.py`) — not yet run.
- Dynamic reproduction of static findings (knock clamp [-10,0]°, injector map 0xd7d4
  → ATU-II 8A–8F, math-helper endpoints) and reimplementation-vs-emulator
  cross-validation — pending.
- Virtual OBD-II answering real UDS requests (needs E4 RCAN model) — pending.
- Sensor inputs wired to the real ADC/ATU read paths (E2) — currently placeholder
  override registers.

## Phase 2 — Static gap closure & labeling (open)

- Triage the 154 warning functions (`decompiler_issues.tsv`); classify
  `non_instruction_ranges.tsv`.
- Label the 99-record dispatch table at 0x5f10c–0x5f5af and task table at 0x4998
  (scheduler/OS + UDS service mapping: 0x10/0x23/0x27/0x34/0x36/0x37).
- Differential labeling across the 10 stock ROMs (byte-match function bodies
  ROM-to-ROM).
- **Ignition-timing labeling pass** (not yet covered): verify/correct the thread's
  final-BTDC equation in the disassembly (thread extract §9).
- Cross-check thread's OL-fueling chain vs our fueling report; verify engine-load
  math (MAF×rpm/60 → g/rev, ×0.6345/charge, PID 0x43) and settle g/rev vs VolEf.
- Settle checksum/CVN (find the incremental hash routine) and bootloader seed/key
  location (D3/D4).
- Map Mode 22 PID handlers cross-ROM (0x5fa0c-area in 60E0FC00; 0x56b8a in 60E15120).
- Label 60E0G500 (new ROM this session) via the pipeline; map the streetport diff
  ranges to descriptors.

### Done this session

- Tuned-vs-stock diff: `binaries/dumps/aron-N3ZHEC-streetportv1_24_*.bin` vs stock
  `aron-N3ZHEC-2026-10-31.bin` (fw 60E0G500) — **calibration-only** (≥0x6c000, no code
  patch); rev limiter = float32 at **0x6d54c** (9000.0 stock → 5500/9500/10000).
  `docs/investigations/60E0G500_N3ZHEC/2026-10-31-streetport-diff.md`.
- RX8Club thread mined + OCR'd: BOOT-mode CN400 pinout (150 Hz WDT feed on pin 3),
  UDS services, seed/key in bootloader, PID 0x43 = g/rev × 1/255 (verified vs our
  labels: handler 0x56b8a), ignition BTDC equation, inline XML addresses verified
  against the real N3ZHEC ROM (`docs/references/rx8club-*.md/.tsv`, `rx8club-ocr/`).
- Watchdog semantics: firmware services internal WDT (TCSR 0xffffec10, keyed 0xa53c)
  and toggles PB15 as external-watchdog heartbeat (0x31c) — now emulated and traced.
- ROM↔cal-ID table verified for 60E0G500/N3ZHEC, 60E15120/N3ZHE (D1 documented).

## Phase 3 — Calibration/table extraction at scale (open)

- Parse lookup descriptors (0x6c000–0x7ffff, `>HBBII`) → dump all tables+axes to
  `data/maps/` with ROM address + source hash (settles D5 numerically).
- Cross-ROM calibration diffs → feed `data/definitions/` corrections.

## Phase 4 — Reimplementation coverage (open)

- Grow `reverse-engineered/reimplementation/` per labeled subsystem (rx8_math,
  rx8_apv done) with host tests **and** emulator cross-checks (Phase 1).

## Phase 5 — Definitions for all ROMs (open)

- Extend `data/definitions/` from 60E15120_N3J1E to the other ROMs
  (incl. 60E0G500 — pinned submodule has a newer ECUFlash XML, 1210 tables) via
  `utilities/scripts/defs-merge/`, citing upstream commits.

## Phase 6 — Toward hardware (gated, open)

- Pre-validate patchers (`utilities/scripts/patchers/`) in the emulator first
  (incl. the "fast RAM logging" patch via the virtual OBD port), then bench.
- Bench BOOT-mode needs ~150 Hz square wave on CN400 pin 3 (thread §8; D9 pinout
  conflict to verify against `Sh7055h.pdf` first). **No vehicle flashing without
  bench validation** (AGENTS.md).

## Fidelity limits & known discrepancies (E = emulator, D = data/docs; all open)

E1 FPU host floats (no SH rounding) · E2 placeholder peripheral bases · E3 WDT IVT
vector slot TODO · E4 RCAN mailbox model stub (OBD answers) · E5 guessed
`io_read_overrides` ready-bits · E6 only WDT interrupts fire (no ATU-II timers) ·
E7 div1/rotcl approximations, cycles ≠ real time.
D1 N3ZHE-vs-N3J1E cal ID · D2 package-pin↔terminal board routing + pinout markers ·
D3 checksum/CVN unverified · D4 seed/key location unknown · D5 g/rev vs VolEf ·
D6 unproven `candidate_*` labels · D7 60E1B800 dual N3* strings · D8 defs copies vs
pinned submodule · D9 BOOT CN400 pinout conflict · D10 PID 0x221410 double-claim.

Full table with locations, impact, and closure plans: previous revision of this
file in git history; summary rules in `utilities/scripts/emu/README.md` and
`docs/references/`. Discrepancies are **documented, never silently resolved** —
closing one needs new evidence (ROM bytes, manual table, bench trace, Renesas diff)
+ a note in the investigation doc.

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per commit,
`hash_binaries.py --check` after touching `binaries/`, emulator changes get a
Renesas differential run. See `AGENTS.md` and `docs/learnings.md`.
