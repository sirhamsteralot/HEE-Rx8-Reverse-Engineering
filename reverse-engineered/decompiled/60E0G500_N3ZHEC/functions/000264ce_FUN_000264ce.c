/* ROM address: 0x000264ce; body bytes: 226; decompiled */

void FUN_000264ce(void)

{
  if (DAT_ffffb600 < 10.0) {
    if (DAT_ffffb600 < 9.0) {
      DAT_ffffb6b6 = '\0';
    }
  }
  else {
    DAT_ffffb6b6 = '\x01';
  }
  if (((((DAT_ffffb6c4 <= 16.973) || (10.938 <= DAT_ffffb6c8)) || (DAT_ffffa428 == '\0')) ||
      ((DAT_ffffa428 == '\x01' && (DAT_ffffb6ac < 0x3f)))) ||
     ((DAT_ffffb6b6 == '\0' || ((DAT_ffffb6b6 == '\x01' && (DAT_ffffb6ae < 0x3f)))))) {
    DAT_ffffb67a = 0x138;
  }
  else if (DAT_ffffb67a != 0) {
    DAT_ffffb67a = DAT_ffffb67a + -1;
  }
  if (DAT_ffffa428 == '\0') {
    DAT_ffffb6ac = 0;
  }
  else {
    DAT_ffffb6ac = FUN_00002460((int)(short)DAT_ffffb6ac,1);
  }
  if (DAT_ffffb6b6 == '\0') {
    DAT_ffffb6ae = 0;
  }
  else {
    DAT_ffffb6ae = FUN_00002460((int)(short)DAT_ffffb6ae,1);
  }
  return;
}


