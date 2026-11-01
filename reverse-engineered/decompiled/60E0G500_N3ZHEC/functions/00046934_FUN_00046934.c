/* ROM address: 0x00046934; body bytes: 42; decompiled */

uint FUN_00046934(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  if ((uVar1 & 0xff) == 1) {
    FUN_0003ebc0(&DAT_ffff8764,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff8766,1);
    return uVar1;
  }
  return uVar1 & 0xff;
}


