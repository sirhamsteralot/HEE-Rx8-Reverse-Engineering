/* ROM address: 0x0005eba6; body bytes: 114; decompiled */

uint FUN_0005eba6(void)

{
  uint uVar1;
  float arg1;
  float arg2;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffd28e;
  fVar2 = (DAT_ffffae64 + DAT_ffffb140 + -1.0) * 100.0;
  if (uVar1 == 0x30) {
    uVar1 = FUN_0003ec20(fVar2,&DAT_ffff9188);
    return uVar1;
  }
  if (uVar1 == 0x40) {
    arg2 = 0.004999995;
    arg1 = (float)FUN_0003eb72(0,&DAT_ffff9188);
    fVar2 = rx8_first_order_filter(fVar2,arg1,arg2,1e-05);
    uVar1 = FUN_0003ec20(fVar2,&DAT_ffff9188);
    return uVar1;
  }
  return uVar1;
}


