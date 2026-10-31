# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for how to reverse engineer and label as much as possible of the Mazda RX-8
(Series 1) PCM firmware (Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB
RAM), building on the prior effort already in this repo.

## Where we are (baseline, done)

- Full static export of ROM `60E15120_N3J1E.bin`: 3,355 functions decompiled, 0
  failures, 154 with warnings; 337,184 / 524,288 bytes classified as instructions
  (`reverse-engineered/decompiled/60E15120_N3J1E/analysis_summary.json`).
- Memory map established (`docs/architecture/design/README.md` §1): vectors
  0x0–0x3ff, code 0x40–0x68e3e, descriptors/calibration 0x6c000–0x7ffff, RAM
  0xffff6000–0xffffdfff, volatile I/O 0xffffe000–0xffffffff. Reset PC/SP from the
  first two ROM words; firmware ID at 0x2000, calibration ID at 0x6c046.
- Labeled subsystems (10-section reports + reviews): knock control, fueling chain,
  intake solenoids (SSV/VDI/VFAD/APV/secondary air), load/fueling model, limiter,
  plus hardware pin mapping (`docs/investigations/60E15120_N3J1E/`).
- Working Ghidra SH-2E pipeline (`utilities/scripts/rx8-pcm-pipeline/`), label
  records (`data/labels/60E15120_N3J1E/`), XML definitions (`data/definitions/`),
  10 stock ROMs for differential analysis (submodule, pinned commit).
- **Nothing is validated by execution yet** — every finding is static.

## Phase 1 — Simulation suite (run the binaries, validate against them)

**Goal:** an SH-2E simulator that executes the ROM images so static findings can be
checked dynamically, and every future label/reimplementation can be validated by
running code.

**Deliverables**

1. `utilities/scripts/emu/` — emulator core (scaffolded 2026-10-31, config-driven so
   different bins/markets/models run with different peripherals — see
   `emu/profiles/README.md`; add a profile per ROM/variant):
   - SH-2E CPU interpreter (custom, exact — the prior effort already documented the
     encodings in `docs/learnings.md`: PC-relative sign extension, `mov.l` align-down,
     `mova`, FPU opcodes, delay slots). Prefer a hand-written interpreter over
     Unicorn/QEMU: those model SH-4, not SH-2E, and over-accept instructions (the
     reason the local Ghidra Sleigh config exists). Unknown opcodes stop the run
     loudly (`UnknownOpcode`).
   - FPU subset used by the firmware (fmov/fadd/fsub/fmul/fcmp…), with SH rounding
     noted as a limit.
   - **Profiles** (`emu/profiles/*.json`): ROM path + SHA-256 (verified at load),
     memory map from `data/labels/<rom-id>/input.json` + `design/README.md` §1, and
     the peripheral set per market/model/variant (USDM/JDM/EU, 4-/6-port, MT/AT,
     DSC/RKE/immo) — WDT, GPIO (PB15 heartbeat), ADC (scripted sensors), ATU-II,
     SCI, CAN.
2. Peripheral stub layer for the SH7055 registers (map per `docs/references/Sh7055h.pdf`):
   - MMIO reads return scripted values (sensor inputs: ADC channels, e.g. AN6 APV,
     coolant temp); MMIO writes are logged (GPIO actuator writes, ATU-II injector
     pulse registers → decode to per-injector timing).
   - **Watchdog modeled:** TCSR `0xffffec10` / TCNT `0xffffec11` / RSTCSR `0xffffec12` —
     TCNT counts up, TCSR bit `0x80` sets on overflow, un-serviced overflow triggers the
     WDT reset vector; log **PB15 heartbeat toggles** (`service_wdt_overflow_and_toggle_pb15`,
     0x31c) as a "firmware alive" trace observable for golden-trace comparison
     (see `docs/references/rx8club-user-guide-thread.md` §8).
   - Interrupt injection through the vector table; timers driven by a cycle counter.
3. Harness + runner: load ROM from the pinned submodule path, start at reset vector,
   run N cycles or until a stop condition; emit traces (PC stream, register deltas,
   RAM writes, MMIO access log) to `tests/fixtures/` as golden files.
4. `tests/` integration: pytest harness driving the emulator; compare traces against
   golden fixtures; per-function I/O checks (feed inputs, read RAM/MMIO outputs).

**Done when**

- Emulator decodes/executes every instruction in `firmware_disassembly.asm` without
  unknown-opcode faults on a full boot run of `60E15120_N3J1E.bin` (scaffold today:
  boots from the reset vector, stops at the first unimplemented opcode — 9/9 tests
  pass in `tests/test_emu.py`).
