/* ROM address: 0x000196ec; body bytes: 284; decompiled */

void FUN_000196ec(void)

{
  if (DAT_ffffbc1c < 3.0) {
    if (DAT_ffffbc1c < 1.0) {
      DAT_ffffa9fc = '\0';
    }
  }
  else {
    DAT_ffffa9fc = '\x01';
  }
  if (DAT_ffffaa10 < 105.0) {
    if (DAT_ffffaa10 < 101.0) {
      DAT_ffffa9fd = '\0';
    }
  }
  else {
    DAT_ffffa9fd = '\x01';
  }
  if (DAT_ffffb5b8 < 5000.0) {
    if (DAT_ffffb5b8 < 5000.0) {
      DAT_ffffa9fe = '\0';
    }
  }
  else {
    DAT_ffffa9fe = '\x01';
  }
  if (DAT_ffffb5b8 < 1000.0) {
    if (DAT_ffffb5b8 < 1000.0) {
      DAT_ffffa9ff = '\0';
    }
  }
  else {
    DAT_ffffa9ff = '\x01';
  }
  if ((((DAT_ffffb5aa == '\0') || (DAT_ffffa9fc == '\x01')) || (DAT_ffffa9fd == '\0')) ||
     (((DAT_ffffa9ff == '\0' || (DAT_ffffc600 == '\x01')) ||
      ((DAT_ffffc656 == '\x01' || (DAT_ffffc68e == '\x01')))))) {
    DAT_ffffa9ee = 0;
    DAT_ffffa9f2 = 0;
  }
  else if (DAT_ffffa9fe == '\x01') {
    if (0x9b < DAT_ffffa9f2) {
      DAT_ffffa9ee = 1;
    }
    DAT_ffffa9f2 = FUN_00002460((int)(short)DAT_ffffa9f2,1);
  }
  else {
    DAT_ffffa9f2 = 0;
  }
  return;
}


