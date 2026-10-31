/* ROM address: 0x00053a6e; body bytes: 166; decompiled */

undefined4 FUN_00053a6e(void)

{
  char cVar1;
  
  cVar1 = FUN_0005f9f0(0x1b,0);
  if ((((((cVar1 != '\x01') && (cVar1 = FUN_0005f9f0(99,0), cVar1 != '\x01')) &&
        (cVar1 = FUN_0005f9f0(100,0), cVar1 != '\x01')) &&
       ((cVar1 = FUN_0005f9f0(0x19,0), cVar1 != '\x01' &&
        (cVar1 = FUN_0005f9f0(0x1a,0), cVar1 != '\x01')))) &&
      ((cVar1 = FUN_0005f9f0(0x18,0), cVar1 != '\x01' &&
       ((cVar1 = FUN_0005f9f0(0x1d,0), cVar1 != '\x01' &&
        (cVar1 = FUN_0005f9f0(0x1c,0), cVar1 != '\x01')))))) &&
     ((cVar1 = FUN_0005f9f0(0x69,0), cVar1 != '\x01' &&
      (cVar1 = FUN_0005f9f0(0x6a,0), cVar1 != '\x01')))) {
    DAT_ffffd19c = 0;
    return 0;
  }
  DAT_ffffd19c = 1;
  return 1;
}


