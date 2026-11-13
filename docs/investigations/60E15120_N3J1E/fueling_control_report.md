# Fueling control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes, plus dynamic execution of
the fuel-split function 0x30b08 and the SSV control 0x2178c in the SH-2E
emulator (no hardware execution). Full evidence: [`reviews/fueling/README.md`](reviews/fueling/README.md); sceptical re-check:
[`reviews/fueling/REVIEW_NOTES.md`](reviews/fueling/REVIEW_NOTES.md); validation: `reviews/fueling/validation.json`.

**Related reports:** [load & fuelling model](load_fueling_report.md) (engine-load input), [knock control](knock_control_report.md) (blend weights 0x200c6), [calibration extraction](labeling/calibration_extraction_report.md) (fuel tables in data/maps/), [UDS/Mode-22 dispatch](uds_mode22_dispatch_report.md) (the fueling cells exposed as PIDs 0x0006/0x0034/0x003c/0x0044/0x1410), [intake solenoids](intake_solenoids_report.md) (the split flag `secondary_injectors_active_flag` 0xffffbecd from 0x30b08 is an SSV on-term — §2.1).


## 1. Executive summary

The PCM computes a requested fuel volume from MAF-derived load and RPM, splits
it into per-injector amounts, arbitrates pulse times (with cranking decay and
battery/MRP-compensated injector latency), and drives six ATU-II injector
channels. **Loop mode selects the fuel target, not the fuel math**: in open
loop the target comes from the 'Open Loop Target' table family
(`open_loop_fuel_target_ffffb120`, computed by 0x1ee4a); in closed loop a
filtered trim (`closed_loop_trim_filtered_ffffbeb8`, 0x307e0) corrects around
`lambda_target_ffffadfc`. The blend weights `fuel_blend_weight_ffffb11c` /
`timing_blend_weight_ffffb118` (producer 0x200c6 — resolves a knock-review
open item) go 1.0 in normal conditions, decay −0.0667/call in sustained open
loop, and 0.0 on fault/safe-mode conditions.

## 1a. Plain-language summary (what the fuel math means)

- The PCM decides how much fuel to inject from **measured airflow (MAF) and
  RPM** ("load"), not from the throttle pedal. Open vs. closed loop only
  changes the *target* (open-loop table vs. lambda-sensor target + trim);
  the math that turns a fuel volume into injector pulse times is the same
  either way.
- The fuel maps in the ROM are **not the literal injector pulse width**: the
  final pulse = base map value x enrichment factors x fuel-target multiplier,
  split across the primary/secondary injectors, latency-compensated for
  battery voltage, clamped, and handed to six timer channels.
- The **primary/secondary split** (0x30b08 `primary_secondary_fuel_split`) only engages the secondary
  injectors above a coolant-dependent RPM threshold (or above 6250 rpm
  outright) **and** when total fuel demand exceeds the primary-only amount —
  and that same "secondaries active" flag (`secondary_injectors_active_flag` 0xffffbecd) also switches the
  intake SSV open (see [intake solenoids §2.1](intake_solenoids_report.md)).
- A fuel trim shown on OBD/datalogs is the closed-loop correction *around*
  the target, not a cell of the base map — expect it to differ from the map
  whenever the lambda feedback is active.

## 2. Condensed pseudocode

```python
# sensors -> load
maf_scaled   = tbl_maf_scaling_0x69788(raw_adc_ffff9eea * 5/65536)     # 0x7438
mass_air_flow= maf_scaled (latched on fault, 0x19f4e/0x19f40)           # a9ec
engine_load  = min(filter(load_raw_ffffc0b0, 0.2), load_max_ffffc0b8)   # 0x33ad2; 0.525 if injectors off

# air charge (0x314d0)
bf68 = rpm*load/38.07; bf44 = tbl_0x6ad44(bf68) * tbl_0x6ad30(batt_V)
bf4c = baro*353.0163/((IAT+273)*101.32)                                # density ratio
air_charge = min(bf44*0.6345*bf4c/(60*rpm), 2.0)                       # bf50, filtered -> bf54

# fuel request (0x306e8)
bed0 = load*0.07196; bed4 = tbl_0x6ac88(rpm)                           # load compensation
bf14 = (b0d0 - c0c8 - ae08 - b21c + max(c104,cde0)
        + min(tbl_0x6ac38(coolant), c00c + b120) + max(ae10, b124) + 1.0) * adec * bed4
fuel_volume_final = FUN_0005c024(bf14) * bed0                          # beb0

# per-injector amounts + pulse times (0x30948, 0x30b08, 0x30f5c, 0x2fea8)
# 0x30b08 primary/secondary split: becc==0 -> all fuel to primaries (bef4=0), else split by tbl_0x6ab70;
#          also computes the split flags that gate the split AND feed the SSV (0x2178c) — see §2.1
bf24 = lookup2d(coolant, tbl_0x6ac74)      # split_high_rpm_threshold: 6250 rpm flat override -> bf36 = rpm >= bf24 (hyst 188)
bf28 = lookup2d(coolant, tbl_0x6ac60)      # secondary_allowed_rpm_threshold ("Secondary Injectors Allowed
                                           #  Threshold", 3000 rpm <= 0C, 0 warm) -> bf37
bf38 = fuel_volume_final >= (throttle>=60% ? baro_corr(tbl_0x6ab84)*amount_a : amount_a)   # bf39 vs amount_a
becd = bf36 or (bf37 and bf38)            # secondary_injectors_active_flag 0xffffbecd -> SSV on-term (intake report §2.1)
becc = bf36 or (bf37 and bf39)            # secondary_split_gate_flag 0xffffbecc -> split gate + open-loop logic 0x1f0c4/0x1fd48
amounts[6] = temp_mult[3] * flow * 6e7/rpm * tbl_0x6ac4c/360 * {369.472, 475.93} - latency   # 0x30948
injector_pulse_time be24 = (cranking? be58 : be4c) + latency_primary be40   # PID 0x1410, step 8 us
cranking decay be3c = tbl_0x6bab0(coolant)

# targets
open loop:  b120 = max(b170*b190, b194)*b134            (or implausible-coolant branch blended by b11c)  # 0x1ee4a
closed loop: beb8 = filter(clamp((max(bf40, c01c+b0c4) + min(tbl_0x6ac38(ECT), b120) + 1)*adec - 1, -1, 2), 0.0625)  # 0x307e0

# output (0x8a68): pulse = (latency_ch a094[ch] + fuel_request a010[ch*0x18]) >> 4 -> ATU-II DCNT8x
# channel map (verified vs ROM 0xd7d4 + wrappers 0x59a4-0x59ea + Sh7055h.pdf):
#   ch0 -> 8A/1A -> TO8A -> pkg pin 195   } rotor block 0
#   ch1 -> 8C/1C -> TO8C -> pkg pin 198   } (queue block 0, channels {0,1,2}, ROM 0x4e2c8)
#   ch2 -> 8E/1E -> TO8E -> pkg pin 200   }
#   ch3 -> 8B/1B -> TO8B -> pkg pin 197   } rotor block 1
#   ch4 -> 8D/1D -> TO8D -> pkg pin 199   } (queue block 1, channels {3,4,5})
#   ch5 -> 8F/1F -> TO8F -> pkg pin 201   }
#   (running PFC config: PKCRL=0x5555 -> TO8A-H on port K, pins 195/197-202/204)
# PID 0x1410 pulse time = be24 = primary request be4c + latency be40 (0x2fea8)
# connector terminals 2M/2J/2G/2D/3A/3D: chip-pin->terminal hop still unresolved (board routing)
```

