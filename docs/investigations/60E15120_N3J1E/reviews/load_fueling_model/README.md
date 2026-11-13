# Targeted static review: engine load and fuelling model

Scope: the MAF-to-injector fuelling chain of 60E15120_N3J1E (RX-8 PCM,
SH7055 / SH-2E): MAF acquisition and validation, engine-load calculation,
manifold-pressure estimation, fuel-volume request, and the per-injector
split down to the output timers. Read from the canonical export
(`decompiled/`), the disassembly, and the untouched ROM; key float literals
were re-verified from ROM bytes. No firmware changes were made; the ROM is
untouched (SHA-256 recorded in `validation.json`).

This pass is a **findings review**: the chain is documented and evidence-ranked
here, with candidate aliases in the TSVs. The names have NOT yet been
integrated into the export views (no rename pass was run) — that integration
is the follow-up work listed at the end.

## 1. Chain overview

```
ADC sweep 0x6884 ref_sensorADCRead (32 channels)
  MAF raw = ADDR3 -> RAM 0xffff9eea

ISR 0x63f0 -> 0x114b0 -> 0x19806 -> 0x19f4e ref_MAFRelated   (MAF plausibility)
  a9e4 = MAF volts (x5/65536 affine), a9e8 = scaled MAF g/s from 0x7438

task[5] 0x65f6 ref_task1_ -> 0x11b7e -> 0x19794  (MAF smoothing / fallback)
  -> 0x1a13c fallback throttle airflow model aa28 (used when c590 set)
  -> 0x1a086 buffer average + density cap -> mass_air_flow 0xffffa9ec
  -> 0x3b214 MAF fault management (0.64 V / 4.9 V checks -> c590 fallback flag)

task[6] 0x661e ref_task2_ -> ref_engineControlTASK 0x11ba4 -> 0x197be
  -> 0x1a1dc transient detection (raw-vs-filtered MAF select flag aa4c)
  -> 0x1a418 airflow index aa3c = min(MAF x 60/RPM, 5.0)   [g/rev, capped]
  -> 0x33a6c ref_airPerStroke: c0b0 = aa3c x 0.6345
  -> 0x33ad2 ref_calculateEngineLoad: engine_load 0xffffc0b4
              = min(first-order filter of c0b0, max-load cap c0b8)
              crank/injectors-off state forces load = 0.525
  -> 0x33ab0 ref_getMaxLoadCompensations: c0bc = f(IAT), c0c0 = f(baro)
  -> 0x33a7c ref_calculateEngineLoadMax: c0b8 = c0bc x c0c0 x f(RPM)

fuelling task 0x20e40 (three interrupt-masked phases)
  phase 2:
  -> 0x2fdb0 MAP estimate: be00 = f(RPM, load; tbl 0x6aa48 "Estimated
           Manifold Pressure") x (IAT+273) x be1c / 300.0   [no MAP sensor]
  -> 0x2fe00 relative pressure = baro - MAP estimate
  -> 0x2fe1e per-injector manifold-relative multipliers (0x6aa0c/0x6aa20/0x6aa34)
  -> 0x306e8 ref_calcFuelVolumeRequest: base = load x 0.07196;
             x lookup3d(RPM, load; 0x6ac88 "Engine Load Compensation")
             x enrichment sum x fuel-target multiplier 0xffffadec
             + diagnostic trim adder (0x5c024) -> beac, beb0
  -> 0x30948 per-rotation window/duration constants (369.472 / 475.93 families)
  -> 0x30030 per-channel clamps [1024, f(RPM; tbl 0x6aa9c)]
  -> 0x2fea8 ref_injectorPulseTimeArbitrate_crankAddTimer (cranking add)
  0x21186 -> 0x2ff78 injector latency: lookup3d(MAP-est, battery; 0x6aa80)
             -> ref_setFuelInjectorLatency per channel

output timers 0x8a68 ref_injectorPulseSet / 0x8814 / 0x8344 (6 channels,
  0x18-stride RAM records at 0xffffa004) -> ATUII timer compare pulses
```

