/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a150: DSC Mode C - Max Throttle Plate Opening Allowed (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a164: Trans Requested Torque To Throttle Plate Position Position (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000218c4; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022230 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_throttlePlateControl_Related(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  undefined4 snapshot_candidate_throttle_base_position_ffffb38c;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  float snapshot_inferred_desired_torque_ffffbbd4;
  
  DAT_ffffb2d8 = inferred_desired_torque_ffffbbd4;
  snapshot_candidate_throttle_base_position_ffffb38c = candidate_throttle_base_position_ffffb38c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  snapshot_inferred_desired_torque_ffffbbd4 = inferred_desired_torque_ffffbbd4;
  DAT_ffffb2e4 = lookup_3d_descriptor_scaled(inferred_desired_torque_ffffbbd4,engine_speed_rpm_ffffb548,&tbl_trans_requested_torque_to_throttle_plate_position_position_0006a164);
  if (((DAT_ffffbbcb == '\x01') && (snapshot_inferred_desired_torque_ffffbbd4 <= DAT_ffffb2c0)) || (DAT_ffffa966 == '\x01')) {
    DAT_ffffb2cf = 1;
    DAT_ffffb2b8 = DAT_ffffb2e4;
  }
  else {
    DAT_ffffb2cf = 0;
    DAT_ffffb2b8 = snapshot_candidate_throttle_base_position_ffffb38c;
  }
  uVar1 = (uint)DAT_ffffbbcc;
  if ((uVar1 == 1) && (DAT_ffffbbca == '\0')) {
    uVar1 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_dsc_mode_c_max_throttle_plate_opening_allowed_0006a150);
    DAT_ffffb2d0 = 1;
    DAT_ffffb2bc = extraout_fr0;
  }
  else {
    DAT_ffffb2d0 = 0;
    DAT_ffffb2bc = snapshot_candidate_throttle_base_position_ffffb38c;
  }
  return uVar1;
}


