/* ROM address: 0x000458ac; body bytes: 40; decompiled */

undefined1 * FUN_000458ac(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd201;
  if ((puVar1 == (undefined1 *)0x1) &&
     (puVar1 = (undefined1 *)(uint)DAT_ffffa41c, puVar1 == (undefined1 *)0x1)) {
    puVar1 = &DAT_ffffcbf3;
    DAT_ffffcbf0 = 1000;
    DAT_ffffcbf3 = 0;
  }
  return puVar1;
}


