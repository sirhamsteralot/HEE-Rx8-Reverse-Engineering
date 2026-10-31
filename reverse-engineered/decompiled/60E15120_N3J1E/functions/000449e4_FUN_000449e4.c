/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b9cc: Table 2D - 277 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000449e4; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00044200 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000449e4(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  uVar1 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_277_0006b9cc);
  DAT_ffffcb88 = extraout_fr0;
  if ((extraout_fr0 < engine_load_ffffc0b4) || (3910.0 < snapshot_engine_speed_rpm_ffffb548)) {
    DAT_ffffcb86 = 0;
  }
  else {
    DAT_ffffcb86 = 1;
  }
  return uVar1;
}


