# Targeted static review: knock control strategy and loop-mode interaction

Scope: the knock sensing, knock control and closed/open-loop decision chain of
60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E), read from the canonical export
(`decompiled/`), the disassembly and the untouched ROM. This pass labels the
chain in the export (39 functions, 84 RAM locations, 15 lookup tables), fixes
one export bug, and corrects three earlier misreadings. No firmware changes
were made; the ROM is untouched (SHA-256 verified by `scripts/validate_export.py`).

Revised 2026-10-29 after an independent sceptical re-check against the ROM
bytes and both def sets: constant values, the cd60 polarity wording, the
threshold-command formula, the noise-filter coefficient, the 0x1746 PID
range, the fault-threshold "addresses", the signal-chain task attribution and
the call-chain diagram were corrected; see [`REVIEW_NOTES.md`](REVIEW_NOTES.md) in this folder.

Result: the knock control strategy is now traced end to end and labeled.
**Knock control applies in open loop as well as closed loop** — the knock chain
never reads the loop-mode flags; its gates are engine conditions only (run time,
coolant, load, RPM, sensor health). What loop mode changes is the *fueling*
around the knock correction, not the correction itself.

## 1. Signal chain

```
task[5] 0x65f6 ref_task1_ (knock sensing task)
  -> ref_functionDrivingTiming 0xc338
       -> 0xc486 knock_magnitude_integrate   (magnitude, per-rotor integration)
       -> 0xc8dc knock_sensor_sci_command   (ATU window SCI front-end)
            -> 0xc276 knock_reference_adc_read   (reference-channel ADC; also called from 0x5a4c)
  -> 0xc7ba ref_setupCoilOutputs            (coil pulse timing, thresholds)
ISR 0x803e ref_INT_ATU101_IMI10AG            (crank period -> raw RPM 0xffff9f80)

task[6] 0x661e ref_task2_ (engine control task)
  -> 0xc3ce knock_voltage_sample            (knock ADC sample + filter, before ref_engineControlTASK)
  -> ref_engineControlTASK 0x11ba4
       -> 0x197be (speed/load) -> 0x336c4 knock_threshold_setup
                               -> 0x33970 knock_attack_condition
       -> 0x142a4 ignition_timing_main_task
            -> 0x13826/0x1388a/0x138b2  enable / health / active gates
            -> 0x13a60 knock_retard_attack (calls 0x13bd2 knock_retard_clamp)
            -> 0x139c4 knock_retard_learn_to_eeprom (0xffffa73f trigger; calls 0x13bd2)
       -> 0x125bc/0x125f6 knock_retard_apply_leading/trailing
       -> 0x123ba/0x123ca leading/trailing_timing_add_corrections
       -> 0x11f00/0x1206c leading/trailing_base_timing_calc
       -> 0x12300 clamp -> leading/trailing_ignition_timing 0xffffa630/a638

task[9]  0x64ba candidate_knock_sensor_fault_task -> 0xc290 ref_knockSensorADCFault
task[10] 0x64f6 -> 0x11744 -> 0x390b8 candidate_knock_sensor_monitor_task
       -> 0x49fac knock_sensor_health_persistence, 0x4a084 knock_sensor_dtc_report
task[13] 0x65b2 -> 0x118d0 -> 0x1467c candidate_knock_rough_correction_update
       -> 0x12ed0, 0x13034 knock_rough_correction_targets,
          0x13210 ref_roughKnockCorrection, 0x43870
task[11] 0x6584 -> 0x117ac -> 0x21246 ref_getFuelingSlowtask_
       -> 0x1f0c4 open_loop_request_condition, 0x1ee30 set_open_loop_flag,
          0x1ee4a open_loop_fueling_targets
record 0x64e8 (ROM 0x4ab8, dispatch unresolved) -> 0x11534 -> 0x145c8
candidate_timing_retard_fast_task
       -> 0x1391c knock-seen counter + 0x13b40 knock_retard_slow_recovery (the ONLY
          caller of 0x13b40; 0x13b40 calls 0x13bd2 knock_retard_clamp — fixed: returns
          the clamped value) + throttle/rev-limit/AC retards
```

