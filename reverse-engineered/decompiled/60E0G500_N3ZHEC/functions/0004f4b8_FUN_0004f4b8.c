/* ROM address: 0x0004f4b8; body bytes: 40; decompiled */

char FUN_0004f4b8(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffcffb == '\x01') || (cVar1 = DAT_ffffcffc, DAT_ffffcffc == '\x01')) {
    DAT_ffffcffa = 1;
  }
  else {
    DAT_ffffcffa = 0;
  }
  return cVar1;
}


