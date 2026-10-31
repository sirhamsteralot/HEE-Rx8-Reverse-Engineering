/* ROM address: 0x00054682; body bytes: 40; decompiled */

char FUN_00054682(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffc92d == '\x01') || (cVar1 = DAT_ffffc930, DAT_ffffc930 == '\x01')) {
    DAT_ffffd1bc = 1;
  }
  else {
    DAT_ffffd1bc = 0;
  }
  return cVar1;
}


