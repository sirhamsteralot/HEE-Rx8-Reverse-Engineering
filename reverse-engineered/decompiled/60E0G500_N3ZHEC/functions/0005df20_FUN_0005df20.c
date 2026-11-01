/* ROM address: 0x0005df20; body bytes: 52; decompiled */

char FUN_0005df20(void)

{
  char cVar1;
  
  if (DAT_ffffa41c == '\x01') {
    DAT_ffffd3a8 = 0x80;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffaadb;
    if ((DAT_ffffaadb == '\x01') && (cVar1 = DAT_ffffb5aa, DAT_ffffb5aa == '\x01')) {
      DAT_ffffd3a8 = 0x40;
    }
    else {
      DAT_ffffd3a8 = 0x20;
    }
  }
  return cVar1;
}


