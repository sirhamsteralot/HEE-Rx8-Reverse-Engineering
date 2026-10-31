/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a9f8: Table 2D - 169 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002fe4e; body bytes: 20; decompiled */

void FUN_0002fe4e(void)

{
  DAT_ffffbe1c = lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_table_2d_169_0006a9f8);
  return;
}


