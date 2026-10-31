/* ROM address: 0x00054780; body bytes: 54; decompiled */

undefined4 FUN_00054780(void)

{
  char cVar1;
  
  cVar1 = FUN_0005f9f0(1,0);
  if ((cVar1 != '\x01') && (cVar1 = FUN_0005f9f0(0), cVar1 != '\x01')) {
    DAT_ffffd1c0 = 0;
    return 0;
  }
  DAT_ffffd1c0 = 1;
  return 1;
}


