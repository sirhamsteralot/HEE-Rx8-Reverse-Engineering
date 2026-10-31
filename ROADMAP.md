# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM). Statuses as of
2026-10-31.

**How to read this file.** §Completed is reference only — collapsed summaries with
pointers to the detailed docs. §Open work lists groups B–F in pickup order (group A = calibration extraction,
done — see P3 above; start at B). Items within each group are roughly in
dependency order. Phase numbers (P1–P6)
are kept as tags so existing cross-references still resolve. The discrepancy
register at the bottom tracks every known unknown (E = emulator, D = data/docs);
closing one requires new evidence + a note in the relevant investigation doc —
never silently resolve.

---

## Completed (reference only)

### Baseline (prior effort)

- Full static export of `60E15120_N3J1E.bin`: 3,355 functions decompiled, 0
  failures, 154 warnings (`reverse-engineered/decompiled/60E15120_N3J1E/`).
- Memory map ([`docs/architecture/design/README.md`](docs/architecture/design/README.md) §1): vectors 0x0–0x3ff, code
  0x40–0x68e3e, descriptors/calibration 0x6c000–0x7ffff, RAM 0xffff6000–0xffffdfff,
  volatile I/O 0xffffe000–0xffffffff. Firmware ID at 0x2000, cal ID at 0x6c046.
- Labeled subsystems (10-section reports): knock control, fueling chain, intake
  solenoids, load/fueling model, limiter
  (`docs/investigations/60E15120_N3J1E/`).
- Ghidra SH-2E pipeline (`utilities/scripts/rx8-pcm-pipeline/`, paths via
  `paths.py`), labels (`data/labels/60E15120_N3J1E/`), XML definitions
  (`data/definitions/`), 10 stock ROMs via the pinned submodule.

### P1 — Simulation suite (DONE 2026-10-31)

- Corpus-validated SH-2E CPU core: dispatch table `opdec.py` generated from the
  real disassembly, 100% decode of all 168,592 instructions
  (`tests/test_decode_corpus.py`); delay slots, FPU subset, sign-extending
  `mov.w @(disp,pc)`; unknown opcodes stop loudly.
- Full clean boot of `60E15120_N3J1E`: passes CAN init (RCAN MCR/GSR handshake),
  programs ATU-II/SCI/DMAC, reaches main idle loop 0x3dac, 0 unknown-opcode
  faults; WDT serviced by the firmware's own poll path (keyed 0xa53c writes,
  PB15 heartbeat, service routine 0x31c). `interrupt()` honors VBR (0x7fc50).
- Peripherals at symbols.tsv bases: RCAN0 0xffffe400, RCAN1 0xffffe600, ATU-II
  0xfffff400, SCI 0xfffff000, ADC 0xfffff800, WDT 0xffffec10, DMAC 0xffffecb0,
  GPIO 0xfffff700 — WDT, GPIO, ADC (ADST→ADF), ATU-II (ch10B tick + crank input
  capture), DMAC, RCAN mailbox model, SCI/HCAN1, UBC hardware-break model.
- Golden 200k-instruction boot PC trace byte-exact (`tests/fixtures/`);
  `compare_traces.py` self-check MATCH.
- Debugger (breakpoints, watchpoints, step/continue, regs/mem/disasm) — CLI
  `debug.py` + UI `/api/debug`. Virtual OBD-II/UDS port (`isotp.py`, `can.py`,
  `obd_port.py` — localhost ISO-TP TCP). Interactive UI (`ui.py` + `ui.html` on
  127.0.0.1:8080) with sensor inputs wired to real ADC/ATU read paths, watched
  outputs, drive-cycle replay of `data/logs/*.csv`.
- Dynamic validation harness (`harness.py` + `tests/test_phase1_dynamic.py`):
  math helpers vs `rx8_math.c` reimplementation, knock clamp 0x13bd2 = [−10,0]°,
  injector map 0x8a68(ch)→DCNT8x/GR1x per ROM 0xd7d4, ADC read path 0x6884,
  RCAN RX/TX through the ROM's own driver, Mode 22 dispatch 0x5774c.
