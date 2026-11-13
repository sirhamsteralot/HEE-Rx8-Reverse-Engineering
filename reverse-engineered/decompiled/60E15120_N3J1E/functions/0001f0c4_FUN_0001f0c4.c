/* [ADDITIONAL SOURCE REVIEW]
 * open_loop_request_condition [high]: Sets b12a=1 when load/throttle exceed 'Closed Loop Fuelling Threshold' tables 0x69d24/0x69d38/0x69d4c/0x69d60/0x69d74 with hysteresis flags b1b6/b1b7, throttle threshold b15c and timers b148/b14e.
 * RAM 0xffffb15c cl_throttle_threshold (float): b15c = tbl 0x69d74 'Closed Loop Fuelling Threshold (Throttle Position)'(rpm); compared against throttle ad44 in open_loop_request_condition.
 * RAM 0xffffb160 cl_load_threshold_a (float): b160 = tbl 0x69d24 'Closed Loop Fuelling Threshold (Engine Load A)'(rpm).
 * RAM 0xffffb164 cl_load_threshold_b (float): b164 = tbl 0x69d38 (Engine Load B)(rpm).
 * RAM 0xffffb168 cl_load_threshold_c (float): b168 = tbl 0x69d4c (Engine Load C)(rpm).
 * RAM 0xffffb16c cl_unknown_threshold_a (float): b16c = tbl 0x69d60 'Closed Loop Fuelling Threshold (Unknown A)'(rpm).
 * RAM 0xffffb1b6 cl_load_a_exceeded (uint8): b1b6 = load >= b160 (hysteresis -0.04) in 0x1f0c4.
 * RAM 0xffffb1b7 cl_load_b_exceeded (uint8): b1b7 = load >= b164 (hysteresis) in 0x1f0c4.
 * RAM 0xffffb1b8 cl_load_c_exceeded (uint8): b1b8 = load >= b168 (hysteresis) in 0x1f0c4.
 * RAM 0xffffb1b1 coolant_above_78_flag (uint8): b1b1 = coolant >= 80 (clear below 78) in open_loop_request_condition.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069d38: Closed Loop Fuelling Threshold (Engine Load B) (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069d4c: Closed Loop Fuelling Threshold (Engine Load C) (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e14: Table 2D - 320 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e20: Table 2D - 321 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e2c: Table 2D - 322 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e38: Table 2D - 323 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001f0c4; body bytes: 1166; decompiled */

uint open_loop_request_condition(void)

