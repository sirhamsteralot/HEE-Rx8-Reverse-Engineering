/* ROM address: 0x0003d618; body bytes: 280; decompiled */

char FUN_0003d618(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = DAT_ffffae4c;
  FUN_0003d8ea(DAT_ffffae4c);
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc648 = '\x03';
    DAT_ffffc649 = '\x03';
    DAT_ffffc64b = 0;
    DAT_ffffc64e = '\0';
    DAT_ffffc64f = '\0';
    DAT_ffffc650 = 0;
    cVar1 = '\x01';
  }
  else if ((fVar2 < 0.16) || (4.8 < fVar2)) {
    if (DAT_ffffc64c == '\x01') {
      if (DAT_ffffc648 == '\0') {
        cVar1 = FUN_000671a4(0xf);
        if (cVar1 == '\0') {
          DAT_ffffc64e = '\x01';
        }
      }
      else {
        DAT_ffffc648 = DAT_ffffc648 + -1;
      }
    }
    if (DAT_ffffc64d == '\x01') {
      if (DAT_ffffc649 == '\0') {
        cVar1 = FUN_000671a4(0x10);
        if (cVar1 == '\0') {
          DAT_ffffc64f = '\x01';
        }
      }
      else {
        DAT_ffffc649 = DAT_ffffc649 + -1;
      }
    }
    cVar1 = '\x01';
    if ((DAT_ffffc64e == '\x01') || (cVar1 = DAT_ffffc64f, DAT_ffffc64f == '\x01')) {
      DAT_ffffc64b = 1;
      DAT_ffffc650 = 0;
    }
  }
  else {
    cVar1 = FUN_000671a4(0xf);
    if (cVar1 == '\0') {
      cVar1 = FUN_000671a4(0x10);
      if (cVar1 == '\0') {
        DAT_ffffc650 = 1;
        DAT_ffffc648 = '\x03';
        DAT_ffffc649 = '\x03';
        DAT_ffffc64b = 0;
        DAT_ffffc64e = '\0';
        DAT_ffffc64f = '\0';
      }
    }
  }
  return cVar1;
}


