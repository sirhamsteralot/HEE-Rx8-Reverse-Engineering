/* ROM address: 0x0000a13e; body bytes: 24; decompiled */

undefined4 FUN_0000a13e(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  uVar1 = ref_osTaskScheduler(1,8,local_8);
  return uVar1;
}


