/* ROM address: 0x000547d2; body bytes: 52; decompiled */

undefined * FUN_000547d2(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)DAT_ffffa42c;
  if ((puVar1 == &UNK_00000001) || (DAT_ffffd1ea == '\0')) {
    puVar1 = &DAT_0007da50;
    DAT_ffffd1e8 = '\b';
  }
  else if (DAT_ffffd1e8 != '\0') {
    DAT_ffffd1e8 = DAT_ffffd1e8 + -1;
  }
  return puVar1;
}


