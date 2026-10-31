/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * Ordered max: a>b ? a:b. With NaN second argument it returns that NaN, unlike newlib fmaxf which selects the numeric operand. Equal inputs choose the second operand, affecting signed zero.
 */
/* ROM address: 0x000023e4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023e4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_max_float(float left,float right)

{
  if (right < left) {
    right = left;
  }
  return right;
}


