/* ROM address: 0x00014230; body bytes: 92; decompiled */

void FUN_00014230(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00003920(0x10);
  FUN_00013458();
  uVar2 = param_1 & 0xff;
  if ((((uVar2 == 0) || (uVar2 == 0xc)) || (uVar2 == 6)) || (uVar2 == 0x12)) {
    FUN_000191e8(param_1);
  }
  FUN_0002c7c4();
  FUN_0002c8c0();
  FUN_00010b30(param_1);
  FUN_00010388(param_1);
  FUN_00003934(uVar1);
  return;
}


