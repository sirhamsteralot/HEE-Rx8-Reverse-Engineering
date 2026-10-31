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

**Status: implemented 2026-10-31** — full boot of 60E15120_N3J1E runs 50M+ instructions
with zero unknown-opcode faults; WDT PB15 heartbeat live (3.9k toggles / 1M cycles);
golden 200k-instruction PC trace in `tests/fixtures/` reproduces byte-exact;
18/18 tests pass (`tests/test_emu.py`, `tests/test_decode_corpus.py`, `tests/test_phase1.py`).
Virtual OBD-II port (`obd_port.py` + `isotp.py`) and interactive UI (`ui.py --ui`)
scaffolded; UI sensor injection + `data/logs/` replay work against the booted ROM.

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
4. **Virtual OBD-II/UDS port** (design: `docs/architecture/emulated-obd.md`) —
   ISO-TP over the emulated CAN (0x7E0/0x7E8), TCP/PTY port so RomRaider Logger or a
   Python UDS client connects to the emulated PCM *as if it was in a real car*;
   UDS runs on the ROM's own handlers (dispatch table 0x5f10c; PID 0x43 → 0x56b8a).
   Validate against real-car log captures as golden fixtures.
5. **Interactive UI** (design: `docs/architecture/emulator-ui.md`) —
   `emu.py --ui` serves a localhost browser UI (stdlib only) to set sensor inputs
   (RPM, load, MAF, coolant/IAT, throttle, λ, knock, voltage…) which are injected
   through the hardware paths the firmware reads (ADC/port/timer regs per the
   profile's `sensors` map), run/step/reset, watch MMIO outputs + WDT heartbeats,
   and **replay `data/logs/*.csv` drive cycles** as scripted inputs, comparing
   emulated OBD PID outputs against the original log.
5. `tests/` integration: pytest harness driving the emulator; compare traces against
   golden fixtures; per-function I/O checks (feed inputs, read RAM/MMIO outputs);
   OBD-path tests (PID responses, 0x23 dump parity).

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
- **OBD path behaves like a real car:** Mode 22 PID responses match our static
  findings (PID 0x43 = g/rev × 1/255, 0 with injectors off) and real-car log
  captures; UDS 0x23 dump of emulated memory equals the loaded ROM byte-for-byte;
  RomRaider Logger can log from the virtual port (`docs/architecture/emulated-obd.md`).
- **UI drives the emulation:** set RPM/load/sensors in the browser UI, run, and the
  firmware reacts; replaying a `data/logs/` CSV reproduces the logged values
  (`docs/architecture/emulator-ui.md`).
- **Debugging like the original MCU:** execution breakpoints, memory read/write
  watchpoints, single-step/continue, register + memory inspection, disassembly at
  PC — CLI (`utilities/scripts/emu/debug.py`) and UI (`/api/debug`), plus a modeled
  SH7055 **UBC** hardware-break peripheral (`peripherals.UBC`). Implemented
  2026-10-31, tested in `tests/test_phase1.py`.
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
- **Diff user-tuned vs stock ROMs:** done 2026-10-31 for
  `aron-N3ZHEC-streetportv1_24_*.bin` vs stock `aron-N3ZHEC-2026-10-31.bin` (fw
  60E0G500) — see `docs/investigations/60E0G500_N3ZHEC/2026-10-31-streetport-diff.md`:
  cal-only changes (≥0x6c000), rev limiter = float32 at **0x6d54c** (9000 stock →
  5500/9500/10000). Remaining: map changed cal ranges to descriptors/tables, and
  label 60E0G500 functions (only 60E15120_N3J1E is labeled) so 0x6d54c's consumer is
  named. Same diff technique applies to any future tuned dump.
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
- Evaluate the "fast RAM logging" patch as a validation aid — first against the
  emulator's virtual OBD port (`docs/architecture/emulated-obd.md`), then real
  hardware; cross-check `docs/references/rx8club-inline-defs.tsv` against
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

## Fidelity limits & known discrepancies (goal: as close to real hardware as possible)

Scanned 2026-10-31 across emulator, profiles, docs, and labels. Each item lists where
it lives, the fidelity impact, and how we close it.

### Emulator vs. real SH7055 hardware

| # | Item | Where | Impact | Close by |
|---|---|---|---|---|
| E1 | FPU uses host floats — SH-2E rounding modes / exception bits not modeled | `utilities/scripts/emu/README.md` Limits | float results can differ in last ulp vs. real ECU | implement FPSCR rounding (RNE etc.) + fr bank; diff vs Renesas sim traces |
| E2 | Peripheral register bases are placeholders (`_note` in profiles: ATU-II 0xffffe400, CAN 0xffffe800, SCI 0xfffffe00) | `emu/profiles/*.json` | MMIO addresses may be wrong per register | extract full SH7055 register map from `docs/references/Sh7055h.pdf` + reference project's `regs_7055_*.csv` |
| E3 | WDT overflow jumps direct to handler 0x31c; real IVT vector slot TODO | profiles `wdt.config._note` | interrupt entry path differs from hardware | find WOVI vector slot (Sh7055h.pdf IVT / `ivt_7055.csv`) |
| E4 | CAN/RCAN model is a register-file stub; OBD responses depend on the ROM's CAN driver running correctly | `emu/can.py`, `emu/obd_port.py` | UDS over virtual OBD may not answer until RCAN mailboxes are modeled | model mailboxes/interrupts per manual; test with a Mode 22 request in-emulation |
| E5 | `io_read_overrides` (e.g. 0xffffed18=0x8000) are guessed "ready" bits | profiles `memory.io_read_overrides` | firmware may take wrong paths if the real bit semantics differ | identify the peripheral at 0xffffed18 from the manual and model it properly |
| E6 | Only WDT overflow fires interrupts; no ATU-II timer interrupts yet | `emu/peripherals.py` | scheduler/task timing not hardware-realistic | model ATU-II timers → their vector slots; verify task-table cadence |
| E7 | `div1` algorithm and rotcl edge cases are approximations; "cycles" ≠ real time | `emu/sh2e.py` | rare arithmetic divergence; no cycle-accurate timing | property-test vs. corpus + Renesas diff runs; document timing model |

### Data / documentation discrepancies (kept deliberately, do not "fix" silently)

| # | Item | Where | Close by |
|---|---|---|---|
| D1 | `60E15120_N3J1E.bin` contains cal ID `N3ZHE` at 0x6c046 (filename/XML say N3J1E) | `docs/architecture/design/README.md` §1 | donor-ECU provenance (part number) — leave bytes untouched |
| D2 | Package-pin ↔ connector-terminal is board routing, unresolved; pinout has 5L unread, `*`/`†` markers, unverified mirrored pairs | `docs/architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md` Limits | bench ECU board trace / photos |
| D3 | Checksum/CVN algorithm unverified (forum claims conflict) | thread extract §4 | find the incremental hash routine in the disassembly |
| D4 | Bootloader seed/key algorithm location unknown | thread §10 | locate in ROM; relate to UDS 0x27 handler |
| D5 | Load axis semantics disputed: g/rev vs VolEf (STP 1.18 kg/m³) | thread §9 | numeric check once `data/maps/` is populated |
| D6 | Dozens of `candidate_*` labels unproven (diag readers, knock/fuel-cut candidates) | `data/labels/60E15120_N3J1E/integrated_names.json` | binary-level verification per pass (AGENTS.md rule 7) |
| D7 | `60E1B800` shows two N3* strings; unsupported by tools | thread §2 | dump + compare against known ROMs |
| D8 | Our `data/definitions/` copies are from older upstream commits than the pinned submodule (e.g. ECUFlash 60E0G500.xml) | `data/README.md` | deliberate re-sync per ROM when needed |
| D9 | BOOT-mode CN400 pinout conflict in the thread (pin 5/7 vs pin 6/8 variant) | thread §3/§8 | verify against `Sh7055h.pdf` + board before any bench wiring |
| D10 | Logger def caveat: PID 0x221410 claimed by two definitions | fueling report | fix defs deliberately, with evidence |

Rule: discrepancies are **documented, never silently resolved** — resolving one
requires new evidence (ROM bytes, manual table, bench trace) and a note in the
investigation doc.

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per commit, and
`hash_binaries.py --check` after touching `binaries/`. See `AGENTS.md` and
`docs/learnings.md`.
