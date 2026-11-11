/* [MATH AND UNITS REVIEW]
 * Assembly clamp is !(value>lower) ? lower : (upper>value ? value:upper). Raw C simplification using upper<=value is not equivalent for NaN upper. Reconstructed/rx8_math.c preserves the assembly ordering.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002404; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002404 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_clamp_float(float value,float lower,float upper)

{
  if ((lower < value) && (lower = value, upper <= value)) {
    lower = upper;
  }
  return lower;
}


