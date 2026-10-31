/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a19c: Table 2D - 119 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a1b0: Table 2D - 120 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a1c4: Table 3D - 43 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a1e0: Table 3D - 44 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00021efc; body bytes: 410; decompiled */

uint FUN_00021efc(void)

{
  char cVar2;
  uint uVar1;
  uint extraout_r0;
  float *pfVar3;
  float fVar4;
  float fVar5;
  undefined4 snapshot_mass_air_flow_ffffa9ec;
  undefined4 snapshot_DAT_ffffbe00;
  float arg1;
  
  fVar5 = DAT_ffffadec;
  arg1 = 0.0;
  snapshot_DAT_ffffbe00 = DAT_ffffbe00;
  fVar4 = rx8_absolute_difference(closed_loop_trim_filtered_ffffbeb8,0.0);
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffb2ec,arg1,0x3727c5ac);
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  DAT_ffffb320 = lookup_2d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe08,&tbl_table_2d_120_0006a1b0);
  DAT_ffffb324 = (float)lookup_3d_descriptor_scaled(snapshot_DAT_ffffbe00,engine_speed_rpm_ffffb548,&tbl_table_3d_44_0006a1e0);
  if (DAT_ffffaa62 == '\x01') {
    DAT_ffffb2f8 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_table_2d_119_0006a19c);
  }
  else {
    DAT_ffffb2f8 = (float)lookup_3d_descriptor_scaled(snapshot_DAT_ffffbe00,inferred_barometric_pressure_ffffad14,&tbl_table_3d_43_0006a1c4);
  }
  if (DAT_ffffb2f4 < 0xd6e) {
    pfVar3 = (float *)&DAT_00072f10;
    DAT_ffffb30c = 0.0008;
  }
  else {
    pfVar3 = (float *)&DAT_00072f18;
    DAT_ffffb30c = 0.0125;
  }
  DAT_ffffb310 = *pfVar3;
  if ((fVar5 <= 0.79999995) || (1.1999999 <= fVar5)) {
    DAT_ffffb2fc = rx8_max_float(DAT_ffffb2ec - 0.00938,arg1);
  }
  else {
    fVar5 = DAT_ffffb30c;
    if ((fVar4 < 0.0195) || (fVar5 = DAT_ffffb310, fVar4 < 0.1)) {
      DAT_ffffb2fc = rx8_min_float(DAT_ffffb2ec + fVar5,DAT_ffffb2f8);
    }
    else {
      DAT_ffffb2fc = DAT_ffffb2ec;
    }
  }
  if (cVar2 != '\0') {
    DAT_ffffb2f4 = rx8_add_u16_saturate((int)(short)DAT_ffffb2f4,1);
  }
  fVar5 = (float)rx8_divide_with_zero_fallback(DAT_ffffb320,snapshot_mass_air_flow_ffffa9ec);
  DAT_ffffb300 = fVar5 * 100.0;
  DAT_ffffb314 = (DAT_ffffb0d0 + 1.0) * DAT_ffffb324;
  fVar5 = rx8_max_float(DAT_ffffb220,arg1);
  fVar5 = (float)rx8_divide_with_zero_fallback(DAT_ffffb314,fVar5);
  DAT_ffffb304 = rx8_min_float(fVar5,20.0);
  uVar1 = (uint)DAT_ffffb2f6;
  if (uVar1 == 1) {
    fVar5 = rx8_min_float(DAT_ffffb2fc,DAT_ffffb300);
    arg1 = rx8_min_float(fVar5,DAT_ffffb304);
    uVar1 = extraout_r0;
  }
  DAT_ffffb2ec = arg1;
  return uVar1;
}


