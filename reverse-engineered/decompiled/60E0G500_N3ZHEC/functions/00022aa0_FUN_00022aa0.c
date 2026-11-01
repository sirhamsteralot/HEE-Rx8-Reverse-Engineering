/* ROM address: 0x00022aa0; body bytes: 410; decompiled */

uint FUN_00022aa0(void)

{
  char cVar2;
  uint uVar1;
  uint extraout_r0;
  float *pfVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float arg1;
  
  fVar5 = DAT_ffffae64;
  arg1 = 0.0;
  uVar7 = DAT_ffffbe6c;
  fVar4 = rx8_absolute_difference(DAT_ffffbf24,0.0);
  cVar2 = FUN_00002440(DAT_ffffb35c,arg1,0x3727c5ac);
  uVar6 = DAT_ffffaa88;
  DAT_ffffb390 = FUN_00002068(DAT_ffffbe74,&DAT_0006a720);
  DAT_ffffb394 = (float)FUN_000020dc(uVar7,DAT_ffffb5b8,&DAT_0006a750);
  if (DAT_ffffaada == '\x01') {
    DAT_ffffb368 = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006a70c);
  }
  else {
    DAT_ffffb368 = (float)FUN_000020dc(uVar7,DAT_ffffad8c,&PTR_DAT_0006a734);
  }
  if (DAT_ffffb364 < 0xd6e) {
    pfVar3 = (float *)&DAT_00073750;
    DAT_ffffb37c = 0.0008;
  }
  else {
    pfVar3 = (float *)&DAT_00073758;
    DAT_ffffb37c = 0.0125;
  }
  DAT_ffffb380 = *pfVar3;
  if ((fVar5 <= 0.79999995) || (1.1999999 <= fVar5)) {
    DAT_ffffb36c = rx8_max_float(DAT_ffffb35c - 0.00938,arg1);
  }
  else {
    fVar5 = DAT_ffffb37c;
    if ((fVar4 < 0.0195) || (fVar5 = DAT_ffffb380, fVar4 < 0.1)) {
      DAT_ffffb36c = rx8_min_float(DAT_ffffb35c + fVar5,DAT_ffffb368);
    }
    else {
      DAT_ffffb36c = DAT_ffffb35c;
    }
  }
  if (cVar2 != '\0') {
    DAT_ffffb364 = FUN_00002460((int)(short)DAT_ffffb364,1);
  }
  fVar5 = (float)FUN_0003ea74(DAT_ffffb390,uVar6);
  DAT_ffffb370 = fVar5 * 100.0;
  DAT_ffffb384 = (DAT_ffffb140 + 1.0) * DAT_ffffb394;
  fVar5 = rx8_max_float(DAT_ffffb290,arg1);
  fVar5 = (float)FUN_0003ea74(DAT_ffffb384,fVar5);
  DAT_ffffb374 = rx8_min_float(fVar5,20.0);
  uVar1 = (uint)DAT_ffffb366;
  if (uVar1 == 1) {
    fVar5 = rx8_min_float(DAT_ffffb36c,DAT_ffffb370);
    arg1 = rx8_min_float(fVar5,DAT_ffffb374);
    uVar1 = extraout_r0;
  }
  DAT_ffffb35c = arg1;
  return uVar1;
}


