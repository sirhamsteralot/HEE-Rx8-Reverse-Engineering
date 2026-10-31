/* [CROSS-ECU / RX8DEFS REVIEW]
 * lookup_3d_descriptor_scaled [layout_correlated]: Descriptor access matches ScoobyRom Denso layout: type byte +16, optional scale +20 and offset +24. This is structural evidence, not proof of calibration meaning or complete ABI recovery.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000020dc; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000020dc (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.
 * Explicit register-result structs are an analysis representation.
 */
float lookup_3d_descriptor_scaled(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated;
  switch (table->type_code) {
    case 0: interpolated = rx8_interpolate_2axis_f32(table->x_count, RX8_ROM_PTR(float, table->data_address), position); break;
    case 4: interpolated = rx8_interpolate_2axis_u8(table->x_count, RX8_ROM_PTR(uint8_t, table->data_address), position); break;
    case 8: interpolated = rx8_interpolate_2axis_u16(table->x_count, RX8_ROM_PTR(uint16_t, table->data_address), position); break;
    case 12: interpolated = rx8_interpolate_2axis_s8(table->x_count, RX8_ROM_PTR(int8_t, table->data_address), position); break;
    case 16: interpolated = rx8_interpolate_2axis_s16(table->x_count, RX8_ROM_PTR(int16_t, table->data_address), position); break;
    default: return rx8_unresolved_table_dispatch_3d(table->type_code);
  }
  if (table->type_code == 0) return interpolated;
  return rx8_sh_fmac_model(table->multiplier, interpolated, table->offset);
}

