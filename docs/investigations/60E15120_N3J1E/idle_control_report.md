# Idle speed control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/idle_control_labels.json`; detailed
evidence in [`reviews/idle_control/README.md`](reviews/idle_control/README.md).

**Related reports:** target-RPM calculation in
[`idle_target_control_report.md`](idle_target_control_report.md); task structure
and task[10] in [`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md);
the VDI wrapper called from the same batch in
[`intake_solenoids_report.md`](intake_solenoids_report.md); Mode 22 PID 0x096e in
[`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md); the E2RAM-backed
trim cells in [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md); throttle
plate/torque chain names are inherited `ref_` hypotheses from the upstream project.

## 1. Executive summary

Idle speed control runs as a **28-call batch** `idle_control_calc_batch` 0x167c0
(27 `jsr` + 1 tail `jmp`, 174-byte body) under interrupt mask 0x10, called from
task[10] body 0x11744 (task table rec[10].entry thunk 0x64f6 at ROM 0x4a38). The
inherited `ref_updateIdleControl__` name is **confirmed** by the callee set: all
26 callees (pool 0x16888-0x168fc) compute idle air terms, the idle target, the
idle feedback, the stall/learn flags and the long-term trim.

The chain is:

1. **Target**: `idle_target_rpm_calculate` 0x1506c (see
   [`idle_target_control_report.md`](idle_target_control_report.md)) filters the
   target and writes float `idle_target_rpm` 0xffffa7f4, then encodes it through
   `idle_target_encode_u16` 0x5ca94 to a u16 at 0.25 rpm/LSB into 0xffffa7ac —
   which is exactly the Mode 22 **PID 0x096e** source (handler 0x56e22, ×0.25).
   0x5ca94 also mirrors the value into the diagnostic override cell 0xffffd34d
   when the active DID is 0x96e; it is **not** an actuator register.
2. **Air terms**: barometric comp (0x16358), IAT comp (0x16720), A/C load
   (0x16748), MAF-derived term (0x148c4), target term (0x148a4), correction
   select (0x16900), aux term (0x16380), summed/filtered into the
   0xffffa8xx workspace.
3. **Feedback**: `idle_air_feedback_calc` 0x15a9a compares actual rpm
   (0xffffb548) with the quantized target (0xffffa7ac) and computes the required
   idle air (0xffffa838 = min(baro × IAT × airflow term, rpm-error term)).
4. **Output**: `idle_air_output_clamp` 0x216f8 clamps 0xffffa838 between
   coolant-indexed tables into `idle_air_required` 0xffffb2a4, which the
   electronic-throttle chain reads (0x21a80 `ref_throttlePlatePosToTorqueOutput_`,
   pool 0x21b10) — the RX-8 has a drive-by-wire throttle body (terminals 1B/1C),
   so idle air is executed by the throttle plate motor, not a separate IAC valve.
5. **Trim**: `candidate_idle_trim_integrator` 0x1617e integrates a long-term trim
   (±1e-5 steps, clamp ±0.12) into the E2RAM-backed cells 0xffff8040/0xffff8048
   when the learn flag 0xffffa890 is set; `candidate_idle_trim_load` 0x15fa0
   loads it back each cycle.

## 1a. Plain-language summary

When the engine is idling, the PCM first decides the target rpm (cold engines
idle faster; A/C and electrical load raise it — see
[`idle_target_control_report.md`](idle_target_control_report.md)). It then works
out how much air the engine needs to hold that rpm, using measured airflow,
barometric pressure, intake temperature and A/C state, compares it with what the
rpm error demands, and clamps the result to calibrated coolant-dependent limits.
That air demand is handed to the electronic throttle, which opens or closes the
throttle plate to hit the target rpm. A slow "trim" remembers small persistent
errors and stores them in non-volatile memory so the idle stays accurate over
time. The target rpm is also reported on the diagnostic port (Mode 22 PID 0x096e)
with 0.25 rpm resolution.

## 2. How it works (condensed pseudocode)

