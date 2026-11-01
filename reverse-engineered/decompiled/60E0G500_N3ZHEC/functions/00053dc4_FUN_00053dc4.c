/* ROM address: 0x00053dc4; body bytes: 76; decompiled */

undefined4 FUN_00053dc4(void)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = (float)FUN_000024c0(0x3f800000,0,(int)DAT_ffffc532);
  if (DAT_ffffd048 != 0) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fe4,0);
    return uVar1;
  }
  if (360.0 < fVar2) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fe4,1);
    return uVar1;
  }
  return 0;
}


