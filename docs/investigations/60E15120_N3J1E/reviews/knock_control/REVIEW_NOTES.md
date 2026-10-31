# Sceptical re-review of the knock control report — findings and corrections

Date: 2026-10-29. Scope: an independent, deliberately sceptical re-check of
`knock_control_report.md` and this folder's `README.md` against the ground
truth — the untouched ROM
(`Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`, 512 KiB,
SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`),
the disassembly (`decompiled/firmware_disassembly.asm`), the canonical export
(`decompiled/`) and both def sets (`RX8Defs/RomRaider/rx8_defs.xml`, ROM block
lines 26245–28033 for xmlid 60E15120/N3J1E; `RX8Defs/RomRaider/logger_rx8_defs.xml`).
Defs and labelling were treated as hypotheses throughout, per the evidence rules
in `AGENTS.md` (`ref_`/`CAL_`/`inferred_`/`candidate_` are not facts).

**Verdict: the report is substantially accurate** — the knock-control strategy,
every calibration table (byte-exact), the control signs and polarities, both
misnomer corrections, the clamp export-bug fix, the task/dispatch tables and the
`validate_export.py` numbers all re-verified cleanly. But the re-check found
**18 concrete discrepancies**, all now fixed in the analysis output; 3 further
issues are def-side and are documented here without touching the upstream def
repos.

## 1. Re-verified and confirmed (not restated in full)

ROM identity (hash, size, fw ID `60E15120` @0x2000, cal ID `N3ZHE` @0x6c046 —
the deliberate N3ZHE/N3J1E discrepancy kept); descriptor format (1D scaled 20 B,
1D raw 12 B, 3D 28/20 B, big-endian float32 axes); all 15+ tables byte-exact
(load floor 0x6af54, clamp min 0x6af68 + alt 0x6af7c, clamp max 0x6af90,
fail-safe 0x6afa4, learned scale 0x6afb8, volt→mag 0x6b250, transient hold
0x6b264, 3D levels 0x6b2b8/0x6b2f0/0x6b304, warmup 0x6990c, CLF thresholds
0x69d24–0x69d74, threshold A/B 0x6b270/0x6b288, base timing 0x69078/0x69120);
the control functions (attack −1.0°/cycle, recovery +0.35°/62 counts, the
genuine 0x13bd2 export-bug fix at disasm 0x13c18, the gate conditions,
`b12c=(b12a!=0)` and cruise-control misnomer fixes, rotor alternation 0xc8dc,
fault window 0xc290, health monitor 0x49fac, DTC raise 0x4a084, learn 0x139c4,
apply path 0x125bc/0x125f6/0x123ba/0x123ca, OL status 0x5535e); callgraph
edges; task table 0x4998 (incl. the extra record at 0x4ab8); dispatch records
0x5f124 (PID 0x0003) and 0x5f3e8 (PID 0x1746); the loop-mode claim (no
knock-chain function reads b12a/b12c/ae1e/ae1f; `b12c` readers are exactly
{0x1c13c, 0x1ee30, 0x1ee4a, 0x200c6, 0x22144}); the def cross-checks for this
ROM block (threshold A/B uint16 ×14 ×0.15625 ✓, volt→mag uint8 ×58 ✓,
"Ignition 4" uint8 ×12 ×0.5−50 ✓, CLF thresholds ✓, base timing leading/trailing
✓); and the closed-loop chain (0x1c13c CL-enable conditions, 0x1ee4a open-loop
fuel targets with safe-mode variants 0x69cac–0x69f44, 0x1f0c4 open-loop request
via the CLF threshold tables).

## 2. Discrepancies found and fixed

### Wrong constant values (report text, review README, TSVs and C comments)

1. **Transient noise-filter coeff `c060`** was stated as 0.15625; ROM @0x7a234
   = `0x3e400000` = **0.1875**. (0.15625 = `0x3e200000` is the threshold-A decode
   scale in 0x33970 — the two were conflated.) Calm `c060` = 0.0625 ✓.
   0x336c4 hardcodes `0x3e400000` on transient (`c05d==1`).
2. **`c064`** was stated as ~0.1289; actual `0x3e004ea5` = **0.1253**, in both
   the calm set (ROM 0x7a244) and the transient set (0x336c4 hardcodes it —
   c064 does *not* switch).
3. **`c068` calm** was stated as 0.0078125; actual ROM @0x7a248 =
   `0x3d000000` = **0.03125** (transient @0x7a23c = 0.09375 ✓). The code was
   correct; only comments/report text were wrong.
4. **Knock level default** was stated as 3.5; 0xc1f8 seeds
   `knock_level_threshold_ffffa328` from `0x406c0000` = **3.6875**.

### Logic / polarity errors

5. **`safe_mode_ffffcd60` polarity inverted** in README §1.3: text said the alt
   threshold tables are selected when `cd60 == 0`; the code is
   `if (cd60 == 0) normal else alt` → alt selected when `cd60` is **set**. (The
   `lookup_aliases.tsv` rows were already correct; only the README prose was
   wrong.)
6. **Threshold command base formula** was stated as "64 + a328*a360 clamped
   64..255"; the code is `a364 = clamp(a34c + a328*a360, 64, 255)` — the
   combined knock level `a34c` is an **addend**; 64 is only the clamp floor.
7. **Noise filter coefficient**: README said `filter(a330 − a348, c060)`; the
   code uses a hardcoded literal **0.0625** — matches calm `c060` but ignores
   the transient 0.1875.

### Diagnostics / def scepticism

8. **Knock Retard PID 0x1746 is degenerate**: handler 0x5707a encodes
   `knock_retard` (clamped to [−10, 0] — the retard-max table 0x6af90 is all
   0.0) via `rx8_encode_u8_affine_saturate(x, 0.3515625, 0)` =
   `clamp(trunc(x/0.3515625 + 0.5), 0, 255)` (FTRC truncates toward zero,
   verified at 0x24d0). Since x ≤ 0, **raw is always 0** — the PID always
   reports 0.00° in this ROM. The report's "(matches the [-10, 0] range)" was
   wrong; the encoding spans [0, +89.7]°. The logger def agrees with the
   firmware step (`expr="x*0.3515625"`) but is itself sloppy — see §3.
9. **Def "Knock Retard Max - Knock Sensor Faulted"** (base def: uint8, sizey=5,
   ×0.5−64, Engine Speed axis) **does not exist in this ROM** — no 5-cell
   ×0.5−64 table anywhere. This ROM's fail-safe table 0x6afa4 is 15 cells — a
   different table. The report wisely used its own name, but that def cannot
   validate this ROM's table (dimensions differ).
10. **DTC 0x23/0x24 not def-corroborated**: this ROM's def block has no DTC
    0023/0024 enable/disable tables (only 0030/0031/0032/0037/0038/0076/0077
    among the 00xx codes) and no DTC description list. The DTC claim rests
    solely on firmware dataflow (`FUN_0005fd38(0x23/0x24)` from the knock
    health monitor) — now labelled firmware-inferred in the report.

### Unexplained terms / misattribution

11. **`a5e0` "idle/base term" has no identified writer**: the blend
    `a5fc*b118 + base*(1−b118)` is written to **`a5e8`** (0x11f00) / `a5ec`
    (0x1206c) and reaches base timing `a640` via 0x123da. The `a5e0` (read by
    0x125bc), `a5e4` (read by 0x125f6) and `a5dc` (read by fuel fn 0x306e8)
    terms are dangling reads — no writer anywhere in the export, no u32
    0xffffa5e0 in ROM (a u16 0xa5e0 appears only in the literal pool at
    0x12696). The report's §2 pseudocode pointed at an unexplained term;
    §8.3's RAM map omitted a5e0/a5e8/a5ec/a5fc/a640/a644. All now annotated.
12. **Signal-chain misattribution**: README §1 put 0xc3ce
    (`knock_voltage_sample`) under the 0x65f6 task chain; its only caller is
    **0x661e (task[6])**, which calls it before `ref_engineControlTASK`. The
    report's §2 header "sensing (task entry 0x65f6)" was misleading for the
    sample/filter part (0xc486 magnitude integration *is* in the 0x65f6 chain
    via 0xc338). Also 0xc276's callers are 0xc8dc and 0x5a4c — the README
    diagram showed 0xc338 calling it, which is wrong.
13. **Chain diagram error** (README §1): showed 0x13b40 and 0x13bd2 as children
    of 0x142a4; 0x142a4 calls neither — 0x13b40 is called only by 0x145c8
    (fast task), 0x13bd2 only by 0x13a60/0x13b40/0x139c4. The same wrong callee
    list was in the 0x142a4 row of `accepted_function_aliases.tsv` and its
    comment block.
14. **Fault thresholds mislabelled as addresses**: report table 8.4 listed
    "0x0000c831 / 0x00003ef9" as ROM addresses — they are **values**
    (51249/16121) stored as u16 at ROM 0x6c17e/0x6c17c (calibration area). The
    code comparison in 0xc290 was correct.
15. **"Per-rotor" wording wrong** for the rough knock corrections
    (`a6ac`/`a6b0`) and the coolant derates (`a750`/`a754`): these are
    leading/trailing outputs, not per-rotor. (The genuinely per-rotor arrays —
    a334/a33c/a350/a368/a381/a387/a389 — were labelled correctly.)
16. **0x33970 reads `c090` directly**, not `a37e` as the report pseudocode
    said (same raw value reaches a37e via 0x336c4 → 0xc0f0; numerically
    equivalent, wrong address).
17. **"2D" label** for threshold A/B: the descriptors have a single RPM axis
    (14 cells); "2D" referred to the lookup engine (`rx8_lookup_2d_raw_u16`),
    not table dimensionality. Relabelled "raw u16 vs RPM".
18. **Minor**: 0xc1f8 was called `ref_knockFunctionInit` in README §1.3 — that
    name belongs to 0xc14c; 0xc1f8 is `ref_knockRelatedInit`.

## 3. Def-side issues (documented, not fixed — the def repos are upstream)

- `RX8Defs/RomRaider/logger_rx8_defs.xml` line 161: logger parameter PIDTEST3
  name="Knock Retard" (PID 0x1746) has **desc="Tire Size"** (copy-paste error)
  and **gauge_max="500"** — meaningless given the PID's degenerate
  [0, +89.7]° encoding that always yields 0 in this ROM (finding 8).
  Recommended upstream fix: desc="Knock Retard (always 0.00 in this ROM)" or
  similar, and a sane gauge_max. Not applied here: `RX8Defs/` is the upstream
  repo whose commit hashes are cited as merge provenance, and `RX8Defs_Copy/`
  is merge input — a def change would need the merge pipeline re-run.
- The base def "Knock Retard Max - Knock Sensor Faulted" (finding 9) does not
  match this ROM; if the RX8Defs ROM block for 60E15120/N3J1E is ever extended,
  the 15-cell table 0x6afa4 should get its own descriptor rather than reusing
  that name.
- DTC 0x23/0x24 (finding 10): no def corroboration exists; if upstream later
  adds DTC tables or a description list, these codes should be checked against
  it then.
- The "rough knock" semantic of the "Ignition 4..17" tables rests on the
  inherited `ref_roughKnockCorrection` name (a hypothesis); the defs place
  them in category "Ignition". In this ROM the values are nearly all 0
  (Ign4 = 0/30/0 vs temp axis −15…40; Ign6 = 0/5/0; rest 0.0), selected by
  mode flags a6b7/a6b8/a6b9.

## 4. Fixes applied (all in the analysis output; ROM untouched)

| File | Fixes |
|---|---|
| `knock_control_report.md` | revision note; §2 sensing task attribution, command formula, threshold_a source (c090), idle_base_term caveat, diagnostics paragraph (DTC firmware-inferred, PID always 0, logger desc); §6 REVIEW_NOTES row; §8.1 rows (0xc276 callers, 0xc290 thresholds, 0xc3ce caller, level 3.6875, 0x13210 not per-rotor); §8.1 task note (0x661e calls 0xc3ce); §8.3 RAM rows (a98c, c0b4, a5e0/a5e4, a5e8/a5ec, a5fc, a640/a644, a66c/a670); §8.4 "2D"→"raw u16 vs RPM", constants row 0x7a234–0x7a248, fault-threshold values at 0x6c17c/0x6c17e; §9 unresolved a5e0/a5e4/a5dc |
| `reviews/knock_control/README.md` | revision note; §1 chain diagram (0xc486 added under 0xc338; 0xc276 moved under 0xc8dc with 0x5a4c; 0xc3ce moved to task[6]; 0x13b40/0x13bd2 removed from 0x142a4, clamp noted under 0x13a60/0x13b40/0x139c4); §1.1 caller notes; §1.2 noise-filter literal + command formula; §1.3 cd60 polarity, constants, 0xc1f8 name, thresholdA source; §1.6 not-per-rotor wording + a5e0 writer caveat; §1.6 coolant derate wording; §1.7 fault thresholds + DTC firmware-inferred; §1.8 degenerate PID + logger def; §3 task table; §5 unresolved items 6–7 |
| `source_review/accepted_ram_aliases.tsv` | c060/c064/c068 values, a32c literal coefficient, a364 formula, a325 fault thresholds, a6ac not-per-rotor, a37e row (reads c090 directly) |
| `source_review/accepted_function_aliases.tsv` | 0x125bc/0x125f6 idle/base term caveat, 0x142a4 callee list, 0x33632 constants, 0x33970 thresholdA source, 0xc3ce caller, 0xc276 callers, 0x64ba fault thresholds |
| `decompiled/functions/0000c486_FUN_0000c486.c` | c060/c064/c068 comment values, a32c literal coefficient, a364 formula |
| `decompiled/functions/00033632_FUN_00033632.c` | constants comment |
| `decompiled/functions/000064ba_FUN_000064ba.c`, `00049fac_FUN_00049fac.c` | fault-threshold values at ROM 0x6c17c/0x6c17e |
| `decompiled/functions/000125bc_FUN_000125bc.c`, `000125f6_FUN_000125f6.c` | idle/base term a5e0/a5e4 writer caveat, a6ac not-per-rotor |
| `decompiled/functions/0000c276_FUN_0000c276.c`, `0000c3ce_FUN_0000c3ce.c`, `0000c7ba_ref_setupCoilOutputs.c`, `000142a4_FUN_000142a4.c`, `00033970_FUN_00033970.c` | caller/callee notes, a37e row, thresholdA source |
| `decompiled/firmware_decompiled.c`, `named/firmware_named.c` | all of the above comment blocks, in both synchronized views |

No function bodies, names, addresses or ROM bytes were changed — comment text
and documentation only. The pipeline scripts were not re-run; the TSVs and the
C views were edited in lock-step so they stay consistent (a re-run of
`scripts/review_knock_loop_labels*.py` would regenerate the same comments from
the corrected TSVs).

## 5. Validation

- `python3 scripts/validate_export.py` — re-run after the edits: pass (ROM
  SHA-256 verified, 3,355 function files, 168,592 instructions byte-verified,
  1,833 exact reference matches). See `validation.json` in this folder.
- `python3 scripts/verify_readability.py` — re-run: pass (function bodies
  consistent between per-function files and the combined C; only comments
  changed).
- Comment-level consistency between the per-function files, both combined C
  views and the alias TSVs was checked by grep audit (no old strings remain;
  corrected strings present in all views).
- Limits unchanged: static analysis only. `validate_export.py` proves bytes,
  matches and linkage — not semantics. No hardware/emulator execution; host
  math tests do not validate SH FPU rounding/exception behaviour.
