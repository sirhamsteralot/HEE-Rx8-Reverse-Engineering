/* ROM address: 0x0001df8a; body bytes: 188; decompiled */

void FUN_0001df8a(void)

{
  if ((DAT_ffffb08e == 0) || (DAT_ffffae99 == '\0')) {
    DAT_ffffae92 = 0;
    DAT_ffffae94 = 0;
    DAT_ffffb070 = 0.0;
  }
  else if (((DAT_ffffb0dd == '\0') || (DAT_ffffb0d2 == 0)) || (DAT_ffffb08e < DAT_ffffae94)) {
    DAT_ffffae94 = DAT_ffffb08e;
  }
  else if (DAT_ffffb08e < DAT_ffffae92) {
    DAT_ffffae92 = DAT_ffffb08e;
  }
  else if (DAT_ffffae94 == 0) {
    if (DAT_ffffae92 != 0) {
      DAT_ffffae92 = DAT_ffffae92 - 1;
      if (DAT_ffffae92 == 0) {
        DAT_ffffae94 = DAT_ffffb08e;
        DAT_ffffb070 = 0.0 - DAT_ffffb06c;
      }
      else {
        DAT_ffffb070 = DAT_ffffb06c;
      }
    }
  }
  else {
    DAT_ffffae94 = DAT_ffffae94 - 1;
    DAT_ffffb070 = 0.0 - DAT_ffffb06c;
    if (DAT_ffffae94 == 0) {
      DAT_ffffae92 = DAT_ffffb08e;
      DAT_ffffb070 = DAT_ffffb06c;
    }
  }
  DAT_ffffb0dd = DAT_ffffae99;
  DAT_ffffb0d2 = DAT_ffffb08e;
  return;
}


