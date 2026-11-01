/* ROM address: 0x00051e5e; body bytes: 138; decompiled */

uint FUN_00051e5e(void)

{
  ushort uVar1;
  uint uVar2;
  uint extraout_r0;
  float arg0;
  
  uVar1 = DAT_ffffcfe6;
  arg0 = (DAT_ffffae64 + -1.0) * 100.0;
  uVar2 = (uint)DAT_ffffd12e;
  if (uVar2 == 1) {
    uVar2 = 0x1f;
    if ((0x1e < DAT_ffffcfe6) && (uVar2 = 0x88, DAT_ffffcfe6 < 0x89)) {
      arg0 = rx8_first_order_filter(arg0,DAT_ffffd120,0.25,1e-05);
      uVar2 = extraout_r0;
    }
    DAT_ffffd120 = arg0;
    if (uVar1 == 0x3e) {
      DAT_ffffd124 = DAT_ffffd120;
    }
    arg0 = DAT_ffffd120;
    if (uVar1 == 0x88) {
      DAT_ffffd128 = DAT_ffffd120;
    }
  }
  DAT_ffffd120 = arg0;
  return uVar2;
}


