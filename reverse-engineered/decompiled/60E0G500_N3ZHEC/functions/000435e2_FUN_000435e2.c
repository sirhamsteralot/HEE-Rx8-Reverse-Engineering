/* ROM address: 0x000435e2; body bytes: 158; decompiled */

char FUN_000435e2(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9dc = 0;
    DAT_ffffc9de = 0;
    DAT_ffffc9dd = 0;
    DAT_ffffc9df = 0;
    DAT_ffffc9e0 = 0;
    DAT_ffffc9e1 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffc9eb == '\x01') && (DAT_ffffc9ee == '\x01')) {
      DAT_ffffc9dc = 1;
      DAT_ffffc9de = 1;
    }
    if ((DAT_ffffc9e9 == '\x01') || (DAT_ffffc9ec == '\x01')) {
      DAT_ffffc9dd = 1;
    }
    if ((DAT_ffffc9ea == '\x01') || (DAT_ffffc9ed == '\x01')) {
      DAT_ffffc9df = 1;
    }
    if (DAT_ffffc9f0 == '\x01') {
      DAT_ffffc9e0 = 1;
    }
    cVar1 = DAT_ffffc9ef;
    if (DAT_ffffc9ef == '\x01') {
      DAT_ffffc9e1 = 1;
    }
  }
  return cVar1;
}


