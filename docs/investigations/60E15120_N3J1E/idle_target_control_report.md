# Idle target RPM calculation report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/idle_target_control_labels.json`.

**Related reports:** task structure and task[10] in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); the
idle task entry `idle_control_calc_batch` 0x167c0 (this report identifies
its largest inner body 0x1506c; see [`idle_control_report.md`](idle_control_report.md));
coolant/IAT scaling (0x7298/0x73a0);
alternator load interaction via `ref_alternatorControl` 0x2680e in the same task.

## 1. Executive summary

**0x1506c** (1,530 B) is the **idle target RPM calculation**
inside the idle-control batch `idle_control_calc_batch` 0x167c0 (itself
called from task[10] body 0x11744; task table rec[10] entry 0x64f6 at ROM
0x4a38). It filters battery voltage (0xffffa7c8, factor 0.03125, gates at 13.016
and 12.0 V), tracks engine-running/cranking timers, selects between open-loop
ramp (0x15818, floor 500 rpm, tbl 0x69384) and running modes (0x15934, tbl
0x693c0), picks a base target from the coolant-indexed "Idle Target" tables
(descriptors 0x69370 base / 0x693d4 F / 0x693e8 G / 0x693fc H / 0x69410 vehicle
moving-AT) with hard floors of 500 and 790–840 rpm, takes the max of the
candidates, applies a first-order filter whose factor comes from tbl 0x6935c, and
writes the **idle target rpm to 0xffffa7f4**, which `idle_target_encode_u16` 0x5ca94 converts to the
actuator output.

## 1a. Plain-language summary

When the engine is idling, the PCM decides how fast it should idle: higher when
cold (the table says 1700 rpm at −40 °C down to 810 rpm at 80 °C), adjusted for
air conditioning and electrical load, never below 500 rpm, and smoothed by a
filter so the target doesn't jump around. That number (0xffffa7f4) is what the
idle air control then chases.

## 2. How it works (condensed pseudocode)

```
# idle_control_calc_batch 0x167c0 (task[10] body 0x11744) calls ... 0x1506c (jsr pool 0x168ac at 0x167fa) ...
# idle_target_rpm_calculate 0x1506c:
a7c8 = filter(battery_voltage 0xffffb590, a7c8, 0.03125)      # V
# engine-running gates: a804/a806/a808 counters, a818/a81a decay (0x753/0x271), a7b7 latch
if b534 (`automatic_transmission` 0xffffb534, AT?) : 15818(coolant 0xffffa990)  -> a7e0/a7d8/a7dc open-loop ramps (floor 500, tbl 0x69384)
else           : 15934(...)               -> cranking vs running (tbl 0x693c0)
a800 = lookup_2d(coolant, tbl 0x69370 base | 0x693d4 F | 0x693e8 G | 0x693fc H | 0x69410 vmoving-AT)
a7d4 = target base (floors 500.0 / 790-840 rpm by flags bd69/bdb8/b5b3/b53c)
a7b0 = max(a800, a7cc, a7d4)
a7bc = (a81c==0) ? lookup_2d(a7b0 - a7ac, tbl 0x6935c filter factor) : 1.0   # a7ac = `inferred_ram_a7ac_ffffa7ac` 0xffffa7ac
a7f4 = filter(a7b0, a7ac, a7bc)          # -> idle_target_rpm; min 850 if a7b7
out = idle_target_encode_u16(a7f4)       # 0x5ca94: u16 @0.25 rpm/LSB -> `inferred_ram_a7ac_ffffa7ac` 0xffffa7ac (PID 0x096e)
```

### 2a. Select-flag producers and the 0x5ca94 output path (traced this pass)

The five mode-select flags read by 0x1506c now have verified producers
(disassembly pool words + decompiled bodies):

