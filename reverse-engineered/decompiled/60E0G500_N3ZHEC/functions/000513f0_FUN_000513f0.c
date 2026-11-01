/* ROM address: 0x000513f0; body bytes: 64; decompiled */

undefined2 * FUN_000513f0(void)

{
  undefined2 *puVar1;
  
  puVar1 = &DAT_ffffcfe4;
  if (((DAT_ffffcfe4 < DAT_ffffcfe6) && (DAT_ffffd034 == '\0')) &&
     ((puVar1 = (undefined2 *)0x1, DAT_ffffd0e4 == '\x01' ||
      (puVar1 = (undefined2 *)(uint)DAT_ffffcfb4, puVar1 == (undefined2 *)0x1)))) {
    DAT_ffffd0e7 = 1;
  }
  else {
    DAT_ffffd0e7 = 0;
  }
  return puVar1;
}