```
# task[10]: 0x64f6 -> 0x11744 -> ... -> idle_control_calc_batch 0x167c0 (mask 0x10)
idle_control_calc_batch:                    # 0x167c0, 28-call batch
  prev_sr = sh_raise_interrupt_mask_return_previous(0x10)   # jsr 0x167c6 -> 0x3920
  idle_target_term_lookup(a7ac)             # 0x148a4: a7a0 = tbl 0x692bc(a7ac)
  idle_ac_load_calc()                       # 0x16748: tbl 0x69530 | 3D 0x69544 -> a8c4, filter a8c8
  idle_baro_comp()                          # 0x16358: a898 = 3D 0x6a814(baro, a834)
  idle_air_correction_select()              # 0x16900: a8cc/a8d0 from tbls 0x69244..0x692a8 by bd69/b534/b53c/b540/bdb8
  idle_maf_airflow_term()                   # 0x148c4: a7a4 = tbl(0x6a100/0x6a114/0x6a128)(b5a8)*0.6345*60/a7ac
  idle_air_terms_sum()                      # 0x15f5c: a888 = a8cc + a7a4
  ... flag/timer bodies 0x14944, 0x14baa ...
  idle_target_rpm_calculate()               # 0x1506c: target -> 0xffffa7f4 -> 0x5ca94 -> 0xffffa7ac (PID 0x096e)
  ... 0x14d10, 0x14f6c, 0x16432, 0x165d6, 0x16672, 0x15ffc (stall/learn flags) ...
  idle_trim_integrator()                    # 0x1617e: learn trim into 0xffff8040/8048 when a890
  idle_trim_load()                          # 0x15fa0: a88c = read(0xffff8040 | 0xffff8048)
  fuel_cut_resume_threshold()               # 0x15a40, aux_air_term 0x16380, iat_comp 0x16720
  idle_ratio_calcs() 0x3337c, idle_ac_blend_ramp() 0x3354e, idle_vehicle_speed_flags() 0x34650
  FUN_00034814 (VDI wrapper)                # 0x34814
  idle_air_feedback_calc()                  # 0x15a9a: rpm vs a7ac -> a838 = min(a898*a8c0*a848, a83c)
  idle_air_output_clamp()                   # 0x216f8: b2a4 = clamp(tbl 0x6a218(a838), tbl 0x6a240(a990), tbl 0x6a22c(a990))
  tail jmp -> ref_setSR 0x3934              # jmp 0x1686a via pool 0x168f4

# output path: 0xffffb2a4 read by 0x21a80 ref_throttlePlatePosToTorqueOutput_ (pool 0x21b10)
#   -> electronic throttle plate motor (PCM terminals 1B/1C, board routing to chip pins unresolved)
```

## 3. Key calibrated tables

Descriptors parsed from ROM (`>HBBII`, type 4 = u8 data, type 8 = u16):

| Descriptor | Dims | Type | Axis | Data | Role |
|---|---|---|---|---|---|
| 0x6a218 | 21 | 4 | 0x732dc | 0x73330 | idle air output base (indexed by 0xffffa838) |
| 0x6a22c / 0x6a240 | 13 / 13 | 4 | 0x73348 / 0x7338c | 0x7337c / 0x733c0 | idle air clamp min/max (coolant axis) |
| 0x6947c / 0x69490 / 0x694b8 | 9 / 5 / 14 | 4 | 0x6dff4 / 0x6e024 / 0x6e060 (rpm) | 0x6e018 / 0x6e038 / 0x6e098 | feedback correction tables (0x15a9a) |
| 0x69440 / 0x69454 | 9 / 9 | 4 | coolant 0x6df64 / 0x6df94 | 0x6df88 / 0x6dfb8 | feedback clamp tables (0x15a9a) |
| 0x694a4 | 6 | 4 | coolant 0x6e040 | 0x6e058 | cranking correction (0x15a9a) |
| 0x69244–0x692a8 | 6 × 2-D | — | — | — | idle air correction select (0x16900) |
| 0x692bc | 2-D | — | 0xffffa7ac | — | target term (0x148a4) |
| 0x6a100 / 0x6a114 / 0x6a128 | 2-D | — | 0xffffb5a8 | — | MAF airflow term (0x148c4) |
| 0x6a814 / 0x6a830 / 0x6a13c | 3-D / 2-D | — | baro / IAT / 0xffffb220 | — | baro, IAT, aux comps |
| 0x69530 / 0x69544 | 2-D / 3-D | — | coolant / catalyst | — | A/C load (0x16748) |
| 0x69424 | 3-D | — | coolant, baro | — | trim ramp floor (0x14f6c) |
| 0x694cc | 2-D | — | coolant | — | A/C request term (0x16432) |
| 0x69768 | 2-D | — | 0xffffa6ac | — | fuel-cut resume threshold (0x15a40) |
| 0x6b318 / 0x6b32c | 2-D | — | vspeed / rpm | — | vehicle-speed flags (0x34650) |
| 0x6af18 / 0x6af40 | 2-D | — | coolant / 0xffffc04c | — | ratio calcs (0x3337c) |

