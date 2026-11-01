/* ROM address: 0x0003ec20; body bytes: 70; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003ec56) */

undefined4 FUN_0003ec20(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  short local_14;
  short sStack_12;
  
  sStack_12 = (short)param_1;
  local_14 = (short)((uint)param_1 >> 0x10);
  uVar1 = FUN_00003920(0x10);
  *(short *)(param_2 + 1) = ~(sStack_12 + local_14);
  *param_2 = param_1;
  *(short *)((int)param_2 + 6) = ~(sStack_12 + local_14);
  FUN_00003934(uVar1);
  return 0;
}


