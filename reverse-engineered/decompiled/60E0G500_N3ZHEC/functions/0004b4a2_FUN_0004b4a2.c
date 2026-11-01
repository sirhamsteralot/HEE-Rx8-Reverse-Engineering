/* ROM address: 0x0004b4a2; body bytes: 54; decompiled */

char FUN_0004b4a2(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcdfc = 0;
    cVar1 = '\x01';
  }
  else {
    cVar1 = '\x01';
    if ((DAT_ffffce00 == '\x01') || (cVar1 = DAT_ffffce01, DAT_ffffce01 == '\x01')) {
      DAT_ffffcdfc = 1;
    }
    else {
      DAT_ffffcdfc = 0;
    }
  }
  return cVar1;
}


