/* ROM address: 0x00005ce2; body bytes: 16; decompiled */

byte FUN_00005ce2(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff818;
  DAT_fffff818 = bVar1 & 0x7f;
  return bVar1 & 0x7f;
}


