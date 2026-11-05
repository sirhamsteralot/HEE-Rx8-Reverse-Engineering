# Targeted static review: fueling chain

Scope: the air/fuel calculation, injection output, open/closed-loop fuel target
selection, enrichments, fuel cut / rev limit and the fuel-related diagnostic
PIDs of 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E), read from the canonical
export (`decompiled/`), the disassembly and the untouched ROM. This pass
labels the chain in the export (39 functions, 151 RAM locations, 1 lookup
table; see `source_review/accepted_*_aliases.tsv` and
`metadata/fueling_labels.json`). No firmware changes were made; the ROM is
untouched (SHA-256 verified by `scripts/validate_export.py`).

Result: the fueling chain is traced end to end and labeled. It runs in two
task chains plus the main engine-control task, and — like the knock chain —
its **corrections are gated by engine conditions; the loop mode only selects
which fuel target table set feeds the request** (open-loop tables vs the
closed-loop trim around lambda target).

## 1. Signal chain

```
task[6]  0x661e ref_task2_ -> ref_engineControlTASK 0x11ba4 -> fueling_main_task 0x20e40
  block 1 (mask 0x10): enrichments + injection angle limits
       ref_UnknownFueling1_0000e454, injection_angle_limit_lookup 0xe48e,
       0x30274/0x302a2/0x303f2, cranking_pulse_adder 0x30678, 0x30228, 0xefa,
       0x34364, throttle fault 0x341be..., load_delta_enrichment 0x33ec4
  block 2 (mask 0x10): fuel core
       calc_fuel_volume_request 0x306e8
       calculate_fuel_amount_per_rotation 0x30948
       injector_pulse_time_arbitrate 0x2fea8   -> injector_pulse_time be24 etc.
       cold_start_enrichment 0x1ddfc, 0x4af14, 0x4b190
  block 3 (mask 0x10): closed-loop conditions
       0x1c384, 0x1d5c2, closed_loop_enable_condition 0x1c13c, 0x1d2e2, ...

task 0x64f6 -> 0x11744 -> fueling_condition_flags_task 0x211fe (ref_OLFueling__)
  -> load/RPM band flags 0x1ff38, throttle/load band flags 0x1f6ae, 0x1fd48
  -> blend_weight_update 0x200c6   (b11c/b118)
  -> off-throttle fuel-cut resume 0xe560 (tbl 0x68f48), 0x3133c (tbl 0x6aca4)
  -> calculate_air_charge 0x314d0
  -> secondary-air enrichment 0x31624
  -> injector_temp_multiplier_lookup 0x2fd3e (bde4/bde8/bdec)

task[11] 0x6584 -> 0x117ac -> fueling_slow_task 0x21246 (ref_getFuelingSlowtask_)
  -> open_loop_request_condition 0x1f0c4 -> set_open_loop_flag 0x1ee30
  -> open_loop_fueling_targets 0x1ee4a  -> open_loop_fuel_target b120
  -> open_loop_changeover_enrichment 0x2024c (b124)
  -> warmup_fueling_compensation 0x32e08 (c00c/c010/c014/c018)
  -> rear-O2 chain 0x1d6b4/0x1d772/0x1d850/0x1d8dc/0x1e134
  -> maf_operating_range 0x1e842, LTFT-for-CAN 0x1e900, 0x188a4
  -> closed_loop_fuel_trim 0x307e0 (beb4/beb8)  [via 0x307e0 call]
  -> fuel_cut_rpm_condition 0x18cfe (a964), rev_limit_conditionals 0xee82

injector output (ATU-II):
  six wrappers 0x59a4-0x59ea -> injector_pulse_set_dispatch 0x8340
  -> injector_pulse_set_channel 0x8a68
       pulse = (injector_latency_chN a094[ch] + injector_fuel_request a010[ch*0x18]) >> 4
       (four `shar` at 0x8a96-0x8a9e — the shift applies to the SUM) -> ATU-II DCNT8A;
       start = a014[ch*0x18] (or TCNT1A+3) -> GR1A
  injector_channel_disable 0x85e4 (called from 0x82b8, 0xf0dc, 0xf7f8, 0xf8d0, 0xfa4e, 0xfb8c, 0xfcfe)
  injector_latency_cal_lookup 0x2ff78 -> set_fuel_injector_latency 0x86f8
  injector_zero_offset_set 0x86ac (caller 0x10208 ref_setAllInjectorto0_)

sensors feeding load:
  maf_adc_raw 0xffff9eea -> maf_sensor_scaling 0x7438 (tbl 0x69788 'MAF Scaling', *5/65536)
  -> maf_voltage_and_fault_counters 0x19f4e -> maf_scaled_latched a9e8
  -> maf_filtered_update 0x19f40 -> mass_air_flow a9ec
  -> maf_per_rotation_calc 0x1a418 (aa3c = min(maf*60/rpm, 5.0))
  -> calculate_engine_load 0x33ad2 -> engine_load c0b4 (PID 0x0043)
```

