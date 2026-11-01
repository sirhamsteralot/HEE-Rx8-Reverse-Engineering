/* ROM address: 0x0003eca2; body bytes: 60; decompiled */

bool FUN_0003eca2(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_00003920(0x10);
  uVar1 = *param_1;
  uVar2 = param_1[1];
  if (uVar1 != (ushort)~uVar2) {
    FUN_0003eecc();
  }
  FUN_00003934(uVar3);
  return uVar1 != (ushort)~uVar2;
}


