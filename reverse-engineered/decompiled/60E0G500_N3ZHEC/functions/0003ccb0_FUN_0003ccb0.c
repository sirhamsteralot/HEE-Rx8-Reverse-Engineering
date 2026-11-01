/* ROM address: 0x0003ccb0; body bytes: 394; decompiled */

char FUN_0003ccb0(void)

{
  char cVar1;
  
  if (DAT_ffffc068 == -1) {
    DAT_ffffc629 = DAT_ffffc06a < 0x80;
    if (DAT_ffffc06a < 0x81) {
      DAT_ffffc62a = '\0';
    }
    else {
      DAT_ffffc62a = '\x01';
    }
  }
  else {
    DAT_ffffc629 = false;
    DAT_ffffc62a = '\0';
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc61a = '\'';
    DAT_ffffc61b = '\'';
    DAT_ffffc62b = '\0';
    DAT_ffffc62c = '\0';
    DAT_ffffc62d = 0;
    DAT_ffffc62e = 0;
    cVar1 = '\x01';
  }
  else {
    if (((DAT_ffffb600 < 11.0) || (16.0 < DAT_ffffb600)) || (DAT_ffffd1e9 == '\x01')) {
      DAT_ffffc61a = '\'';
      DAT_ffffc61b = '\'';
    }
    else if (DAT_ffffc068 == -1) {
      if ((bool)DAT_ffffc629 == true) {
        if (DAT_ffffc61a == '\0') {
          cVar1 = FUN_000671a4(0x35);
          if (cVar1 == '\0') {
            DAT_ffffc62b = '\x01';
          }
        }
        else {
          DAT_ffffc61a = DAT_ffffc61a + -1;
        }
      }
      if (DAT_ffffc62a == '\x01') {
        if (DAT_ffffc61b == '\0') {
          cVar1 = FUN_000671a4(0x37);
          if (cVar1 == '\0') {
            DAT_ffffc62c = '\x01';
          }
        }
        else {
          DAT_ffffc61b = DAT_ffffc61b + -1;
        }
      }
    }
    else {
      DAT_ffffc61a = '\'';
      DAT_ffffc61b = '\'';
      if ((0x7f < DAT_ffffc06a) && (DAT_ffffc06a < 0x81)) {
        DAT_ffffc62e = 1;
        DAT_ffffc62b = '\0';
        DAT_ffffc62c = '\0';
        DAT_ffffc62d = 0;
      }
    }
    if (((DAT_ffffc62b == '\x01') || (cVar1 = DAT_ffffc62c, DAT_ffffc62c == '\x01')) &&
       ((cVar1 = FUN_000671a4(0x35), cVar1 == '\0' && (cVar1 = FUN_000671a4(0x37), cVar1 == '\0'))))
    {
      DAT_ffffc62d = 1;
      DAT_ffffc62e = 0;
    }
  }
  return cVar1;
}


