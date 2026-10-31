/* ROM address: 0x0000213c; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000213c (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_3d_raw_u16(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated = rx8_interpolate_2axis_u16(table->x_count, RX8_ROM_PTR(uint16_t, table->data_address), position);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}

