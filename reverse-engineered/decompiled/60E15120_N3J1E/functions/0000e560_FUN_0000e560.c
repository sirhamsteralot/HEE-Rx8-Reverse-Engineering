/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00068f48: Off Throttle Fuel Cut - Fuel Resume - Engine Startup Base (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f80: Off Throttle Fuel Cut - Fuel Resume - In Neutral Threshold (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068fa8: Off Throttle Fuel Cut - Fuel Resume - In Gear Threshold (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068fc4: Off Throttle Fuel Cut - Fuel Resume - NOTUSED (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000e560; body bytes: 672; decompiled */

undefined2 * FUN_0000e560(void)

{
  char cVar1;
  char cVar2;
  byte snapshot_inferred_ram_bf3c_ffffbf3c_ffffbf3c;
  undefined2 *extraout_r0;
  undefined2 *puVar4;
  undefined4 uVar5;
  float fVar6;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_inferred_predicted_engine_speed_ffffb55c;
  float fVar9;
  
  snapshot_inferred_ram_bf3c_ffffbf3c_ffffbf3c = inferred_ram_bf3c_ffffbf3c_ffffbf3c;
  cVar2 = DAT_ffffb53a;
  cVar1 = automatic_transmission_ffffb534;
  if ((DAT_ffffa4a1 == '\x01') && (DAT_ffffb53a == '\0')) {
    DAT_ffffa48c = 0x58;
  }
  if (((DAT_ffffb54c < 15.0) || (engine_speed_rpm_ffffb548 < 1500.0)) || (DAT_ffffa48c == 0)) {
    DAT_ffffa462 = '\x01';
  }
  else {
    DAT_ffffa462 = '\0';
  }
  if (DAT_ffffa48c != 0) {
    DAT_ffffa48c = DAT_ffffa48c + -1;
  }
  if (automatic_transmission_ffffb534 == '\x01') {
    DAT_ffffa461 = current_gear_ffffbc3d;
  }
  else if (DAT_ffffbc41 == '\x01') {
    DAT_ffffa461 = '\x01';
  }
  else {
    DAT_ffffa461 = '\x02';
  }
  fVar6 = DAT_ffffb54c;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_inferred_predicted_engine_speed_ffffb55c = inferred_predicted_engine_speed_ffffb55c;
  fVar9 = vehicle_speed_ffffbbb4;
  uVar5 = rx8_decode_u16_affine(0x41000000,0,(int)engine_running_timer_ffffa424);
  DAT_ffffa468 = (float)lookup_2d_descriptor_scaled(uVar5,&tbl_off_throttle_fuel_cut_fuel_resume_engine_startup_base_00068f48);
  if (fVar9 < 120.0) {
    if (fVar9 < 115.0) {
      DAT_ffffa499 = '\0';
    }
  }
  else {
    DAT_ffffa499 = '\x01';
  }
  puVar4 = (undefined2 *)(uint)snapshot_inferred_ram_bf3c_ffffbf3c_ffffbf3c;
  DAT_ffffa458 = DAT_ffffa468;
  if (puVar4 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffa458 = DAT_ffffa468 + 0.0;
  }
  if (((fVar6 < -50.0) && (DAT_ffffa462 == '\x01')) && (cVar1 == '\x01')) {
    DAT_ffffa458 = DAT_ffffa458 + 0.0;
  }
  if (DAT_ffffcca1 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 5000.0;
  }
  if (DAT_ffffb2d0 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 10000.0;
  }
  if (DAT_ffffa7b8 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 1500.0;
  }
  if (DAT_ffffc590 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 10000.0;
  }
  if (((DAT_ffffbad0 == '\x01') && (at_drive_range_engaged_ffffb53c == '\0')) && (DAT_ffffa499 == '\x01')) {
    DAT_ffffa458 = DAT_ffffa458 + 1500.0;
  }
  if (cVar2 == '\x01') {
    DAT_ffffa46c = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_off_throttle_fuel_cut_fuel_resume_in_neutral_threshold_00068f80);
  }
  else {
    fVar6 = (float)rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffa461);
    DAT_ffffa46c = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,fVar6,&tbl_off_throttle_fuel_cut_fuel_resume_in_gear_threshold_00068fa8);
  }
  DAT_ffffa448 = DAT_ffffa458 + DAT_ffffa46c;
  if (cranking_active_ffffaa62_ffffaa62 == '\0') {
    DAT_ffffa454 = 300.0;
  }
  else if (snapshot_inferred_predicted_engine_speed_ffffb55c < DAT_ffffa448) {
    DAT_ffffa454 = 500.0;
  }
  fVar9 = 0.0;
  if (cVar2 == '\0') {
    DAT_ffffa480 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,fVar6,&tbl_off_throttle_fuel_cut_fuel_resume_notused_00068fc4);
    fVar9 = DAT_ffffa480 + fVar9;
  }
  if (puVar4 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    fVar9 = fVar9 + 0.0;
  }
  fVar6 = DAT_ffffa454 + fVar9;
  DAT_ffffa45c = fVar9;
  if (((DAT_ffffa448 <= snapshot_inferred_predicted_engine_speed_ffffb55c) && (puVar4 = &DAT_0006c298, 0x5d < DAT_ffffa496)) &&
     (DAT_ffffb53a == '\0')) {
    fVar6 = rx8_min_float(fVar6,200.0);
    puVar4 = extraout_r0;
  }
  DAT_ffffa44c = fVar6;
  if (snapshot_inferred_predicted_engine_speed_ffffb55c < DAT_ffffa448) {
    DAT_ffffa496 = 0;
  }
  else {
    puVar4 = (undefined2 *)rx8_add_u16_saturate((int)(short)DAT_ffffa496,1);
    DAT_ffffa496 = (ushort)puVar4;
  }
  DAT_ffffa4a1 = cVar2;
  return puVar4;
}


