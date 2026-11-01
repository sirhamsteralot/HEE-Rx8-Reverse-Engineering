/* ROM address: 0x0004c854; body bytes: 256; decompiled */

char FUN_0004c854(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffced9 = 0;
    DAT_ffffced6 = '\0';
    DAT_ffffced7 = '\0';
    DAT_ffffced8 = '\0';
    DAT_ffffced5 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((((1 < DAT_ffffcecf) && (cVar1 = FUN_000671a4(0x54), cVar1 == '\0')) &&
        (cVar1 = FUN_000671a4(0x55), cVar1 == '\0')) && (cVar1 = FUN_000671a4(0x56), cVar1 == '\0'))
    {
      DAT_ffffced9 = 1;
      DAT_ffffced6 = '\0';
      DAT_ffffced7 = '\0';
      DAT_ffffced8 = '\0';
      DAT_ffffced5 = 0;
    }
    if ((9 < DAT_ffffcecc) && (cVar1 = FUN_000671a4(0x55), cVar1 == '\0')) {
      DAT_ffffced6 = '\x01';
    }
    if ((9 < DAT_ffffcecd) && (cVar1 = FUN_000671a4(0x56), cVar1 == '\0')) {
      DAT_ffffced7 = '\x01';
    }
    if ((9 < DAT_ffffcece) && (cVar1 = FUN_000671a4(0x54), cVar1 == '\0')) {
      DAT_ffffced8 = '\x01';
    }
    cVar1 = '\x01';
    if (((DAT_ffffced6 == '\x01') || (cVar1 = '\x01', DAT_ffffced7 == '\x01')) ||
       (cVar1 = DAT_ffffced8, DAT_ffffced8 == '\x01')) {
      DAT_ffffced5 = 1;
      DAT_ffffced9 = 0;
    }
  }
  return cVar1;
}


