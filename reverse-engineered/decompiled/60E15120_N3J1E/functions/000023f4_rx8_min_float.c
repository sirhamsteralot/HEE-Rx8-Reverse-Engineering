/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * Ordered min: b>a ? a:b. With NaN second argument it returns that NaN, unlike newlib fminf. Equal inputs choose the second operand.
 */
/* ROM address: 0x000023f4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023f4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_min_float(float left,float right)

{
  if (left < right) {
    right = left;
  }
  return right;
}


