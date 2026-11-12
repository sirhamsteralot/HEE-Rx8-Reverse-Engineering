# Ignition timing report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM:
`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). Static-analysis disclaimer: findings come from the canonical export +
disassembly + ROM bytes, the RX8Club thread extract §9 ([`docs/references/rx8club-user-guide-thread.md`](../../references/rx8club-user-guide-thread.md)),
and **dynamic execution in the SH-2E emulator** (`utilities/scripts/emu/harness.py`,
tests in `tests/test_phase1_dynamic.py`). Label evidence:
`data/labels/60E15120_N3J1E/ignition_timing_labels.json`,
`source_review/accepted_*.tsv`, backup `backups/pre_ignition_timing_labels.zip`.

**Related reports:** [load & fuelling model](load_fueling_report.md) (engine-load axis), [knock control](knock_control_report.md) (retard enters via correction_total), [calibration extraction](calibration_extraction_report.md) (timing tables in data/maps/), [UDS/Mode-22 dispatch](uds_mode22_dispatch_report.md) — the final leading/trailing timing cells computed here are diag-exposed as PID 0x0e (`leading_ignition_timing_ffffa630` × 0.5 − 64, handler 0x569ae) and PID 0x0904 (`trailing_ignition_timing_ffffa638` × 0.5 − 64, handler 0x56cc8), scale constants verified in the handlers' literal pools; the DSC torque-request derate producer (`engine_max_torque_allowed` 0xffffbbd8 ← 0x2b3b8, consumed here at 0x1815c) is in [DSC CAN arbitration](dsc_can_arbitration_report.md).

## 1. Executive summary

The final ignition timing per rotor is computed in `ignition_timing_main_task` (0x142a4,
task[6] worker) as:

```
# 0x123da leading_timing_cranking_blend / 0x124d6 trailing_timing_cranking_blend — VERIFIED bit-exact in the emulator:
base_final = base_blend * cranking_mult                       # leading_base_timing_final 0xffffa5e8 (0x11f00)
             + (clt_scaled_term + idle_speed_comp + crank_angle) * (1 - cranking_mult)
             + idle_base - iat_comp                            # 0xffffa5f0, 0xffffa718, 0xffffca9c, 0xffffa780, 0xffffa778
