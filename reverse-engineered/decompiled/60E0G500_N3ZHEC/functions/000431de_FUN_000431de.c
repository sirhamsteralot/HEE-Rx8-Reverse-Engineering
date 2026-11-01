/* ROM address: 0x000431de; body bytes: 132; decompiled */

char FUN_000431de(void)

{
  char cVar1;
  
  if ((DAT_ffffc99f == '\x01') || (DAT_ffffc9bf == '\x01')) {
    DAT_ffffc9a2 = 1;
  }
  else {
    DAT_ffffc9a2 = 0;
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9a3 = 0;
    DAT_ffffc9a1 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffc9a0 == '\x01') || (DAT_ffffc99d == '\x01')) {
      DAT_ffffc9a3 = 1;
      DAT_ffffc9a1 = 0;
    }
    cVar1 = DAT_ffffc99e;
    if ((DAT_ffffc99e == '\x01') && (cVar1 = DAT_ffffc99c, DAT_ffffc99c == '\x01')) {
      DAT_ffffc9a1 = 1;
      DAT_ffffc9a3 = 0;
    }
  }
  return cVar1;
}


