/* ROM address: 0x00068e2c; body bytes: 112; decompiled */

uint FUN_00068e2c(void)

{
  uint uVar1;
  
  uVar1 = (int)DAT_ffffde04 & 0xf;
  DAT_ffffde2c = (undefined1)uVar1;
  if (uVar1 == 0) {
    FUN_000693fc(4);
    DAT_ffffde20 = 0;
    DAT_ffffde2d = DAT_ffffde05;
    DAT_ffffde2e = DAT_ffffde06;
    DAT_ffffde1d = 9;
    uVar1 = FUN_0006936a(2,DAT_ffffde06);
    return uVar1;
  }
  if (uVar1 == 1) {
    FUN_000693fc(4);
    DAT_ffffde1d = 7;
    uVar1 = FUN_0006936a(4,0x4b);
    return uVar1;
  }
  return uVar1;
}


