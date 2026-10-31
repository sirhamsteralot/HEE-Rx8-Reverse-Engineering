/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069384: Idle Target Minimum - Open Loop Conditonal (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069398: Idle Target Minimum - Closed Loop Conditonal (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693ac: Idle Target Minimum - Reset Value (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00015818; body bytes: 192; decompiled */

undefined4 FUN_00015818(undefined4 param_1)

{
  ushort snapshot_DAT_ffffa6b4;
  ushort uVar3;
  undefined4 uVar2;
  undefined4 extraout_r0;
  float extraout_fr0;
  float arg1;
  
  snapshot_DAT_ffffa6b4 = DAT_ffffa6b4;
  arg1 = 500.0;
  if (DAT_ffffa6b4 == 0) {
    DAT_ffffa7d8 = (float)lookup_2d_descriptor_scaled(param_1,&tbl_idle_target_minimum_open_loop_conditonal_00069384);
  }
  else if (DAT_ffffa6b4 < 0x76) {
    DAT_ffffa7d8 = rx8_max_float(DAT_ffffa7d8 - 0.16,500.0);
  }
  uVar3 = rx8_add_u16_saturate(0x75,1);
  if (uVar3 < snapshot_DAT_ffffa6b4) {
    DAT_ffffa7dc = rx8_max_float(DAT_ffffa7dc - 0.16,arg1);
  }
  else if (0x75 < snapshot_DAT_ffffa6b4) {
    DAT_ffffa7dc = (float)lookup_2d_descriptor_scaled(param_1,&tbl_idle_target_minimum_closed_loop_conditonal_00069398);
  }
  if (snapshot_DAT_ffffa6b4 == 0) {
    uVar2 = lookup_2d_descriptor_scaled(param_1,&tbl_idle_target_minimum_reset_value_000693ac);
    DAT_ffffa7e0 = extraout_fr0;
  }
  else {
    DAT_ffffa7e0 = rx8_max_float(DAT_ffffa7e0 - 0.0,arg1);
    uVar2 = extraout_r0;
  }
  return uVar2;
}


