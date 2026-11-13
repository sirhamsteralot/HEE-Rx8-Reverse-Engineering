# Cruise control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). Findings are from static analysis of the canonical export
(`reverse-engineered/decompiled/60E15120_N3J1E/`), the disassembly and the raw ROM
bytes, plus emulator harness-call validation (no hardware execution) recorded in
[`reviews/cruise_control/dynamic_validation_log.txt`](reviews/cruise_control/dynamic_validation_log.txt).
Labels recorded in
`data/labels/60E15120_N3J1E/cruise_control_labels.json`.

**Related reports:** task table and task[10]/slow-task structure in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); vehicle
speed producer chain `ref_filterVehicleSpeed` 0x320c6 and switch-voltage reader
`ref_calculateCruiseControlSwitchVolt` 0x2be18 (inherited `ref_` labels — unverified hypotheses); DTC engine in [`dtc_control_report.md`](dtc_control_report.md);
fuel-cut/arbitration interacting with cruise in
[`fueling_control_report.md`](fueling_control_report.md).

## 1. Executive summary

Two of the seven large unlabeled bodies belong to **cruise
control**: **0x4ca7e** (2,200 B) is the per-run cruise stage inside batch 0x2e692 —
it debounces the decoded cruise-switch flags (0x4c828 maps switch code
0xffffbaed, values 1–6, to flags 0xffffcf47–0xffffcf4c), filters the 12-sample
mean speed error (ring 0xffffceb4–0xffffcedc → 0xffffcee4, clamped ±15) and adds
a per-switch, vehicle-speed-indexed offset (2-D tables 0x6bc40–0x6bc70) to produce
the filtered error 0xffffcef4; downstream 0x4d4a6/0x4d700 track per-channel
min/max and compare against more vss tables (0x6bbe0–0x6bc34). **0x2d83c**
(1,444 B, called from slow-task batch 0x2e5c6) is the **output adjustment
integrator**: it ramps 0xffffbd08 within [0,100] up/down by 3-D tables
(0x6a8d0–0x6a920, axes speed 20–200 km/h × band 2–6) selected by bands of
0xffffcf1c via 2-D tables 0x6a880–0x6a8b0, gated on the cruise switch flags and
an 8.0 delta; 0x2df62 folds it into the cruise output
(0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100) — a **percent** demand,
see below). The follow-up pass pinned the rest of the loop: the **set speed in
km/h** is latched by 0x32614 into the learned readValue cell **0xffff866c**
(clamp [27, 200] km/h, floor 27.0) with target **0xffffbfa4**; the band
selector **0xffffcf1c = float(current gear 0xffffbc3d)** is produced by
**0x4de1c** (gear chain 0x2c324 rpm/vss ratio → 0x2c3b2 latch); the control law
**0x2d638** computes 0xffffbd00 = clamp(bd04·bd18·0.01, ±100) from gear-band
tables × speed error (0xffffbfa0 − 0xffffbfa4); **0x4c896** sets the enable
flag 0xffffcf34 = cruise_on && bcf8 ≥ TP% 0xffffa9b4 (pedal override); 0x193c4
mixes demand 0xffffa9bc = min(max(TP% 0xffffa9b4, bcf8), limiter 0xffffc028),
which 0x228dc maps through the pedal→throttle-plate tables.

## 1a. Plain-language summary

Cruise control has two halves here. One half (0x4ca7e) watches the cruise buttons
and works out "how far off the set speed are we, really" — filtering the raw
error and adding a correction that depends on road speed and which button is
held. The other half runs in the slow task: 0x32614 remembers the speed you set
(in km/h, in a learned cell), 0x2d638 turns the speed error into a throttle-style
output in percent using tables picked by the current gear, and 0x2df62 clamps
that output to 0–100 %. If you press the accelerator harder than the cruise
output, the cruise lets go (pedal override).

## 2. How it works (condensed pseudocode)

