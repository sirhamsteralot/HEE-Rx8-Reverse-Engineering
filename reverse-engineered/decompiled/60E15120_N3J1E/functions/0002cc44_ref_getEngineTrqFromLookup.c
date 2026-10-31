/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a7dc: Engine Torque (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002cc44; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d2e8 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getEngineTrqFromLookup(void)

{
  DAT_ffffbc98 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_engine_torque_0006a7dc);
  return;
}


