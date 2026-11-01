/* ROM address: 0x00054730; body bytes: 64; decompiled */

char FUN_00054730(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((((DAT_ffffc982 == '\x01') || (cVar1 = '\x01', DAT_ffffc984 == '\x01')) ||
      (cVar1 = '\x01', DAT_ffffca05 == '\x01')) || (cVar1 = DAT_ffffca07, DAT_ffffca07 == '\x01')) {
    DAT_ffffd1e6 = 1;
  }
  else {
    DAT_ffffd1e6 = 0;
  }
  return cVar1;
}


