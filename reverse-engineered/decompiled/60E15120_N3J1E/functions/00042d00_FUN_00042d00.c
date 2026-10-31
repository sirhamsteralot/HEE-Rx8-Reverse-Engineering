/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b800: Table 2D - 270 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b814: Table 2D - 271 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042d00; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042534 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00042d00(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float snapshot_DAT_ffffca30;
  
  snapshot_DAT_ffffca30 = DAT_ffffca30;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffca30,0,0x3727c5ac);
  if (cVar2 != '\0') {
    DAT_ffffca2c = engine_speed_rpm_ffffb548 / snapshot_DAT_ffffca30;
  }
  if ((DAT_ffffca4f == '\0') || (DAT_ffffb53a == '\x01')) {
    DAT_ffffca28 = lookup_2d_descriptor_scaled(DAT_ffffca2c,&tbl_table_2d_271_0006b814);
    uVar1 = lookup_2d_descriptor_scaled(DAT_ffffca2c,&tbl_table_2d_270_0006b800);
    DAT_ffffca24 = extraout_fr0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