- Agent tooling: `utilities/scripts/hee.py` CLI + `.vibe/plugins/hee-re/` MCP
  plugin (20 `heeRe.*` tools) + `hee-reverse-engineering` skill.
- **38/38 tests pass.** Details: [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md),
  [`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md).
- Fidelity items closed during hardening: E2 (sensor inputs on real read paths),
  E3 (WDT IVT slot 0x358), E4 (RCAN model + CAN RX interrupt on inject),
  E5 (NMI pin = SYSC peripheral, guessed overrides removed), E6 partial
  (CAN RX + scheduler autonomous). See register below.

### P2 — Completed labeling passes (2026-10-31)

- **Ignition timing**: thread §9 final-BTDC equation verified/corrected (blend
  0x123da/0x124d6, clamp 0x121fc/0x12300), dynamically bit-exact in the
  emulator, then re-verified at the binary level (min-advance constants
  corrected to −25.0/−58.5°). 15 functions + 22 RAM + 17 tables labeled.
  → [`docs/investigations/60E15120_N3J1E/ignition_timing_report.md`](docs/investigations/60E15120_N3J1E/ignition_timing_report.md)
- **OS scheduler / IVT / CAN-UDS**: task table 0x4998 + ctrl block labeled, IVT
  at VBR 0x7fc50 mapped, dispatch table 0x5f10c PID 0x43 → handler 0x56b8a
  (record 0x5f268) verified dynamically. 27 functions + 16 RAM + 9 tables.
  → [`docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md)
- **Streetport diff** (60E0G500): tuned vs stock = calibration-only (≥0x6c000);
  rev limiter float32 at 0x6d54c (9000.0 → 5500/9500/10000).
  → [`docs/investigations/60E0G500_N3ZHEC/2026-10-31-streetport-diff.md`](docs/investigations/60E0G500_N3ZHEC/2026-10-31-streetport-diff.md)
- **RX8Club thread mined + OCR'd**: BOOT-mode CN400 pinout (150 Hz WDT feed pin
  3), UDS services, seed/key in bootloader, PID 0x43 = g/rev × 1/255, ignition
  BTDC equation — inline XML addresses verified against the real N3ZHEC ROM.
  → `docs/references/rx8club-*.md/.tsv`, `rx8club-ocr/`
- **Watchdog semantics**: internal WDT (TCSR 0xffffec10, keyed 0xa53c) +
  external PB15 heartbeat (0x31c) — emulated and traced.
- **ROM↔cal-ID table** verified for 60E0G500/N3ZHEC, 60E15120/N3ZHE (D1 documented).

### P3 — Calibration extraction (DONE 2026-10-31)

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live.

### B. Emulator fidelity hardening (P1 residual) — partially done 2026-10-31

Foundational for dynamic validation of everything in groups C–E.

- **E1 CLOSED 2026-10-31**: every FPU result rounded to float32 (SH-2E FR
  registers are single precision); `harness.call` f32-rounds float args.
  Filter 0x23b0 now bit-exact vs the reimplementation (was the last E1 diff).
- **E7 CLOSED 2026-10-31 (div1/rotcr)**: ROTCR was aliased to ROTCL (wrong
  direction — 21 ROM sites); DIV1 lacked the Q/M SR bits and did no arithmetic.
  Both now implement the full Renesas algorithm (SR bit8=Q, bit9=M per
  Sh7055h.pdf fig 2.2; DIV1 pseudocode per the SH instruction-set reference).
  Validated against the ROM's own division routine ref_LongFunc 0x2158 as
  oracle (r4 = exact quotient). Cycles ≠ real time remains (accepted).
- **Interrupt masking added 2026-10-31**: prioritized interrupts below the SR
  I3-I0 mask are now deferred and delivered when ldc/rte lower the mask
  (SH-2E manual 7.2.5) — previously every interrupt fired immediately.
