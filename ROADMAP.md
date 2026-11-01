# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM). Statuses as of
2026-11-01.

**How to read this file.** §Completed is reference only — collapsed summaries with
pointers to the detailed docs. §Open work lists groups E–F in pickup order: groups
A–D are done (group A = calibration extraction, see P3 below; group B = emulator
fidelity, done except the E4/E6 partials tracked in the register; group C = static
labeling & gap closure, items 1–6 all done 2026-10-31; group D = cross-ROM
propagation, items 1–4 done 2026-10-31/2026-11-01), so pick up at group E. Items
within each group are roughly in dependency order. Phase numbers (P1–P6) and group
letters are kept as tags so existing cross-references still resolve. The discrepancy
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
- **61/61 tests pass** (2026-10-31). Details: [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md),
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

- 587 tables extracted from `60E15120_N3J1E` (478 RX8Defs-matched + 109 unnamed),
  381–587 across all 10 stock ROMs + 4 own dumps, 0 non-monotonic axes; cross-ROM
  structural diff; streetport tunes mapped to 15–17 named descriptors.
  → [`docs/investigations/60E15120_N3J1E/calibration_extraction_report.md`](docs/investigations/60E15120_N3J1E/calibration_extraction_report.md);
  artifacts: `data/maps/` (`extract_maps.py` + `diff_maps.py`).

### B. Emulator fidelity hardening (P1 residual) — DONE 2026-10-31 except the E4/E6 partials

Collapsed from the open-work list 2026-10-31 (work complete; the open partials are
tracked as E4/E6 in the register below). Closed: E1 (f32 rounding, filter 0x23b0
bit-exact), E7 (full Q/M DIV1 + ROTCR direction, oracle = ROM div routine 0x2158),
interrupt masking on ldc/rte, E2/E3/E5; E6 narrowed (CAN RX autonomous; response TX
still via profile `uds` entry points). Renesas Simulator Debugger cross-check DONE:
NMI-loop segment MATCH 20000/20000; full-boot-from-reset MATCH 147/147 then one
peripheral-pin divergence (GPIO PLIOR_W 0xfffff756 bit3) — zero CPU-caused divergence.
→ [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md),
[`docs/learnings.md`](docs/learnings.md) §group B; register below for E4/E6.

### C. Static labeling & gap closure (P2 residual) — DONE 2026-10-31 (items 1–6, D item 1)

#### C item 1 — UDS/Mode-22 dispatch tables — DONE 2026-10-31

All 99 Mode 22 PID records (0x5f10c) + 29 UDS service records (0x5eb40) + sub-PID
table 0x5f5b2 labeled; ISO-TP frame dispatch 0x6842c, service router 0x68dac; 177
functions + 63 RAM cells + 3 tables renamed; re-verified against raw disassembly and
dynamically (full 99-PID sweep, 15-service routing; 61/61 tests).
→ [`docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md`](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md);
labels: `data/labels/60E15120_N3J1E/uds_dispatch_labels.json`.

#### C item 2 — Decompiler-warning triage + non-instruction-range classification — DONE 2026-10-31

All 154 warning functions triaged (151 benign, 3 actionable → all resolved: record
dispatch tables 0x5ea08 via 0x54d90 and 0x5eb18 via 0x55a7c recovered from ROM; orphan
2-byte artifact 0x33b6 proven unreferenced); all 1,759 non-instruction ranges (187,104
bytes) classified with pc-relative referrer evidence. No labels upgraded.
→ [`docs/investigations/60E15120_N3J1E/decompiler_triage_report.md`](docs/investigations/60E15120_N3J1E/decompiler_triage_report.md);
`utilities/scripts/rx8-pcm-pipeline/triage_export.py`, `decompiler_issues_triaged.tsv`,
`non_instruction_ranges_classified.tsv`, `data/labels/60E15120_N3J1E/triage_export.json`.

#### C items 3-4 — Fueling deepening + engine-load units (D5) — DONE 2026-10-31

