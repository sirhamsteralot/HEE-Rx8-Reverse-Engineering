/* ROM address: 0x0003eae4; body bytes: 64; decompiled */

int FUN_0003eae4(ushort *param_1,ushort param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (*param_1 == (ushort)~param_1[1]) {
    param_2 = *param_1;
  }
  else {
    FUN_0003edb8();
  }
  FUN_00003934(uVar1);
  return (int)(short)param_2;
}


