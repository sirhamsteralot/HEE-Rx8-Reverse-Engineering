# O2 sensor (front HO2S) response monitor report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`reverse-engineered/decompiled/60E15120_N3J1E/`), the disassembly
(`reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm`) and the
raw ROM bytes. No hardware execution was performed. Labels recorded in
`data/labels/60E15120_N3J1E/o2_sensor_monitor_labels.json`.

**Related reports:** DTC set path and the fault-id → slot map are documented in
[`dtc_control_report.md`](dtc_control_report.md) (0x5fd38 → 0x5fe20, id2slot table
0x7df42, code table 0x7e560); lambda/AFR producers in
[`fueling_control_report.md`](fueling_control_report.md) and
[`load_fueling_report.md`](load_fueling_report.md); the slow/background task that
hosts the monitor batch in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); Mode-06
test-result reporting in [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md).

## 1. Executive summary

The PCM runs an **OBD front-O2-sensor response (slow-response) monitor** that ends
in **DTC P0133** ("front HO2S circuit slow response", Mazda manual wording). Four
first-order-filtered channels of the AFR word and the actual lambda signal
(0x3f924) are delta-accumulated per evaluation window by **0x3fb9e**
(4,884 B — the largest unlabeled body). When a window
completes, 0x3fb9e publishes four amplitude ratios (0xffffc6f0/c6f4/c780/c784).
**0x4128e** then compares them against load/rpm-indexed 3-D thresholds; if any
channel exceeds its threshold the fault is set pending (0x5fd38(0x1c,1)), if all
four exceed it is confirmed (0x5fd38(0x1c,2)) — fault id 0x1c maps to slot 0x1b,
code 0x0133 = P0133. The ratios are also exported as Mode-06 test results by
0x58262/0x5831c.

## 1a. Plain-language summary

The front oxygen sensor tells the PCM the exhaust oxygen content; the PCM uses it
to trim fuel. A healthy sensor swings quickly; an aging one swings slowly. This
monitor measures how much the sensor signal still swings (through four filters
with different speeds), divides the "still swinging" amount by the "should be
swinging" amount, and compares that ratio against a table that depends on engine
load and rpm. If the sensor responds too slowly, the PCM records P0133 and lights
the check-engine lamp per the usual DTC rules.

## 2. How it works (condensed pseudocode)

```
# channel filters — 0x3f924, called from 0x38dca (init/monitor chain 0x11ba4)
c708 = filter(diag_afr_word_a 0xffffaa6c, c708, 1.0)      # fast AFR
c70c = filter(diag_afr_word_a 0xffffaa6c, c70c, 0.5)
c710 = filter(lambda_actual   0xffffadec, c710, 0.1)      # slow lambda
c714 = filter(lambda_actual   0xffffadec, c714, 0.03125)

# accumulator — o2_response_monitor_accumulate 0x3fb9e (batch 0x38f3e, jsr at 0x38f74)
if ++c8fc == 2:                       # every 2nd run
    c8fc = 0; c908 = 1
    c7b2 = lookup_3d_raw_u16(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6b66c)  # reload window
shift ring c7f4[10] floats; c7f4[0] = c710
shift ring c870[10] u16;    c870[0] = c714
c718 = c710 - c81c; c71c = c714 - c898          # channel deltas, sign bits c7de/c7e0
# per-channel pair counters c7ba..c7d8 (decay -2, reload with c7b2 on edge patterns)
# accumulate max-positive deltas into c724/c730/c73c/c748, min-negative into
# c754/c760/c76c/c778; on transition move them into c728/c758, c734/c764, c740/c770, c74c/c77c
if window complete (c904 == 0):
    c701 = 1
    c6f0 = c758/c728; c6f4 = c764/c734; c780 = c770/c740; c784 = c77c/c74c   # 1e-5 guard (pool 0x41220)

# evaluation — o2_response_monitor_evaluate 0x4128e (jsr at 0x38f7a)
c6f8/c6fc/c798/c79c = running avg of lookup_3d(load, rpm, tbl 0x6b680/0x6b69c/0x6b6b8/0x6b6d4)
if c701:
    any_fail  = any(ratio > threshold); all_fail = all four ratios > thresholds
    if any_fail:  0x5fd38(0x1c, 1)      # pending
    if all_fail:  0x5fd38(0x1c, 2)      # confirmed
    # id 0x1c -> slot u16 @0x7df7a = 0x1b -> code u16 @0x7e596 = 0x0133 = P0133
# Mode-06: 0x58262 encodes c6f0, 0x5831c encodes c6f4 via 0x5904a
```

## 3. Key calibrated tables

| Descriptor | Dims | Axes (ROM-verified) | Role |
|---|---|---|---|
| 0x6b66c | 9×9 | x load 0.125–0.625 @0x7ad48, y rpm 500–4500 @0x7ad6c, data @0x7ad90 | per-window counter reload (0x3fb9e → 0xffffc7b2) |
| 0x6b680 / 0x6b69c | 9×9 | x load 0.125–0.625 @0x7ae34/0x7af20, y rpm 500–4500 @0x7ae58/0x7af44, data u16 (typ 8) @0x7ae7c/0x7af68, scaled ×0.000152587890625 (mult @+20) | per-channel thresholds ch0/ch1 → 0xffffc6f8/c6fc |
| 0x6b6b8 / 0x6b6d4 | **1×1** | single-point axes 0.125/500 @0x7b00c/0x7b010, data u16 0 @0x7b014/0x7b020, mult 0.000152587890625, off −1.0 → constant −1.0 | constant thresholds ch2/ch3 → 0xffffc798/c79c (1×1 per `data/maps/60E15120_N3J1E/index.tsv` tbl_06b6b8/tbl_06b6d4) |

