/* ROM address: 0x00038274; body bytes: 162; decompiled */

uint FUN_00038274(void)

{
  uint uVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  if ((((DAT_ffffc2c9 == '\x01') && (DAT_ffffc2ca == 0)) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\v';
    FUN_00036a74(0xb);
    DAT_ffffc2ca = 1;
    DAT_ffffc2c9 = '\0';
  }
  uVar1 = (uint)DAT_ffffc2ca;
  if (uVar1 == 1) {
    FUN_00036d68((int)DAT_ffffc2d1);
    uVar1 = (uint)DAT_ffffc2f8;
    if (uVar1 == 1) {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2ca = 0;
      local_14 = 0xf1;
      uStack_13 = 0;
      uStack_12 = 0xb;
      FUN_000688c8(0xb1,&local_14,3);
      uVar1 = FUN_000550ca(0xb1,3);
    }
  }
  return uVar1;
}


