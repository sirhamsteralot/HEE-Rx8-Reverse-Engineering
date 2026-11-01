/* ROM address: 0x00005ddc; body bytes: 16; decompiled */

void FUN_00005ddc(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff014;
  DAT_fffff014 = bVar1 & 7 | 0xf8;
  FUN_00005348(0xd3);
  return;
}


