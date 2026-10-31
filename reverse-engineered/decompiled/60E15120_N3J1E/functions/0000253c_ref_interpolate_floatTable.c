/* ROM address: 0x0000253c; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000253c (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0000253c: signed low-word row offset, two calls to 00002678, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_f32(uint32_t column_count, const float *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 4u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const float *row = (const float *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_f32(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const float *next_row = (const float *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_f32(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}

