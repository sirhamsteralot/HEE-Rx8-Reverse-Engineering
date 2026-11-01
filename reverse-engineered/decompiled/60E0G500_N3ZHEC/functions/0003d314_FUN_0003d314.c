/* ROM address: 0x0003d314; body bytes: 280; decompiled */

char FUN_0003d314(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = DAT_ffffad88;
  FUN_0003d4ae(DAT_ffffad88);
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc640 = '\r';
    DAT_ffffc641 = '\r';
    DAT_ffffc644 = '\0';
    DAT_ffffc645 = '\0';
    DAT_ffffc646 = 0;
    DAT_ffffc647 = 0;
    cVar1 = '\x01';
  }
  else if ((fVar2 < 0.2) || (4.8 < fVar2)) {
    if (DAT_ffffc642 == '\x01') {
      if (DAT_ffffc640 == '\0') {
        cVar1 = FUN_000671a4(0xc);
        if (cVar1 == '\0') {
          DAT_ffffc644 = '\x01';
        }
      }
      else {
        DAT_ffffc640 = DAT_ffffc640 + -1;
      }
    }
    if (DAT_ffffc643 == '\x01') {
      if (DAT_ffffc641 == '\0') {
        cVar1 = FUN_000671a4(0xd);
        if (cVar1 == '\0') {
          DAT_ffffc645 = '\x01';
        }
      }
      else {
        DAT_ffffc641 = DAT_ffffc641 + -1;
      }
    }
    cVar1 = '\x01';
    if ((DAT_ffffc644 == '\x01') || (cVar1 = DAT_ffffc645, DAT_ffffc645 == '\x01')) {
      DAT_ffffc647 = 1;
      DAT_ffffc646 = 0;
    }
  }
  else {
    cVar1 = FUN_000671a4(0xc);
    if (cVar1 == '\0') {
      cVar1 = FUN_000671a4(0xd);
      if (cVar1 == '\0') {
        DAT_ffffc646 = 1;
        DAT_ffffc640 = '\r';
        DAT_ffffc641 = '\r';
        DAT_ffffc647 = 0;
        DAT_ffffc644 = '\0';
        DAT_ffffc645 = '\0';
      }
    }
  }
  return cVar1;
}


