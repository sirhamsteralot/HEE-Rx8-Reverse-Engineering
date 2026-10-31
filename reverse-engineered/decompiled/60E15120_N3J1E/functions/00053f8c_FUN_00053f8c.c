/* ROM address: 0x00053f8c; body bytes: 64; decompiled */

char FUN_00053f8c(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((((DAT_ffffc912 == '\x01') || (cVar1 = '\x01', DAT_ffffc914 == '\x01')) ||
      (cVar1 = '\x01', DAT_ffffc995 == '\x01')) || (cVar1 = DAT_ffffc997, DAT_ffffc997 == '\x01')) {
    DAT_ffffd1aa = 1;
  }
  else {
    DAT_ffffd1aa = 0;
  }
  return cVar1;
}