| Flag | Producer (verified) | Meaning |
|---|---|---|
| 0xffffb534 `automatic_transmission` | `ref_getAutoTransCal__` 0x24b44 copies the AT calibration byte at ROM 0x74924 into it (cal byte read at 0x24b46 via pool 0x24b60 = 0x74924; `mov.b r0,@r4` at 0x24b54 when nonzero, `mov.b r1,@r4` at 0x24b58 when zero; pool 0x24b5e = 0xb534; ROM 0x74924 = 0x00 on this ROM → MT); called from 0x19624/0x19da2 | automatic-transmission calibration flag (1 = AT) — selects the 0x15818 open-loop ramp vs the 0x15934 running path and the 0x69370 base vs vehicle-moving tables |
| 0xffffb53c | `FUN_00024b8c`: = 1 when 0xffffb540 or 0xffffb53e (pool 0x24c5a @0x24bdc, write 0x24bde; pool 0x24e54 @0x24e36, write 0x24e38); 0 when AT (0x24b8c clears it when b534==1) | AT drive-range engaged / vehicle-moving conditional, derived from the CAN 0x231 gear byte (0xffffbaec = 0xffffbae5 >> 4, `ref_can231TxPack` 0x290c6), vehicle speed and rpm |
| 0xffffb5b3 `high_load_flag` | 0x264f0 `electrical_load_flag_calc`: = 1 when filtered electrical load 0xffffb5e0 >= 40.0, 0 below 30.0 (pool 0x265f0 @0x265b0, write 0x265ce); called from `ref_alternatorControl` 0x2680e | high electrical (alternator) load flag |
| 0xffffbd69 `ac_clutch_on` | `FUN_0002e9a4` sets it under a gating chain (engine-running timer 0xffffa424, injectors-off 0xffffa42c, rpm < 7800, coolant < 118 °C, flags bd72/bd73/bd76/bd92/bd96/bd97/bd98/0xffffc5e6) — pool 0x2eb58 = 0xbd69 @0x2ea70 | A/C compressor clutch engaged |
| 0xffffbdb8 | `ref_getACSwitchStatus` 0x2f868: `bdb8 = (0xffff9ecd & 4) == 0` (pool 0x2f888 @0x2f868, write 0x2f882); called from 0x19640/0x199d4 | A/C switch request from the vehicle input latch 0xffff9ecd bit2 (active low) |

In 0x1506c these select the hard floors: AT → 820 base, 840 with A/C clutch +
switch or high load, 810 with A/C clutch alone or high load alone; MT with
0xffffb53c → 790, 830/800 with A/C clutch, 800 with high load. (The floor
constants 790–840 rpm are built by FP ops in 0x1506c, not literal pool words —
same export-derived caveat as the battery-gate constants noted in
[reviews/large_control_bodies_review.md](labeling/reviews/large_control_bodies_review.md).)

**0x5ca94 output path**: 0x5ca94 `idle_target_encode_u16` drives **no actuator
register**. Its sole caller is 0x1506c (pool word 0x0005ca94 exists only at
0x158d4): `mov.l @(0x158d4,pc),r2` at 0x157f4, `jsr @r2` at 0x157f6, result
stored `fmov.s fr0,@r12` at 0x157fa with r12 = 0xffffa7ac (pool 0x1576a at
0x15710). 0xffffa7ac is the Mode 22 PID 0x096e source (handler 0x56e22, ×0.25)
and doubles as the filter state read back next cycle (`filter(a7b0, a7ac, …)`)
and as the index of the target-term table 0x692bc (0x148a4) and the rpm-error
feedback (0x15a9a). 0x5ca94 also mirrors the value into the diagnostic override
cell 0xffffd34d when the active DID is 0x96e. The actuator path from the idle
target is separate: [`idle_control_report.md`](idle_control_report.md) —
`idle_air_required` 0xffffb2a4 → `ref_throttlePlatePosToTorqueOutput_` 0x21a80
/ 0x233ec → `inferred_throttle_position_ffffb2d4` 0xffffb2d4 →
0xffffb410 throttle-plate command (0–84 counts) → drive-by-wire throttle motor
(PCM terminals 1B/1C; package-pin routing untraced, discrepancy D2).

## 3. Key calibrated tables