### 2.1 Primary/secondary split (0x30b08 `primary_secondary_fuel_split`) and the SSV link

Between `calculate_fuel_amount_per_rotation` (0x30948) and the pulse
arbitration (0x2fea8), the fuel task 0x20e40 calls 0x30b08, which decides
whether the **secondary injectors get any fuel at all**:

```python
bf24 = lookup2d(coolant, tbl_0x6ac74)   # flat 6250 rpm (u16 cells 0x186a, scale 1) — high-RPM override
bf36 = rpm >= bf24                      # 188 rpm hysteresis band (high_rpm_override_flag 0xffffbf36)
bf28 = lookup2d(coolant, tbl_0x6ac60)   # CAL "Secondary Injectors Allowed Threshold - Coolant
                                        #  Temperature Based": 3000 rpm at <= 0 C, 0 above ~20 C
bf37 = rpm >= bf28                      # hysteresis band (secondary_allowed_rpm_flag 0xffffbf37)
bf04 = fuel_amount_per_rotation_a (bec8)
if throttle >= 60: bf04 *= lookup2d(baro, tbl_0x6ab84)   # "Primary Injector Max Baro Correction"
bf38 = fuel_volume_final (beb0) >= bf04 # WOT-aware gate (split_fuel_gate_wot_flag, hyst bf08)
bf39 = fuel_volume_final (beb0) >= bec8 # plain gate (split_fuel_gate_flag, hyst bf08)
becd = bf36 or (bf37 and bf38)          # secondary_injectors_active_flag 0xffffbecd
becc = bf36 or (bf37 and bf39)          # secondary_split_gate_flag 0xffffbecc
if becc == 0:   all fuel to primaries (bef0 = beb0, bef4 = 0)
else:           ratio = clamp(lookup2d(rpm, tbl_0x6ab70), 0, 1); secondary share bef4, primary bef0
```

0x30f5c `split_pulse_time_output` then converts the two volumes to pulse times
using the injector flow ratings (primary 0x43b8bc6a = 250.0, secondary
0x43edf70a = 475.93 cc/min — the literal-pool `CAL_Secondary_Injector_Size`
scalars at 0x7818c/0x78194).

**Cross-subsystem feed:** `secondary_injectors_active_flag` (0xffffbecd) is read by the SSV solenoid control
0x2178c as an OR-term in its on-condition, so **the SSV opens whenever the
secondary injectors are active** (and stays independently controllable via the
cold/engine-stopped counter path) — full analysis and dynamic proof in
[intake solenoids §2.1](intake_solenoids_report.md), script
[`reviews/intake_solenoids/ssv_secondary_injector_link.py`](reviews/intake_solenoids/ssv_secondary_injector_link.py).
`secondary_split_gate_flag` (0xffffbecc) is additionally read by the open-loop request logic
(0x1f0c4 `open_loop_request_condition`, 0x1fd48). Dynamically verified in the
SH-2E emulator: at 0 °C coolant the split engages above 3000 rpm (bf28=3000),
at ≥ 6250 rpm it engages regardless (bf36), and with warm coolant (threshold
0) it is gated only by the fuel-demand term (beb0 ≥ amount_a); with fuel
demand below the primary-only amount, becc/becd stay 0 and all fuel goes to
the primaries.

## 3. Key calibrated tables (RX8Defs names; descriptor-matched)

Scalar constants behind the math (not tables - literal-pool float32s, now
extracted per ROM into `data/maps/<rom-id>/scalars.{json,tsv}` by
`utilities/scripts/extract_scalars.py`, see
[calibration extraction section 6a](labeling/calibration_extraction_report.md)): the base
fuel scalar `fuel_load_scale_ffffbed0` = load x **0.07196** (0x3d935fc4 @0x78170,
ptr 0x30830) multiplying into every fuel-volume request, injector flow rates
369.472/475.93 cc/min (@0x78184, @0x7818c/0x78194), blend decay 0.0667
(0x3d889a02 @0x7132c/0x71330).

