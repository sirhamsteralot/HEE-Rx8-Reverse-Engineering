/* [ADDITIONAL SOURCE REVIEW]
 * throttle_gear_mode_flags [high]: Sets b2cc/b2cd/b2ce from AT gear bytes 0xffffbc41/bc42/bc43 (and automatic_transmission_ffffb534); calls ref_throttlePlatePosToTorqueOutput_ 0x21a80; computes b2d4 = idle_air b2a4 + b38c, b2c0 = tbl 0x6a180 (Throttle Position To Torque), b2c4/b2e0 = tbl 0x6a164 (Trans Requested Torque To Throttle Plate Position). Called from 0x21b4c.
 * RAM 0xffffb2cc throttle_gear_mode_1_2 (uint8): Gear-mode flags b2cc/b2cd/b2ce set by 0x21970 from AT bytes bc41/bc42/bc43 + automatic_transmission b534; select the pedal-to-plate map (0x228dc) and the 0x21970 branch.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a164: Trans Requested Torque To Throttle Plate Position Position (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00021970; body bytes: 202; decompiled */

undefined4 * throttle_gear_mode_flags(void)

{
  undefined4 *puVar1;
  float snapshot_DAT_ffffbac8;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  if (automatic_transmission_ffffb534 == '\x01') {
    if (DAT_ffffbc41 == '\x01') {
      throttle_gear_mode_1_2_ffffb2cc = 1;
      DAT_ffffb2cd = 0;
    }
    else {
      if (DAT_ffffbc42 != '\x01') {
        if (DAT_ffffbc43 != '\x01') {
          throttle_gear_mode_1_2_ffffb2cc = 0;
          DAT_ffffb2cd = 0;
          DAT_ffffb2ce = 0;
          puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
          return puVar1;
        }
        throttle_gear_mode_1_2_ffffb2cc = 0;
        DAT_ffffb2cd = 0;
        DAT_ffffb2ce = 1;
        puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
        return puVar1;
      }
      throttle_gear_mode_1_2_ffffb2cc = 0;
      DAT_ffffb2cd = 1;
    }
  }
  else if (((DAT_ffffbc41 == '\0') && (DAT_ffffbc42 == '\0')) && (DAT_ffffbc43 == '\0')) {
    throttle_gear_mode_1_2_ffffb2cc = 0;
    DAT_ffffb2cd = 0;
  }
  else if (DAT_ffffbc41 == '\x01') {
    throttle_gear_mode_1_2_ffffb2cc = 1;
    DAT_ffffb2cd = 0;
  }
  else {
    if (DAT_ffffbc42 != '\x01') {
      if (DAT_ffffbc43 == '\x01') {
        throttle_gear_mode_1_2_ffffb2cc = 0;
        DAT_ffffb2cd = 0;
        DAT_ffffb2ce = 1;
      }
      inferred_throttle_position_ffffb2d4 = idle_air_required_ffffb2a4 + candidate_throttle_base_position_ffffb38c;
      snapshot_DAT_ffffbac8 = DAT_ffffbac8;
      snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
      DAT_ffffb2c0 = lookup_3d_descriptor_scaled(inferred_throttle_position_ffffb2d4,engine_speed_rpm_ffffb548,&tbl_throttle_position_to_torque_0006a180);
      DAT_ffffb2d8 = snapshot_DAT_ffffbac8;
      DAT_ffffb2dc = DAT_ffffb2c0;
      DAT_ffffb2c4 = lookup_3d_descriptor_scaled(snapshot_DAT_ffffbac8,snapshot_engine_speed_rpm_ffffb548,&tbl_trans_requested_torque_to_throttle_plate_position_position_0006a164);
      DAT_ffffb2e0 = DAT_ffffb2c4;
      if ((automatic_transmission_ffffb534 != '\0') || (puVar1 = &DAT_00021b3c, 256.0 < snapshot_DAT_ffffbac8)) {
        puVar1 = &DAT_00021b40;
        DAT_ffffb2c4 = 0x42c80000;
      }
      return puVar1;
    }
    throttle_gear_mode_1_2_ffffb2cc = 0;
    DAT_ffffb2cd = 1;
  }
  DAT_ffffb2ce = 0;
  puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
  return puVar1;
}


