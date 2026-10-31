/* ROM address: 0x0005904a; body bytes: 58; decompiled */

void FUN_0005904a(int param_1,short *param_2)

{
  short sVar1;
  byte bVar2;
  
  bVar2 = 0;
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    ref_updateMemoryAtAddress_16bit_ADDR_VAL(param_1,(int)sVar1);
    bVar2 = bVar2 + 1;
    param_1 = param_1 + 4;
  } while (bVar2 < 3);
  ref_updateMemoryAtAddress_16bit_ADDR_VAL(param_1,0);
  return;
}


