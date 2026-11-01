/* ROM address: 0x0005e872; body bytes: 154; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3f4. Table purpose inferred from
   neighboring code. */

uint FUN_0005e872(short param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  char local_14 [4];
  short sStack_10;
  
  param_2 = param_2 & 0xff;
  sStack_10 = param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      FUN_00068928(0x33,local_14,1);
      cVar1 = FUN_00059aa4((int)local_14[0]);
      if (cVar1 == '\0') {
        cVar1 = FUN_00059934((int)local_14[0]);
        if (cVar1 == '\0') {
          param_2 = FUN_00059b86((int)local_14[0]);
          uVar2 = 0;
        }
        else {
          param_2 = FUN_00055112(0x33,0x31);
          uVar2 = param_2;
        }
      }
      else {
        param_2 = FUN_00055112(0x33,0x22);
        uVar2 = param_2;
      }
    }
    else {
      param_2 = FUN_00055112(0x33,0x12);
      uVar2 = param_2;
    }
    if ((uVar2 & 0xffff) != 0) {
      param_2 = FUN_000550ca(0x33,uVar2);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x33);
  }
  return param_2;
}