### 1.1 Front end (per rotor, per ATU window)

- ISR 0x803e accumulates crank periods (`crank_period_accumulator_ffff9f88` =
  sum of `DAT_ffff9fd0[]`) and stores raw RPM `engine_speed_rpm_raw_ffff9f80`
  = 120e6 / sum.
- 0xc3ce `knock_voltage_sample` (called from task[6] 0x661e, before
  `ref_engineControlTASK` — not from the 0x65f6 chain): reads the knock ADC
  (`knock_sensor_adc_raw` 0xffff9ef8 -> `knock_adc_raw_ffffa37a`), first-order filters it into
  `knock_adc_filtered_ffffa374` (coeff 0.004, snap 1.0) **only in the
  200-2000 RPM window**, stores the u16 sample `knock_voltage_sample_ffffa378`,
  and sets `high_rpm_10k_flag_ffffa386` = (raw RPM >= 10000).
- 0xc276 `knock_reference_adc_read` (called from 0xc8dc in the 0x65f6 chain
  and from 0x5a4c): `knock_voltage_reference_ffffa326` =
  `ref_readADCResult()` (knock reference channel).
- 0xc8dc `knock_sensor_sci_command`: on the ATU window interrupt, alternates
  the rotor index (`knock_rotor_index_ffffa384` = 0/1, init 0xff), picks the
  per-channel reference bytes from ROM 0x7a750 (below 10k) or 0x7a752 (at/above;
  both contain `01 01` in this ROM — see `reviews/reset_at_10000_rpm.md`),
  maps the per-rotor threshold command `knock_threshold_command_ffffa368[i]`
  to a command code (`knock_command_code_ffffa381[i]` / `..._a380`: 6 if <64,
  5 if <96, 4 if <128, 2 if <192, 0 if >=192) and sends it over SCI0
  (`update_serial_command_bits_3_to_5_and_send` or
  `sci0_configure_sync_and_exchange_command`). This is the external knock
  amplifier/filter (pins 1F/1T/1G, `hardware/pcm_connections.tsv`): the PCM
  commands a per-rotor threshold and the device reports the filtered level.

### 1.2 Magnitude and integration — 0xc486 `knock_magnitude_integrate`

- Knock voltage `knock_voltage_ffffa370` = (a378 - a326) * 5/65536 V.
- Magnitude `knock_magnitude_ffffa330` = lookup(tbl 0x6b250, voltage) minus
  the command-code term `knock_command_code_ffffa381[a384] << 5`, clamped >= 0.
- Noise term `knock_noise_filtered_ffffa32c` = filter(a330 - a348, literal
  0.0625) — the code hardcodes 0.0625, not c060 (equals calm c060, ignores the
  transient 0.1875);
  a change of the latched reference (`knock_reference_voltage_latched_ffffa389`)
  forces a32c = 40 (noise reset).
- Integrator step `knock_integrator_step_ffffa344` =
  min(|a32c|, c060 * |a330 - a334[a384]|), floor 1.0; per-rotor integrators
  `knock_level_integrator_ffffa33c[i]` +/-= a344 and noise thresholds
  `knock_noise_threshold_ffffa350[i]` +/-= a344 * `knock_filter_coeff_b_ffffc064`
  (x2 on decay), clamped to [tbl 0x6b2a0 min, a358+8 max].
- `knock_noise_floor_ffffa358` = lookup(raw RPM, tbl 0x6b2ac);
  `knock_noise_excess_ffffa360` = a350 - 2x excess above the floor (>= 0).
- Baseline `knock_baseline_slow_ffffa348` = filter(a330, c068);
  `knock_level_combined_ffffa34c` = a33c[a384] + a348 (>= 0) -> a334[a384].
