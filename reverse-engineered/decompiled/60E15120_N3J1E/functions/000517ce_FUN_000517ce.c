/* ROM address: 0x000517ce; body bytes: 96; decompiled */

undefined1 * FUN_000517ce(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  DAT_ffffd0fb = 0;
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = &DAT_ffffd0f5;
    DAT_ffffd0f5 = 0;
  }
  else {
    puVar1 = (undefined1 *)(uint)DAT_ffffd0f2;
    if (((puVar1 == (undefined1 *)0x1) &&
        (puVar1 = (undefined1 *)(int)DAT_ffffcfaa, (undefined1 *)0x3e < puVar1)) &&
       (DAT_ffffcfe0 <= DAT_ffffd0dc)) {
      uVar2 = ref_getFaultStatus__(0x2d);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x0) {
        DAT_ffffd0f5 = 1;
        DAT_ffffd0fb = 1;
      }
    }
  }
  return puVar1;
}


