/* ROM address: 0x0004dc52; body bytes: 448; decompiled */

void FUN_0004dc52(void)

{
  float fVar1;
  float fVar2;
  float arg1;
  float arg1_00;
  float arg1_01;
  float arg1_02;
  float fVar3;
  float arg0;
  float arg0_00;
  float arg0_01;
  float arg0_02;
  undefined4 uVar4;
  float fVar5;
  
  fVar5 = 0.0;
  uVar4 = DAT_ffffbc1c;
  if (DAT_ffffcf70 == '\0') {
    DAT_ffffcf34 = 0.0;
    DAT_ffffcf3c = 0.0;
    DAT_ffffcf44 = 0.0;
    DAT_ffffcf4c = 0.0;
  }
  else {
    if (DAT_ffffcf8c != '\0') {
      if (DAT_ffffcfae == '\0') {
        DAT_ffffcf34 = DAT_ffffcf30;
      }
      else {
        DAT_ffffcf34 = rx8_min_float(DAT_ffffcf30,DAT_ffffcf34);
      }
    }
    if (DAT_ffffcf8f != '\0') {
      if (DAT_ffffcfaf == '\0') {
        DAT_ffffcf3c = DAT_ffffcf30;
      }
      else {
        DAT_ffffcf3c = rx8_min_float(DAT_ffffcf30,DAT_ffffcf3c);
      }
    }
    if (DAT_ffffcf92 != '\0') {
      if (DAT_ffffcfb0 == '\0') {
        DAT_ffffcf44 = DAT_ffffcf30;
      }
      else {
        DAT_ffffcf44 = rx8_min_float(DAT_ffffcf30,DAT_ffffcf44);
      }
    }
    if (DAT_ffffcf95 != '\0') {
      if (DAT_ffffcfb1 == '\0') {
        DAT_ffffcf4c = DAT_ffffcf30;
      }
      else {
        DAT_ffffcf4c = rx8_min_float(DAT_ffffcf30,DAT_ffffcf4c);
      }
    }
  }
  arg0 = DAT_ffffcf34 - 1.5;
  arg1 = (float)FUN_00002068(uVar4,&DAT_0006bf3c);
  arg0_00 = DAT_ffffcf3c - 1.5;
  arg1_00 = (float)FUN_00002068(uVar4,&DAT_0006bf54);
  arg0_01 = DAT_ffffcf44 - 1.5;
  arg1_01 = (float)FUN_00002068(uVar4,&DAT_0006bf6c);
  arg0_02 = DAT_ffffcf4c - 1.5;
  arg1_02 = (float)FUN_00002068(uVar4,&DAT_0006bf84);
  fVar1 = fVar5;
  fVar2 = fVar5;
  fVar3 = fVar5;
  if (DAT_ffffcf70 != '\0') {
    if (DAT_ffffcf8c != '\0') {
      DAT_ffffcf38 = rx8_max_float(arg0,arg1);
    }
    if (DAT_ffffcf8f != '\0') {
      DAT_ffffcf40 = rx8_max_float(arg0_00,arg1_00);
    }
    if (DAT_ffffcf92 != '\0') {
      DAT_ffffcf48 = rx8_max_float(arg0_01,arg1_01);
    }
    fVar5 = DAT_ffffcf38;
    fVar1 = DAT_ffffcf40;
    fVar2 = DAT_ffffcf48;
    fVar3 = DAT_ffffcf50;
    if (DAT_ffffcf95 != '\0') {
      fVar3 = rx8_max_float(arg0_02,arg1_02);
      fVar5 = DAT_ffffcf38;
      fVar1 = DAT_ffffcf40;
      fVar2 = DAT_ffffcf48;
    }
  }
  DAT_ffffcf50 = fVar3;
  DAT_ffffcf48 = fVar2;
  DAT_ffffcf40 = fVar1;
  DAT_ffffcf38 = fVar5;
  DAT_ffffcfae = DAT_ffffcf8c;
  DAT_ffffcfaf = DAT_ffffcf8f;
  DAT_ffffcfb0 = DAT_ffffcf92;
  DAT_ffffcfb1 = DAT_ffffcf95;
  return;
}


