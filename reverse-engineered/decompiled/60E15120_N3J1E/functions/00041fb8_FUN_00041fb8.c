/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b710: Table 2D - 377 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00041fb8; body bytes: 474; decompiled */

undefined2 * FUN_00041fb8(void)

{
  char cVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  undefined2 uVar7;
  float snapshot_DAT_ffffc928;
  byte bStack_28;
  
  cVar1 = DAT_ffffc94e;
  cVar5 = DAT_ffffc930;
  cVar3 = DAT_ffffc92f;
  uVar6 = (uint)DAT_ffffc946;
  bStack_28 = DAT_ffffc92e;
  if (DAT_ffffd1c5 == '\x01') {
    puVar2 = &DAT_ffffc946;
    DAT_ffffc946 = 0;
    DAT_ffffc92f = '\0';
    DAT_ffffc930 = '\0';
    DAT_ffffc92e = 0;
    DAT_ffffc967 = '\0';
    DAT_ffffc95a = 0;
    DAT_ffffc95c = 0;
    DAT_ffffc962 = 0;
  }
  else {
    snapshot_DAT_ffffc928 = DAT_ffffc928;
    DAT_ffffc938 = (float)lookup_2d_descriptor_scaled(DAT_ffffc940,&tbl_table_2d_377_check_datatype_0006b710);
    if ((DAT_ffffc967 == '\0') && (cVar3 == '\x01')) {
      DAT_ffffc95a = 0x14;
    }
    else if (DAT_ffffc95a != 0) {
      DAT_ffffc95a = DAT_ffffc95a + -1;
    }
    if ((((cVar1 == '\x01') && (DAT_ffffb0d0 < 0.23)) && (snapshot_DAT_ffffc928 < DAT_ffffc938)) &&
       ((DAT_ffffc95a == 0 || (cVar3 == '\0')))) {
      uVar6 = rx8_add_u16_saturate(uVar6,1);
    }
    uVar7 = (undefined2)uVar6;
    if (cVar5 == '\x01') {
      cVar3 = '\0';
    }
    else if (3 < (uVar6 & 0xffff)) {
      cVar3 = '\x01';
    }
    if ((0x1e < (uVar6 & 0xffff)) && (cVar3 == '\x01')) {
      cVar5 = '\x01';
      bStack_28 = 0;
    }
    if (DAT_ffffc96b == '\x01') {
      DAT_ffffc962 = rx8_add_u16_saturate((int)(short)DAT_ffffc962,1);
    }
    if ((((cVar1 != '\x01') || (DAT_ffffc96b != '\x01')) || (DAT_ffffc962 < 0x4e)) || (snapshot_DAT_ffffc928 < 0.73)
       ) {
      DAT_ffffc95c = 0;
    }
    else {
      if (3 < DAT_ffffc95c) {
        cVar5 = '\0';
        cVar3 = '\0';
        bStack_28 = 1;
        uVar7 = 0;
      }
      DAT_ffffc95c = rx8_add_u16_saturate((int)(short)DAT_ffffc95c,1);
    }
    DAT_ffffc967 = DAT_ffffc92f;
    DAT_ffffc92e = bStack_28;
    DAT_ffffc92f = cVar3;
    DAT_ffffc930 = cVar5;
    DAT_ffffc946 = uVar7;
    if (cVar5 == '\x01') {
      puVar2 = (undefined2 *)FUN_0005fd38(0x20,1);
    }
    else {
      puVar2 = (undefined2 *)(uint)bStack_28;
      if (puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
        cVar3 = ref_driveCycleDetectMAYBE_(0x1f);
        if (cVar3 == '\0') {
          uVar4 = 4;
        }
        else {
          uVar4 = 2;
        }
        puVar2 = (undefined2 *)FUN_0005fd38(0x20,uVar4);
      }
    }
  }
  return puVar2;
}


