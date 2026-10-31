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

Closed 2026-10-31 (this session; see `tests/test_phase1_dynamic.py`):

- **Dynamic reproduction of static findings + reimplementation cross-validation**
  via the new `harness.py` direct-call harness: math helpers 0x23b0/0x23dc/0x23e4/
  0x23f4/0x2404 match the `rx8_math.c` reimplementation (bit-exact except the
  filter, which differs only by FMA/E1 double semantics); knock clamp 0x13bd2
  dynamically clamps to [-10, 0] deg at 1000/3000 rpm and to 0 at 6000 rpm;
  injector map dynamically confirmed: 0x8a68(ch) writes DCNT8x/GR1x exactly per
  ROM table 0xd7d4 (ch0→8A, ch1→8C, ch2→8E, ch3→8B, ch4→8D, ch5→8F).
- **E4 RCAN model**: `can.py` now models HCAN0 at 0xffffe400 (W1C pending regs,
  MCR/GSR reset handshake, mailbox masks per ROM 0xd914). Virtual OBD-II port
  drives the ROM's own path: inject on 0x7e0 → RXPR → FUN_00011d88 moves it to the
  UDS buffer 0xffffddc8; ref_txCAN_EventBased(0x99b0, desc 0x4e00c) → 0x7e8 in
  tx_log; Mode 22 dispatch 0x5774c (id 0x0043 → handler 0x56b8a) verified.
  `obd_port.py` pumps these entry points (profile `uds` section). Fully
  OS-scheduled round trip still needs the tick (E6).
- **E2 sensor inputs on real read paths**: ADC model serves ADDRnH/L channels with
  the ADCSR/ADCR-ADST→ADF handshake (ref_sensorADCRead 0x6884 consumes them);
  ATU-II at 0xfffff400 with crank input capture into ICR0AH/ICR10AH (`set_rpm`);
  profiles map sensors to AN3/AN4/AN6/AN10/AN28/AN29 + crank — no more placeholder
  override registers. Profile peripheral bases fixed to symbols.tsv (RCAN0 was
  misplaced at 0xffffe800, ATU-II at 0xffffe400); RAM base fixed to 0xffff6000;
  ROM region is now read-only; DMAC model added (CHCR DE → transfer + TE);
  `interrupt()` honors VBR (0x7fc50) and pushes SR/PC. Boot now passes CAN init
  and reaches the main idle loop 0x3dac clean (golden trace regenerated).

Still open:

- Renesas Simulator Debugger cross-check (`compare_traces.py`) — the tool is not
  installed on this Windows machine (no HEW/e² studio); golden trace regenerated
  and self-reproducible, external diff pending a machine with the licensed tool.
- Full OS tick (CMI10B → 0x2ec0) runs, but task contexts need it for autonomous
  scheduling (E6) — the OBD port drives the ROM entry points directly meanwhile.

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

E1 FPU host floats (no SH rounding) · E2 CLOSED 2026-10-31 (bases from symbols.tsv;
sensors on real ADC/ATU paths) · E3 WDT IVT vector slot TODO (firmware polls TCSR,
calls 0x31c itself; overflow = OVF flag only) · E4 RCAN mailbox model done for the
diag path 2026-10-31 (full interrupt/mailbox fidelity open) · E5 guessed
`io_read_overrides` ready-bits · E6 ATU-II tick modeled (CMI10B→0x2c8) but the OS
scheduler's task contexts still need it — OBD port drives entry points directly ·
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
