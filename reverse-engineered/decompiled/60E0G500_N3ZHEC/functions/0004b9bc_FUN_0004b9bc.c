/* ROM address: 0x0004b9bc; body bytes: 304; decompiled */

uint FUN_0004b9bc(void)

{
  bool bVar1;
  char cVar2;
  uint extraout_r0;
  uint uVar3;
  uint extraout_r0_00;
  uint extraout_r0_01;
  float fVar4;
  float fVar5;
  float fVar6;
  float arg2;
  float arg1;
  
  cVar2 = DAT_ffffd183;
  bVar1 = ((int)DAT_ffffcff1 & 0x80U) != 0;
  arg1 = 0.0;
  uVar3 = 1;
  if ((DAT_ffffd29f != '\x01') && (uVar3 = 1, DAT_ffffc9a2 != '\x01')) {
    arg2 = 100.0;
    if (DAT_ffffd2a0 == '\x01') {
      DAT_ffffce40 = 100.0;
      DAT_ffffce48 = DAT_ffffd183;
      return 1;
    }
    if (((bVar1) && (DAT_ffffce48 == '\0')) && (DAT_ffffd183 == '\x01')) {
      DAT_ffffce40 = 0.0;
      DAT_ffffce48 = DAT_ffffd183;
      return 0;
    }
    if ((bVar1) && (DAT_ffffd183 == '\x01')) {
      DAT_ffffce40 = rx8_min_float(DAT_ffffce40 + 0.0,0.0);
      DAT_ffffce48 = cVar2;
      return extraout_r0;
    }
    uVar3 = (uint)DAT_ffffcfc1;
    if (uVar3 < 0x28) {
      if (uVar3 != 0) {
        DAT_ffffce40 = rx8_min_float(DAT_ffffce40 + 2.0,DAT_ffffcfbc);
        DAT_ffffce48 = cVar2;
        return extraout_r0_00;
      }
      if (DAT_ffffcfd8 != '\0') {
        fVar4 = (float)FUN_000020dc(DAT_ffffce4c,DAT_ffffbe6c,&DAT_0006bf0c);
        fVar5 = (float)FUN_00002068(DAT_ffffae54,&DAT_0006bee4);
        fVar6 = (float)FUN_00002068(DAT_ffffb600,&DAT_0006bef8);
        DAT_ffffce40 = rx8_clamp_float(fVar6 + fVar4 * fVar5,arg1,arg2);
        DAT_ffffce48 = cVar2;
        return extraout_r0_01;
      }
      DAT_ffffce40 = 0.0;
      DAT_ffffce48 = DAT_ffffd183;
      return 0;
    }
  }
  DAT_ffffce40 = 0.0;
  DAT_ffffce48 = cVar2;
  return uVar3;
}


