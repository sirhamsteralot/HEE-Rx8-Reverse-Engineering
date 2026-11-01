/* ROM address: 0x00002068; body bytes: 46; decompiled */

float FUN_00002068(int param_1)

{
  int extraout_r3;
  float in_fr2;
  
  FUN_00002624();
  (**(code **)((int)&PTR_FUN_00002098 + (uint)*(byte *)(param_1 + 2)))();
  if (extraout_r3 != 0) {
    in_fr2 = *(float *)(param_1 + 0x10) + in_fr2 * *(float *)(param_1 + 0xc);
  }
  return in_fr2;
}


