/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a4c8: Table 2D - 144 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4dc: Table 2D - 145 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4f0: Table 2D - 146 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a504: Table 2D - 147 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * throttle_target_plate_position [high]: Arbitrated plate target: b424 = clamp(b2b8, b418=tbl 0x6a4c8(coolant), b38c+b2a4) when b2cf==1 (DSC torque limit), = max(b38c+b2a4, b2bc) when b2d0==1 (DSC mode C max opening), else clamp(b38c+b2a4, 0, 84.0) with fuel-cut decel reduction via tbls 0x6a4dc/0x6a4f0/0x6a504 (descriptors 0x6a4c8/0x6a4dc/0x6a4f0/0x6a504) -> b434/b422; b410 = FUN_0005ccb4(b424) stored with fmov.s at 0x2353e (float in b424 units, PIDs 0x004c/0x091a; 0x5ccb4 quantizes to 1/512 for the PID export and decodes back for descriptor codes 5/7). Called from batch 0x22f86.
 * RAM 0xffffb424 throttle_target_plate_percent (float): Arbitrated plate target percent from 0x233ec (DSC limit b2cf/b2b8, DSC mode C b2d0/b2bc, idle air + base b2a4+b38c, fuel-cut decel, clamp 84.0); passed through the PID 0x091a export 0x5ccb4 into the float b410.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000233ec; body bytes: 300; decompiled */

void throttle_target_plate_position(void)

{
  float *pfVar1;
  undefined1 uVar2;
  float fVar3;
  undefined4 snapshot_intake_air_temperature_ffffaddc;
  float arg0;
  
  arg0 = candidate_throttle_base_position_ffffb38c + idle_air_required_ffffb2a4;
  fVar3 = idle_air_required_ffffb2a4;
  snapshot_intake_air_temperature_ffffaddc = intake_air_temperature_ffffaddc;
  DAT_ffffb418 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_144_0006a4c8);
  uVar2 = 0;
  if (dsc_torque_limit_active_ffffb2cf == '\x01') {
    if (DAT_ffffa966 == '\0') {
      pfVar1 = (float *)&DAT_ffffb2b8;
      fVar3 = DAT_ffffb418;
    }
    else {
      pfVar1 = (float *)&DAT_000747d8;
    }
    throttle_target_plate_percent_ffffb424 = rx8_clamp_float(*pfVar1,fVar3,arg0);
  }
  else if (dsc_mode_c_active_ffffb2d0 == '\x01') {
    throttle_target_plate_percent_ffffb424 = rx8_max_float(arg0,DAT_ffffb2bc);
  }
  else {
    DAT_ffffb41c = rx8_clamp_float(arg0,0.0,84.0);
    fVar3 = (float)lookup_2d_descriptor_scaled(inferred_predicted_engine_speed_ffffb55c,&tbl_table_2d_145_0006a4dc);
    DAT_ffffb42c = (float)lookup_2d_descriptor_scaled(snapshot_intake_air_temperature_ffffaddc,&tbl_table_2d_146_0006a4f0);
    DAT_ffffb430 = (float)lookup_2d_descriptor_scaled(snapshot_intake_air_temperature_ffffaddc,&tbl_table_2d_147_0006a504);
    if (DAT_ffffb41c <= DAT_ffffb42c * fVar3) {
      if (DAT_ffffb41c <= DAT_ffffb42c * fVar3 - 0.5) {
        DAT_ffffb434 = '\0';
      }
    }
    else {
      DAT_ffffb434 = '\x01';
    }
    if (((DAT_ffffb434 == '\0') && (DAT_ffffb53a == '\0')) &&
       ((fuel_cut_flag_a_ffffa444 == '\x01' || (fuel_cut_flag_b_ffffa445 == '\x01')))) {
      throttle_target_plate_percent_ffffb424 = (fVar3 + 0.0) * DAT_ffffb430;
      uVar2 = 1;
    }
    else {
      throttle_target_plate_percent_ffffb424 = DAT_ffffb41c;
    }
  }
  inferred_ram_b410_ffffb410_ffffb410 = FUN_0005ccb4(throttle_target_plate_percent_ffffb424);
  DAT_ffffb422 = uVar2;
  return;
}