- Threshold command base `knock_threshold_command_base_ffffa364` =
  a34c + a328 * a360 clamped 64..255 (a34c = combined knock level addend; 64 is
  the clamp floor); per-rotor command
  `knock_threshold_command_ffffa368[i]` = a364 + a360*2.
- **Knock detected**: `knock_detected_ffffa324` = (a364 <= a330).

### 1.3 Threshold setup and attack condition

- 0x336c4 `knock_threshold_setup` (called from 0x197be): loads the 3D
  load/RPM knock-level tables (`tbl_knock_level_3d_a..d_0006b2b8/b2d4/b2f0/b304`)
  into `knock_level_threshold_ffffa328` = a328; selects raw u16 thresholds A/B
  from tbl 0x6b270/0x6b27c and 0x6b288/0x6b294 (`knock_threshold_a_raw_ffffc090`
  / `knock_threshold_b_raw_ffffc092`, alt tables when `safe_mode_ffffcd60` is set (!= 0))
  and moves them to `knock_ignition_threshold_a/b_ffffa37e/a37c` (defaults 94 /
  193, set by 0xc1f8 `ref_knockRelatedInit`). Stability check (RPM/load/throttle
  deltas vs snapshots, per-rotor derates) drives `knock_transient_flag_ffffc05d`
  and the hold counter `knock_transient_hold_counter_ffffc0ac`
  (tbl 0x6b264: raw u8 0x0a << 1 = 20 cycles); calm constants c060=0.0625,
  c064=0.1253, c068=0.03125 (ROM 0x7a240/0x7a244/0x7a248); transient c060=0.1875
  (ROM 0x7a234), c064=0.1253 (unchanged), c068=0.09375 (ROM 0x7a23c) —
  0x336c4 switches c060 and c068 on c05d.
  Latches `knock_detected_latched_ffffc078` = a324.
- 0x33970 `knock_attack_condition`: sets `knock_attack_condition_ffffc05c` =
  knock latched (c078) && engine running (a428) && run timer (a424) >= 0xfa &&
  leading **and** trailing timing both > 5 deg - thresholdA * 0.15625, where
  thresholdA = raw u16 `knock_threshold_a_raw_ffffc090` decoded x0.15625 (the
  same raw value is copied to a37e via 0x336c4 -> 0xc0f0)
  (i.e. timing not already deeply retarded — the attack is suppressed when the
  engine is already pulled back).
- 0x33632 `knock_filter_constants_init` and 0x335e4
  `knock_condition_snapshots_init` (from `ref_mainInit__` 0x61a8 via 0xc14c
  `ref_knockFunctionInit`) install the calm constants and snapshots.

### 1.4 Enable gating — engine conditions only

- 0x13826 `knock_enable_gate`: `knock_enable_ffffa73d` = run timer >= 0x177
  (3 s), coolant >= 10 C, load >= 0.5 (`tbl_knock_enable_load_floor_0006af54`,
  12 cells all 0.5 vs RPM 800-9600), RPM < 5000.
- 0x1388a `knock_sensor_health_gate`: `knock_sensors_healthy_ffffa73e` =
  `knock_sensor_healthy_a_ffffcd64` && `..._b_ffffcd66` (set by 0x49fac after
  >30 healthy counts; see 1.7).
- 0x138b2 `knock_active_gate`: `knock_active_ffffa73c` = a73d && a73e.

### 1.5 Retard state machine (signs corrected)

`knock_retard_ffffa734` is a **negative** retard angle in degrees, clamped to
[min, 0]: min = `tbl_knock_retard_clamp_min_0006af68` (u8 cells 0x6c -> -10 deg
... 0x80 -> 0 vs RPM 2000-5000; alternative `tbl_knock_retard_clamp_min_alt_0006af7c`
= -10/-7.5/-5/-5/-5/-5/0 selected when `DAT_ffffb534`==1 && 4<`DAT_ffffbc3d`),
max = `tbl_knock_retard_clamp_max_0006af90` (all 0.0 vs RPM 800-6400).
So the retard lives in [-10, 0] deg and 0 means "no knock retard".

