/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b9ac: Table 3D - 126 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * misfire_type_count_lookup [high]: DAT_ffffcb64 = lookup_3d_descriptor_scaled(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6b9ac [10x17, x 0.16..1.1, y 780..8500, data 5..79.7]). Called from 0x287aa; feeds the sustained window 0x44436.
 */
/* ROM address: 0x0004441e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043c52 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_type_count_lookup(void)

{
  DAT_ffffcb64 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_126_0006b9ac);
  return;
}


