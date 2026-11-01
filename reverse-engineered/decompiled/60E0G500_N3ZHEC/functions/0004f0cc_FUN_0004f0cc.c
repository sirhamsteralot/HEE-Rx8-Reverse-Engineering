/* ROM address: 0x0004f0cc; body bytes: 40; decompiled */

char FUN_0004f0cc(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffd07c == '\x01') || (cVar1 = DAT_ffffd0e4, DAT_ffffd0e4 == '\x01')) {
    DAT_ffffd002 = 1;
  }
  else {
    DAT_ffffd002 = 0;
  }
  return cVar1;
}


