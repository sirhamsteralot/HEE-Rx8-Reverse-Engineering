/* ROM address: 0x000561aa; body bytes: 86; decompiled */

undefined * FUN_000561aa(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)(uint)DAT_ffffd205;
  if ((puVar2 != (undefined *)0x0) && (DAT_ffffd200 != '\0')) {
    DAT_ffffd200 = DAT_ffffd200 + -1;
  }
  puVar1 = &DAT_ffffd205;
  if (DAT_ffffd200 == '\0') {
    if (puVar2 == &UNK_00000004) {
      puVar2 = (undefined *)FUN_00066916();
    }
    else if (puVar2 == &UNK_00000014) {
      puVar2 = (undefined *)FUN_000560e6();
    }
    DAT_ffffd201 = 0;
    DAT_ffffd205 = 0;
    puVar1 = puVar2;
  }
  return puVar1;
}