- 0x13a60 `knock_retard_attack` computes the target
  (`knock_recovery_target_ffffa744`):
  - knock disabled (a73d==0) -> **0**;
  - sensors unhealthy (a73e==0) -> `tbl_knock_recovery_target_0006afa4`(RPM)
    (-10 x9, -8, -6, -4, -2, 0, 0 vs RPM 500-5500) — fail-safe retard;
  - activation edge (a74c==0 && a73c==1) -> `tbl_knock_learned_retard_scale_0006afb8`
    over the learned EEPROM retard axis (-8.4..+8.4 deg; all 0.0 in this ROM);
  - active && attack condition (c05c==1) -> previous retard **- 1.0 deg/cycle**
    (fast attack, more negative);
  - otherwise the target stays at the previous value.
  The result is clamped by 0x13bd2 and written to a734, with the mirror
  `knock_retard_mirror_ffffa738` for the trailing apply path.
- 0x13b40 `knock_retard_slow_recovery`: active && !c05c -> previous **+ 0.35 deg
  per 62 counts** (two u8 saturating counters `knock_recovery_counter_a/b_ffffa74a/a74b`
  selected by c05d), then clamped via 0x13bd2. (An earlier session had attack and
  recovery swapped; the disassembly and the clamp range settle the signs.)
- 0x13bd2 `knock_retard_clamp`: clamp(param, min(RPM), max(RPM)) — **export bug
  fixed in this pass** (see 4.3).
- 0x139c4 `knock_retard_learn_to_eeprom`: when `knock_seen_learn_trigger_ffffa73f`
  is set, filters a734 toward the EEPROM value 0xffff8038
  (`rx8_first_order_filter(a734, eeprom, 0.0039, 1e-05)`), clamps via 0x13bd2 and
  writes it back with `ref_updateMemoryAtAddress_float` — persistent learned
  knock retard.
- 0x1391c (`ref_calcKnockRAMUpdate_`) increments `knock_seen_counter_ffffa748`
  on knock-seen events (called from 0x145c8 `candidate_timing_retard_fast_task`,
  which also runs 0x13b40 and the throttle/rev-limit/AC retards).
- 0x339ea `knock_state_reset_rpm_window` (called from 0x19cf4): 6500/7000 RPM
  hysteresis -> 0xc116 `reset_knock_state_on_mode_change`(1) at/above 7000,
  (0) below 6500 — a full knock-state reset at high RPM.

### 1.6 Correction and apply path

- 0x13210 `ref_roughKnockCorrection` (inherited name; the knock semantic is a
  hypothesis — the RX8Defs tables are category "Ignition"): leading/trailing
  rough knock corrections `rough_knock_correction_leading/trailing_ffffa6ac/a6b0`
  (not per-rotor) move toward targets `a6bc/a6c0` from 0x13034
  `knock_rough_correction_targets` (RX8Defs "Ignition 4..17" descriptors
  0x69630-0x6974c; nearly all 0 in this ROM); zeroed when the engine
  is not running. Updated in 0x1467c `candidate_knock_rough_correction_update`.
- 0x13ecc `ref_getCoolantBasedTimingDerate__` (inherited): leading/trailing
  coolant timing derates `coolant_timing_derate_leading/trailing_ffffa750/a754`.
- 0x12630/0x12754: cold-start timing reduction
  `cold_start_timing_reduction_leading/trailing_ffffc9a0/c9a4` =
  min(c9a8, tbl 0x6b83c(RPM)) * clamp((ECT+30)*0.01, 0, 1) when ca44==1 && ca3f>1.
- 0x214f8/0x215f8 (inherited): A/C compressor timing retard
  `ac_compressor_leading/trailing_timing_retard_ffffb288/b28c` = -5.0 deg
  while the compressor ramps, else 0.