- **E6 partial → narrowed 2026-10-31**: traced precisely. CAN RX ISR exits via
  plain RTE, so the 0x3db0 wake check (ref_setSR 0x3934 with r4==0) never runs
  on that path; the OS tick (ATU-II ch10B CMI10B 0x2c8) never fires because the
  ROM arms it from task[8] (0x648e→0x759e→0x7778→0x7b58, OCR10B=table 0xd76d)
  which needs a scheduler pass that needs the tick — boot-ordering circularity
  in the partial peripheral model. Verified gates: with CMI10B firing, the
  0x3db0 wake check runs (165 hits/500k cycles); with the vehicle-present latch
  word 0xffff9ec8 bit0=1, uds_entry 0x680a0 fires autonomously from can_rx_poll
  0x11d88. Remaining: autonomous response TX needs the ROM's task[8]/task[17]
  to run at boot (arm tick + poll vehicle inputs) — i.e. the emulator must
  deliver the first scheduler pass; until then the OBD port drives the profile
  `uds` entry points (0x680a0 + 0x3c2a) for the response side. RX side autonomous.
- **Renesas Simulator Debugger cross-check** (`compare_traces.py`): tooling now
  installed (HEW 9.4.3 + SH-2E simulator Sdsh2e.dll + SH7055F device files);
  workspace + SH-2E simulator session created and connected, ROM offered at 0x0.
  External trace diff still pending — this scripted session cannot inject
  keyboard input into HEW's command control, and `hprojgen.exe` is missing from
  the install. Manual finish steps in `utilities/scripts/emu/README.md`. Our
  200k trace re-verified MATCH vs the golden fixture after the E1/E7/interrupt
  fixes.

### C. Static labeling & gap closure (P2 residual) — base ROM first

Per-ROM work on `60E15120_N3J1E` before propagating cross-ROM (group D).
Use the emulator for dynamic verification where useful (see group B).

- Label the remaining **98 records** of the dispatch table at 0x5f10c–0x5f5af +
  full UDS service mapping (services 0x10/0x23/0x27/0x34/0x36/0x37). One record
  done (PID 0x43 → 0x56b8a at 0x5f268).
- Triage the **154 decompiler warning functions** (`decompiler_issues.tsv`);
  classify `non_instruction_ranges.tsv`.
- Cross-check the thread's OL-fueling chain vs our fueling report; verify
  engine-load math (MAF×rpm/60 → g/rev, ×0.6345/charge, PID 0x43).
