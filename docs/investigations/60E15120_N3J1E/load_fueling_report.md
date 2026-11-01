# Load and fuelling model report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Date: 2026-10-29. Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes; the load-path float
literals were re-read directly from the untouched ROM. No hardware execution
was performed. Full per-function evidence: `reviews/load_fueling_model/`
(README, REVIEW_NOTES, candidate alias TSVs, validation.json).

**Related reports:** this is the upstream of the fuelling and timing chains — see [fueling control](fueling_control_report.md), [ignition timing](ignition_timing_report.md), [intake solenoids](intake_solenoids_report.md) (MAF/RPM thresholds); tables extracted in [calibration extraction](calibration_extraction_report.md); the computed load cell is diag-exposed as [Mode 22 PID 0x43](uds_mode22_dispatch_report.md) (handler 0x56b8a reads `engine_load_ffffc0b4` × 1/255; PID 0x04 = load/max×100 — ROADMAP D5 handler side settled 2026-10-31).

## 1. Executive summary

The PCM's "engine load" — the axis shared by every fuel and timing table in
the RX8Defs — is **not a percentage of a measured quantity**. It is an
airflow index: MAF (g/s) converted to air-per-revolution, capped, scaled,
filtered and clamped. The full chain:

1. **MAF** is ADC channel 3, scaled by the "MAF Scaling" table. A
   plausibility gate debounces short excursions; a fault manager (0.64 V low /
   4.9 V high, battery and RPM windows, fault slots 10/11) switches fuelling
   to a **throttle-based fallback airflow model** when the MAF fails.
2. **Engine load** = `min(filter(air_per_revolution × 0.6345), max_load)`,
   forced to **0.525 during cranking**; the ceiling is air-density
   compensated (IAT × baro × RPM tables). The filter snaps (coefficient 1.0)
   for 25 cycles after a trigger and follows normally at 0.2.
3. **Manifold pressure is estimated, not measured** — from the RX8Defs
   "Estimated Manifold Pressure" RPM×load table times (IAT+273)/300. The
   barometric pressure *is* a real sensor (raw × 25.325 + 0.0182 kPa).
4. **Fuel volume request** = load × 0.07196 × the RPM×load base map
   ("Fuel Injection - Engine Load Compensation", 0x6ac88) × the enrichment
   sum × the fuel-target multiplier (1.0 default; this is where closed-loop
   trim enters), plus a **diagnostic proportional trim** pathway
   (diagnostic request id 0x17e0, command 7).
5. The request fans out through **three injector channel groupings**
   (primary / secondary-1 / secondary-2) with weighted-engine-temp and
   manifold-relative (vacuum) multipliers, battery/MAP injector latency,
   RPM-based clamps, and a cranking adder, into six output timer records.

**Key finding for tuning:** the RPM×load "Engine Load Compensation" table
(0x6ac88) is the base fuel map, and its second axis is confirmed to be
`engine_load_ffffc0b4` (verified in the disassembly at the call site — the
decompiler prints only the RPM argument). Load itself is MAF-derived with a
hard cap of 5.0 g/rev before the 0.6345 scale, so a big MAF calibration
change cannot push load past that product ceiling.

## 1a. Plain-language summary (what "engine load" means)

- "Engine load" — the axis shared by every fuel and timing map — is **not a
  percentage of anything measured**. It is an airflow-per-revolution index
  computed from the MAF sensor (with a throttle-based fallback model if the
  MAF fails). Manifold pressure is *estimated* from a table, not measured;
  only barometric pressure is a real sensor.
- So the ROM map cells are per-operating-point values indexed by this load x
  RPM; the final fuel volume = load x base map x enrichment sum x target
  multiplier. A datalog "load" value is this airflow index, not throttle or
  manifold pressure.

## 2. How it works (condensed pseudocode)

