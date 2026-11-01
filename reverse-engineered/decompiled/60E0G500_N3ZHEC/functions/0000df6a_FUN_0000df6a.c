/* ROM address: 0x0000df6a; body bytes: 72; decompiled */

char FUN_0000df6a(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffaae0;
  if ((DAT_ffffaae0 == '\x01') && (cVar1 = '\x01', DAT_ffffb5e8 != '\x01')) {
    if ((DAT_ffffc067 == '\0') && (cVar1 = FUN_000671a4(0x81), cVar1 == '\0')) {
      DAT_ffffa403 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa403 = 0;
  }
  return cVar1;
}