`0x69788` MAF Scaling; `0x6ac88` Fuel Injection - Engine Load Compensation;
`0x6aa80/0x6aa64` Injector Latency Primary/Secondary (3D vs MRP + battery V);
`0x6a9a4/0x6a9c0/0x6a9dc` injector weighted-engine-temp multipliers;
`0x6ae28/0x6ae3c/0x6ae58/0x6ae74` Warmup Fueling family; `0x69e00` Open Loop
Changeover Enrichment; `0x69cac..0x69f44` Open Loop Target/Fuelling family
(incl. safe-mode and coolant-implausible variants); `0x69d24..0x69d74` Closed
Loop Fuelling Thresholds; `0x6bab0` Primary Fuel Injector Cranking Pulse Decay
Time; `0x6b0c0/0x6b124/0x6b160/0x6b17c` load-delta/tip-in; `0x68ef8/0x68f0c/0x68f20`
Max Injection Angle 1-3; `0x6ad30/0x6ad44` air-flow x battery-V correction;
`0x6ac38` fuel coolant compensation (**candidate name** — descriptor not
def-matched).

## 4. Labeling applied

- 39 functions, 151 RAM locations, 1 lookup table added to
  `labeling/source_review/accepted_*_aliases.tsv`; integrated into all synchronized
  views (per-function files, `decompiled/firmware_decompiled.c`,
  `named/firmware_named.c`, index/callgraph/symbols TSVs,
  `metadata/integrated_names.json`); 234 snapshot-local renames.
- Pipeline: `scripts/review_fueling_labels.py` (idempotent, wired into
  `scripts/rebuild.sh`); record `metadata/fueling_labels.json`; backup
  `backups/pre_fueling_labels.zip`.
- The primary/secondary split bodies 0x30b08/0x30f5c and their RAM cells
  (incl. `secondary_injectors_active_flag` 0xffffbecd, the SSV on-term — §2.1)
  are labeled by `scripts/review_fuel_split_labels.py` (2 functions + 21 RAM
  rows; record `metadata/fuel_split_labels.json`), applied to all views by
  `integrate_reviewed_names.py`.
- Design doc updated: [`design/README.md`](../../architecture/design/README.md) §5.8.

## 5. Corrections made in this pass

1. `injector_pulse_set_channel` (0x8a68): pulse = (latency + fuel_request) >> 4 —
   the four `shar` at 0x8a96-0x8a9e apply to the sum (see [`reviews/fueling/REVIEW_NOTES.md`](reviews/fueling/REVIEW_NOTES.md) §10).
2. Pipeline hygiene: TSV append scripts consume the header (DictReader without
   fieldnames), and `name_lookup_variables.py` is a fresh-export-only step.
3. Def caveat (documented, not fixed — upstream repo): logger PID 0x221410 is
   claimed by both "Injector Pulse Time" and "Throttle Pedal Position"; handler
   0x56f6c encodes `injector_pulse_time_ffffbe24` at step 8 µs.

## 6. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function
  files, 168,592 instructions byte-verified, 1,833 reference matches.
- `scripts/verify_readability.py` — pass (3,355 bodies consistent).
- `scripts/verify_math_units.py` — pass.
- Dynamic (SH-2E emulator harness calls to 0x30b08 / 0x2178c, no hardware):
  the 0x30b08 split flags behave as §2.1 states (rpm/coolant/fuel gates) and
  `secondary_injectors_active_flag` drives the SSV pin PE7 — log in
  [`reviews/intake_solenoids/ssv_secondary_injector_link_log.txt`](reviews/intake_solenoids/ssv_secondary_injector_link_log.txt).
- Def caveat: logger PID 0x221410 is claimed by both "Injector Pulse Time" and
  "Throttle Pedal Position" in `logger_rx8_defs.xml`; the firmware handler
  (0x56f6c, step 8.0 us from `injector_pulse_time_ffffbe24`) supports pulse
  time — upstream def repair needed, not done here.

## 7. Limits

Static analysis only. `candidate_` names (fuel-cut arbitration details,
injection-angle semantics, cold-start degenerate body, MAF fault latching,
PID 0x1410) are unproven hypotheses. Untraced adder writers into
`fuel_correction_sum` (b0d0/c0c8/ae08/b21c/c104/cde0/ae10), `DAT_ffffadec`,
`DAT_ffffc644`, injector index->pin mapping, and the 0x4ab8 task-record
dispatch remain open (see [`reviews/fueling/README.md`](reviews/fueling/README.md) §9). The ROM was not
modified.

## 8. Memory map for validation

Check any address in `decompiled/firmware_disassembly.asm` (ROM) or
`decompiled/functions/<address>_*.c` (index: `decompiled/function_index.tsv`);
alias evidence in `labeling/source_review/accepted_*_aliases.tsv` (basis
`source_review_fueling`). Full RAM list (150 entries) is in the TSV; core
entries below.