```
# batch 0x2e692 (called from task[10] body 0x11744); mask raise 0x3920 ... tail 0x3934
0x4c828: cf47..cf4c = (0xffffbaed == 1..6)          # cruise_switch_code_decode
0x4c896: cf18 = 0xffffbcf8;  cf34 = (bced && bcf8 >= vehicle_speed 0xffffa9b4)
0x4dce8: shift ring ceb4..cedc; cee4 = sum(12 samples)/12     # cruise_speed_error_mean12
0x4ca7e: cruise_speed_error_filter_stage:
    debounce cf47..cf4c (62 counts) -> cf5c..cf63
    cee8 = clamp(cee4, -15, 15); ceec/cef0 = filter(ceec, 0.1)
    cfe4 = cef0 + lookup_2d(vss 0xffffbbb4, tbl 0x6bc40..0x6bc70)[selected switch]
    3.2f tolerance (0x404ccccd @0x7d0c8/0x7d0cc via ptr pools 0x4ce14/0x4ce1c)
    vs 0xffffbfa0/0xffffbfac; latch per-switch flags cf3a..cf40
0x4d4a6: per-channel min/max of cfe4 -> cef8/cf00/cf08/cf10; max with tbl 0x6bbe0.. -> cfefc/cf04/cf0c/cf14
0x4d700: cfe4 vs (channel max + 1.5) and vss tbl 0x6bbec/0x6bc04/0x6bc1c/0x6bc34 -> flags cf51..cf5b

# slow task 0x11534 -> batch 0x2e5c6 (jsr via pool 0x2e790 at 0x2e63c)
0x2d83c: cruise_set_speed_adjust_integrator:
    bd1c = bfa0 - bfa4;  if bd3e && (|bd1c| >= 8.0 or bccc < 1.0): bd10++
    bd20 = bd10 * 1.0 (affine)
    bd24/bd28/bd2c/bd30 = lookup_3d(bfa0 or bfa4, cf1c, tbl 0x6a8d0/0x6a8e4/0x6a8f8/0x6a90c)
    bd34 = lookup_3d(bd20, cf1c, tbl 0x6a920)
    band = cf1c in [2.0,3.0,4.0,5.0,6.0] -> 2-D ramp tbl 0x6a880..0x6a8b0 -> bd0c
    bd08 = clamp(bd08 +/- bd28/bd2c, 0, 100) or bd08 + bd0c*bd30*bd34*0.0001
    on accel/decel: set flags 0xffffbcfc / 0xffffbcfd
0x2df62: cruise_set_speed_apply: if (bced && bd3e) bcf8 = clamp(bd00 + bd08, 0, 100)

# follow-up pass: set speed (km/h), gear band, control law, output demand
0x2c324: candidate_gear_from_ratio: bc3c = gear from rpm 0xffffb548 < vss 0xffffbbb4 * {110.741, 71.887, 52.001, 40.158, 33.841}
0x2c3b2: gear_latch_confirm: bc3d = 0 if neutral 0xffffb53a else bc3c after >0xb counts
0x4de1c: gear_float_band_producer: cf1c = float(bc3d)   # ROM cfg byte 0x7d07f = 0 selects this
0x32614: cruise_set_speed_latch: 866c = clamp(vss_or_button_adjust, 27, 100/200) km/h (learned readValue); bfa4 = clamp(target, 27, bfac)
0x2d638: cruise_control_output_law: bd00 = clamp(bd04*bd18*0.01, -100, 100) from gear-band tbls x (bfa0-bfa4)
0x4c896: cruise_enable_pedal_override: cf18 = bcf8; cf34 = bced && (bcf8 >= TP% 0xffffa9b4)
0x193c4: throttle_percent_and_demand_calc: a9b4/a9b8 = TP1/TP2 % (clamp [0,100]); a9bc = min(max(a9b4, bcf8), c028)
0x228dc: ref_calculateThrottlePedalPositionMapBased: throttle-plate request = 3-D tbl(rpm, a9bc) clamp [0,84] -> 0xffffb398
```

## 3. Key calibrated tables

