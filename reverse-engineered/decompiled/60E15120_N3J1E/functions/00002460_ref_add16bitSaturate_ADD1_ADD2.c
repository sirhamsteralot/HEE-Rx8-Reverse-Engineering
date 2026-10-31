/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_add_u16_saturate: Inputs are truncated to uint16 before addition; output min(a+b,65535). Saturation, not ordinary wrapping unsigned-short arithmetic.
 */
/* ROM address: 0x00002460; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002460 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_add_u16_saturate(uint left,uint right)

{
  uint sum;
  
  sum = (left & 0xffff) + (right & 0xffff);
  if (0xfffe < sum) {
    sum = 0xffff;
  }
  return sum;
}


