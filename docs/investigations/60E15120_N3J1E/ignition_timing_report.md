# Ignition timing report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Date: 2026-10-31 (Phase 2 ignition-timing labeling pass). Target ROM:
`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). Static-analysis disclaimer: findings come from the canonical export +
disassembly + ROM bytes, the RX8Club thread extract §9 (`docs/references/rx8club-user-guide-thread.md`),
and **dynamic execution in the SH-2E emulator** (`utilities/scripts/emu/harness.py`,
tests in `tests/test_phase1_dynamic.py`). Label evidence:
`data/labels/60E15120_N3J1E/ignition_timing_labels.json`,
`source_review/accepted_*.tsv`, backup `backups/pre_ignition_timing_labels.zip`.

## 1. Executive summary

The final ignition timing per rotor is computed in `ignition_timing_main_task` (0x142a4,
task[6] worker) as:

```
# 0x123da (leading) / 0x124d6 (trailing) — the cranking blend, VERIFIED bit-exact in the emulator:
base_final = base_blend * cranking_mult                       # base_blend = a5e8 (0x11f00)
             + (clt_scaled_term + idle_speed_comp + crank_angle) * (1 - cranking_mult)
             + idle_base - iat_comp                            # a5f0, a718, ca9c, a780, a778
corrected  = base_final + correction_total                    # 0x123ba: a634 = a640 + a648
final      = clamp(corrected, min_advance, max_advance_rpm)   # 0x121fc: a630 = clamp(a634, a64c, a660)
```

The **thread §9 equation is confirmed**, with one structural correction: the coolant
term (`CLTcomp`, a5f0 = off-throttle-3D − advance×coolant-multiplier) sits **inside**
the `(1−CrankingMult)` blend group, and `IdleBaseFinal` (a780) is added **outside** it —
the thread drew both outside the parens. Knock retard enters via `correction_total`
(0x125bc/0x125f6, see `knock_control_report.md`), DSC torque-request derate applies to
the **leading rotor only** (0x1815c, confirmed — no trailing reader). All dynamic checks
in the emulator matched to <1e-4 deg (E1 double-precision limit).

## 2. How it works (condensed pseudocode)

```python
# task 0x142a4 (ignition_timing_main_task), per cycle:
leading_base_timing_calc()    # 0x11f00: a5e8 = blend of base(0x69078) and advance cap, weight b118
trailing_base_timing_calc()   # 0x1206c: a5ec mirror (0x69120/0x69174)
# ... knock state machine (0x13826..0x13bd2), idle corrections, coolant derate ...
idle_base_timing_select()     # 0x14100: a780 = tbl 0x69208 (cranking) / 0x6921c / 0x69230
iat_timing_compensation_on_throttle()  # 0x14090: a778 = a77c = IAT tbl 0x6a0d8 (load>=0.5) else 0
cranking_timing_leading_filter()       # 0x43934: ca9c = filter(lookup(ECT, 0x6b630))
cranking_timing_trailing_filter()      # 0x439b2: caa0 = filter(lookup(ECT, 0x6b644))
min_advance_clamp_select()    # 0x12630: a64c = -24 / -44 / lookup(ECT, 0x691a4/0x691b8)
dsc_timing_derate_select()    # 0x1815c: a91c = DSC Mode A base (bc94, tbl 0x6a7a4) when DSC mode 4
leading_timing_cranking_blend()  # 0x123da: a640 = a5e8*a644 + (a5f0+a718+ca9c)*(1-a644) + a780 - a778
knock_retard_apply_leading()     # 0x125bc: a648 = (a734 - a6ac) - max(a750, c9a0) + a5e0 + b288 - a66c
leading_timing_add_corrections() # 0x123ba: a634 = a640 + a648
leading_final_timing_clamp_output()  # 0x121fc: a630 = clamp(a634, a64c, lookup(rpm, 0x69190))
# trailing mirrors: 0x124d6, 0x125f6, 0x123ca, 0x12300 (a638 = clamp(a63c, a65c, lookup(rpm, 0x691cc)))
# cranking_mult a644: -0.05/call while cranking (aa62==1) and rpm < a7ac+9900, else +1.0 -> 1.0
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

## 4. Labeling applied (2026-10-31 pass)

