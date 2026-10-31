/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069560: Table 3D - 14 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000180c8; body bytes: 82; decompiled */

void FUN_000180c8(void)

{
  float arg1;
  
  if (DAT_ffffa938 == 0) {
    DAT_ffffa934 = 0.0;
  }
  else {
    DAT_ffffa940 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,&tbl_table_3d_14_00069560);
    DAT_ffffa944 = DAT_ffffbca0 - DAT_ffffa940;
    arg1 = rx8_max_float(DAT_ffffa92c,DAT_ffffa930);
    DAT_ffffa934 = rx8_min_float(DAT_ffffa944,arg1);
  }
  return;
}


