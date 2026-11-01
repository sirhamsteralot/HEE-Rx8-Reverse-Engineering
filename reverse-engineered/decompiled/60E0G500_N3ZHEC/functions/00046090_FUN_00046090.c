/* ROM address: 0x00046090; body bytes: 34; decompiled */

uint FUN_00046090(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8754,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