### 1.1 Injector channel → rotor → ATU-II → pin (see [`injector_pin_mapping.md`](injector_pin_mapping.md))

- Rotor blocks: queue blocks at 0xffffa4b4; block 0 → fw channels {0,1,2},
  block 1 → {3,4,5} (ROM 0x4e2c8 via `ref_fuelingArrayInit_` 0xf37c) —
  per-rotor injection, matching per-rotor knock sensing.
- Channel → ATU-II 8x/1x (ROM 0xd7d4 + wrappers 0x59a4-0x59ea + TSR8 bits):
  ch0→8A/1A, ch1→8C/1C, ch2→8E/1E, ch3→8B/1B, ch4→8D/1D, ch5→8F/1F.
- 8x → TO8x → SH7055F package pins (supplied `Sh7055h.pdf`, Tables 1.2/1.3,
  PKCR §20.3.21; running config PKCRL=0x5555 via `ref_setRegisters`):
  ch0→pin 195, ch3→197, ch1→198, ch4→199, ch2→200, ch5→201.
- PID 0x1410 "Injector Pulse Time" reports be24 = primary request (be4c) +
  latency (0x2fea8) — the logged pulse is the primary injector's.
- Open: package-pin → connector-terminal hop (2M/2J/2G/2D/3A/3D) is board
  routing; readers of the secondary pulse slots be2c/be30/be34/be38 and of
  the secondary-enable gates bf36/bf37 are not visible in the export.

## 2. Fuel request core (0x306e8 `calc_fuel_volume_request`)

```
fuel_load_scale        bed0 = engine_load * 0.07196
fuel_load_compensation bed4 = tbl 0x6ac88 'Fuel Injection - Engine Load Compensation'(RPM)
fuel_coolant_comp      bf1c = tbl 0x6ac38 (coolant)          [candidate name; descriptor unmatched]
fuel_correction_sum    bf14 = (b0d0 - c0c8 - ae08 - b21c
                              + max(c104, cde0)                 # cranking/start adders
                              + min(bf1c, c00c + b120)          # warmup + OL target
                              + max(ae10, b124) + 1.0)          # OL changeover enrichment
                              * ad ecc * bed4
fuel_volume_scaled     beac = FUN_0005c024(bf14)              # diagnostic scaler
fuel_volume_final      beb0 = beac * bed0
```

Air side (0x314d0 `calculate_air_charge`): `bf68 = rpm*load/38.07`;
`bf44 = tbl 0x6ad44(bf68) * tbl 0x6ad30(battery V)`; density ratio
`bf4c = baro*353.0163/((IAT+273)*101.32)`; air charge per cycle
`bf50 = min(bf44*0.6345*bf4c/(60*rpm), 2.0)`, filtered into `bf54` (clamp 50).

Per-injector amounts (0x30948 `calculate_fuel_amount_per_rotation`): amounts
`bec8/beec/bed8/bedc/bee0` from injector temp multipliers (bde4/bde8/bdec) x
flow rates (be0c/be10/be14) x `6e7/rpm` x `tbl 0x6ac4c/360` x 369.472/475.93,
latency-compensated with be40/be44; ratios bee4/bee8 via
`rx8_divide_with_zero_fallback`.

Pulse arbitration (0x2fea8 `injector_pulse_time_arbitrate`): cranking
(!engine_running) uses `be30 = be38 = be5c + be44`, running
`be30 = be50 + be44`, `be38 = be54 + be44`; `be24 = be28 = (cranking? be58 :
be4c) + be40`; cranking decay counter be3c from tbl 0x6bab0 'Primary Fuel
Injector Cranking Pulse Decay Time'(coolant). `injector_pulse_time_ffffbe24`
is exported on PID 0x1410 (handler 0x56f6c, step 8.0 -> logger x*8 us).

## 3. Open/closed-loop target selection

- 0x1f0c4 `open_loop_request_condition` (already labeled in the knock pass):
  compares load/throttle against the 'Closed Loop Fuelling Threshold' tables
  (0x69d24/0x69d38/0x69d4c/0x69d60/0x69d74) with hysteresis flags
  b1b6/b1b7/b1b8 and timers -> open_loop_request b12a.
