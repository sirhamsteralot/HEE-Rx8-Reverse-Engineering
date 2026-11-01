/* ROM address: 0x00053f10; body bytes: 96; decompiled */

undefined4 FUN_00053f10(void)

{
  char cVar1;
  
  cVar1 = FUN_00060194(0x2a,0);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_00060194(0x65,0), cVar1 != '\x01')) &&
      (cVar1 = FUN_00060194(0x66,0), cVar1 != '\x01')) &&
     ((cVar1 = FUN_00060194(0x67,0), cVar1 != '\x01' &&
      (cVar1 = FUN_00060194(0x68,0), cVar1 != '\x01')))) {
    DAT_ffffd1cc = 0;
    return 0;
  }
  DAT_ffffd1cc = 1;
  return 1;
}