- **D5 closed**: `engine_load_ffffc0b4` and PID 0x43 are VolEf-like cell units
  (g/rev × 0.6345 = 1/(1.308 L × 1.205 g/L)), proven by the max-load clamp
  (tbl_0x6b200×0x6b214×0x6b1ec = 0.58–1.29 cell units ↔ 0.92–2.03 g/rev) matching
  the extracted load axes (tbl_06aa48 axis_y 0.0625–1.25). Thread corrections:
  MAF×60/rpm (not ×rpm/60), 0.6345 = VolEf (not g/combustion), PID 0x43 = VolEf
  ×1/255 (not g/rev). → load_fueling_report.md "Update 2026-10-31".
- **fueling_control_report.md §10 deepening**: all `fuel_correction_sum` adder
  writers traced (LTFT b0d0, product-sums c0c8/c104, CL terms ae08/ae10, MAF-%
  b21c, transient cde0, lambda adf8→adec, cat-temp c644); fuel-cut arbitration
  0xedc4/0x18cfe/0xee82; injection-angle tables 0x68ef8/f0c/f20 = per-injector max
  open-angle degrees (consumer 0xff32); cold-start 0x1ddfc byte-verified
  degenerate (pool floats 0x71060/0x71064 = 0.0); MAF latch 0x19f4e/0x19f40;
  0x4ab8 = task rec[18].entry in a 19-record table based at 0x4990 (corrects
  os_scheduler_can_ivt_report.md §11); descriptor→data/maps mapping; thread OL
  chain confirmed (0x1ee4a: max(baro·tipin, target)×coolant, +1.0 lambda decimal
  part). Dynamic: `tests/test_fuel_chain_dynamic.py` (65/65 pytest).

#### C item 5 — Checksum/CVN (D3) + seed/key (D4) — DONE 2026-10-31

- **D3 closed**: incremental checksum routine = 0x5a3f4 (dual-u16 additive sum
  over app flash 0x2000-0x7ffff in 0x1000-byte sections per call, skipping hole
  0x7fb00-0x7fb7f), finalized by 0x5a714 into RAM 0xffff9104/0xffff910c,
  diag-readable via 0x55bda (case of 0x55a7c) -> 0x5a5a6. Not a CRC. App flash
  services 0x34/36/37 are stubs; Mode 09 PID 6 stubbed — checksum fixup is
  host-side (Rx8Man), as the thread suspected.
- **D4 closed**: app UDS 0x27 seed/key = 0x55f5e (ATU-II timer seed ->
  0xffffd1d5-d1d8) + 0x5609e (64-round shift/xor key verify, fixed "MazdA" key at
  0x5f084); bootloader (SBL 0x0-0x1fff, `*SBL_END` marker at 0x1ff4) 0x27 at
  0x1858: seed 55 AA 55, key 4D AC CD. SBL flash path 0x34/0x36/0x37/0xb1 mapped
  (0x1ad6/0x1c04/0x1d30/0x1d78; 0x36 stages 0x400-byte blocks at 0xffff6000+ and
  jumps on `*SBL_END` via 0x1090).
- → [uds_mode22_dispatch_report.md §12](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md).

#### C item 6 + D item 1 — 60E0G500 pipeline export + cross-ROM differential labeling — DONE 2026-10-31

- 60E0G500/N3ZHEC (`binaries/dumps/aron-N3ZHEC-2026-10-31.bin`) exported via
  Ghidra 12.1.2 headless into `reverse-engineered/{decompiled,disassembly}/60E0G500_N3ZHEC/`
  (3,200 functions, 0 failures; all 166,294 instruction words byte-verified;
  `data/labels/60E0G500_N3ZHEC/input.json` provenance). Recipe/log in `input/`
  (uncommitted).
- `utilities/scripts/cross_rom_match.py`: byte-match of base-ROM function bodies
  across all 10 stock ROMs + 4 own dumps → 33,644 matches, 2,999 propagated
  aliases (`data/labels/cross_rom_function_matches.tsv`,
  `cross_ecu/cross_rom_function_aliases.tsv`, `cross_rom_match_summary.json`).
  60E0G500: 2,582 matches / 262 aliases; streetport tunes identical on code.
- → [60E0G500_N3ZHEC/2026-10-31-pipeline-export.md](docs/investigations/60E0G500_N3ZHEC/2026-10-31-pipeline-export.md),
  [cross_ecu/cross_rom_differential_labeling.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_differential_labeling.md).

