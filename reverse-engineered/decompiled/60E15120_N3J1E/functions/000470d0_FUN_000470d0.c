/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ba30: Load Limit C (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000470d0; body bytes: 534; decompiled */

uint FUN_000470d0(void)

{
  ushort snapshot_inferred_throttle_sensor_volts_ffffad5c_ffffad5c;
  ushort snapshot_inferred_pedal_volts_ffffad5e_ffffad5e;
  char cVar3;
  byte snapshot_candidate_idle_learn_flag_ffffcc91;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_vehicle_speed_ffffbbb4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar7 = DAT_ffffcc9f;
  cVar6 = DAT_ffffcc99;
  cVar5 = DAT_ffffcc98;
  snapshot_candidate_idle_learn_flag_ffffcc91 = candidate_idle_learn_flag_ffffcc91;
  cVar3 = DAT_ffffb53a;
  snapshot_inferred_pedal_volts_ffffad5e_ffffad5e = inferred_pedal_volts_ffffad5e_ffffad5e;
  snapshot_inferred_throttle_sensor_volts_ffffad5c_ffffad5c = inferred_throttle_sensor_volts_ffffad5c_ffffad5c;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffcc78 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_load_limit_c_0006ba30);
  if (snapshot_engine_speed_rpm_ffffb548 < 3000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 2800.0) {
      DAT_ffffcc82 = '\0';
    }
  }
  else {
    DAT_ffffcc82 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 1150.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 1150.0) {
      DAT_ffffcc83 = '\0';
    }
  }
  else {
    DAT_ffffcc83 = '\x01';
  }
  if (snapshot_vehicle_speed_ffffbbb4 < 80.0) {
    if (snapshot_vehicle_speed_ffffbbb4 < 76.0) {
      DAT_ffffcc84 = '\0';
    }
  }
  else {
    DAT_ffffcc84 = '\x01';
  }
  if (((cVar7 == '\0') || (((cVar3 == '\0' && (DAT_ffffcc84 == '\x01')) && (DAT_ffffcc83 == '\0'))))
     || ((DAT_ffffcc82 == '\0' && ((cVar3 == '\x01' || (DAT_ffffcc84 == '\0')))))) {
    DAT_ffffcc76 = '\0';
  }
  else {
    DAT_ffffcc76 = '\x01';
  }
  if (((2 < snapshot_candidate_idle_learn_flag_ffffcc91) && (snapshot_candidate_idle_learn_flag_ffffcc91 < 5)) &&
     (((cVar5 == '\0' && (((cVar6 == '\x01' && (0x2b84 < snapshot_inferred_throttle_sensor_volts_ffffad5c_ffffad5c)) && (0x270 < DAT_ffffcc7c)))) ||
      (((((cVar5 == '\x01' && (cVar6 == '\0')) && (0x5603 < snapshot_inferred_pedal_volts_ffffad5e_ffffad5e)) && (0x270 < DAT_ffffcc7e)) ||
       ((DAT_ffffcc78 <= snapshot_engine_load_ffffc0b4 && (0x270 < DAT_ffffcc80)))))))) {
    DAT_ffffcc77 = 1;
  }
  uVar8 = 1;
  if ((DAT_ffffcc76 == '\x01') || (uVar8 = (uint)DAT_ffffcc77, uVar8 == 1)) {
    DAT_ffffcc71 = 1;
  }
  else {
    DAT_ffffcc71 = 0;
  }
  if (snapshot_inferred_throttle_sensor_volts_ffffad5c_ffffad5c < 0x2b85) {
    DAT_ffffcc7c = 0;
  }
  else {
    uVar8 = rx8_add_u16_saturate((int)(short)DAT_ffffcc7c,1);
    DAT_ffffcc7c = (ushort)uVar8;
  }
  if (snapshot_inferred_pedal_volts_ffffad5e_ffffad5e < 0x5604) {
    DAT_ffffcc7e = 0;
  }
  else {
    uVar8 = rx8_add_u16_saturate((int)(short)DAT_ffffcc7e,1);
    DAT_ffffcc7e = (ushort)uVar8;
  }
  if (snapshot_engine_load_ffffc0b4 < DAT_ffffcc78) {
    DAT_ffffcc80 = 0;
  }
  else {
    uVar8 = rx8_add_u16_saturate((int)(short)DAT_ffffcc80,1);
    DAT_ffffcc80 = (ushort)uVar8;
  }
  return uVar8;
}


