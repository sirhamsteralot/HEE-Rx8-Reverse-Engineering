/* [MATH AND UNITS REVIEW]
 * rx8_encode_u16_affine_saturate: For finite in-range intermediate t=(signal-offset)/step, performs trunc(t+0.5), then clamps integer to 0..65535. Physical decode is raw*step+offset. Step is units/count, not an encode multiplier. NaN, zero step and out-of-range FTRC require SH-specific analysis; do not model by an unrestricted C float-to-int cast. Not roundf: that has a signed floating result and halfway-away-from-zero rules.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002490; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002490 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_encode_u16_affine_saturate(float signal,float units_per_count,float offset)

{
  int encoded_value;
  int rounded_counts;
  
  encoded_value = RX8_U16_MAX;
  rounded_counts = (int)((signal - offset) / units_per_count + 0.5);
  if ((rounded_counts < 0x10000) && (encoded_value = rounded_counts, rounded_counts < 0)) {
    encoded_value = 0;
  }
  return encoded_value;
}


