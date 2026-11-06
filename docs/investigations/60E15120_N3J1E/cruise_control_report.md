# Cruise control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`reverse-engineered/decompiled/60E15120_N3J1E/`), the disassembly and the raw ROM
bytes. No hardware execution was performed. Labels recorded in
`data/labels/60E15120_N3J1E/large_control_bodies_labels.json`.

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
(1,444 B, called from slow-task batch 0x2e5c6) is the **set-speed adjustment
integrator**: it ramps 0xffffbd08 within [0,100] up/down by 3-D tables
(0x6a8d0–0x6a920, axes speed 20–200 km/h × band 2–6) selected by bands of
0xffffcf1c via 2-D tables 0x6a880–0x6a8b0, gated on the cruise switch flags and
an 8.0 delta; 0x2df62 folds it into the set speed
(0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100)).

## 1a. Plain-language summary

Cruise control has two halves here. One half (0x4ca7e) watches the cruise buttons
and works out "how far off the set speed are we, really" — filtering the raw
error and adding a correction that depends on road speed and which button is
held. The other half (0x2d83c) slowly winds the set speed up or down while you hold
ACCEL/RESUME or SET/COAST, using richer tables at higher speed, and the result is
clamped to 0–100 and stored as the active set speed.

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

RAM aliases: `cruise_switch_code` (0xffffbaed), `cruise_set_speed` (0xffffbcf8),
`cruise_set_speed_adjust` (0xffffbd08), `cruise_filtered_speed_error`
(0xffffcef4), `cruise_speed_error_mean12` (0xffffcee4). Evidence:
`source_review/accepted_{function,ram}_aliases.tsv`,
`data/labels/60E15120_N3J1E/large_control_bodies_labels.json`.

## 5. Corrections made in this pass

None — the bodies were unlabeled `FUN_`. The inherited `ref_cruise*` labels
(0x2be18, 0x2c5d0, 0x2d45c, 0x2d520, 0x2e0e8, 0x32104, 0x32326, 0x32378, 0x320c6)
were left untouched; they remain unverified hypotheses.

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0004ca7e_*.c`,
  `0002d83c_*.c`, `0004c828_*.c`, `0002df62_*.c` (symbol renamed in place;
  filenames keep the `FUN_` prefix)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/large_control_bodies_labels.json`

## 7. Validation

- Binary-level: call sites (jsr via pool 0x2e7dc at 0x2e6c6; pool 0x2e790 at
  0x2e63c; 0x11744 → 0x2e692; slow task 0x11534 → 0x2e5c6; task table rec[10]
  entry 0x64f6 at ROM 0x4a38, rec[18] 0x64e8 at 0x4ab8), all listed descriptors
  parsed from ROM, 3.2f located at 0x7d0c8/0x7d0cc via pointer pools 0x4ce14/0x4ce1c,
  8.0/2.0–6.0 band constants, clamp [0,100] in 0x2df62. Scripted checks 62/62 PASS.
- `validate_reports.py` / `verify_claims.py` / `validate_export.py` from repo
  root; `tests/test_large_control_bodies.py`.

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
| 0x0004dce8 / 0x0004d4a6 / 0x0004d700 | `FUN_0004dce8` / `FUN_0004d4a6` / `FUN_0004d700` | mean-of-12, min/max track, threshold compare |
| 0x00011744 | `FUN_00011744` | task[10] body (entry 0x64f6) |
| 0x00011534 | `slow_background_task` | task[18] body (entry 0x64e8) |

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

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffbaed | `cruise_switch_code` | switch enum 1–6 |
| 0xffffcf47–0xffffcf4c | `DAT_ffffcf47`–`DAT_ffffcf4c` | decoded switch flags |
| 0xffffbcf8 | `cruise_set_speed` | set speed (clamp target) |
| 0xffffbd08 | `cruise_set_speed_adjust` | integrator output [0,100] |
| 0xffffcee4 | `cruise_speed_error_mean12` | mean of 12-sample ring |
| 0xffffcef4 | `cruise_filtered_speed_error` | filtered error + offset |
| 0xffffbfa0 / 0xffffbfac | `DAT_ffffbfa0` / `DAT_ffffbfac` | filtered vehicle speed pair (3.2f tolerance) |
| 0xffffbcfc / 0xffffbcfd | `DAT_ffffbcfc` / `DAT_ffffbcfd` | accel/decel active flags |

## 9. Limits

- Static analysis only. The split of responsibilities between 0x4ca7e (error
  shaping) and 0x4d4a6/0x4d700 (plausibility) is from dataflow; the exact control
  law that consumes 0xffffcf51–0xffffcf5b downstream is not fully traced here.
- 0xffffcf1c (band 2–6 selector) is read but its producer is not identified in
  this pass (likely gear/speed band; upstream hypothesis `ref_cruiseControlStateStuff`
  0x2e0e8).
- Whether 0xffffbcf8 is km/h or percent is inferred from the [0,100] clamp and the
  20–200 km/h table axes; not proven against a scanner PID in this pass.
