/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b71c: Injection Angle Related AFR Input (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b730: Unknown Lambda Input (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b758: AirFlow Inj Angle Related (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b76c: Table 2D - 264 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b7e4: Injection Angle (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003e39e; body bytes: 292; decompiled */

void FUN_0003e39e(void)

{
  float fVar1;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  float fVar5;
  
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  DAT_ffffc654 = rx8_max_float(DAT_ffffa778,DAT_ffffa77c);
  DAT_ffffc658 = lookup_2d_descriptor_scaled(mass_air_flow_ffffa9ec,&tbl_airflow_inj_angle_related_0006b758);
  fVar5 = 1.0;
  if (DAT_ffffc64c == '\x01') {
    DAT_ffffc65c = 0x3f800000;
  }
  else {
    DAT_ffffc65c = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_264_0006b76c);
  }
  if (DAT_ffffb12b == '\x01') {
    DAT_ffffc660 = open_loop_fuel_target_ffffb120;
    DAT_ffffc664 = (float)lookup_2d_descriptor_scaled(open_loop_fuel_target_ffffb120,&tbl_injection_angle_related_afr_input_0006b71c);
  }
  else {
    DAT_ffffc664 = 0.0;
  }
  DAT_ffffc668 = (rough_knock_correction_leading_ffffa6ac + coolant_timing_derate_leading_ffffa750 + DAT_ffffa66c + DAT_ffffc654) * 2.25;
  if (DAT_ffffb0ca == '\x01') {
    DAT_ffffc66c = 500.0;
  }
  else {
    DAT_ffffc6a0 = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_engine_load_ffffc0b4,&tbl_injection_angle_0006b7e4);
    DAT_ffffc66c = DAT_ffffc664 + DAT_ffffc668 + DAT_ffffc6a0;
  }
  if ((engine_running_ffffa428 == '\0') && (engine_stopped_latch_ffffa41c == '\0')) {
    ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffc640,&DAT_ffff8708);
  }
  fVar1 = fVar5;
  if (secondary_air_pump_request_ffffbf6c == '\x01') {
    fVar5 = (float)lookup_2d_descriptor_scaled(diag_afr_word_a_ffffaa6c,&tbl_unknown_lambda_input_0006b730);
    fVar1 = DAT_ffffc538 * fVar5;
  }
  DAT_ffffc674 = fVar1;
  DAT_ffffc670 = fVar5;
  FUN_0003e89e();
  return;
}


