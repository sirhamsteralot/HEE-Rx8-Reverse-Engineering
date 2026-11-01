/* ROM address: 0x00054e4e; body bytes: 40; decompiled */

char FUN_00054e4e(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc99c;
  if ((DAT_ffffc99c == '\x01') && (cVar1 = DAT_ffffc99e, DAT_ffffc99e == '\x01')) {
    DAT_ffffd1f9 = 1;
  }
  else {
    DAT_ffffd1f9 = 0;
  }
  return cVar1;
}


