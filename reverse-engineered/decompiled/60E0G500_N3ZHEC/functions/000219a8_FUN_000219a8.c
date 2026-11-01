/* ROM address: 0x000219a8; body bytes: 80; decompiled */

void FUN_000219a8(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00003920(0x10);
  uVar2 = param_1 & 0xff;
  if ((((uVar2 == 0) || (uVar2 == 0xc)) || (uVar2 == 6)) || (uVar2 == 0x12)) {
    fuel_cut_arbitration(param_1);
    FUN_00047b22(param_1);
  }
  FUN_0002d604(param_1);
  FUN_0000f4d8(param_1);
  FUN_00003934(uVar1);
  return;
}


