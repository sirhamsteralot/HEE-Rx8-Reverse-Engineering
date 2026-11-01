/* ROM address: 0x0004fa0c; body bytes: 34; decompiled */

undefined2 * FUN_0004fa0c(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(uint)DAT_ffffcffa;
  if ((puVar1 == (undefined2 *)0x1) && (DAT_ffffd013 == '\0')) {
    puVar1 = &DAT_ffffcfe6;
    DAT_ffffcfe6 = 0;
  }
  DAT_ffffd013 = DAT_ffffcffa;
  return puVar1;
}


