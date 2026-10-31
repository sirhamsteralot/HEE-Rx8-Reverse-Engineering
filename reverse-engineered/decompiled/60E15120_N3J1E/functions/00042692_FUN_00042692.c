/* ROM address: 0x00042692; body bytes: 158; decompiled */

char FUN_00042692(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc96c = 0;
    DAT_ffffc96e = 0;
    DAT_ffffc96d = 0;
    DAT_ffffc96f = 0;
    DAT_ffffc970 = 0;
    DAT_ffffc971 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffc97b == '\x01') && (DAT_ffffc97e == '\x01')) {
      DAT_ffffc96c = 1;
      DAT_ffffc96e = 1;
    }
    if ((DAT_ffffc979 == '\x01') || (DAT_ffffc97c == '\x01')) {
      DAT_ffffc96d = 1;
    }
    if ((DAT_ffffc97a == '\x01') || (DAT_ffffc97d == '\x01')) {
      DAT_ffffc96f = 1;
    }
    if (DAT_ffffc980 == '\x01') {
      DAT_ffffc970 = 1;
    }
    cVar1 = DAT_ffffc97f;
    if (DAT_ffffc97f == '\x01') {
      DAT_ffffc971 = 1;
    }
  }
  return cVar1;
}


