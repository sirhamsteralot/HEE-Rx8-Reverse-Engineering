/* ROM address: 0x00054562; body bytes: 40; decompiled */

char FUN_00054562(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffd1df == '\x01') || (cVar1 = DAT_ffffd1e0, DAT_ffffd1e0 == '\x01')) {
    DAT_ffffd1dd = 1;
  }
  else {
    DAT_ffffd1dd = 0;
  }
  return cVar1;
}