All five descriptors were parsed from ROM bytes (`>HHIIIB` 3-D base + 3 pad;
0x6b66c has type byte 0 but is consumed as raw u16 via
`rx8_lookup_3d_raw_u16`).

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x3fb9e | `o2_response_monitor_accumulate` | high |
| 0x4128e | `o2_response_monitor_evaluate` | high |
| 0x3f924 | `o2_channel_filter_update` | high |

RAM aliases: `o2_monitor_ratio_ch0..ch3` (0xffffc6f0/c6f4/c780/c784),
`o2_monitor_fluctuation_detected` (0xffffc701), `o2_channel_afr_fast` (0xffffc708),
`o2_channel_lambda_slow` (0xffffc710). Full evidence strings:
`docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv`
and `accepted_ram_aliases.tsv`; record:
`data/labels/60E15120_N3J1E/o2_sensor_monitor_labels.json`.

## 5. Corrections made in this pass

None — these bodies were previously unlabeled `FUN_`; no prior label was
contradicted. (The neighboring `ref_misfireDetectInit_` 0xab8a label belongs to a
different monitor and was not touched.)

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0003fb9e_*.c`,
  `0004128e_*.c`, `0003f924_*.c` (symbol renamed in place by
  `integrate_reviewed_names.py`; filenames keep the `FUN_` prefix)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/o2_sensor_monitor_labels.json`,
  `data/labels/60E15120_N3J1E/integrated_names.json`

## 7. Validation

- Binary-level: call sites (jsr at 0x38f74/0x38f7a, pool word 0x390b0 = 0x3fb9e),
  3-D descriptors 0x6b66c/0x6b680/0x6b69c/0x6b6b8/0x6b6d4 parsed from ROM, tolerance
  float 1e-5 (0x3727c5ac) at pool 0x41220 reached by `mova` at
  0x41140/0x41156/0x4116a/0x4117e, fault chain id 0x1c → u16 @0x7df7a = 0x1b →
  u16 @0x7e596 = 0x0133 (P0133, `data/dtc/60E15120_N3J1E.tsv` slot 1b), Mode-06
  encoders 0x58262/0x5831c. 62/62 scripted ROM/disassembly checks passed.
- `validate_reports.py`, `verify_claims.py`, `validate_export.py` run from repo
  root (see `data/labels/60E15120_N3J1E/report_validation.json` /
  `claim_validation.json`); `tests/test_o2_sensor_monitor.py` covers the ROM-byte
  anchors above.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0003fb9e | `o2_response_monitor_accumulate` | 4-channel delta accumulator, window ratios |
| 0x0004128e | `o2_response_monitor_evaluate` | threshold compare + P0133 set |
| 0x0003f924 | `o2_channel_filter_update` | 4 first-order filters of AFR/lambda |
| 0x00038f3e | `FUN_00038f3e` | slow-task batch hosting 0x3fb9e/0x4128e |
| 0x00038dca | `FUN_00038dca` | calls 0x3f924 |
| 0x00058262 / 0x0005831c | `FUN_00058262` / `FUN_0005831c` | Mode-06 encoders of c6f0/c6f4 |
| 0x0005fd38 | `dtc_set_fault_x0` | set-fault trampoline, x=0 (see [dtc_control_report.md](dtc_control_report.md)) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x6b66c, 0x6b680, 0x6b69c, 0x6b6b8, 0x6b6d4 | 3-D descriptors (load × rpm) |
| 0x41220 | literal pool word 0x3727c5ac (1e-5 tolerance) |
| 0x390b0 | pool word = 0x3fb9e (call site 0x38f74) |
| 0x7df42 + 2*0x1c = 0x7df7a | id2slot[0x1c] = 0x1b |
| 0x7e560 + 2*0x1b = 0x7e596 | slot 0x1b code = 0x0133 (P0133) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffc708 / 0xffffc70c / 0xffffc710 / 0xffffc714 | `o2_channel_afr_fast` … | filtered channel values (0x3f924) |
| 0xffffc6f0 / 0xffffc6f4 / 0xffffc780 / 0xffffc784 | `o2_monitor_ratio_ch0..3` | window amplitude ratios |
| 0xffffc701 | `o2_monitor_fluctuation_detected` | window complete flag |
| 0xffffc6f8 / … / 0xffffc79c | `DAT_ffffc6f8` … `DAT_ffffc79c` | running-average thresholds |
| 0xffffc724–0xffffc77c | `DAT_ffffc724`–`DAT_ffffc77c` | max/min delta accumulators |
| 0xffffc7b2 | `DAT_ffffc7b2` | 3-D reload value (tbl 0x6b66c) |
| 0xffffd1c5 | `DAT_ffffd1c5` | DTC-setting-disabled flag; resets accumulators when set |

## 9. Limits

- Static analysis only; the exact physical meaning of the four channels (which
  filter pairs the ratio compares) is inferred from dataflow, not from a
  specification. The P0133 attribution is solid (fault id → slot → code bytes
  verified); the ratio formula direction (pass/fail polarity) follows the
  decompiled comparisons.
- Thresholds 0x6b680–0x6b6d4 are running averages of 3-D lookups, gated by
  0xffffc704 and 0xffffae21; the exact gating conditions of those flags are not
  fully traced.
- No dynamic (emulator) run was performed for this monitor in this pass.
