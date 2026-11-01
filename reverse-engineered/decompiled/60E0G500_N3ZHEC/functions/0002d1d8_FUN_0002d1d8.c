/* ROM address: 0x0002d1d8; body bytes: 44; decompiled */

char FUN_0002d1d8(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_ffffb5a4;
  if ((DAT_ffffb5a4 == '\x01') && (cVar1 = DAT_ffffb5aa, DAT_ffffb5aa != '\x01')) {
    cVar2 = '\x0f';
  }
  else {
    cVar2 = '\0';
  }
  DAT_ffffbcc9 = cVar2 * '\x10' + '\x0f';
  return cVar1;
}


