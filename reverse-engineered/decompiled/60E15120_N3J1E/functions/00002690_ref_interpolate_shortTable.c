/* ROM address: 0x00002690; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002690 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 00002690: integer extension distinguishes int16_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_s16(uint32_t lower_index, const int16_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}

