/* ROM address: 0x00011f58; body bytes: 276; decompiled */

void FUN_00011f58(void)

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
  DAT_ffffa60c = (float)FUN_00002068(DAT_ffffa7bc,&DAT_000697bc);
  DAT_ffffa610 = (float)FUN_000020dc(uVar5,uVar6,&DAT_0006980c);
  DAT_ffffa61c = (float)FUN_00002068(uVar4,&DAT_000697d0);
  DAT_ffffa5f4 = (0.0 - DAT_ffffa610 * DAT_ffffa61c) + DAT_ffffa60c;
  if (DAT_ffffcda0 == '\0') {
    DAT_ffffa5fc = 80.0;
  }
  else {
    DAT_ffffa5fc = 16.0;
  }
  if (DAT_ffffb19d == '\x01') {
    DAT_ffffa614 = (float)FUN_000020dc(uVar5,uVar6,&DAT_00069844);
    fVar2 = rx8_min_float(DAT_ffffa614,DAT_ffffa5fc);
    pfVar1 = (float *)&DAT_0006d564;
  }
  else {
    DAT_ffffa614 = (float)FUN_000020dc(uVar5,uVar6,&DAT_00069860);
    fVar2 = rx8_min_float(DAT_ffffa614,DAT_ffffa5fc);
    pfVar1 = (float *)&DAT_0006d568;
  }
  DAT_ffffa600 = *pfVar1 + fVar2;
  DAT_ffffa618 = (float)FUN_000020dc(uVar5,uVar6,&DAT_00069828);
  DAT_ffffa620 = (float)FUN_000020dc(uVar6,uVar4,&DAT_000698ec);
  fVar2 = rx8_min_float(DAT_ffffa618,DAT_ffffa5fc);
  DAT_ffffa5ec = rx8_max_float(DAT_ffffa600 * fVar3 + (fVar2 + 0.0) * (1.0 - fVar3),DAT_ffffa620);
  return;
}