```python
# --- MAF acquisition (ADC sweep 0x6884; MAF = channel 3) ---
maf_raw = adc[3]                                        # RAM 0xffff9eea
maf_volts = maf_raw * 5/65536                           # 0x7438
maf_g_s   = lookup(tbl_0x69788, maf_volts)              # "MAF Scaling" -> RAM 0xffff9f78

# --- plausibility (0x19f4e, interrupt context via 0x63f0->0x114b0->0x19806) ---
count_high = count_high + 1 if maf_raw >= 0xf852 else 0        # RAM 0xffffaa35 (saturating u8)
count_low  = count_low + 1  if maf_raw <  0x7ae  else 0        # RAM 0xffffaa36 (saturating u8)
if count_high >= 3 or count_low >= 3 or 0x7ae <= maf_raw < 0xf852:
    maf_volts_validated = maf_raw * 5/65536             # RAM 0xffffa9e4 (gate verified in disassembly)
    maf_g_s_validated    = maf_g_s                      # RAM 0xffffa9e8
# 1-2 sample excursions hold the previous values (debounce); sustained
# excursions propagate so the fault manager can see them.

# --- fault manager (0x3b214) ---
low_cond  = maf_volts_validated < 0.64                  # RAM 0xffffc593 (battery >= 8 V, RPM >= 500 windows)
high_cond = maf_volts_validated > 4.9                   # RAM 0xffffc594 (RPM <= 6500 window)
# 4-count debounces, fault slots 10/11 -> ref_getFaultStatus__
maf_fault = low_cond_latched or high_cond_latched       # RAM 0xffffc590

# --- smoothing + density cap (task[5]: 0x65f6 -> 0x11b7e -> 0x19794) ---
buffer[idx % 6] = maf_g_s_validated; avg = (prev + new) / 2
cap = lookup(tbl_0x69794, rpm) * 293.0/(iat+273) * baro/101.33299   # ROM literal 293.0 @0x1a198
mass_air_flow = min(avg, cap) if not maf_fault else throttle_fallback    # RAM 0xffffa9ec
throttle_fallback = ((tps*0.04 + 0.26) * rpm) / 60.0    # 0x1a13c -> RAM 0xffffaa28 (units candidate)

# --- transient select (0x1a1dc) ---
use_raw_maf = 1 if throttle/rpm deltas exceed lookup(tbl_0x697a0, tps) thresholds \
                  or startup else 0                     # RAM 0xffffaa4c

# --- load core (task[6]: 0x661e -> 0x11ba4 -> 0x197be; 0x1a418) ---
selected = mass_air_flow if use_raw_maf else filter(mass_air_flow, coeff=lookup(tbl_0x697b4, rpm))
air_per_rev = min(selected * 60.0 / rpm, 5.0)           # literals 60.0 @0x1a4e8, 5.0 @0x1a4f4; RAM 0xffffaa3c
load_unfiltered = air_per_rev * 0.6345                   # ROM 0x7a088 -> RAM 0xffffc0b0 (0x33a6c)

# --- load filter/clamp (0x33ad2) ---
if cranking_or_injectors_off: engine_load = 0.525        # RAM 0xffffc0b4
else: engine_load = min(filter(load_unfiltered, coeff=0.2 or 1.0 if snap_counter),
                        max_load)                        # snap counter RAM 0xffffc0c4, set to 25 by 0x33a58
max_load = lookup(tbl_0x6b200, iat) * lookup(tbl_0x6b214, baro) * lookup(tbl_0x6b1ec, rpm)
                                                          # RAM 0xffffc0b8 (0x33ab0/0x33a7c)

# --- pressure model (fuelling task 0x20e40, phase 2) ---
map_est = lookup3d(tbl_0x6aa48, rpm, engine_load) * (iat+273) * be1c / 300.0   # RAM 0xffffbe00 (0x2fdb0)
map_rel = baro - map_est                                 # RAM 0xffffbe04/0xffffbe08 (0x2fe00)
baro   = baro_raw * 25.325 + 0.0182                      # 0xd144 -> RAM 0xffffad14; forced 101.3 by flag

# --- fuel volume request (0x306e8) ---
load_to_fuel     = engine_load * 0.07196                 # literal @0x78170 -> RAM 0xffffbed0
base_map_mult    = lookup3d(tbl_0x6ac88, rpm, engine_load)  # RAM 0xffffbed4; load arg verified in fr5
request_pre_trim = (enrichment_sum - subtractors) * fuel_target * base_map_mult
fuel_target      = 1.0 default; closed-loop trim clamped [max(2D-65, 3D-22, 2D-66), 2D-67]
                                                          # RAM 0xffffadec (0x1c880)
request_trimmed  = request_pre_trim + diag_trim           # 0x5c024: diagnostic id 0x17e0 cmd 7, affine u8 (1/256, -0.5)
fuel_volume_request = request_trimmed * load_to_fuel      # RAM 0xffffbeb0

# --- per-injector split (0x2fd3e / 0x2fe1e / 0x2ff78 / 0x30948 / 0x30030 / 0x2fea8) ---
mult_primary    = lookup3d(tbl_0x6a9a4, weighted_temp, engine_load)
mult_secondary1 = lookup3d(tbl_0x6a9c0, weighted_temp, engine_load)
mult_secondary2 = lookup3d(tbl_0x6a9dc, weighted_temp, engine_load)
vacuum_mult     = lookup(tbl_0x6aa0c/0x6aa20/0x6aa34, map_rel)
latency         = lookup3d(tbl_0x6aa80, map_est, battery_voltage)      # per channel, RAM 0xffffa094[]
pulse           = clamp(channel_request * vacuum_mult, 1024, lookup(tbl_0x6aa9c, rpm))
cranking: add cranking pulse products (tbls 0x6ab48/0x6ab98/0x6abc8/0x6bab0)

# --- output (0x8344/0x8814/0x84c6/0x8a68) ---
# six 0x18-stride timer records at RAM 0xffffa004 -> ATUII compare pulses
# per-injector ISRs 0x59a4-0x59ea; channel-to-injector mapping not established

# --- consumers worth noting ---
decel_cut_base = filter(rpm * fuel_volume_request * 0.12, coeff=0.75)    # 0x2f9d0 -> RAM 0xffffbdc0
diag_percent   = (fuel_target - 1.0) * 100.0                            # -> RAM 0xffffd0d8 (candidate)
```

