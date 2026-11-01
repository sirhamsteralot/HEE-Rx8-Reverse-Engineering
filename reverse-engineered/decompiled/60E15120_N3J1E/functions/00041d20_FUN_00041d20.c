/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b704: Table 2D - 376 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00041d20; body bytes: 476; decompiled */

undefined2 * FUN_00041d20(void)

{
  char cVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 uVar6;
  char cVar7;
  float snapshot_DAT_ffffc928;
  byte bStack_28;
  
  cVar7 = DAT_ffffc94f;
  cVar1 = DAT_ffffc94d;
  cVar3 = DAT_ffffc92d;
  uVar5 = (uint)DAT_ffffc944;
  bStack_28 = DAT_ffffc92c;
  if (DAT_ffffd1c5 == '\x01') {
    puVar2 = &DAT_ffffc944;
    DAT_ffffc944 = 0;
    DAT_ffffc94f = '\0';
    DAT_ffffc92d = '\0';
    DAT_ffffc92c = 0;
    DAT_ffffc969 = '\0';
    DAT_ffffc95e = 0;
    DAT_ffffc958 = 0;
    DAT_ffffc960 = 0;
  }
  else {
    snapshot_DAT_ffffc928 = DAT_ffffc928;
    DAT_ffffc934 = (float)lookup_2d_descriptor_scaled(DAT_ffffc940,&tbl_table_2d_376_check_datatype_0006b704);
    if ((cVar7 == '\x01') && (DAT_ffffc969 == '\0')) {
      DAT_ffffc95e = 0x14;
    }
    else if (DAT_ffffc95e != 0) {
      DAT_ffffc95e = DAT_ffffc95e + -1;
    }
    if ((((cVar1 == '\x01') && (-0.23 <= inferred_ltft_bank1_ffffb0d0_ffffb0d0)) && (DAT_ffffc934 <= snapshot_DAT_ffffc928)) &&
       ((DAT_ffffc95e == 0 || (DAT_ffffc94f == '\0')))) {
      uVar5 = rx8_add_u16_saturate(uVar5,1);
    }
    uVar6 = (undefined2)uVar5;
    if (cVar3 == '\x01') {
      cVar7 = '\0';
    }
    else if (3 < (uVar5 & 0xffff)) {
      cVar7 = '\x01';
    }
    if ((0x1e < (uVar5 & 0xffff)) && (cVar7 == '\x01')) {
      cVar3 = '\x01';
      bStack_28 = 0;
    }
    if (DAT_ffffc96a == '\x01') {
      DAT_ffffc960 = rx8_add_u16_saturate((int)(short)DAT_ffffc960,1);
    }
    if ((((cVar1 != '\x01') || (DAT_ffffc96a != '\x01')) || (DAT_ffffc960 < 0x4e)) ||
       (1.25 <= snapshot_DAT_ffffc928)) {
      DAT_ffffc958 = 0;
    }
    else {
      if (3 < DAT_ffffc958) {
        cVar7 = '\0';
        cVar3 = '\0';
        bStack_28 = 1;
        uVar6 = 0;
      }
      DAT_ffffc958 = rx8_add_u16_saturate((int)(short)DAT_ffffc958,1);
    }
    DAT_ffffc969 = DAT_ffffc94f;
    DAT_ffffc92c = bStack_28;
    DAT_ffffc92d = cVar3;
    DAT_ffffc944 = uVar6;
    DAT_ffffc94f = cVar7;
    if (cVar3 == '\x01') {
      puVar2 = (undefined2 *)FUN_0005fd38(0x1f,1);
    }
    else {
      puVar2 = (undefined2 *)(uint)bStack_28;
      if (puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
        cVar3 = ref_driveCycleDetectMAYBE_(0x1e);
        if (cVar3 == '\0') {
          uVar4 = 4;
        }
        else {
          uVar4 = 2;
        }
        puVar2 = (undefined2 *)FUN_0005fd38(0x1f,uVar4);
      }
    }
  }
  return puVar2;
}


