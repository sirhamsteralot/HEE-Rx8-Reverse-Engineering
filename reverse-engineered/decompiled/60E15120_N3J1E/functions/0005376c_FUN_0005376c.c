/* ROM address: 0x0005376c; body bytes: 96; decompiled */

undefined4 FUN_0005376c(void)

{
  char cVar1;
  
  cVar1 = FUN_0005f9f0(0x2a,0);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_0005f9f0(0x65,0), cVar1 != '\x01')) &&
      (cVar1 = FUN_0005f9f0(0x66,0), cVar1 != '\x01')) &&
     ((cVar1 = FUN_0005f9f0(0x67,0), cVar1 != '\x01' &&
      (cVar1 = FUN_0005f9f0(0x68,0), cVar1 != '\x01')))) {
    DAT_ffffd190 = 0;
    return 0;
  }
  DAT_ffffd190 = 1;
  return 1;
}


