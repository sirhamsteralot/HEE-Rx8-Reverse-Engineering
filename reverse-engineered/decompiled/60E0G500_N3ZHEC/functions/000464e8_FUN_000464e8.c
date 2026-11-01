/* ROM address: 0x000464e8; body bytes: 42; decompiled */

uint FUN_000464e8(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  if ((uVar1 & 0xff) == 1) {
    FUN_0003ebc0(&DAT_ffff875c,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff875e,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