- 0x125bc `knock_retard_apply_leading`:
  `leading_timing_correction_total_ffffa648` =
  ((a734 - a6ac) - max(a750, c9a0)) + a5e0 + b288 - a66c
  (knock retard minus rough correction, minus the larger of coolant derate and
  cold-start reduction, plus idle/base term a5e0, plus A/C retard, minus trim
  a66c). a5e0's writer is not identified in the export (see unresolved items);
  the similar blend a5fc*b118 + base*(1-b118) is computed by 0x11f00/0x1206c
  into a5e8/a5ec and reaches a640 via 0x123da — it is not a5e0.
  0x125f6 `knock_retard_apply_trailing` mirrors it (a738/a6b0/a754/c9a4/b28c)
  into `trailing_timing_correction_total_ffffa658`.
- 0x123ba/0x123ca `leading/trailing_timing_add_corrections`:
  `leading_timing_with_corrections_ffffa634` = a640 + a648
  (trailing: `trailing_timing_with_corrections_ffffa63c` = a650 + a658).
- 0x11f00/0x1206c `leading/trailing_base_timing_calc`: RX8Defs base-timing
  plates ("Ignition Leading - Base Timing" / "Ignition Timing Trailing Base"),
  blended by the open/closed-loop weight b118; safe-mode cap via b12d.
- 0x12300 clamps both into the outputs `leading_ignition_timing_ffffa630` /
  `trailing_ignition_timing_ffffa638`.

### 1.7 Sensor health and DTCs

- 0xc290 `ref_knockSensorADCFault` (inherited): compares the knock reference
  ADC 0xffff9f0e against u16 thresholds 51249/16121 stored at ROM
  0x6c17e/0x6c17c (calibration area) ->
  `knock_sensor_fault_status_ffffa325` (0 OK, 1/2 per-channel fault).
- 0x49fac `knock_sensor_health_persistence`: a325==0 for >30 counts ->
  cd64=cd66=1 (`knock_sensor_healthy_counter_ffffcd68`); fault 1 -> cd67,
  fault 2 -> cd65, with counters cd6a/cd6c; cleared by DTC 0x23/0x24 active or
  0xffffd1c5.
- 0x4a084 `knock_sensor_dtc_report`: raises **DTC 0x23 / 0x24** via
  `FUN_0005fd38` from cd65/cd67 (cd64/cd66 reported as status 2). The codes are
  firmware-inferred: this ROM's def block contains no DTC 0023/0024 enable
  tables and no DTC description list.

### 1.8 Diagnostics

- RomRaider logger PID 0x1746 "Knock Retard" -> handler 0x5707a, encodes
  `knock_retard_ffffa734` via `rx8_encode_u8_affine_saturate(x, 0.3515625, 0)`
  = clamp(trunc(x/0.3515625 + 0.5), 0, 255) deg. That encoding spans
  [0, +89.7] deg, so with knock_retard clamped to [-10, 0] the raw value is
  always 0 — the PID reports 0.00 deg in this ROM. The logger def's desc text
  ("Tire Size") is a copy-paste error; gauge_max 500 is meaningless for the
  same reason.
- OBD PID 0x0003 "OL Status" -> handler 0x568ca packs
  `diag_ol_status_byte` (0x5535e) << 8 | `diag_ol_status_low_byte` (0x553d8, 0).

## 2. Loop-mode interaction — the open-loop answer

**Does knock control apply in open loop mode too? Yes.** The entire knock chain
(sections 1.1-1.8) was read after labeling: none of its ~40 functions reference
`open_loop_request_ffffb12a`, `open_loop_active_ffffb12c`,
`closed_loop_allowed_ffffae1e` or `closed_loop_active_ffffae1f`. The only
readers of `open_loop_active_ffffb12c` in the firmware are 0x1c13c (blocks closed
loop), 0x1ee30 (sets it), 0x1ee4a (open-loop fuel targets), 0x200c6 (blend-weight
decay) and 0x22144 (evap condition). Knock gating uses engine conditions only
(run time, coolant, load, RPM, sensor health, timing-not-already-retarded).

