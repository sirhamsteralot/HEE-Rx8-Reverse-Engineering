/* ROM address: 0x00005e22; body bytes: 16; decompiled */

void FUN_00005e22(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 7 | 0xc0;
  FUN_00005348(0xd8);
  return;
}


