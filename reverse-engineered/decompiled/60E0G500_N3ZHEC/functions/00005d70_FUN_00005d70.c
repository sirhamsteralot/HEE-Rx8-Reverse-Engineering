/* ROM address: 0x00005d70; body bytes: 16; decompiled */

void FUN_00005d70(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 7 | 0xf8;
  FUN_00005348(0xcb);
  return;
}