| Descriptor | Dims | Axes (ROM-verified) | Role |
|---|---|---|---|
| 0x6bc40–0x6bc70 | 10 × f32 | vss 0–200 km/h (ax 0x7d368–0x7d4a8, data 0x7d390–0x7d4d0) | per-switch error offsets (0x4ca7e) |
| 0x6bbe0–0x6bc34 | 2-D | vss | min/max + threshold tables (0x4d4a6/0x4d700) |
| 0x6a8d0 / 0x6a8e4 / 0x6a8f8 / 0x6a90c / 0x6a920 | 3-D | x speed 20–200 km/h @0x77198, y band 2–6 @0x771c0, data 0x771d4+ | set-speed ramp/step tables (0x2d83c) |
| 0x6a880–0x6a8b0 | 31 × f32 | delta 0xffffbd1c (ax 0x76bd4–, data 0x76c50–0x77030) | band-selected 2-D ramps (0x2d83c) |

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x4ca7e | `cruise_speed_error_filter_stage` | high |
| 0x2d83c | `cruise_set_speed_adjust_integrator` | high |
| 0x4c828 | `cruise_switch_code_decode` | high |
| 0x2df62 | `cruise_set_speed_apply` | high |
| 0x4de1c | `gear_float_band_producer` | high |
| 0x2c324 | `candidate_gear_from_ratio` | high |
| 0x2c3b2 | `gear_latch_confirm` | high |
| 0x32614 | `cruise_set_speed_latch` | high |
| 0x193c4 | `throttle_percent_and_demand_calc` | high |
| 0x2d638 | `cruise_control_output_law` | high |
| 0x4c896 | `cruise_enable_pedal_override` | high |
| 0x4d700 | `cruise_switch_plausibility_timers` | high |
| 0x4db22 | `cruise_plausibility_stage` | medium |

RAM aliases: `cruise_switch_code` (0xffffbaed), `cruise_output_percent`
(0xffffbcf8), `cruise_output_integrator` (0xffffbd08),
`cruise_control_law_output` (0xffffbd00), `cruise_filtered_speed_error`
(0xffffcef4), `cruise_speed_error_mean12` (0xffffcee4), `current_gear_float`
(0xffffcf1c), `current_gear` (0xffffbc3d), `candidate_gear` (0xffffbc3c),
`throttle_position_1_percent` (0xffffa9b4), `throttle_position_2_percent`
(0xffffa9b8), `cruise_set_speed_kmh` (0xffff866c),
`cruise_target_speed_kmh` (0xffffbfa4), `cruise_enable_flag` (0xffffcf34).
Evidence: `labeling/source_review/accepted_{function,ram}_aliases.tsv`,
`data/labels/60E15120_N3J1E/cruise_control_labels.json`,
[`reviews/cruise_control/`](reviews/cruise_control/README.md).

## 5. Corrections made in this pass

- **0xffffbcf8 was mislabeled `cruise_set_speed`** — it is the cruise **output
  demand in percent** (clamp [0,100] in 0x2df62), compared against TP1 percent
  0xffffa9b4 for the pedal-override enable flag and mixed into demand
  0xffffa9bc by 0x193c4. The set speed in km/h is the learned cell **0xffff866c**
  (0x32614, clamp [27,200], floor 27.0 — matching the 27 km/h cruise-minimum gate
  in 0x2d520). Corrected in the label TSV/JSON; the export symbol
  `cruise_set_speed_ffffbcf8` is renamed by the next re-runnable pipeline pass.
- **0xffffa9b4 was described as "vehicle speed"** in the earlier cruise
  evidence — it is **TP1 percent** (AN4 raw 0xffff9eec → 0x94f0 → 0x18f60 →
  0x1933a → 0x193c4, learned zero 10.856 / span 12.7). Vehicle speed is
  0xffffbbb4 (PID 0x0D, km/h) / filtered 0xffffbfa0. Emulator: AN4 50% →
  a9b4 = 39.27, 75% → 100.
