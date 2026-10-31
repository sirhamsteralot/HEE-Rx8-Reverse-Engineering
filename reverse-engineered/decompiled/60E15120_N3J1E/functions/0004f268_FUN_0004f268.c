/* ROM address: 0x0004f268; body bytes: 34; decompiled */

undefined2 * FUN_0004f268(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(uint)DAT_ffffcfbe;
  if ((puVar1 == (undefined2 *)0x1) && (DAT_ffffcfd7 == '\0')) {
    puVar1 = &DAT_ffffcfaa;
    DAT_ffffcfaa = 0;
  }
  DAT_ffffcfd7 = DAT_ffffcfbe;
  return puVar1;
}


