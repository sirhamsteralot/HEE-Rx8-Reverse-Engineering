/* ROM address: 0x0002cb08; body bytes: 58; decompiled */

void FUN_0002cb08(byte param_1)

{
  if (param_1 < 4) {
    DAT_ffffbc86 = (param_1 & 1) == 1;
    if ((param_1 & 2) == 2) {
      DAT_ffffbc87 = 1;
    }
    else {
      DAT_ffffbc87 = 0;
    }
  }
  else {
    DAT_ffffbc86 = false;
    DAT_ffffbc87 = 0;
  }
  return;
}