## 3. Task structure

| Context | Chain |
|---|---|
| ISR/ADC sweep `0x6884` | 32 ADC channels; MAF = ch 3, knock = ch 10 |
| interrupt `0x63f0` → `0x114b0` → `0x19806` | `ref_MAFRelated` plausibility gate |
| task[5] `0x65f6` → `0x11b7e` → `0x19794` | fallback model, buffer average, density cap, fault manager |
| task[6] `0x661e` → `0x11ba4` → `0x197be` | transient detect, air/rev index, load filter/clamp, max load |
| fuelling task `0x20e40` | 3 interrupt-masked phases: MAP estimate → volume request → per-channel pulses; phase 3 = closed-loop block |
| `0x21186` | injector latency calibration |

## 4. Key calibrated tables

Confirmed in-role by this trace (all RX8Defs-matched):

| Table | Contents |
|---|---|
| `tbl_maf_scaling_00069788` | MAF volts → g/s (RX8Defs "MAF Scaling") |
| `tbl_estimated_manifold_pressure_0006aa48` | RPM × load → estimated MAP (RX8Defs name corroborates the estimate role) |
| `tbl_fuel_injection_engine_load_compensation_0006ac88` | **the RPM × load base fuel map** (18×20); inputs verified at the call site |
| `tbl_injector_latency_primary_0006aa80` | latency vs estimated MAP × battery |
| `tbl_rpm_based_max_engine_load_0006b1ec` | load ceiling vs RPM; × `0x6b200` (IAT) × `0x6b214` (baro) |
| `tbl_primary/secondary1/secondary2_injector_weighted_engine_temp_multiplier_0006a9a4/a9c0/a9dc` | temp × load injector multipliers |
| `tbl_injector_manifold_vacuum_multiplier_0006aa0c/0x6aa20/0x6aa34` | vacuum (relative pressure) multipliers |
| `tbl_primary_fuel_injector_cranking_pulse_width_0006ab48` + `0x6ab98/0x6abc8/0x6bab0` | cranking pulse family |
| `tbl_closed_loop_fuelling_threshold_*_00069d24–0x69d74` | open-loop entry vs load/throttle (existing annotations re-read) |

**New table candidates (no RX8Defs match yet — candidates only, dimension/storage
verification required before any def work):**

| Descriptor | Read by | Interpretation (candidate) |
|---|---|---|
| 0x69794 | 0x1a086 | MAF density-cap window vs RPM |
| 0x697a0 | 0x1a1dc | transient-detection threshold vs throttle |
| 0x697b4 | 0x1a418 | MAF filter coefficient vs RPM |
| 0x6aa9c | 0x30030 | max per-channel injection time vs RPM |
| 0x6ac38 | 0x306e8/0x307e0 | coolant-based enrichment/fuel adder |

## 5. Candidates recorded (not yet integrated)

This pass was a findings review; **no rename pass was run**. Candidates live
in `reviews/load_fueling_model/candidate_function_aliases.tsv`
(19 functions: 14 high, 5 medium confidence) and
`candidate_ram_aliases.tsv` (~45 RAM locations). Integration into the
synchronized views — following the knock-review workflow
(`scripts/` annotation pass, `metadata/integrated_names.json`, all views,
validators) — is the follow-up work if the candidates are accepted.

