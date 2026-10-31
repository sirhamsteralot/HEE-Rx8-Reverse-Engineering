/* ROM address: 0x00050c4c; body bytes: 64; decompiled */

undefined2 * FUN_00050c4c(void)

{
  undefined2 *puVar1;
  
  puVar1 = &DAT_ffffcfa8;
  if (((DAT_ffffcfa8 < DAT_ffffcfaa) && (DAT_ffffcff8 == '\0')) &&
     ((puVar1 = (undefined2 *)0x1, DAT_ffffd0a8 == '\x01' ||
      (puVar1 = (undefined2 *)(uint)DAT_ffffcf78, puVar1 == (undefined2 *)0x1)))) {
    DAT_ffffd0ab = 1;
  }
  else {
    DAT_ffffd0ab = 0;
  }
  return puVar1;
}


