/* [ADDITIONAL SOURCE REVIEW]
 * maf_per_rotation_calc [high]: aa54 = tbl 0x697b4(rpm) filter coefficient; aa48 = filter(maf a9ec, aa48, aa54); aa3c = min(maf*60/rpm, 5.0) (air per rotation, 60 = 2 rotors x 30?); aa38 = filtered maf*60/rpm, 0.1560058 when rpm ~ 0. | promoted to high (data/labels/60E15120_N3J1E/fueling_labels.json/function_aliases)
 * RAM 0xffffaa54 maf_filter_coeff (float): aa54 = lookup_2d tbl 0x697b4(rpm); filter coefficient for MAF per-rotation calc.
 * RAM 0xffffaa48 maf_filter_state (float): aa48 = first_order_filter(maf, aa48, aa54).
 * RAM 0xffffaa3c maf_per_rotation (float): aa3c = min(maf*60/rpm, 5.0) (maf*0x42700000/rpm).
 * RAM 0xffffaa38 maf_per_rotation_filtered (float): aa38 = filtered maf*60/rpm; 0.1560058 when rpm ~ 0.
 * RAM 0xffffaa4c maf_filter_mode (uint8): aa4c selects filtered vs instantaneous MAF for the per-rotation calc.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001a418; body bytes: 174; decompiled */

uint maf_per_rotation_calc(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  float arg3;
  undefined4 uVar4;
  float arg0;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  arg0 = mass_air_flow_ffffa9ec;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  maf_filter_coeff_ffffaa54 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_000697b4);
  arg3 = 1e-05;
  maf_filter_state_ffffaa48 = rx8_first_order_filter(arg0,maf_filter_state_ffffaa48,maf_filter_coeff_ffffaa54,1e-05);
  uVar4 = 0x42700000;
  if (maf_filter_mode_ffffaa4c == '\x01') {
    fVar2 = (float)rx8_divide_with_zero_fallback(0x42700000,snapshot_engine_speed_rpm_ffffb548);
    fVar3 = arg0;
  }
  else {
    fVar2 = (float)rx8_divide_with_zero_fallback(0x42700000,snapshot_engine_speed_rpm_ffffb548);
    fVar3 = maf_filter_state_ffffaa48;
  }
  maf_per_rotation_ffffaa3c = rx8_min_float(fVar3 * fVar2,5.0);
  uVar1 = rx8_is_outside_tolerance_band(snapshot_engine_speed_rpm_ffffb548,0,arg3);
  if ((uVar1 & 0xff) == 0) {
    maf_per_rotation_filtered_ffffaa38 = 0.1560058;
  }
  else {
    fVar3 = (float)rx8_divide_with_zero_fallback(uVar4,snapshot_engine_speed_rpm_ffffb548);
    maf_per_rotation_filtered_ffffaa38 = rx8_first_order_filter(arg0 * fVar3,maf_per_rotation_filtered_ffffaa38,1.0,arg3);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


