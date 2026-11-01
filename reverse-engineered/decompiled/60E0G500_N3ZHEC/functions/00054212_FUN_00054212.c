/* ROM address: 0x00054212; body bytes: 166; decompiled */

undefined4 FUN_00054212(void)

{
  char cVar1;
  
  cVar1 = FUN_00060194(0x1b,0);
  if ((((((cVar1 != '\x01') && (cVar1 = FUN_00060194(99,0), cVar1 != '\x01')) &&
        (cVar1 = FUN_00060194(100,0), cVar1 != '\x01')) &&
       ((cVar1 = FUN_00060194(0x19,0), cVar1 != '\x01' &&
        (cVar1 = FUN_00060194(0x1a,0), cVar1 != '\x01')))) &&
      ((cVar1 = FUN_00060194(0x18,0), cVar1 != '\x01' &&
       ((cVar1 = FUN_00060194(0x1d,0), cVar1 != '\x01' &&
        (cVar1 = FUN_00060194(0x1c,0), cVar1 != '\x01')))))) &&
     ((cVar1 = FUN_00060194(0x69,0), cVar1 != '\x01' &&
      (cVar1 = FUN_00060194(0x6a,0), cVar1 != '\x01')))) {
    DAT_ffffd1d8 = 0;
    return 0;
  }
  DAT_ffffd1d8 = 1;
  return 1;
}


