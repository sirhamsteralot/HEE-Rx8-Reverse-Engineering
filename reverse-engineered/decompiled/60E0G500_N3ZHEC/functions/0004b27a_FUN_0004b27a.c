/* ROM address: 0x0004b27a; body bytes: 48; decompiled */

char FUN_0004b27a(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\0') {
    cVar1 = DAT_ffff9fa2;
    if (DAT_ffff9fa2 == '\x02') {
      cVar1 = '\0';
      DAT_ffffcdfe = 1;
    }
  }
  else {
    cVar1 = '\0';
    DAT_ffffcdfe = 0;
  }
  return cVar1;
}


