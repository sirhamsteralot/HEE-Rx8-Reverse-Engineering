# Math helpers and unit conversions

This review updates the canonical `decompiled/firmware_decompiled.c`, individual C files, function index and call graph. **15 helpers have clearer names, 84 functions have review comments, and 70 constant-scale encoding calls are decoded.** Twelve calls have physical/dimensionless units supported by earlier signal interpretation. Other calls retain unassigned units.

## Clear conversions

| Signal | Decode from encoded raw value | Evidence |
|---|---|---|
| Engine speed | raw × 0.25 RPM | Known RPM reader and conversion helper |
| Coolant / intake temperature | raw − 40 °C | Diagnostic-correlated signals; scale 1, offset −40 |
| Leading / trailing timing | raw × 0.5 − 64 degrees | Diagnostic-correlated timing readers |
| Knock retard | raw × 0.3515625 degrees | Knock reader scaling |
| MAF | raw × approximately 0.01 g/s | MAF diagnostic reader |
| Lambda target | raw / 32768 | Dimensionless signal and exact power-of-two scalar |

Scale constants printed as integer hex in raw C are decoded in the comments, rather than changed into typed floating arguments while the ABI is still imperfect. The encoders apply `(signal-offset)/step`, add 0.5, truncate, then clamp the integer result. The scale is **units per encoded count**, so treating it as an encoding multiplier reverses the conversion.

Other dimensional clues are deliberately provisional: 5/65536 in the MAF sensor path suggests a 5-V normalized ADC input, but not a 16-bit physical ADC; RPM/60 is revolutions/second; 1/3.6 next to acceleration-like comparisons suggests conversion from (km/h)/s to m/s², pending timebase confirmation. Generic 0.001 constants were not labelled milliseconds without dataflow evidence.

[affine_conversions.json](affine_conversions.json) records every automatically decoded call, original literals, binary32 values, signal and function. It covers direct three-argument calls with constant scale and offset; it does not claim all conversions in the ROM have been resolved.

## Helpers and library comparison

[helper_aliases.tsv](helper_aliases.tsv) lists all 15 changes. Notable findings:

- **0x231c — rx8_mul_s32_shift16_saturate:** signed 64-bit product, arithmetic shift by 16, signed 32-bit saturation. This is consistent with Q16.16 multiplication when the operands use that format. It differs from ordinary multiplication and GCC's SH `__mulsi3` implementation. Compared against the [GCC SH runtime source](https://github.com/gcc-mirror/gcc/blob/master/libgcc/config/sh/lib1funcs.S) and [runtime descriptions](https://gcc.gnu.org/onlinedocs/gcc-9.1.0/gccint/Integer-library-routines.html); no library-origin match is claimed.
- **0x2490 / 0x24d0 — unsigned affine encoders:** application scaling, rounding and saturation, rather than generic casts or `roundf`.
- **0x2440 — outside-tolerance test:** checks strict lower/upper inequalities; it is not a divide-protection helper.
- **0x2420 / 0x2430 — value/complement packing:** redundancy encoding, not endian conversion or CRC.
- **0x42b0 — forward byte copy:** R0=count, R1=destination, R2=source. It does not return the original destination in R0 and does not select a backwards copy path. The behavior resembles a runtime copy primitive, but is not the standard `memcpy` interface or an overlap-safe `memmove`. Compared with [newlib's memory-function contracts](https://sourceware.org/newlib/libc.html).
- **0x6689e — specialized insertion sort:** ascending uint16 key, byte payload, four-byte stride. No general comparator and no proven `qsort` origin.

The existing ordered min/max return their second operand for unordered comparisons or equality. That differs from newlib `fminf`/`fmaxf`, which select the numeric argument when the other is NaN. Likewise, `roundf` rounds halfway cases away from zero and returns floating-point, whereas our encoders saturate an integer representation. Source: [newlib math documentation](https://sourceware.org/newlib/libm.html).

The filter and clamp retain explicit comments about decompiler edge cases. In particular, the filter's exponent check is a bit reinterpretation, not a numeric integer conversion. The clamp's assembly predicate is `upper > value`; a raw-C simplification using `upper <= value` differs for NaN. The existing hand reconstruction preserves the instruction ordering. No attempt was made to silently repair every raw decompiler expression.

## Validation and limits

`verify_math_units.py` verifies the 16 SHAR/ROTCR pairs and compares their signed-word simulation against the fixed-point formula for **10,007 boundary/random cases**. It also checks all 70 decoded constant pairs and known unit examples. The existing host math tests pass without fast-math or floating-point contraction. All 3,355 exported functions and 168,592 instruction encodings still pass export consistency checks.

These checks do not prove complete SH FPU equivalence. In particular, NaNs, zero scaling factors, overflow and exceptional FTRC conversions cannot safely be reconstructed using unrestricted C float-to-int casts. No specific compiler or library provenance was established. The saved Ghidra database remains unchanged.

Reapply after export/name integration with `python3 scripts/annotate_math_units.py`; validate with `python3 scripts/verify_math_units.py`. The named compatibility file is synchronized with the canonical C.
