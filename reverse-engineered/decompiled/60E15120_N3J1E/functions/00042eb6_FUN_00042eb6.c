/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b918: Table 3D - 97 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b934: Table 3D - 98 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b950: Table 3D - 99 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042eb6; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000426ea (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00042eb6(void)

{
  undefined4 snapshot_DAT_ffffc9e8;
  undefined4 snapshot_DAT_ffffca24;
  
  snapshot_DAT_ffffc9e8 = DAT_ffffc9e8;
  snapshot_DAT_ffffca24 = DAT_ffffca24;
  DAT_ffffc9dc = lookup_3d_descriptor_scaled(DAT_ffffc9e8,DAT_ffffca24,&tbl_table_3d_97_0006b918);
  DAT_ffffc9e0 = lookup_3d_descriptor_scaled(snapshot_DAT_ffffc9e8,snapshot_DAT_ffffca24,&tbl_table_3d_98_0006b934);
  DAT_ffffc9e4 = lookup_3d_descriptor_scaled(snapshot_DAT_ffffc9e8,snapshot_DAT_ffffca24,&tbl_table_3d_99_0006b950);
  return;
}


