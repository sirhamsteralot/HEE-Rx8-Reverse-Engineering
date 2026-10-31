/* ROM address: 0x00044e90; body bytes: 88; decompiled */

byte FUN_00044e90(void)

{
  if (DAT_ffffa415 < 6) {
    DAT_ffffcbc2 = 0;
  }
  else if ((DAT_ffffa415 < 6) || (0xb < DAT_ffffa415)) {
    if ((DAT_ffffa415 < 0xc) || (0x11 < DAT_ffffa415)) {
      if ((0x11 < DAT_ffffa415) && (DAT_ffffa415 < 0x18)) {
        DAT_ffffcbc2 = 3;
      }
    }
    else {
      DAT_ffffcbc2 = 2;
    }
  }
  else {
    DAT_ffffcbc2 = 1;
  }
  return DAT_ffffa415;
}


