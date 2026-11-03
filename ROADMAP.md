# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM).

**How to read this file.** §Open work
lists what remains, in suggested pickup order; the discrepancy register at the
bottom tracks every known unknown (E = emulator, D = data/docs) — closing one
requires new evidence + a note in the relevant investigation doc, never a silent
resolve. Tags are stable so cross-references from other docs keep resolving: phases
P1–P6, work groups A–F with item numbers, register IDs E1–E8 / D1–D11. Group ↔ phase
map: A = P3 (calibration extraction), B = P1 residual (emulator fidelity), C = P2
residual (static labeling & gap closure), D = P2/P5 (cross-ROM propagation), E = P4
(reimplementation), F = P6 (toward hardware).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live. Groups A–D are complete; the next pickup is group E:
**E item 1** (reimplementation coverage), then F (gated).

### E. Reimplementation coverage (P4) — depends on C (done)

- **E item 1 (open)** — grow `reverse-engineered/reimplementation/` per labeled
  subsystem with host tests **and** emulator cross-checks (`harness.py` +
  `tests/test_phase1_dynamic.py` pattern). Implemented so far: `rx8_math`, `rx8_apv`,
  `rx8_knock` — knock-retard state machine 0x13a60/0x13b40 +
  `rx8_add_u8_saturate` 0x2478, host tests plus
  `tests/test_knock_retard_dynamic.py` emulator cross-checks.
  Remaining subsystems: fueling chain, load model, ignition timing, intake
  solenoids, limiter.

### F. Toward hardware (P6) — GATED

No vehicle flashing without bench validation (AGENTS.md rule 10).

- **F item 1 (open)** — pre-validate patchers (`utilities/scripts/patchers/`) in
  the emulator first — including the "fast RAM logging" patch via the virtual
  OBD port — then bench.
- **F item 2 (open)** — bench BOOT-mode needs ~150 Hz square wave on CN400 pin 3
  (thread §8; verify **D9** pinout conflict against `Sh7055h.pdf` first).

---

## Discrepancy register

### Emulator fidelity (E-items)

