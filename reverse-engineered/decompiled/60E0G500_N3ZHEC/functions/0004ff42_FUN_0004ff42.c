/* ROM address: 0x0004ff42; body bytes: 124; decompiled */

undefined4 * FUN_0004ff42(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 *extraout_r0;
  undefined4 *extraout_r0_00;
  float arg1;
  
  uVar1 = DAT_ffffcfe6;
  puVar2 = (undefined4 *)(uint)DAT_ffffcffb;
  if (puVar2 == (undefined4 *)0x1) {
    if (DAT_ffffd034 == '\0') {
      puVar2 = (undefined4 *)&DAT_ffffcfe2;
      if (DAT_ffffcfe2 < DAT_ffffcfe6) {
        arg1 = DAT_ffffd01c;
        DAT_ffffd028 = rx8_max_float(DAT_ffffd028,DAT_ffffd01c);
        puVar2 = extraout_r0;
        if (uVar1 <= DAT_ffffcfe4) {
          DAT_ffffd02c = rx8_min_float(DAT_ffffd02c,arg1);
          puVar2 = extraout_r0_00;
        }
      }
    }
    else {
      puVar2 = (undefined4 *)&DAT_ffffcfe4;
      DAT_ffffd028 = 0.0;
      if (DAT_ffffcfe4 < DAT_ffffcfe6) {
        puVar2 = &DAT_0004ffd4;
        DAT_ffffd02c = 0.038;
      }
    }
  }
  return puVar2;
}