## 2. Load calculation semantics (verified)

- `engine_load_ffffc0b4` (the value every RX8Defs table calls "load") is a
  **filtered, capped airflow index, not a percentage of anything measured**:
  - upstream index `aa3c = min(MAF_used x 60.0/RPM, 5.0)` — air per
    engine revolution, capped at 5 (ROM literals 60.0 @0x1a4e8, 5.0 @0x1a4f4);
  - scaled by 0.6345 (ROM @0x7a088, referenced by `ref_airPerStroke`
    via literal pointer @0x33b70). The physical meaning of 0.6345 is
    **unresolved** — it is not the obvious 1.5 (2 rotors fire once per e-shaft
    rev) or 2/3 factor; do not assign units to it;
  - first-order filtered (coeff 0.2; snap coeff 1.0 while `DAT_ffffc0c4`
    counts down from 25, set by 0x19640) and clamped to the max-load product.
- The crank/injectors-off branch pins load to **0.525** — an important
  baseline for anyone reading logs during cranking.
- Max-load cap = `f(IAT; tbl 0x6b200) x f(baro; tbl 0x6b214) x f(RPM;
  tbl_rpm_based_max_engine_load 0x6b1ec)` — air-density compensated ceiling.

## 3. MAF handling and failure model (verified)

- MAF is ADC **channel 3** (`0xffff9eea` ← ADDR3H in `ref_sensorADCRead`).
- `ref_getMAFSensorValue` (0x7438): volts = raw x 5/65536, then the RX8Defs
  "MAF Scaling" table (0x69788) -> g/s at 0xffff9f78; separate status flags
  (raw < 0xac0 / >= 0xfae2) at 0xffff9f7c.
- `ref_MAFRelated` (0x19f4e): keeps two saturating excursion counters
  (raw >= 0xf852 high, raw < 0x7ae low). The validated copies a9e4 (volts) /
  a9e8 (g/s) are updated when the raw value is in range **or** when a counter
  has saturated (>= 3); only 1–2 sample excursions are held out. Disassembly
  verified at 0x19fa8–0x19fe8. Interpretation: transient spikes are debounced;
  a sustained fault must propagate so the fault manager can see it.
- Fault manager `FUN_0003b214`: a9e4 < 0.64 V (low) and > 4.9 V (high) checks,
  gated by battery >= 8 V and RPM windows (500 / 6500) with 4-count debounces
  and fault slots 10/11; sets `DAT_ffffc590` = 1 to switch the fuel source to
  the **throttle-based fallback model**.
- Fallback `FUN_0001a13c`: `aa28 = ((throttle x 0.04 + 0.26) x RPM) / 60`.
  This is the documented MAF-failure fuelling path; unit interpretation of
  the 0.04/0.26 affine is a candidate, not established.
- Density cap `FUN_0001a086`: MAF used = min(2-sample buffer average,
  `f(RPM; tbl 0x69794) x 293.0/(IAT+273) x baro/101.33299`). **The reference temperature literal is 293.0 K (0x43928000 @0x1a198), not
  295** (documentation-only; all synchronized views carry 293.0).

## 4. Manifold pressure is estimated, and baro is real (verified)

- There is **no measured MAP** in the fuelling model. `FUN_0002fdb0` estimates
  absolute manifold pressure from the RX8Defs "Estimated Manifold Pressure"
  3D table (0x6aa48, RPM x load) scaled by (IAT+273) x `DAT_ffffbe1c` / 300.0.
  Relative pressure (used by the injector vacuum multipliers 0x6aa0c/0x6aa20/
  0x6aa34 and latency table 0x6aa80) = baro − estimate (0x2fe00).
- Barometric pressure **is** measured: `ref_getBaroSensorVal` (0xd144):
  kPa = raw x 25.325 + 0.0182, selected into 0xffffad14 by 0x1ad54
  (default 101.3 kPa when a flag forces it). The sensor input channel is not
  traced in this pass — hardware routing remains unverified.

