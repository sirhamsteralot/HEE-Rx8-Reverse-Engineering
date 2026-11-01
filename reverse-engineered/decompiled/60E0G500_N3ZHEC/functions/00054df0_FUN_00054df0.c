/* ROM address: 0x00054df0; body bytes: 54; decompiled */

undefined4 FUN_00054df0(void)

{
  char cVar1;
  
  cVar1 = FUN_00060194(0x1e,0);
  if ((cVar1 != '\x01') && (cVar1 = FUN_00060194(0x1f,0), cVar1 != '\x01')) {
    DAT_ffffd1fa = 0;
    return 0;
  }
  DAT_ffffd1fa = 1;
  return 1;
}


