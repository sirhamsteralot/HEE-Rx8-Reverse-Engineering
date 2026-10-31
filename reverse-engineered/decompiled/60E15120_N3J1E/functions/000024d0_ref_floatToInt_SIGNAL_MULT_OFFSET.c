/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_encode_u8_affine_saturate: For finite in-range intermediate t=(signal-offset)/step, performs trunc(t+0.5), then clamps integer to 0..255. Decode is raw*step+offset. Exceptional FTRC behavior is not established by raw C.
 */
/* ROM address: 0x000024d0; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000024d0 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_encode_u8_affine_saturate(float signal,float units_per_count,float offset)

{
  int encoded_value;
  int rounded_counts;
  
  encoded_value = RX8_U8_MAX;
  rounded_counts = (int)((signal - offset) / units_per_count + 0.5);
  if ((rounded_counts < 0x100) && (encoded_value = rounded_counts, rounded_counts < 0)) {
    encoded_value = 0;
  }
  return encoded_value;
}


