/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b14c: Table 2D - 221 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b1d0: Table 3D - 83 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034126; body bytes: 118; decompiled */

uint FUN_00034126(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  float snapshot_DAT_ffffc164;
  
  snapshot_DAT_ffffc164 = DAT_ffffc164;
  DAT_ffffc118 = (float)lookup_2d_descriptor_scaled(DAT_ffffc164,&tbl_table_2d_221_0006b14c);
  DAT_ffffc11c = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&DAT_0006b0fc);
  if (0.0 <= snapshot_DAT_ffffc164) {
    DAT_ffffc114 = DAT_ffffc118 * 1.0 * DAT_ffffc11c;
  }
  else {
    DAT_ffffc114 = 0.0;
  }
  uVar1 = (uint)engine_injectors_off_ffffa42c;
  if ((uVar1 == 1) || (warmup_complete_flag_ffffc010 == '\0')) {
    DAT_ffffc120 = 0;
  }
  else {
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,&tbl_table_3d_83_0006b1d0);
    DAT_ffffc120 = extraout_fr0;
  }
  return uVar1;
}


