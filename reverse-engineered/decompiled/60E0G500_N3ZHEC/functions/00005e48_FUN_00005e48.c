/* ROM address: 0x00005e48; body bytes: 16; decompiled */

void FUN_00005e48(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 7 | 0xf8;
  FUN_00005348(0xdb);
  return;
}


