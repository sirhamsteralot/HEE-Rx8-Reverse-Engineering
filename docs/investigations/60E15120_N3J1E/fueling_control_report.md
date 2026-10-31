# Fueling control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Date: 2026-10-30. Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes. No hardware execution was
performed. Full evidence: `reviews/fueling/README.md`; sceptical re-check:
`reviews/fueling/REVIEW_NOTES.md`; validation: `reviews/fueling/validation.json`.

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

# per-injector amounts + pulse times (0x30948, 0x2fea8)
amounts[6] = temp_mult[3] * flow * 6e7/rpm * tbl_0x6ac4c/360 * {369.472, 475.93} - latency
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

## 3. Key calibrated tables (RX8Defs names; descriptor-matched)

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

## 4. Labeling applied (2026-10-30 pass)

- 39 functions, 151 RAM locations, 1 lookup table added to
  `source_review/accepted_*_aliases.tsv`; integrated into all synchronized
  views (per-function files, `decompiled/firmware_decompiled.c`,
  `named/firmware_named.c`, index/callgraph/symbols TSVs,
  `metadata/integrated_names.json`); 234 snapshot-local renames.
- Pipeline: `scripts/review_fueling_labels.py` (idempotent, wired into
  `scripts/rebuild.sh`); record `metadata/fueling_labels.json`; backup
  `backups/pre_fueling_labels.zip`.
- Design doc updated: `design/README.md` §5.8.

## 5. Corrections made in this pass

1. `injector_pulse_set_channel` (0x8a68): pulse = (latency + fuel_request) >> 4 —
   the four `shar` at 0x8a96-0x8a9e apply to the sum (found in the binary-level
   verification pass; see `reviews/fueling/REVIEW_NOTES.md` §10).
2. Pipeline hygiene: `review_fueling_labels.py` initially duplicated TSV header
   rows (read with explicit fieldnames); fixed to consume the header, duplicates
   removed, and `name_lookup_variables.py` confirmed as a fresh-export-only step.
3. Def caveat (documented, not fixed — upstream repo): logger PID 0x221410 is
   claimed by both "Injector Pulse Time" and "Throttle Pedal Position"; handler
   0x56f6c encodes `injector_pulse_time_ffffbe24` at step 8 µs.

## 6. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function
  files, 168,592 instructions byte-verified, 1,833 reference matches.
- `scripts/verify_readability.py` — pass (3,355 bodies consistent).
- `scripts/verify_math_units.py` — pass.
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
dispatch remain open (see `reviews/fueling/README.md` §9). The ROM was not
modified.

## 8. Memory map for validation

