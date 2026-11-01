/* ROM address: 0x00026664; body bytes: 90; decompiled */

void FUN_00026664(void)

{
  if (DAT_ffffaa10 < 60.0) {
    if (DAT_ffffaa10 < 55.0) {
      DAT_ffffb6b8 = '\0';
    }
  }
  else {
    DAT_ffffb6b8 = '\x01';
  }
  if ((DAT_ffffa428 == '\0') && (DAT_ffffb6b8 == '\x01')) {
    DAT_ffffb67c = 100;
  }
  else if (DAT_ffffb67c != 0) {
    DAT_ffffb67c = DAT_ffffb67c + -1;
  }
  return;
}


