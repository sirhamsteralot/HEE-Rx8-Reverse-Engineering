/* ROM address: 0x00058fea; body bytes: 44; decompiled */

void FUN_00058fea(int param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    ref_validateAddressCopy_16bit_ADDRESS__(param_1);
    bVar1 = bVar1 + 1;
    param_1 = param_1 + 4;
  } while (bVar1 < 4);
  return;
}


