/* ROM address: 0x0003eb24; body bytes: 78; decompiled */

undefined4 FUN_0003eb24(short *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (((short)~(param_1[1] + *param_1) == param_1[2]) ||
     ((short)~(param_1[1] + *param_1) == param_1[3])) {
    param_2 = *(undefined4 *)param_1;
  }
  else {
    FUN_0003edb8();
  }
  FUN_00003934(uVar1);
  return param_2;
}


