/* ROM address: 0x0003c93a; body bytes: 394; decompiled */

char FUN_0003c93a(void)

{
  char cVar1;
  
  if (DAT_ffffc068 == -1) {
    DAT_ffffc61d = DAT_ffffc069 < 0x80;
    if (DAT_ffffc069 < 0x81) {
      DAT_ffffc61e = '\0';
    }
    else {
      DAT_ffffc61e = '\x01';
    }
  }
  else {
    DAT_ffffc61d = false;
    DAT_ffffc61e = '\0';
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc618 = '\'';
    DAT_ffffc619 = '\'';
    DAT_ffffc61f = '\0';
    DAT_ffffc620 = '\0';
    DAT_ffffc621 = 0;
    DAT_ffffc622 = 0;
    cVar1 = '\x01';
  }
  else {
    if (((DAT_ffffb600 < 11.0) || (16.0 < DAT_ffffb600)) || (DAT_ffffd1e9 == '\x01')) {
      DAT_ffffc618 = '\'';
      DAT_ffffc619 = '\'';
    }
    else if (DAT_ffffc068 == -1) {
      if ((bool)DAT_ffffc61d == true) {
        if (DAT_ffffc618 == '\0') {
          cVar1 = FUN_000671a4(0x34);
          if (cVar1 == '\0') {
            DAT_ffffc61f = '\x01';
          }
        }
        else {
          DAT_ffffc618 = DAT_ffffc618 + -1;
        }
      }
      if (DAT_ffffc61e == '\x01') {
        if (DAT_ffffc619 == '\0') {
          cVar1 = FUN_000671a4(0x36);
          if (cVar1 == '\0') {
            DAT_ffffc620 = '\x01';
          }
        }
        else {
          DAT_ffffc619 = DAT_ffffc619 + -1;
        }
      }
    }
    else {
      DAT_ffffc618 = '\'';
      DAT_ffffc619 = '\'';
      if (((0x7f < DAT_ffffc069) && (DAT_ffffc069 < 0x81)) &&
         ((cVar1 = FUN_000671a4(0x34), cVar1 == '\0' && (cVar1 = FUN_000671a4(0x36), cVar1 == '\0'))
         )) {
        DAT_ffffc622 = 1;
        DAT_ffffc61f = '\0';
        DAT_ffffc620 = '\0';
        DAT_ffffc621 = 0;
      }
    }
    cVar1 = '\x01';
    if ((DAT_ffffc61f == '\x01') || (cVar1 = DAT_ffffc620, DAT_ffffc620 == '\x01')) {
      DAT_ffffc621 = 1;
      DAT_ffffc622 = 0;
    }
  }
  return cVar1;
}