- Golden boot trace committed; re-running reproduces it byte-for-byte.
- **Cross-checked against Renesas' own Simulator Debugger** (SuperH family, SH7055)
  on the Windows dev machine: same ROM, same cycle count, PC traces diffed with
  `utilities/scripts/emu/compare_traces.py` — workflow in `utilities/scripts/emu/README.md`.
  Every emulator-core change gets such a differential run before it is trusted.
- Known static findings reproduced dynamically: e.g. knock retard clamped to
  [-10, 0] deg (`reviews/knock_control/`), injector channel map table 0xd7d4 →
  ATU-II 8A–8F, first-order filter endpoints (mirroring `test_rx8_math.c`).
- Emulated outputs match `reverse-engineered/reimplementation/` functions on the
  same inputs (cross-validation of the clean C against the real binary).

## Phase 2 — Close the static gaps

- Triage the 154 warning functions (`decompiled/decompiler_issues.tsv`).
- Classify `non_instruction_ranges.tsv` (vectors, tables, strings, padding, any
  missed code).
- Label the 99-record dispatch table handlers at 0x5f10c–0x5f5af
  (`data/labels/60E15120_N3J1E/diagnostic_dispatch.tsv`) and the task table at
  0x4998 — scheduler/OS understanding.
- Differential labeling across the 10 stock ROMs in the submodule: byte-match
  function bodies ROM-to-ROM to propagate `ref_` names and find code vs.
  calibration differences.
- Settle the checksum/CVN question from the RX8Club thread
  (`docs/references/rx8club-user-guide-thread.md` §4): locate the incremental
  hash routine in the disassembly; map UDS handlers (0x10/0x23/0x27/0x34/0x36/0x37)
  and relate them to the dispatch table at 0x5f10c.
- Verify the thread's engine-load math (MAF×rpm/60 → g/rev, ×0.6345 per-charge,
  Mode 22 PID 0x43) against our fueling report; settle the g/rev vs VolEf (STP
  1.18 kg/m³) axis debate numerically once `data/maps/` is populated.
- **Ignition-timing labeling pass** (not yet covered): use the thread's final-BTDC
  equation (base × cranking-mult + idle blend + CLT − IAT, plus knock retard and
  DSC derates) as the hypothesis to confirm/correct in the disassembly
  (`docs/references/rx8club-user-guide-thread.md` §9).
- Cross-check the thread's OL-fueling chain (max(target, tip-in×baro) × CLT corr,
  implausible-ECT A/B sets, cat-warmup/catalyst model) against our fueling report.
- Locate the bootloader seed/key algorithm in the ROM (thread §10) — relates to the
  UDS 0x27 handler mapping; note immo data is outside flash (EEPROM).
- Map Mode 22 PID handlers cross-ROM: thread OCR shows PID 0x43 (`getMode22EngineLoad`,
  g/rev × 1/255, 0 when injectors off) dispatched at 0x5fa0c–0x5fa14 in 60E0FC00; our
  60E15120 labels put the same handler at 0x56b8a — extend the PID table per ROM.
- Evaluate the "fast RAM logging" patch as a hardware validation aid for Phase 1
  golden traces; cross-check `docs/references/rx8club-inline-defs.tsv` against
  `data/definitions/`.

## Phase 3 — Calibration/table extraction at scale

- Parse lookup descriptors (0x6c000–0x7ffff, descriptor format `>HBBII`) and dump
  every table + axes to `data/maps/` with ROM addresses and source hash.
- Cross-ROM diff of calibration areas to separate per-market/tune differences from
  code; feed corrections into `data/definitions/`.

## Phase 4 — Reimplementation coverage

- Grow `reverse-engineered/reimplementation/` subsystem by subsystem (math helpers
  done; APV done), each with host tests (C11 strict) **and** emulator cross-checks
  from Phase 1. Target: every labeled subsystem has a compilable twin.

## Phase 5 — Definitions for all ROMs

- Extend the merged/reviewed RomRaider + ECUFlash XML definitions
  (`data/definitions/`) from `60E15120_N3J1E` to the other 9 stock ROMs using
  `utilities/scripts/defs-merge/`, citing upstream commits.

## Phase 6 — Toward hardware (gated)

- Use the emulator to pre-validate patchers (`utilities/scripts/patchers/`)
  before any bench work; bench-ECU validation plan; only then consider flashing
  (Rx8Man context in `submodules/Rx8Man`). **No vehicle flashing without bench
  validation** — standing rule in `AGENTS.md`.
- Bench BOOT-mode setup requires an external **~150 Hz 50% square wave on CN400
  pin 3 (WDT)** or the MCU self-resets (RX8Club thread §3/§8; conflicting pinout
  variant in the thread — verify against `Sh7055h.pdf` before wiring).

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per commit, and
`hash_binaries.py --check` after touching `binaries/`. See `AGENTS.md` and
`docs/learnings.md`.
