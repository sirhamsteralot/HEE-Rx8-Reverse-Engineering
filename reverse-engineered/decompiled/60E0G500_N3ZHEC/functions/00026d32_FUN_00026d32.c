/* ROM address: 0x00026d32; body bytes: 392; decompiled */

void FUN_00026d32(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = 2.5;
  fVar5 = -2.5;
  fVar2 = rx8_clamp_float(DAT_ffffb60c - DAT_ffffb6cc,-2.5,2.5);
  fVar3 = fVar2 - DAT_ffffb638;
  DAT_ffffb638 = fVar2;
  DAT_ffffb63c = rx8_clamp_float(fVar3,fVar5,fVar4);
  fVar2 = 0.0;
  if (DAT_ffffb683 == '\x01') {
    DAT_ffffb610 = (float)FUN_00002068(DAT_ffffb608,&DAT_0006aabc);
  }
  else {
    DAT_ffffb610 = 0.0;
  }
  if ((DAT_ffffb5a4 == '\x01') && (DAT_ffffb5aa == '\0')) {
    pfVar1 = (float *)&DAT_00075230;
    DAT_ffffb670 = 406.25;
  }
  else {
    DAT_ffffb670 = 700.0;
    pfVar1 = (float *)&DAT_00075228;
  }
  DAT_ffffb674 = *pfVar1;
  if (DAT_ffffa424 == 0) {
    DAT_ffffb640 = DAT_ffffb610 * 0.5;
  }
  else {
    fVar3 = (float)FUN_0003ea74(DAT_ffffb5b8 - DAT_ffffb670,DAT_ffffb674 - DAT_ffffb670);
    fVar3 = rx8_clamp_float(fVar3,0.1,1.0);
    DAT_ffffb640 = DAT_ffffb610 * fVar3;
  }
  fVar4 = DAT_ffffb638 * 0.2;
  fVar3 = DAT_ffffb63c * 0.0;
  if (DAT_ffffb684 == '\x01') {
    DAT_ffffb644 = rx8_clamp_float(DAT_ffffb638 * 10.0,-125.0,4.8828);
    fVar4 = rx8_clamp_float(fVar4,-0.1,0.0343);
    DAT_ffffb648 = rx8_clamp_float(DAT_ffffb648 + fVar4,fVar2,DAT_ffffb610);
    fVar4 = 249.02;
    fVar5 = -125.0;
  }
  else {
    fVar5 = -125.0;
    DAT_ffffb644 = rx8_clamp_float(DAT_ffffb638 * 10.0,-125.0,125.0);
    fVar4 = rx8_clamp_float(fVar4,fVar5,125.0);
    DAT_ffffb648 = rx8_clamp_float(DAT_ffffb648 + fVar4,fVar2,DAT_ffffb610);
    fVar4 = 125.0;
  }
  DAT_ffffb64c = rx8_clamp_float(fVar3,fVar5,fVar4);
  DAT_ffffb650 = rx8_clamp_float(DAT_ffffb644 + DAT_ffffb648 + DAT_ffffb64c,fVar2,DAT_ffffb640);
  return;
}


