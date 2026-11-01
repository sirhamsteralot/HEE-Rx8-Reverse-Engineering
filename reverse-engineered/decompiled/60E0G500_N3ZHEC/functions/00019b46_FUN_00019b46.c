/* ROM address: 0x00019b46; body bytes: 130; decompiled */

char FUN_00019b46(void)

{
  char cVar1;
  
  if (DAT_ffffb5b8 < 2500.0) {
    if (DAT_ffffb5b8 < 1700.0) {
      DAT_ffffaa00 = '\0';
    }
  }
  else {
    DAT_ffffaa00 = '\x01';
  }
  if (DAT_ffffb5b8 < 1700.0) {
    if (DAT_ffffb5b8 < 1100.0) {
      DAT_ffffaa01 = '\0';
    }
  }
  else {
    DAT_ffffaa01 = '\x01';
  }
  if (((DAT_ffffa9ee == '\x01') && (cVar1 = '\x01', DAT_ffffaa00 == '\x01')) ||
     ((cVar1 = DAT_ffffa9f0, DAT_ffffa9f0 == '\x01' &&
      (cVar1 = DAT_ffffaa01, DAT_ffffaa01 == '\x01')))) {
    DAT_ffffa9e8 = 1;
  }
  else {
    DAT_ffffa9e8 = 0;
  }
  return cVar1;
}


