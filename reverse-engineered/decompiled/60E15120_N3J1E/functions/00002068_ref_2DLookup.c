/* [CROSS-ECU / RX8DEFS REVIEW]
 * lookup_2d_descriptor_scaled [layout_correlated]: Descriptor access matches ScoobyRom Denso layout: type byte +2, optional scale +12 and offset +16; this ROM uses indirect interpolation dispatch. Raw signature/register-derived temporaries remain unresolved. Layout compatibility does not transfer Subaru table names or units.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002068; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002068 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.
 * Explicit register-result structs are an analysis representation.
 */
float lookup_2d_descriptor_scaled(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated;
  switch (table->type_code) {
    case 0: interpolated = rx8_interpolate_1d_f32(position.index, RX8_ROM_PTR(float, table->data_address), position.fraction); break;
    case 4: interpolated = rx8_interpolate_1d_u8(position.index, RX8_ROM_PTR(uint8_t, table->data_address), position.fraction); break;
    case 8: interpolated = rx8_interpolate_1d_u16(position.index, RX8_ROM_PTR(uint16_t, table->data_address), position.fraction); break;
    case 12: interpolated = rx8_interpolate_1d_s8(position.index, RX8_ROM_PTR(int8_t, table->data_address), position.fraction); break;
    case 16: interpolated = rx8_interpolate_1d_s16(position.index, RX8_ROM_PTR(int16_t, table->data_address), position.fraction); break;
    default: return rx8_unresolved_table_dispatch_2d(table->type_code);
  }
  if (table->type_code == 0) return interpolated;
  return rx8_sh_fmac_model(table->multiplier, interpolated, table->offset);
}