Loop mode therefore changes the *fueling* around the knock correction, not the
correction itself:

- 0x1f0c4 `open_loop_request_condition` sets `open_loop_request_ffffb12a` when
  load/throttle exceed the RX8Defs "Closed Loop Fuelling Threshold" tables
  (0x69d24/0x69d38/0x69d4c/0x69d60/0x69d74) with hysteresis and timers.
- 0x1ee30 `set_open_loop_flag` sets `open_loop_active_ffffb12c` = (b12a != 0).
- 0x1c13c `closed_loop_enable_condition` computes
  `closed_loop_allowed_ffffae1e` (coolant >= 35 C, engine time >=
  `tbl_closed_loop_warmup_time_0006990c` vs catalyst-temp model, **b12c==0**,
  O2 in tolerance, no DTC-ish conditions) and `closed_loop_active_ffffae1f`
  (= ae1e && cd5c==0 && lambda feedback aa80/aa81).
- 0x1ee4a `open_loop_fueling_targets` computes `open_loop_fuel_target_ffffb120`
  from open-loop tables (safe-mode variants selected by `safe_mode_ffffb12d`)
  and zeroes it in closed loop.

### Polarity correction (important)

Earlier sessions labeled 0xffffb12a/0xffffb12c as the closed-loop flag. The
evidence establishes the opposite:

1. OBD PID 0x0003 handler 0x568ca builds the standard OL/CL status byte from
   `diag_ol_status_byte` (0x5535e): 2 (CL) or 0x10 when `closed_loop_active_ffffae1f`
   ==1, 4 (OL-DTC) when `closed_loop_allowed_ffffae1e`==0, 8 when coolant >= 35 C,
   1 when cold — so ae1e/ae1f really are the closed-loop flags.
2. 0x1c13c sets ae1e=0 when (coolant < 35 C || run time < tbl 0x6990c ||
   **b12c != 0** || O2 out of tolerance || DTC-ish conditions) — b12c *blocks*
   closed loop.
3. 0x1ee4a computes the RX8Defs "Open Loop Fuelling/Target" tables when
   b12c==1.
4. 0x200c6 decays the blend weights when b12c==1.

So **b12a/b12c are the OPEN-loop flag** (1 = open loop), and the inherited name
`ref_setClosedLoopBool` (0x1ee30) is a misnomer — renamed `set_open_loop_flag`.
The conclusion of the earlier Q&A is unchanged: knock control applies in open
loop too. Only the flag polarity was wrong before.

## 3. Task scheduling map

Task table 0x4998 (18 x 16-byte records), knock-relevant entries:

| Entry | Chain | Role |
|---|---|---|
| 0x65f6 `ref_task1_` | -> 0xc338 -> 0xc486/0xc8dc/0xc7ba | knock sensing task |
| 0x661e `ref_task2_` | -> 0xc3ce + 0x11ba4 -> 0x197be/0x142a4/0x20e40 | engine control task |
| 0x64ba `candidate_knock_sensor_fault_task` | -> 0xc290 | knock sensor fault task |
| 0x64f6 | -> 0x11744 -> 0x390b8 + `ref_OLFueling__` 0x211fe | knock monitor + loop-mode fueling |
| 0x6584 | -> 0x117ac -> 0x21246 (`ref_getFuelingSlowtask_`) | fueling/emissions slow task |
| 0x65b2 | -> 0x118d0 -> 0x1467c + 0x3957c | rough correction + catalyst monitor |
| 0x65cc | -> 0x11adc -> 0x39b08 -> 0x41964 | reads `closed_loop_active_ffffae1f` |
| 0x64e8 | -> 0x11534 -> 0x145c8 | knock-attack fast task (see 5.2) |

The scheduler itself (`ref_osTaskScheduler` 0x9630 -> 0x5f1c) is a separate
event/queue system (pointer table 0xd74c, timing records 0xd750, RAM control
blocks 0xffff9304); it is not the reader of the 0x4998 task table.

