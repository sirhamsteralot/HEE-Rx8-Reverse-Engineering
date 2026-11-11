/* [MATH AND UNITS REVIEW]
 * rx8_decode_u16_affine: Returns offset+(uint16 raw)*step. Float args are scale,offset; integer arg is raw. This is affine scaling, not evidence of a specific sensor unit.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000024c0; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000024c0 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_decode_u16_affine(float units_per_count,float offset,ushort raw_value)

{
  return offset + (float)raw_value * units_per_count;
}


