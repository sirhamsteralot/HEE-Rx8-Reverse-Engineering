/* ROM address: 0x0001b15c; body bytes: 122; decompiled */

uint FUN_0001b15c(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar4 = 0x42700000;
  fVar5 = DAT_ffffaa88;
  uVar6 = DAT_ffffb5b8;
  fVar2 = (float)FUN_0003ea74(0x42700000,DAT_ffffb5b8);
  DAT_ffffaad4 = rx8_min_float(fVar5 * fVar2,5.0);
  fVar2 = 1e-05;
  uVar1 = FUN_00002440(uVar6,0,0x3727c5ac);
  if ((uVar1 & 0xff) == 0) {
    DAT_ffffaad0 = 0.1560058;
  }
  else {
    fVar3 = (float)FUN_0003ea74(uVar4,uVar6);
    DAT_ffffaad0 = rx8_first_order_filter(fVar5 * fVar3,DAT_ffffaad0,1.0,fVar2);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


