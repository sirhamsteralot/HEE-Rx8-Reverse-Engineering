/* ROM address: 0x000120e4; body bytes: 276; decompiled */

void FUN_000120e4(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  fVar3 = DAT_ffffb188;
  uVar4 = DAT_ffffaa10;
  uVar5 = DAT_ffffc12c;
  uVar6 = DAT_ffffb5b8;
  DAT_ffffa624 = (float)FUN_00002068(DAT_ffffa7bc,&DAT_000697e4);
  DAT_ffffa628 = (float)FUN_000020dc(uVar5,uVar6,&DAT_0006987c);
  DAT_ffffa634 = (float)FUN_00002068(uVar4,&DAT_000697f8);
  DAT_ffffa5f8 = (0.0 - DAT_ffffa628 * DAT_ffffa634) + DAT_ffffa624;
  if (DAT_ffffcda0 == '\0') {
    DAT_ffffa604 = 80.0;
  }
  else {
    DAT_ffffa604 = 11.0;
  }
  if (DAT_ffffb19d == '\x01') {
    DAT_ffffa62c = (float)FUN_000020dc(uVar5,uVar6,&DAT_000698b4);
    fVar2 = rx8_min_float(DAT_ffffa62c,DAT_ffffa604);
    pfVar1 = (float *)&DAT_0006d57c;
  }
  else {
    DAT_ffffa62c = (float)FUN_000020dc(uVar5,uVar6,&DAT_000698d0);
    fVar2 = rx8_min_float(DAT_ffffa62c,DAT_ffffa604);
    pfVar1 = (float *)&DAT_0006d580;
  }
  DAT_ffffa608 = *pfVar1 + fVar2;
  DAT_ffffa630 = (float)FUN_000020dc(uVar5,uVar6,&DAT_00069898);
  DAT_ffffa638 = (float)FUN_000020dc(uVar6,uVar4,&DAT_00069900);
  fVar2 = rx8_min_float(DAT_ffffa630,DAT_ffffa604);
  DAT_ffffa5f0 = rx8_max_float(DAT_ffffa608 * fVar3 + (fVar2 + 0.0) * (1.0 - fVar3),DAT_ffffa638);
  return;
}


