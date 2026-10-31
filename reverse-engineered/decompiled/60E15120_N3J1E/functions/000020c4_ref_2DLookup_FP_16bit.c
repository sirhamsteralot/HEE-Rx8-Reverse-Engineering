/* ROM address: 0x000020c4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000020c4 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_2d_raw_u16(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated = rx8_interpolate_1d_u16(position.index, RX8_ROM_PTR(uint16_t, table->data_address), position.fraction);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}

