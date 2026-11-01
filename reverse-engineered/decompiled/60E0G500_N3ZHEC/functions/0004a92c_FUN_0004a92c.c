/* ROM address: 0x0004a92c; body bytes: 88; decompiled */

char FUN_0004a92c(void)

{
  char cVar1;
  
  if ((DAT_ffffc9a2 == '\x01') || (DAT_ffffcdc3 == '\x01')) {
    cVar1 = '\x01';
    DAT_ffffcdb4 = 1;
  }
  else {
    cVar1 = DAT_ffffcdc4;
    if (DAT_ffffcdc4 == '\x01') {
      cVar1 = '\0';
    }
    DAT_ffffcdb4 = 0;
  }
  return cVar1;
}


