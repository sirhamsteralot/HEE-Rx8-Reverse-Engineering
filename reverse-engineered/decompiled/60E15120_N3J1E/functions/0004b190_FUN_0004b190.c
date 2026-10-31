/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bae0: Table 2D - 282 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004b190; body bytes: 86; decompiled */

undefined1 * FUN_0004b190(void)

{
  undefined1 *puVar1;
  float extraout_fr0;
  
  puVar1 = &fuel_cut_flag_b_ffffa445;
  if (fuel_cut_flag_a_ffffa444 == fuel_cut_flag_b_ffffa445) {
    DAT_ffffcdf4 = 0.0;
  }
  else {
    DAT_ffffcdf8 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_table_2d_282_0006bae0);
    DAT_ffffcdfc = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006baf4);
    puVar1 = (undefined1 *)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_0006bb08);
    DAT_ffffcdf4 = DAT_ffffcdf8 * DAT_ffffcdfc * extraout_fr0;
    DAT_ffffce00 = extraout_fr0;
  }
  return puVar1;
}