- 0x1ee30 `set_open_loop_flag`: open_loop_active b12c = (b12a != 0).
- 0x1ee4a `open_loop_fueling_targets`: when b12c==1 computes
  `b130 = max(baro base b170 * tip-in b190, OL target 3D b194)` and the
  coolant-implausible pair `b138 = max(rich-limit b174 * tip-in b198, b19c)`,
  with coolant corrections b134/b13c; final
  `open_loop_fuel_target b120 = b130*b134` (when b150 && coolant plausible)
  or `b138*b13c*b11c + (1-b11c)*b130*b134`. Zero in closed loop.
- 0x307e0 `closed_loop_fuel_trim`: when closed_loop_active ae1f,
  `beb4 = clamp((max(bf40, c01c+b0c4) + min(tbl 0x6ac38(coolant), b120) + 1)*ad ecc - 1, -1, 2)`,
  filtered (0.0625) into beb8. Zero in open loop.
- **Blend weights b11c/b118** (knock-review unresolved item 2, now resolved as
  to producer): 0x200c6 `blend_weight_update` sets both to 1.0 in normal
  conditions, decays them by 0.0667/call (0x3d888889) while open loop is
  active with the band flags set, and forces 0.0 on fault/safe-mode
  conditions (c590/cca1, coolant < -43, c644 > 1000). b118 blends the base
  ignition timing with the OL cap (0x11f00/0x1206c); b11c blends the
  implausible-coolant OL target branch (0x1ee4a). Exact semantic of the
  1.0-vs-decayed state (which side is "closed loop") is inferred from the
  consumers, not from a diagnostic readback.

## 4. Enrichments

| Function | RAM | Tables (RX8Defs names) |
|---|---|---|
| 0x32e08 warmup_fueling_compensation | c014/c018/c00c, flag c010 | 0x6ae28 load mult, 0x6ae3c warmup 3D, 0x6ae58/0x6ae74 speed-based (normal/fault) |
| 0x2024c open_loop_changeover_enrichment | b124 | 0x69e00 'Open Loop Changeover Enrichment'(RPM), gated by b146 |
| 0x33ec4 load_delta_enrichment | c134/c140 | 0x6b124 (load delta), 0x6b0c0 (load), 3D tip-in 0x6b160/0x6b17c |
| 0x1ddfc cold_start_enrichment | b0c4 | both branches store 0.0 in this ROM (candidate) |
| 0x30678 cranking_pulse_adder | be94 | adds be58 when cranking && injectors off && ce32 |
| 0x31624 ref_calculateSecondaryAirPumpEnirchment | — | secondary air pump enrichment (not re-reviewed this pass) |
| 0x2fd3e injector_temp_multiplier_lookup | bde4/bde8/bdec | 0x6a9a4/0x6a9c0/0x6a9dc weighted-engine-temp x load 3D |

## 5. Fuel cut / rev limit

- 0x18cfe `fuel_cut_rpm_condition`: hysteresis flags a97c (rpm >= 2500, clear
  < 1700) / a97d (>= 1700, clear < 1100); `fuel_cut_allowed a964 =
  (a96a && a97c) || (a96c && a97d)`.
- 0xedc4 `fuel_cut_arbitration`: sets fuel_cut_flag a444/a445 from requests
  a464/a465 and the mode param (band checks 0/12 vs 6/18), mirrors
  a4a2/a4a3, calls FUN_0000e2d4. (candidate: exact requester identity of
  a464/a465 not established.)
- 0xee82 `rev_limit_conditionals`: coolant_below_18c a4a6; rev-limit countdown
  a4ae (=0x0f on mode change) with a4aa/a4ad.
- 0xee64 `rev_limit_fuel_cut_init`: clears a4a4/a4a5/a4a8 when 9f8c==1.
- 0xe2a8 `update_injectors_off_flag`: engine_injectors_off a42c = 1 iff
  !engine_running && !a41c.
- 0xe560: off-throttle fuel-cut / fuel-resume base, tbl 0x68f48.

## 6. Diagnostics (logger PIDs)

| PID | Handler | Reads | Encoding |
|---|---|---|---|
| 0x0034 Air Fuel Ratio | 0x56b22 `diag_air_fuel_ratio` | aa6c (step 3.05e-05), aa7c (mult 0.0625, offset -96) | 2x u16 BE |
| 0x0043 Engine Load | 0x56b8a `diag_engine_load` | engine_load c0b4 | step 1/255, u16 BE |
| 0x0044 Lambda Target | 0x56b9e `diag_lambda_target` | lambda_target adfc | step 3.05e-05, u16 BE |
| 0x1410 Injector Pulse Time | 0x56f6c `candidate_diag_injector_pulse_time` | injector_pulse_time be24 | step 8.0 (us) |

