/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a814: Table 3D - 63 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_baro_comp [medium]: 0xffffa898 = 3-D tbl 0x6a814(baro 0xffffad14, 0xffffa834). Called from 0x167c0 via pool 0x16894.
 */
/* ROM address: 0x00016358; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001615c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_idle_baro_comp(void)

{
  DAT_ffffa898 = lookup_3d_descriptor_scaled(inferred_barometric_pressure_ffffad14,inferred_ram_a834_ffffa834_ffffa834,&tbl_table_3d_63_0006a814);
  return;
}


