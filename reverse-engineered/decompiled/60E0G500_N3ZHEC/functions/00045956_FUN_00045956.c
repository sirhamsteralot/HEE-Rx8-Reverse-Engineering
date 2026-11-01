/* ROM address: 0x00045956; body bytes: 42; decompiled */

undefined4 * FUN_00045956(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcbf3 = 0;
    puVar1 = (undefined4 *)0x1;
  }
  else {
    puVar1 = &DAT_ffffb5b8;
    if (5000.0 <= DAT_ffffb5b8) {
      DAT_ffffcbf3 = 1;
    }
  }
  return puVar1;
}


