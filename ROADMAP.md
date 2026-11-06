# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM).

**How to read this file.** §Open work
lists what remains, in suggested pickup order; the discrepancy register at the
bottom tracks every known unknown (E = emulator, D = data/docs) — closing one
requires new evidence + a note in the relevant investigation doc, never a silent
resolve. Tags are stable so cross-references from other docs keep resolving: phases
P1–P6, work groups A–F with item numbers, register IDs (E/D). Closed items are
**pruned from this file** — their full records (evidence, closure plans) live in
this file's git history; an item's number is never reused. Group ↔ phase
map: A = P3 (calibration extraction), B = P1 residual (emulator fidelity), C = P2
residual (static labeling & gap closure), D = P2/P5 (cross-ROM propagation), E = P4
(reimplementation), F = P6 (toward hardware).

Groups A, B and D are complete. Group C (static labeling & gap closure) is
**reopened**: open items 10–15 — pick up 10 first; C item 10 pairs naturally
with **E item 1** (reimplementation coverage), then F (gated). The audit
snapshot: 3,355 functions in the 60E15120_N3J1E export, 833 named + 2,522
`FUN_` (function_index.tsv figures of 2026-11-04,
`reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv`).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live.

### C. Static labeling & gap closure (P2 residual) — REOPENED (items 10–15)

- **C item 10 (open)** — prove or demote the 122 unverified `candidate_*`
  labels (**D6**): 58 diag22 PID/RAM-meaning labels plus control-path
  candidates (`candidate_rev_limit_conditionals` 0xee82,
  `candidate_o2_monitor_integrator` 0x3d010,
  `candidate_evap_open_loop_condition` 0x22144,
  `candidate_knock_sensor_fault_task` 0x64ba). Dynamic validation
  (`harness.call()` + datalog replay) pairs naturally with E item 1.
