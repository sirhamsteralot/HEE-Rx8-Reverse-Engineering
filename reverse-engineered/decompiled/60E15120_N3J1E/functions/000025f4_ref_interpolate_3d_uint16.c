/* ROM address: 0x000025f4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000025f4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000025f4: signed low-word row offset, two calls to 000026d0, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_u16(uint32_t column_count, const uint16_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 2u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const uint16_t *row = (const uint16_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_u16(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const uint16_t *next_row = (const uint16_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_u16(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}

