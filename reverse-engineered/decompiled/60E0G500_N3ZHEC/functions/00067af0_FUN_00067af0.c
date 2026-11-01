/* ROM address: 0x00067af0; body bytes: 112; decompiled */

uint FUN_00067af0(uint param_1,char param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 == 0) {
    param_1 = FUN_000694fa();
  }
  else if (param_1 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_00066ece(6,0x12,uVar1);
  }
  else if (param_1 == 2) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_00066ece(6,0x12,uVar1);
  }
  return param_1;
}


