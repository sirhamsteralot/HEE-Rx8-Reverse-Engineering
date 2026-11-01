/* ROM address: 0x00005dc6; body bytes: 16; decompiled */

void FUN_00005dc6(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff014;
  DAT_fffff014 = bVar1 & 7 | 0xb8;
  FUN_00005348(0xd1);
  return;
}


