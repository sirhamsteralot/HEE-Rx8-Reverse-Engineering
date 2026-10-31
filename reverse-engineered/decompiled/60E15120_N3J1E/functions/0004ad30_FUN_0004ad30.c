/* ROM address: 0x0004ad30; body bytes: 50; decompiled */

undefined1 * FUN_0004ad30(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd1c5;
  if (puVar1 == (undefined1 *)0x1) {
    DAT_ffffcdbd = 0;
  }
  else if ((DAT_ffffcdc0 == '\0') && (puVar1 = &DAT_ffffcdc1, DAT_ffffcdc1 == '\0')) {
    DAT_ffffcdbd = 1;
  }
  else {
    DAT_ffffcdbd = 0;
  }
  return puVar1;
}


