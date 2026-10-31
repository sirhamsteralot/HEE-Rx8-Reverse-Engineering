/* ROM address: 0x000186d8; body bytes: 172; decompiled */

byte FUN_000186d8(byte param_1,byte param_2)

{
  if (param_1 < 0x10) {
    if ((param_2 == 0) || (param_2 == 0xc)) {
      DAT_ffffa951 = (param_1 & 1) == 1;
      if ((param_1 & 4) == 4) {
        DAT_ffffa953 = 1;
      }
      else {
        DAT_ffffa953 = 0;
      }
    }
    if ((param_2 == 6) || (param_2 == 0x12)) {
      DAT_ffffa952 = (param_1 & 2) == 2;
      param_2 = param_1 & 8;
      if (param_2 == 8) {
        DAT_ffffa954 = 1;
      }
      else {
        DAT_ffffa954 = 0;
      }
    }
  }
  else {
    if ((param_2 == 0) || (param_2 == 0xc)) {
      DAT_ffffa951 = 0;
      DAT_ffffa953 = 0;
    }
    if ((param_2 == 6) || (param_2 == 0x12)) {
      DAT_ffffa952 = 0;
      DAT_ffffa954 = 0;
    }
  }
  return param_2;
}


