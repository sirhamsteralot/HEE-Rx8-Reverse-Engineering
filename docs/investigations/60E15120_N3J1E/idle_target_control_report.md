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

RAM alias: `idle_target_rpm` (0xffffa7f4). Evidence:
`source_review/accepted_function_aliases.tsv` / `accepted_ram_aliases.tsv`,
`data/labels/60E15120_N3J1E/idle_target_control_labels.json`.

## 5. Corrections made in this pass

None — 0x1506c was unlabeled. `idle_control_calc_batch` 0x167c0 is labeled in
[`idle_control_report.md`](idle_control_report.md).

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0001506c_*.c`
  (symbol renamed in place; filename keeps the `FUN_` prefix)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/idle_target_control_labels.json`

## 7. Validation

- Binary-level: call site jsr via pool 0x168ac (= 0x1506c) at 0x167fa; 0x11744 →
  0x167c0; task table rec[10].entry = 0x64f6 (ROM 0x4a38) and thunk 0x64f6 →
  0x11744 (jsr at 0x6506); all six 2-D descriptors parsed from ROM; base table
  values read (1700 rpm @−40 °C … 810 rpm @80 °C). Scripted checks 62/62 PASS.
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
| 0x0005ca94 | `idle_target_encode_u16` | target → u16 (`inferred_ram_a7ac_ffffa7ac` 0xffffa7ac, PID 0x096e) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x6935c, 0x69370, 0x69384, 0x693c0, 0x693d4, 0x693e8, 0x693fc, 0x69410 | idle 2-D descriptors |
| 0x168ac | pool word = 0x1506c (call site 0x167fa) |
| 0x4990 + 10*16 + 8 = 0x4a38 | task table rec[10].entry = 0x64f6 |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffa7f4 | `idle_target_rpm` | filtered idle target rpm output |
| 0xffffa7b0 / … / 0xffffa800 | `DAT_ffffa7b0` … `DAT_ffffa800` | max-chain candidates / base target |
| 0xffffa7c8 | `DAT_ffffa7c8` | filtered battery voltage (gates 13.016 / 12.0 V) |
| 0xffffa804 / … / 0xffffa82c | `DAT_ffffa804` … `DAT_ffffa82c` | running/cranking timers and decay counters |
| 0xffffa990 / 0xffffb590 / 0xffffbbb4 | `DAT_ffffa990` / `DAT_ffffb590` / `DAT_ffffbbb4` | coolant temp / battery volts / vehicle speed inputs |

## 9. Limits

- Static analysis only; no emulator run of the idle loop in this pass.
- The meaning of each select flag (`automatic_transmission` 0xffffb534/b53c/b5b3/bd69/bdb8, e.g. A/C or
  AT) is inferred from context and the table names, not from the flag producers.
- 0x5ca94's role is settled in [`idle_control_report.md`](idle_control_report.md):
  it encodes the target to `inferred_ram_a7ac_ffffa7ac` 0xffffa7ac (Mode 22 PID 0x096e) and the diag override
  cell 0xffffd34d; the actuator path runs via `idle_air_required` 0xffffb2a4 → 0x21a80 (electronic
  throttle).
