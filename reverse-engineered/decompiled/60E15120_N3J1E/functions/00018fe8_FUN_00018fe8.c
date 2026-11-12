/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00018fe8; body bytes: 652; decompiled */

uint FUN_00018fe8(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float snapshot_DAT_ffffa9a8;
  
  fVar8 = DAT_ffffa9c0;
  fVar5 = rx8_absolute_difference(DAT_ffffa9c0,0.0);
  cVar3 = DAT_ffffcc9c;
  cVar2 = DAT_ffffcc9b;
  if ((DAT_ffffa9ce == 0) && (DAT_ffffa9de == '\x01')) {
    DAT_ffffa9cc = '\0';
  }
  else if ((-0.5 <= fVar8) && (fVar8 < -0.3)) {
    DAT_ffffa9cc = '\x01';
  }
  if ((40.0 <= throttle_position_1_percent_ffffa9b4) || ((DAT_ffffa9ce == 0 && (DAT_ffffa9de == '\x01')))) {
    DAT_ffffa9cd = '\0';
  }
  else if (5.0 <= throttle_position_1_percent_ffffa9b4) {
    DAT_ffffa9cd = '\x01';
  }
  DAT_ffffa9de = DAT_ffffa9ce;
  if ((((DAT_ffffa9ce == 1) && (DAT_ffffa9d8 == 0x177)) || (throttle_position_1_percent_ffffa9b4 < 0.0)) ||
     (((5.0 <= throttle_position_1_percent_ffffa9b4 || (DAT_ffffcc9b == '\x01')) || (DAT_ffffcc9c == '\x01')))) {
    DAT_ffffa9ce = 0;
  }
  else if ((DAT_ffffa9cc == '\x01') && (DAT_ffffa9cd == '\x01')) {
    DAT_ffffa9ce = 1;
  }
  fVar8 = DAT_ffffa9a0;
  snapshot_DAT_ffffa9a8 = DAT_ffffa9a8;
  if (DAT_ffffa9ce == 1) {
    DAT_ffffa9d8 = rx8_add_u16_saturate((int)DAT_ffffa9d8,1);
  }
  else {
    DAT_ffffa9d8 = 0;
  }
  if ((cVar2 == '\x01') || (cVar3 == '\x01')) {
    ref_updateMemoryAtAddress_float_VAL_ADDR(&DAT_ffff8068);
    ref_updateMemoryAtAddress_float_VAL_ADDR(0x412db22d,&DAT_ffff8070);
    uVar4 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8078,0);
  }
  else {
    uVar4 = (uint)DAT_ffffa9ce;
    if (uVar4 == 1) {
      fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8068);
      fVar7 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8070);
      if ((DAT_ffffa9de == 0) && (0x176 < DAT_ffffa9da)) {
        fVar8 = rx8_min_float(10.856,fVar6 + 0.01);
        ref_updateMemoryAtAddress_float_VAL_ADDR(fVar8,&DAT_ffff8068);
        fVar8 = rx8_min_float(10.856,fVar7 + 0.01);
        uVar4 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar8,&DAT_ffff8070);
      }
      else {
        bVar1 = fVar8 <= fVar6;
        if (bVar1) {
          fVar6 = rx8_max_float(fVar8,fVar6 - 0.005);
          fVar6 = rx8_max_float(9.626,fVar6);
          ref_updateMemoryAtAddress_float_VAL_ADDR(fVar6,&DAT_ffff8068);
        }
        uVar4 = (uint)bVar1;
        if (snapshot_DAT_ffffa9a8 <= fVar7) {
          fVar7 = rx8_max_float(snapshot_DAT_ffffa9a8,fVar7 - 0.005);
          fVar7 = rx8_max_float(9.626,fVar7);
          ref_updateMemoryAtAddress_float_VAL_ADDR(fVar7,&DAT_ffff8070);
          uVar4 = 1;
        }
        if ((((uVar4 == 1) && (fVar6 - fVar8 < 0.032)) && (fVar7 - snapshot_DAT_ffffa9a8 < 0.032)) &&
           ((fVar5 <= 0.3 && (uVar4 = 0x19, 0x18 < DAT_ffffa9dc)))) {
          uVar4 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8078,1);
        }
      }
    }
  }
  if (DAT_ffffa9ce == 0) {
    uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffa9da,1);
    DAT_ffffa9da = (ushort)uVar4;
  }
  else {
    DAT_ffffa9da = 0;
  }
  if (0.3 < fVar5) {
    DAT_ffffa9dc = 0;
  }
  else {
    uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffa9dc,1);
    DAT_ffffa9dc = (ushort)uVar4;
  }
  return uVar4;
}


