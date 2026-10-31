/* ROM address: 0x00059016; body bytes: 52; decompiled */

void FUN_00059016(int param_1)

{
  byte bVar1;
  
  ref_updateMemoryAtAddress_16bit_ADDR_VAL(param_1 + 0xc,1);
  bVar1 = 0;
  do {
    ref_updateMemoryAtAddress_16bit_ADDR_VAL(param_1,0);
    bVar1 = bVar1 + 1;
    param_1 = param_1 + 4;
  } while (bVar1 < 3);
  return;
}


