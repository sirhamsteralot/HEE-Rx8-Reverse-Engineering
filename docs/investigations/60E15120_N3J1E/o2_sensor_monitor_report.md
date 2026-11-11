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
completes, 0x3fb9e publishes four amplitude ratios (`o2_monitor_ratio_ch0..ch3` 0xffffc6f0/c6f4/c780/c784).
**0x4128e** then compares them against load/rpm-indexed 3-D thresholds (running
averages updated only while both monitor gates 0xffffc704 and 0xffffae21 are
set, see §2a); per channel, ratio ≤ threshold sets the channel flag
0xffffc7ea–0xffffc7ed, ratio > threshold sets 0xffffc7e6–0xffffc7e9
(asm-verified: `fcmp/gt fr3,fr2` at 0x41440/0x41456/0x4146e/0x414e0, T = ratio >
threshold). If any of 0xffffc7ea–0xffffc7ed is set the fault is set pending
(0x5fd38(0x1c,1) via 0xffffc703); if all four 0xffffc7e6–0xffffc7e9 are set it
is confirmed (0x5fd38(0x1c,2) via 0xffffc702) — fault id 0x1c maps to slot 0x1b,
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
c710 = filter(lambda_actual   `inferred_lambda_actual_ffffadec` 0xffffadec, c710, 0.1)      # slow lambda
c714 = filter(lambda_actual   `inferred_lambda_actual_ffffadec` 0xffffadec, c714, 0.03125)

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
    c6f0 = c758/c728; c6f4 = c764/c734; c780 = c770/c740; c784 = c77c/c74c   # o2_monitor_ratio_ch0..ch3 0xffffc6f0/c6f4/c780/c784; 1e-5 guard (pool 0x41220)

# evaluation — o2_response_monitor_evaluate 0x4128e (jsr at 0x38f7a)
c788/c78c/c790/c794 = lookup_3d(load, rpm, tbl 0x6b680/0x6b69c/0x6b6b8/0x6b6d4)
if c704 == 1 and ae21 == 1:               # both gates required (asm 0x413ae-0x413c2)
    c7da += 1; c7a0/c7a4/c7a8/c7ac += c788/c78c/c790/c794
    c6f8/c6fc/c798/c79c = c7a0/c7a4/c7a8/c7ac / c7da      # running-average thresholds; else hold
if c701:
    per channel: ratio <= thr -> c7ea/c7eb/c7ec/c7ed = 1; ratio > thr -> c7e6/c7e7/c7e8/c7e9 = 1
    if any(c7ea..c7ed): c703 = 1 -> 0x5fd38(0x1c, 1)      # pending
    if all(c7e6..c7e9): c702 = 1 -> 0x5fd38(0x1c, 2)      # confirmed
    # id 0x1c -> slot u16 @0x7df7a = 0x1b -> code u16 @0x7e596 = 0x0133 = P0133
