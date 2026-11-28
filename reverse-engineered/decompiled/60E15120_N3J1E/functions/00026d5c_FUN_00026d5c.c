/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a680: Table 2D - 157 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * misfire_load_floor_lookup [high]: DAT_ffffb698 = lookup_2d_descriptor_scaled(rpm 0xffffb548, tbl 0x6a680 [18 cells, 1000..9000 rpm, 20..71 raw]). Called from 0x287aa; consumed by the enable window 0x26d70.
 */
/* ROM address: 0x00026d5c; body bytes: 20; decompiled */

void misfire_load_floor_lookup(void)

{
  DAT_ffffb698 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_157_0006a680);
  return;
}


