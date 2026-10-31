/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b7bc: Table 2D - 268 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b7d0: Table 2D - 269 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b7e4: Injection Angle (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003e7b6; body bytes: 108; decompiled */

void FUN_0003e7b6(void)

{
  DAT_ffffc690 = lookup_2d_descriptor_scaled(mass_air_flow_ffffa9ec,&tbl_table_2d_268_0006b7bc);
  if (DAT_ffffc64f == '\0') {
    DAT_ffffc694 = 0x3f800000;
  }
  else {
    DAT_ffffc694 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_269_0006b7d0);
  }
  if (DAT_ffffb0ca == '\x01') {
    DAT_ffffc698 = 100.0;
  }
  else {
    DAT_ffffc6a4 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_injection_angle_0006b7e4);
    DAT_ffffc698 = DAT_ffffc664 + DAT_ffffc668 + DAT_ffffc6a4;
  }
  FUN_0003ea16();
  return;
}


