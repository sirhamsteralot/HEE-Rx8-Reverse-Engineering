/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b5e0: Compensated Barometric Pressure (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b5f4: Table 3D - 86 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003a3d6; body bytes: 184; decompiled */

undefined4 FUN_0003a3d6(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 extraout_r0;
  float extraout_fr0;
  float arg0;
  
  if (DAT_ffffd26e == '\x01') {
    DAT_ffffc534 = 1.1;
    uVar1 = 1;
  }
  else {
    arg0 = DAT_ffffc534;
    if (secondary_air_pump_request_ffffbf6c == '\x01') {
      cVar2 = rx8_is_outside_tolerance_band(DAT_ffffc538,0,0x3727c5ac);
      DAT_ffffc54c = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_compensated_barometric_pressure_0006b5e0);
      uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_table_3d_86_0006b5f4);
      DAT_ffffc550 = extraout_fr0;
      if (cVar2 == '\0') {
        DAT_ffffc534 = 1.0;
        goto LAB_0003a498;
      }
      arg0 = ((extraout_fr0 + -1.0) * DAT_ffffc54c * 0.01 + 1.0) / DAT_ffffc538;
    }
    DAT_ffffc534 = rx8_max_float(arg0,0.7656);
    uVar1 = extraout_r0;
  }
LAB_0003a498:
  DAT_ffffc545 = DAT_ffffc534 <= diag_afr_word_a_ffffaa6c;
  DAT_ffffc544 = DAT_ffffc534 > diag_afr_word_a_ffffaa6c;
  return uVar1;
}