## 4. Corrections made in this pass

### 4.1 Misnomer: `ref_enableDisableCruiseControl__` (0xc116)
The body only does `if (a38c != param) { a384=0xff; a385=0; a324=0; a38c=param; }`
— a knock state reset on mode change. Renamed `reset_knock_state_on_mode_change`.
Callers: 0x335e4 (init, param 0) and 0x339ea (RPM window).

### 4.2 Misnomer + polarity: `ref_setClosedLoopBool` (0x1ee30)
Sets the OPEN-loop flag b12c = (b12a != 0). Renamed `set_open_loop_flag`
(see section 2).

### 4.3 Export bug fixed: 0x13bd2 returned void
The decompilation discarded the `rx8_clamp_float` result and declared the
function `void`, while all three callers (0x139c4, 0x13a60, 0x13b40) use the
return value (`knock_retard_ffffa734 = (float)FUN_00013bd2(...)`). Disassembly
0x13bd2-0x13c26: fr4 (param) saved at 0x13be2; min lookup -> fr14 (0x13c0a);
max lookup 0x6af90 -> fr6 (0x13c12); `jsr rx8_clamp_float` (0x2404) at 0x13c18
with delay slot `fmov.s @r15,fr4` restoring fr4=param, fr5=min, fr6=max; `rts`
at 0x13c24 returns fr0 = clamp result (SH float return). Fixed to
`float knock_retard_clamp(float param_1) { ... return rx8_clamp_float(param_1,arg1,arg2); }`
in all three synchronized views (per-function file, combined C, named view).
The redundant `(float)` casts at the call sites are residual ABI artifacts.

### 4.4 Attack/recovery signs corrected
`knock_retard_ffffa734` is a negative retard in [-10, 0] deg (clamp tables).
Attack (c05c==1) = -1.0 deg/cycle; slow recovery (!c05c) = +0.35 deg per 62
counts. An earlier session had these two swapped.

## 5. Unresolved items

1. **Task record 0x64e8 at ROM 0x4ab8**: referenced immediately after the 18-record
   task table (bytes {0x64e8, 0x02000000, 0x04ffffff, 0x00000001} then
   0xffff76xx stack/param pairs). The record layout differs from the 0x4998
   entries and no ROM pointer to 0x4998 was found either; the dispatch
   mechanism for both is unresolved. 0x64e8 is a thin wrapper
   (`FUN_00011534(); ref_taskEndRoutine_();`) leading to 0x145c8
   `candidate_timing_retard_fast_task`.
2. **Blend weights b11c/b118** (0xffffb11c/b118): 0..1 weights blending the
   open-loop fuel target (0x1ee4a), the base timing (0x11f00/0x1206c) and gating
   a0d6=0x7d in 0x4c6a4. Their producer 0x200c6 has a complex condition; semantics
   not established. Deliberately left unnamed.
3. **Variant/mode selectors**: `DAT_ffffb534` (60 hits), `DAT_ffffbc3d`/`bc3c`
   (mode state 0-6 via 0x2c3b2 with counters bc4a-bc54), `DAT_ffffa415`
   (knock threshold table-pair selector), `DAT_ffffcd5c`, `DAT_ffffad24`,
   `DAT_ffffaa81`, `DAT_ffffb150`, `DAT_ffffbaed`, `DAT_ffffad48`, `DAT_ffffc9a8`,
   `DAT_ffffca44`/`ca3f`, evap internals b318/b319/b308/b32a, and the partial
   functions 0x12630/0x12754, 0x12ed0, 0x43870, 0x384de/0x3856c,
   0x14754/0x13ce0/0x13db8, 0x2c3b2.
4. **`safe_mode_ffffb12d` vs `safe_mode_ffffcd60`**: two flags both tied to
   "Safe Mode" calibrations (b12d: fueling/base-timing cap tables; cd60: knock
   threshold table pair, checked in 0x200c6). Their producer relationship is
   not established.
