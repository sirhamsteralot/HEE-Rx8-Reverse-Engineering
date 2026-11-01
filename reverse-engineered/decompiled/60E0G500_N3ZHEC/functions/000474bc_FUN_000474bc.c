/* ROM address: 0x000474bc; body bytes: 80; decompiled */

undefined4 FUN_000474bc(void)

{
  short sVar2;
  undefined4 uVar1;
  
  if (DAT_ffffa3f0 == '\0') {
    uVar1 = FUN_0003ebc0(&DAT_ffff8772,0);
    DAT_ffffcca4 = 1;
  }
  else {
    sVar2 = FUN_0003eae4(&DAT_ffff8774,0);
    if (sVar2 == 0) {
      sVar2 = -0x788e;
    }
    else {
      FUN_0003ebc0(&DAT_ffff8772,0);
      sVar2 = -0x7890;
    }
    uVar1 = FUN_0003ebc0((int)sVar2,1);
  }
  return uVar1;
}


