/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b138: Table 2D - 220 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b198: Table 3D - 81 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b1b4: Table 3D - 82 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034050; body bytes: 128; decompiled */

undefined4 FUN_00034050(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  float snapshot_DAT_ffffc15c;
  
  snapshot_DAT_ffffc15c = DAT_ffffc15c;
  DAT_ffffc128 = (float)lookup_2d_descriptor_scaled(DAT_ffffc15c,&tbl_table_2d_220_0006b138);
  DAT_ffffc12c = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&DAT_0006b0e8);
  if (0.0 <= snapshot_DAT_ffffc15c) {
    DAT_ffffc124 = DAT_ffffc128 * 1.0 * DAT_ffffc12c;
  }
  else {
    DAT_ffffc124 = 0.0;
  }
  if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffc130 = 0;
    uVar1 = 1;
  }
  else {
    if (warmup_complete_flag_ffffc010 == '\x01') {
      puVar2 = &tbl_table_3d_82_0006b1b4;
    }
    else {
      puVar2 = &tbl_table_3d_81_0006b198;
    }
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,puVar2);
    DAT_ffffc130 = extraout_fr0;
  }
  return uVar1;
}


