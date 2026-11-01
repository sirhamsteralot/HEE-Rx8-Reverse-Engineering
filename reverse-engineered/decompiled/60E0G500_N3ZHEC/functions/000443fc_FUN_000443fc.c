/* ROM address: 0x000443fc; body bytes: 40; decompiled */

char FUN_000443fc(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffcab4;
  if (DAT_ffffcab4 == '\x01') {
    cVar1 = DAT_ffffcab5;
    if (DAT_ffffcab5 == '\x01') {
      DAT_ffffca2c = 0x40000000;
    }
    else {
      DAT_ffffca2c = 0;
    }
  }
  return cVar1;
}


