/* ROM address: 0x00051744; body bytes: 88; decompiled */

undefined4 * FUN_00051744(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = &DAT_0005178c;
    DAT_ffffd0dc = 0.038;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd0f2;
    if (((puVar1 == (undefined4 *)0x1) &&
        (puVar1 = (undefined4 *)(int)DAT_ffffcfaa, (undefined4 *)0x1e < puVar1)) &&
       (puVar1 = (undefined4 *)0x0, DAT_ffffcff8 != '\0')) {
      DAT_ffffd0dc = rx8_min_float(DAT_ffffd0dc,DAT_ffffcfe0 + -0.0003);
      puVar1 = extraout_r0;
    }
  }
  return puVar1;
}


