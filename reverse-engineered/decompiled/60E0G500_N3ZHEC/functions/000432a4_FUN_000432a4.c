/* ROM address: 0x000432a4; body bytes: 84; decompiled */

undefined * FUN_000432a4(void)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = FUN_000671a4(0x1b);
  puVar2 = (undefined *)(uVar1 & 0xff);
  if (puVar2 == (undefined *)0x0) {
    uVar1 = FUN_000671a4(0x1a);
    puVar2 = (undefined *)(uVar1 & 0xff);
    if (puVar2 == (undefined *)0x0) {
      uVar1 = FUN_000671a4(0x19);
      puVar2 = (undefined *)(uVar1 & 0xff);
      if (((puVar2 == (undefined *)0x0) &&
          (puVar2 = (undefined *)(uint)DAT_ffffb3c8, puVar2 == &UNK_00000001)) &&
         (DAT_ffffd201 == '\0')) {
        DAT_ffffc9e8 = 1;
        return &DAT_ffffc9e8;
      }
    }
  }
  DAT_ffffc9e8 = 0;
  return puVar2;
}


