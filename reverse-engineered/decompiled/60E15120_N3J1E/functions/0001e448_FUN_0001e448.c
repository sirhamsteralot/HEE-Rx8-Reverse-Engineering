/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069c88: Table 2D - 317 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001e448; body bytes: 814; decompiled */

uint FUN_0001e448(void)

{
  byte snapshot_DAT_ffffb0da;
  short sVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  float arg1;
  char local_3c;
  
  snapshot_DAT_ffffb0da = DAT_ffffb0da;
  cVar3 = DAT_ffffaa62;
  uVar11 = 0;
  uVar5 = (uint)DAT_ffffb0dc;
  uVar6 = (uint)DAT_ffffb0d8;
  fVar9 = lambda_target_ffffadfc;
  arg1 = DAT_ffffadf0;
  fVar8 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80c4 + (uint)maf_range_index_ffffb0fe * 8);
  fVar8 = rx8_absolute_difference(DAT_ffffb0d0,fVar8);
  fVar9 = rx8_absolute_difference(DAT_ffffaa70,fVar9);
  fVar10 = rx8_absolute_difference(DAT_ffffadec,arg1);
  DAT_ffffb0fc = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&tbl_table_2d_317_00069c88);
  uVar4 = (uint)snapshot_DAT_ffffb0da;
  if ((((uVar4 != 1) || (DAT_ffffb0f0 < DAT_ffffb0fc)) || (0.02 <= fVar8)) || (0.02 <= fVar10)) {
    uVar5 = 0;
    uVar6 = 0x8000;
    DAT_ffffb0df = '\0';
  }
  else {
    DAT_ffffb0df = '\x01';
  }
  if ((DAT_ffffb0df != '\x01') ||
     ((((cVar3 != '\x01' || (7 < (uVar5 & 0xffff))) || (0.05 <= fVar9)) &&
      ((cVar3 != '\0' || (7 < (uVar5 & 0xffff))))))) {
    sVar2 = 0;
    uVar6 = 0x8000;
    DAT_ffffb0e0 = '\0';
  }
  else {
    DAT_ffffb0e0 = '\x01';
    sVar2 = rx8_add_u16_saturate(uVar5,1);
  }
  if (DAT_ffffb0e0 == '\x01') {
    if (1.01 <= arg1) {
      uVar6 = rx8_add_u16_saturate(uVar6,1);
    }
    if ((arg1 < 0.99) && ((uVar6 & 0xffff) != 0)) {
      uVar6 = uVar6 + 0xffff;
    }
  }
  uVar7 = (undefined2)uVar6;
  if ((DAT_ffffb0df == '\x01') &&
     (((cVar3 == '\0' && (sVar2 == 8)) || ((cVar3 == '\x01' && (sVar2 == 8)))))) {
    DAT_ffffb0e1 = '\x01';
  }
  else {
    DAT_ffffb0e1 = '\0';
  }
  if (DAT_ffffb0e1 == '\x01') {
    fVar9 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS
                             (uVar11,&DAT_ffff80c4 + (uint)maf_range_index_ffffb0fe * 8);
    local_3c = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80e4 + (uint)maf_range_index_ffffb0fe * 2,0);
    if (cVar3 == '\0') {
      if (0x8007 < (uVar6 & 0xffff)) {
        uVar6 = 0x8000;
        local_3c = '\x01';
        sVar2 = 0;
        fVar9 = fVar9 + 0.0009999999;
      }
      uVar7 = (undefined2)uVar6;
      if ((uVar6 & 0xffff) < 0x7ff9) {
        fVar9 = fVar9 - 0.0009999999;
        uVar7 = 0x8000;
        sVar2 = 0;
        local_3c = '\x01';
      }
    }
    else {
      if (0x8007 < (uVar6 & 0xffff)) {
        uVar6 = 0x8000;
        local_3c = '\x01';
        sVar2 = 0;
        fVar9 = fVar9 + 0.0009999999;
      }
      uVar7 = (undefined2)uVar6;
      if ((uVar6 & 0xffff) < 0x7ff9) {
        fVar9 = fVar9 - 0.0009999999;
        uVar7 = 0x8000;
        sVar2 = 0;
        local_3c = '\x01';
      }
    }
    fVar9 = rx8_clamp_float(fVar9,-0.23,0.23);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar9,&DAT_ffff80c4 + (uint)maf_range_index_ffffb0fe * 8);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80e4 + (uint)maf_range_index_ffffb0fe * 2,(int)local_3c);
  }
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80e4,0);
  if (cVar3 == '\0') {
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar11,&DAT_ffff80c4);
  }
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80e6,0);
  if (cVar3 == '\0') {
    fVar9 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar11,&DAT_ffff80c4);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar9 * 1.0,&DAT_ffff80cc);
  }
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80e8,0);
  if (cVar3 == '\0') {
    fVar9 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar11,&DAT_ffff80cc);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar9 * 1.0,&DAT_ffff80d4);
  }
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80ea,0);
  if (cVar3 == '\0') {
    fVar9 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar11,&DAT_ffff80d4);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar9 * 1.0,&DAT_ffff80dc);
  }
  if (uVar4 == 1) {
    uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffb0f0,1);
    DAT_ffffb0f0 = (ushort)uVar4;
  }
  else {
    DAT_ffffb0f0 = 0;
  }
  DAT_ffffb0dc = sVar2;
  DAT_ffffb0d8 = uVar7;
  return uVar4;
}


