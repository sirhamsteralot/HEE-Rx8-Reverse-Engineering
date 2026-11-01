/* ROM address: 0x00005d80; body bytes: 16; decompiled */

void FUN_00005d80(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff00c;
  DAT_fffff00c = bVar1 & 7 | 0xc0;
  FUN_00005348(0xcc);
  return;
}


