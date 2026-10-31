/* ROM address: 0x000026b0; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000026b0 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000026b0: integer extension distinguishes uint8_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_u8(uint32_t lower_index, const uint8_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}

