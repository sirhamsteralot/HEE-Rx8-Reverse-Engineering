/* ROM address: 0x0003eb72; body bytes: 78; decompiled */

undefined4 FUN_0003eb72(undefined4 param_1,short *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (((short)~(param_2[1] + *param_2) == param_2[2]) ||
     ((short)~(param_2[1] + *param_2) == param_2[3])) {
    param_1 = *(undefined4 *)param_2;
  }
  else {
    FUN_0003edb8();
  }
  FUN_00003934(uVar1);
  return param_1;
}