| Descriptor | Dims | Axis (ROM-verified) | Data | Role |
|---|---|---|---|---|
| 0x69370 | 7 | coolant −40…80 °C @0x6dcf4 | u16 rpm 1700→810 @0x6dd10 | Idle Target – Base |
| 0x6935c | 11 | u16 (type 8) @0x6dcb0, data @0x6dcdc | filter factor | output smoothing |
| 0x693d4 / 0x693e8 / 0x693fc | 7 | coolant @0x6de40/0x6de6c/0x6de98 | type 8 | Idle Target F / G / H |
| 0x69410 | 7 | coolant @0x6dec4 | type 8 | Idle Target – vehicle moving (AT) |
| 0x69384 / 0x693c0 | 2-D | coolant | — | open-loop min / cranking target (0x15818/0x15934) |

Descriptor bytes for all six were parsed from ROM (`>HBBII`, type 8 = u16 data);
the names match the RX8Defs cross-ECU annotations already in the function header.

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x1506c | `idle_target_rpm_calculate` | high |

RAM aliases: `idle_target_rpm` (0xffffa7f4), plus the select-flag cells proven
in §2a: `automatic_transmission` (0xffffb534, already labeled),
`at_drive_range_engaged` (0xffffb53c), `high_load_flag` (0xffffb5b3, already
labeled), `ac_clutch_on` (0xffffbd69, already labeled), `ac_switch_request`
(0xffffbdb8), and `idle_target_u16` for 0xffffa7ac's role as PID 0x096e source
+ filter state. Evidence:
`labeling/source_review/accepted_function_aliases.tsv` / `accepted_ram_aliases.tsv`,
`data/labels/60E15120_N3J1E/idle_target_control_labels.json`.

## 5. Corrections made in this pass

