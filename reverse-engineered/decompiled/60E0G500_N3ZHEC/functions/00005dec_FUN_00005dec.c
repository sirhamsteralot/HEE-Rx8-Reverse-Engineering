/* ROM address: 0x00005dec; body bytes: 16; decompiled */

void FUN_00005dec(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff01c;
  DAT_fffff01c = bVar1 & 7 | 0xc0;
  FUN_00005348(0xd4);
  return;
}


