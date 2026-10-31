/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_divide_with_zero_fallback: For denominator zero: 0/0 returns +0; nonzero numerator selects a signed large finite fallback about 3.4028229e38. Denominator negative zero does not reverse fallback sign. Other inputs use division. Not IEEE division or a normal libm function; the fallback is not asserted to equal FLT_MAX.
 */
/* ROM address: 0x0003db24; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e0ac (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_divide_with_zero_fallback(float numerator,float denominator)

{
  if (denominator == 0.0) {
    if (numerator == 0.0) {
      numerator = 0.0;
    }
    else if (numerator <= 0.0) {
      numerator = -3.4028229e+38;
    }
    else {
      numerator = 3.4028229e+38;
    }
  }
  else {
    numerator = numerator / denominator;
  }
  return numerator;
}