None — 0x1506c was unlabeled. `idle_control_calc_batch` 0x167c0 is labeled in
[`idle_control_report.md`](idle_control_report.md).

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0001506c_*.c`
  (symbol renamed in place; filename keeps the `FUN_` prefix)
- `docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/idle_target_control_labels.json`

## 7. Validation

- Binary-level: call site jsr via pool 0x168ac (= 0x1506c) at 0x167fa; 0x11744 →
  0x167c0; task table rec[10].entry = 0x64f6 (ROM 0x4a38) and thunk 0x64f6 →
  0x11744 (jsr at 0x6506); all six 2-D descriptors parsed from ROM; base table
  values read (1700 rpm @−40 °C … 810 rpm @80 °C). Scripted checks 62/62 PASS.
- Binary-level, flag producers + 0x5ca94 output (§2a): pool words 0x24b5e =
  0xb534 (write 0x24b58 in 0x24b44), 0x24c5a = 0xb53c (write 0x24bde) and
  0x24e54 = 0xb53c (write 0x24e38) in 0x24b8c, 0x265f0 = 0xb5b3 (write 0x265ce
  in 0x264f0), 0x2eb58 = 0xbd69 (@0x2ea70 in 0x2e9a4), 0x2f888 = 0xbdb8 (write
  0x2f882 in 0x2f868); 0x5ca94 called only from 0x1506c (pool 0x158d4 @0x157f4,
  jsr 0x157f6; whole-ROM scan: pool word 0x0005ca94 only at 0x158d4), result
  stored at 0x157fa to r12 = 0xa7ac (pool 0x1576a @0x15710). Covered by
  `tests/test_idle_target_control.py`.
- `validate_reports.py` / `verify_claims.py` / `validate_export.py`;
  `tests/test_idle_target_control.py`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0001506c | `idle_target_rpm_calculate` | target rpm computation |
| 0x000167c0 | `idle_control_calc_batch` | idle calc batch (task[10] callee) |
| 0x00011744 | `FUN_00011744` | task[10] body, calls 0x167c0 |
| 0x000064f6 | `FUN_000064f6` | task[10] entry thunk → 0x11744 |
| 0x00015818 / 0x00015934 | `FUN_00015818` / `FUN_00015934` | open-loop ramp / mode select |
| 0x0005ca94 | `idle_target_encode_u16` | target → u16 (`inferred_ram_a7ac_ffffa7ac` 0xffffa7ac, PID 0x096e); sole caller 0x1506c (pool 0x158d4 @0x157f4, jsr 0x157f6, store @r12=0xffffa7ac at 0x157fa) |
| 0x00024b44 / 0x00024b8c | `ref_getAutoTransCal__` / `FUN_00024b8c` | producers of `automatic_transmission` 0xffffb534 / 0xffffb53c |
| 0x000264f0 / 0x0002e9a4 / 0x0002f868 | `candidate_electrical_load_flag_calc` / `FUN_0002e9a4` / `ref_getACSwitchStatus` | producers of `high_load_flag` 0xffffb5b3 / `ac_clutch_on` 0xffffbd69 / 0xffffbdb8 |
| 0x000290c6 | `ref_can231TxPack` | 0xffffbaec = 0xffffbae5 >> 4 (CAN 0x231 gear byte feeding 0x24b8c) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x6935c, 0x69370, 0x69384, 0x693c0, 0x693d4, 0x693e8, 0x693fc, 0x69410 | idle 2-D descriptors |
| 0x168ac | pool word = 0x1506c (call site 0x167fa) |
| 0x4990 + 10*16 + 8 = 0x4a38 | task table rec[10].entry = 0x64f6 |
| 0x158d4 / 0x1576a | pool words = 0x5ca94 (0x5ca94 call site 0x157f4) / 0xa7ac (store 0x157fa) |
| 0x24b5e / 0x24c5a / 0x24e54 / 0x265f0 / 0x2eb58 / 0x2f888 | pool words = 0xb534 / 0xb53c / 0xb53c / 0xb5b3 / 0xbd69 / 0xbdb8 (flag producers) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffa7f4 | `idle_target_rpm` | filtered idle target rpm output |
| 0xffffa7ac | `inferred_ram_a7ac_ffffa7ac` | 0x5ca94 output: PID 0x096e source (0x56e22 ×0.25), filter state, tbl 0x692bc index (0x148a4), rpm-error feedback (0x15a9a); not an actuator register |
| 0xffffa7b0 / … / 0xffffa800 | `DAT_ffffa7b0` … `DAT_ffffa800` | max-chain candidates / base target |
| 0xffffa7c8 | `DAT_ffffa7c8` | filtered battery voltage (gates 13.016 / 12.0 V) |
| 0xffffa804 / … / 0xffffa82c | `DAT_ffffa804` … `DAT_ffffa82c` | running/cranking timers and decay counters |
| 0xffffa990 / 0xffffb590 / 0xffffbbb4 | `DAT_ffffa990` / `DAT_ffffb590` / `DAT_ffffbbb4` | coolant temp / battery volts / vehicle speed inputs |
| 0xffffb534 | `automatic_transmission` | AT cal flag, set by `ref_getAutoTransCal__` 0x24b44 |
| 0xffffb53c | `at_drive_range_engaged` | AT drive/moving conditional from `FUN_00024b8c` (CAN 0x231 gear byte 0xffffbaec, vss, rpm) |
| 0xffffb5b3 | `high_load_flag` | set by 0x264f0 when filtered 0xffffb5e0 ≥ 40.0 |
| 0xffffbd69 | `ac_clutch_on` | set by 0x2e9a4 under its gating chain |
| 0xffffbdb8 | `inferred_ram_bdb8_ffffbdb8` | A/C switch request: (0xffff9ecd & 4) == 0, `ref_getACSwitchStatus` 0x2f868 |

## 9. Limits

- Static analysis only; no emulator run of the idle loop in this pass.
- The select flags 0xffffb534/b53c/b5b3/bd69/bdb8 are now proven from their
  producers (§2a), not just inferred: AT cal (0x24b44), AT drive/moving
  conditional (0x24b8c from CAN 0x231 gear + vss/rpm), high electrical load
  (0x264f0), A/C clutch engaged (0x2e9a4), A/C switch request (0x2f868 from
  0xffff9ecd bit2). The exact gear encoding inside 0xffffbaec (CAN 0x231
  nibble) is not decoded here.
- 0x5ca94's output path is resolved (§2a): it writes no actuator register —
  0xffffa7ac is the PID 0x096e diag cell + filter state, and the diag override
  cell 0xffffd34d; the actuator path runs via `idle_air_required` 0xffffb2a4 →
  0x21a80/0x233ec → 0xffffb2d4 → 0xffffb410 (throttle-plate command) →
  drive-by-wire throttle motor (terminals 1B/1C; package-pin routing untraced,
  discrepancy D2).
