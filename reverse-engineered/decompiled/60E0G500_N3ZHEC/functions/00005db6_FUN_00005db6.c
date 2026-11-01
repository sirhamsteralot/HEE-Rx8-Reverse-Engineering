/* ROM address: 0x00005db6; body bytes: 16; decompiled */

void FUN_00005db6(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff014;
  DAT_fffff014 = bVar1 & 7 | 0xc0;
  FUN_00005348(0xd0);
  return;
}