### D item 2 — Mode 22 PID handlers cross-ROM — DONE 2026-11-01

- Mode 22 dispatch table located in all 14 ROMs by pool ref + self-consistent
  count byte (family A: 99 records at 0x5e4e8/0x5e740/0x5f10c/0x5e7b8/0x5fb48/0x5f8b0;
  family B: 110 records at 0x5d994/0x5dc2c/0x64d0c; 60E32000_N3M5E: 113 at 0x651bc),
  1,444 PID→handler rows mapped (793 byte_match asserted to the same-PID base
  handler, 494 pid_match, 58 unmapped extra PIDs); dynamically verified on
  60E0G500/N3ZHEC (99/99-PID sweep: dispatcher 0x57ef0 hits every mapped handler
  exactly, r0=len+3; 5 non-table PIDs take the NRC 0x31 path).
  → [cross_ecu/cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md);
  artifacts: `data/labels/cross_rom_mode22_pid_handlers.tsv` +
  `cross_rom_mode22_summary.json`, script `utilities/scripts/cross_rom_mode22_map.py`.
  New register item E8 (opdec corpus-keyed; family-B diag dispatch not dynamically
  executable yet).

### D item 3 — cross-ROM labels applied to the 60E0G500_N3ZHEC export — DONE 2026-11-01

