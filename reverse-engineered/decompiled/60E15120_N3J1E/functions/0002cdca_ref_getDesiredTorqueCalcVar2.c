/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a7f8: Table 3D - 62 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002cdca; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d46e (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDesiredTorqueCalcVar2(void)

{
  DAT_ffffbcb8 = lookup_3d_descriptor_scaled(0x42a00000,engine_speed_rpm_ffffb548,&tbl_table_3d_62_0006a7f8);
  return;
}


