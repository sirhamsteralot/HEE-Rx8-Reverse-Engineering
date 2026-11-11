/* [MATH AND UNITS REVIEW]
 * rx8_decode_u8_affine: Returns offset+(uint8 raw)*step. Float args are scale,offset; integer arg is raw.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002500; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002500 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_decode_u8_affine(float units_per_count,float offset,byte raw_value)

{
  return offset + (float)raw_value * units_per_count;
}


