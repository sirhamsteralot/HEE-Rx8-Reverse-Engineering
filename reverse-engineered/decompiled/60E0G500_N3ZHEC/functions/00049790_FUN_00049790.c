/* ROM address: 0x00049790; body bytes: 106; decompiled */

uint FUN_00049790(void)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = rx8_absolute_difference(DAT_ffffb52c,0.0);
  uVar1 = (uint)DAT_ffffccfb;
  if (uVar1 == 1) {
    if (fVar2 < 80.0) {
      DAT_ffffcd0e = 0;
    }
    else {
      uVar1 = FUN_0003eaa4(&DAT_ffff8766,0);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        uVar1 = FUN_00002460((int)(short)DAT_ffffcd0e,1);
        DAT_ffffcd0e = (ushort)uVar1;
      }
    }
  }
  else {
    DAT_ffffcd0e = 0;
  }
  DAT_ffffcd08 = 4 < DAT_ffffcd0e;
  return uVar1;
}