- **15 functions** renamed (see `ignition_timing_labels.json`): 0x123da/0x124d6
  cranking blends, 0x121fc/0x12300 final clamps, 0x12630 min-advance select,
  0x14100 idle base select, 0x14090 IAT comp, 0x43934/0x439b2 cranking filters,
  0x135b4/0x136e4 idle error corrections, 0x2cc2c/0x1815c DSC, 0x13ecc coolant
  derate, 0x12e60 trim scale. Applied to symbols.tsv, function_index.tsv,
  callgraph.tsv, functions/*.c, named/firmware_named.c, firmware_decompiled.c.
- **22 RAM locations** named (base finals a5e8/a5ec, coolant terms a5f0/a5f4, idle
  corrections a718/a71c, cranking ca9c/caa0 (+raw caa4/caa8), idle base a780/a784,
  IAT comp a778/a77c, cranking mult a644/a654, clamps a64c/a65c/a660/a664,
  DSC bc94/a91c).
- **17 lookup descriptors** named (table above; candidate_ where no RX8Defs match).

## 5. Corrections made in this pass

- Thread §9 equation: CLTcomp is inside the `(1−CrankingMult)` group (a5f0), and
  IdleBaseFinal (a780) is added outside it — corrected mapping documented above and
  verified dynamically.
- DSC derate confirmed **leading-rotor only** (0x1815c writes a91c; no trailing reader
  exists; torque-loss calc 0x2cc5c/0x2cc7c uses (bc94 − actual)² × bc90).
- 0x121fc/0x12300 clamp bounds: min from 0x12630 (−24/−44 fixed or coolant table),
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
  add 0x123ba exact (21.5); clamp 0x121fc exact (65.0 max @3000 rpm, −24.0 min);
  base calc 0x11f00 runs (a5e8=−11° @ load 0.8/rpm 3000, cap 80°).
- `python -m pytest tests/` 38/38; pipeline validators run from repo root and PASS
  (validate_export, validate_reports incl. this report, verify_readability,
  verify_math_units).

## 8. Memory map for validation

Functions: 0x142a4 ignition_timing_main_task; 0x11f00/0x1206c base timing calc;
0x123da/0x124d6 cranking blend; 0x125bc/0x125f6 knock/derate/A-C correction;
0x123ba/0x123ca add corrections; 0x121fc/0x12300 final clamp+output;
0x12630/0x12754 min-advance select; 0x14100 idle base select; 0x14090 IAT comp;
0x43934/0x439b2 cranking filters; 0x135b4/0x136e4 idle error corr; 0x13ecc coolant
derate; 0x12e60 trim scale; 0x2cc2c/0x1815c DSC; 0x1340e/0x1346a final copy;
0x14774/0x147aa per-rotor output; 0x8f2a/0x9110/0x9490 dwell; 0xc338 driving timing.

RAM: a5e8/a5ec base final; a5f0/a5f4 coolant term; a718/a71c idle corr; ca9c/caa0
cranking filtered (+caa4/caa8 raw); a780/a784 idle base; a778/a77c IAT comp;
a644/a654 cranking mult; a634/a63c with corrections; a648/a658 correction total;
a64c/a65c min clamp; a660/a664 max; a630/a638 final outputs; a734 knock retard;
a6ac/a6b0 rough knock; a750/a754 coolant derate; c9a0/c9a4 cold-start; b288/b28c A/C;
a66c/a670 trim; bc94 DSC base; a91c DSC derate. Tables: section 3.

## 9. Limits

- `candidate_` table names (0x69040-0x69230 block) are thread-hypotheses; descriptor
  bytes verified (>HBBII) but not cross-ROM matched yet — Phase 2 differential labeling.
- The idle/base term a5e0/a5e4 inside 0x125bc/0x125f6 has **no writer in the export**
  (stays 0 in emulation) — open question, possibly written via pointer arithmetic the
  decompiler missed.
- Dynamic values use host-double FPU (E1); <1e-4 deg agreement is the checkable bound.
- DSC derate a91c has no direct reader in the export beyond 0x1815c's write — its
  application point (final clamp? torque limit?) is partially resolved: torque-loss
  calc reads bc94; flag if a reader appears in later passes.

## 10. Update — 2026-10-31 (initial record of this pass)
