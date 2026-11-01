/* ROM address: 0x00005dfc; body bytes: 16; decompiled */

void FUN_00005dfc(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff01c;
  DAT_fffff01c = bVar1 & 7 | 0xb8;
  FUN_00005348(0xd5);
  return;
}


