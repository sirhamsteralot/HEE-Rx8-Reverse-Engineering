/* ROM address: 0x000137ee; body bytes: 40; decompiled */

char FUN_000137ee(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffa748;
  if ((DAT_ffffa748 == '\x01') && (cVar1 = DAT_ffffa749, DAT_ffffa749 == '\x01')) {
    DAT_ffffa740 = 1;
  }
  else {
    DAT_ffffa740 = 0;
  }
  return cVar1;
}


