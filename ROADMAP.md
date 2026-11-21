# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM).

**How to read this file.** §Open work lists what remains, in suggested pickup
order; the discrepancy register at the bottom tracks every known unknown
(E = emulator, D = data/docs) — closing one requires new evidence + a note in
the relevant investigation doc, never a silent resolve. Tags are stable so
cross-references from other docs keep resolving: phases P1–P6, work groups A–F
with item numbers, register IDs (E/D). Closed items and folded duplicates are
**pruned from this file** — their full records (evidence, closure plans, fold
maps) live in this file's git history; an item's number is never reused.
Group ↔ phase map: A = P3 (calibration extraction), B = P1 residual (emulator
fidelity), C = P2 residual (static labeling & gap closure), D = P2/P5
(cross-ROM propagation), E = P4 (reimplementation), F = P6 (toward hardware).

**Status.** Groups A, B and D are complete. Group C is reopened — open items
27, 29–34, 36–37, 39, 42–61, 64, 91, 92 (the former per-subsystem fold-back
items 62–63 and 65–90 were folded into their source items — fold map in this
file's git history). Groups E and F remain open as listed below. Pick up
**C item 27** next.

## Open work — pick up here

Groups are in suggested pickup order; dependencies flow downward: E item 1
grows per subsystem as its C item lands, and F stays gated on bench validation
([`AGENTS.md`](AGENTS.md) rule 10). Each item lists scope, what it unblocks,
and where artifacts live.

### C. Static labeling & gap closure (P2 residual)

Pickup order inside C: **C.1** new subsystem coverage → **C.2** existing
reports (fold back + migrate) → **C.3** cross-cutting audits (they consume the
labels the earlier items produce) → **C.4** docs reorganisation (reorganises
what C.1/C.2 produce).

**Definition of done — applies to every C item, one branch + PR per item.**
(a) The subsystem's report in its final home:
[`docs/subsystem-logic/`](docs/subsystem-logic/README.md) in the human-first
format when the logic is shared across ROM bins (assumed shared until proven
otherwise), `docs/investigations/<rom-id>/` when ROM-specific — one report per
subsystem, however many items it took. (b) One label record for the subsystem
plus canonical TSV / labels-JSON / `symbols.tsv` coverage and a re-filled
`validation.json`, keeping the rule-6 label ladder — binary-level
verification (rule 7) before any label stands. (c) Fold-back: the subsystem's
names carried into the decompiled export via the annotation +
`integrate_reviewed_names.py` + comment-merge passes over
`reverse-engineered/decompiled/60E15120_N3J1E/` (`functions/`,
`firmware_decompiled.c`, `named/firmware_named.c`), and its table labels,
scalars and storage-type corrections applied to the merged def with the
per-ROM defs + `defs_table_labels.json` regenerated via the re-runnable
defs-merge passes (rule 6d: edit the generators, never the generated files).
(d) Pipeline validators (`validate_export.py`, `validate_reports.py`,
`verify_claims.py`, `verify_readability.py`, `verify_math_units.py` from
`utilities/scripts/rx8-pcm-pipeline/`), the link + non-empty-size check over
every touched `.md` under `docs/`, and `python -m pytest tests/` — all green
in the same change.

#### C.1 New subsystem coverage — analyze, report, label

- **C item 27 (open)** — **throttle / DBW.** Pedal PIDs 0x0011/0x093c and the
  DSC torque-request throttle via CAN 0x212 are labeled (see
  [dsc_can_arbitration_report.md](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md)),
  but pedal→throttle-motor control (motor drive, limp/home mode, TP sensor
  plausibility) has no report; also settle the logger PID 0x1410 conflict
  (injector pulse time vs. throttle pedal, noted in design doc §5.8). Label
  record `data/labels/60E15120_N3J1E/throttle_dbw_labels.json` and checks
  `tests/test_throttle_dbw.py` already exist — the report is the missing
  deliverable.
- **C item 29 (open)** — **misfire detection / monitor.**
  `ref_misfireDetectInit_` `0xab8a` is named and the misfire DTCs sit in
  [dtc_control_report.md](docs/investigations/60E15120_N3J1E/dtc_control_report.md),
  but the detection logic (crank-fluctuation path, per-rotor counting, monitor
  enable conditions) is unanalyzed.
- **C item 30 (open)** — **emissions monitors beyond O2.** Catalyst and EVAP
  have no reports (EVAP appears only as `candidate_evap_open_loop_condition`
  `0x22144`); readiness / monitor-completion logic is not covered even for the
  O2 monitor ([o2_sensor_monitor_report.md](docs/investigations/60E15120_N3J1E/o2_sensor_monitor_report.md)).
- **C item 31 (open)** — **starting / cranking.** Only `cranking_pulse_adder`
  `0x30678` inside the fueling chain is known; starter control, crank-signal
  handling and flood-clear are unmapped. Label record
  `data/labels/60E15120_N3J1E/starting_cranking_labels.json` and checks
  `tests/test_starting_cranking.py` already exist — the report is the missing
  deliverable.
- **C item 32 (open)** — **power management / watchdog / main relay.** The PB15
  external-WDT heartbeat (`0x31c` / `0x11cc`, routing unverified per design doc
  §5.6) and the WDT ITI vector `0x7ffa8` are noted, but there is no
  main-relay/power-latch or power-state analysis; ties into the warm/cold reset
  split and key-off state machine already mapped in
  [ignition_power_state_report.md](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md)
  (reset split 0x4e0, magic 0x5aa5a55a @0xffffdffc, key-off state machine
  0x252c2 → halt 0x9ea2).
- **C item 33 (open)** — **sensor acquisition / ADC front-end.**
  `ref_getSensorStuff__` `0x60c8` and `ref_readADCResult` `0x6fb0` are named,
  but per-sensor scaling, fault and rationality handling is not consolidated
  anywhere (MAF scaling is only covered inside
  [load_fueling_report.md](docs/investigations/60E15120_N3J1E/load_fueling_report.md)).
- **C item 34 (open)** — **limiter (rev limit / fuel cut / limp).**
  [reviews/limiter/](docs/investigations/60E15120_N3J1E/reviews/limiter/README.md)
  holds only a README; fuel-cut arbitration `0xedc4` is currently a subsection
  of [fueling_control_report.md](docs/investigations/60E15120_N3J1E/fueling_control_report.md)
  (moves with the merged C items 51+57 report). Deliver a dedicated limiter
  report + labels.
- **C item 91 (open)** — **input expander (SCI0) subsystem report.** The
  external input expander read over SCI0 (`sci0_gpio_expander_read` `0x70ac`,
  channel select on PH13/PH14, results latched to `0xffff9ecc`/`0xffff9ecd`/
  `0xffff9ede` by `0x6744`/`0x6796`) feeds several switch inputs. The
  expander transport itself is already documented in
  [`ignition_power_state_report.md`](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md)
  (§4 misnomer note + memory map). What is **not yet documented anywhere** and
  was removed from the fuel pump report as out of scope: the oil pressure
  switch consumers — light `ref_writeOilPressureLight__` `0x2bafc` reads
  expander ch1 bit 0x80 (`tst 0x80` at `0x2bb12`), debounced over
  `0xffffbc0e`/`0xffffbc10` vs threshold ROM `0x775b8`=0x10 → `0xffffbc0c`;
  gauge `ref_writeOilPressureGauge__` `0x2bb74`/`0x2bb7c` reads ch2 bit 0 →
  `0xffffbc14`, exported to CAN by `ref_setOilPressureGaugeStatus` `0x28c52`
  (status word `0xffffbab0`); harness terminal 2E. Deliver a dedicated
  subsystem report for the expander and its input consumers, with labels
  and a review evidence folder.
- **C item 92 (open)** — **A/C compressor clutch control.** Mapped while
  tracing the fuel pump port banks and split out of
  [`docs/subsystem-logic/fuel_pump_control_report.md`](docs/subsystem-logic/fuel_pump_control_report.md)
  §4.6: PJ7 (PJDR_W `0xfffff76c` bit 0x80, pkg pin 183, harness candidate
  A/C relay 5AA) is driven by `ac_clutch_relay_drive_pj7[_diag]`
  `0x2e800`/`0x2e840` from `ac_clutch_relay_drive` `0xffffbd68`, computed by
  `ref_calculateACClutchOn__` `0x2e89c` from `ac_clutch_on` `0xffffbd69` with
  rpm thresholds 600.0/7800.0 (ROM `0x774c0`/`0x774c4`); the on gate
  `0x2e9a4` and the idle A/C clutch gate `0x165d6` are known. Label record
  `data/labels/60E15120_N3J1E/ac_compressor_clutch_labels.json` and checks
  `tests/test_ac_compressor_clutch.py` already exist — the report is the
  missing deliverable.

#### C.2 Existing reports — fold back + migrate into `docs/subsystem-logic/`

One item per report still at the `docs/investigations/60E15120_N3J1E/` root.
Shared instructions for each: `git mv` the named report, restructure it
human-first (header: applicable-ROMs table listing only investigated ROMs +
ROM SHA-256 + static-analysis disclaimer; §1 plain-language introduction; §2
step-by-step body, starting with a hardware setup diagram when the subsystem
touches hardware; §3 technical pseudocode; §4 proof with the mandatory memory
map, labeling, corrections, files, validation, limits and §4.7 related
reports) per AGENTS.md rule 8 + [`docs/subsystem-logic/TEMPLATE.md`](docs/subsystem-logic/TEMPLATE.md)
— worked example:
[`knock_control_report.md`](docs/subsystem-logic/knock_control_report.md);
keep every address, label and validation claim (rules 5/7), and update all
cross-references in the same change — including generated label artifacts via
their generators (rule 6d), e.g. `build_table_labels.py` source paths — plus
the fold-back per the definition of done above. The three overlapping report
pairs are **single work units** under both IDs: merge each pair into one
canonical report per subsystem (subsystem-logic README rule), folding
duplicated sections and leaving unique evidence in exactly one `reviews/`
folder. If a report's logic turns out ROM-specific rather than shared, leave
it in `docs/investigations/` and close the item with that reason instead of
migrating.

- **C item 42 (open)** — migrate [`can_mailbox_config_report.md`](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md)
- **C item 43 (open)** — migrate [`cooling_fan_control_report.md`](docs/investigations/60E15120_N3J1E/cooling_fan_control_report.md)
- **C item 44 (open)** — migrate [`cruise_control_report.md`](docs/investigations/60E15120_N3J1E/cruise_control_report.md)
- **C item 45 (open)** — migrate [`dsc_can_arbitration_report.md`](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md)
- **C item 46 (open)** — migrate [`dtc_authoring_report.md`](docs/investigations/60E15120_N3J1E/dtc_authoring_report.md)
- **C item 47 (open)** — migrate [`dtc_control_report.md`](docs/investigations/60E15120_N3J1E/dtc_control_report.md)
- **C item 48 (open)** — migrate [`e2ram_device_layer_report.md`](docs/investigations/60E15120_N3J1E/e2ram_device_layer_report.md)
- **C item 49 (open)** — migrate [`e2ram_nv_storage_report.md`](docs/investigations/60E15120_N3J1E/e2ram_nv_storage_report.md)
- **C item 50 (open)** — migrate [`eeprom_content_map_report.md`](docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md)
- **C items 51 + 57 (open, one work unit)** — migrate and **merge**
  [`fueling_control_report.md`](docs/investigations/60E15120_N3J1E/fueling_control_report.md)
  + [`load_fueling_report.md`](docs/investigations/60E15120_N3J1E/load_fueling_report.md)
  into a single load-and-fueling report (the pair re-derives the same content
  today).
- **C items 52 + 53 (open, one work unit)** — migrate and **merge**
  [`idle_control_report.md`](docs/investigations/60E15120_N3J1E/idle_control_report.md)
  + [`idle_target_control_report.md`](docs/investigations/60E15120_N3J1E/idle_target_control_report.md)
  into a single idle-control report.
- **C item 54 (open)** — migrate [`ignition_power_state_report.md`](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md)
- **C item 55 (open)** — migrate [`ignition_timing_report.md`](docs/investigations/60E15120_N3J1E/ignition_timing_report.md)
- **C item 56 (open)** — migrate [`intake_solenoids_report.md`](docs/investigations/60E15120_N3J1E/intake_solenoids_report.md)
- **C item 58 (open)** — migrate [`o2_sensor_monitor_report.md`](docs/investigations/60E15120_N3J1E/o2_sensor_monitor_report.md)
- **C items 59 + 60 (open, one work unit)** — migrate and **merge**
  [`os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md)
  + [`os_scheduling_deep_dive_report.md`](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)
  into a single OS/scheduler report.
- **C item 61 (open)** — migrate [`uds_mode22_dispatch_report.md`](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)
- **C item 64 (open)** — **finish the fuel pump control fold-back.** Item 28
  is closed and its report + label record already live in their final homes
  ([`docs/subsystem-logic/fuel_pump_control_report.md`](docs/subsystem-logic/fuel_pump_control_report.md),
  `data/labels/60E15120_N3J1E/fuel_pump_control_labels.json`,
  `tests/test_fuel_pump_control.py`), but the subsystem's names are not yet in
  the decompiled export or the canonical TSVs — run the annotation +
  `integrate_reviewed_names.py` + comment-merge passes and fold the label
  record into the TSVs / labels JSONs / `symbols.tsv` / `validation.json` per
  the definition of done above.

#### C.3 Cross-cutting audits

- **C item 36 (open)** — **whole-export "is it really code" audit.** The triage
  pass ([decompiler_triage_report.md](docs/investigations/60E15120_N3J1E/labeling/decompiler_triage_report.md))
  classified the 1,759 *non-instruction ranges* outside functions and triaged
  the 154 decompiler warnings, but nothing yet proves that every **function**
  in `function_index.tsv` (3,355 entries) is genuine code rather than a
  decompilation artifact. For each function: re-decode its `body_bytes` from
  the raw ROM with the SH-2E decoder (opdec corpus in
  `utilities/scripts/emu/`, same one `test_decode_corpus.py` uses), assert
  every 16-bit word is a valid instruction (illegal/`0x0000` words only where
  a terminator is expected), that the body does not overlap a range classified
  in
  [non_instruction_ranges_classified.tsv](reverse-engineered/decompiled/60E15120_N3J1E/non_instruction_ranges_classified.tsv),
  that its entry is a real instruction boundary hit by a call/vector/dispatch
  referrer (or deliberately unreferenced, like the proven orphan `0x33b6`),
  and that its direct call targets land on function entries. Reconcile the
  result with `decompiler_issues_triaged.tsv` and extend
  `utilities/scripts/rx8-pcm-pipeline/validate_export.py` so the check is
  re-runnable (ROM hash + instruction bytes + matches, as today). Deliverable:
  an audit report + updated `validation.json`; any function that fails gets
  demoted per rule 6 and the export artifacts fixed in the same pass. Spot-check
  the same audit on 60E0G500_N3ZHEC and one family-B/C ROM (E8 opcode-table gap
  applies — note which opcodes could not be decoded there).
- **C item 37 (open)** — **audit def `type`/`storagetype` fields for more
  editor-compatible forms.** The upstream DTC switch rework (spliced into our
  defs by `utilities/scripts/defs-merge/splice_upstream_dtc_immo.py`; record:
  [upstream-sync-validation.md](docs/investigations/60E15120_N3J1E/labeling/rx8defs-analysis/upstream-sync-validation.md))
  showed the pattern: a byte the firmware treats as on/off is better exposed as
  RomRaider `type="Switch"` (Enabled/Disabled states) than as a raw `1D`. In the
  merged def's RX8Base, 248 tables are already `Switch` but 127 remain `1D uint8` —
  and all 123 "Enable/Disable"-named ones among them are the DTC #3 bank `0x7e790`,
  which is deliberately 1D (feature bitmask, not on/off —
  [dtc_control_report.md](docs/investigations/60E15120_N3J1E/dtc_control_report.md)),
  so the remaining candidates must be found semantically, not by name. Upstream
  `39d98a0` has no further type changes to ingest (only the DTC tables differ in
  type vs ours). Scope, per table in the merged def's RX8Base + 60E15120 block,
  then propagated to all per-ROM defs: (a) 1D uint8/uint16 bytes the firmware
  reads as a boolean gate (tested ==0/!=0, no arithmetic — the read site in the
  disassembly is the rule-7 evidence) → candidate `Switch` with states; bitmask
  bytes stay 1D; (b) `storagetype` vs the ROM lookup-descriptor `type_code`
  mismatches (`relabel.STORAGETYPE` map; precedent: the 62 storage-type
  corrections in
  [defs-merge/README.md](docs/investigations/60E15120_N3J1E/labeling/defs-merge/README.md));
  (c) `type`/sizex/sizey fields that disagree with the descriptor geometry.
  Deliverables: a re-runnable pass under `utilities/scripts/defs-merge/`, updated
  merged + per-ROM defs + label-map evidence, tests.

#### C.4 Docs reorganisation

- **C item 39 (open)** — **reader-focused reorganisation of the investigation
  docs (indexes + maintainability).** The per-subsystem report migration and
  the dedup of the three overlapping report pairs are handled by the C.2 items
  (51+57, 52+53, 59+60). Remaining scope here: (a) one reading order — a
  single entry-point index per ROM folder (what to read first, in what
  sequence) merged with the top-level
  [`docs/investigations/README.md`](docs/investigations/README.md) so there is
  one source of truth, replacing the per-ROM `README.md` indexes that duplicate
  it; (b) uniform shape — spot-audit the root reports still in the old
  10-section layout against
  [`docs/investigations/TEMPLATE.md`](docs/investigations/TEMPLATE.md) / rule 8
  until each is migrated by its C.2 item; (c) maintainability — extend the
  link + non-empty-size check to every `.md` under `docs/` (the pipeline
  validators only scan `*_report.md`, so a truncated review note is not
  caught) and add a short "how to add a report" section to
  [`docs/investigations/README.md`](docs/investigations/README.md).
  Constraints: no evidence loss — every address, label and validation claim
  survives any move (rules 5/7).

### E. Reimplementation coverage (P4)

- **E item 1 (open)** — grow `reverse-engineered/reimplementation/` per labeled
  subsystem with host tests **and** emulator cross-checks (`harness.py` +
  `tests/test_phase1_dynamic.py` pattern); pick up each subsystem as its C item
  above lands. Implemented so far: `rx8_math`, `rx8_apv`,
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
- **F item 3 (study done, implementation open)** — live-tuning feasibility:
  stock ROM already supports live logging (Mode 22 PIDs + UDS 0x23 after 0x27
  unlock); live *writes* need a patch (no 0x2E; app 0x34/0x36/0x37 are stubs) —
  RAM-shadow of hot cal tables (idle-free window 0xffff8000–0xffff92ff 4,864 B on
  all 11 ROMs; 3,852 B static-free after removing code-referenced cells, largest
  contiguous 1,087 B at 0xffff8109–0xffff8547) + write service in a code cave
  (per-ROM app free flash 899 B–21,956 B; 196 B cave 0x7fb8c–0x7fc4f on all ROMs)
  + PC tool over CAN/ISO-TP (J2534 on car, emulator TCP port in dev).
  See [live_tuning_feasibility_report.md](docs/investigations/60E15120_N3J1E/labeling/live_tuning_feasibility_report.md)
  + [free_resources_report.md](docs/investigations/60E15120_N3J1E/labeling/free_resources_report.md).
- **F item 4 (answered statically + emulator; handshake sequence confirmed on a
  real PCM 2026-11-18; the write path itself still open)** — the OBD upload path
  is the app's **0xB1 00B2**, not the app 0x34/0x36/0x37 stubs
  (0x5d7bc/0x5d834/0x5d874 on 60E15120_N3J1E): app service 0xB1 = 0x565e8 ->
  sub-record 0x5f0f4 -> handler 0x56350 (needs session 0x85 via 0xffffd1cf,
  unlock level 1 via 0xffffd1d0, conditions 0x56428 = battery 8.0-16.5 V +
  0x1008() < 100, data byte 0) queues F1 00 B2 (0x564ac) and sets boot-request
  0xffffd1dc = 3 (0x563de(3)); after the response, 0x680de -> 0x6892a ->
  0x54a36(0xb1) -> 0x563de(1) -> 0x564d4 -> 0x1038(1) enters the SBL loop 0x1378,
  where 0x34/0x36/0x37 stage and jump to the flash kernel and 0xb1 (0x1d78) only
  arms one download (0xffffdfb3) — the SBL has no flash-write path. The SBL
  loop relocks on inactivity: u16@0xffffdfa0 counts passes (0x11cc), is reset
  by every processed frame (0x11c4 at 0x13c8/0x13e4/0x140a/0x1544), and at
  >= 0x5f6 while idle (0x1428) 0x16dc(0) clears all latches; mid-multi-frame,
  >= 0x2e (0x1448) aborts only the transfer. Emulator: ~256 cycles/pass, relock
  ~390k cycles, inter-frame abort ~12k cycles (at 40 MHz ≈ 9.8 ms / 0.29 ms; PCM
  clock not pinned in-repo). So an upload only needs frames within the
  inter-frame window; a mid-upload relock is recoverable (10 85 + fixed
  27 01/02 + B1 00 B2 00, restart 34/36). So over OBD:
  10 85, 27 01/02 (app key algorithm 0x5609e), B1 00 B2 00 -> F1 00 B2, then
  34/36/37 in the SBL. The handover enters the SBL with its latches already set:
  0x1038(1) calls 0x16dc(1), which clears 0xffffdfb0-b5 then sets session
  0xffffdfb0=1, unlock 0xffffdfb1=1, download-armed 0xffffdfb3=1 — so right
  after F1 00 B2 the SBL answers 22 D1 00 with 85 and 27 01 with a zero seed;
  the fixed seed 55 AA 55 / key 4D AC CD is only offered on non-handover entries
  (warm boot / erased-flash fallback, after 10 81, after the loop relock at
  0x1428). On-car 2026-11-18 (guarded read-only session, calibration
  N3YLEE00013SN0A0): the app-side sequence above confirmed (7F B1 22 / 7F B1 33 /
  F1 00 B2), the post-handover 62 D1 00 85 / 67 01 00 00 00 / 7F 27 22 confirmed,
  and SBL 11 01 -> 51 with the app back ~1.05 s later confirmed. Details +
  emulator validation (tests/test_sbl_bootloader.py, 9 tests, on-car trace
  reproduced frame-for-frame):
  [sbl_bootloader_report.md](docs/subsystem-logic/sbl_bootloader_report.md)
  §2.2–2.3. Remaining: an actual upload still needs the RAM flash kernel (no
  kernel image in the corpus — the SBL stages it via 0x34/0x36 and jumps to it)
  plus F item 1/2 bench validation; the emulator can only drive the app side at
  handler level because the OS tick never fires (E6).

---

## Discrepancy register

### Emulator fidelity (E-items)

| ID | Status | What |
|----|--------|------|
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E6 | partial (still open) | CAN RX (0x378) autonomous; wake 0x3db0 fires when CMI10B tick delivered; UDS entry 0x680a0 gated by vehicle latch word 0xffff9ec8 bit0; OS tick arming (task[8]→0x7778) circular without first scheduler pass → response TX still via profile `uds` entry points; pending-interrupt delivery on ldc/rte. The deep dive ([os_scheduling_deep_dive_report.md](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)) maps the full scheduler model and reproduces the post→queue→dequeue→handler→taskEnd→dispatch chain in the emulator; the ISR-exit context switch (0x32f4) still does not fire autonomously from idle (preemption needs class > ctrl[0] unsigned, ctrl[0]=0xff at boot) — that is the remaining E6 gap |
| E8 | open | opdec.OPMNEM keyed on full 16-bit words from the 60E15120 corpus (9,902 entries); family-B ROMs use operand encodings absent from it (e.g. 0xda29 `mov.l @(0x29*4,pc),r10` in 60E0FC00 dispatcher 0x55c14) → UnknownOpcode; family-B profiles boot but diag dispatch is not dynamically executable until the opcode table is widened. See [cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/labeling/cross_ecu/cross_rom_mode22_pid_handlers.md) |
| E9 | open | emulator `sh2e.py` `_op_mull`/`_op_mulsw`/`_op_muluw` write the product to the operand register `r[t[1]]` instead of MACL (Sh7055h.pdf: MULU.W Rm,Rn → MACL, registers unchanged). Consequence: firmware RMW idioms `mulu.w` + `sts macl` (e.g. HCAN MBCR/MBIMR setup at 0x9d58-0x9d82 and compare at 0x2a596/0x2a5a2) compute 0 in-emulator, so HCAN mailbox direction/interrupt-mask registers cannot be dynamically validated until fixed. Evidence + workaround run in [can_mailbox_config_report.md](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md) §7/§9 |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID — both strings coexist in-ROM: fw id `60E15120` at 0x2000, `N3J1E_1W.Z05` at 0x6c000, `SW-N3ZHEB000.HEX` at 0x6c043/0x6c046, `15120 ` at 0x6c05c; PIDs 0xe611/0xe21b-0xe21e/0xff40-0xff43 return them ([uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)) |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D7 | open | 60E1B800 dual N3* strings |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D13 | open | upstream RX8Defs `39d98a0` set the shared 60E32000 block's immobilizer addresses to `0x37278`/`0x376c4`, which match only the N3M5E variant — the N3N5EB ROM's immo start pattern sits at `0x371d8` (`0x37624` with RKE), so `per-rom/60E32000_N3N5EB.xml` inherits an address wrong for that ROM (ROM-verified; see [upstream-sync-validation.md](docs/investigations/60E15120_N3J1E/labeling/rx8defs-analysis/upstream-sync-validation.md) §3). Closure plan: per-ROM immo-address repair derived from the ROM pattern in `extend_defs_all_roms.py` (same approach as `repair_dtc_tables`), or an explicit N3N5EB override |
| D14 | open | `0xffffdfa0` is dual-labeled: `immo_diag_bit` in `accepted_ram_aliases.tsv` / the immobilizer report (cleared by `0x11c4`, tested by `ref_readImmoBit` `0x16b20`) vs `sbl_inactivity_counter` (u16) in [`docs/subsystem-logic/sbl_bootloader_report.md`](docs/subsystem-logic/sbl_bootloader_report.md), where `0x11c4` zeroing it is dynamically proven in the emulator relock tests. `0x11c4` sits inside the SBL block (`0x1000–0x1fff`). Reconcile the alias (and the `0x11c4`/`0x16b20` rows) in one direction — likely SBL-side — and fold back into both reports |
| D15 | documented | upstream RX8Defs `d4140dc` delta absorbed: 118 renames + 16 category moves + 10 duplicate removals on `RomRaider/rx8_defs.xml`, no `storageaddress` changed; per-ROM defs + `coverage.json` regenerated at the pin, upstream snapshot re-pinned (`repin_upstream_snapshot.py`), splice pass normalization-only (`upstream_splice_d4140dc.json`), collision/alias findings logged pin-tagged in `defs-merge/axis_conflicts.json` + `inheritance_issues.json`; label map needed no changes; record [upstream-sync-d4140dc.md](docs/investigations/60E15120_N3J1E/labeling/rx8defs-analysis/upstream-sync-d4140dc.md), machine record `defs-merge/upstream_pin_audit_d4140dc.json`; open follow-up: 26 `Table 3D - 2 `/`3D - 3 ` block overrides lost their RX8Base template upstream (`base_template_removed_at_pin`) |

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
