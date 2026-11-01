/* ROM address: 0x00054e26; body bytes: 40; decompiled */

char FUN_00054e26(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffc99d == '\x01') || (cVar1 = DAT_ffffc9a0, DAT_ffffc9a0 == '\x01')) {
    DAT_ffffd1f8 = 1;
  }
  else {
    DAT_ffffd1f8 = 0;
  }
  return cVar1;
}


