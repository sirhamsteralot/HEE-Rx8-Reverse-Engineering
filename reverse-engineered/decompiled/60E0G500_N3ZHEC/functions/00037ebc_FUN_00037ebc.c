/* ROM address: 0x00037ebc; body bytes: 164; decompiled */

uint FUN_00037ebc(void)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  if ((((DAT_ffffc2c1 == '\x01') && (DAT_ffffc2c2 == 0)) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\a';
    FUN_00036a74(7);
    DAT_ffffc2c2 = 1;
    DAT_ffffc2c1 = '\0';
  }
  uVar1 = (uint)DAT_ffffc2c2;
  if (uVar1 == 1) {
    FUN_00036d68((int)DAT_ffffc2d1);
    uVar1 = (uint)DAT_ffffc2f8;
    if (uVar1 == 1) {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2c2 = 0;
      local_18 = 0xf1;
      uStack_17 = 0xf0;
      uStack_16 = 1;
      FUN_000688c8(0xb1,&local_18,3);
      uVar1 = FUN_000550ca(0xb1,3);
    }
  }
  return uVar1;
}


