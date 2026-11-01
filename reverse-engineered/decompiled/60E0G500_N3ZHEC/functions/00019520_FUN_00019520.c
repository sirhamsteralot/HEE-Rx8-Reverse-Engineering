/* ROM address: 0x00019520; body bytes: 172; decompiled */

byte FUN_00019520(byte param_1,byte param_2)

{
  if (param_1 < 0x10) {
    if ((param_2 == 0) || (param_2 == 0xc)) {
      DAT_ffffa9d5 = (param_1 & 1) == 1;
      if ((param_1 & 4) == 4) {
        DAT_ffffa9d7 = 1;
      }
      else {
        DAT_ffffa9d7 = 0;
      }
    }
    if ((param_2 == 6) || (param_2 == 0x12)) {
      DAT_ffffa9d6 = (param_1 & 2) == 2;
      param_2 = param_1 & 8;
      if (param_2 == 8) {
        DAT_ffffa9d8 = 1;
      }
      else {
        DAT_ffffa9d8 = 0;
      }
    }
  }
  else {
    if ((param_2 == 0) || (param_2 == 0xc)) {
      DAT_ffffa9d5 = 0;
      DAT_ffffa9d7 = 0;
    }
    if ((param_2 == 6) || (param_2 == 0x12)) {
      DAT_ffffa9d6 = 0;
      DAT_ffffa9d8 = 0;
    }
  }
  return param_2;
}


