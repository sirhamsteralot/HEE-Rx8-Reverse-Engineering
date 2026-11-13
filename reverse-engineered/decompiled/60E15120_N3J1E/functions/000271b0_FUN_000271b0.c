/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a6a0: Table 2D - 333 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000271b0; body bytes: 286; decompiled */

char FUN_000271b0(void)

{
  ushort snapshot_DAT_ffffb6c4;
  ushort uVar3;
  int iVar2;
  char cVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_DAT_ffffb6c4 = e2ram_learned_table_cell_index_ffffb6c4;
  iVar8 = (int)(short)e2ram_learned_table_cell_index_ffffb6c4;
  uVar3 = sector_parity_bank_ffffb660 & 1;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  iVar2 = FUN_00003fe8();
  uVar7 = iVar8 + iVar2 * -0x11;
  DAT_ffffb8ec = rx8_decode_u16_affine(0x3f800000,0,uVar7);
  DAT_ffffb8f0 = (float)lookup_2d_descriptor_scaled(DAT_ffffb8ec,&tbl_table_2d_333_check_datatype_0006a6a0);
  uVar7 = uVar7 & 0xffff;
  if (uVar7 == 0) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = ref_readValue_8bit_ADDRESS_VAL
                      (&e2ram_learned_table_flag_a_ffff8548 + (uint)(ushort)(snapshot_DAT_ffffb6c4 - 1) * 2 + (uint)uVar3 * 0x88,0);
  }
  if (uVar7 == 0x10) {
    cVar5 = '\x01';
  }
  else {
    cVar5 = ref_readValue_8bit_ADDRESS_VAL
                      (&e2ram_learned_table_flag_a_ffff8548 + (uint)(ushort)(snapshot_DAT_ffffb6c4 + 1) * 2 + (uint)uVar3 * 0x88,0);
  }
  cVar6 = ref_readValue_8bit_ADDRESS_VAL(&e2ram_learned_table_flag_a_ffff8548 + (uint)snapshot_DAT_ffffb6c4 * 2 + (uint)uVar3 * 0x88,0);
  if ((cVar6 != '\x01') ||
     (((DAT_ffffb8f0 <= snapshot_engine_speed_rpm_ffffb548 || (cVar6 = cVar4, cVar4 != '\x01')) &&
      ((snapshot_engine_speed_rpm_ffffb548 < DAT_ffffb8f0 || (cVar6 = cVar5, cVar5 != '\x01')))))) {
    DAT_ffffb6c6 = 0;
  }
  else {
    DAT_ffffb6c6 = 1;
  }
  return cVar6;
}


