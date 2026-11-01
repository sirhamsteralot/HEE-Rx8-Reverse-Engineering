/* ROM address: 0x0000df08; body bytes: 98; decompiled */

char FUN_0000df08(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffaae0;
  if ((DAT_ffffaae0 == '\x01') && (cVar1 = '\x01', DAT_ffffb5e8 != '\x01')) {
    if (((DAT_ffffbb28 == '\0') || (DAT_ffffbb58 == '\0')) &&
       ((((int)DAT_ffffcd4e & 0x80U) != 0 && (cVar1 = FUN_000671a4(0x7f), cVar1 == '\0')))) {
      DAT_ffffa402 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa402 = 0;
  }
  return cVar1;
}


