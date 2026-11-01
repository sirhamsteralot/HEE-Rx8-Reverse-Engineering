/* ROM address: 0x00046bac; body bytes: 414; decompiled */

uint FUN_00046bac(void)

{
  char cVar2;
  uint uVar1;
  float fVar3;
  float arg0;
  float arg1;
  
  arg0 = DAT_ffffb47c;
  arg1 = DAT_ffffada8;
  fVar3 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  DAT_ffffcc60 = arg1 - fVar3;
  DAT_ffffcc64 = arg0 - fVar3;
  fVar3 = rx8_absolute_difference(arg0,arg1);
  DAT_ffffcc6c = (float)FUN_00002068(DAT_ffffcc64,&PTR_LAB_0006bdcc);
  if (DAT_ffffcc68 == '\x01') {
    if (fVar3 < DAT_ffffcc6c) {
      if (0xf9 < DAT_ffffcc7a) {
        DAT_ffffcc5c = 1;
      }
      DAT_ffffcc74 = 0;
      DAT_ffffcc76 = 0;
      DAT_ffffcc78 = 0;
      DAT_ffffcc7a = FUN_00002460((int)(short)DAT_ffffcc7a,1);
    }
    else if (DAT_ffffb5b8 < 500.0) {
      if (0x9c3 < DAT_ffffcc78) {
        FUN_0003ebc0(&DAT_ffff8768,1);
      }
      DAT_ffffcc74 = 0;
      DAT_ffffcc76 = 0;
      DAT_ffffcc78 = FUN_00002460((int)(short)DAT_ffffcc78,1);
      DAT_ffffcc7a = 0;
    }
    else {
      if (arg1 < arg0) {
        DAT_ffffcc72 = FUN_000020c4(DAT_ffffcc60,&PTR_LAB_0006bdc0);
        if (DAT_ffffcc72 <= DAT_ffffcc76) {
          FUN_0003ebc0(&DAT_ffff8768,1);
        }
        DAT_ffffcc74 = 0;
        DAT_ffffcc76 = FUN_00002460((int)(short)DAT_ffffcc76,1);
      }
      else {
        DAT_ffffcc70 = FUN_000020c4(&PTR_LAB_0006bdb4);
        if (DAT_ffffcc70 <= DAT_ffffcc74) {
          FUN_0003ebc0(&DAT_ffff8768,1);
        }
        DAT_ffffcc74 = FUN_00002460((int)(short)DAT_ffffcc74,1);
        DAT_ffffcc76 = 0;
      }
      DAT_ffffcc78 = 0;
      DAT_ffffcc7a = 0;
    }
  }
  else {
    DAT_ffffcc74 = 0;
    DAT_ffffcc76 = 0;
    DAT_ffffcc78 = 0;
    DAT_ffffcc7a = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8768,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x46,1);
    return uVar1;
  }
  if (DAT_ffffcc5c == 1) {
    uVar1 = FUN_000604dc(0x46,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc5c;
}


