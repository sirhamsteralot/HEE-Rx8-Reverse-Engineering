/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a164: Trans Requested Torque To Throttle Plate Position Position (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a180: Throttle Position To Torque (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00021970; body bytes: 202; decompiled */

undefined4 * FUN_00021970(void)

{
  undefined4 *puVar1;
  float snapshot_DAT_ffffbac8;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  if (DAT_ffffb534 == '\x01') {
    if (DAT_ffffbc41 == '\x01') {
      DAT_ffffb2cc = 1;
      DAT_ffffb2cd = 0;
    }
    else {
      if (DAT_ffffbc42 != '\x01') {
        if (DAT_ffffbc43 != '\x01') {
          DAT_ffffb2cc = 0;
          DAT_ffffb2cd = 0;
          DAT_ffffb2ce = 0;
          puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
          return puVar1;
        }
        DAT_ffffb2cc = 0;
        DAT_ffffb2cd = 0;
        DAT_ffffb2ce = 1;
        puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
        return puVar1;
      }
      DAT_ffffb2cc = 0;
      DAT_ffffb2cd = 1;
    }
  }
  else if (((DAT_ffffbc41 == '\0') && (DAT_ffffbc42 == '\0')) && (DAT_ffffbc43 == '\0')) {
    DAT_ffffb2cc = 0;
    DAT_ffffb2cd = 0;
  }
  else if (DAT_ffffbc41 == '\x01') {
    DAT_ffffb2cc = 1;
    DAT_ffffb2cd = 0;
  }
  else {
    if (DAT_ffffbc42 != '\x01') {
      if (DAT_ffffbc43 == '\x01') {
        DAT_ffffb2cc = 0;
        DAT_ffffb2cd = 0;
        DAT_ffffb2ce = 1;
      }
      inferred_throttle_position_ffffb2d4 = DAT_ffffb2a4 + DAT_ffffb38c;
      snapshot_DAT_ffffbac8 = DAT_ffffbac8;
      snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
      DAT_ffffb2c0 = lookup_3d_descriptor_scaled(inferred_throttle_position_ffffb2d4,engine_speed_rpm_ffffb548,&tbl_throttle_position_to_torque_0006a180);
      DAT_ffffb2d8 = snapshot_DAT_ffffbac8;
      DAT_ffffb2dc = DAT_ffffb2c0;
      DAT_ffffb2c4 = lookup_3d_descriptor_scaled(snapshot_DAT_ffffbac8,snapshot_engine_speed_rpm_ffffb548,&tbl_trans_requested_torque_to_throttle_plate_position_position_0006a164);
      DAT_ffffb2e0 = DAT_ffffb2c4;
      if ((DAT_ffffb534 != '\0') || (puVar1 = &DAT_00021b3c, 256.0 < snapshot_DAT_ffffbac8)) {
        puVar1 = &DAT_00021b40;
        DAT_ffffb2c4 = 0x42c80000;
      }
      return puVar1;
    }
    DAT_ffffb2cc = 0;
    DAT_ffffb2cd = 1;
  }
  DAT_ffffb2ce = 0;
  puVar1 = (undefined4 *)ref_throttlePlatePosToTorqueOutput_();
  return puVar1;
}


