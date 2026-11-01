/* ROM address: 0x0003e336; body bytes: 168; decompiled */

char FUN_0003e336(void)

{
  char cVar1;
  
  if ((((DAT_ffffb5aa != '\0') && (DAT_ffffb5ac != '\x01')) || (DAT_ffffc12c <= 0.3984)) ||
     (((DAT_ffffb5b8 < 2500.0 || (cVar1 = FUN_000671a4(0x3a), cVar1 != '\0')) ||
      (DAT_ffffc600 != '\0')))) {
    DAT_ffffc68d = '\0';
  }
  else {
    DAT_ffffc68d = '\x01';
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc68e = 0;
    DAT_ffffc68f = 0;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffc68d;
    if (DAT_ffffc68d == '\x01') {
      if (DAT_ffffbc1c < 3.76) {
        if (DAT_ffffc68c == '\0') {
          DAT_ffffc68e = 1;
          DAT_ffffc68f = 0;
        }
      }
      else {
        DAT_ffffc68f = 1;
        DAT_ffffc68e = 0;
      }
    }
  }
  return cVar1;
}


