/* ROM address: 0x00044648; body bytes: 42; decompiled */

undefined1 * FUN_00044648(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffcab6 == '\0') {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffcab1 = 0;
  }
  else {
    puVar1 = &DAT_0007b3da;
    if (DAT_ffffcab1 < 4) {
      DAT_ffffcab1 = DAT_ffffcab1 + 1;
    }
  }
  return puVar1;
}


