/* ROM address: 0x00012930; body bytes: 136; decompiled */

char FUN_00012930(void)

{
  char cVar1;
  
  if (((((DAT_ffffb5a4 != '\x01') && (cVar1 = DAT_ffffcabc, DAT_ffffcabc != '\x01')) ||
       (cVar1 = DAT_ffffaada, DAT_ffffaada != '\x01')) ||
      (((DAT_ffffa6a3 != '\x01' || (cVar1 = '\0', DAT_ffffa444 != '\0')) &&
       ((cVar1 = DAT_ffffa6a4, DAT_ffffa6a4 != '\x01' || (DAT_ffffa445 != '\0')))))) ||
     ((DAT_ffffa694 - DAT_ffffb5b8 < 40.0 || (2000.0 < DAT_ffffb5b8)))) {
    DAT_ffffa690 = 0;
  }
  else {
    DAT_ffffa690 = 1;
  }
  DAT_ffffa694 = DAT_ffffb5b8;
  DAT_ffffa6a3 = DAT_ffffa444;
  DAT_ffffa6a4 = DAT_ffffa445;
  return cVar1;
}


