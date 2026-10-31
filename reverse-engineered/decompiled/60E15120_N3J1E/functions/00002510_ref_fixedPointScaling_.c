/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_blend_s32_u16_weight_over_256: Returns a+trunc((1-weight/256)*(float(b)-float(a))). weight is uint16, not restricted to 0..256; values above 256 extrapolate. Floating arithmetic and truncation matter; not generic integer lerp with unrestricted overflow guarantees.
 */
/* ROM address: 0x00002510; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002510 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_blend_s32_u16_weight_over_256(int endpoint_a,int endpoint_b,ushort weight_256)

{
  return endpoint_a + (int)((1.0 - (float)weight_256 * 0.00390625) * ((float)endpoint_b - (float)endpoint_a));
}


