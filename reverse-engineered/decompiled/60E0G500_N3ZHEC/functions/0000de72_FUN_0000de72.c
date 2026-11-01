/* ROM address: 0x0000de72; body bytes: 102; decompiled */

char FUN_0000de72(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffaae0;
  if ((DAT_ffffaae0 == '\x01') && (cVar1 = '\x01', DAT_ffffb5e8 != '\x01')) {
    if (((DAT_ffffbc44 == '\0') ||
        (((DAT_ffffbc18 == '\0' || (DAT_ffffce98 == '\0')) || (DAT_ffffbc66 == '\0')))) &&
       (cVar1 = FUN_000671a4(0x80), cVar1 == '\0')) {
      DAT_ffffa401 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa401 = 0;
  }
  return cVar1;
}


