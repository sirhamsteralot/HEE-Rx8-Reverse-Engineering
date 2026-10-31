/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b030: Table 2D - 214 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00033c10; body bytes: 108; decompiled */

undefined4 FUN_00033c10(void)

{
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float snapshot_DAT_ffffc15c;
  
  snapshot_DAT_ffffc15c = DAT_ffffc15c;
  DAT_ffffc0e4 = (float)lookup_2d_descriptor_scaled(DAT_ffffc15c,&tbl_table_2d_214_0006b030);
  DAT_ffffc0e8 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&DAT_0006afe0);
  if (snapshot_DAT_ffffc15c < 0.0) {
    DAT_ffffc0e0 = DAT_ffffc0e4 * 1.0 * DAT_ffffc0e8;
  }
  else {
    DAT_ffffc0e0 = 0.0;
  }
  if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffc0ec = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,&DAT_0006b074);
    DAT_ffffc0ec = extraout_fr0;
  }
  return uVar1;
}


