/* ROM address: 0x00043722; body bytes: 60; decompiled */

char FUN_00043722(void)

{
  char cVar1;
  
  if ((DAT_ffffca4b == '\x01') && (DAT_ffffca3f == '\0')) {
    DAT_ffffca4b = '\0';
    cVar1 = '\0';
  }
  else {
    cVar1 = DAT_ffffca4b;
    if ((DAT_ffffca42 != '\0') && (cVar1 = DAT_ffffca44, DAT_ffffca44 == '\x01')) {
      DAT_ffffca4b = '\x01';
    }
  }
  return cVar1;
}


