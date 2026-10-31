/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a714: Table 3D - 56 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a730: Table 3D - 57 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a74c: Table 3D - 58 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002ca8e; body bytes: 88; decompiled */

void FUN_0002ca8e(void)

{
  undefined *puVar1;
  
  if (DAT_ffffa934 == 0.0) {
    DAT_ffffbc74 = 0;
  }
  else if (DAT_ffffbc83 == '\0') {
    DAT_ffffbc74 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_table_3d_56_0006a714);
  }
  else {
    if (DAT_ffffbc89 == '\x01') {
      puVar1 = &tbl_table_3d_57_0006a730;
    }
    else {
      puVar1 = &tbl_table_3d_58_0006a74c;
    }
    DAT_ffffbc74 = lookup_3d_descriptor_scaled(puVar1);
  }
  return;
}


