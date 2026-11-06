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
**reopened**: open items 9–11 — pick up 9–10 first; C item 10 pairs naturally
with **E item 1** (reimplementation coverage), then F (gated). The audit
snapshot: 3,355 functions in the 60E15120_N3J1E export, 833 named + 2,522
`FUN_` (function_index.tsv figures of 2026-11-04,
`reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv`).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live.

### C. Static labeling & gap closure (P2 residual) — REOPENED (items 9–11)

- **C item 9 (open)** — subsystem reports for areas with only inherited
  `ref_` seed labels and no report: idle speed control
  (`ref_updateIdleControl__` 0x167c0), alternator/charging
  (`ref_alternatorControlMain` 0x267c6 / `ref_alternatorControl` 0x2680e
  chain), cooling fan (`ref_initFanControl` 0x2f188 / `ref_setFanOutputGPIO`
  0x2f1dc), E2RAM read/write layer (`ref_getDataFromE2RAM` 0x3599c /
  `ref_writeToE2RAMArea_INDEX_ADDR_LEN` 0x37ea4; serves knock-learn storage,
  [knock report](docs/investigations/60E15120_N3J1E/knock_control_report.md) 0x139c4),
  DSC-related CAN arbitration (`ref_updateDSCRelatedCANStuff__` 0x2a2ae).
  `ref_` names are upstream-inherited hypotheses — binary-verify before
  upgrading any label (rule 6).
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
    stays with C item 9: 0x3599c/0x37ea4.)
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
