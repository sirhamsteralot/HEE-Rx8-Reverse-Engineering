/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_add_u8_saturate: Inputs are truncated to uint8 before addition; output min(a+b,255).
 */
/* ROM address: 0x00002478; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002478 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_add_u8_saturate(uint left,uint right)

{
  uint sum;
  
  sum = (left & 0xff) + (right & 0xff);
  if (0xfe < sum) {
    sum = 0xff;
  }
  return sum;
}