Check any address in `decompiled/firmware_disassembly.asm` (ROM) or
`decompiled/functions/<address>_*.c` (index: `decompiled/function_index.tsv`);
alias evidence in `source_review/accepted_*_aliases.tsv` (basis
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
| 0x0002fea8 | `injector_pulse_time_arbitrate` | be24..be38 pulse slots, cranking decay tbl 0x6bab0 |
| 0x00008a68 | `injector_pulse_set_channel` | ATU-II program: pulse = (a094[ch]+a010[ch])>>4 → DCNT8x |
| 0x00008340 | `candidate_injector_pulse_set_dispatch` | thunk → 0x8a68; wrappers 0x59a4-0x59ea |
| 0x000086f8 / 0x000086ac | `set_fuel_injector_latency` / `candidate_injector_zero_offset_set` | a094..a0a8 / a0ac..a0c0 per-channel pairs |
| 0x000085e4 | `injector_channel_disable` | per-channel off (TIER/GR/DCNT) |
| 0x0002ff78 | `injector_latency_cal_lookup` | 3D latency tbls 0x6aa80/0x6aa64 vs MRP + battery V, /0.25 |
| 0x0002fd3e | `injector_temp_multiplier_lookup` | bde4/bde8/bdec 3D temp×load tbls 0x6a9a4/0x6a9c0/0x6a9dc |
| 0x00032e08 | `warmup_fueling_compensation` | c00c = c014+c018 warmup enrichment |
| 0x0002024c | `open_loop_changeover_enrichment` | b124 = tbl 0x69e00(rpm) when b146 |
| 0x00033ec4 | `load_delta_enrichment` | c134 load-delta, c140 3D tip-in |
| 0x000307e0 | `closed_loop_fuel_trim` | beb4/beb8 CL trim (clamp −1..2, filter 0.0625) |
| 0x00033ad2 | `calculate_engine_load` | c0b4 = min(filter(c0b0), c0b8); 0.525 if injectors off |
| 0x00007438 | `maf_sensor_scaling` | 9f78 = tbl 0x69788(raw·5/65536); fault 9f7c |
| 0x00019f4e / 0x00019f40 / 0x0001a418 | `candidate_maf_voltage_and_fault_counters` / `…_filtered_update` / `…_per_rotation_calc` | MAF voltage, latching, per-rotation |
| 0x0001e842 | `maf_operating_range` | b0fe range 0-3 from a9ec |
| 0x0000e48e | `candidate_injection_angle_limit_lookup` | a434..a43c max injection angle (tbls 0x68ef8/f0c/f20) |
| 0x00030678 | `cranking_pulse_adder` | be94 += be58 when cranking |
| 0x0000e2a8 / 0x0000ee64 | `update_injectors_off_flag` / `rev_limit_fuel_cut_init` | a42c; clears a4a4/a4a5/a4a8 |
| 0x0000edc4 / 0x00018cfe / 0x0000ee82 | `candidate_fuel_cut_arbitration` / `…_rpm_condition` / `…_rev_limit_conditionals` | a444/a445, a964, a4a6-a4ae |
| 0x0001ddfc | `candidate_cold_start_enrichment` | b0c4 (0.0 in this ROM) |
| 0x00056b22 / 0x00056b8a / 0x00056b9e / 0x00056f6c | `diag_air_fuel_ratio` / `diag_engine_load` / `diag_lambda_target` / `candidate_diag_injector_pulse_time` | PIDs 0x0034/0x0043/0x0044/0x1410 |
| 0x000556ec / 0x00055702 | `candidate_diag_afr_word_a/b` | AFR PID words aa6c/aa7c |

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
| 0xffffbeb4 / beb8 | `closed_loop_trim_raw` / `…_filtered` | 0x307e0 |
| 0xffffc00c / c010 / c014 / c018 | `warmup_enrichment_total` / `warmup_complete_flag` / `warmup_load_multiplier` / `warmup_rpm_multiplier` | 0x32e08 |
| 0xffffb120 | `open_loop_fuel_target` | 0x1ee4a (0 in CL) |
| 0xffffb130/b134/b138/b13c, b170/b174/b190/b194/b198/b19c | `ol_fuel_target_main` / `ol_coolant_correction` / `…_implausible` / `ol_temperature_correction_b`, baro/tip-in/target components | 0x1ee4a |
| 0xffffb11c / b118 | `fuel_blend_weight` / `timing_blend_weight` | 0x200c6 producer |
| 0xffffc0b0 / c0b8 / c0c4 / c0c5 | `engine_load_raw` / `engine_load_max` / `load_filter_fast_flag` / `injectors_off_previous` | 0x33ad2 |
| 0xffff9eea / 9f78 / 9f7c | `maf_adc_raw` / `maf_scaled` / `maf_fault_status` | 0x7438 |
| 0xffffa9e4 / a9e8 / aa2c / aa35 / aa36 | MAF latched voltage/scaled/fault counters | 0x19f4e |
| 0xffffaa38 / aa3c / aa48 / aa54 / aa4c | MAF per-rotation filtered/value/filter | 0x1a418 |
| 0xffffb0fe / b101-b103 | `maf_range_index` / band flags | 0x1e842 |
| 0xffffa094..a0c0 | `injector_latency_ch0-2`(+mirrors) / `injector_zero_offset_ch0-2`(+mirrors) | 0x86f8/0x86ac |
| 0xffffa004 base (+0xc=a010, +0x10=a014, +0x13=a017, +0x14=a018) | injector channel struct, 0x18 stride | 0x8a68/0x85e4 |
| 0xffffa444/a445/a464/a465/a4a2/a4a3, a964/a97c/a97d/a96a/a96c, a4a4-a4ae | fuel-cut flags/requests/rpm gates/rev-limit state | 0xedc4/0x18cfe/0xee82/0xee64 |
| 0xffffaa6c / aa7c | `diag_afr_word_a/b` | PID 0x0034 |

### 7.3 ROM tables/data and entry points

Descriptors (verified vs `cross_ecu/romraider_descriptor_matches.json` from raw
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
dispatch 0x5f10c (PIDs above). See `reviews/fueling/injector_pin_mapping.md`.
FSM pinout cross-check (`mazda-rx-8-pcm-pinout-series-1.pdf`, 13B/FSM-derived, markers ³/†/* kept):
  2M=Front Primary 1, 2J=Rear Primary 1, 2G=Front Secondary, 2D=Rear Secondary,
  3A/3D=Primary 2 (HP only). The PDF has no chip-pin numbers, so pkg pin (195/197-201)
  -> terminal stays board-level unresolved; full combined chain in the review doc §7.

### 7.4 How to validate

- `python3 scripts/validate_export.py` (ROM hash + instruction bytes);
  `python3 scripts/verify_readability.py`.
- Per-function C / disasm / alias TSV lookups as in §7 header; binary-level
  re-check notes in `reviews/fueling/REVIEW_NOTES.md` §10.

---

## 9. Update — 2026-10-30 (later same day)

- Binary-level verification pass re-checked every label against the raw ROM
  (`reviews/fueling/REVIEW_NOTES.md` §10): all 168,592 instruction words, all
  RAM aliases vs reader literal pools, descriptors re-parsed, dispatch records —
  one correction (0x8a68 pulse = (latency+request)>>4, shift on the sum).
- Injector channel → ATU-II → SH7055F pin mapping completed and cross-checked
  against the supplied FSM pinout v3 (`reviews/fueling/injector_pin_mapping.md`):
  ch0/3/1/4/2/5 → pins 195/197/198/199/200/201; rotor blocks {0,1,2}/{3,4,5};
  injectors share a W/L +12V feed (PCM pins are ground-side). Package-pin ↔
  terminal remains board routing (unresolved).
- `scripts/validate_reports.py` validates this report's memory map against the
  export/ROM (`metadata/report_validation.json`).
