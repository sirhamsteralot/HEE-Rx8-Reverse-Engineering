/* ROM address: 0x000020dc; body bytes: 48; decompiled */

float FUN_000020dc(int param_1)

{
  int iVar1;
  float in_fr2;
  
  FUN_00002658();
  iVar1 = (int)*(char *)(param_1 + 0x10);
  (**(code **)((int)&PTR_LAB_0000210c + iVar1))();
  if (iVar1 != 0) {
    in_fr2 = *(float *)(param_1 + 0x18) + in_fr2 * *(float *)(param_1 + 0x14);
  }
  return in_fr2;
}


