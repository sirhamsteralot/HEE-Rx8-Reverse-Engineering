/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b318: Table 2D - 228 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b32c: Table 2D - 229 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_vehicle_speed_flags [medium]: AT branch: 0xffffc1b4 = tbl 0x6b318(vspeed), 0xffffc1b8 = tbl 0x6b32c(rpm), 0xffffc1a0 = c1b4 * clamp((680.0 - rpm)/130.0, 0, 1), 0xffffc1a8 = max(c1a0, c1a8 - c1b8), 0xffffc1bc = rpm >= 680 (clears below 672.1875). Called from 0x167c0 via pool 0x168e4.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034650; body bytes: 356; decompiled */

uint candidate_idle_vehicle_speed_flags(void)

{
  uint uVar1;
  char cVar2;
  uint extraout_r0;
  float fVar3;
  float arg2;
  float snapshot_inferred_coolant_temperature_ffffa990;
  float fVar5;
  float snapshot_engine_speed_rpm_ffffb548;
  
  uVar1 = (uint)automatic_transmission_ffffb534;
  fVar5 = DAT_ffffc1ac;
  if (uVar1 == 1) {
    snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
    snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
    DAT_ffffc1b4 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_table_2d_228_0006b318);
    DAT_ffffc1b8 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_229_0006b32c);
    arg2 = 1.0;
    fVar5 = 0.0;
    fVar3 = rx8_clamp_float((680.0 - snapshot_engine_speed_rpm_ffffb548) / 130.0,0.0,1.0);
    DAT_ffffc1a0 = DAT_ffffc1b4 * fVar3;
    DAT_ffffc1a4 = rx8_max_float(DAT_ffffc1a8 - DAT_ffffc1b8,fVar5);
    DAT_ffffc1a8 = rx8_max_float(DAT_ffffc1a0,DAT_ffffc1a4);
    if (snapshot_engine_speed_rpm_ffffb548 < 680.0) {
      if (snapshot_engine_speed_rpm_ffffb548 < 672.1875) {
        DAT_ffffc1bc = '\0';
      }
    }
    else {
      DAT_ffffc1bc = '\x01';
    }
    if (snapshot_inferred_coolant_temperature_ffffa990 < 70.0) {
      if (snapshot_inferred_coolant_temperature_ffffa990 < 65.0) {
        DAT_ffffc1bd = '\0';
      }
    }
    else {
      DAT_ffffc1bd = '\x01';
    }
    cVar2 = rx8_is_outside_tolerance_band(DAT_ffffc1a8,fVar5,0x3727c5ac);
    if (((DAT_ffffa844 == '\x01') && (DAT_ffffc1bc == '\0')) && (DAT_ffffc1bd == '\x01')) {
      DAT_ffffc1b0 = '\x01';
    }
    else if (cVar2 == '\0') {
      DAT_ffffc1b0 = '\0';
    }
    uVar1 = (uint)DAT_ffffb53a;
    if (uVar1 == 1) {
      if (DAT_ffffc1b0 != '\0') {
        fVar5 = rx8_clamp_float((snapshot_inferred_coolant_temperature_ffffa990 - 70.0) / 10.0,fVar5,arg2);
        uVar1 = extraout_r0;
        fVar5 = DAT_ffffc1a8 * fVar5;
      }
    }
    else {
      DAT_ffffc1ac = DAT_ffffc1b4;
      fVar5 = DAT_ffffc1ac;
    }
  }
  DAT_ffffc1ac = fVar5;
  return uVar1;
}


