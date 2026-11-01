/* ROM address: 0x00018bb8; body bytes: 52; decompiled */

uint FUN_00018bb8(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    FUN_0003ebc0(&DAT_ffff8080,0);
    FUN_0003ebc0(&DAT_ffff8082,0);
    FUN_0003ebc0(&DAT_ffff8084,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff8086,0);
  }
  return uVar1;
}


