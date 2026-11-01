/* ROM address: 0x0004e4f2; body bytes: 60; decompiled */

char FUN_0004e4f2(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_ffffcf82;
  if (DAT_ffffc020 == '\x01') {
    DAT_ffffcf81 = 1;
  }
  if (DAT_ffffc01e == '\x01') {
    DAT_ffffcf82 = '\x01';
  }
  cVar2 = DAT_ffffc01e;
  if ((cVar1 == '\0') && (cVar2 = DAT_ffffcf82, DAT_ffffcf82 == '\x01')) {
    DAT_ffffcfac = 1;
  }
  return cVar2;
}