Verified constants: 0.25 rpm/LSB encode step (f32 0x3e800000 at ROM 0x5cb64),
312.0 rpm floor (0x6df44), 29.1969 (0x6df48), 0.892 (0x6df58), 0.15 (0x6df5c),
2.72 (0x6df60), 0.6345 (shared pool 0x7a088), 0.00087 trim ramp (0x6dabc).

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x167c0 | `idle_control_calc_batch` | high |
| 0x15a9a | `idle_air_feedback_calc` | high |
| 0x216f8 | `idle_air_output_clamp` | high |
| 0x5ca94 | `idle_target_encode_u16` | high |
| 0x1617e | `candidate_idle_trim_integrator` | medium |
| 0x15fa0 | `candidate_idle_trim_load` | medium |
| 0x16900 | `candidate_idle_air_correction_select` | medium |
| 0x16748 | `candidate_idle_ac_load_calc` | medium |
| 0x16358 | `candidate_idle_baro_comp` | medium |
| 0x148c4 | `candidate_idle_maf_airflow_term` | medium |
| 0x148a4 | `candidate_idle_target_term_lookup` | medium |
| 0x15f5c | `candidate_idle_air_terms_sum` | medium |
| 0x16720 | `candidate_idle_iat_comp` | medium |
| 0x16380 | `candidate_idle_aux_air_term` | medium |
| 0x15a40 | `candidate_fuel_cut_resume_threshold` | medium |
| 0x14944 / 0x14baa / 0x14d10 / 0x14f6c | `candidate_idle_drive_flags` / `_mode_timers` / `_stall_flags` / `_trim_ramp` | medium |
| 0x16432 / 0x165d6 / 0x16672 / 0x15ffc | `candidate_idle_ac_request_calc` / `_ac_clutch_gate` / `_stall_detect` / `_learn_condition` | medium |
| 0x3337c / 0x3354e / 0x34650 | `candidate_idle_ratio_calcs` / `_ac_blend_ramp` / `_vehicle_speed_flags` | medium |

RAM aliases: `idle_air_required` 0xffffb2a4, `idle_air_calc_total` 0xffffa838,
`idle_trim_learn_active` 0xffffa890, `ac_clutch_on` 0xffffbd69,
`automatic_transmission` 0xffffb534, `high_load_flag` 0xffffb5b3.

Evidence: `source_review/accepted_function_aliases.tsv` /
`accepted_ram_aliases.tsv`, `data/labels/60E15120_N3J1E/idle_control_labels.json`.

## 5. Corrections made in this pass

- `ref_updateIdleControl__` 0x167c0 renamed to `idle_control_calc_batch`: the
  binary-verified callee set (pool 0x16888-0x168fc) is the idle air/target/trim
  chain; the `ref_` prefix (inherited hypothesis) is dropped per the label ladder.
- The open question "output path of 0x5ca94" from
  [`idle_target_control_report.md`](idle_target_control_report.md) §9 is settled:
  0x5ca94 is `idle_target_encode_u16`, the target→u16 (0.25 rpm/LSB) encoder for
  Mode 22 PID 0x096e (0xffffa7ac, handler 0x56e22) plus the diagnostic override
  cell 0xffffd34d — not an actuator register. The actual idle output is
  0xffffb2a4 → 0x21a80 throttle-plate torque chain.
- Select-flag producers found (previously "inferred, not proven"): 0xffffbdb8 =
  A/C switch input (`ref_getACSwitchStatus` 0x2f868: `(0xffff9ecd & 4) == 0`;
  cell already carried the inferred PID-0x1102 alias, kept), 0xffffbd69 = A/C
  clutch-on (0x2e9a4 gating chain), 0xffffb534 = automatic transmission
  (`ref_getAutoTransCal__` 0x24b44 sets 1), 0xffffb5b3 = high-load flag
  (0x264f0, filtered 0xffffb5e0 ≥ 40, hysteresis 30).

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/review_idle_control_labels.py` (wired into
  `rebuild.sh` after `review_intake_labels.py`; idempotent)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/idle_control_labels.json`
