/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a180: Throttle Position To Torque (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00021ae8; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022454 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getThrottleBasedTorque_Related(void)

{
  inferred_throttle_position_ffffb2d4 = inferred_throttle_position_ffffad44;
  DAT_ffffb2e8 = lookup_3d_descriptor_scaled(inferred_throttle_position_ffffad44,engine_speed_rpm_ffffb548,&tbl_throttle_position_to_torque_0006a180);
  DAT_ffffb2c8 = DAT_ffffb2e8;
  return;
}


