/* ROM address: 0x0004ed14; body bytes: 40; decompiled */

char FUN_0004ed14(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffcfbf == '\x01') || (cVar1 = DAT_ffffcfc0, DAT_ffffcfc0 == '\x01')) {
    DAT_ffffcfbe = 1;
  }
  else {
    DAT_ffffcfbe = 0;
  }
  return cVar1;
}