- `reverse-engineered/decompiled/60E15120_N3J1E/` (symbols renamed in place by
  `integrate_reviewed_names.py`; filenames keep historical names)
- `docs/investigations/60E15120_N3J1E/reviews/idle_control/README.md`,
  `reviews/idle_control/validation.json`

## 7. Validation

- Binary-level: 28-call batch of 0x167c0 re-counted in the disassembly (27 `jsr` +
  1 tail `jmp`); pool 0x16888-0x168fc words read from ROM and resolved to the 26
  callees + mask/SR helpers; 0x5ca94 pool words (0x5cb42 = 0x96e DID compare,
  0x5cb64 = f32 0.25 step, 0x5cb68 = 0x2490 encoder) verified in ROM; table
  descriptors 0x6a218/0x6a22c/0x6a240 and 0x69440-0x694b8 parsed from ROM;
  0xffffb2a4 reader scan via mov.w pool words (0x21b10 → 0x21a80 etc.).
- `validate_export.py` (ROM SHA-256 + 168,592 instruction bytes + 1,833 exact
  reference matches), `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`, `validate_reports.py` — all PASS;
  `data/labels/60E15120_N3J1E/{validation,claim_validation,report_validation}.json`.
- Follow-up claims-verification pass: every machine-checkable claim re-run
  (`verify_claims.py` / `validate_reports.py` PASS) and every binary-level claim
  re-read from the raw ROM and disassembly (see
  [`reviews/idle_control/validation.json`](reviews/idle_control/validation.json)
  `claim_verification`). Two errors found and fixed in all artifacts: the 0x216f8
  pool words were cited one word off (0x21744 = 0x2068, 0x21748 = 0x6a218,
  0x2174c = 0x6a240), and the §3 feedback-table row listed the axis addresses
  (0x6dff4/0x6e024/0x6e060) as data — the data cells are 0x6e018/0x6e038/0x6e098.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x000167c0 | `idle_control_calc_batch` | 28-call idle batch under mask 0x10 |
