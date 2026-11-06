/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a934: Table 2D - 164 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a948: Table 2D - 165 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002ebda; body bytes: 882; decompiled */

undefined4 FUN_0002ebda(void)

{
  char cVar1;
  float snapshot_inferred_throttle_position_ffffad44;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined4 uVar8;
  float snapshot_DAT_ffffa7ac;
  float fVar10;
  float snapshot_vehicle_speed_ffffbbb4;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar7 = inferred_ram_bf9c_ffffbf9c_ffffbf9c;
  cVar6 = inferred_ram_bdb8_ffffbdb8_ffffbdb8;
  cVar5 = inferred_ram_b53b_ffffb53b_ffffb53b;
  cVar4 = DAT_ffffb53a;
  cVar3 = automatic_transmission_ffffb534;
  snapshot_inferred_throttle_position_ffffad44 = inferred_throttle_position_ffffad44;
  cVar1 = cranking_active_ffffaa62_ffffaa62;
  snapshot_DAT_ffffa7ac = inferred_ram_a7ac_ffffa7ac_ffffa7ac;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffbd7c = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_164_0006a934);
  DAT_ffffbd80 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_165_0006a948);
  fVar10 = snapshot_DAT_ffffa7ac + 0.0;
  if (snapshot_vehicle_speed_ffffbbb4 < 5.0) {
    if (snapshot_vehicle_speed_ffffbbb4 < 2.0) {
      DAT_ffffbd99 = '\0';
    }
  }
  else {
    DAT_ffffbd99 = '\x01';
  }
  if (snapshot_vehicle_speed_ffffbbb4 < 5.0) {
    if (snapshot_vehicle_speed_ffffbbb4 < 2.0) {
      DAT_ffffbd9a = '\0';
    }
  }
  else {
    DAT_ffffbd9a = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 20.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 17.5) {
      DAT_ffffbd9b = '\0';
    }
  }
  else {
    DAT_ffffbd9b = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 120.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 117.5) {
      DAT_ffffbd9c = '\0';
    }
  }
  else {
    DAT_ffffbd9c = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 2000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 1800.0) {
      DAT_ffffbd9d = '\0';
    }
  }
  else {
    DAT_ffffbd9d = '\x01';
  }
  if (((((DAT_ffffbd99 != '\0') || (cVar1 != '\0')) || (0x3d < DAT_ffffbd8c)) ||
      (snapshot_engine_speed_rpm_ffffb548 < snapshot_DAT_ffffa7ac + -500.0)) ||
     (((cVar4 != '\0' && (((cVar3 != '\x01' || (cVar5 != '\0')) || (cVar7 != '\x01')))) ||
      (((snapshot_inferred_throttle_position_ffffad44 < DAT_ffffbd7c || (cVar6 != '\0')) && ((snapshot_inferred_throttle_position_ffffad44 < 8.0 || (cVar6 != '\x01')))))))) {
    if ((0x3e < DAT_ffffbd6e) || ((0x1f < DAT_ffffbd6e && (cVar6 == '\x01')))) {
      DAT_ffffbd74 = '\0';
    }
  }
  else {
    DAT_ffffbd74 = '\x01';
    DAT_ffffbd6e = 0;
  }
  DAT_ffffbd6e = rx8_add_u16_saturate((int)(short)DAT_ffffbd6e,1);
  if ((((DAT_ffffbd9a != '\0') || (snapshot_DAT_ffffa7ac + -250.0 <= snapshot_engine_speed_rpm_ffffb548)) || (cVar3 != '\x01')) ||
     ((cVar5 != '\0' || (cVar7 != '\x01')))) {
    if (0x3e < DAT_ffffbd70) {
      DAT_ffffbd75 = '\0';
    }
  }
  else {
    DAT_ffffbd75 = '\x01';
    DAT_ffffbd70 = 0;
  }
  DAT_ffffbd70 = rx8_add_u16_saturate((int)(short)DAT_ffffbd70,1);
  if (((DAT_ffffbd9d == '\0') && (DAT_ffffbd9b == '\x01')) &&
     ((DAT_ffffbd9c == '\0' && ((DAT_ffffbd74 == '\x01' || (DAT_ffffbd75 == '\x01')))))) {
    DAT_ffffbd73 = 1;
  }
  else {
    DAT_ffffbd73 = 0;
  }
  if (cVar1 == '\0') {
    DAT_ffffbd8c = rx8_add_u16_saturate((int)(short)DAT_ffffbd8c,1);
  }
  else {
    DAT_ffffbd8c = 0;
  }
  uVar8 = 4;
  if (snapshot_DAT_ffffa7ac + -250.0 <= snapshot_engine_speed_rpm_ffffb548) {
    DAT_ffffbd8e = 0;
  }
  else {
    uVar8 = rx8_add_u16_saturate((int)DAT_ffffbd8e,1);
    DAT_ffffbd8e = (short)uVar8;
  }
  if (snapshot_engine_speed_rpm_ffffb548 < fVar10) {
    DAT_ffffbd90 = 0;
  }
  else {
    uVar8 = rx8_add_u16_saturate((int)DAT_ffffbd90,1);
    DAT_ffffbd90 = (short)uVar8;
  }
  return uVar8;
}


