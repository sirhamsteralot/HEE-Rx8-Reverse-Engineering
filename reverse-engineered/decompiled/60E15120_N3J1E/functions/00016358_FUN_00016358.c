/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a814: Table 3D - 63 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016358; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001615c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00016358(void)

{
  DAT_ffffa898 = lookup_3d_descriptor_scaled(inferred_barometric_pressure_ffffad14,DAT_ffffa834,&tbl_table_3d_63_0006a814);
  return;
}


