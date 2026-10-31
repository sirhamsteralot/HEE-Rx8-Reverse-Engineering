/* ROM address: 0x00050d98; body bytes: 388; decompiled */

char FUN_00050d98(void)

{
  char cVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  sVar2 = DAT_ffffd0a2;
  fVar11 = 0.0;
  fVar10 = 100.0;
  fVar7 = (float)rx8_decode_u16_affine(0x42c80000,0,(int)DAT_ffffd0a2);
  fVar8 = (float)rx8_decode_u16_affine(fVar10,fVar11,(int)DAT_ffffd0a0);
  fVar9 = (float)rx8_decode_u16_affine(fVar10,fVar11,(int)DAT_ffffd0a6);
  fVar7 = (fVar7 - fVar8) / 1000.0;
  cVar4 = rx8_is_outside_tolerance_band(fVar7,fVar11,0x3727c5ac);
  fVar8 = (fVar8 - fVar9) / 1000.0;
  cVar5 = rx8_is_outside_tolerance_band(fVar8,fVar11,0x3727c5ac);
  cVar3 = DAT_ffffd1c5;
  cVar1 = DAT_ffffcf78;
  if ((DAT_ffffd0d0 == sVar2) || (DAT_ffffd0ab != '\x01')) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((DAT_ffffd1c5 == '\x01') || ((DAT_ffffd0d4 == '\0' && (DAT_ffffcf78 == '\x01')))) {
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar11,&DAT_ffff86a8);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar11,&DAT_ffff86b0);
  }
  else if (cVar6 == '\x01') {
    if (cVar4 == '\0') {
      fVar7 = 0.35999998;
    }
    else {
      fVar7 = 0.35 / fVar7;
    }
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar7,&DAT_ffff86a8);
    if (cVar5 == '\0') {
      fVar8 = 0.35999998;
    }
    else {
      fVar8 = 0.35 / fVar8;
    }
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar8,&DAT_ffff86b0);
  }
  if (cVar3 == '\x01') {
    cVar6 = '\x01';
    DAT_ffffd094 = fVar11;
  }
  else if (cVar6 == '\x01') {
    fVar7 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar11,&DAT_ffff86a8);
    fVar8 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar11,&DAT_ffff86b0);
    cVar6 = rx8_is_outside_tolerance_band(fVar8,fVar11,0x3727c5ac);
    DAT_ffffd094 = fVar11;
    if (cVar6 != '\0') {
      DAT_ffffd094 = (fVar7 / fVar8) * fVar10;
    }
  }
  DAT_ffffd0d0 = sVar2;
  DAT_ffffd0d4 = cVar1;
  return cVar6;
}


