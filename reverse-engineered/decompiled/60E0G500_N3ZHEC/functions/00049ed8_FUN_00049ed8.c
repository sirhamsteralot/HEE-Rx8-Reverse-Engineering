/* ROM address: 0x00049ed8; body bytes: 116; decompiled */

uint FUN_00049ed8(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcd54 = 0;
    DAT_ffffcd55 = '\0';
    uVar1 = 1;
  }
  else {
    if ((DAT_ffffcd61 == '\x01') && (DAT_ffffcd84 == '\x01')) {
      DAT_ffffcd54 = 1;
    }
    if ((DAT_ffffcd62 == '\x01') || (DAT_ffffcd85 == '\x01')) {
      DAT_ffffcd55 = '\x01';
    }
    if (DAT_ffffcd55 == '\x01') {
      uVar1 = FUN_000604dc(0x1e,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcd54;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x1e,2);
      return uVar1;
    }
  }
  return uVar1;
}