### 7.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x00021246 | `fueling_slow_task` | task[11] worker: OL/CL target selection, enrichments, fuel-cut/rev-limit |
| 0x000211fe | `fueling_condition_flags_task` | task 0x64f6 chain: band flags, blend weights, air charge, latency multipliers |
| 0x00020e40 | `fueling_main_task` | from `ref_engineControlTASK` 0x11ba4: fuel core + arbitration + CL conditions |
| 0x000200c6 | `blend_weight_update` | b11c/b118: 1.0 normal, −0.0667/call in OL, 0 on faults |
| 0x000306e8 | `calc_fuel_volume_request` | core fuel mass: beb0 = FUN_0005c024(bf14) * bed0 |
| 0x000314d0 | `calculate_air_charge` | bf50 = min(airflow·density/(60·rpm), 2.0) |
| 0x00030948 | `calculate_fuel_amount_per_rotation` | per-injector amounts bec8..bee0 |
| 0x00030b08 | `primary_secondary_fuel_split` | primary/secondary split + split flags (§2.1); `secondary_injectors_active_flag` feeds SSV 0x2178c |
| 0x00030f5c | `split_pulse_time_output` | split volumes bef0/bef4 → pulse times via flow scalars 250.0/475.93 |
| 0x0002fea8 | `injector_pulse_time_arbitrate` | be24..be38 pulse slots, cranking decay tbl 0x6bab0 |
| 0x00008a68 | `injector_pulse_set_channel` | ATU-II program: pulse = (a094[ch]+a010[ch])>>4 → DCNT8x |
| 0x00008340 | `injector_pulse_set_dispatch` | thunk → 0x8a68; wrappers 0x59a4-0x59ea |
| 0x000086f8 / 0x000086ac | `set_fuel_injector_latency` / `injector_zero_offset_set` | a094..a0a8 / a0ac..a0c0 per-channel pairs |
| 0x000085e4 | `injector_channel_disable` | per-channel off (TIER/GR/DCNT) |
| 0x0002ff78 | `injector_latency_cal_lookup` | 3D latency tbls 0x6aa80/0x6aa64 vs MRP + battery V, /0.25 |
| 0x0002fd3e | `injector_temp_multiplier_lookup` | bde4/bde8/bdec 3D temp×load tbls 0x6a9a4/0x6a9c0/0x6a9dc |
| 0x00032e08 | `warmup_fueling_compensation` | c00c = c014+c018 warmup enrichment |
| 0x0002024c | `open_loop_changeover_enrichment` | b124 = tbl 0x69e00(rpm) when b146 |
| 0x00033ec4 | `load_delta_enrichment` | c134 load-delta, c140 3D tip-in |
| 0x000307e0 | `closed_loop_fuel_trim` | beb4/beb8 CL trim (clamp −1..2, filter 0.0625) |
| 0x00033ad2 | `calculate_engine_load` | c0b4 = min(filter(c0b0), c0b8); 0.525 if injectors off |
| 0x00007438 | `maf_sensor_scaling` | 9f78 = tbl 0x69788(raw·5/65536); fault 9f7c |
| 0x00019f4e / 0x00019f40 / 0x0001a418 | `maf_voltage_and_fault_counters` / `…_filtered_update` / `maf_per_rotation_calc` | MAF voltage, latching, per-rotation |
| 0x0001e842 | `maf_operating_range` | b0fe range 0-3 from a9ec |
| 0x0000e48e | `injection_angle_limit_lookup` | a434..a43c max injection angle (tbls 0x68ef8/f0c/f20) |
| 0x00030678 | `cranking_pulse_adder` | be94 += be58 when cranking |
| 0x0000e2a8 / 0x0000ee64 | `update_injectors_off_flag` / `rev_limit_fuel_cut_init` | a42c; clears a4a4/a4a5/a4a8 |
| 0x0000edc4 / 0x00018cfe / 0x0000ee82 | `fuel_cut_arbitration` / `…_rpm_condition` / `…_rev_limit_conditionals` | a444/a445, a964, a4a6-a4ae |
| 0x0001ddfc | `cold_start_enrichment` | b0c4 (0.0 in this ROM) |
| 0x00056b22 / 0x00056b8a / 0x00056b9e / 0x00056f6c | `diag22_pid0034_afr_lambda_words` / `diag22_pid0043_engine_load_g_rev` / `diag22_pid0044_lambda_target` / `diag22_pid1410_injector_pulse_time` | PIDs 0x0034/0x0043/0x0044/0x1410 (see [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md)) |
| 0x000556ec / 0x00055702 | `diag_read_afr_word_a` / `diag_read_afr_word_b` | AFR PID words aa6c/aa7c |

### 7.2 Core RAM

| Address | Name | Meaning |
|---|---|---|
| 0xffffbeb0 | `fuel_volume_final` | final fuel request (beac·bed0) |
| 0xffffbed0 / bed4 / bf1c / bf14 / beac | `fuel_load_scale` / `fuel_load_compensation` / `fuel_coolant_compensation` / `fuel_correction_sum` / `fuel_volume_scaled` | 0x306e8 chain |
| 0xffffbf68 / bf44 / bf4c / bf50 / bf54 | `airflow_rpm_load_product` / `airflow_corrected` / `air_density_ratio` / `air_charge_per_cycle` / `air_charge_filtered` | 0x314d0 chain |
| 0xffffbe24 | `injector_pulse_time` | PID 0x1410 (step 8 µs); = be28 |
| 0xffffbe28..be3c | `injector_pulse_time_base` / `…_ch1/ch2/ch3/ch4` / `cranking_decay_counter` | 0x2fea8 slots |
| 0xffffbe40 / be44 | `injector_latency_secondary` / `…_primary` | 0x2ff78 (tbls 0x6aa64/0x6aa80) |
| 0xffffbec8..bee8 | `fuel_amount_per_rotation_a..e` / `fuel_ratio_a/b` | 0x30948 |
| 0xffffbecc / becd | `secondary_split_gate_flag` / `secondary_injectors_active_flag` | secondary-split gate / SSV on-term, from 0x30b08 (§2.1) |
| 0xffffbf36 / bf37 / bf38 / bf39 | `high_rpm_override_flag` / `secondary_allowed_rpm_flag` / `split_fuel_gate_wot_flag` / `split_fuel_gate_flag` | rpm≥6250 override, rpm≥sec-allowed-threshold, WOT fuel gate, plain fuel gate (0x30b08) |
| 0xffffbef0 / bef4 / bef8 / befc | `fuel_volume_primary_split` / `fuel_volume_secondary_split` / `primary_secondary_split_ratio` / `fuel_volume_secondary_amount` | primary volume / secondary volume / ratio / secondary amount from the 0x30b08 split |
| 0xffffbeb4 / beb8 | `closed_loop_trim_raw` / `…_filtered` | 0x307e0 |
| 0xffffc00c / c010 / c014 / c018 | `warmup_enrichment_total` / `warmup_complete_flag` / `warmup_load_multiplier` / `warmup_rpm_multiplier` | 0x32e08 |
| 0xffffb120 | `open_loop_fuel_target` | 0x1ee4a (0 in CL) |
| 0xffffb130/b134/b138/b13c, b170/b174/b190/b194/b198/b19c | `ol_fuel_target_main` / `ol_coolant_correction` / `…_implausible` / `ol_temperature_correction_b`, baro/tip-in/target components | 0x1ee4a |
| 0xffffb11c / b118 | `fuel_blend_weight` / `timing_blend_weight` | 0x200c6 producer |
| 0xffffc0b0 / c0b8 / c0c4 / c0c5 | `engine_load_raw` / `engine_load_max` / `load_filter_fast_flag` / `injectors_off_previous` | 0x33ad2 |
| 0xffff9eea / 9f78 / 9f7c | `maf_adc_raw` / `maf_scaled` / `maf_fault_status` | 0x7438 |
| 0xffffa9e4 / a9e8 / aa2c / aa35 / aa36 | `maf_voltage_latched` / `maf_scaled_latched` / `maf_voltage` / `maf_high_fault_counter` / `maf_low_fault_counter` | 0x19f4e |
| 0xffffaa38 / aa3c / aa48 / aa54 / aa4c | `maf_per_rotation_filtered` / `maf_per_rotation` / `maf_filter_state` / `maf_filter_coeff` / `maf_filter_mode` | 0x1a418 |
| 0xffffa094..a0c0 | `injector_latency_ch0-2`(+mirrors) / `injector_zero_offset_ch0-2`(+mirrors) | 0x86f8/0x86ac |
| 0xffffa004 base (+0xc=a010, +0x10=a014, +0x13=a017, +0x14=a018) | injector channel struct, 0x18 stride | 0x8a68/0x85e4 |
| 0xffffa444/a445/a464/a465/a4a2/a4a3, a964/a97c/a97d/a96a/a96c, a4a4-a4ae | `fuel_cut_flag_a`/`fuel_cut_flag_b`/`fuel_cut_request_a`/`fuel_cut_request_b`/hysteresis latches, rpm gates/rev-limit state | 0xedc4/0x18cfe/0xee82/0xee64 |
| 0xffffaa6c / aa7c | `diag_afr_word_a/b` | PID 0x0034 |
| 0xffffb0fe / b101-b103 | `maf_range_index` / `maf_band_low`/`maf_band_mid`/`maf_band_high` (b102 = MAF < 9, hyst 8.4) | 0x1e842 |
| 0xffffb142 / b152 / b157 | `ol_decay_enable_a/b/c` — gate the 0x200c6 blend-weight decay branches | 0x200c6 |
| 0xffffbf20 | `cl_coolant_compensation` — lookup_2d tbl 0x6ac38(coolant), used in closed-loop fuel trim | 0x307e0 |
| 0xffffc138 / c13c / c158 / c14c | `load_delta_scale` / `load_scale_2d` / `load_delta_input` / `tip_in_mode_flag` — load-delta & tip-in state (0x33ec4) | 0x33ec4 |

