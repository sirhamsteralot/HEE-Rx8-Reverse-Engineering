/* ROM address: 0x00053378; body bytes: 44; decompiled */

char FUN_00053378(void)

{
  char cVar1;
  
  if (DAT_ffffd002 == '\x01') {
    DAT_ffffd168 = 0x3a03126f;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffd12e;
    if (DAT_ffffd12e == '\x01') {
      DAT_ffffd168 = 0x3a83126f;
    }
  }
  return cVar1;
}


