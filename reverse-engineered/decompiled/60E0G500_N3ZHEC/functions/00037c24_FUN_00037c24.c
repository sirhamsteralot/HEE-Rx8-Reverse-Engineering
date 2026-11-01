/* ROM address: 0x00037c24; body bytes: 162; decompiled */

uint FUN_00037c24(void)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  if ((((DAT_ffffc2bf == '\x01') && (DAT_ffffc2c0 == 0)) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\x04';
    FUN_00036a74(4);
    DAT_ffffc2c0 = 1;
    DAT_ffffc2bf = '\0';
  }
  uVar1 = (uint)DAT_ffffc2c0;
  if (uVar1 == 1) {
    FUN_00036d68((int)DAT_ffffc2d1);
    uVar1 = (uint)DAT_ffffc2f8;
    if (uVar1 == 1) {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2c0 = 0;
      local_18 = 0xf1;
      uStack_17 = 1;
      uStack_16 = 0x9c;
      FUN_000688c8(0xb1,&local_18,3);
      uVar1 = FUN_000550ca(0xb1,3);
    }
  }
  return uVar1;
}


