/* ROM address: 0x0003ed52; body bytes: 90; decompiled */

undefined4 FUN_0003ed52(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  short local_10;
  short sStack_e;
  
  uVar1 = FUN_00003920(0x10);
  sStack_e = (short)*param_1;
  local_10 = (short)((uint)*param_1 >> 0x10);
  uVar2 = ~(sStack_e + local_10);
  if ((uVar2 == *(ushort *)(param_1 + 1)) || (uVar2 == *(ushort *)((int)param_1 + 6))) {
    uVar3 = 0;
    *(ushort *)(param_1 + 1) = uVar2;
    *(ushort *)((int)param_1 + 6) = uVar2;
  }
  else {
    uVar3 = 1;
    FUN_0003eecc();
  }
  FUN_00003934(uVar1);
  return uVar3;
}


