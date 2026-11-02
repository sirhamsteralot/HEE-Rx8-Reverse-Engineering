# Knock control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Date: 2026-10-29 (revised same day after an independent sceptical re-check
against the ROM bytes and both def sets; corrections listed in
[`reviews/knock_control/REVIEW_NOTES.md`](reviews/knock_control/REVIEW_NOTES.md)). Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes. No hardware execution was
performed. Full evidence: [`reviews/knock_control/README.md`](reviews/knock_control/README.md).

**Related reports:** retard applies to [ignition timing](ignition_timing_report.md); blend-weight producer 0x200c6 feeds [fueling control](fueling_control_report.md); load axis from [load & fuelling model](load_fueling_report.md); [calibration extraction](calibration_extraction_report.md) (knock tables in data/maps/); [UDS/Mode-22 dispatch](uds_mode22_dispatch_report.md) (PID 0x1746 exposes this report's retard cell).

## 1. Executive summary

The PCM runs a **closed-loop knock control** on both rotors. It listens to each
rotor through an external knock amplifier (per-rotor noise threshold commanded
over SCI0, filtered level read back via ADC), integrates the knock magnitude
against an adaptive noise threshold, and when knock is detected it **retards
the ignition timing quickly (−1.0° per cycle)**. When knock stops it **recovers
slowly (+0.35° per 62 cycles)**. The retard is a negative angle clamped to a
calibrated, RPM-dependent window of [−10°, 0°], fail-safes to a table (up to
−10°) when the knock sensors are unhealthy, resets at very high RPM, and slowly
learns a persistent offset into EEPROM.

**Key finding: knock control applies in open loop as well as closed loop.**
None of the ~40 functions in the knock chain read the loop-mode flags; its
gates are engine conditions only (run time, coolant, load, RPM, sensor health,
timing-not-already-retarded). Loop mode changes the *fueling* around the
knock correction, not the correction itself.

## 1a. Plain-language summary (what knock control means for timing)

- If the knock sensors hear detonation, the PCM **immediately retards the
  spark a little (-1.0 deg per cycle)**; when the knock stops it creeps back
  slowly (+0.35 deg per 62 cycles), never past a calibrated window
  (-10..0 deg). It works in open loop and closed loop alike.
- Consequence: the **ignition timing you see on OBD already includes any
  knock retard** — the base timing maps do not show it. If the knock sensors
  are unhealthy, a fail-safe table applies instead, and a persistent learned
  offset is stored in EEPROM.

## 2. How it works (condensed pseudocode)

```python
# --- sensing (per engine cycle; tasks 0x65f6 / 0x661e) ---
rpm_raw       = 120_000_000 / crank_period_sum            # ISR 0x803e -> RAM 0xffff9f80
knock_sample  = filter(read_adc(knock_sensor), 0.004)     # 0xc3ce; ADC 0xffff9ef8, only 200-2000 RPM; called from task[6] 0x661e
knock_ref     = read_adc(knock_reference)                 # 0xc276 -> RAM 0xffffa326; called from 0xc8dc (task[5] chain) and 0x5a4c

# --- magnitude (0xc486, per rotor) ---
voltage   = (knock_sample - knock_ref) * 5/65536           # RAM 0xffffa370
magnitude = lookup(tbl_0x6b250, voltage) - command_code*32 # RAM 0xffffa330
level_integrator[rotor] += min(|noise|, c060*|magnitude - level_running|)  # RAM 0xffffa33c[2]
noise_threshold[rotor]  += step * c064                    # RAM 0xffffa350[2], adaptive, clamped
command[rotor]  = clamp(level_combined + level_threshold*noise_excess, 64, 255) + noise_excess*2  # base RAM 0xffffa364, command RAM 0xffffa368[2]
send command[rotor] to knock amplifier over SCI0          # 0xc8dc; sensor pins 1F/1T/1G
knock_detected = (command_base <= magnitude)              # RAM 0xffffa324

# --- decision inputs (0x336c4 / 0x33970) ---
level_threshold = lookup_3d(load, rpm, knock_level_tables)   # RAM 0xffffa328; tables 0x6b2b8/0x6b2d4/0x6b2f0/0x6b304
attack_condition = knock_detected_latched and engine_running and run_time >= 2.5s \   # RAM 0xffffc078 / 0xffffa428 / 0xffffa424
                   and leading_timing  > 5 - threshold_a*0.15625 \                      # RAM 0xffffa630; threshold_a = raw u16 0xffffc090 (same value copied to 0xffffa37e)
                   and trailing_timing > 5 - threshold_a*0.15625                          # RAM 0xffffa638

# --- gates (0x13826/0x1388a/0x138b2): engine conditions only ---
knock_enable = run_time >= 3s and coolant >= 10C and load >= 0.5 and rpm < 5000   # RAM 0xffffa73d
knock_active = knock_enable and knock_sensors_healthy     # RAM 0xffffa73c = a73d && a73e (0xffffcd64 / 0xffffcd66)

# --- retard state machine (0x13a60 attack, 0x13b40 recovery, 0x13bd2 clamp) ---
# state: knock_retard = RAM 0xffffa734 (negative deg, [-10, 0]); mirror RAM 0xffffa738
if not knock_enable:            target = 0                        # control off
elif not sensors_healthy:       target = lookup(tbl_0x6afa4, rpm) # fail-safe, up to -10 deg
elif just_activated:            target = lookup(tbl_0x6afb8, learned_eeprom_retard)
elif knock_active and attack_condition:
                                target = knock_retard - 1.0          # ATTACK: -1 deg/cycle
elif knock_active and not attack_condition:
                                target = knock_retard + 0.35         # RECOVER: per 62 cycles (RAM 0xffffa74a/a74b)
else:                           target = knock_retard                # hold
knock_retard = clamp(target, lookup_min(rpm), lookup_max(rpm))      # 0x13bd2; min tbl 0x6af68/0x6af7c, max tbl 0x6af90
knock_retard_mirror = knock_retard

# --- learning (0x139c4): persistent adaptation; EEPROM address held in RAM 0xffff8038 ---
if knock_seen_learn_trigger:                                  # RAM 0xffffa73f
    eeprom = filter(knock_retard, eeprom, 0.0039); eeprom_write(eeprom)

# --- apply (0x125bc/0x125f6 -> 0x123ba/0x123ca -> 0x12300) ---
correction  = (knock_retard - rough_knock_correction)         # rough: RAM 0xffffa6ac / 0xffffa6b0
correction -= max(coolant_derate, cold_start_reduction)       # RAM 0xffffa750/a754, 0xffffc9a0/c9a4
correction += idle_base_term + ac_compressor_retard           # idle/base term = RAM 0xffffa5e0 (writer not identified); A/C: RAM 0xffffb288/b28c, -5 deg while ramping
final_leading  = clamp(base_leading_timing  + correction, limits)   # RAM 0xffffa634 -> output 0xffffa630
final_trailing = clamp(base_trailing_timing + correction, limits)   # RAM 0xffffa63c -> output 0xffffa638
```

Memory addresses for every quantity above are listed in section 8.

Sensor health is monitored independently (0xc290 ADC window check ->
0x49fac persistence -> 0x4a084 raises **DTC 0x23/0x24**; the codes are
firmware-inferred — this ROM's def block has no DTC 0023/0024 tables);
unhealthy sensors both block knock control and force the fail-safe retard
table. Diagnostics: RomRaider PID 0x1746 "Knock Retard" (handler 0x5707a
`diag22_pid1746_knock_retard_deg`, uint8 × 0.3515625° — scale constant 0x3eb40000
re-verified in the handler's literal pool 2026-10-31) and OBD PID 0x0003 "OL Status"
(handler 0x568ca `diag22_pid0003_fuel_system_status_ol_cl`). Note
the 0x1746 encoding (clamp(trunc(x/0.3515625 + 0.5), 0, 255)) spans
[0, +89.7]°, so with knock_retard clamped to [−10, 0] the PID always reports
0.00° in this ROM; the logger def's desc text ("Tire Size") is a copy-paste
error.

## 3. Key calibrated tables

| Table | Contents |
|---|---|
| `tbl_knock_retard_clamp_min_0006af68` / alt `…_0006af7c` | retard clamp minimum vs RPM: −10° … 0° |
| `tbl_knock_retard_clamp_max_0006af90` | retard clamp maximum vs RPM: 0.0° (all cells) |
| `tbl_knock_recovery_target_0006afa4` | fail-safe retard when sensors unhealthy, vs RPM (−10…0°) |
| `tbl_knock_learned_retard_scale_0006afb8` | activation-edge target vs learned EEPROM retard (−8.4…+8.4°; all 0 in this ROM) |
| `tbl_knock_enable_load_floor_0006af54` | load floor 0.5 (flat) vs RPM 800–9600 |
| `tbl_knock_level_3d_a..d_0006b2b8/b2d4/b2f0/b304` | 3D knock level vs load/RPM |
| `tbl_ignition_timing_threshold_a/b_…_0006b27c/b294` | raw u16 thresholds A/B (alt pair) |
| `tbl_knock_transient_hold_0006b264` | 20-cycle transient hold (raw u8 << 1) |
| `tbl_closed_loop_warmup_time_0006990c` | engine warmup time before closed loop (raw u16 vs catalyst-temp model) |

## 4. Labeling applied (2026-10-29 pass)

- **39 functions** named in `source_review/accepted_function_aliases.tsv`
  (33 high confidence; 6 medium → `candidate_` prefix: `candidate_timing_retard_fast_task`,
  `candidate_knock_sensor_monitor_task`, `candidate_knock_sensor_fault_task`,
  `candidate_knock_rough_correction_update`, `candidate_o2_monitor_integrator`,
  `candidate_evap_open_loop_condition`).
- **84 RAM locations** named in `source_review/accepted_ram_aliases.tsv`
  (integrated as `<alias>_<address>`), e.g. `knock_retard_ffffa734` (pre-existing),
  `knock_detected_ffffa324`, `knock_attack_condition_ffffc05c`,
  `knock_level_integrator_ffffa33c[2]`, `open_loop_active_ffffb12c`,
  `closed_loop_active_ffffae1f`; 8 `snapshot_` locals renamed to match.
- **15 lookup-table rows** in `source_review/accepted_lookup_aliases.tsv`
  (merged into `named/lookup_aliases.tsv`).
- All renames applied to every synchronized view: per-function files,
  `decompiled/firmware_decompiled.c`, `named/firmware_named.c`,
  `decompiled/function_index.tsv` (name column; historical filenames kept),
  `decompiled/callgraph.tsv`, `decompiled/symbols.tsv`, and accumulated in
  `metadata/integrated_names.json`. Evidence notes added to the per-function
  files (`[ADDITIONAL SOURCE REVIEW]` blocks).

## 5. Corrections made in this pass

1. **Misnomer** `ref_setClosedLoopBool` (0x1ee30) → `set_open_loop_flag`.
2. **Misnomer** `ref_enableDisableCruiseControl__` (0xc116) →
   `reset_knock_state_on_mode_change` (it only resets knock state).
3. **Polarity**: 0xffffb12a/0xffffb12c are the **open**-loop flag (1 = open
   loop), proven by the OBD PID 0x0003 handler and the 0x1c13c/0x1ee4a logic.
   Earlier sessions had this backwards; the open-loop conclusion is unchanged.
4. **Signs**: `knock_retard` is a negative angle in [−10°, 0°]; attack =
   −1.0°/cycle, slow recovery = +0.35° per 62 counts (earlier session had
   these swapped).
5. **Export bug fixed**: 0x13bd2 `knock_retard_clamp` now returns the
   `rx8_clamp_float` result (SH fr0) instead of discarding it as `void`
   (disassembly 0x13c18–0x13c24 confirms the float return).

## 6. Files

| Artifact | Path |
|---|---|
| Full review (evidence, unresolved items) | [`reviews/knock_control/README.md`](reviews/knock_control/README.md) |
| Sceptical re-review addendum (corrections + def caveats) | [`reviews/knock_control/REVIEW_NOTES.md`](reviews/knock_control/REVIEW_NOTES.md) |
| Review validation record | `reviews/knock_control/validation.json` |
| Rename map + fix evidence | `metadata/knock_loop_labels.json` |
| Integrated rename manifest | `metadata/integrated_names.json` |
| Design document (subsystem map, §5.7) | `design/README.md` |
| Pipeline scripts (idempotent, in `scripts/rebuild.sh`) | `scripts/review_knock_loop_labels.py`, `scripts/merge_reviewed_lookup_aliases.py`, `scripts/review_knock_loop_labels_apply.py` |
| Pre-change backup | `backups/pre_knock_loop_labels.zip` |

## 7. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function
  files linked, 168,592 instructions byte-verified against the ROM, 1,833
  exact reference matches.
- `scripts/verify_readability.py` — pass: all 3,355 function bodies consistent
  between the per-function files and the combined C.
- `scripts/verify_math_units.py` — pass.
- `scripts/design_graph_stats.py` — pass (all 6 cross-checks true).
- The three new pipeline scripts are idempotent (re-running is a no-op).

## 8. Memory map for validation

Every address below can be checked directly in `decompiled/firmware_disassembly.asm`
(ROM addresses), in `decompiled/functions/<address>_*.c` (per-function C; index in
`decompiled/function_index.tsv`), and in the alias TSVs (evidence columns). RAM is
the 32 KiB window 0xffff6000–0xffffdfff; ROM tables live in the descriptor /
calibration area 0x0006c000–0x0007ffff.

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0000803e | `crank_isr_compute_rpm` (ISR; renamed 2026-10-31 from `ref_INT_ATU101_IMI10AG` — see §10) | crank period sum → raw RPM 0xffff9f80 |
| 0x0000c276 | `knock_reference_adc_read` | reference-channel ADC → 0xffffa326; called from 0xc8dc and 0x5a4c |
| 0x0000c290 | `ref_knockSensorADCFault` | knock ref ADC 0xffff9f0e vs u16 thresholds 51249/16121 at ROM 0x6c17e/0x6c17c → fault status |
| 0x0000c3ce | `knock_voltage_sample` | knock ADC sample/filter (200–2000 RPM window), 10k flag; called from 0x661e (task[6]) |
| 0x0000c486 | `knock_magnitude_integrate` | magnitude, per-rotor integration, knock detected |
| 0x0000c7ba | `ref_setupCoilOutputs` | coil pulse timing from thresholds 0xffffa37e/a37c |
| 0x0000c8dc | `knock_sensor_sci_command` | per-rotor threshold command over SCI0 |
| 0x0000c1f8 | `ref_knockRelatedInit` | defaults: thresholds 94/193, level 3.6875 |
| 0x0000c14c | `ref_knockFunctionInit` | knock subsystem init (called from 0x61a8) |
| 0x000197be | (speed/load calc) | calls 0x336c4 |
| 0x000336c4 | `knock_threshold_setup` | 3D level → 0xffffa328; raw thresholds → 0xffffa37e/a37c; stability |
| 0x00033632 | `knock_filter_constants_init` | calm filter constants |
| 0x00033970 | `knock_attack_condition` | sets 0xffffc05c |
| 0x000335e4 | `knock_condition_snapshots_init` | state reset + snapshots |
| 0x000339ea | `knock_state_reset_rpm_window` | 6500/7000 RPM hysteresis → 0xc116 (from 0x19cf4) |
| 0x0000c116 | `reset_knock_state_on_mode_change` | knock state reset (misnomer corrected) |
| 0x00013826 | `knock_enable_gate` | sets 0xffffa73d |
| 0x0001388a | `knock_sensor_health_gate` | sets 0xffffa73e |
| 0x000138b2 | `knock_active_gate` | sets 0xffffa73c |
| 0x00013a60 | `knock_retard_attack` | retard target; −1.0°/cycle attack |
| 0x00013b40 | `knock_retard_slow_recovery` | +0.35° per 62 counts |
| 0x00013bd2 | `knock_retard_clamp` | clamp [min,max](RPM); returns value (bug fixed) |
| 0x000139c4 | `knock_retard_learn_to_eeprom` | persistent learned retard |
| 0x0001391c | `ref_calcKnockRAMUpdate_` | knock-seen counter 0xffffa748 |
| 0x000145c8 | `candidate_timing_retard_fast_task` | 0x1391c + 0x13b40 + throttle/rev-limit/AC retards |
| 0x000125bc | `knock_retard_apply_leading` | writes 0xffffa648 |
| 0x000125f6 | `knock_retard_apply_trailing` | writes 0xffffa658 |
| 0x000123ba | `leading_timing_add_corrections` | 0xffffa634 = base + corrections |
| 0x000123ca | `trailing_timing_add_corrections` | 0xffffa63c |
| 0x00012300 | (timing clamp) | clamps into 0xffffa630/a638 |
| 0x00011f00 | `leading_base_timing_calc` | base-timing plate, blend b118 |
| 0x0001206c | `trailing_base_timing_calc` | base-timing plate |
| 0x00013034 | `knock_rough_correction_targets` | rough-knock targets (descriptors 0x69630–0x6974c) |
| 0x00013210 | `ref_roughKnockCorrection` | leading/trailing rough corrections 0xffffa6ac/a6b0 (inherited name; semantic unproven) |
| 0x0001467c | `candidate_knock_rough_correction_update` | rough-correction task chain |
| 0x000142a4 | `ignition_timing_main_task` | task[6] timing chain |
| 0x00049fac | `knock_sensor_health_persistence` | health persistence → 0xffffcd64/cd66 |
| 0x0004a084 | `knock_sensor_dtc_report` | DTC 0x23/0x24 via 0x5fd38 |
| 0x000390b8 | `candidate_knock_sensor_monitor_task` | 0x49fac + 0x4a084 |
| 0x000064ba | `candidate_knock_sensor_fault_task` | task[9]: 0xc290 |
| 0x0001f0c4 | `open_loop_request_condition` | sets 0xffffb12a |
| 0x0001ee30 | `set_open_loop_flag` | sets 0xffffb12c (misnomer corrected) |
| 0x0001c13c | `closed_loop_enable_condition` | 0xffffae1e / 0xffffae1f |
| 0x0001ee4a | `open_loop_fueling_targets` | 0xffffb120 |
| 0x0005535e | `diag_ol_status_byte` | OBD PID 0x0003 status byte |
| 0x000553d8 | `diag_ol_status_low_byte` | PID 0x0003 low byte (0) |
| 0x00022144 | `candidate_evap_open_loop_condition` | evap gated on open loop |
| 0x0003d010 | `candidate_o2_monitor_integrator` | O2/catalyst monitor integrator |

### 8.2 Data and entry points (ROM)

| Address | Contents |
|---|---|
| 0x00004998–0x00004ab7 | task table: 18 × 16-byte records {entry, mask, param, stack}; stacks 0xffff7410–0xffff7498 |
| 0x00004ab8 | additional record {0x64e8, 0x02000000, 0x04ffffff, 0x00000001} + 0xffff76xx pairs; dispatch unresolved |
| 0x00005f10c | `tbl_diag22_dispatch_records_0005f10c` (99 × 12 bytes, all labeled 2026-10-31); PID 0x1746 → handler 0x5707a `diag22_pid1746_knock_retard_deg`, PID 0x0003 → handler 0x568ca `diag22_pid0003_fuel_system_status_ol_cl` — [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md) |
| 0x0006c046 | calibration ID `N3ZHE` |
| 0x0000d74c / 0x0000d750 | scheduler pointer table / timing records (used by 0x5f1c) |
| 0x00009630 | `ref_osTaskScheduler` (scheduler; RAM control blocks 0xffff9304) |

Task-table entries: 0x65f6 `ref_task1_` (knock sensing), 0x661e `ref_task2_`
(engine control; also calls 0xc3ce knock_voltage_sample), 0x64ba `candidate_knock_sensor_fault_task`, 0x64f6 (→ 0x390b8
+ `ref_OLFueling__` 0x211fe), 0x6584 (→ `ref_getFuelingSlowtask_` 0x21246),
0x65b2 (→ 0x1467c), 0x65cc (→ 0x41964, reads 0xffffae1f). Wrapper 0x64e8 →
0x11534 → 0x145c8.

### 8.3 RAM (0xffff…)

Core knock state:

| Address | Name | Meaning |
|---|---|---|
| 0xffffa734 | `knock_retard` | current retard; negative deg, [−10, 0] |
| 0xffffa738 | `knock_retard_mirror` | copy for the trailing apply path |
| 0xffffa73c | `knock_active` | = enable && sensors healthy |
| 0xffffa73d | `knock_enable` | engine-conditions gate |
| 0xffffa73e | `knock_sensors_healthy` | = 0xffffcd64 && 0xffffcd66 |
| 0xffffa73f | `knock_seen_learn_trigger` | learn-to-EEPROM trigger |
| 0xffffa744 | `knock_recovery_target` | attack/recovery target |
| 0xffffa748 | `knock_seen_counter` | u16 knock-seen counter |
| 0xffffa74a / 0xffffa74b | `knock_recovery_counter_a/b` | recovery pacing counters (u8) |
| 0xffffa74c | `knock_active_previous` | activation-edge detection |
| 0xffffa324 | `knock_detected` | knock detected this cycle |
| 0xffffc078 | `knock_detected_latched` | latched detection |
| 0xffffc05c | `knock_attack_condition` | attack allowed |
| 0xffffc05d | `knock_transient_flag` | stability (0 = stable) |
| 0xffffc060 / 0xffffc064 / 0xffffc068 | `knock_filter_coeff_a/b/c` | filter constants |
| 0xffffa328 | `knock_level_threshold` | 3D level threshold |
| 0xffffa37e / 0xffffa37c | `knock_ignition_threshold_a/b` | thresholds A/B (defaults 94/193) |
| 0xffffc090 / 0xffffc092 | `knock_threshold_a/b_raw` | raw table values |
| 0xffffc0ac | `knock_transient_hold_counter` | 20-cycle hold (u16) |
| 0xffffa378 / 0xffffa326 | `knock_voltage_sample` / `knock_voltage_reference` | filtered sample / reference ADC |
| 0xffffa37a / 0xffffa374 | `knock_adc_raw` / `knock_adc_filtered` | raw / filtered knock ADC |
| 0xffffa370 / 0xffffa330 / 0xffffa32c | `knock_voltage` / `knock_magnitude` / `knock_noise_filtered` | |
| 0xffffa344 / 0xffffa348 / 0xffffa34c | `knock_integrator_step` / `knock_baseline_slow` / `knock_level_combined` | |
| 0xffffa334[2] / 0xffffa33c[2] / 0xffffa350[2] | `knock_level_running` / `knock_level_integrator` / `knock_noise_threshold` | per rotor |
| 0xffffa358 / 0xffffa360 | `knock_noise_floor` / `knock_noise_excess` | |
| 0xffffa364 / 0xffffa368[2] | `knock_threshold_command_base` / `knock_threshold_command` | |
| 0xffffa387[2] / 0xffffa389[2] | `knock_reference_voltage` / `knock_reference_voltage_latched` | per-channel ROM refs |
| 0xffffa381[2] / 0xffffa380 | `knock_command_code` / `knock_command_code_current` | |
| 0xffffa384 / 0xffffa386 / 0xffffa38c | `knock_rotor_index` / `high_rpm_10k_flag` / `knock_state_mode` | |
| 0xffffa325 | `knock_sensor_fault_status` | 0 OK, 1/2 per-channel fault |
| 0xffffcd64 / 0xffffcd66 / 0xffffcd65 / 0xffffcd67 | `knock_sensor_healthy_a/b` / `knock_sensor_fault_a/b` | |
| 0xffffcd68 / 0xffffcd6a / 0xffffcd6c | `knock_sensor_healthy/fault counters` | u16 |
| 0xffff8038 | (EEPROM address holder) | EEPROM address of the learned retard, used by 0x139c4 |

Sensing, timing and shared state:

| Address | Name | Meaning |
|---|---|---|
| 0xffff9f80 / 0xffff9f88 / 0xffff9ef8 / 0xffff9f0e | `engine_speed_rpm_raw` / `crank_period_accumulator` / `knock_sensor_adc_raw` / knock ref ADC (fault check) | |
| 0xffffb548 | `engine_speed_rpm` | filtered RPM used by the tables |
| 0xffffa424 / 0xffffa428 / 0xffffa426 / 0xffffa42c | `engine_running_timer` / `engine_running` / `engine_on_time_counter` / `engine_injectors_off` | |
| 0xffffa630 / 0xffffa638 | `leading/trailing_ignition_timing` | final outputs |
| 0xffffa634 / 0xffffa63c | `leading/trailing_timing_with_corrections` | |
| 0xffffa648 / 0xffffa658 | `leading/trailing_timing_correction_total` | |
| 0xffffa6ac / 0xffffa6b0 | `rough_knock_correction_leading/trailing` | |
| 0xffffa750 / 0xffffa754 | `coolant_timing_derate_leading/trailing` | |
| 0xffffb288 / 0xffffb28c | `ac_compressor_leading/trailing_timing_retard` | −5.0° while ramping |
| 0xffffc9a0 / 0xffffc9a4 | `cold_start_timing_reduction_leading/trailing` | |
| 0xffffaddc / 0xffffc150 | `intake_air_temperature` (working copy) / `engine_load_delta` | |
| 0xffffa98c | `inferred_coolant_temperature` | coolant temperature (inferred_ label; gates at 0x13826/0x1c13c) |
| 0xffffc0b4 | `engine_load` | load input to the 3D knock-level tables (0x336c4) |
| 0xffffa5e0 / 0xffffa5e4 | (unnamed `DAT_`) | idle/base terms read by 0x125bc/0x125f6; writer not identified |
| 0xffffa5e8 / 0xffffa5ec | (unnamed `DAT_`) | base timing blended by loop weight b118 (0x11f00/0x1206c) |
| 0xffffa5fc | (unnamed `DAT_`) | unweighted base timing sum (0x11f00) |
| 0xffffa640 / 0xffffa644 | (unnamed `DAT_`) | base timing after trim blend a644 (0x123da) |
| 0xffffa66c / 0xffffa670 | (unnamed `DAT_`) | leading/trailing timing trims, subtracted in 0x125bc/0x125f6 |

Loop mode:

| Address | Name | Meaning |
|---|---|---|
| 0xffffb12a / 0xffffb12c | `open_loop_request` / `open_loop_active` | open-loop flag (polarity corrected) |
| 0xffffae1e / 0xffffae1f | `closed_loop_allowed` / `closed_loop_active` | |
| 0xffffb120 | `open_loop_fuel_target` | |
| 0xffffb12d / 0xffffcd60 | `safe_mode` (fueling/base-timing cap) / `safe_mode` (knock threshold pair) | |
| 0xffffaa80 | `lambda_in_target_band` | |

Full list of all 84 named locations: `source_review/accepted_ram_aliases.tsv`.

### 8.4 ROM tables and constants

| Address | Name | Contents |
|---|---|---|
| 0x0006af54 | `tbl_knock_enable_load_floor_0006af54` | 12 cells, 0.5 flat; axis 0x795e8 (RPM 800–9600) |
| 0x0006af68 | `tbl_knock_retard_clamp_min_0006af68` | u8 cells × mult + offset(−64): −10…0°; axis 0x79624 (RPM 2000–5000) |
| 0x0006af7c | `tbl_knock_retard_clamp_min_alt_0006af7c` | alt min: −10/−7.5/−5×4/0; axis 0x79648 |
| 0x0006af90 | `tbl_knock_retard_clamp_max_0006af90` | 0.0° ×15; axis 0x7966c (RPM 800–6400) |
| 0x0006afa4 | `tbl_knock_recovery_target_0006afa4` | fail-safe target −10…0°; axis 0x796b8 (RPM 500–5500) |
| 0x0006afb8 | `tbl_knock_learned_retard_scale_0006afb8` | 0.0 ×13; axis 0x79704 = learned retard −8.4…+8.4° |
| 0x0006b250 | (voltage → magnitude) | knock voltage → magnitude scale |
| 0x0006b264 | `tbl_knock_transient_hold_0006b264` | raw u8 0x0a → <<1 = 20-cycle hold |
| 0x0006b270 / 0x0006b27c | threshold A raw u16 vs RPM (normal / alt) | → 0xffffc090 → 0xffffa37e |
| 0x0006b288 / 0x0006b294 | threshold B raw u16 vs RPM (normal / alt) | → 0xffffc092 → 0xffffa37c |
| 0x0006b2a0 | (noise threshold min) | clamp floor for 0xffffa350[2] |
| 0x0006b2ac | (noise floor) | lookup vs raw RPM → 0xffffa358 |
| 0x0006b2b8 / 0x6b2d4 / 0x6b2f0 / 0x6b304 | `tbl_knock_level_3d_a..d` | 3D knock level vs load/RPM (20×12 scaled / 1×1 raw) |
| 0x0006990c | `tbl_closed_loop_warmup_time_0006990c` | raw u16 ×15; axis 0x6f7e0, data 0x6f81c |
| 0x00069d24–0x00069d74 | "Closed Loop Fuelling Threshold" tables | open-loop request conditions (0x1f0c4) |
| 0x00069cac–0x00069f44 | open-loop fueling tables (normal + "Safe Mode") | 0x1ee4a |
| 0x00069630–0x0006974c | RX8Defs "Ignition 4..17" descriptors | rough-knock targets (0x13034) |
| 0x00006b83c | (cold-start reduction) | min(c9a8, lookup(RPM)) (0x12630) |
| 0x00007a750 / 0x00007a752 | per-channel reference bytes | selected by the 10k flag; both `01 01` in this ROM |
| 0x00007a234–0x00007a248 | filter constants c060/c064/c068: transient 0.1875/0.1253/0.09375 @0x7a234/38/3c, calm 0.0625/0.1253/0.03125 @0x7a240/44/48 | 0x33632 (calm literals), 0x336c4 (switch on c05d; c068 from ROM) |
| 0x0006c17c / 0x0006c17e | knock reference ADC fault thresholds (u16 values 16121 / 51249) | 0xc290 |

### 8.5 How to validate

- **ROM integrity and instruction bytes**: `python3 scripts/validate_export.py`
  (SHA-256 `a7cd953c…f264f1`, 168,592 instructions byte-checked against the ROM).
- **Any function**: `decompiled/functions/<address>_*.c`; name/index lookup in
  `decompiled/function_index.tsv`; disassembly in
  `decompiled/firmware_disassembly.asm` (format `00013bd2  2fe6  mov.l r14,@-r15`).
- **The 0x13bd2 fix**: disassembly 0x13bd2–0x13c26 — `jsr @r3` (rx8_clamp_float)
  at 0x13c18 with delay slot `fmov.s @r15,fr4` (restores fr4 = param), `rts` at
  0x13c24 returning fr0.
- **Alias evidence**: `source_review/accepted_function_aliases.tsv` (39 rows),
  `source_review/accepted_ram_aliases.tsv` (84 rows),
  `source_review/accepted_lookup_aliases.tsv` (15 rows); the same notes appear
  as `[ADDITIONAL SOURCE REVIEW]` blocks in the per-function files.
- **Rename map**: `metadata/integrated_names.json` (672 entries); pass record:
  `metadata/knock_loop_labels.json`.
- **Task table bytes**: ROM 0x4998–0x4ab7; extra record at 0x4ab8; diagnostic
  dispatch table at 0x5f10c.
- **Knock sensor wiring**: pins 1F/1T/1G (`hardware/pcm_connections.tsv`);
  cross-ECU descriptor/logger matches in `cross_ecu/`.

## 9. Limits

Static analysis only: no hardware/emulator execution, so scheduling order,
interrupt load and real knock behavior are unmeasured. `candidate_` names are
unproven hypotheses. Unresolved: the blend weights b11c/b118, the variant/mode
selectors (b534, bc3d, a415, cd5c, …), the task-record dispatch at ROM 0x4ab8
(entry 0x64e8), the exact semantics of the two "safe mode" flags
(b12d/cd60), and the idle/base terms 0xffffa5e0/a5e4/a5dc (read by
0x125bc/0x125f6/0x306e8 with no identified writer in the export). The saved Ghidra database predates these annotations; the
canonical C carries the newest names. The ROM was not modified.

---

## 10. Update — 2026-10-30 (later passes, this file left as the 2026-10-29 record)

2026-10-31 addendum: 0x803e was renamed `crank_isr_compute_rpm` (emulator-verified CMI10B
handler, IVT 0x2c8 at VBR 0x7fc50) in the 2026-10-31 OS/CAN/IVT labeling pass
([`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md)); the memory-map row above carries the new name.

Subsequent passes built on this review: the **fueling chain** is now labeled
([`fueling_control_report.md`](fueling_control_report.md), `reviews/fueling/`) and resolves this report's open
item on blend weights b11c/b118 (producer `blend_weight_update` 0x200c6); the
**intake solenoids** are mapped to GPIO/package pins ([`intake_solenoids_report.md`](intake_solenoids_report.md),
`reviews/intake_solenoids/`); the **injector channels** are mapped to ATU-II
8A-8F → TO8A-F → SH7055F pins 195/197-201 with rotor blocks {0,1,2}/{3,4,5}
([`reviews/fueling/injector_pin_mapping.md`](reviews/fueling/injector_pin_mapping.md)); the supplied FSM pinout
(`mazda-rx-8-pcm-pinout-series-1.pdf` v3) confirmed terminal functions and wire
colours (still no chip-pin data — that hop stays board-level unresolved). All
labels were re-verified against the raw ROM (`reviews/*/README.md` binary-level
sections), and `scripts/validate_reports.py` now validates every root report's
address tables. Patchers for VDI/SSV RPM windows and limiter behavior live in
`Mazda_RX8_PCM_ReverseEngineering/Utilities/` (stock ROMs untouched; see
[`reviews/limiter/README.md`](reviews/limiter/README.md)). This knock report itself is unchanged and still
accurate for its date.

---

## 11. Update — 2026-11-02 (rpm-path attribution corrected)

The "ISR 0x803e" references in §2 and the memory map above were re-checked: 0x803e has no
callers in the callgraph or as a ROM pointer — it is a dead duplicate of the rpm math. The
live path is the CMI10B tick chain 0x5b3c → 0x75f4 → 0x77f0 → 0x7c68 → `ref_getCrankAngle`
0x7fcc, which writes `crank_period_accumulator_ffff9f88` and
`engine_speed_rpm_raw_ffff9f80` = 1.2e8 / Σ ring(0xffff9fd0[6]). Details and emulator
evidence: [os_scheduling_deep_dive_report.md](os_scheduling_deep_dive_report.md) §7/§9.
