/* ROM address: 0x0003c164; body bytes: 410; decompiled */

char FUN_0003c164(void)

{
  char cVar1;
  float fVar2;
  
  DAT_ffffc603 = DAT_ffffaa80 < 0.64;
  DAT_ffffc604 = 4.9 < DAT_ffffaa80;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5fc = '\x04';
    DAT_ffffc5fd = '\x04';
    DAT_ffffc5fe = '\x1f';
    DAT_ffffc600 = 0;
    DAT_ffffc601 = '\0';
    DAT_ffffc602 = '\0';
    DAT_ffffc605 = 0;
    cVar1 = '\x01';
  }
  else {
    if (8.0 <= DAT_ffffb600) {
      if (DAT_ffffc5fe != '\0') {
        DAT_ffffc5fe = DAT_ffffc5fe + -1;
      }
    }
    else {
      DAT_ffffc5fe = '\x1f';
    }
    if ((bool)DAT_ffffc604 || (bool)DAT_ffffc603) {
      if (DAT_ffffc5fe == '\0') {
        fVar2 = DAT_ffffb5b8;
        if (500.0 <= DAT_ffffb5b8) {
          if ((bool)DAT_ffffc603) {
            if (DAT_ffffc5fc == '\0') {
              cVar1 = FUN_000671a4(10);
              if (cVar1 == '\0') {
                DAT_ffffc601 = '\x01';
              }
            }
            else {
              DAT_ffffc5fc = DAT_ffffc5fc + -1;
            }
          }
        }
        else {
          DAT_ffffc5fc = '\x04';
        }
        if (fVar2 <= 6500.0) {
          if (DAT_ffffc604 == '\x01') {
            if (DAT_ffffc5fd == '\0') {
              cVar1 = FUN_000671a4(0xb);
              if (cVar1 == '\0') {
                DAT_ffffc602 = '\x01';
              }
            }
            else {
              DAT_ffffc5fd = DAT_ffffc5fd + -1;
            }
          }
        }
        else {
          DAT_ffffc5fd = '\x04';
        }
      }
      else {
        DAT_ffffc5fc = '\x04';
        DAT_ffffc5fd = '\x04';
      }
      cVar1 = '\x01';
      if ((DAT_ffffc601 == '\x01') || (cVar1 = DAT_ffffc602, DAT_ffffc602 == '\x01')) {
        DAT_ffffc600 = 1;
        DAT_ffffc605 = 0;
      }
    }
    else {
      cVar1 = FUN_000671a4(10);
      if ((cVar1 == '\0') && (cVar1 = FUN_000671a4(0xb), cVar1 == '\0')) {
        DAT_ffffc605 = 1;
        DAT_ffffc5fc = '\x04';
        DAT_ffffc5fd = '\x04';
        DAT_ffffc600 = 0;
        DAT_ffffc601 = '\0';
        DAT_ffffc602 = '\0';
      }
    }
  }
  return cVar1;
}


