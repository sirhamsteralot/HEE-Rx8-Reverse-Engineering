/* ROM address: 0x00002658; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002658 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0x2658-2676: first search FR4/X/count+0/axis+4, second FR5/Y/count+2/axis+8; results R2/R3 and FR0/FR1. Both calls required.
 * Explicit register-result structs are an analysis representation.
 */
Rx8MapPosition rx8_find_xy_axis_positions(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position;
  position.x = rx8_find_axis_index_fraction(table->x_count, RX8_ROM_PTR(float, table->x_axis_address), x_value);
  position.y = rx8_find_axis_index_fraction(table->y_count, RX8_ROM_PTR(float, table->y_axis_address), y_value);
  return position;
}

