/* ROM address: 0x000445f6; body bytes: 82; decompiled */

char FUN_000445f6(void)

{
  bool bVar1;
  char cVar2;
  
  cVar2 = DAT_ffffcabe;
  if ((DAT_ffffb5a4 == '\x01') && (DAT_ffffb5aa == '\0')) {
    DAT_ffffcabe = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffcabe = 0;
    bVar1 = false;
  }
  if ((cVar2 != '\x01') || (bVar1)) {
    if (DAT_ffffcab0 != '\0') {
      DAT_ffffcab0 = DAT_ffffcab0 + -1;
    }
  }
  else {
    cVar2 = '^';
    DAT_ffffcab0 = '^';
  }
  return cVar2;
}