- **C item 11 (open)** — follow-ups from the large-control-bodies labeling pass
  (PR #33, closed — record in git history). The
  dynamic/emulator validation of the seven newly labeled bodies is **done**
  (per-subsystem dynamic tests `tests/test_*_dynamic.py`, 11 passed; pairs with C item 10 / E item 1 —
  see [reviews/large_control_bodies_review.md](docs/investigations/60E15120_N3J1E/reviews/large_control_bodies_review.md);
  it also fixed the CAN report's BCR expect 0x83e → 0x803e and closed two
  emulator decode gaps). Still open, per subsystem (report §9 Limits):
  - cruise ([cruise_control_report.md](docs/investigations/60E15120_N3J1E/cruise_control_report.md)):
    units of `cruise_set_speed` 0xffffbcf8 (km/h vs % — inferred from the
    [0,100] clamp + 20–200 km/h axes, not proven against a scanner PID); the
    control law consuming 0xffffcf51–0xffffcf5b downstream of 0x4ca7e/0x4d4a6/
    0x4d700; producer of the band selector 0xffffcf1c.
  - E2RAM ([e2ram_nv_storage_report.md](docs/investigations/60E15120_N3J1E/e2ram_nv_storage_report.md)):
    attribute the remaining payload u16s of the 28-u16 block (only rpm
    0xffffb548, pedal volts 0xffffa9c4, two readValue floats and the DTC flag
    bytes are attributed); save cadence/trigger — the caller of 0x1150e was
    not traced beyond the callgraph. (The deeper E2RAM device protocol layer
    now covered by [e2ram_device_layer_report.md](docs/investigations/60E15120_N3J1E/e2ram_device_layer_report.md): 0x3599c/0x37ea4.)
  - CAN mailbox ([can_mailbox_config_report.md](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md)):
    attribute record bytes +12..+15 of the 16-byte mailbox descriptors; whether
    `ref_canSetup` 0xd9f4 runs once at boot or also on CAN error recovery.
  - idle ([idle_target_control_report.md](docs/investigations/60E15120_N3J1E/idle_target_control_report.md)):
    meaning of the select flags 0xffffb534/b53c/b5b3/bd69/bdb8 (inferred, not
    proven from producers); output path of 0x5ca94 (which actuator register it
    drives).
  - O2 monitor ([o2_sensor_monitor_report.md](docs/investigations/60E15120_N3J1E/o2_sensor_monitor_report.md)):
    physical meaning of the four filtered channels 0xffffc708–0x14; gating
    conditions of 0xffffc704 / 0xffffae21 on the threshold averages
    0x6b680–0x6b6d4.
- **C item 12 (open)** — fold the leading/trailing timing-correction findings
  that landed with the DSC CAN report (PR #55, branch
  `research/c9-dsc-can-report`) into the label records and the ignition timing
  report. That pass added `[ADDITIONAL SOURCE REVIEW]` RAM aliases on the
  leading/trailing timing chain — but only as decompiled header comments, not
  yet in `source_review/accepted_ram_aliases.tsv` or the labels JSON:
  0x11f00/0x1206c coolant terms (`leading_coolant_scaled_advance_term`
  0xffffa5f0, `trailing_...` 0xffffa5f4), 0x123da/0x124d6 cranking blends
  (`leading_base_timing_final` 0xffffa5e8, `trailing_base_timing_final`
  0xffffa5ec, `cranking_timing_multiplier_leading` 0xffffa644 /
  `_trailing` 0xffffa654), 0x12630/0x12754 min-advance clamps
  (`leading_min_advance_clamp` 0xffffa64c, `trailing_min_advance_clamp`
  0xffffa65c), 0x121fc/0x12300 max-advance + pre-clamp cells
  (`leading_max_advance` 0xffffa660, `trailing_max_advance` 0xffffa664,
  `leading_timing_with_corrections` 0xffffa634,
  `trailing_timing_with_corrections` 0xffffa63c), idle error corrections
  0x135b4/0x136e4 (`idle_leading_timing_error_correction` 0xffffa718,
  `idle_trailing_timing_error_correction` 0xffffa71c), IAT compensation
  0x14090 (`iat_timing_compensation_leading` 0xffffa778 /
  `_trailing` 0xffffa77c), idle base select 0x14100
  (`idle_base_timing_leading` 0xffffa780 / `_trailing` 0xffffa784).
  Investigate: re-verify each cell against the raw ROM/disassembly (AGENTS.md
  rule 7), promote into
  [data/labels/60E15120_N3J1E/](data/labels/60E15120_N3J1E/) +
  `source_review/accepted_ram_aliases.tsv`, and update
  [ignition_timing_report.md](docs/investigations/60E15120_N3J1E/ignition_timing_report.md)
  — its §4/§8 memory map still uses raw `a5e8`-style cell names. Pairs with
  E item 1 (ignition timing is a remaining reimplementation subsystem).
- **C item 13 (open)** — sweep and apply the `[ADDITIONAL SOURCE REVIEW]`
  comments that landed with the DSC CAN report (PR #55, branch
  `research/c9-dsc-can-report`): 311 decompiled function files under
  `reverse-engineered/decompiled/60E15120_N3J1E/functions/` carry new review
  headers with 268 function-level alias descriptions and 164
  `RAM <addr> <alias>` lines. Today they exist only as header comments — not
  yet in `source_review/accepted_function_aliases.tsv` /
  `accepted_ram_aliases.tsv`, not in the per-subsystem labels JSON under
  [data/labels/60E15120_N3J1E/](data/labels/60E15120_N3J1E/), and not reflected
  in the subsystem reports. For each: evaluate (keep the label ladder —
  `candidate_` stays until proven), re-verify against the raw ROM/disassembly
  (AGENTS.md rule 7), then apply — promote into the TSVs + the matching
  per-subsystem labels JSON, and update the relevant
  [investigation reports](docs/investigations/60E15120_N3J1E/) where the new
  names change the memory maps. C item 12 is the ignition-timing subset of
  this sweep; do that one first, then batch the rest per subsystem (one work
  unit per subsystem, per AGENTS.md rule 11). Run the pipeline validators +
  `python -m pytest tests/` after each batch.
- **C item 14 (open)** — sweep all decompiled function definitions and their
  header comments for merge/reduce/apply opportunities. Every file under
  `reverse-engineered/decompiled/60E15120_N3J1E/functions/` now stacks several
  comment blocks (`[ADDITIONAL SOURCE REVIEW]`, `[CROSS-ECU / RX8DEFS REVIEW]`,
  `[READABILITY RECONSTRUCTION]`, `[ROM address: ...]`), and the same bodies
  appear in the monolithic
  [`firmware_decompiled.c`](reverse-engineered/decompiled/60E15120_N3J1E/firmware_decompiled.c)
  and [`named/firmware_named.c`](reverse-engineered/decompiled/60E15120_N3J1E/named/firmware_named.c)
  — with C item 13 landing more review comments, some statements are now
  duplicated across blocks. Go through all of them: merge or drop redundant
  comment lines, apply the ones that belong in the canonical export (via the
  re-runnable pipeline passes, not hand edits), and keep the per-function files
  and the two monoliths in sync. Any rename/relabel still needs rule-7
  binary-level verification; run the pipeline validators + `python -m pytest
  tests/` after the pass.
- **C item 15 (open)** — verify all claims in the reports added today:
  [dsc_can_arbitration_report.md](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md)
  (+ `reviews/dsc_can_arbitration/`, merged today) and
  [idle_control_report.md](docs/investigations/60E15120_N3J1E/idle_control_report.md)
  (+ `reviews/idle_control/`, open PR branch). For each: re-check every
  machine-checkable claim with `verify_claims.py` / `validate_reports.py`,
  plus the rule-7 binary-level pass over prose claims (ROM bytes, literal
  pools, mailbox/descriptor bytes, call counts vs the disassembly), and record
  the outcome in the report's `reviews/<subsystem>/validation.json`. Fix any
  factual error in *all* artifacts (report + label JSON/TSV evidence), per
  AGENTS.md rule 11.

### E. Reimplementation coverage (P4)

- **E item 1 (open)** — grow `reverse-engineered/reimplementation/` per labeled
  subsystem with host tests **and** emulator cross-checks (`harness.py` +
  `tests/test_phase1_dynamic.py` pattern). Implemented so far: `rx8_math`, `rx8_apv`,
  `rx8_knock` — knock-retard state machine 0x13a60/0x13b40 +
  `rx8_add_u8_saturate` 0x2478, host tests plus
  `tests/test_knock_retard_dynamic.py` emulator cross-checks.
  Remaining subsystems: fueling chain, load model, ignition timing, intake
  solenoids, limiter.

### F. Toward hardware (P6) — GATED

No vehicle flashing without bench validation (AGENTS.md rule 10). Preferred bench
path: upload the patched blob to a **bench ECU over the OBD port** via UDS 0x34
RequestDownload / 0x36 TransferData / 0x37 RequestTransferExit (ISO-TP on CAN
0x7E0/0x7E8, after 0x10 session + 0x27 security unlock) — the same route
Rx8Man-class tools use on a car. CN400 **BOOT mode is recovery-only** (it erases
flash before any read), not the test path.

- **F item 1 (open)** — pre-validate patchers (`utilities/scripts/patchers/`) in
  the emulator first — including the "fast RAM logging" patch via the virtual
  OBD port — then bench-ECU OBD upload.
- **F item 2 (open)** — recovery only: BOOT-mode via CN400 needs ~150 Hz square
  wave on pin 3 (thread §8; verify **D9** pinout conflict against `Sh7055h.pdf`
  first).
- **F item 4 (open)** — reconcile the OBD upload path with our static finding that
  the app's 0x34/0x36/0x37 handlers (0x5d7bc/0x5d834/0x5d874 on 60E15120_N3J1E) are
  NRC stubs and real flashing code lives in the SBL BOOT (0x1ad6/0x1c04/0x1d30/
  0x1d78): check session/security gating of the app handlers and whether an
  unlocked app 0x34 hands off to the SBL over OBD. Bench-ECU OBD upload is the
  accepted working path; the ROM-side mechanism is still open.
- **F item 3 (study done, implementation open)** — live-tuning feasibility:
  stock ROM already supports live logging (Mode 22 PIDs + UDS 0x23 after 0x27
  unlock); live *writes* need a patch (no 0x2E; app 0x34/0x36/0x37 are stubs) —
  RAM-shadow of hot cal tables (idle-free window 0xffff8000–0xffff92ff 4,864 B on
  all 11 ROMs; 3,852 B static-free after removing code-referenced cells, largest
  contiguous 1,087 B at 0xffff8109–0xffff8547) + write service in a code cave
  (per-ROM app free flash 899 B–21,956 B; 196 B cave 0x7fb8c–0x7fc4f on all ROMs)
  + PC tool over CAN/ISO-TP (J2534 on car, emulator TCP port in dev).
  See [live_tuning_feasibility_report.md](docs/investigations/60E15120_N3J1E/live_tuning_feasibility_report.md)
  + [free_resources_report.md](docs/investigations/60E15120_N3J1E/free_resources_report.md).

---

## Discrepancy register

### Emulator fidelity (E-items)

| ID | Status | What |
|----|--------|------|
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E6 | partial (still open) | CAN RX (0x378) autonomous; wake 0x3db0 fires when CMI10B tick delivered; UDS entry 0x680a0 gated by vehicle latch word 0xffff9ec8 bit0; OS tick arming (task[8]→0x7778) circular without first scheduler pass → response TX still via profile `uds` entry points; pending-interrupt delivery on ldc/rte. The deep dive ([os_scheduling_deep_dive_report.md](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)) maps the full scheduler model and reproduces the post→queue→dequeue→handler→taskEnd→dispatch chain in the emulator; the ISR-exit context switch (0x32f4) still does not fire autonomously from idle (preemption needs class > ctrl[0] unsigned, ctrl[0]=0xff at boot) — that is the remaining E6 gap |
| E8 | open | opdec.OPMNEM keyed on full 16-bit words from the 60E15120 corpus (9,902 entries); family-B ROMs use operand encodings absent from it (e.g. 0xda29 `mov.l @(0x29*4,pc),r10` in 60E0FC00 dispatcher 0x55c14) → UnknownOpcode; family-B profiles boot but diag dispatch is not dynamically executable until the opcode table is widened. See [cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md) |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID — both strings coexist in-ROM: fw id `60E15120` at 0x2000, `N3J1E_1W.Z05` at 0x6c000, `SW-N3ZHEB000.HEX` at 0x6c043/0x6c046, `15120 ` at 0x6c05c; PIDs 0xe611/0xe21b-0xe21e/0xff40-0xff43 return them ([uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)) |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D6 | open (proof pass 2026-11-05 done, renames pending) | 122 `candidate_*` names in the 60E15120_N3J1E export ([function_index.tsv](reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv)); the 2026-11-05 low-confidence proof pass dynamically proved the underlying functions behind many of them (incl. 0xee82, 0x3d010, 0x22144, 0x64ba evidence notes) — see [reviews/low_confidence_proof_pass_2026-11-05.md](docs/investigations/60E15120_N3J1E/reviews/low_confidence_proof_pass_2026-11-05.md); dropping the `candidate_` prefix in the export remains pickup = C item 10 |
| D7 | open | 60E1B800 dual N3* strings |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D12 | open | `annotate_source_review.py` fails on clean main too: 38 pre-existing 4-field rows in `docs/investigations/60E15120_N3J1E/source_review/accepted_ram_aliases.tsv` (row count verified on main and on the PR #33 head). Noted in PR #33 and deliberately left as-is there (no drive-by fix, AGENTS.md rule 9); fixing the parser/rows is its own work unit |

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
