/* ROM address: 0x0003e57c; body bytes: 240; decompiled */

char FUN_0003e57c(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = DAT_ffffc695;
  cVar1 = DAT_ffffc004;
  if (DAT_ffffc680 == '\0') {
    DAT_ffffc695 = '\0';
  }
  else if (30.08 < DAT_ffffbc1c) {
    DAT_ffffc695 = '\x01';
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc696 = '\0';
    DAT_ffffc691 = '\n';
    DAT_ffffc698 = 0;
    DAT_ffffc699 = 0;
    cVar3 = '\x01';
  }
  else {
    if (DAT_ffffc697 != DAT_ffffc004) {
      DAT_ffffc696 = '\x01';
    }
    if (DAT_ffffc696 == '\x01') {
      DAT_ffffc691 = '\n';
      cVar3 = DAT_ffffb5a4;
      if (DAT_ffffb5a4 == '\x01') {
        cVar3 = FUN_000671a4(0x4b);
        if (cVar3 == '\0') {
          DAT_ffffc699 = 1;
          DAT_ffffc698 = 0;
        }
      }
    }
    else {
      cVar3 = DAT_ffffc696;
      if ((DAT_ffffc695 == '\0') && (cVar3 = cVar2, cVar2 == '\x01')) {
        if (DAT_ffffc691 != '\0') {
          DAT_ffffc691 = DAT_ffffc691 + -1;
        }
        cVar3 = DAT_ffffb5a4;
        if (DAT_ffffb5a4 == '\x01') {
          cVar3 = FUN_000671a4(0x4b);
          if ((cVar3 == '\0') && (DAT_ffffc691 == '\0')) {
            DAT_ffffc698 = 1;
            DAT_ffffc699 = 0;
          }
        }
      }
    }
  }
  DAT_ffffc697 = cVar1;
  return cVar3;
}