5. Scheduling semantics (periods, priorities) of the task-table masks remain
   unestablished (timing records at 0xd750, control blocks 0xffff9304).
6. **Idle/base terms a5e0/a5e4/a5dc**: read by 0x125bc/0x125f6 and by the fuel
   function 0x306e8, but no writer is identified anywhere in the export (no u32
   0xffffa5e0 in ROM; a u16 0xa5e0 appears only in the literal pool at 0x12696).
   The a5fc*b118 + base*(1-b118) blend lives in a5e8/a5ec, not a5e0.
7. **Def-side caveats** (documented, not "fixed" — the def repos are upstream):
   the base def "Knock Retard Max - Knock Sensor Faulted" (uint8, 5 cells,
   x0.5-64, RPM axis) does not exist in this ROM — the 15-cell table 0x6afa4 is
   a different table; DTC 0x23/0x24 have no def corroboration (see 1.7); the
   logger parameter PIDTEST3 "Knock Retard" carries desc="Tire Size"
   (copy-paste) and gauge_max=500 despite the PID's degenerate [0, +89.7] deg
   encoding (see 1.8).

## 6. Labeling applied in this pass

- 39 functions (`source_review/accepted_function_aliases.tsv`): 33 high
  confidence, 6 medium (integrated with the `candidate_` prefix:
  `candidate_timing_retard_fast_task`, `candidate_knock_sensor_monitor_task`,
  `candidate_knock_sensor_fault_task`, `candidate_knock_rough_correction_update`,
  `candidate_o2_monitor_integrator`, `candidate_evap_open_loop_condition`).
- 84 RAM locations (`source_review/accepted_ram_aliases.tsv`), integrated as
  `<alias>_<address>`; 8 `snapshot_` locals renamed to match (192 occurrences).
- 15 lookup-table rows (`source_review/accepted_lookup_aliases.tsv`, merged into
  `named/lookup_aliases.tsv`), including the chained rename of the auto-named
  descriptor 0x6990c to `tbl_closed_loop_warmup_time_0006990c`.
- Export bug fix at 0x13bd2 (section 4.3).
- Pipeline: `scripts/review_knock_loop_labels.py` (TSV appends, before
  `annotate_source_review.py`), `scripts/merge_reviewed_lookup_aliases.py`
  (after `name_lookup_variables.py`, before `integrate_reviewed_names.py`),
  `scripts/review_knock_loop_labels_apply.py` (after `refine_export_cleanup.py`,
  before `verify_readability.py`); all wired into `scripts/rebuild.sh` and
  idempotent. Record: `metadata/knock_loop_labels.json`; pre-change backup:
  `backups/pre_knock_loop_labels.zip`.

## 7. Sources

Local address-indexed C (`decompiled/`), SH disassembly
(`decompiled/firmware_disassembly.asm`), the original ROM
(`Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`,
SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1),
RX8Defs descriptors (`cross_ecu/romraider_descriptor_matches.json`), RomRaider
logger matches (`cross_ecu/romraider_logger_matches.json`: OL Status PID 0x0003
-> 0x568ca; Knock Retard PID 0x1746 -> 0x5707a), wiring
(`hardware/pcm_connections.tsv`), and the related reviews
(`reviews/reset_at_10000_rpm.md`, `source_review/`, `cross_ecu/`). Function names
inherited from the reference project remain hypotheses where marked `ref_`;
`candidate_` names are unproven. No hardware execution was performed.

---

Note 2026-11-02: the "ISR 0x803e" references above are superseded — 0x803e is only the
default (VBR=0) IVT slot 0x2c8 target (pre-VBR entry, superseded after VBR=0x7fc50 at
0xd206); the crank period → raw RPM 0xffff9f80 path runs in `ref_getCrankAngle`
0x7fcc, reached from the CMI10B tick handler 0x5b3c via 0x75f4 → 0x77f0 → 0x7c68.
See [os_scheduling_deep_dive_report.md](../../os_scheduling_deep_dive_report.md) §7.
