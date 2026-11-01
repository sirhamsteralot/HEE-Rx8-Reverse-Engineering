/* ROM address: 0x000373b8; body bytes: 78; decompiled */

undefined * FUN_000373b8(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)DAT_ffffc2a9;
  if (puVar1 == &UNK_00000001) {
    if (DAT_ffffc2a7 != 0xff) {
      DAT_ffffc2a7 = DAT_ffffc2a7 + 1;
    }
    if (0x18 < DAT_ffffc2a7) {
      if (DAT_ffffc2e9 == '\0') {
        DAT_ffffc2a9 = 0;
      }
      else {
        puVar1 = &DAT_ffffc2b0;
        DAT_ffffc2e9 = DAT_ffffc2e9 + -1;
        DAT_ffffc2b0 = 1;
      }
      DAT_ffffc2a7 = 0;
    }
  }
  return puVar1;
}