## 5. Fuel volume request (verified, one ABI caveat)

`ref_calcFuelVolumeRequest` (0x306e8):
- `bed0 = engine_load x 0.07196` (literal @0x78170) — the load-to-fuel scale;
- `bed4 = lookup3d(RPM, load; tbl_fuel_injection_engine_load_compensation
  0x6ac88)` — the decompiler prints only the RPM argument; the load argument
  was verified present in fr5 at the call site (0x3070a, delay-slot fmov) —
  this is the ROM's RPM x load base fuel map;
- the request = base x enrichment sum x `DAT_ffffadec` (fuel-target / lambda
  multiplier, 1.0 default, closed-loop trim applied here) x bed4, plus a
  **diagnostic trim adder** `FUN_0005c024`: a diagnostic request identifier
  0x17e0 with command 7 adds a u8 affine offset (scale 1/256, offset −0.5) to
  the request — a service-tool proportional-trim pathway (candidate);
- output `beb0` feeds the per-rotation timers and the decel-cut comparisons.

Per-injector structure: three fuel channels (primary / secondary-1 /
secondary-2 groupings per `ref_getInjectorTempBasedMultiplierLookups` 0x2fd3e
with weighted-engine-temp x load tables 0x6a9a4/0x6a9c0/0x6a9dc), latency per
channel from 0x6aa80, six output timer records at 0xffffa004. The exact
timer-channel-to-physical-injector mapping is not established here.

## 6. New table candidates for RX8Defs

Tables used by this chain with **no RX8Defs match** in
`labeling/cross_ecu/romraider_descriptor_matches.json` (candidate definitions,
needs dimension/storage verification before any def work):

| Descriptor | Read by | Interpretation (candidate) |
|---|---|---|
| 0x69794 | 0x1a086 | MAF density-cap window vs RPM |
| 0x697a0 | 0x1a1dc | transient-detection threshold vs throttle |
| 0x697b4 | 0x1a418 | MAF filter coefficient vs RPM |
| 0x6aa9c | 0x30030 | max per-channel injection time vs RPM |
| 0x6ac38 | 0x306e8, 0x307e0 | coolant-based enrichment/fuel adder |

Already matched and confirmed in-role by this trace: 0x69788 (MAF Scaling),
0x6aa48 (Estimated Manifold Pressure), 0x6ac88 (Engine Load Compensation,
inputs verified as RPM x load), 0x6aa80 (injector latency), 0x6b1ec/0x6b200/
0x6b214 (max-load family), 0x6a9a4/0x6a9c0/0x6a9dc (injector temp multipliers),
0x6aa0c/0x6aa20/0x6aa34 (manifold-relative multipliers), 0x6ab48/0x6ab98/
0x6abc8/0x6bab0 (cranking family).

## 7. What this pass did not establish

- Physical meaning of the 0.6345 and 0.07196 scale constants (unit
  interpretations remain open; numerology is not evidence).
- The `DAT_ffffbe1c` factor in the MAP estimate (candidate: volumetric-efficiency
  correction from another table lookup — its writer was not traced).
- Channel-to-injector hardware mapping; sensor ADC channel for baro.
- The exact scheduler tick / phase relationship between 0x19794 and 0x197be.
- Hardware behavior: all findings are static; nothing was executed.

## 8. Follow-up work

1. Integrate the candidate aliases of this review into the export views
   (rename pass + `metadata/integrated_names.json` update + validators), if
   accepted.
2. Verify the five new table candidates against the RX8Defs merge workflow
   (`reverse_engineered/Defs/`) before proposing definitions.
3. Trace `DAT_ffffbe1c` and the 0x19640 snap-trigger context.

Evidence details per function: [`REVIEW_NOTES.md`](REVIEW_NOTES.md). Candidate names:
`candidate_function_aliases.tsv`, `candidate_ram_aliases.tsv`.
