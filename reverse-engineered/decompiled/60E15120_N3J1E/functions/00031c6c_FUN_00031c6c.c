/* [ADDITIONAL SOURCE REVIEW]
 * apv_target_condition [medium]: Computes APV target state bf8d from RPM >= 150/200 (bf99), counter bf92 > 0x32, aa68; uses MAF a9ec and coolant a98c snapshots.
 * RAM 0xffffbf8d apv_target_state (uint8): APV target condition from RPM/counter/aa68.
 * RAM 0xffffbf8e apv_target_state_prev (uint8): previous bf8d.
 * RAM 0xffffbf92 apv_counter_92 (uint8): > 0x32 term in APV target logic.
 * RAM 0xffffbf99 apv_rpm_low_flag (uint8): RPM >= 200 (clear below 150).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00031c6c; body bytes: 504; decompiled */

void candidate_apv_target_condition(void)

{
  char cVar1;
  float snapshot_mass_air_flow_ffffa9ec;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_speed_rpm_ffffb548;
  undefined4 local_28;
  char cStack_24;
  char cStack_20;
  
  cStack_24 = apv_target_state_ffffbf8d;
  cStack_20 = apv_target_state_prev_ffffbf8e;
  if (engine_speed_rpm_ffffb548 < 200.0) {
    if (engine_speed_rpm_ffffb548 < 150.0) {
      apv_rpm_low_flag_ffffbf99 = '\0';
    }
  }
  else {
    apv_rpm_low_flag_ffffbf99 = '\x01';
  }
  if ((apv_target_state_prev_ffffbf8e == '\0') && (0x32 < apv_counter_92_ffffbf92)) {
    apv_target_state_ffffbf8d = '\0';
  }
  else if ((engine_running_flag_ffffaa68 == '\0') && (apv_rpm_low_flag_ffffbf99 == '\0')) {
    apv_target_state_ffffbf8d = '\x01';
  }
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  if (((apv_target_state_ffffbf8d == '\x01') && (DAT_ffffccc6 == '\0')) && (DAT_ffffa8ea == '\0')) {
    apv_target_state_prev_ffffbf8e = DAT_ffffbf90 < 0x32;
    DAT_ffffbf90 = rx8_add_u16_saturate((int)(short)DAT_ffffbf90,1);
  }
  else {
    apv_target_state_prev_ffffbf8e = '\0';
    DAT_ffffbf90 = 0;
  }
  cVar1 = cStack_24;
  if ((cStack_20 == '\x01') && (apv_target_state_prev_ffffbf8e == '\0')) {
    apv_counter_92_ffffbf92 = 0;
    DAT_ffffbf9a = '\x01';
  }
  else if ((DAT_ffffbf9a == '\x01') && (apv_counter_92_ffffbf92 != 0xffff)) {
    apv_counter_92_ffffbf92 = apv_counter_92_ffffbf92 + 1;
  }
  if ((cStack_24 == '\0') && (apv_target_state_ffffbf8d == '\x01')) {
    local_28 = 0;
    os_schedule_task_event(0,2,&local_28);
  }
  if ((cVar1 == '\x01') && (apv_target_state_ffffbf8d == '\0')) {
    local_28 = 0;
    os_schedule_task_event(0,3,&local_28);
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 6100.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5912.5) {
      DAT_ffffbf94 = '\0';
    }
  }
  else {
    DAT_ffffbf94 = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 20.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 18.12) {
      DAT_ffffbf95 = '\0';
    }
  }
  else {
    DAT_ffffbf95 = '\x01';
  }
  if (snapshot_mass_air_flow_ffffa9ec < 0.0) {
    if (snapshot_mass_air_flow_ffffa9ec < -0.25) {
      DAT_ffffbf96 = '\0';
    }
  }
  else {
    DAT_ffffbf96 = '\x01';
  }
  if ((((DAT_ffffbf94 == '\x01') && (DAT_ffffbf95 == '\x01')) && (DAT_ffffbf96 == '\x01')) ||
     (apv_target_state_prev_ffffbf8e == '\x01')) {
    DAT_ffffbf8c = '\x01';
  }
  else {
    DAT_ffffbf8c = '\0';
  }
  DAT_ffffbf97 = DAT_ffffbf8c == '\0';
  apv_direction_flag_ffffbf8b = ref_diagControlMode__(DAT_ffffbf97);
  return;
}


