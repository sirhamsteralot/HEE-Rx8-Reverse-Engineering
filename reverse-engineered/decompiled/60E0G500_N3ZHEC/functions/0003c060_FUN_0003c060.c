/* ROM address: 0x0003c060; body bytes: 140; decompiled */

char FUN_0003c060(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5f1 = 0;
    DAT_ffffc5f2 = 0;
    cVar1 = '\x01';
  }
  else {
    if (((DAT_ffffc5f8 == '\x01') && (DAT_ffffc5f9 == '\x01')) &&
       (cVar1 = FUN_000671a4(0x2f), cVar1 == '\0')) {
      DAT_ffffc5f2 = 1;
      DAT_ffffc5f1 = 0;
    }
    if (((DAT_ffffc5f5 == '\x01') || (DAT_ffffc5f6 == '\x01')) ||
       (cVar1 = DAT_ffffc5f4, DAT_ffffc5f4 == '\x01')) {
      cVar1 = FUN_000671a4(0x2f);
      if (cVar1 == '\0') {
        DAT_ffffc5f1 = 1;
        DAT_ffffc5f2 = 0;
      }
    }
  }
  return cVar1;
}


