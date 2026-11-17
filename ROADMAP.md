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
**reopened**: open items 26–34, 36–37, 39, 42–90 — pick up 26 next (items 24–25 closed
2026-11-16: SBL block `0x0–0x1fff` statically labeled + cross-ROM SBL diff, and the
SBL→app handover incl. the `0x61a8` entry mechanism mapped — report
[`sbl_bootloader_report.md`](docs/subsystem-logic/sbl_bootloader_report.md), record
`data/labels/60E15120_N3J1E/sbl_bootloader_labels.json` (incl. handover records),
cross-ROM `data/labels/cross_rom/sbl_first_8k.json`;
item 38 closed
2026-11-15: ignition key-state logic (key-off/ON/crank) labeled and
reported — key-on input PFDR bit0 → latch 0xffff9ec8 → 0xffffaa68 gating
UDS/CAN, warm/cold reset split 0x4e0 (magic 0x5aa5a55a @0xffffdffc), key-off
state machine 0x252c2 → halt 0x9ea2, PD11 relay hold 0x251d0; report
[ignition_power_state_report.md](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md),
record
`data/labels/60E15120_N3J1E/ignition_power_state_labels.json`, per-ROM
`data/labels/cross_rom/ignition_power_state_addresses.json`, checks
`tests/test_ignition_power_state.py`; item 23 closed
2026-11-13: the upstream-sync findings (RX8Defs `39d98a0` / MRP `b243b35`,
record
[upstream-sync-validation.md](docs/investigations/60E15120_N3J1E/labeling/rx8defs-analysis/upstream-sync-validation.md)
§7) are folded into our docs and label artifacts — per-ROM immobilizer
start-pattern offsets re-verified against all 11 raw ROMs →
`data/labels/cross_rom/immobilizer_start_patterns.json` +
`data/labels/60E15120_N3J1E/immobilizer_labels.json` +
`data/labels/60E0G500_N3ZHEC/immobilizer_labels.json`; upstream DTC categories
cross-linked from [dtc_control_report.md](docs/investigations/60E15120_N3J1E/dtc_control_report.md)
§5c (0x7e678/0x7e704/0x7e790 ↔ "DTC - MIL Illuminate" / "OBD Report" / "Unknown");
`N3ZGEC` as 60E0G500's second cal ID noted in
[flash-memory-layout.md](docs/architecture/flash-memory-layout.md) §4.2 and
the 60E0G500 defs-merge record; the `Table 3D - UNKNOWN_CL` → `Closed Loop
Fueling Base` rename cross-referenced in
[fueling_control_report.md](docs/investigations/60E15120_N3J1E/fueling_control_report.md)
§10.7; the `Fuel Target (Closed Loop)` → `Fuel Injection - Closed Loop`
category rename folded into `defs_table_labels.json` (9 entries), all local
def files (splice item 3) and the regenerated per-ROM defs, rename alias
dropped from `tests/test_defs_relabel.py`; pipeline validators + full pytest
green; item 35 closed
2026-11-13: the full 256 B of the 93C56 (IC420) are mapped in
[eeprom_content_map_report.md](docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md)
against the upstream dumps — immo key 0x02–0x09, immo code 0x16–0x19, param
block 0x00–0x1f, learned table 0x20–0x63, ECU ID 0x64–0x6d, VIN 0x80–0x90,
tire marker/revs 0x95/0x9a–0x9b, config bit 0x9f — plus the RAM side (shadow
0xffffc28e, param block 0xffffc268, E2 window 0xffff8000–0xffff80ff);
`flash-memory-layout.md` §2/§5 updated; record
`data/labels/60E15120_N3J1E/eeprom_content_labels.json`; checks
`tests/test_eeprom_content_map.py`; item 22 closed 2026-11-13:
spliced the upstream RX8Defs `d95b0be` DTC switch rework + `39d98a0` 60E15120
immobilizer patch addresses (ROM-verified 0x34b10/0x34f5c) into the reviewed
merged 60E15120 def and therefore per-rom/60E15120_N3J1E.xml via the re-runnable
`utilities/scripts/defs-merge/splice_upstream_dtc_immo.py` (splice, not rebase —
local P-code names kept); `repair_dtc_tables` in `extend_defs_all_roms.py` now
emits the Switch form for every per-ROM def; `tests/test_defs_upstream_sync.py`
added; relabel passes normalization-only, pipeline validators + full pytest
green; item 21 closed
2026-11-13: label-artifact consistency audit — 22 RAM + 26 lookup TSV rows got
ROM-anchored evidence, 342 evidence-less labels-JSON entries filled from the
canonical TSVs, 7 stale duplicate alias rows removed, symbols.tsv coverage
restored, durable `tests/test_label_artifact_consistency.py` added; items 13–14 closed
2026-11-11: item 13 applied the `[ADDITIONAL SOURCE REVIEW]` comment sweep to
the accepted TSVs, the per-subsystem labels JSONs and the subsystem report
memory maps; item 14 applied, merged and reduced the stacked review comment
blocks in the export via the re-runnable pipeline passes; item 16 closed
2026-11-12: the annotation + `integrate_reviewed_names.py` passes were re-run so
every file under `reverse-engineered/decompiled/60E15120_N3J1E/functions/`,
`firmware_decompiled.c` and `named/firmware_named.c` carries the accepted
function/RAM aliases and review comments; item 17 closed 2026-11-12: the docs
sweep added the DSC↔idle↔ignition cross-links (0xffffbbb8 `vehicle_not_moving`
→ idle A/C clutch gate 0x165d6, 0xffffbbd8 `engine_max_torque_allowed` → DSC
timing derate 0x1815c) to the report Related-reports lines, §9/§10 sections and
the investigations README index, noted the re-runnable comment-merge pass in
`docs/learnings.md`, and fixed the 9 broken `.md` links a repo-wide scan found;
item 18 closed 2026-11-12: the ECU defs were updated from the subsystem
investigations — 47 new curated table labels (idle target/air, alternator,
CAN 0x212-derived DSC Mode C throttle) applied to the merged 60E15120 block and
all per-ROM defs via the re-runnable defs passes, and the 12 remaining verified
literal-pool scalars exposed as editable `Scalar - …` entries (14 total) —
full records in this file's git history). The
audit snapshot: 3,355 functions in the 60E15120_N3J1E export, 939 named +
2,416 `FUN_` (function_index.tsv figures of 2026-11-12,
`reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv`).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live.

### C. Static labeling & gap closure (P2 residual) — REOPENED (items 26–34, 36–37, 39, 42–90)

- **C item 26 (open)** — **immobilizer subsystem analysis.** Today only the
  start-pattern addresses are known (`0x34b10` / with-RKE `0x34f5c` on
  60E15120_N3J1E; per-ROM table in
  [upstream-sync-validation.md §3](docs/investigations/60E15120_N3J1E/labeling/rx8defs-analysis/upstream-sync-validation.md),
  D13 open for N3N5EB), plus the `ref_afterImmo_1..6` UDS handlers and the immo
  counter in the slow task `0x11534`. Label the immo challenge/response and
  keyless-module CAN dialogue; deliver `immobilizer_report.md` +
  `data/labels/60E15120_N3J1E/immobilizer_labels.json` + per-ROM equivalents
  (the per-ROM start-pattern addresses are already folded into those records —
  don't duplicate them, extend with the challenge/response analysis).
- **C item 27 (open)** — **throttle / DBW.** Pedal PIDs 0x0011/0x093c and the
  DSC torque-request throttle via CAN 0x212 are labeled (see
  [dsc_can_arbitration_report.md](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md)),
  but pedal→throttle-motor control (motor drive, limp/home mode, TP sensor
  plausibility) has no report; also settle the logger PID 0x1410 conflict
  (injector pulse time vs. throttle pedal, noted in design doc §5.8).
- **C item 28 (open)** — **fuel pump control.** Zero coverage today (no report,
  no labels): find the pump relay GPIO drive and its control conditions
  (cranking, oil pressure, inertia switch input).
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
  handling and flood-clear are unmapped.
- **C item 32 (open)** — **power management / watchdog / main relay.** The PB15
  external-WDT heartbeat (`0x31c` / `0x11cc`, routing unverified per design doc
  §5.6) and the WDT ITI vector `0x7ffa8` are noted, but there is no
  main-relay/power-latch or power-state analysis; ties into the open reset
  investigation (C item 25).
- **C item 33 (open)** — **sensor acquisition / ADC front-end.**
  `ref_getSensorStuff__` `0x60c8` and `ref_readADCResult` `0x6fb0` are named,
  but per-sensor scaling, fault and rationality handling is not consolidated
  anywhere (MAF scaling is only covered inside
  [load_fueling_report.md](docs/investigations/60E15120_N3J1E/load_fueling_report.md)).
- **C item 34 (open)** — **limiter (rev limit / fuel cut / limp).**
  [reviews/limiter/](docs/investigations/60E15120_N3J1E/reviews/limiter/README.md)
  holds only a README; fuel-cut arbitration `0xedc4` is currently a subsection
  of [fueling_control_report.md](docs/investigations/60E15120_N3J1E/fueling_control_report.md).
  Deliver a dedicated limiter report + labels.
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
  merged + per-ROM defs + label-map evidence, tests; then the defs passes +
  pipeline validators + `python -m pytest tests/`.

- **C item 39 (open)** — **reader-focused reorganisation of the investigation
  docs (dedup + indexes; the per-subsystem report migration is split out into
  C items 42–61).** `docs/investigations/` has grown organically: ~20 root
  reports for 60E15120_N3J1E alone (~9.5k lines counting `labeling/`) plus
  `reviews/` evidence folders, with overlapping report pairs that re-derive the
  same content instead of cross-linking
  ([`os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md)
  vs [`os_scheduling_deep_dive_report.md`](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md),
  [`load_fueling_report.md`](docs/investigations/60E15120_N3J1E/load_fueling_report.md)
  vs [`fueling_control_report.md`](docs/investigations/60E15120_N3J1E/fueling_control_report.md),
  [`idle_control_report.md`](docs/investigations/60E15120_N3J1E/idle_control_report.md)
  vs [`idle_target_control_report.md`](docs/investigations/60E15120_N3J1E/idle_target_control_report.md)),
  and per-ROM `README.md` indexes duplicating the top-level
  [`docs/investigations/README.md`](docs/investigations/README.md). The
  shared-logic placement groundwork is done — [`docs/subsystem-logic/`](docs/subsystem-logic/README.md)
  exists with the human-first
  [`TEMPLATE.md`](docs/subsystem-logic/TEMPLATE.md) and the placement rules are
  baked into [`AGENTS.md`](AGENTS.md) (repo map + rule 8), the subsystem-logic
  and investigations READMEs, [`README.md`](README.md) and
  [`docs/learnings.md`](docs/learnings.md); migrating each individual report is
  tracked per subsystem in C items 42–61. Remaining scope here:
  (a) one reading order — a single entry-point index per ROM folder (what to
  read first, in what sequence) merged with the top-level index so there is
  one source of truth; (b) dedup — fold duplicated sections into one canonical
  report per topic and leave the other as a short summary + cross-link
  (AGENTS.md rule 8), unique evidence staying in exactly one place
  (`reviews/<subsystem>/` remains the evidence home); (c) uniform shape —
  spot-audit the root reports still in the old 10-section layout against
  [`docs/investigations/TEMPLATE.md`](docs/investigations/TEMPLATE.md) / rule 8
  until each is migrated; (d) maintainability — extend the link +
  non-empty-size check to every `.md` under `docs/` (the pipeline validators
  only scan `*_report.md`, so a truncated review note is not caught) and add a
  short "how to add a report" section to
  [`docs/investigations/README.md`](docs/investigations/README.md).
  Constraints: no evidence loss — every address, label and validation claim
  survives any move (rules 5/7); after each touched doc: re-run the pipeline
  validators, the link check over all touched docs and `python -m pytest tests/`.

- **C items 42–61 (open)** — **per-subsystem migration of the remaining
  60E15120_N3J1E root reports into `docs/subsystem-logic/`** in the human-first
  format. Worked example:
  [`knock_control_report.md`](docs/subsystem-logic/knock_control_report.md);
  rules: AGENTS.md rule 8 +
  [`docs/subsystem-logic/TEMPLATE.md`](docs/subsystem-logic/TEMPLATE.md). Each
  item: move the named report with `git mv`, restructure it human-first
  (header: applicable-ROMs table listing only investigated ROMs + ROM SHA-256 +
  static-analysis disclaimer; §1 plain-language introduction; §2 step-by-step
  body, starting with a hardware setup diagram when the subsystem touches
  hardware; §3 technical pseudocode; §4 proof with the mandatory memory map,
  labeling, corrections, files, validation, limits and §4.7 related reports),
  keep every address, label and validation claim (rules 5/7), and update all
  cross-references in the same change — including generated label artifacts via
  their generators (rule 6d), e.g. `build_table_labels.py` source paths — then
  re-run the pipeline validators, the link + non-empty check over `docs/` and
  `python -m pytest tests/`. If a report's logic turns out ROM-specific rather
  than shared, leave it in `docs/investigations/` and close the item with that
  reason instead of migrating.
  - **C item 42 (open)** — migrate [`can_mailbox_config_report.md`](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md)
  - **C item 43 (open)** — migrate [`cooling_fan_control_report.md`](docs/investigations/60E15120_N3J1E/cooling_fan_control_report.md)
  - **C item 44 (open)** — migrate [`cruise_control_report.md`](docs/investigations/60E15120_N3J1E/cruise_control_report.md)
  - **C item 45 (open)** — migrate [`dsc_can_arbitration_report.md`](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md)
  - **C item 46 (open)** — migrate [`dtc_authoring_report.md`](docs/investigations/60E15120_N3J1E/dtc_authoring_report.md)
  - **C item 47 (open)** — migrate [`dtc_control_report.md`](docs/investigations/60E15120_N3J1E/dtc_control_report.md)
  - **C item 48 (open)** — migrate [`e2ram_device_layer_report.md`](docs/investigations/60E15120_N3J1E/e2ram_device_layer_report.md)
  - **C item 49 (open)** — migrate [`e2ram_nv_storage_report.md`](docs/investigations/60E15120_N3J1E/e2ram_nv_storage_report.md)
  - **C item 50 (open)** — migrate [`eeprom_content_map_report.md`](docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md)
  - **C item 51 (open)** — migrate [`fueling_control_report.md`](docs/investigations/60E15120_N3J1E/fueling_control_report.md)
  - **C item 52 (open)** — migrate [`idle_control_report.md`](docs/investigations/60E15120_N3J1E/idle_control_report.md)
  - **C item 53 (open)** — migrate [`idle_target_control_report.md`](docs/investigations/60E15120_N3J1E/idle_target_control_report.md)
  - **C item 54 (open)** — migrate [`ignition_power_state_report.md`](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md)
  - **C item 55 (open)** — migrate [`ignition_timing_report.md`](docs/investigations/60E15120_N3J1E/ignition_timing_report.md)
  - **C item 56 (open)** — migrate [`intake_solenoids_report.md`](docs/investigations/60E15120_N3J1E/intake_solenoids_report.md)
  - **C item 57 (open)** — migrate [`load_fueling_report.md`](docs/investigations/60E15120_N3J1E/load_fueling_report.md)
  - **C item 58 (open)** — migrate [`o2_sensor_monitor_report.md`](docs/investigations/60E15120_N3J1E/o2_sensor_monitor_report.md)
  - **C item 59 (open)** — migrate [`os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md)
  - **C item 60 (open)** — migrate [`os_scheduling_deep_dive_report.md`](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)
  - **C item 61 (open)** — migrate [`uds_mode22_dispatch_report.md`](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)

- **C items 62–90 (open)** — **per-subsystem end-of-C fold-back: push each
  subsystem's new knowledge back into the decompiled export, the label
  artifacts and the ECU defs.** One item per subsystem covered by items 26–61,
  so each fold-back is its own reviewable work unit and nothing learned during
  group C lives only in `docs/`. Per item: (a) decompiled code — re-run the
  annotation + `integrate_reviewed_names.py` + comment-merge passes over
  `reverse-engineered/decompiled/60E15120_N3J1E/` (`functions/`,
  `firmware_decompiled.c`, `named/firmware_named.c`) so the subsystem's new
  function, RAM-cell and table names carry their accepted aliases and review
  comments in the export; (b) labels — fold the subsystem's label record into
  the canonical TSVs, the labels JSONs and `symbols.tsv` coverage and re-fill
  `validation.json`, keeping the rule-6 ladder (no upgrades without
  binary-level evidence, rule 7); (c) defs — apply the subsystem's table
  labels, scalars and storage-type corrections to the merged def, then
  regenerate the per-ROM defs and `defs_table_labels.json` via the re-runnable
  defs-merge passes (rule 6d: edit the generators, never the generated files).
  Finish each item with the pipeline validators (`validate_export.py`,
  `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`), the link + non-empty check over `docs/`, and
  `python -m pytest tests/`. Cross-cutting outputs stay with their own items
  (36 export audit, 37 defs audit, 39 docs reorg); subsystems already migrated
  to [`docs/subsystem-logic/`](docs/subsystem-logic/README.md) (alternator,
  knock, SBL bootloader) were folded by the earlier annotation passes and are
  out of scope here.
  - **C item 62 (open)** — fold back **immobilizer** (item 26's report + `data/labels/60E15120_N3J1E/immobilizer_labels.json` + per-ROM records)
  - **C item 63 (open)** — fold back **throttle / DBW** (item 27)
  - **C item 64 (open)** — fold back **fuel pump control** (item 28)
  - **C item 65 (open)** — fold back **misfire detection / monitor** (item 29)
  - **C item 66 (open)** — fold back **emissions monitors beyond O2** (item 30)
  - **C item 67 (open)** — fold back **starting / cranking** (item 31)
  - **C item 68 (open)** — fold back **power management / watchdog / main relay** (item 32)
  - **C item 69 (open)** — fold back **sensor acquisition / ADC front-end** (item 33)
  - **C item 70 (open)** — fold back **limiter** (item 34)
  - **C item 71 (open)** — fold back [`can_mailbox_config_report.md`](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md) (item 42)
  - **C item 72 (open)** — fold back [`cooling_fan_control_report.md`](docs/investigations/60E15120_N3J1E/cooling_fan_control_report.md) (item 43)
  - **C item 73 (open)** — fold back [`cruise_control_report.md`](docs/investigations/60E15120_N3J1E/cruise_control_report.md) (item 44)
  - **C item 74 (open)** — fold back [`dsc_can_arbitration_report.md`](docs/investigations/60E15120_N3J1E/dsc_can_arbitration_report.md) (item 45)
  - **C item 75 (open)** — fold back [`dtc_authoring_report.md`](docs/investigations/60E15120_N3J1E/dtc_authoring_report.md) (item 46)
  - **C item 76 (open)** — fold back [`dtc_control_report.md`](docs/investigations/60E15120_N3J1E/dtc_control_report.md) (item 47)
  - **C item 77 (open)** — fold back [`e2ram_device_layer_report.md`](docs/investigations/60E15120_N3J1E/e2ram_device_layer_report.md) (item 48)
  - **C item 78 (open)** — fold back [`e2ram_nv_storage_report.md`](docs/investigations/60E15120_N3J1E/e2ram_nv_storage_report.md) (item 49)
  - **C item 79 (open)** — fold back [`eeprom_content_map_report.md`](docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md) (item 50)
  - **C item 80 (open)** — fold back [`fueling_control_report.md`](docs/investigations/60E15120_N3J1E/fueling_control_report.md) (item 51)
  - **C item 81 (open)** — fold back [`idle_control_report.md`](docs/investigations/60E15120_N3J1E/idle_control_report.md) (item 52)
  - **C item 82 (open)** — fold back [`idle_target_control_report.md`](docs/investigations/60E15120_N3J1E/idle_target_control_report.md) (item 53)
  - **C item 83 (open)** — fold back [`ignition_power_state_report.md`](docs/investigations/60E15120_N3J1E/ignition_power_state_report.md) (item 54)
  - **C item 84 (open)** — fold back [`ignition_timing_report.md`](docs/investigations/60E15120_N3J1E/ignition_timing_report.md) (item 55)
  - **C item 85 (open)** — fold back [`intake_solenoids_report.md`](docs/investigations/60E15120_N3J1E/intake_solenoids_report.md) (item 56)
  - **C item 86 (open)** — fold back [`load_fueling_report.md`](docs/investigations/60E15120_N3J1E/load_fueling_report.md) (item 57)
  - **C item 87 (open)** — fold back [`o2_sensor_monitor_report.md`](docs/investigations/60E15120_N3J1E/o2_sensor_monitor_report.md) (item 58)
  - **C item 88 (open)** — fold back [`os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md) (item 59)
  - **C item 89 (open)** — fold back [`os_scheduling_deep_dive_report.md`](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md) (item 60)
  - **C item 90 (open)** — fold back [`uds_mode22_dispatch_report.md`](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md) (item 61)

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
- **F item 4 (answered statically + emulator handler-level; bench verification
  still open)** — the OBD upload path is the app's **0xB1 00B2**, not the app
  0x34/0x36/0x37 stubs (0x5d7bc/0x5d834/0x5d874 on 60E15120_N3J1E): app service
  0xB1 = 0x565e8 -> sub-record 0x5f0f4 -> handler 0x56350 (needs session 0x85 via
  0xffffd1cf, unlock level 1 via 0xffffd1d0, conditions 0x56428 = battery
  8.0-16.5 V + 0x1008() < 100, data byte 0) queues F1 00 B2 (0x564ac) and sets
  boot-request 0xffffd1dc = 3 (0x563de(3)); after the response, 0x680de ->
  0x6892a -> 0x54a36(0xb1) -> 0x563de(1) -> 0x564d4 -> 0x1038(1) enters the SBL
  loop 0x1378, where 0x34/0x36/0x37 stage and jump to the flash kernel and 0xb1
  (0x1d78) only arms one download (0xffffdfb3) — the SBL has no flash-write path.
  So over OBD: 10 85, 27 01/02 (app key algorithm 0x5609e), B1 00 B2 00 ->
  F1 00 B2, then the SBL answers its own 10 85 / 27 (fixed 55 AA 55 / 4D AC CD)
  before 34/36/37. Details + emulator validation (tests/test_sbl_bootloader.py):
  [sbl_bootloader_report.md](docs/subsystem-logic/sbl_bootloader_report.md) §2.3.
  Remaining: bench-ECU confirmation of the full sequence (still gated on F
  item 1/2 bench validation); the emulator can only drive the app side at
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
