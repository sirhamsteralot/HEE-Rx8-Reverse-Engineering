/* ROM address: 0x000137c6; body bytes: 40; decompiled */

char FUN_000137c6(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffcda4;
  if ((DAT_ffffcda4 == '\x01') && (cVar1 = DAT_ffffcda6, DAT_ffffcda6 == '\x01')) {
    DAT_ffffa749 = 1;
  }
  else {
    DAT_ffffa749 = 0;
  }
  return cVar1;
}