# Mode-06: 0x58262 encodes `o2_monitor_ratio_ch0` c6f0, 0x5831c encodes `o2_monitor_ratio_ch1` c6f4 via 0x5904a
```

### 2a. Physical meaning of the four channels and of the two gates (traced this pass)

The four filtered channels (0x3f924 `o2_channel_filter_update`) are the
front-O2-derived signals at four filter speeds:

| Cell | Filter | Input | Input producer (verified) |
|---|---|---|---|
| 0xffffc708 `o2_channel_afr_fast` | k=1.0 (unity, instantaneous) | `diag_afr_word_a` 0xffffaa6c | 0x1aa98: filtered 0xffffaa88 with MAF-indexed factor (tbl 0x697f8/0x69804); init 1.0 in 0x1a6c0 |
| 0xffffc70c | k=0.5 | 0xffffaa6c | same |
| 0xffffc710 `o2_channel_lambda_slow` (fast lambda) | k=0.1 | `inferred_lambda_actual_ffffadec` 0xffffadec | 0x1c880: clamped actual lambda (clamp(…, 0xffffb048, 0xffffb044)); init 1.0 |
| 0xffffc714 | k=0.03125 (slow lambda) | 0xffffadec | same |

In 0x3fb9e each ratio channel pairs the swing of an AFR-word channel with the
swing of a lambda channel (delta vs the previous sample c8ec/c8f0/c8f4/c8f8,
max-positive accumulated into c724/c730/c73c/c748 → moved to c728/c734/c740/c74c,
min-negative into c754/c760/c76c/c778 → moved to c758/c764/c770/c77c; published
when the window counter c904 reaches 0, c701 = 1):

| Ratio | Formula | AFR channel | Lambda channel |
|---|---|---|---|
| ch0 0xffffc6f0 | c758/c728 | c708 (unity), negative swing | c710 (k=0.1), positive swing |
| ch1 0xffffc6f4 | c764/c734 | c708, positive swing | c710, negative swing |
| ch2 0xffffc780 | c770/c740 | c70c (k=0.5), negative swing | c714 (k=0.03125), positive swing |
| ch3 0xffffc784 | c77c/c74c | c70c, positive swing | c714, negative swing |

Delta accumulation is gated by 0xffffc704 (and the sign bits c7de–c7e5); the
per-window reload counter comes from 3-D tbl 0x6b66c (load × rpm) every 2nd run
(c908).

**Gates** (both must be 1 for the threshold averages in 0x4128e to update, asm
0x413ae–0x413c2):

- 0xffffc704 — set inside 0x3fb9e every 2nd run (c908) when 0xffffc700 == 1,
  0xffffc7b0 == 0 and 0xffffc7b8 != 0x32; cleared when 0xffffd1c5 (DTC-setting
  disabled) is set. 0xffffc700 is the monitor-enable computed by 0x3fa18: 0 if
  P0133 is already stored (`ref_getFaultStatus__` 0x1c), 0xffffaa81 != 1,
  closed-loop not active (0xffffae1f), plausibility bands exceeded
  (|0xffffcab8| ≥ 50, |0xffffcabc| ≥ 0.05, |0xffffad50| ≥ 0.42,
  0xffffc7b8 > 0x31, 0xffffb220 ≥ 0.15, 0xffffb2f4 ≥ 0x271 …), else 1 with a
  0x20 startup countdown (0xffffc7b0).
- 0xffffae21 — O2-monitor enable computed by 0x1d1ca: 1 when 0xffffc700 == 1
  OR (closed-loop active 0xffffae1f AND coolant 0xffffa98c ≥ 150.0 AND
  0xffffad24 == 1 AND 0xffffae20 == 0). 0x1d1ca also computes the expected
  oscillation period/amplitude (0xffffb016, 0xffffaff4 from 3-D MAF × rpm
  lookups 0x69a98/0x69aac/0x69ac0/0x69adc) consumed by the half-period timers
  0xffffae1a/0xffffae1c in 0x1d2e2, which are themselves gated by 0xffffae21.

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
`o2_channel_afr_medium` (0xffffc70c), `o2_channel_lambda_slow` (0xffffc710),
`o2_channel_lambda_very_slow` (0xffffc714), `o2_monitor_accum_gate` (0xffffc704),
`o2_monitor_enable` (0xffffae21). Full evidence strings:
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
- Binary-level, channels + gates (§2a): gate reads in 0x4128e (pools 0x4147e =
  0xc704 @0x413ae, 0x41480 = 0xae21 @0x413ba, both `cmp/eq 0x1` with `bf/s` at
  0x413b6/0x413c2 skipping the average update), ratio compares `fcmp/gt fr3,fr2`
  at 0x41440/0x41456/0x4146e/0x414e0, decision jsr 0x5fd38 (pool 0x415dc) with
  r5=1 at 0x41564 / r5=2 at 0x4157c, ratio ch0 `fdiv` at 0x4119e (pools 0x41224 =
  0xffffc728, 0x41238 = 0xffffc758); channel-input producers 0x1aa98/0x1c880 and
  gate producers 0x3fa18/0x1d1ca/0x1d2e2 from the decompiled bodies + callgraph.
  Covered by `tests/test_o2_sensor_monitor.py`.
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
| 0x00058262 / 0x0005831c | `FUN_00058262` / `FUN_0005831c` | Mode-06 encoders of `o2_monitor_ratio_ch0/ch1` 0xffffc6f0/c6f4 |
| 0x0005fd38 | `dtc_set_fault_x0` | set-fault trampoline, x=0 (see [dtc_control_report.md](dtc_control_report.md)) |
| 0x00003fa18 / 0x0001d1ca / 0x0001d2e2 | `FUN_0003fa18` / `FUN_0001d1ca` / `FUN_0001d2e2` | producers of 0xffffc700 (monitor enable), 0xffffae21 (O2-monitor enable) and the half-period timers 0xffffae1a/0xffffae1c |
| 0x0001aa98 / 0x0001c880 | `FUN_0001aa98` / `FUN_0001c880` | producers of the channel inputs 0xffffaa6c (AFR word) / 0xffffadec (lambda actual) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x6b66c, 0x6b680, 0x6b69c, 0x6b6b8, 0x6b6d4 | 3-D descriptors (load × rpm) |
| 0x69a98 / 0x69aac / 0x69ac0 / 0x69adc | 3-D descriptors (MAF × rpm) for expected oscillation period/amplitude (0x1d1ca) |
| 0x697f8 / 0x69804 | 2-D descriptors for the AFR-word filter factor (0x1aa98) |
| 0x41220 | literal pool word 0x3727c5ac (1e-5 tolerance) |
| 0x390b0 | pool word = 0x3fb9e (call site 0x38f74) |
| 0x7df42 + 2*0x1c = 0x7df7a | id2slot[0x1c] = 0x1b |
| 0x7e560 + 2*0x1b = 0x7e596 | slot 0x1b code = 0x0133 (P0133) |
| 0x413ae / 0x413ba | gate reads: 0xffffc704 (pool 0x4147e) and 0xffffae21 (pool 0x41480) at 0x413ae–0x413c2 |
| 0x41440 / 0x41456 / 0x4146e / 0x414e0 | `fcmp/gt fr3,fr2` ratio-vs-threshold compares (T = ratio > threshold) |
| 0x41564 / 0x4157c | jsr 0x5fd38 with r5=1 (pending, via 0xffffc703) / r5=2 (confirmed, via 0xffffc702) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffc708 / 0xffffc70c / 0xffffc710 / 0xffffc714 | `o2_channel_afr_fast` / `o2_channel_afr_medium` / `o2_channel_lambda_slow` / `o2_channel_lambda_very_slow` | filtered channel values: AFR word 0xffffaa6c k=1.0/0.5, lambda 0xffffadec k=0.1/0.03125 (0x3f924) |
| 0xffffc6f0 / 0xffffc6f4 / 0xffffc780 / 0xffffc784 | `o2_monitor_ratio_ch0` / `_ch1` / `_ch2` / `_ch3` | window amplitude ratios (AFR-swing/lambda-swing pairs, §2a) |
| 0xffffc701 | `o2_monitor_fluctuation_detected` | window complete flag |
| 0xffffc704 | `o2_monitor_accum_gate` | delta-accumulation gate, set in 0x3fb9e when 0xffffc700 && 0xffffc7b0==0 && 0xffffc7b8 != 0x32 |
| 0xffffc700 | `DAT_ffffc700` | monitor enable (0x3fa18; cleared when P0133 stored / not closed-loop / plausibility bands) |
| 0xffffae21 | `o2_monitor_enable` | O2-monitor enable (0x1d1ca); with 0xffffc704 gates the threshold averages in 0x4128e |
| 0xffffc6f8 / … / 0xffffc79c | `DAT_ffffc6f8` … `DAT_ffffc79c` | running-average thresholds (updated only when 0xffffc704 && 0xffffae21) |
| 0xffffc724–0xffffc77c | `DAT_ffffc724`–`DAT_ffffc77c` | max/min delta accumulators |
| 0xffffc7b2 | `DAT_ffffc7b2` | 3-D reload value (tbl 0x6b66c) |
| 0xffffd1c5 | `DAT_ffffd1c5` | DTC-setting-disabled flag; resets accumulators when set |

## 9. Limits

- Static analysis only. The four channels' physical meaning is now traced to
  their producers (§2a): filtered versions of the O2-feedback AFR word
  0xffffaa6c (k=1.0/0.5) and the actual lambda 0xffffadec (k=0.1/0.03125); each
  ratio channel compares an AFR-word swing against a lambda swing. The P0133
  attribution is solid (fault id → slot → code bytes verified); the per-channel
  comparison wiring is asm-verified (ratio ≤ threshold → 0xffffc7ea–c7ed, pending
  if any set; all four > threshold → 0xffffc7e6–c7e9, confirmed), but which
  physical direction means "slow" is not proven beyond the code.
- The threshold gating is resolved (§2a): the running averages of the 3-D
  lookups 0x6b680–0x6b6d4 update only while 0xffffc704 (accumulation gate, set in
  0x3fb9e) AND 0xffffae21 (monitor enable from 0x1d1ca) are both 1.
- No dynamic (emulator) run was performed for this monitor in this pass.
