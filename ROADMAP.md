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
- Memory map (`docs/architecture/design/README.md` §1): vectors 0x0–0x3ff, code
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
- **38/38 tests pass.** Details: `utilities/scripts/emu/README.md`,
  `docs/architecture/emulator-re-guide.md`.
- Fidelity items closed during hardening: E2 (sensor inputs on real read paths),
  E3 (WDT IVT slot 0x358), E4 (RCAN model + CAN RX interrupt on inject),
  E5 (NMI pin = SYSC peripheral, guessed overrides removed), E6 partial
  (CAN RX + scheduler autonomous). See register below.

### P2 — Completed labeling passes (2026-10-31)

- **Ignition timing**: thread §9 final-BTDC equation verified/corrected (blend
  0x123da/0x124d6, clamp 0x121fc/0x12300), dynamically bit-exact in the
  emulator, then re-verified at the binary level (min-advance constants
  corrected to −25.0/−58.5°). 15 functions + 22 RAM + 17 tables labeled.
  → `docs/investigations/60E15120_N3J1E/ignition_timing_report.md`
- **OS scheduler / IVT / CAN-UDS**: task table 0x4998 + ctrl block labeled, IVT
  at VBR 0x7fc50 mapped, dispatch table 0x5f10c PID 0x43 → handler 0x56b8a
  (record 0x5f268) verified dynamically. 27 functions + 16 RAM + 9 tables.
  → `docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md`
- **Streetport diff** (60E0G500): tuned vs stock = calibration-only (≥0x6c000);
  rev limiter float32 at 0x6d54c (9000.0 → 5500/9500/10000).
  → `docs/investigations/60E0G500_N3ZHEC/2026-10-31-streetport-diff.md`
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

### B. Emulator fidelity hardening (P1 residual)

Foundational for dynamic validation of everything in groups C–E. Most items are
small, targeted fixes.

- **E6 full**: OS task context switch — the 0x3db0 wake (called from ref_setSR
  on ISR exit) still doesn't fire, so UDS response TX is driven via profile
  `uds` entry points (0x680a0 + dispatcher 0x3c2a) instead of an autonomously
  scheduled task. RX side is already autonomous.
- **Renesas Simulator Debugger cross-check** (`compare_traces.py`): tool not
  installed on this machine (no HEW/e² studio); golden trace is self-reproducible,
  external diff pending a machine with the licensed tool.
- **E1** FPU host floats (no SH rounding) — low priority, edge-case impact only.
- **E7** div1/rotcl approximations, cycles ≠ real time — acceptable for now.

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
| E1 | open | FPU uses host floats, no SH rounding |
| E2 | CLOSED 2026-10-31 | Peripheral bases from symbols.tsv; sensors on real ADC/ATU read paths |
| E3 | CLOSED 2026-10-31 | WDT ITI = vector 214 = IVT offset 0x358 (Sh7055h.pdf table 7.3; ROM slot 0x7ffa8 → trampoline 0x30b8); firmware polls TCSR itself, overflow = OVF flag only |
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E5 | CLOSED 2026-10-31 | Guessed `io_read_overrides` (0xffffed18=0x8000) was ICR_W bit15 = NMI pin level — now SYSC peripheral (`nmi_level`), overrides removed from all profiles |
| E6 | partial | ATU-II ch10B tick (CMI10B→0x2c8) + CAN RX interrupt (0x378) fire and run scheduler/CAN poll autonomously; task context switch (0x3db0 wake via ref_setSR) still not triggered → UDS response TX driven via profile `uds` entry points |
| E7 | open | div1/rotcl approximations; cycle counts ≠ real time |

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
file in git history; summary rules in `utilities/scripts/emu/README.md` and
`docs/references/`. Discrepancies are **documented, never silently resolved** —
closing one needs new evidence (ROM bytes, manual table, bench trace, Renesas
diff) + a note in the investigation doc.

---

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per commit,
`hash_binaries.py --check` after touching `binaries/`, emulator changes get a
Renesas differential run. See `AGENTS.md` and `docs/learnings.md`.
