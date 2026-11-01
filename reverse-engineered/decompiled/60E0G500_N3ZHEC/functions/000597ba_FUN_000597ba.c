/* ROM address: 0x000597ba; body bytes: 52; decompiled */

void FUN_000597ba(int param_1)

{
  byte bVar1;
  
  FUN_0003ebd0(param_1 + 0xc,1);
  bVar1 = 0;
  do {
    FUN_0003ebd0(param_1,0);
    bVar1 = bVar1 + 1;
    param_1 = param_1 + 4;
  } while (bVar1 < 3);
  return;
}


