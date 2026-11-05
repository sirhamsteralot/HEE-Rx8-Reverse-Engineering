/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a844: Table 2D - 335 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a850: Table 2D - 336 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a85c: Table 2D - 337 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a868: Table 2D - 338 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a874: Table 2D - 339 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8bc: Table 3D - 111 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002d638; body bytes: 372; decompiled */

uint FUN_0002d638(void)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  uint extraout_r0;
  undefined *puVar7;
  float extraout_fr0;
  undefined4 uVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 snapshot_DAT_ffffcf1c;
  
  fVar9 = DAT_ffffbfa4 - DAT_ffffbfa0;
  DAT_ffffbd14 = DAT_ffffbfa0 - DAT_ffffbfa4;
  snapshot_DAT_ffffcf1c = DAT_ffffcf1c;
  uVar1 = lookup_3d_descriptor_scaled(DAT_ffffbfa0,DAT_ffffcf1c,&tbl_table_3d_111_0006a8bc);
  uVar8 = 0;
  if (DAT_ffffbced == '\0') {
    DAT_ffffbd00 = 0.0;
    DAT_ffffbd18 = extraout_fr0;
    return uVar1;
  }
  if (DAT_ffffbd3e != 1) {
    DAT_ffffbd18 = extraout_fr0;
    return (uint)DAT_ffffbd3e;
  }
  uVar10 = 0x3727c5ac;
  DAT_ffffbd18 = extraout_fr0;
  cVar2 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffcf1c,0x40000000,0x3727c5ac);
  cVar3 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffcf1c,0x40400000,uVar10);
  cVar4 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffcf1c,0x40800000,uVar10);
  cVar5 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffcf1c,0x40a00000,uVar10);
  cVar6 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffcf1c,0x40c00000,uVar10);
  if (cVar2 == '\0') {
    puVar7 = &tbl_table_2d_335_check_datatype_0006a844;
  }
  else if (cVar3 == '\0') {
    puVar7 = &tbl_table_2d_336_check_datatype_0006a850;
  }
  else if (cVar4 == '\0') {
    puVar7 = &tbl_table_2d_337_check_datatype_0006a85c;
  }
  else {
    if (cVar5 != '\0') {
      if (cVar6 == '\0') {
        puVar7 = &tbl_table_2d_339_check_datatype_0006a874;
      }
      else {
        puVar7 = &tbl_table_2d_335_check_datatype_0006a844;
      }
      DAT_ffffbd04 = (float)lookup_2d_descriptor_scaled(DAT_ffffbd14,puVar7);
      goto LAB_0002d77c;
    }
    puVar7 = &tbl_table_2d_338_check_datatype_0006a868;
  }
  DAT_ffffbd04 = (float)lookup_2d_descriptor_scaled(puVar7);
LAB_0002d77c:
  if ((100.0 <= fVar9) || (fVar9 < -100.0)) {
    fVar9 = DAT_ffffbd00;
    if (DAT_ffffa9b4 <= cruise_set_speed_ffffbcf8) {
      if (DAT_ffffbbcb != 1) {
        DAT_ffffbd00 = (float)uVar8;
        return (uint)DAT_ffffbbcb;
      }
      if ((0xfd < DAT_ffffbbc8) && (0xfd < DAT_ffffbbc9)) {
        DAT_ffffbd00 = (float)uVar8;
        return (uint)DAT_ffffbbc9;
      }
    }
  }
  else {
    fVar9 = DAT_ffffbd04 * DAT_ffffbd18 * 0.01;
  }
  DAT_ffffbd00 = rx8_clamp_float(fVar9,-100.0,100.0);
  return extraout_r0;
}


