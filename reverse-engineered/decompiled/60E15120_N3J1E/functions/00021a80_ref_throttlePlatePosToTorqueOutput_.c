/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a164: Trans Requested Torque To Throttle Plate Position Position (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a180: Throttle Position To Torque (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00021a80; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000223ec (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_throttlePlatePosToTorqueOutput_(void)

{
  undefined4 *puVar1;
  float in_fr14;
  undefined4 in_fr15;
  
  inferred_throttle_position_ffffb2d4 = idle_air_required_ffffb2a4 + candidate_throttle_base_position_ffffb38c;
  DAT_ffffb2c0 = lookup_3d_descriptor_scaled(inferred_throttle_position_ffffb2d4,&tbl_throttle_position_to_torque_0006a180);
  DAT_ffffb2d8 = in_fr14;
  DAT_ffffb2dc = DAT_ffffb2c0;
  DAT_ffffb2c4 = lookup_3d_descriptor_scaled(in_fr14,in_fr15,&tbl_trans_requested_torque_to_throttle_plate_position_position_0006a164);
  DAT_ffffb2e0 = DAT_ffffb2c4;
  if ((automatic_transmission_ffffb534 != '\0') || (puVar1 = &DAT_00021b3c, 256.0 < in_fr14)) {
    puVar1 = &DAT_00021b40;
    DAT_ffffb2c4 = 0x42c80000;
  }
  return puVar1;
}


