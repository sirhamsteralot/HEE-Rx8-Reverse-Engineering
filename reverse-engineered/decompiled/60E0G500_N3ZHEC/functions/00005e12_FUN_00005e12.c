/* ROM address: 0x00005e12; body bytes: 16; decompiled */

void FUN_00005e12(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff01c;
  DAT_fffff01c = bVar1 & 7 | 0xf8;
  FUN_00005348(0xd7);
  return;
}


