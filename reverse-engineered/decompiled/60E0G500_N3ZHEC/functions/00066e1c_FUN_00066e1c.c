/* ROM address: 0x00066e1c; body bytes: 50; decompiled */

undefined4 FUN_00066e1c(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 0xff) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00066e4e(param_1,param_2 + 0xff & 0xe0);
    uVar1 = FUN_00067162(param_2,uVar1);
  }
  return uVar1;
}


