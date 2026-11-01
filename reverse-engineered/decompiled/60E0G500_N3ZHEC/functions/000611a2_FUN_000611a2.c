/* ROM address: 0x000611a2; body bytes: 68; decompiled */

uint FUN_000611a2(void)

{
  uint uVar1;
  
  uVar1 = FUN_0006413c();
  if ((uVar1 & 0xff) == 0) {
    if (DAT_ffff87bc._0_2_ == -1) {
      uVar1 = (int)DAT_ffff87a4._0_1_ + 1;
      DAT_ffff87a4 = FUN_00002420(uVar1);
    }
    else {
      uVar1 = FUN_0006413c();
    }
  }
  return uVar1;
}


