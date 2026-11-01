/* ROM address: 0x0004f06a; body bytes: 98; decompiled */

char FUN_0004f06a(void)

{
  char cVar1;
  
  if (DAT_ffffd005 == '\0') {
    cVar1 = '\0';
  }
  else {
    cVar1 = FUN_00011f34();
    if ((cVar1 == '\0') || (((int)DAT_ffffce5c & 0x80U) != 0)) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\x02';
    }
  }
  if (cVar1 == '\0') {
    DAT_ffffcff1 = -0x80;
  }
  else if (cVar1 == '\x01') {
    DAT_ffffcff1 = '@';
  }
  else {
    DAT_ffffcff1 = cVar1;
    if (cVar1 == '\x02') {
      DAT_ffffcff1 = ' ';
    }
  }
  return cVar1;
}