corrected  = base_final + correction_total                    # 0x123ba: leading_timing_with_corrections 0xffffa634 = 0xffffa640 + 0xffffa648
final      = clamp(corrected, min_advance, max_advance_rpm)   # 0x121fc: leading_ignition_timing_ffffa630 0xffffa630 = clamp(0xffffa634, 0xffffa64c, 0xffffa660)
```

The **thread §9 equation is confirmed**, with one structural correction: the coolant
term (`CLTcomp`, `leading_coolant_scaled_advance_term` 0xffffa5f0 = off-throttle-3D − advance×coolant-multiplier) sits **inside**
the `(1−CrankingMult)` blend group, and `IdleBaseFinal` (`idle_base_timing_leading` 0xffffa780) is added **outside** it —
the thread drew both outside the parens. Knock retard enters via `correction_total`
(0x125bc/0x125f6, see [`knock_control_report.md`](knock_control_report.md)), DSC torque-request derate applies to
the **leading rotor only** (0x1815c, confirmed — no trailing reader). All dynamic checks
in the emulator matched to <1e-4 deg (E1 double-precision limit).

## 1a. Plain-language summary (maps vs. applied timing)

- The ROM's leading/trailing **maps** (tbl 0x69078 / 0x69120, rpm x load) are
  only a **base** starting point — they are *not* the timing that reaches the
  spark plugs.
- The PCM then adds corrections (coolant, intake air, idle, cranking blend,
  knock retard, DSC, A/C), blends during cranking via `cranking_mult`
  (0x123da/0x124d6), adds the correction total (0x123ba/0x123ca), and finally
  **clamps** the result between a min (-25.0/-58.5 deg or a coolant table,
  0x12630) and a max (rpm table 0x69190/0x691cc, e.g. 65 deg @ 3000 rpm)
  at 0x121fc/0x12300.
- Only that clamped value is written to the output RAM (0xffffa630 leading /
  0xffffa638 trailing) and drives the actual spark event per rotor
  (0x14774/0x147aa).
- So an **OBD/datalog timing value is the final computed (commanded) timing**,
  not a raw map cell — it can legitimately differ from the map at idle,
  cranking, cold start, or under knock retard. Even it is the *commanded*
  value; the physically applied spark can still be altered downstream (dwell,
  misfire cutoff), which is why the chain was verified dynamically in the
  emulator rather than from any single number.

## 2. How it works (condensed pseudocode)

```python
# task 0x142a4 (ignition_timing_main_task), per cycle:
leading_base_timing_calc()    # 0x11f00: 0xffffa5e8 = blend of base(0x69078) and advance cap, weight 0xffffb118 timing_blend_weight
trailing_base_timing_calc()   # 0x1206c: 0xffffa5ec mirror (0x69120/0x69174)
# ... knock state machine (0x13826..0x13bd2), idle corrections, coolant derate ...
idle_base_timing_select()     # 0x14100: 0xffffa780 = tbl 0x69208 (cranking) / 0x6921c / 0x69230
iat_timing_compensation_on_throttle()  # 0x14090: 0xffffa778 = 0xffffa77c = IAT tbl 0x6a0d8 (load>=0.5) else 0
cranking_timing_leading_filter()       # 0x43934: 0xffffca9c = filter(lookup(ECT, 0x6b630))
cranking_timing_trailing_filter()      # 0x439b2: 0xffffcaa0 = filter(lookup(ECT, 0x6b644))
min_advance_clamp_select()    # 0x12630: 0xffffa64c = -25.0 / -58.5 / lookup(a98c, 0x691a4/0x691b8)
dsc_timing_derate_select()    # 0x1815c: dsc_timing_derate_leading 0xffffa91c = dsc_mode_a_base_timing 0xffffbc94 (tbl 0x6a7a4) when DSC mode 4
leading_timing_cranking_blend()  # 0x123da: 0xffffa640 = 0xffffa5e8*0xffffa644 + (0xffffa5f0+0xffffa718+0xffffca9c)*(1-0xffffa644) + 0xffffa780 - 0xffffa778
knock_retard_apply_leading()     # 0x125bc: 0xffffa648 = (knock_retard_ffffa734 - rough_knock_correction_leading 0xffffa6ac) - max(coolant_timing_derate_leading 0xffffa750, cold_start_timing_reduction_leading 0xffffc9a0) + a5e0 + ac_compressor_leading_timing_retard 0xffffb288 - a66c
leading_timing_add_corrections() # 0x123ba: 0xffffa634 = 0xffffa640 + 0xffffa648
leading_final_timing_clamp_output()  # 0x121fc: 0xffffa630 = clamp(0xffffa634, 0xffffa64c, lookup(rpm, 0x69190))
# trailing mirrors: 0x124d6, 0x125f6, 0x123ca, 0x12300 (0xffffa638 = clamp(0xffffa63c, 0xffffa65c, lookup(rpm, 0x691cc)))
# cranking_timing_multiplier_leading 0xffffa644: -0.05/call while cranking (cranking_active_ffffaa62 0xffffaa62==1) and rpm < 0xffffa7ac+9900, else +1.0 -> 1.0
```

## 3. Key calibrated tables (descriptor addresses; >HBBII parsed from ROM bytes)

| Descriptor | RX8Defs name (thread 60E0FC00 tree) | Used by |
|---|---|---|
| 0x69078 | Ignition Leading - Base Timing (3D float, deg) | 0x11f00 |
| 0x690cc | Ignition Timing Leading Advance | 0x11f00 (cap) |
| 0x69120 / 0x69174 | Ignition Timing Trailing Base / Advance | 0x1206c |
| 0x69040 / 0x6905c / 0x69018 | off-throttle 3D / advance 3D / coolant multiplier (candidate_) | 0x11f00 |
| 0x69208 / 0x6921c / 0x69230 | Idle Base Timing (cranking / cold-lowload / warm-highload; candidate_) | 0x14100 |
| 0x691a4 / 0x691b8 | Minimum Advance vs coolant (candidate_) | 0x12630 |
| 0x69190 / 0x691cc | Max advance vs rpm, leading/trailing (candidate_) | 0x121fc / 0x12300 |
| 0x6a060 / 0x6a074 / 0x6a088 / 0x6a09c | Idle Error Timing Correction bool false/true, leading/trailing (deg) | 0x135b4 / 0x136e4 |
| 0x6a0d8 / 0x6a0ec | IAT Compensation - On Throttle / Table 2D - 113 (cranking) | 0x14090 |
| 0x6af2c / 0x6b644 | Ignition Leading/Trailing - Cranking Timing Advance (deg, vs ECT) | 0x43934/0x439b2 via 0x6b630 |
| 0x6b630 | Off Throttle Leading Timing Realted (deg, vs ECT) | 0x43934 |
| 0x6a7a4 / 0x6957c | Ignition Timing Leading - DSC Mode A - Base / Map 4 | 0x2cc2c / 0x1815c |

Descriptors not present in `romraider_descriptor_matches.json` are labeled
`candidate_` (thread names are hypotheses until cross-ROM matched).

## 4. Labeling applied

- **15 functions** renamed (see `ignition_timing_labels.json`): 0x123da/0x124d6
  cranking blends, 0x121fc/0x12300 final clamps, 0x12630 min-advance select,
  0x14100 idle base select, 0x14090 IAT comp, 0x43934/0x439b2 cranking filters,
  0x135b4/0x136e4 idle error corrections, 0x2cc2c/0x1815c DSC, 0x13ecc coolant
  derate, 0x12e60 trim scale. Applied to symbols.tsv, function_index.tsv,
  callgraph.tsv, functions/*.c, named/firmware_named.c, firmware_decompiled.c.
- **24 RAM locations** named in `ignition_timing_labels.json` +
  [accepted_ram_aliases.tsv](source_review/accepted_ram_aliases.tsv): base finals
  `leading_base_timing_final` 0xffffa5e8 / `trailing_base_timing_final` 0xffffa5ec,
  coolant terms 0xffffa5f0/0xffffa5f4, idle corrections 0xffffa718/0xffffa71c,
  cranking angle 0xffffca9c/0xffffcaa0 (+raw 0xffffcaa4/0xffffcaa8), idle base
  0xffffa780/0xffffa784, IAT comp 0xffffa778/0xffffa77c, cranking mult
  0xffffa644/0xffffa654, clamps 0xffffa64c/0xffffa65c (min) and 0xffffa660/0xffffa664
  (max), with-corrections 0xffffa634/0xffffa63c, correction total 0xffffa648/0xffffa658,
  final outputs `leading_ignition_timing_ffffa630` 0xffffa630 /
  `trailing_ignition_timing_ffffa638` 0xffffa638, DSC `dsc_mode_a_base_timing`
  0xffffbc94 / `dsc_timing_derate_leading` 0xffffa91c. Correction inputs named in
  the same TSV: `knock_retard_ffffa734`, `rough_knock_correction_leading/trailing`
  0xffffa6ac/0xffffa6b0, `coolant_timing_derate_leading/trailing` 0xffffa750/0xffffa754,
  `cold_start_timing_reduction_leading/trailing` 0xffffc9a0/0xffffc9a4,
  `ac_compressor_leading/trailing_timing_retard` 0xffffb288/0xffffb28c,
  `timing_blend_weight` 0xffffb118, `cranking_active_ffffaa62` 0xffffaa62.
  The 18 leading/trailing chain cells (base finals, coolant terms, cranking
  multipliers, min/max clamps, with-corrections, idle error corrections, IAT
  comp, idle base) each carry a binary-level store/pool citation in both the
  TSV and the labels JSON — re-verified against the raw ROM in §10 below.
- **17 lookup descriptors** named (table above; candidate_ where no RX8Defs match).

## 5. Corrections made in this pass

- Thread §9 equation: CLTcomp is inside the `(1−CrankingMult)` group (0xffffa5f0), and
  IdleBaseFinal (a780) is added outside it — corrected mapping documented above and
  verified dynamically.
- DSC derate confirmed **leading-rotor only** (0x1815c writes `dsc_timing_derate_leading`
  0xffffa91c; no trailing reader exists; torque-loss calc 0x2cc5c/0x2cc7c uses
  (`dsc_mode_a_base_timing` 0xffffbc94 − actual)² × bc90).
- 0x121fc/0x12300 clamp bounds: min from 0x12630 (−25.0/−58.5 fixed or coolant table; constants ROM-verified: 0xc1c80000, 0xc26a0000),
  max from rpm tables 0x69190/0x691cc (65° at 3000 rpm observed in emulator).

## 6. Files

- `data/labels/60E15120_N3J1E/ignition_timing_labels.json` (with thread-equation verdict)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram,lookup}_aliases.tsv` (appended)
- `reverse-engineered/decompiled/60E15120_N3J1E/`: symbols.tsv, function_index.tsv,
  callgraph.tsv, functions/*.c, named/firmware_named.c, firmware_decompiled.c
- `data/labels/60E15120_N3J1E/integrated_names.json`
- `tests/test_phase1_dynamic.py` (2 new dynamic tests: blend equation, add+clamp)
- backup: `docs/investigations/60E15120_N3J1E/backups/pre_ignition_timing_labels.zip`

## 7. Validation

- ROM bytes untouched (`rom_unchanged`); every aliased address present in function_index.tsv.
- Dynamic (emulator, `tests/test_phase1_dynamic.py`): blend 0x123da/0x124d6 bit-exact
  (25.775 / 36.5 / 18.115 deg for scripted inputs, both cranking states, both rotors);
  add 0x123ba exact (21.5); clamp 0x121fc exact (65.0 max @3000 rpm via tbl 0x69190; min-bound passthrough exact with a64c=−24.0)
  base calc 0x11f00 runs (`leading_base_timing_final` 0xffffa5e8=−11° @ load 0.8/rpm 3000, cap 80°).
- `python -m pytest tests/` 38/38; pipeline validators run from repo root and PASS
  (validate_export, validate_reports incl. this report, verify_readability,
  verify_math_units, verify_claims).
- Source-review sweep (this pass): every RAM cell named above was re-read from the
  raw ROM literal pools this session — e.g. the 0x123da pool at 0x12532-0x12562
  holds 0xffffaa62/0xffffa718/0xffffa5f0/0xffffca9c/0xffffa5e8/0xffffa780/0xffffa778/
  0xffffa644/0xffffa640 exactly as mapped — and the §1/§2/§4/§8 texts now use the
  promoted alias names from
  [accepted_ram_aliases.tsv](source_review/accepted_ram_aliases.tsv) +
  `ignition_timing_labels.json` instead of raw `a5e8`-style cells. Unlabeled cells
  (0xffffa66c/0xffffa670 trim, 0xffffa5e0/0xffffa5e4) stay raw per the label ladder.

## 8. Memory map for validation

Functions: 0x142a4 ignition_timing_main_task; 0x11f00/0x1206c base timing calc;
0x123da/0x124d6 cranking blend; 0x125bc/0x125f6 knock/derate/A-C correction;
0x123ba/0x123ca add corrections; 0x121fc/0x12300 `trailing_final_timing_clamp_output` final clamp+output;
0x12630/0x12754 min-advance select; 0x14100 idle base select; 0x14090 IAT comp;
0x43934/0x439b2 cranking filters; 0x135b4/0x136e4 idle error corr; 0x13ecc `coolant_timing_derate_calc` coolant
derate; 0x12e60 `timing_trim_scale_calc` trim scale; 0x2cc2c `dsc_mode_a_base_timing_lookup`/0x1815c `dsc_timing_derate_select` DSC; 0x1340e/0x1346a final copy;
0x14774/0x147aa per-rotor output; 0x8f2a/0x9110/0x9490 dwell; 0xc338 driving timing.

RAM: 0xffffa5e8/0xffffa5ec `leading/trailing_base_timing_final`; 0xffffa5f0/0xffffa5f4
`leading/trailing_coolant_scaled_advance_term`; 0xffffa718/0xffffa71c `idle_leading/trailing_timing_error_correction`;
0xffffca9c/0xffffcaa0 `cranking_angle_timing_leading/trailing_filtered` (+raw 0xffffcaa4/0xffffcaa8);
0xffffa780/0xffffa784 `idle_base_timing_leading/trailing`; 0xffffa778/0xffffa77c `iat_timing_compensation_leading/trailing`;
0xffffa644/0xffffa654 `cranking_timing_multiplier_leading/trailing`; 0xffffa634/0xffffa63c
`leading/trailing_timing_with_corrections`; 0xffffa648/0xffffa658 `leading/trailing_timing_correction_total`;
0xffffa64c/0xffffa65c `leading/trailing_min_advance_clamp`; 0xffffa660/0xffffa664 `leading/trailing_max_advance`;
0xffffa630/0xffffa638 `leading_ignition_timing_ffffa630`/`trailing_ignition_timing_ffffa638` final outputs;
0xffffa734 `knock_retard_ffffa734`; 0xffffa6ac/0xffffa6b0 `rough_knock_correction_leading/trailing`;
0xffffa750/0xffffa754 `coolant_timing_derate_leading/trailing`; 0xffffc9a0/0xffffc9a4
`cold_start_timing_reduction_leading/trailing`; 0xffffb288/0xffffb28c `ac_compressor_leading/trailing_timing_retard`;
0xffffa66c/0xffffa670 trim (unlabeled); 0xffffbc94 `dsc_mode_a_base_timing`; 0xffffa91c `dsc_timing_derate_leading`;
0xffffbbd8 `engine_max_torque_allowed` (written by 0x2b3b8 in the DSC CAN batch, consumed here at 0x1815c).
Tables: section 3.

## 9. Limits

- `candidate_` table names (0x69040-0x69230 block) are thread-hypotheses; descriptor
  bytes verified (>HBBII) but not cross-ROM matched yet — Phase 2 differential labeling.
- The idle/base term a5e0/a5e4 inside 0x125bc/0x125f6 has **no writer in the export**
  (stays 0 in emulation) — open question, possibly written via pointer arithmetic the
  decompiler missed.
- Dynamic values use host-double FPU (E1); <1e-4 deg agreement is the checkable bound.
- DSC derate `dsc_timing_derate_leading` 0xffffa91c has no direct reader in the export
  beyond 0x1815c's write — its application point (final clamp? torque limit?) is
  partially resolved: torque-loss calc reads `dsc_mode_a_base_timing` 0xffffbc94;
  flag if a reader appears in later passes. The 0xffffbbd8 input is produced in the
  DSC CAN batch ([`dsc_can_arbitration_report.md`](dsc_can_arbitration_report.md)).

## 10. Binary-level re-verification

The labels are checked against raw ROM bytes + disassembly (literal pools resolved;
note this disassembly prints the *computed* EA in `@(disp,pc)`, and `mov.w
@(disp,pc)` **sign-extends** on this core, so 16-bit literals like 0xa5e8 are
RAM 0xffffa5e8):

- Blend 0x123da/0x124d6: `fmac` at 0x124c2/0x125a8 confirmed bit-for-bit:
  `a640 = a5e8*a644 + (a718+a5f0+ca9c)*(1-a644) + a780 - a778` (trailing mirrors
  into a650). Alias map for these cells: 0xffffa5e8 `leading_base_timing_final`,
  0xffffa644 `cranking_timing_multiplier_leading`, 0xffffa718 `idle_leading_timing_error_correction`,
  0xffffa5f0 `leading_coolant_scaled_advance_term`, 0xffffca9c `cranking_angle_timing_leading_filtered`,
  0xffffa780 `idle_base_timing_leading`, 0xffffa778 `iat_timing_compensation_leading`
  (literal pool at 0x12532-0x12562 re-read from ROM this pass — values match).
  Constants at 0x6d778=10000.0, 0x6d77c=100.0, 0x6d764=0.05,
  0x6d768=1.0; 0x23e4=max, 0x23f4=min → cranking mult update
  `max(a644-0.05,0)` / `min(a644+1,1)` exactly as documented.
- Clamp 0x121fc/0x12300: `a630 = clamp(corrected, a64c, lookup(b548, 0x69190))`
  via 0x2404 (3-arg clamp); 2000.0 rpm gate (mova 0x122e4), aa62/ce1c/bbce
  conditions, helper 0x2440 = out-of-band detector (|x|>tol). Confirmed.
- Lookup 0x2068 on tbl 0x69190 (axis 800..7200 step 800 @0x6d7a0) returns
  **65.0 deg at 3000 rpm** in the emulator (also 65.0 across 0..9000 rpm —
  flat-topped table after the descriptor's 0.5/-40 affine map). Confirmed.
- **Correction:** min-advance fixed constants in 0x12630/0x12754 are
  **-25.0** (0xc1c80000 @0x6d76c/0x6d794) and **-58.5** (0xc26a0000
  @0x6d770/0x6d774). Branch structure confirmed
  in emulator: cranking(aa62==1) && a66c in band -> -25.0; cranking && a66c
  out of band -> lookup(a98c, 0x691a4); else if a750,c9a0 in band or
  load-high a66a -> -58.5; else lookup(a98c, 0x691b8). a66a hysteresis:
  set when c0b4 > 0.5, cleared at <= 0.45 (0x6d780=0.5, 0x6d784=0.05).
  The report, labels JSON, accepted_*.tsv and decompiled comments all carry the corrected values.
- Base calc 0x11f00 cap constant 80.0 (0x42a00000 @0x6c758/0x6c76c) confirmed.
- Leading/trailing chain RAM cells: every cell's writer store was re-traced to
  its literal-pool word in the raw ROM (mov.w pools sign-extend, mov.l pools
  carry the full 0xffff.... word), and the store instruction bytes were checked
  in the disassembly:
  - 0xffffa5e8 `leading_base_timing_final`: fmov.s fr2,@r2 0x11fe8, mov.w pool
    0x12010=0xa5e8 @0x11fdc (writer 0x11f00); read by 0x123da via pool 0x1253a @0x124b0.
  - 0xffffa5ec `trailing_base_timing_final`: fmov.s fr2,@r2 0x12154, pool
    0x1217c=0xa5ec @0x12148 (writer 0x1206c); read by 0x124d6 via pool 0x12688 @0x12594.
  - 0xffffa5f0 `leading_coolant_scaled_advance_term`: fmov.s fr2,@r1 0x11f60,
    pool 0x1200a=0xa5f0 @0x11f58 (writer 0x11f00); read by 0x123da via pool 0x12536 @0x124a0.
  - 0xffffa5f4 `trailing_coolant_scaled_advance_term`: fmov.s fr2,@r1 0x120cc,
    pool 0x12176=0xa5f4 @0x120c4 (writer 0x1206c); read by 0x124d6 via pool 0x12684 @0x12588.
  - 0xffffa644 `cranking_timing_multiplier_leading`: fmov.s fr0,@r14 0x1249c,
    mov.l pool 0x12548=0xffffa644 @0x12464 (writer 0x123da).
  - 0xffffa654 `cranking_timing_multiplier_trailing`: fmov.s fr0,@r14 0x12582,
    mov.l pool 0x1256c=0xffffa654 @0x12508 (writer 0x124d6).
  - 0xffffa64c `leading_min_advance_clamp`: fmov.s fr0/fr3,@r14 0x1270e/0x12738/0x12742,
    mov.l pool 0x127b8=0xffffa64c @0x126e8 (writer 0x12630); read by 0x121fc.
  - 0xffffa65c `trailing_min_advance_clamp`: fmov.s fr0/fr3,@r14 0x1281a/0x12844/0x1284e,
    mov.l pool 0x12868=0xffffa65c @0x127f4 (writer 0x12754); read by 0x12300.
  - 0xffffa660 `leading_max_advance`: fmov.s fr0,@r2 0x1229c, mov.l pool
    0x122f4=0xffffa660 @0x1229a (writer 0x121fc).
  - 0xffffa664 `trailing_max_advance`: fmov.s fr0,@r2 0x123a0, mov.l pool
    0x12430=0xffffa664 @0x1239e (writer 0x12300).
  - 0xffffa634 `leading_timing_with_corrections`: fmov.s fr2,@r3 0x123c8, mov.w
    pool 0x12410=0xa634 @0x123c4 (writer 0x123ba); read by 0x121fc (pool 0x122c6
    @0x1228a) and 0x2cc2c (pool 0x2cd54 @0x2ccc6).
  - 0xffffa63c `trailing_timing_with_corrections`: fmov.s fr2,@r3 0x123d8, mov.w
    pool 0x1240c=0xa63c @0x123d4 (writer 0x123ca); read by 0x12300 (pool 0x1240c @0x1238e).
  - 0xffffa718 `idle_leading_timing_error_correction`: fmov.s fr15,@r3 0x1368a,
    mov.w pool 0x136aa=0xa718 @0x13688 (writer 0x135b4); read by 0x123da (pool 0x12534 @0x1249e).
  - 0xffffa71c `idle_trailing_timing_error_correction`: fmov.s fr15,@r3 0x137ba,
    mov.w pool 0x137da=0xa71c @0x137b8 (writer 0x136e4); read by 0x124d6 (pool 0x12682 @0x12584).
  - 0xffffa778 `iat_timing_compensation_leading`: fmov.s fr5/fr0,@r14
    0x140b8/0x140d2/0x140d4, mov.w pool 0x140e2=0xa778 @0x14098 (writer 0x14090);
    read by 0x123da (pool 0x1253e @0x124bc).
  - 0xffffa77c `iat_timing_compensation_trailing`: fmov.s fr3,@r3 0x140da, mov.w
    pool 0x140ea=0xa77c @0x140d8 (writer 0x14090); read by 0x124d6 (pool 0x1268c @0x125a0).
  - 0xffffa780 `idle_base_timing_leading`: fmov.s fr0,@r14 0x14120/0x14146, mov.w
    pool 0x14158=0xa780 @0x1410a (writer 0x14100); read by 0x123da (pool 0x1253c
    @0x124b4) and 0x121fc (pool 0x122b8 @0x12200).
  - 0xffffa784 `idle_base_timing_trailing`: fmov.s fr3,@r3 0x1414c, mov.w pool
    0x1415e=0xa784 @0x1414a (writer 0x14100); read by 0x124d6 (pool 0x1268a
    @0x12598) and 0x12300 (pool 0x123fe @0x12304).
  These citations are stored verbatim as the evidence column of the
  [accepted_ram_aliases.tsv](source_review/accepted_ram_aliases.tsv) rows and the
  `evidence` fields in `ignition_timing_labels.json`.