## 6. Corrections made in this pass

- **293 K, not 295 K.** The density-cap reference temperature at 0x1a086 is
  ROM literal `0x43928000` @0x1a198 = **293.0** (295.0 would be 0x43938000,
  which does not occur in that function). Earlier annotations said
  "Kelvin conversion 295/(x+273)"; corrected in
  `decompiled/functions/0001a086_FUN_0001a086.c`,
  `decompiled/firmware_decompiled.c`, `named/firmware_named.c` and
  `source_review/accepted_ram_aliases.tsv`. Documentation-only change: no
  function bodies, names, addresses or ROM bytes changed.

## 7. Files

| File | Contents |
|---|---|
| [`reviews/load_fueling_model/README.md`](reviews/load_fueling_model/README.md) | chain overview, findings, follow-ups |
| [`reviews/load_fueling_model/REVIEW_NOTES.md`](reviews/load_fueling_model/REVIEW_NOTES.md) | per-function evidence, disassembly excerpts |
| `reviews/load_fueling_model/candidate_function_aliases.tsv` | 19 candidate function names |
| `reviews/load_fueling_model/candidate_ram_aliases.tsv` | ~45 candidate RAM names |
| `reviews/load_fueling_model/validation.json` | inputs by hash, literal checks, validator results |
| [`README.md`](README.md) (root) | pointer section added |

## 8. Validation

- `scripts/validate_export.py`: **pass** — ROM SHA-256 verified
  (`a7cd953c…64f1`), 3,355 function files, 168,592 instructions byte-verified
  (337,184 instruction bytes), 1,833 exact reference matches. Note: run from a
  faithful copy with only the ROM path localized (the copy of
  `metadata/input.json` on this machine still records the original author's
  `/home/yannick/…` path); the script's `metadata/validation.json` output is
  identical.
- `scripts/verify_readability.py`: **pass** (3,355 function bodies consistent).
- `scripts/verify_math_units.py`: **pass**.
- ROM literal verification (big-endian float32 read from the untouched ROM):
  0.6345 @0x7a088, 0.07196 @0x78170, 60.0 @0x1a4e8, 5.0 @0x1a4f4, 273.0
  @0x1a194, 293.0 @0x1a198, 101.33299 @0x1a1a0, 300.0, 369.472, 475.93.
- Disassembly verification: the MAF copy gate (0x19fa8–0x19fe8), the 0x1a418
  call arguments (RPM/filter/MAF wiring), and the 0x306e8 lookup_3d
  arguments (RPM via delay slot, load in fr5) were each checked against
  `decompiled/firmware_disassembly.asm`.

## 9. Limits

Static analysis only; nothing was executed on hardware. Validation proves
byte/linkage consistency, not semantic equivalence or correct function
boundaries. Unit interpretations remain **candidates**: the 0.6345 and
0.07196 scale constants (their numerology is not evidence), the throttle
fallback affine (0.04/0.26), the 369.472/475.93 timer constants, and the
grams-per-second reading of the MAF scaling table. Untraced in this pass:
`DAT_ffffbe1c` (MAP-estimate scale factor), the `DAT_ffffad48` fallback
input, the 0x19640 snap-trigger caller, the baro sensor's ADC channel, and
the output-timer-channel-to-physical-injector mapping. Candidate aliases are
not factory symbols; they must not be presented as verified names until the
integration pass and its validators pass.

## 10. Labeling applied (2026-10-30 pass, recorded 2026-10-31 for the report validator)

The 2026-10-30 fueling-chain labeling pass integrated **39 function aliases,
150 RAM aliases and lookup aliases** into the synchronized views
(`data/labels/60E15120_N3J1E/fueling_labels.json`;
`source_review/accepted_function_aliases.tsv` / `accepted_ram_aliases.tsv`;
`integrated_names.json`; evidence in `reviews/load_fueling_model/` incl.
`REVIEW_NOTES.md` + `validation.json`; backup
`backups/pre_fueling_labels.zip`). Key named rows: `calculate_engine_load`
(RAM 0xffffc0b4), injector pulse path 0x8a68/0x30948/0x2fea8, MAF scaling
0x69788, latency tables 0x6aa80/0x6aa64, warmup family 0x6ae28-0x6ae74.

## 11. Memory map

