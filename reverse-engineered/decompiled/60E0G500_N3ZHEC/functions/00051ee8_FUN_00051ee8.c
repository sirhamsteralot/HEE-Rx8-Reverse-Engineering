/* ROM address: 0x00051ee8; body bytes: 88; decompiled */

undefined4 * FUN_00051ee8(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  
  if (DAT_ffffd201 == '\x01') {
    puVar1 = &DAT_00051f30;
    DAT_ffffd118 = 0.038;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd12e;
    if (((puVar1 == (undefined4 *)0x1) &&
        (puVar1 = (undefined4 *)(int)DAT_ffffcfe6, (undefined4 *)0x1e < puVar1)) &&
       (puVar1 = (undefined4 *)0x0, DAT_ffffd034 != '\0')) {
      DAT_ffffd118 = rx8_min_float(DAT_ffffd118,DAT_ffffd01c + -0.0003);
      puVar1 = extraout_r0;
    }
  }
  return puVar1;
}


