/* ROM address: 0x00005d90; body bytes: 16; decompiled */

void FUN_00005d90(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff00c;
  DAT_fffff00c = bVar1 & 7 | 0xb8;
  FUN_00005348(0xcd);
  return;
}