{
  float snapshot_inferred_throttle_position_ffffad44;
  byte snapshot_DAT_ffffbecc;
  float snapshot_fuel_correction_sum_ffffc644_ffffc644;
  short sVar4;
  uint uVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  float snapshot_fuel_volume_final_ffffbeb0;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float fVar10;
  float snapshot_engine_load_ffffc0b4;
  float fVar12;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_fuel_correction_sum_ffffc644_ffffc644 = fuel_correction_sum_ffffc644_ffffc644;
  snapshot_DAT_ffffbecc = DAT_ffffbecc;
  fVar10 = fuel_amount_per_rotation_a_ffffbec8;
  snapshot_inferred_throttle_position_ffffad44 = inferred_throttle_position_ffffad44;
  fVar12 = inferred_barometric_pressure_ffffad14;
  snapshot_fuel_volume_final_ffffbeb0 = fuel_volume_final_ffffbeb0;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cl_throttle_threshold_ffffb15c = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_closed_loop_fuelling_threshold_throttle_position_00069d74);
  cl_load_threshold_a_ffffb160 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_closed_loop_fuelling_threshold_engine_load_a_00069d24);
  cl_load_threshold_b_ffffb164 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_closed_loop_fuelling_threshold_engine_load_b_00069d38);
  cl_load_threshold_c_ffffb168 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_closed_loop_fuelling_threshold_engine_load_c_00069d4c);
  cl_unknown_threshold_a_ffffb16c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_closed_loop_fuelling_threshold_unknown_a_00069d60);
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_a_ffffb160) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_a_ffffb160 + -0.04) {
      cl_load_a_exceeded_ffffb1b6 = '\0';
    }
  }
  else {
    cl_load_a_exceeded_ffffb1b6 = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_b_ffffb164) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_b_ffffb164 + -0.04) {
      cl_load_b_exceeded_ffffb1b7 = '\0';
    }
  }
  else {
    cl_load_b_exceeded_ffffb1b7 = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_c_ffffb168) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_c_ffffb168 + -0.04) {
      cl_load_c_exceeded_ffffb1b8 = '\0';
    }
  }
  else {
    cl_load_c_exceeded_ffffb1b8 = '\x01';
  }
  if (snapshot_fuel_correction_sum_ffffc644_ffffc644 < 950.0) {
    if (snapshot_fuel_correction_sum_ffffc644_ffffc644 < 900.0) {
      DAT_ffffb1b0 = '\0';
    }
  }
  else {
    DAT_ffffb1b0 = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 80.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 78.0) {
      coolant_above_78_flag_ffffb1b1 = '\0';
    }
  }
  else {
    coolant_above_78_flag_ffffb1b1 = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < -40.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < -42.0) {
      DAT_ffffb1b2 = '\0';
    }
  }
  else {
    DAT_ffffb1b2 = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 200.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 197.0) {
      DAT_ffffb1b3 = 0;
    }
  }
  else {
    DAT_ffffb1b3 = 1;
  }
  if (snapshot_fuel_volume_final_ffffbeb0 < fuel_amount_per_rotation_a_ffffbec8 * 0.7) {
    if (snapshot_fuel_volume_final_ffffbeb0 < fuel_amount_per_rotation_a_ffffbec8 * 0.7 - 0.005) {
      DAT_ffffb1b4 = '\0';
    }
  }
  else {
    DAT_ffffb1b4 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 6000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5750.0) {
      DAT_ffffb1b5 = '\0';
    }
  }
  else {
    DAT_ffffb1b5 = '\x01';
  }
  if (snapshot_inferred_throttle_position_ffffad44 < cl_throttle_threshold_ffffb15c) {
    if (snapshot_inferred_throttle_position_ffffad44 < cl_throttle_threshold_ffffb15c + -3.0) {
      DAT_ffffb1ae = '\0';
    }
  }
  else {
    DAT_ffffb1ae = '\x01';
  }
  if (fVar12 < 10.0) {
    if (fVar12 < 0.0) {
      DAT_ffffb1af = '\0';
    }
  }
  else {
    DAT_ffffb1af = '\x01';
  }
  if (safe_mode_ffffcd60 == '\0') {
    ppuVar6 = (undefined **)&tbl_table_2d_320_check_datatype_00069e14;
  }
  else {
    ppuVar6 = &tbl_table_2d_321_check_datatype_00069e20;
  }
  DAT_ffffb148 = rx8_lookup_2d_raw_u16(snapshot_engine_speed_rpm_ffffb548,ppuVar6);
  if (DAT_ffffb1af == '\x01') {
    puVar7 = &tbl_table_2d_322_check_datatype_00069e2c;
  }
  else {
    puVar7 = &tbl_table_2d_323_check_datatype_00069e38;
  }
  DAT_ffffb14a = rx8_lookup_2d_raw_u16(snapshot_engine_speed_rpm_ffffb548,puVar7);
  sVar4 = DAT_ffffb14a;
  if ((DAT_ffffb1ae == '\x01') && (sVar4 = DAT_ffffb14c, DAT_ffffb14c != 0)) {
    sVar4 = DAT_ffffb14c + -1;
  }
  DAT_ffffb14c = sVar4;
  if ((((cl_unknown_threshold_a_ffffb16c <= snapshot_engine_load_ffffc0b4) || (DAT_ffffb1b0 == '\x01')) ||
      ((coolant_above_78_flag_ffffb1b1 == '\0' && ((DAT_ffffb1b2 == '\x01' && (DAT_ffffb1b4 == '\x01')))))) ||
     ((cl_throttle_threshold_ffffb15c <= snapshot_inferred_throttle_position_ffffad44 && (DAT_ffffb14c == 0)))) {
    DAT_ffffb14e = 0;
  }
  else if (cl_load_a_exceeded_ffffb1b6 == '\x01') {
    if (DAT_ffffb14e != 0) {
      DAT_ffffb14e = DAT_ffffb14e + -1;
    }
  }
  else {
    DAT_ffffb14e = DAT_ffffb148;
  }
  if ((DAT_ffffb14e == 0) || ((cl_load_a_exceeded_ffffb1b6 != '\x01' && (DAT_ffffb1ae != '\x01')))) {
    DAT_ffffb12b = 0;
  }
  else {
    DAT_ffffb12b = 1;
  }
  if (((DAT_ffffb14e == 0) &&
      (((DAT_ffffb158 == '\0' && (cl_load_a_exceeded_ffffb1b6 == '\x01')) ||
       (((DAT_ffffb158 == '\x01' && (cl_load_b_exceeded_ffffb1b7 == '\x01')) || (DAT_ffffb1ae == '\x01')))))) ||
     ((DAT_ffffb1b5 == '\x01' || ((cl_load_c_exceeded_ffffb1b8 == '\x01' && (ol_timer_expired_ffffb159 == '\0')))))) {
    open_loop_request_ffffb12a = 1;
  }
  else {
    open_loop_request_ffffb12a = 0;
  }
  fVar12 = fVar10 * 0.95;
  if (((coolant_above_78_flag_ffffb1b1 != '\x01') || (snapshot_engine_speed_rpm_ffffb548 < 2000.0)) ||
     (((snapshot_fuel_volume_final_ffffbeb0 < fVar12 || ((DAT_ffffb1a4 <= DAT_ffffb1a0 || (DAT_ffffb128 != 0)))) &&
      ((snapshot_DAT_ffffbecc != 1 || (DAT_ffffb1db != '\0')))))) {
    if (DAT_ffffb128 != 0) {
      DAT_ffffb128 = DAT_ffffb128 + -1;
    }
  }
  else {
    DAT_ffffb128 = rx8_lookup_2d_raw_u16(snapshot_engine_speed_rpm_ffffb548,&PTR_CAL_table_845_00069e68);
  }
  uVar5 = (uint)DAT_ffffb1b3;
  fVar10 = fVar10 * (float)0x3f733333;
  if (((uVar5 != 1) || (snapshot_engine_speed_rpm_ffffb548 < 2000.0)) ||
     (((snapshot_fuel_volume_final_ffffbeb0 < fVar10 || ((DAT_ffffb1a8 <= DAT_ffffb1a0 || (DAT_ffffb146 != 0)))) &&
      ((uVar5 = (uint)snapshot_DAT_ffffbecc, uVar5 != 1 || (DAT_ffffb1db != '\0')))))) {
    if (DAT_ffffb146 != 0) {
      DAT_ffffb146 = DAT_ffffb146 + -1;
    }
  }
  else {
    uVar5 = rx8_lookup_2d_raw_u16(snapshot_engine_speed_rpm_ffffb548,&PTR_CAL_table_845_00069e74);
    DAT_ffffb146 = (short)uVar5;
  }
  DAT_ffffb1a0 = snapshot_fuel_volume_final_ffffbeb0;
  DAT_ffffb1a4 = fVar12;
  DAT_ffffb1a8 = fVar10;
  DAT_ffffb1db = snapshot_DAT_ffffbecc;
  return uVar5;
}


