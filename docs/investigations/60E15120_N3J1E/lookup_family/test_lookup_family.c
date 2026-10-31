#include "../decompiled/rx8_analysis_types.h"
#include <math.h>
#include <assert.h>
#include <stdlib.h>
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


uint32_t rx8_lookup_2d_raw_u8(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated = rx8_interpolate_1d_u8(position.index, RX8_ROM_PTR(uint8_t, table->data_address), position.fraction);
  return (uint8_t)rx8_sh_ftrc_model(interpolated);
}


uint32_t rx8_lookup_2d_raw_u16(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated = rx8_interpolate_1d_u16(position.index, RX8_ROM_PTR(uint16_t, table->data_address), position.fraction);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}


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


uint32_t rx8_lookup_3d_raw_u8(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated = rx8_interpolate_2axis_u8(table->x_count, RX8_ROM_PTR(uint8_t, table->data_address), position);
  return (uint8_t)rx8_sh_ftrc_model(interpolated);
}


uint32_t rx8_lookup_3d_raw_u16(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated = rx8_interpolate_2axis_u16(table->x_count, RX8_ROM_PTR(uint16_t, table->data_address), position);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}


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


float rx8_interpolate_2axis_s8(uint32_t column_count, const int8_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 1u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const int8_t *row = (const int8_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_s8(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const int8_t *next_row = (const int8_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_s8(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


float rx8_interpolate_2axis_s16(uint32_t column_count, const int16_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 2u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const int16_t *row = (const int16_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_s16(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const int16_t *next_row = (const int16_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_s16(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


float rx8_interpolate_2axis_u8(uint32_t column_count, const uint8_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 1u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const uint8_t *row = (const uint8_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_u8(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const uint8_t *next_row = (const uint8_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_u8(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


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


Rx8AxisPosition rx8_find_axis_index_fraction(uint32_t count, const float *axis, float value)
{
  uint32_t byte_offset = (count - 1u) * 4u;
  float lower = *(const float *)((uintptr_t)axis + byte_offset);
  /* BF after FCMP/GT includes unordered comparisons: do not replace with <=. */
  if (!(lower > value)) return (Rx8AxisPosition){byte_offset >> 2, 0.0f};
  for (;;) {
    if (byte_offset == 0) return (Rx8AxisPosition){0, 0.0f};
    byte_offset -= 4u;
    lower = *(const float *)((uintptr_t)axis + byte_offset);
    if (!(lower > value)) break;
  }
  float upper = *(const float *)((uintptr_t)axis + byte_offset + 4u);
  return (Rx8AxisPosition){byte_offset >> 2, (value - lower) / (upper - lower)};
}


Rx8MapPosition rx8_find_xy_axis_positions(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position;
  position.x = rx8_find_axis_index_fraction(table->x_count, RX8_ROM_PTR(float, table->x_axis_address), x_value);
  position.y = rx8_find_axis_index_fraction(table->y_count, RX8_ROM_PTR(float, table->y_axis_address), y_value);
  return position;
}


float rx8_interpolate_1d_f32(uint32_t lower_index, const float *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


float rx8_interpolate_1d_s16(uint32_t lower_index, const int16_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


float rx8_interpolate_1d_u8(uint32_t lower_index, const uint8_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


float rx8_interpolate_1d_u16(uint32_t lower_index, const uint16_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


float rx8_interpolate_1d_s8(uint32_t lower_index, const int8_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}



/* Host-only test operations: do not use these as target exception emulation. */
float rx8_sh_fmac_model(float m,float v,float a) { return fmaf(m,v,a); }
int32_t rx8_sh_ftrc_model(float v) { assert(isfinite(v) && v > -2147483648.0f && v < 2147483648.0f); return (int32_t)v; }
float rx8_unresolved_table_dispatch_2d(int t) { (void)t; abort(); }
float rx8_unresolved_table_dispatch_3d(int t) { (void)t; abort(); }
int main(void) {
 float axis[]={0,10,20};
 for(int v=-100;v<=300;v++) {
  float value=v/10.0f; Rx8AxisPosition p=rx8_find_axis_index_fraction(3,axis,value);
  unsigned expect=value>=20?2:value>=10?1:0; assert(p.index==expect);
  float f=value<0||value>=20?0:(value-axis[expect])/10; assert(p.fraction==f);
 }
 Rx8AxisPosition n=rx8_find_axis_index_fraction(3,axis,NAN); assert(n.index==2 && n.fraction==0);
 float one[]={7}; assert(rx8_find_axis_index_fraction(1,one,-10).index==0);
 assert(rx8_interpolate_1d_f32(0,one,0)==7);
 float f[]={0,10,20,30}; uint8_t u8[]={0,10,20,30}; uint16_t u16[]={0,10,20,30};
 int8_t s8[]={-30,-20,-10,0}; int16_t s16[]={-30,-20,-10,0};
 Rx8MapPosition p={{0,0.25f},{0,0.5f}};
 assert(rx8_interpolate_2axis_f32(2,f,p)==12.5f);
 assert(rx8_interpolate_2axis_u8(2,u8,p)==12.5f);
 assert(rx8_interpolate_2axis_u16(2,u16,p)==12.5f);
 assert(rx8_interpolate_2axis_s8(2,s8,p)==-17.5f);
 assert(rx8_interpolate_2axis_s16(2,s16,p)==-17.5f);
 return 0;
}