| 0x00011744 | `FUN_00011744` | task[10] body, calls 0x167c0 |
| 0x000064f6 | `FUN_000064f6` | task[10] entry thunk → 0x11744 |
| 0x0001506c | `idle_target_rpm_calculate` | idle target rpm → 0xffffa7f4 |
| 0x00015a9a | `idle_air_feedback_calc` | rpm vs target → idle air 0xffffa838 |
| 0x000216f8 | `idle_air_output_clamp` | clamp → 0xffffb2a4 |
| 0x0005ca94 | `idle_target_encode_u16` | target → u16 0xffffa7ac (PID 0x096e) |
| 0x0001617e | `candidate_idle_trim_integrator` | trim learn → 0xffff8040/8048 |
| 0x00015fa0 | `candidate_idle_trim_load` | trim load → 0xffffa88c |
| 0x00016900 | `candidate_idle_air_correction_select` | correction table select |
| 0x00016748 / 0x00016358 | `candidate_idle_ac_load_calc` / `candidate_idle_baro_comp` | A/C load / baro comp |
| 0x000148c4 / 0x000148a4 / 0x00015f5c | `candidate_idle_maf_airflow_term` / `candidate_idle_target_term_lookup` / `candidate_idle_air_terms_sum` | air terms |
| 0x00016720 / 0x00016380 / 0x00015a40 | `candidate_idle_iat_comp` / `candidate_idle_aux_air_term` / `candidate_fuel_cut_resume_threshold` | IAT / aux / fuel-cut |
| 0x00014944 / 0x00014baa / 0x00014d10 / 0x00014f6c | `candidate_idle_drive_flags` / `candidate_idle_mode_timers` / `candidate_idle_stall_flags` / `candidate_idle_trim_ramp` | flags, timers, ramp |
| 0x00016432 / 0x000165d6 / 0x00016672 / 0x00015ffc | `candidate_idle_ac_request_calc` / `candidate_idle_ac_clutch_gate` / `candidate_idle_stall_detect` / `candidate_idle_learn_condition` | A/C gate, stall detect, learn flag |
| 0x0003337c / 0x0003354e / 0x00034650 | `candidate_idle_ratio_calcs` / `candidate_idle_ac_blend_ramp` / `candidate_idle_vehicle_speed_flags` | ratios, blend ramp, vspeed flags |
| 0x00034814 | `FUN_00034814` | VDI wrapper called from the batch |
| 0x00003920 / 0x00003934 | `sh_raise_interrupt_mask_return_previous` / `ref_setSR` | mask raise / restore |
| 0x00021a80 | `ref_throttlePlatePosToTorqueOutput_` | reads 0xffffb2a4 (output path) |
| 0x00024b44 / 0x0002f868 / 0x0002e9a4 / 0x000264f0 / 0x0002633e | `ref_getAutoTransCal__` / `ref_getACSwitchStatus` / `FUN_0002e9a4` / `FUN_000264f0` / `FUN_0002633e` | select-flag producers |
| 0x00056e22 | `candidate_diag22_pid096e_ram_a7ac_quarter` | Mode 22 PID 0x096e handler |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x16888-0x168fc | 0x167c0 literal pool (call targets + helpers) |
| 0x5cb3e-0x5cb6b | 0x5ca94 pool (0x5cb42 = 0x96e, 0x5cb64 = f32 0.25, 0x5cb68 = 0x2490) |
| 0x21740-0x2175c | 0x216f8 pool (0x21744 = 0x2068, 0x21748 = 0x6a218, 0x2174c = 0x6a240, 0x2175c = 0x2404) |
| 0x4a38 | task table rec[10].entry = 0x64f6 (base 0x4990 + 10*16 + 8) |
| 0x6a218, 0x6a22c, 0x6a240, 0x69440-0x694b8, 0x69530, 0x69544, 0x69424, 0x692bc, 0x69244-0x692a8, 0x6a100-0x6a13c, 0x6a814, 0x6a830, 0x69768, 0x6b318, 0x6b32c, 0x6af18, 0x6af40, 0x694cc | idle calibration descriptors (see §3) |
| 0x6df44-0x6df60, 0x7a088, 0x6dabc | float constants (see §3) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffa7f4 | `idle_target_rpm` | filtered idle target rpm (float) |
| 0xffffa7ac | `DAT_ffffa7ac` | quantized target u16; PID 0x096e source (×0.25) |
| 0xffffb2a4 | `idle_air_required` | clamped idle air output → 0x21a80 |
| 0xffffa838 | `idle_air_calc_total` | unclamped idle air from 0x15a9a |
| 0xffffa890 | `idle_trim_learn_active` | trim learn enable (0x15ffc) |
| 0xffffbd69 | `ac_clutch_on` | A/C clutch-on (producer 0x2e9a4) |
| 0xffffb534 | `automatic_transmission` | AT flag (producer 0x24b44) |
| 0xffffb5b3 | `high_load_flag` | filtered-load ≥40 flag (producer 0x264f0) |
| 0xffffbdb8 | `DAT_ffffbdb8` | A/C switch input (PID 0x1102 cell; producer 0x2f868) |
| 0xffff8040 / 0xffff8048 | `DAT_ffff8040` / `DAT_ffff8048` | E2RAM-backed idle trim cells |

## 9. Limits

- Static analysis only; no emulator/datalog run of the idle loop in this pass.
- 0xffffb53c's exact meaning is still not pinned (cleared in the AT branch of
  0x24b8c; MT producer not traced here).
- 0xffffb5b3's underlying quantity sits in the alternator domain (0xffffb5a4 ratio
  in 0x2ce18); its physical meaning is deferred to the alternator/charging report.
- The throttle-plate motor drive itself (0x218c4 chain) and the
  package-pin↔connector-terminal hop (terminals 1B/1C) are outside this pass.
- `candidate_` labels are hypotheses pending dynamic or cross-ROM proof.

## 10. Related subsystems

Idle air feeds the fueling chain
([`fueling_control_report.md`](fueling_control_report.md) /
[`load_fueling_report.md`](load_fueling_report.md)); the batch also calls the VDI
wrapper ([`intake_solenoids_report.md`](intake_solenoids_report.md)); the trim
cells live in the E2RAM-backed window
([`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md)); task scheduling in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); PID 0x096e
in [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md).
