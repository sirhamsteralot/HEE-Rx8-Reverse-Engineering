/* ROM address: 0x00005d26; body bytes: 16; decompiled */

void FUN_00005d26(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 7 | 0xb8;
  FUN_00005348(0xc9);
  return;
}


