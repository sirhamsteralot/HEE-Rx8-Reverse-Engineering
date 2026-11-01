/* ROM address: 0x00005da6; body bytes: 16; decompiled */

void FUN_00005da6(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff00c;
  DAT_fffff00c = bVar1 & 7 | 0xf8;
  FUN_00005348(0xcf);
  return;
}


