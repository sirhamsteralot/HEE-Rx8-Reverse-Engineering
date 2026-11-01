/* ROM address: 0x00013f20; body bytes: 104; decompiled */

void coolant_timing_derate_calc(void)

{
  undefined4 uVar1;
  float fVar2;
  float arg1;
  float arg2;
  
  arg2 = 1.0;
  arg1 = 0.0;
  uVar1 = FUN_00002500(0x3f800000,0,(int)DAT_ffffa768);
  DAT_ffffa77c = (float)FUN_00013f88(uVar1);
  DAT_ffffa780 = (float)FUN_00014050(uVar1);
  fVar2 = (float)FUN_0003ea74(DAT_ffffaa10 - 5.0,0x425c0000);
  fVar2 = rx8_clamp_float(fVar2,arg1,arg2);
  DAT_ffffa760 = DAT_ffffa77c * fVar2;
  DAT_ffffa764 = DAT_ffffa780 * fVar2;
  return;
}


