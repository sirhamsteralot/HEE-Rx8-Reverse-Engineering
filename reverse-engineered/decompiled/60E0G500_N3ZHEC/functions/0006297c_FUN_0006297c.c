/* ROM address: 0x0006297c; body bytes: 150; decompiled */

void FUN_0006297c(byte param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    if (param_2 == 1) {
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_0006205e();
        uVar1 = FUN_00062058();
        FUN_00063920(uVar1);
        FUN_000639a0(0xffff);
        return;
      }
    }
    else if (((param_2 == 0xc0) || (param_2 == 0xc1)) && ((param_1 & 0x80) != 0x80)) {
      FUN_0006205e();
      uVar1 = FUN_00062058();
      FUN_000639a0(uVar1);
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_00063920(uVar1);
        return;
      }
    }
  }
  return;
}


