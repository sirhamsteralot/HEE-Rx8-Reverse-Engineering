/* ROM address: 0x0005243a; body bytes: 60; decompiled */

char FUN_0005243a(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffcf86;
  if ((DAT_ffffcf86 == '\x01') && (DAT_ffffcfe4 - DAT_ffffcfe8 < 0.002)) {
    cVar1 = ref_getFaultStatus__(0x30);
    if (cVar1 == '\0') {
      DAT_ffffd115 = 1;
    }
  }
  return cVar1;
}


