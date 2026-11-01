/* ROM address: 0x00047c5a; body bytes: 66; decompiled */

void FUN_00047c5a(byte param_1)

{
  if (param_1 < 4) {
    DAT_ffffccb2 = (param_1 & 1) == 1;
    if ((param_1 & 2) == 2) {
      DAT_ffffccb3 = 1;
    }
    else {
      DAT_ffffccb3 = 0;
    }
  }
  else {
    DAT_ffffccb2 = false;
    DAT_ffffccb3 = 0;
  }
  return;
}


