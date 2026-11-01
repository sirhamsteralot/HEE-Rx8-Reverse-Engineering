/* ROM address: 0x0002e114; body bytes: 102; decompiled */

char FUN_0002e114(void)

{
  char cVar1;
  
  if ((((DAT_ffffbd54 == '\x01') || (DAT_ffffbd55 == '\x01')) || (DAT_ffffbd56 == '\x01')) ||
     (DAT_ffffbd6a == '\x01')) {
    DAT_ffffbd58 = 0;
    cVar1 = '\0';
  }
  else if (27.0 < DAT_ffffc008) {
    DAT_ffffbd58 = 1;
    cVar1 = DAT_ffffbd6a;
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}


