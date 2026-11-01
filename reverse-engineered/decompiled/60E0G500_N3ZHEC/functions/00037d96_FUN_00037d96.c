/* ROM address: 0x00037d96; body bytes: 110; decompiled */

uint FUN_00037d96(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  
  uVar1 = (uint)DAT_ffffc2ad;
  iVar2 = 0;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffc2bc, uVar1 == 1)) {
    DAT_ffffc2ad = 0;
    if (DAT_ffffc2ab != '\0') {
      iVar2 = 0x22;
    }
    DAT_ffffc2bc = 0;
    if (iVar2 == 0) {
      local_10 = 0xf1;
      uStack_f = 1;
      uStack_e = 0x9d;
      FUN_000688c8(0xb1,&local_10,3);
    }
    else {
      FUN_00055112(0xb1);
    }
    uVar1 = FUN_000550ca(0xb1,3);
  }
  return uVar1;
}


