/* ROM address: 0x0003d756; body bytes: 208; decompiled */

char FUN_0003d756(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc651 = 0;
    DAT_ffffc652 = 0;
    DAT_ffffc64a = 'u';
    cVar1 = '\x01';
  }
  else {
    if ((((DAT_ffffae54 - DAT_ffffaa10 <= 1000.0) || (DAT_ffffc64b == '\x01')) ||
        (DAT_ffffc656 == '\x01')) || (DAT_ffffd1e9 == '\x01')) {
      DAT_ffffc64a = 'u';
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 == '\x01') && (DAT_ffffc64a == '\0')) {
      cVar1 = FUN_000671a4(0xe);
      if (cVar1 == '\0') {
        DAT_ffffc651 = 1;
        DAT_ffffc652 = 0;
      }
    }
    else if ((20.0 < DAT_ffffaa10 - DAT_ffffae54) &&
            ((DAT_ffffc64b == '\0' && (DAT_ffffc656 == '\0')))) {
      cVar1 = FUN_000671a4(0xe);
      if (cVar1 == '\0') {
        DAT_ffffc652 = 1;
        DAT_ffffc651 = 0;
      }
    }
  }
  return cVar1;
}