### 7.3 ROM tables/data and entry points

Descriptors (verified vs `labeling/cross_ecu/romraider_descriptor_matches.json` from raw
ROM): 0x69788 MAF Scaling; 0x6ac88 Engine Load Compensation; 0x6aa80/0x6aa64
Injector Latency Primary/Secondary; 0x6a9a4/c0/dc temp multipliers; 0x6ae28/
0x6ae3c/0x6ae58/0x6ae74 Warmup family; 0x69e00 OL Changeover; 0x69cac-0x69f44
OL Target/Fuelling family; 0x69d24-0x69d74 CL thresholds; 0x6bab0 cranking
decay; 0x6b0c0/0x6b124/0x6b160/0x6b17c load-delta/tip-in; 0x68ef8/0x68f0c/
0x68f20 max injection angle; 0x6ad30/0x6ad44 air-flow×battery; 0x6ac4c per-
rotation scale; 0x6ac38 fuel coolant compensation (**candidate**, descriptor
unmatched); cal-area u16 0x6c102=0xfae1, 0x6c104=0xac0 (MAF fault thresholds).
Injector channel map: ROM 0xd7d4 (DCNT8x/GR1x/TIER8 per ch), wrappers
0x59a4-0x59ea, rotor blocks ROM 0x4e2c8 ({0,1,2}/{3,4,5}), task table 0x4998,
dispatch 0x5f10c (PIDs above). See [`reviews/fueling/injector_pin_mapping.md`](reviews/fueling/injector_pin_mapping.md).
FSM pinout cross-check (`mazda-rx-8-pcm-pinout-series-1.pdf`, 13B/FSM-derived, markers ³/†/* kept):
  2M=Front Primary 1, 2J=Rear Primary 1, 2G=Front Secondary, 2D=Rear Secondary,
  3A/3D=Primary 2 (HP only). The PDF has no chip-pin numbers, so pkg pin (195/197-201)
  -> terminal stays board-level unresolved; full combined chain in the review doc §7.

### 7.4 How to validate

- `python3 scripts/validate_export.py` (ROM hash + instruction bytes);
  `python3 scripts/verify_readability.py`.
- Per-function C / disasm / alias TSV lookups as in §7 header; binary-level
  re-check notes in [`reviews/fueling/REVIEW_NOTES.md`](reviews/fueling/REVIEW_NOTES.md) §10.

---

## 9. Binary-level verification

- Every label is verified against the raw ROM
  ([`reviews/fueling/REVIEW_NOTES.md`](reviews/fueling/REVIEW_NOTES.md) §10): all 168,592 instruction words, all
  RAM aliases vs reader literal pools, descriptors re-parsed, dispatch records —
  0x8a68 pulse = (latency+request)>>4, the shift applies to the sum.
- Injector channel → ATU-II → SH7055F pin mapping, cross-checked
  against the FSM pinout ([`reviews/fueling/injector_pin_mapping.md`](reviews/fueling/injector_pin_mapping.md)):
  ch0/3/1/4/2/5 → pins 195/197/198/199/200/201; rotor blocks {0,1,2}/{3,4,5};
  injectors share a W/L +12V feed (PCM pins are ground-side). Package-pin ↔
  terminal remains board routing (unresolved).
- `scripts/validate_reports.py` validates this report's memory map against the
  export/ROM (`metadata/report_validation.json`).


---

## 10. Group C deepening (ROADMAP)

All §7/§9 items are traced in the canonical export, verified against raw ROM
bytes (SHA-256 unchanged `a7cd953c…264f1`), cross-checked against the RX8Club
thread ([`docs/references/rx8club-user-guide-thread.md`](../../references/rx8club-user-guide-thread.md)
§6/§9), and the load chain is verified dynamically in the emulator
(`tests/test_fuel_chain_dynamic.py`, 65/65 pytest). Load math itself lives in
[`load_fueling_report.md`](load_fueling_report.md) — cross-referenced, not
duplicated; it settles the units (cell = VolEf = g/rev ×
0.6345, ROADMAP D5 closed).

### 10.1 `fuel_correction_sum` (bf14) adder writers — all traced

bf14 (0x306e8 `calc_fuel_volume_request`) =
`(b0d0 − c0c8 − ae08 − b21c) + max(c104, cde0) + min(tbl_06ac38(coolant), c00c+b120) + max(ae10, b124) + 1.0`,
then `× adec × bed4`. Producers:

| cell | producer | semantics |
|------|----------|-----------|
| 0xffffb0d0 `inferred_ltft_bank1_ffffb0d0` | 0x1e900 `ref_LTFTForCAN__`, init 0x1e070 | learned long-term fuel trim bank 1, stored per MAF-range slot at RAM 0x80c4+8×`maf_range_index_ffffb0fe`; filter 0.1 toward current, clamp [−0.23, 0.23]; PID 0x07 |
| 0xffffc0c8 `DAT_ffffc0c8` | 0x33dc8 (reset 0x33e36) | `c0cc = c0e0·c0ec + c0d0·c0dc + c0f0·c0fc` (3-term product sum), `c0c8 = min(c0cc·c100, 16.0)`; zeroed when engine_on_time==0 or (c108 && rpm<812.5). Subtracted |
| 0xffffae08 `DAT_ffffae08` | 0x1cc34 | CL-target deviation `(ae0c − ae00) + af1c + af20 − b000` (ae0c = tbl_069a60/069a7c(rpm, load), bank by cac8; af20 = integral term ±0.0005, deadband ±0.02). Subtracted |
| 0xffffae10 `DAT_ffffae10` | 0x1cc34 | CL WOT enrichment tbl_0699b8(rpm, tps); added via `max(ae10, b124)` |
| 0xffffb21c `DAT_ffffb21c` | 0x20288 = b220·b22c | b220 = CL-trim integral clamp [−0.05, 0.15], nudged ±8e-05 by CL-trim sign (0x20298, with fuel-cut edges b238/b23c); b22c = (b224/maf)·100, b224 = filtered per-band fuel-rate array `b1dc[tbl_069f60(rpm)]` (0x2048c, coeff 0.78/0.4) → MAF-relative % correction. Subtracted |
| 0xffffc104 `DAT_ffffc104` | 0x34230 (reset 0x342b0) | `c144 = c124·c130 + c110·c134·c140 + c114·c120` (tip-in product-sum incl. decay×load-delta×tip-in), `c104 = min(c10c·c144, 16.0)`; zeroed when cold (`tbl_06b0ac(coolant) ≤ c01c`). Added via `max(c104, cde0)` |
| 0xffffcde0 `DAT_ffffcde0` | 0x4af14 / 0x4afd6 | transient adder with decay `max(cde0 − cde8, arg1)` / set `fVar5·fr0` (descriptors 0x6bb1c/0x6bb28/0x6bb3c/0x6bb50/0x6bb6c) |
| 0xffffadec `inferred_lambda_actual_ffffadec` | 0x1c880 (init 0x1c0a8/0x1c0ec) | measured lambda: `adf8 = 1/afr_word_a`, 20-tap weighted sum of `aec8[i]·ae68[i]`, clamped to [b044, b048] with b044 = tbl_0698e4(aa78), b048 = max(tbl_0698bc(aa78), tbl_06999c(rpm,load), tbl_0698d0(coolant) when ≥ −40 °C); filtered into adf0/adf4 (0.015325 / 0.0078125); forced 1.0 when CL off. Multiplier `adec`; PID 0x06 = (λ−1)·100 |
| 0xffffc644 `fuel_correction_sum_ffffc644` | 0x3e980 (helpers 0x3e766/0x3e78e) | **catalyst-temperature model** (cat-warmup correction): engine off → cat model a998 (or `max(read(0x8710) − (coolant−a998)·10, a998)`); running with c5e6 → 1000.0; else first-order approach `c644 += (c684−c644)·c678·c67c·c68c`. PID 0x3c (×0.1−40) |

The trailing `+ 1.0` in bf14 and the `+ 1.0` inside the 0x1cc34 lambda-target clamp
confirm the thread's claim that **lambda tables store the decimal part (λ−1) and
1 is added back late** — here visible in 0x1cc34:
`lambda_target_ffffadfc = clamp((ae0c−ae00−ae04) + trim_b074 + af1c + af20 + aff8 − b000 − max(ae10, b00c) + 1.0, 0.85, 1.05)`.

### 10.2 Fuel-cut arbitration — resolved

0xedc4 `fuel_cut_arbitration(param)`: request A (`fuel_cut_request_a` 0xffffa464) → both
flags set (`fuel_cut_flag_a/b` a444=a445=1); request B (a465) only on its rising edge, and unless
the caller is source 0x06/0x12, sets (a444=0, a445=1); otherwise a444=0, a445=0.
Hysteresis via prev-request latches a4a2/a4a3; then calls 0xe2d4. RPM gates
0x18cfe `fuel_cut_rpm_condition`: `fuel_cut_allowed_ffffa964` =
(decel_a a96a && rpm>2500) || (decel_b a96c && rpm>1700), with hysteresis flags
a97c/a97d (1700/2500). Rev-limit conditionals 0xee82: coolant<18 °C flag a4a6 and
a 12-cycle rev-limit countdown a4ae on mode edge (prev a4ad). Still open: the
requesters of `fuel_cut_request_a/b` 0xffffa464/a465 (0xf960 `ref_somethingFuelCutRelated`, tables
0x4e27c/0x4e2c8 — candidate level).

### 10.3 Injection-angle semantics — resolved

0xe48e `injection_angle_limit_lookup` loads a434/a438/a43c from
tbl_068ef8 / tbl_068f0c / tbl_068f20 (rpm axis 800–6800, uint8, RX8Defs scale
"(x·2)+0 deg (MAYBE?)" → 120° at 800 rpm down to 60° at 6800 rpm). Consumer
0xff32 `ref_fuelInjectionRelated` cmd 1 writes them as `value × 65536`
fixed-point into the injector struct at +0x20/+0x38/+0x50 (cmd 0 writes
`(a440−275)·65536` = a temperature in K). So the three tables are **per-injector
maximum open-time angle budgets in crank degrees** (primary / secondary 1 /
secondary 2), shrinking with rpm — not injection *phase*.

### 10.4 Cold-start degenerate body — resolved (byte-verified)

0x1ddfc `cold_start_enrichment`: engine-off stores 0.0 (fldi0 fr15) to
b0c4 in both coolant/IAT branches; running computes `max(b0c4 − pool, 0.0)` with
pool word 0x1de64 → float at 0x71064 = `0x00000000` (0.0), and 0x1de60 → 0x71060
also 0.0. So **b0c4 is hardwired to 0.0 in this ROM** — the cold-start enrichment
is compiled out; the function only ever freezes/zeros it.

### 10.5 MAF fault latching — resolved

0x19f4e `maf_voltage_and_fault_counters`: `maf_voltage_ffffaa2c` =
raw·5/65536 (step 0x38a00000); saturating u8 counters aa35 (raw ≥ 0xf852) /
aa36 (raw < 0x7ae); the validated pair a9e4/a9e8 is latched when a counter > 2
**or** raw is inside the valid band (0x7ae, 0xf852). 0x19f40
`maf_filtered_update` copies a9e8 → `mass_air_flow_ffffa9ec` (the cell
the load/fuel chain consumes). The 0.64 V / 4.9 V window fault manager itself is
in [load_fueling_report.md](load_fueling_report.md) (cal-area u16 0x6c102/0x6c104).

### 10.6 The 0x4ab8 task-record dispatch — resolved (correction to the OS report)

0x375c `os_switch_to_task` loads its base from pool 0x37b0 → **0x4990** (not
0x4998), stride 16 (`shll2`×2). Records at 0x4990+i·16 have layout
{param, stack, entry, mask}: rec[0..18] are valid (stacks `os_task_stack_base` 0xffff7408–0xffff7498,
entries 0x62a0…0x64e8), and 0x4ac0 holds the terminator {0x04ffffff, 0x00000001, …}.
**0x4ab8 is the entry field of rec[18] → 0x64e8 `slow_task_entry`** (u32 at ROM 0x4ab8
= 0x64e8, re-read this pass), a thunk {jsr 0x11534; jmp
0x3d58 taskEnd}; 0x11534 `slow_background_task` is the 29-call slow/background task (torque params,
diag timers, immo counter, …). So the task table is **19 records based at
0x4990**, correcting [os_scheduler_can_ivt_report.md](os_scheduler_can_ivt_report.md)'s
"0x4998, 18 × {entry, mask, param, stack}" (0x4998 is rec[0].entry; count/layout
off by one record — see the dated note added there).

### 10.7 Descriptor → `data/maps/60E15120_N3J1E` table-name mapping

P3-extracted names for every fueling-relevant descriptor (join of
`data/maps/60E15120_N3J1E/index.tsv` with
`labeling/cross_ecu/romraider_descriptor_matches.json`):

| descriptor | data/maps name | RX8Defs name |
|------------|---------------|--------------|
| 0x068ef8 / 0x068f0c / 0x068f20 | tbl_068ef8 / tbl_068f0c / tbl_068f20 | Max Injection Angle1/2/3??? (deg ×2) |
| 0x069788 | tbl_069788 | MAF Scaling |
| 0x069cac / 0x069cc0 | tbl_069cac / tbl_069cc0 | OL Fuelling Base Correction (Throttle) [Safe Mode] |
| 0x069cd4 | tbl_069cd4 | OL Target - Coolant Temperature Correction |
| 0x069ce8 / 0x069cfc | tbl_069ce8 / tbl_069cfc | OL Fuelling Rich Limit [Safe Mode] |
| 0x069d10 | tbl_069d10 | OL Temperature Correction #B |
| 0x069e00 | tbl_069e00 | OL Changeover Enrichment |
| 0x069e80 / 0x069eb8 | tbl_069e80 / tbl_069eb8 | OL Target - Throttle Tip In [Safe Mode] |
| 0x069e9c / 0x069ed4 | tbl_069e9c / tbl_069ed4 | OL Target [Safe Mode] |
| 0x069ef0 / 0x069f28 | tbl_069ef0 / tbl_069f28 | OL Target - Tip In - Coolant Implausible B / A |
| 0x069f0c / 0x069f44 | tbl_069f0c / tbl_069f44 | OL Target - Coolant Implausible - Gear 5-6 / 1-4 |
| 0x0699b8 | tbl_0699b8 | Closed Loop WOT Enrichment?? |
| 0x069a60 / 0x069a7c | tbl_069a60 / tbl_069a7c | Table 3D - 29 / 30 (CL target banks) |
| 0x06ac38 | tbl_06ac38 | (unmatched — coolant comp candidate) |
| 0x06ac88 | tbl_06ac88 | Fuel Injection - Engine Load Compensation |
| 0x06a9a4 / 0x06a9c0 / 0x06a9dc | tbl_06a9a4 / tbl_06a9c0 / tbl_06a9dc | Primary / Sec1 / Sec2 Injector Weighted Engine Temp Multiplier |
| 0x06aa48 | tbl_06aa48 | Estimated Manifold Pressure |
| 0x06aa64 / 0x06aa80 | tbl_06aa64 / tbl_06aa80 | Injector Latency Secondary / Primary |
| 0x06ab70 | tbl_06ab70 | primary/secondary split ratio vs rpm ("Table 2D - 177"; unlabeled) — used by 0x30b08 §2.1 |
| 0x06ab84 | tbl_06ab84 | Primary Injector Max Barometric Pressure Correction — WOT fuel gate in 0x30b08 §2.1 |
| 0x06ac60 | tbl_06ac60 | Secondary Injectors Allowed Threshold - Coolant Temperature Based (3000 rpm ≤ 0 °C, 0 warm) — 0x30b08 §2.1 |
| 0x06ac74 | tbl_06ac74 | flat 6250 rpm high-RPM override (unlabeled) — 0x30b08 §2.1 |
| 0x06ab48 / 0x06bab0 | tbl_06ab48 / tbl_06bab0 | Primary Cranking Pulse Width / Decay Time |
| 0x06ae28 / 0x06ae3c / 0x06ae58 / 0x06ae74 | tbl_06ae28 / tbl_06ae3c / tbl_06ae58 / tbl_06ae74 | Warmup Fueling family |
| 0x0697b4, 0x06ac4c, 0x06ad30, 0x06ad44, 0x06b0ac, 0x06b0c0, 0x06b124, 0x06b160, 0x06b17c | tbl_0697b4 … tbl_06b17c | (unmatched — Table 2D/3D-nnn in RX8Defs) |

### 10.8 Thread OL-fueling cross-check — confirmed

0x1ee4a `open_loop_fueling_targets`: b170 = tbl_069cac|069cc0(baro) [safe-mode
pair], b190 = tbl_069e80|069eb8(rpm, tps) tip-in, b194 = tbl_069e9c|069ed4(load,
rpm) main target; **b130 = max(b170·b190, b194)**; b134 = tbl_069cd4(coolant);
**b120 = b130·b134** — exactly the thread's `Final = max(OL target,
TipIn×BaroCorr) × CLTCorr`. Implausible-coolant A/B sets (gear 1-4 vs 5-6:
tbl_069f44/069f0c, tip-in A/B tbl_069f28/069ef0, rich limit tbl_069cfc/069ce8)
blend by `fuel_blend_weight_ffffb11c`: `b120 = b138·b13c·w + (1−w)·b130·b134`,
and safe mode swaps the whole family (tbl_069cac/069cc0, 069eb8/069ed4, 069ce8).
Cat-warmup rides the catalyst-temperature model (c644, §10.1). All thread claims
in §9 of the reference check out against the ROM; the load-side units are settled in
[load_fueling_report.md](load_fueling_report.md) (D5).

### 10.9 Dynamic verification (emulator, harness.py)

`tests/test_fuel_chain_dynamic.py` (new; 65/65 `python -m pytest tests/`):
- 0x1a418 `maf_per_rotation_calc`: `maf_per_rotation` 0xffffaa3c = min(maf·60/rpm, 5.0)` — 100 g/s @ 3000 rpm → 2.0;
  1000 g/s @ 1000 rpm → 5.0 (cap).
- 0x33a6c: `engine_load_raw = aa3c × 0.6345` — bit-exact vs ROM float 0x3f226e98.
- 0x33ad2: filter+clamp — filter(0.8, 0.5, 0.2) → 0.56, min vs c0b8; clamp case →
  c0b8; stopped latch → 0.525.
- 0x55748 (PID 0x43 encode via handler 0x56b8a): c0b4 = 0.42 → raw 107; 1.0 → 255
  (step 1/255, float at 0x55824).

### 10.10 Functions traced in this update

| address | name | role |
|---------|------|------|
| 0x01ee4a | open_loop_fueling_targets | OL target chain (§10.8) |
| 0x01cc34 | FUN_0001cc34 | CL lambda target + WOT enrichment + af20 integral (§10.1) |
| 0x01c880 | FUN_0001c880 | lambda actual from AFR word + taps, clamp, filters (§10.1) |
| 0x01e900 | ref_LTFTForCAN__ | LTFT bank1 learn/store (§10.1) |
| 0x01e070 | FUN_0001e070 | LTFT init from 0x80c4 |
| 0x00020288 / 0x00020298 / 0x0002048c | FUN_00020288 / FUN_00020298 / FUN_0002048c | b21c = b220·b22c; b220 integral; b22c MAF-relative % (§10.1) |
| 0x00033dc8 / 0x00033e36 | FUN_00033dc8 / FUN_00033e36 | c0c8 product-sum adder, reset |
| 0x00034230 / 0x000342b0 | FUN_00034230 / FUN_000342b0 | c104 tip-in adder, reset |
| 0x0004af14 / 0x0004afd6 | FUN_0004af14 / FUN_0004afd6 | cde0 transient adder + decay |
| 0x0003e980 | FUN_0003e980 | c644 catalyst-temp correction (PID 0x3c) |
| 0x0000edc4 / 0x00018cfe / 0x0000ee82 | fuel_cut_arbitration / fuel_cut_rpm_condition / rev_limit_conditionals | fuel-cut arbitration (§10.2) |
| 0x0000e48e / 0x0000ff32 | injection_angle_limit_lookup / ref_fuelInjectionRelated | max injection angle tables → struct (§10.3) |
| 0x0001ddfc | cold_start_enrichment | degenerate 0.0 body (§10.4) |
| 0x00019f4e / 0x00019f40 | maf_voltage_and_fault_counters / maf_filtered_update | MAF latch (§10.5) |
| 0x000064e8 / 0x00011534 | `slow_task_entry` / `slow_background_task` | task rec[18] entry → slow task (§10.6) |

### 10.11 Limits of this update

- Static + emulator evidence only (no hardware). Producer semantics of the
  c0cc/c144 term cells (c0e0/c0ec/c0d0/c0dc/c0f0/c0fc, c124/c130/c110/c114/c120)
  are read from the decompiled dataflow, not individually re-derived; the
  requesters of `fuel_cut_request_a/b` 0xffffa464/a465 (0xf960, tables 0x4e27c/0x4e2c8) and the exact
  transform of 0x5c024 on bf14 remain candidate-level. Channel→connector-terminal
  hop still board-level. The task-table correction in §10.6 is recorded as a
  dated note in [os_scheduler_can_ivt_report.md](os_scheduler_can_ivt_report.md).