| ID | Status | What |
|----|--------|------|
| E1 | CLOSED | FPU results rounded to float32 per op; harness f32-rounds float args; filter 0x23b0 bit-exact |
| E2 | CLOSED | Peripheral bases from symbols.tsv; sensors on real ADC/ATU read paths |
| E3 | CLOSED | WDT ITI = vector 214 = IVT offset 0x358 (Sh7055h.pdf table 7.3; ROM slot 0x7ffa8 → trampoline 0x30b8); firmware polls TCSR itself, overflow = OVF flag only |
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E5 | CLOSED | `io_read_overrides` guess (0xffffed18=0x8000) resolved as ICR_W bit15 = NMI pin level, modeled as the SYSC peripheral (`nmi_level`); profiles carry no read overrides |
| E6 | partial (still open) | CAN RX (0x378) autonomous; wake 0x3db0 fires when CMI10B tick delivered; UDS entry 0x680a0 gated by vehicle latch word 0xffff9ec8 bit0; OS tick arming (task[8]→0x7778) circular without first scheduler pass → response TX still via profile `uds` entry points; pending-interrupt delivery on ldc/rte. The deep dive ([os_scheduling_deep_dive_report.md](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)) maps the full scheduler model and reproduces the post→queue→dequeue→handler→taskEnd→dispatch chain in the emulator; the ISR-exit context switch (0x32f4) still does not fire autonomously from idle (preemption needs class > ctrl[0] unsigned, ctrl[0]=0xff at boot) — that is the remaining E6 gap |
| E7 | CLOSED (div1/rotcr) | full Q/M DIV1 (SR bits 8/9) + ROTCR direction, validated vs ROM div routine 0x2158; cycle counts ≠ real time remains (accepted) |
| E8 | open | opdec.OPMNEM keyed on full 16-bit words from the 60E15120 corpus (9,902 entries); family-B ROMs use operand encodings absent from it (e.g. 0xda29 `mov.l @(0x29*4,pc),r10` in 60E0FC00 dispatcher 0x55c14) → UnknownOpcode; family-B profiles boot but diag dispatch is not dynamically executable until the opcode table is widened. See [cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md) |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID — both strings coexist in-ROM: fw id `60E15120` at 0x2000, `N3J1E_1W.Z05` at 0x6c000, `SW-N3ZHEB000.HEX` at 0x6c043/0x6c046, `15120 ` at 0x6c05c; PIDs 0xe611/0xe21b-0xe21e/0xff40-0xff43 return them ([uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)) |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D3 | CLOSED | checksum/CVN routine found: 0x5a3f4 = incremental dual-u16 additive sum over app flash 0x2000-0x7ffff (0x1000 B/call, skips hole 0x7fb00-0x7fb7f), finalize 0x5a714 -> RAM 0xffff9104/0xffff910c, diag-read via 0x55bda -> 0x5a5a6. Not CRC (no CRC table/poly in ROM). See [uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md) §12.1 |
| D4 | CLOSED | seed/key located in both layers: app UDS 0x27 (0x57a64): seed from ATU-II timer 0x55f5e -> 0xffffd1d5-d1d8, key verified by 0x5609e (64-round shift/xor network, fixed key "MazdA" at 0x5f084); flash bootloader (SBL 0x0-0x1fff) 0x27 at 0x1858: seed 55 AA 55, key 4D AC CD literal compare. See uds_mode22_dispatch_report.md §12.2 |
| D5 | CLOSED | g/rev vs VolEf settled: `engine_load_ffffc0b4` = VolEf-like cell units (g/rev × 0.6345 = 1/(1.308 L × 1.205 g/L)); PID 0x43 reports that cell × 1/255, not g/rev. Numeric proof: max-load clamp tbl_0x6b200×tbl_0x6b214×tbl_0x6b1ec = 0.58–1.29 cell units ↔ 0.92–2.03 g/rev, matching load axes in data/maps (tbl_06aa48 axis_y 0.0625–1.25). See [load_fueling_report.md](docs/investigations/60E15120_N3J1E/load_fueling_report.md) |
| D6 | open | unproven `candidate_*` labels |
| D7 | open | 60E1B800 dual N3* strings |
| D8 | CLOSED | local def copies that are git-blob-identical to pinned `submodules/RX8Defs` files are not kept (rule 4b) — the submodule path + commit `1b3aea2…` is the reference. The local and pinned ECUFlash XMLs have identical 1210 tables (raw diff is CRLF/LF only). See [cross_rom_defs_coverage.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_defs_coverage.md) + [data/definitions/README.md](data/definitions/README.md) |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D11 | CLOSED | literal-pool scalar constants are extracted into `data/maps/` by `utilities/scripts/extract_scalars.py`: 14 binary-verified float32 seeds located by exact bit pattern per ROM (`data/maps/<rom-id>/scalars.{json,tsv}` + `cross_rom_scalars.json`), asserting the reference-ROM addresses (base fuel scalar 0.07196 = 0x3d935fc4 @0x78170 -> `fuel_load_scale_ffffbed0`, load cell 0.6345 @0x7a088, ...); cross-ROM: 475.93 cc/min secondary flow absent in 60E0E700_N3YLEE (uses 608.0/626.224 @0x76ccc-0x76cd0). per-ROM RomRaider defs expose stoich_afr 14.7 + fuel_load_scale 0.07196 as editable 1-cell scalar tables (extend_defs_all_roms.py injects per-ROM storageaddress, asserted vs ROM bytes). Tests `tests/test_extract_scalars.py` (6, pass). See [calibration extraction section 6a](docs/investigations/60E15120_N3J1E/calibration_extraction_report.md) + [data/maps README](data/maps/README.md) |
| D10 | open | PID 0x221410 double-claim — in 60E15120_N3J1E, PID 0x1410 handler 0x56f6c (`diag22_pid1410_injector_pulse_time`) reads `injector_pulse_time_ffffbe24` × 8.0 = injector pulse time; throttle pedal position is PID 0x0011/0x093c (`ffffad5c`/`ffffad44`), not 0x1410. Cross-ROM check still open |

The tables above are summaries; the full per-item records (locations, impact,
closure plans) live in this file's git history.
Summary rules: [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md) and `docs/references/`.
Discrepancies are **documented, never silently resolved** — closing one needs new
evidence (ROM bytes, manual table, bench trace, Renesas diff) + a note in the
investigation doc.

---

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per work unit
delivered as a branch + PR against `main` ([`AGENTS.md`](AGENTS.md) §Branch & PR
workflow) with one logical change per commit, `hash_binaries.py --check` after
touching `binaries/`, emulator changes get a Renesas differential run. See
[`AGENTS.md`](AGENTS.md) and [`docs/learnings.md`](docs/learnings.md).
