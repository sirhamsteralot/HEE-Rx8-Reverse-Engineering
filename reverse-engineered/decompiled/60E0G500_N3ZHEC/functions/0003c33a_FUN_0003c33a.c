/* ROM address: 0x0003c33a; body bytes: 300; decompiled */

char FUN_0003c33a(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc606 = 0;
    DAT_ffffc607 = 0;
    DAT_ffffc608 = '\0';
    DAT_ffffc609 = '\0';
    DAT_ffffc5ff = 'N';
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffd1e9 == '\x01') || (DAT_ffffc600 == '\x01')) {
      DAT_ffffc5ff = 'N';
    }
    else {
      bVar3 = false;
      if (DAT_ffffb5b8 < 2000.0) {
        if (65.0 < DAT_ffffaa88) {
          if ((70.0 < DAT_ffffaa10) && (DAT_ffffc656 == '\0')) {
            bVar3 = true;
          }
        }
        else {
          DAT_ffffc608 = '\x01';
        }
      }
      bVar2 = false;
      if (((DAT_ffffa428 == '\x01') && (50.0 < DAT_ffffadc0)) && (DAT_ffffcce1 == '\0')) {
        if (DAT_ffffaa88 < 9.0) {
          bVar2 = true;
        }
        else {
          DAT_ffffc609 = '\x01';
        }
      }
      if ((!bVar3) && (!bVar2)) {
        DAT_ffffc5ff = 'N';
      }
    }
    if (DAT_ffffc5ff == '\0') {
      cVar1 = FUN_000671a4(9);
      if (cVar1 == '\0') {
        DAT_ffffc606 = 1;
        DAT_ffffc607 = 0;
        DAT_ffffc608 = '\0';
        DAT_ffffc609 = '\0';
      }
    }
    else {
      cVar1 = DAT_ffffc608;
      if ((DAT_ffffc608 == '\x01') && (cVar1 = DAT_ffffc609, DAT_ffffc609 == '\x01')) {
        cVar1 = FUN_000671a4(9);
        if (cVar1 == '\0') {
          DAT_ffffc607 = 1;
          DAT_ffffc606 = 0;
        }
      }
    }
  }
  return cVar1;
}


