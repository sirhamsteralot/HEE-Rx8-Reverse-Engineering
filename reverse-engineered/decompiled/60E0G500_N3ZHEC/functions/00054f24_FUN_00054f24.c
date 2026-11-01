/* ROM address: 0x00054f24; body bytes: 54; decompiled */

undefined4 FUN_00054f24(void)

{
  char cVar1;
  
  cVar1 = FUN_00060194(1,0);
  if ((cVar1 != '\x01') && (cVar1 = FUN_00060194(0), cVar1 != '\x01')) {
    DAT_ffffd1fc = 0;
    return 0;
  }
  DAT_ffffd1fc = 1;
  return 1;
}


