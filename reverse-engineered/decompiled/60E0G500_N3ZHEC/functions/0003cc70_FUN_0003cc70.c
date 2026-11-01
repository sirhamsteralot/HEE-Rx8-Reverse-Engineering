/* ROM address: 0x0003cc70; body bytes: 64; decompiled */

char FUN_0003cc70(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc627 = 0;
    DAT_ffffc628 = '\0';
    cVar1 = '\x01';
  }
  else {
    if (DAT_ffffc615 == '\0') {
      DAT_ffffc628 = '\x01';
    }
    cVar1 = DAT_ffffc628;
    if (DAT_ffffc628 == '\x01') {
      DAT_ffffc627 = 0;
    }
    else if (DAT_ffffc614 == '\0') {
      DAT_ffffc627 = 1;
    }
  }
  return cVar1;
}


