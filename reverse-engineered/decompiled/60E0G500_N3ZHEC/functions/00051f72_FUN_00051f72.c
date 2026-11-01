/* ROM address: 0x00051f72; body bytes: 96; decompiled */

undefined1 * FUN_00051f72(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  DAT_ffffd137 = 0;
  if (DAT_ffffd201 == '\x01') {
    puVar1 = &DAT_ffffd131;
    DAT_ffffd131 = 0;
  }
  else {
    puVar1 = (undefined1 *)(uint)DAT_ffffd12e;
    if (((puVar1 == (undefined1 *)0x1) &&
        (puVar1 = (undefined1 *)(int)DAT_ffffcfe6, (undefined1 *)0x3e < puVar1)) &&
       (DAT_ffffd01c <= DAT_ffffd118)) {
      uVar2 = FUN_000671a4(0x2d);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x0) {
        DAT_ffffd131 = 1;
        DAT_ffffd137 = 1;
      }
    }
  }
  return puVar1;
}


