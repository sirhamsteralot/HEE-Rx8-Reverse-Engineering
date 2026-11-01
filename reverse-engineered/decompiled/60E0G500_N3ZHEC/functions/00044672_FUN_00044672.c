/* ROM address: 0x00044672; body bytes: 60; decompiled */

char FUN_00044672(void)

{
  char cVar1;
  
  if ((DAT_ffffcabb == '\x01') && (DAT_ffffcaaf == '\0')) {
    DAT_ffffcabb = '\0';
    cVar1 = '\0';
  }
  else {
    cVar1 = DAT_ffffcabb;
    if ((DAT_ffffcab2 != '\0') && (cVar1 = DAT_ffffcab4, DAT_ffffcab4 == '\x01')) {
      DAT_ffffcabb = '\x01';
    }
  }
  return cVar1;
}