Function and RAM addresses for this subsystem are enumerated in
`data/labels/60E15120_N3J1E/fueling_labels.json` (function_aliases/ram_aliases
with per-item evidence) and in the canonical index
`reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv` +
`symbols.tsv`; the cal-table addresses are in section 4 above. The report
validator (`utilities/scripts/rx8-pcm-pipeline/validate_reports.py`, run from
the repo root) checks every address here against those indexes and the ROM
SHA-256.

---

## Update 2026-10-31 (ROADMAP group C): engine-load units settled — D5 closed

Cross-check of the RX8Club thread's load/fueling claims against the ROM
([`docs/references/rx8club-user-guide-thread.md`](../../references/rx8club-user-guide-thread.md)
§6/§9) plus the D5 numeric comparison. All constants re-read from the raw ROM
(SHA-256 unchanged, `a7cd953c…264f1`).

**Byte-verified chain.** 0x1a418 `candidate_maf_per_rotation_calc`:
`maf_per_rotation_ffffaa3c = min(maf × 60.0 / rpm, 5.0)` — 60.0 is float32
`0x42700000` at 0x1a4e8, 5.0 is `0x40a00000` at 0x1a4f4 (g/rev, software cap 5.0).
0x33a6c `ref_airPerStroke`: `engine_load_raw_ffffc0b0 = maf_per_rotation × 0.6345` —
the 0.6345 float32 `0x3f226e98` lives at 0x7a088, reached via pool word 0x33b70
(only u32 ref), operands via mov.w low16 0xaa3c (0x33b52) and 0xc0b0 (0x33b54).
0x33ad2 `calculate_engine_load`: `engine_load_ffffc0b4 = min(filter(c0b0, 0.2 or 1.0),
c0b8)`, forced 0.525 on cranking/injector-off edge. PID 0x43: handler 0x56b8a →
jsr via pool 0x56c64 → 0x55748 `diag_encode_load_g_rev` →
`rx8_encode_u16_affine_saturate(c0b4, step 0x3b808080, 0)` with the step float at
0x55824 (mov.w 0x557ee → 0xffffc0b4); 0x3b808080 = 0.003921568 ≈ 1/255, matching the
logger scaling 0.0039215684.

**Numeric unit resolution (D5).** 1/0.6345 = 1.576 g per cell unit = 1.308 L
(2 × 654 cc) × 1.205 g/L — i.e. the cell is **VolEf at ~20 °C air density**, not
g/rev: cell = g/rev × 0.6345. Proof by the clamp: `engine_load_max_ffffc0b8` =
tbl_0x6b200(IAT) × tbl_0x6b214(baro) × tbl_0x6b1ec(RPM), each uint16 with
multiplier 1/32768 (descriptors' scaled words at 0x6b20c/0x6b220/0x6b1f8), giving
**0.58–1.29 cell units** over IAT −40…100 °C, baro 101.3 kPa, 1000–6000 rpm —
which equals 0.92–2.03 g/rev. That range matches the load axes of the extracted
tables the same cell indexes (`data/maps/60E15120_N3J1E/`): tbl_06aa48 axis_y
0.0625–1.25, tbl_06ac88 axis_y 0.125–1.203, tbl_06a9a4 axis_y 0.125–0.875. If the
cell were g/rev, a max-load clamp of 0.58–1.29 g/rev would be physically absurd at
WOT and the 5.0 g/rev cap would be unreachable.

**Thread claims corrected:**
- "Control load = MAF × rpm / 60" is dimensionally wrong; the ROM computes
  MAF × 60 / rpm (g/s × 60 ÷ rpm = g/rev) — 0x1a418.
- "× 0.6345 → g/combustion-event" is wrong (g/event = g/rev ÷ 2); 0.6345 is the
  VolEf factor 1/(1.308 L × 1.205 g/L).
- "PID 0x43 = engine load in g/rev" — PID 0x43 reports the cell × 1/255, i.e.
  **VolEf**, not g/rev (the thread's VolEf-vs-g/rev debate resolves to VolEf,
  confirming the log-based poster; the g/rev value is cell ÷ 0.6345).
- Cap "clipped at 5.0" ✓ — but it applies to g/rev *before* the 0.6345 scale.

D5 is therefore **settled**: `engine_load_ffffc0b4` and PID 0x43 are in VolEf-like
cell units (g/rev × 0.6345); the handler side (×1/255, 0.42 → raw 107) was already
dynamically verified 2026-10-31. The inherited name `diag22_pid0043_engine_load_g_rev`
stays (label ladder — not renamed on this evidence alone), but its header comment
now records the VolEf unit.
