/* ROM address: 0x0002db3c; body bytes: 34; decompiled */

uint FUN_0002db3c(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff868c,0);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8690,1);
    return uVar1;
  }
  return uVar1 & 0xff;
}


