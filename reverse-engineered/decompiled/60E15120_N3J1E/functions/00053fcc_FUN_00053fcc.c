/* ROM address: 0x00053fcc; body bytes: 64; decompiled */

char FUN_00053fcc(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc911;
  if ((((DAT_ffffc911 == '\x01') && (cVar1 = DAT_ffffc913, DAT_ffffc913 == '\x01')) &&
      (cVar1 = DAT_ffffc994, DAT_ffffc994 == '\x01')) &&
     (cVar1 = DAT_ffffc996, DAT_ffffc996 == '\x01')) {
    DAT_ffffd1a9 = 1;
  }
  else {
    DAT_ffffd1a9 = 0;
  }
  return cVar1;
}


