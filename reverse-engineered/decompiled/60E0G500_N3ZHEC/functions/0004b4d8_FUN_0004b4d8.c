/* ROM address: 0x0004b4d8; body bytes: 50; decompiled */

undefined1 * FUN_0004b4d8(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd201;
  if (puVar1 == (undefined1 *)0x1) {
    DAT_ffffcdfd = 0;
  }
  else if ((DAT_ffffce00 == '\0') && (puVar1 = &DAT_ffffce01, DAT_ffffce01 == '\0')) {
    DAT_ffffcdfd = 1;
  }
  else {
    DAT_ffffcdfd = 0;
  }
  return puVar1;
}


