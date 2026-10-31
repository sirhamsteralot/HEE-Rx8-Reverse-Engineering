/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a680: Table 2D - 157 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00026d5c; body bytes: 20; decompiled */

void FUN_00026d5c(void)

{
  DAT_ffffb698 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_157_0006a680);
  return;
}


