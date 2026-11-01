/* ROM address: 0x0003d934; body bytes: 244; decompiled */

char FUN_0003d934(void)

{
  char cVar1;
  float fVar2;
  
  DAT_ffffc654 = '\x03';
  DAT_ffffc655 = '\x03';
  fVar2 = DAT_ffffaa08;
  FUN_0003dbe6(DAT_ffffaa08);
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc656 = 0;
    DAT_ffffc659 = '\0';
    DAT_ffffc65a = '\0';
    DAT_ffffc65b = 0;
    cVar1 = '\x01';
  }
  else if ((fVar2 < 0.2) || (4.8 < fVar2)) {
    if ((DAT_ffffc657 == '\x01') &&
       ((DAT_ffffc654 == '\0' && (cVar1 = FUN_000671a4(0x11), cVar1 == '\0')))) {
      DAT_ffffc659 = '\x01';
    }
    if (((DAT_ffffc658 == '\x01') && (DAT_ffffc655 == '\0')) &&
       (cVar1 = FUN_000671a4(0x12), cVar1 == '\0')) {
      DAT_ffffc65a = '\x01';
    }
    cVar1 = '\x01';
    if ((DAT_ffffc659 == '\x01') || (cVar1 = DAT_ffffc65a, DAT_ffffc65a == '\x01')) {
      DAT_ffffc656 = 1;
      DAT_ffffc65b = 0;
    }
  }
  else {
    cVar1 = FUN_000671a4(0x11);
    if (cVar1 == '\0') {
      cVar1 = FUN_000671a4(0x12);
      if (cVar1 == '\0') {
        DAT_ffffc65b = 1;
        DAT_ffffc656 = 0;
        DAT_ffffc659 = '\0';
        DAT_ffffc65a = '\0';
      }
    }
  }
  return cVar1;
}


