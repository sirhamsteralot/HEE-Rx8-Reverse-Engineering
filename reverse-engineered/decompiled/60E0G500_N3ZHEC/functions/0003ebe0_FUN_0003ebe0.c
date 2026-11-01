/* ROM address: 0x0003ebe0; body bytes: 64; decompiled */

undefined4 FUN_0003ebe0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  short local_10;
  short sStack_e;
  
  sStack_e = (short)param_2;
  local_10 = (short)((uint)param_2 >> 0x10);
  uVar1 = FUN_00003920(0x10);
  *(short *)(param_1 + 1) = ~(sStack_e + local_10);
  *param_1 = param_2;
  *(short *)((int)param_1 + 6) = ~(sStack_e + local_10);
  FUN_00003934(uVar1);
  return 0;
}


