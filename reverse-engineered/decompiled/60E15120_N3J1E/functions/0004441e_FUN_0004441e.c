/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b9ac: Table 3D - 126 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004441e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043c52 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004441e(void)

{
  DAT_ffffcb64 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_126_0006b9ac);
  return;
}


