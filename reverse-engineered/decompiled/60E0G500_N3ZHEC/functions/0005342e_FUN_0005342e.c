/* ROM address: 0x0005342e; body bytes: 108; decompiled */

undefined1 * FUN_0005342e(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffd16d = 0;
  }
  else {
    puVar1 = (undefined1 *)(uint)DAT_ffffd12e;
    if (((puVar1 == (undefined1 *)0x1) &&
        (puVar1 = (undefined1 *)(uint)DAT_ffffcfe6, (undefined1 *)0x1f < puVar1)) &&
       ((0.0015 < DAT_ffffd030 ||
        (((DAT_ffffcfe6 < 0x3f &&
          (puVar1 = (undefined1 *)(int)DAT_ffffd034, puVar1 == (undefined1 *)0x0)) &&
         (puVar1 = &DAT_ffffd16c, 0x17 < DAT_ffffd16c)))))) {
      DAT_ffffd16d = 1;
    }
  }
  return puVar1;
}