- **Deepen `fueling_control_report.md` (further investigation needed — see the
  marker at the top of that report)**: the report reads shallow because the
  load calculation is not in it (it lives in `load_fueling_report.md` —
  cross-reference it, don't duplicate). Also: trace the untraced adder writers
  into `fuel_correction_sum` (b0d0/c0c8/ae08/b21c/c104/cde0/ae10) and
  `DAT_ffffadec`/`DAT_ffffc644`; resolve fuel-cut arbitration, injection-angle
  semantics (tables 0x68ef8/0x68f0c/0x68f20), cold-start degenerate body, MAF
  fault latching (0x19f4e/0x19f40), PID 0x1410, and the 0x4ab8 task-record
  dispatch; map descriptor addresses to P3-extracted `data/maps/` table names;
  dynamically verify the fuel chain in the emulator via `harness.py`.
- **Settle D5 (g/rev vs VolEf)**: trace PID 0x43 handler 0x56b8a to the specific
  extracted table in `data/maps/60E15120_N3J1E/` it reads, then compare the
  handler's computed value against the table + scaling numerically.
- Settle **checksum/CVN** (find the incremental hash routine) — D3 — and
  **bootloader seed/key location** — D4.
- Label **60E0G500** via the pipeline (streetport diff ranges already mapped to
  descriptors via P3 — see calibration_extraction_report.md §7).
### D. Cross-ROM propagation (P2/P5) — depends on P3 + C for the base ROM

- Differential labeling across the 10 stock ROMs (byte-match function bodies
  ROM-to-ROM).
- Map Mode 22 PID handlers cross-ROM (0x5fa0c-area in 60E0FC00; 0x56b8a in
  60E15120).
- Extend `data/definitions/` from 60E15120_N3J1E to all ROMs (incl. 60E0G500 —
  pinned submodule has a newer ECUFlash XML, 1210 tables) via
  `utilities/scripts/defs-merge/`, citing upstream commits.

### E. Reimplementation coverage (P4) — depends on C

- Grow `reverse-engineered/reimplementation/` per labeled subsystem
  (`rx8_math`, `rx8_apv` done) with host tests **and** emulator cross-checks
  (`harness.py` + `tests/test_phase1_dynamic.py` pattern).

### F. Toward hardware (P6) — GATED

No vehicle flashing without bench validation (AGENTS.md rule 10).

- Pre-validate patchers (`utilities/scripts/patchers/`) in the emulator first —
  including the "fast RAM logging" patch via the virtual OBD port — then bench.
- Bench BOOT-mode needs ~150 Hz square wave on CN400 pin 3 (thread §8; verify
  **D9** pinout conflict against `Sh7055h.pdf` first).

---

## Discrepancy register

### Emulator fidelity (E-items)

| ID | Status | What |
|----|--------|------|
| E1 | CLOSED 2026-10-31 | FPU results rounded to float32 per op; harness f32-rounds float args; filter 0x23b0 bit-exact |
| E2 | CLOSED 2026-10-31 | Peripheral bases from symbols.tsv; sensors on real ADC/ATU read paths |
| E3 | CLOSED 2026-10-31 | WDT ITI = vector 214 = IVT offset 0x358 (Sh7055h.pdf table 7.3; ROM slot 0x7ffa8 → trampoline 0x30b8); firmware polls TCSR itself, overflow = OVF flag only |
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E5 | CLOSED 2026-10-31 | Guessed `io_read_overrides` (0xffffed18=0x8000) was ICR_W bit15 = NMI pin level — now SYSC peripheral (`nmi_level`), overrides removed from all profiles |
| E6 | partial (narrowed 2026-10-31) | CAN RX (0x378) autonomous; wake 0x3db0 fires when CMI10B tick delivered; UDS entry 0x680a0 gated by vehicle latch word 0xffff9ec8 bit0; OS tick arming (task[8]→0x7778) circular without first scheduler pass → response TX still via profile `uds` entry points; pending-interrupt delivery on ldc/rte added |
| E7 | CLOSED 2026-10-31 (div1/rotcr) | full Q/M DIV1 (SR bits 8/9) + ROTCR direction fixed, validated vs ROM div routine 0x2158; cycle counts ≠ real time remains (accepted) |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D3 | open | checksum/CVN unverified — incremental hash routine not yet found |
| D4 | open | bootloader seed/key location unknown |
| D5 | open | g/rev vs VolEf — resolve in group C: trace PID 0x43 (handler 0x56b8a) to a named table in data/maps/ |
| D6 | open | unproven `candidate_*` labels |
| D7 | open | 60E1B800 dual N3* strings |
| D8 | open | defs copies vs pinned submodule — dedupe per AGENTS.md rule 4b |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D10 | open | PID 0x221410 double-claim |

Full table with locations, impact, and closure plans: previous revision of this
file in git history; summary rules in [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md) and
`docs/references/`. Discrepancies are **documented, never silently resolved** —
closing one needs new evidence (ROM bytes, manual table, bench trace, Renesas
diff) + a note in the investigation doc.

---

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per commit,
`hash_binaries.py --check` after touching `binaries/`, emulator changes get a
Renesas differential run. See [`AGENTS.md`](AGENTS.md) and [`docs/learnings.md`](docs/learnings.md).