- The inherited `ref_cruise*` labels
  (0x2be18, 0x2c5d0, 0x2d45c, 0x2d520, 0x2e0e8, 0x32104, 0x32326, 0x32378, 0x320c6)
  were left untouched; they remain unverified hypotheses.

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0004ca7e_*.c`,
  `0002d83c_*.c`, `0004c828_*.c`, `0002df62_*.c` (symbol renamed in place;
  filenames keep the `FUN_` prefix)
- `docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/cruise_control_labels.json`
- [`reviews/cruise_control/`](reviews/cruise_control/README.md) — dynamic
  validation script + log
- `tests/test_cruise_control.py`, `tests/test_cruise_control_dynamic.py`

## 7. Validation

- Binary-level: call sites (jsr via pool 0x2e7dc at 0x2e6c6; pool 0x2e790 at
  0x2e63c; 0x11744 → 0x2e692; slow task 0x11534 → 0x2e5c6; task table rec[10]
  entry 0x64f6 at ROM 0x4a38, rec[18] 0x64e8 at 0x4ab8), all listed descriptors
  parsed from ROM, 3.2f located at 0x7d0c8/0x7d0cc via pointer pools 0x4ce14/0x4ce1c,
  8.0/2.0–6.0 band constants, clamp [0,100] in 0x2df62 (ptr pools 0x2e048→0x767e4
  = 100.0, 0x2e04c→0x767e0 = 0.0). Scripted checks 62/62 PASS.
- Follow-up pass binary level: literal-pool word scan of the full disassembly +
  raw ROM for every touched cell (0xffffcf1c: 3 sites — 0x2d658/0x2d86c readers,
  0x4de24 writer; 0xffffcf51–0xcf5b: only inside 0x4ca7e/0x4d4a6/0x4d700;
  0xffffbcf8: 7 sites; 0xffffbc3d/bc3c, 0xffffa9b4, 0xffff866c, 0xffffbfa4 all
  enumerated in [`reviews/cruise_control/README.md`](reviews/cruise_control/README.md));
  0x4de1c pools 0x4dedc = 0xcf1c/0xbc3d, 0x4def4 = 0x7d07f, ROM[0x7d07f] = 0x00,
  0x4def8 = 0x2500, band floats 0x4defc–0x4df08; 0x2c324 ratio thresholds at
  ROM 0x758b8–0x758c8; TP% constants ROM 0x6eeb8 = 6.341, 0x6ef18 = 12.7,
  0x6ef00 = 10.856; call-site pools 0x2e748/0x2e77c/0x2e78c/0x2e7c8/0x2e7e4/0x2e7e8,
  0x19c84/0x19c88. Scripted checks in `tests/test_cruise_control.py`.
- Dynamic (emulator, no hardware): [`reviews/cruise_control/dynamic_validation_log.txt`](reviews/cruise_control/dynamic_validation_log.txt)
  — 0x4de1c maps gear 0–6 → cf1c 0.0–6.0 regardless of switch flags; gear
  chain 0x2c324/0x2c3b2 (ratio 71.9 → gear 2, neutral → 0); 0x4c896 pedal
  override (bcf8 50 < TP% 80 → cf34=0; 90 → 1); 0x193c4 a9bc = 70 from
  TP%=30/bcf8=70/c028=100; 0x32614 latches 80→80.0, 250→200.0, 10→27.0 km/h
  into 0xffff866c; AN4 50% → a9b4 = 39.27 %; 0x2d638 → bd00 = −23.93.
  Mirrored as pytest cases in `tests/test_cruise_control_dynamic.py` (9 passed).
- `validate_reports.py` / `verify_claims.py` / `validate_export.py` from repo
  root; `tests/test_cruise_control.py` + `tests/test_cruise_control_dynamic.py`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0004ca7e | `cruise_speed_error_filter_stage` | debounce + filtered speed error + vss offset |
| 0x0002d83c | `cruise_set_speed_adjust_integrator` | set-speed ramp integrator [0,100] |
| 0x0004c828 | `cruise_switch_code_decode` | switch code 0xffffbaed → flags cf47–cf4c |
| 0x0002df62 | `cruise_set_speed_apply` | folds adjust into 0xffffbcf8 |
| 0x0002e692 | `FUN_0002e692` | cruise batch in task[10] body 0x11744 |
| 0x0002e5c6 | `FUN_0002e5c6` | batch in slow task 0x11534 (calls 0x2d83c) |
| 0x0004dce8 / 0x0004d4a6 / 0x0004d700 | `FUN_0004dce8` / `FUN_0004d4a6` / `FUN_0004d700` (cruise_switch_plausibility_timers) | mean-of-12, min/max track, threshold compare |
| 0x00011744 | `FUN_00011744` | task[10] body (entry 0x64f6) |
| 0x00011534 | `slow_background_task` | task[18] body (entry 0x64e8) |
| 0x0004de1c | `gear_float_band_producer` | cf1c = float(gear 0xffffbc3d); jsr 0x2e5d2 (pool 0x2e748) in 0x2e5c6 |
| 0x0002c324 | `ref_calculateGearRPMbased` (candidate_gear_from_ratio) | gear from rpm/vss ratio; jsr 0x19ad6 (pool 0x19c84) in 0x19aa0 |
| 0x0002c3b2 | `gear_latch_confirm` | gear latch; jsr 0x19adc (pool 0x19c88) in 0x19aa0 |
| 0x00032614 | `cruise_set_speed_latch` | set speed km/h → 0xffff866c, target → 0xffffbfa4; jsr 0x2e620 (pool 0x2e77c) |
| 0x0002d638 | `cruise_control_output_law` | bd00 = clamp(bd04·bd18·0.01, ±100); jsr 0x2e638 (pool 0x2e78c) |
| 0x0004c896 | `cruise_enable_pedal_override` | cf18 = bcf8; cf34 = bced && bcf8 ≥ TP%; jsr 0x2e6a4 (pool 0x2e7c8) |
| 0x000193c4 | `throttle_percent_and_demand_calc` | TP1/TP2 %, demand a9bc; jsr 0x19a46 (pool 0x19c30) in 0x199d4 |
| 0x0004db22 | `cruise_plausibility_stage` | cf35–38 staging; jsr 0x2e6da (pool 0x2e7e8) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x6bc40–0x6bc70 | 2-D vss offset descriptors (0x4ca7e) |
| 0x6bbe0–0x6bc34 | 2-D vss min/max + threshold descriptors |
| 0x6a880–0x6a8b0 | 2-D band ramps (n=31) |
| 0x6a8d0–0x6a920 | 3-D speed × band ramp/step descriptors |
| 0x2e7dc / 0x2e790 | pool words = 0x4ca7e / 0x2d83c |
| 0x7d0c8 / 0x7d0cc | shared float pool: 3.2f (0x404ccccd) |
| 0x4990 + 10*16 + 8 | task table rec[10].entry = 0x64f6 |
| 0x4dedc–0x4df08 | 0x4de1c pools: cf1c/bc3d, cfg 0x7d07f, 0x2500, band floats 3.0–6.0 |
| 0x758b8–0x758c8 | 0x2c324 gear-ratio thresholds 110.741/71.887/52.001/40.158/33.841 |
| 0x6eeb8 / 0x6eec0 / 0x6ef00 / 0x6ef18 | TP% constants: 6.341, 0.0, 10.856, 12.7 |
| 0x767e0 / 0x767e4 | 0.0 / 100.0 clamp bounds (ptr pools 0x2e04c/0x2e048 of 0x2df62) |
| 0x7d07f | config byte = 0x00 (selects gear decode in 0x4de1c) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffbaed | `cruise_switch_code` | switch enum 1–6 |
| 0xffffcf47–0xffffcf4c | `DAT_ffffcf47`–`DAT_ffffcf4c` | decoded switch flags |
| 0xffffbcf8 | `cruise_output_percent` | cruise output demand % (clamp [0,100]) — NOT km/h |
| 0xffffbd00 | `cruise_control_law_output` | control law 0x2d638, clamp ±100 |
| 0xffffbd08 | `cruise_output_integrator` | integrator output [0,100] |
| 0xffffcee4 | `cruise_speed_error_mean12` | mean of 12-sample ring |
| 0xffffcef4 | `cruise_filtered_speed_error` | filtered error + offset |
| 0xffffcf51–0xffffcf5b | `DAT_ffffcf51`–`DAT_ffffcf5b` | per-switch plausibility countdown timers (0x4d700) |
| 0xffffcf34 | `cruise_enable_flag` | bced && bcf8 ≥ TP% (0x4c896) |
| 0xffffcf1c | `current_gear_float` | float(gear 0xffffbc3d) by 0x4de1c; bands 2–6 = gears 2–6 |
| 0xffffbc3c / 0xffffbc3d | `candidate_gear` / `current_gear` | rpm/vss ratio candidate / latched gear (0=neutral) |
| 0xffffa9b4 / 0xffffa9b8 | `throttle_position_1/2_percent` | TP1/TP2 % (AN4/AN5), learned zero 10.856 / span 12.7 |
| 0xffff866c | `cruise_set_speed_kmh` | learned set speed, km/h, clamp [27,200] (0x32614) |
| 0xffffbfa4 | `cruise_target_speed_kmh` | cruise target km/h (0x32614) |
| 0xffffbfa0 / 0xffffbfac | `DAT_ffffbfa0` / `DAT_ffffbfac` | filtered vehicle speed pair (3.2f tolerance) |
| 0xffffbcfc / 0xffffbcfd | `DAT_ffffbcfc` / `DAT_ffffbcfd` | accel/decel active flags |

## 9. Limits

- The three open questions from the earlier pass are now resolved (evidence in
  [`reviews/cruise_control/`](reviews/cruise_control/README.md)):
  - **0xffffcf1c producer**: 0x4de1c writes float(current gear 0xffffbc3d);
    the compiled-in switch-code band alternative is disabled by config byte
    ROM[0x7d07f] = 0x00 on this ROM. Gear chain: 0x2c324 (rpm/vss ratio
    thresholds 110.741/71.887/52.001/40.158/33.841 rpm per km/h, gated on AT
    flag 0xffffb534 and neutral 0xffffb53a) → 0x2c3b2 (latch after >0xb
    confirmation counts) → 0x4de1c. The bands 2.0–6.0 in the 0x2d83c/0x2d638
    tables are gears 2–6. Emulator-verified (gear 0–6 → cf1c 0.0–6.0, switch
    flags have no effect).
  - **0xffffcf51–0xffffcf5b downstream**: these are per-switch countdown
    timers inside 0x4d700, referenced *only* within the cruise cluster
    (0x4ca7e/0x4d4a6/0x4d700 — pool scan over the full disassembly + ROM).
    Their expiry clears latches 0xffffcf3a/3c/3e/40, staged by 0x4db22 into
    0xffffcf35–38 (vss < 300 gate) and consumed by 0x4ca7e's reload of
    0xffffcf50/53/56/59 — a self-contained plausibility watchdog in batch
    0x2e692. The actuator-side law is the slow-task batch 0x2e5c6:
    0x32614 → 0x2d638 → 0x2d83c → 0x2df62 → 0x193c4 → 0x228dc (§2).
  - **0xffffbcf8 units**: percent (0–100), not km/h — proven by the clamp in
    0x2df62, the comparison with TP1 % 0xffffa9b4 in 0x4c896 (emulator:
    bcf8=50 < TP%=80 → cf34=0; 90 → 1), and the mix a9bc = min(max(a9b4,
    bcf8), c028) in 0x193c4 (emulator: TP%=30, bcf8=70, c028=100 → a9bc=70).
    The set speed in km/h is 0xffff866c (0x32614; emulator 80→80.0, 250→200.0,
    10→27.0 km/h). No Mode 22 PID exposes 0xffffbcf8 directly (only PID 0xa216
    = cruise switch volts), so the scanner-PID cross-check is not available.
- Static + emulator-harness analysis only; no hardware execution. The export
  symbol `cruise_set_speed_ffffbcf8` still carries the old name until the next
  re-runnable pipeline pass renames it to `cruise_output_percent`.
