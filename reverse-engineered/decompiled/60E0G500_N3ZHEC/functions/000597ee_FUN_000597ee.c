/* ROM address: 0x000597ee; body bytes: 58; decompiled */

void FUN_000597ee(int param_1,short *param_2)

{
  short sVar1;
  byte bVar2;
  
  bVar2 = 0;
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    FUN_0003ebd0(param_1,(int)sVar1);
    bVar2 = bVar2 + 1;
    param_1 = param_1 + 4;
  } while (bVar2 < 3);
  FUN_0003ebd0(param_1,0);
  return;
}