- `utilities/scripts/apply_cross_rom_labels.py` applied 236 renames to
  `reverse-engineered/decompiled/60E0G500_N3ZHEC/` (262 byte-match aliases from
  `cross_ecu/cross_rom_function_aliases.tsv` — 28 targets are not function starts
  and were skipped — plus the Mode 22 table labels DAT_0005f8b0 →
  `tbl_diag22_dispatch_records_0005f8b0`, DAT_0005fd56 →
  `tbl_diag22_subpid_supported_bits_0005fd56`): function_index/callgraph/symbols,
  functions/*.c, firmware_decompiled.c + synchronized `named/` view with
  `validation.json`; provenance in
  `data/labels/60E0G500_N3ZHEC/cross_rom_renames_applied.tsv`; pre-change backup
  zip (LFS) in `docs/investigations/60E0G500_N3ZHEC/backups/`. Handler 0x57e66
  (PID 0xc116, pid_match) has no C identifier (mid-function) — provenance only,
  `candidate_`-prefixed per the label ladder. Export header ROM name corrected.
- Per-ROM Mode 22 label TSVs for all 14 ROMs emitted under
  `data/labels/cross_rom/mode22/` for future Ghidra exports; family-B extra PIDs
  stay FUN_-level (no base counterpart).

### D item 4 — ECU definitions extended to all 14 ROMs + D8 dedupe — DONE 2026-11-01

- `utilities/scripts/defs-merge/extend_defs_all_roms.py` identifies every dumped ROM
  by the fw id at 0x2000 (own dumps SHA-256-checked against `binaries/manifest.csv`)
  and emits a standalone per-ROM RomRaider def (base chain + rom block + provenance
  comment) to `data/definitions/romraider/per-rom/<rom-stem>.xml`; 60E15120 uses the
  reviewed block from `rx8defs-merged-60E15120.xml`. 12 of 14 ROMs covered; gaps
  60E0E500 (no upstream block) and 60E1C500 (block commented out upstream @
  `251f54f`). ECUFlash defs exist upstream only for 60E0G500 (1210 tables) and are
  referenced in place. Upstream commits cited: RX8Defs pinned
  `1b3aea274b1e…`, rx8_defs.xml last change `1b3aea2`, ECUFlash @ `aaac6f3`,
  60E15120 merge base `ff5ab4f`.
  → [cross_rom_defs_coverage.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_defs_coverage.md);
  artifacts: `data/definitions/` (per-rom/, coverage.json, README.md) +
  [60E0G500_N3ZHEC/defs-merge/README.md](docs/investigations/60E0G500_N3ZHEC/defs-merge/README.md).
- D8 closed with it: 4 local copies blob-identical to the pinned submodule deleted
  (ecuflash ×2, logger ×2); `upstream-rx8defs/rx8_defs.xml` kept (= upstream
  `ff5ab4f`, differs from pinned HEAD).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live. Groups A–D are complete (see §Completed above, items 1–4 incl. the
2026-11-01 defs extension), so the next pickup is group E.

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
| E8 | open (added 2026-11-01) | opdec.OPMNEM keyed on full 16-bit words from the 60E15120 corpus (9,902 entries); family-B ROMs use operand encodings absent from it (e.g. 0xda29 `mov.l @(0x29*4,pc),r10` in 60E0FC00 dispatcher 0x55c14) → UnknownOpcode; family-B profiles boot but diag dispatch is not dynamically executable until the opcode table is widened. See [cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md) |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID — both strings coexist in-ROM: fw id `60E15120` at 0x2000, `N3J1E_1W.Z05` at 0x6c000, `SW-N3ZHEB000.HEX` at 0x6c043/0x6c046, `15120 ` at 0x6c05c; PIDs 0xe611/0xe21b-0xe21e/0xff40-0xff43 return them (2026-10-31, [uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)) |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D3 | CLOSED 2026-10-31 | checksum/CVN routine found: 0x5a3f4 = incremental dual-u16 additive sum over app flash 0x2000-0x7ffff (0x1000 B/call, skips hole 0x7fb00-0x7fb7f), finalize 0x5a714 -> RAM 0xffff9104/0xffff910c, diag-read via 0x55bda -> 0x5a5a6. Not CRC (no CRC table/poly in ROM). See [uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md) §12.1 |
| D4 | CLOSED 2026-10-31 | seed/key located in both layers: app UDS 0x27 (0x57a64): seed from ATU-II timer 0x55f5e -> 0xffffd1d5-d1d8, key verified by 0x5609e (64-round shift/xor network, fixed key "MazdA" at 0x5f084); flash bootloader (SBL 0x0-0x1fff) 0x27 at 0x1858: seed 55 AA 55, key 4D AC CD literal compare. See uds_mode22_dispatch_report.md §12.2 |
| D5 | CLOSED 2026-10-31 | g/rev vs VolEf settled: `engine_load_ffffc0b4` = VolEf-like cell units (g/rev × 0.6345 = 1/(1.308 L × 1.205 g/L)); PID 0x43 reports that cell × 1/255, not g/rev. Numeric proof: max-load clamp tbl_0x6b200×tbl_0x6b214×tbl_0x6b1ec = 0.58–1.29 cell units ↔ 0.92–2.03 g/rev, matching load axes in data/maps (tbl_06aa48 axis_y 0.0625–1.25). See [load_fueling_report.md](docs/investigations/60E15120_N3J1E/load_fueling_report.md) "Update 2026-10-31" |
| D6 | open | unproven `candidate_*` labels |
| D7 | open | 60E1B800 dual N3* strings |
| D8 | CLOSED 2026-11-01 | 4 local def copies were git-blob-identical to pinned `submodules/RX8Defs` files (raw diff CRLF/LF only) and were deleted per rule 4b; submodule path + commit `1b3aea2…` is the reference. Also settles "pinned has a newer ECUFlash XML": identical 1210 tables, size diff was line endings. See [cross_rom_defs_coverage.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_defs_coverage.md) + [data/definitions/README.md](data/definitions/README.md) |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D10 | open (evidence added 2026-10-31) | PID 0x221410 double-claim — in 60E15120_N3J1E, PID 0x1410 handler 0x56f6c (`diag22_pid1410_injector_pulse_time`) reads `injector_pulse_time_ffffbe24` × 8.0 = injector pulse time; throttle pedal position is PID 0x0011/0x093c (`ffffad5c`/`ffffad44`), not 0x1410. Cross-ROM check still open |

Full table with locations, impact, and closure plans: previous revision of this
file in git history; summary rules in [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md) and
`docs/references/`. Discrepancies are **documented, never silently resolved** —
closing one needs new evidence (ROM bytes, manual table, bench trace, Renesas
diff) + a note in the investigation doc.

---

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per work unit
delivered as a branch + PR against `main` ([`AGENTS.md`](AGENTS.md) §Branch & PR
workflow) with one logical change per commit, `hash_binaries.py --check` after
touching `binaries/`, emulator changes get a Renesas differential run. See
[`AGENTS.md`](AGENTS.md) and [`docs/learnings.md`](docs/learnings.md).
