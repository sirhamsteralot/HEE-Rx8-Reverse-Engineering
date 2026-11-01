/* ROM address: 0x0000d674; body bytes: 38; decompiled */

undefined4 FUN_0000d674(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 & 3) != 0) || (param_2 < param_1)) ||
     (((param_2 & 3) != 3 && (param_1 != param_2)))) {
    uVar1 = 1;
  }
  return uVar1;
}


