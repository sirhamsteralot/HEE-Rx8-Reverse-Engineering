/* ROM address: 0x00002440; body bytes: 30; decompiled */

undefined4 FUN_00002440(float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((param_1 < param_2 - param_3) || (param_2 + param_3 < param_1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


