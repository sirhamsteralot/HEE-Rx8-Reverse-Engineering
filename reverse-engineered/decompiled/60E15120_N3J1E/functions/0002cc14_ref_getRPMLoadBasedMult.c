/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a7c0: Table 3D - 60 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002cc14; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d2b8 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getRPMLoadBasedMult(void)

{
  DAT_ffffbc90 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_60_0006a7c0);
  return;
}


