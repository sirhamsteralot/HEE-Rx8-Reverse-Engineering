/* ROM address: 0x0002d6fc; body bytes: 58; decompiled */

void FUN_0002d6fc(byte param_1)

{
  if (param_1 < 4) {
    DAT_ffffbcf2 = (param_1 & 1) == 1;
    if ((param_1 & 2) == 2) {
      DAT_ffffbcf3 = 1;
    }
    else {
      DAT_ffffbcf3 = 0;
    }
  }
  else {
    DAT_ffffbcf2 = false;
    DAT_ffffbcf3 = 0;
  }
  return;
}


