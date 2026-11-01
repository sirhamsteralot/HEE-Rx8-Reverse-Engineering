/* ROM address: 0x00005d16; body bytes: 16; decompiled */

void FUN_00005d16(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 7 | 0xc0;
  FUN_00005348(200);
  return;
}