**Def caveat:** logger def assigns 0x221410 to both "Injector Pulse Time"
(x*8 us) and "Throttle Pedal Position" (x*0.392 %) — a real conflict in
`RX8Defs/RomRaider/logger_rx8_defs.xml`. The handler encoding (step 8.0)
matches the pulse-time conversion, so the firmware side supports
"Injector Pulse Time", but the def entry needs repair (candidate, not fixed
here — upstream repo).

## 7. Labeling applied in this pass

- **39 functions** in `source_review/accepted_function_aliases.tsv`
  (33 high confidence; 6 medium -> `candidate_` prefix in the integrated
  views: `candidate_injector_pulse_set_dispatch`,
  `candidate_injector_zero_offset_set`, `candidate_injection_angle_limit_lookup`,
  `candidate_fuel_cut_arbitration`, `candidate_fuel_cut_rpm_condition`,
  `candidate_rev_limit_conditionals`, `candidate_cold_start_enrichment`,
  `candidate_maf_voltage_and_fault_counters`, `candidate_maf_filtered_update`,
  `candidate_maf_per_rotation_calc`, `candidate_diag_injector_pulse_time`,
  `candidate_diag_afr_word_a/b`).
- **151 RAM locations** in `source_review/accepted_ram_aliases.tsv`
  (integrated as `<alias>_<address>`; snapshot locals renamed by the
  post-integration pass, 234 occurrences).
- **1 lookup table** in `source_review/accepted_lookup_aliases.tsv`:
  `DAT_0006ac38` -> `tbl_fuel_coolant_compensation_0006ac38` (dataflow
  hypothesis; descriptor not matched to an RX8Defs table).
- Pipeline: `scripts/review_fueling_labels.py` (idempotent TSV append, wired
  into `scripts/rebuild.sh` after `review_knock_loop_labels.py`; writes
  `metadata/fueling_labels.json`). Pre-change backup:
  `backups/pre_fueling_labels.zip`.

## 8. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256
  `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`
  verified, 3,355 function files linked, 168,592 instructions byte-verified
  against the ROM, 1,833 exact reference matches. See `validation.json`.
- `scripts/verify_readability.py` — pass: all 3,355 function bodies
  consistent between per-function files and the combined C.
- `scripts/verify_math_units.py` — pass.
- Spot re-checks against the disassembly/defs are in [`REVIEW_NOTES.md`](REVIEW_NOTES.md).

## 9. Unresolved items

1. Writers of the adder inputs into `fuel_correction_sum` bf14: b0d0, c0c8,
   ae08, b21c, c104, cde0, ae10 — not traced in this pass.
2. `DAT_ffffadec` (lambda controller gain?) read in 0x306e8/0x307e0;
   `DAT_ffffc644` (>1000 gates blend weights); `DAT_ffffc590`/`cca1` fault
   flags; `DAT_ffffce32/ce33`; `DAT_ffffb228` trim mode; `DAT_ffffb146`
   changeover-enrichment gate — writers not identified.
3. Injector channel index -> harness terminal mapping (2M/2J/2G/2D/3A/3D)
   unresolved (wiring review note in 0x85e4).
4. Fuel-cut requesters of a464/a465 and the 0x4e27c/0x4e2c8 tables in
   0xf960 `ref_somethingFuelCutRelated` — candidate only.
5. The task-record dispatch at ROM 0x4ab8 (0x64e8) and the 0x4998 table
   pointer remain unresolved (carried over from the knock review).
6. `FUN_0005c024` (applied to bf14) reads the diagnostic area
   (0xffffd3xx) — its exact transform is not identified; treated as a
   scaler pass-through.
7. Static analysis only: no execution; scheduling order and real injection
   behavior unmeasured. `candidate_` names are unproven hypotheses.

## 10. Sources

Canonical export (`decompiled/`), SH disassembly
(`decompiled/firmware_disassembly.asm`), the untouched ROM
(`Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`),
RX8Defs descriptor matches (`cross_ecu/romraider_descriptor_matches.json`),
logger matches (`cross_ecu/romraider_logger_matches.json`), the logger def
conflict (`RX8Defs/RomRaider/logger_rx8_defs.xml` 0x221410), wiring
(`hardware/pcm_connections.tsv`), and the knock review
([`reviews/knock_control/README.md`](../knock_control/README.md), whose loop-mode findings this pass
builds on).
