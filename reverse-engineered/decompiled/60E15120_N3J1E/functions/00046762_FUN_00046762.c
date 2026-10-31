/* ROM address: 0x00046762; body bytes: 132; decompiled */

uint FUN_00046762(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float arg1;
  
  arg1 = engine_load_ffffc0b4;
  fVar4 = rx8_min_float(DAT_ffffcc3c,engine_load_ffffc0b4);
  fVar5 = rx8_max_float(DAT_ffffcc40,arg1);
  bVar1 = fVar5 - fVar4 < 2.0;
  DAT_ffffcc3c = arg1;
  DAT_ffffcc40 = arg1;
  if (bVar1) {
    DAT_ffffcc3c = fVar4;
    DAT_ffffcc40 = fVar5;
  }
  uVar3 = (uint)bVar1;
  uVar2 = (uint)DAT_ffffcc48;
  if ((DAT_ffffcc48 == 1) && (uVar2 = uVar3, uVar3 == 1)) {
    DAT_ffffcc49 = 1;
    uVar2 = rx8_add_u16_saturate((int)DAT_ffffcc4e,1);
    DAT_ffffcc4e = (short)uVar2;
  }
  else {
    DAT_ffffcc49 = 0;
    DAT_ffffcc4e = 0;
  }
  return uVar2;
}


