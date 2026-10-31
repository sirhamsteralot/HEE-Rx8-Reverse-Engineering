/* ROM address: 0x0005464c; body bytes: 54; decompiled */

undefined4 FUN_0005464c(void)

{
  char cVar1;
  
  cVar1 = FUN_0005f9f0(0x1e,0);
  if ((cVar1 != '\x01') && (cVar1 = FUN_0005f9f0(0x1f,0), cVar1 != '\x01')) {
    DAT_ffffd1be = 0;
    return 0;
  }
  DAT_ffffd1be = 1;
  return 1;
}


