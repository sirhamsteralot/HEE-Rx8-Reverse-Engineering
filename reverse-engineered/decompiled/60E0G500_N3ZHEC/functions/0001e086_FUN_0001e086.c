/* ROM address: 0x0001e086; body bytes: 402; decompiled */

void FUN_0001e086(void)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  float arg0;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = 1.0;
  DAT_ffffafc0 = DAT_ffffaa88;
  DAT_ffffb014 = DAT_ffffb5b8;
  if ((DAT_ffffaa10 < 150.0) || (DAT_ffffb0ed != '\x01')) {
    DAT_ffffb096 = 0;
    DAT_ffffafa4 = 0.0;
    DAT_ffffafb0 = 0.0;
    DAT_ffffafac = 0.0;
    DAT_ffffafb4 = 0.0;
    DAT_ffffafb8 = 0.0;
    DAT_ffffafbc = 0.0;
    fVar7 = DAT_ffffafa4;
    fVar5 = DAT_ffffafbc;
  }
  else {
    DAT_ffffb096 = 1;
    fVar7 = DAT_ffffae70;
    fVar5 = DAT_ffffafa0;
    arg0 = (float)FUN_0003ea74((float)(&DAT_ffffafc0)[DAT_ffffb092] * 30.0,
                               (&DAT_ffffb014)[DAT_ffffb092]);
    DAT_ffffafa8 = rx8_min_float(arg0,200.0);
    if (fVar7 - fVar5 < 0.0) {
      pfVar1 = (float *)&DAT_000701b8;
    }
    else {
      pfVar1 = (float *)&DAT_000701b4;
    }
    DAT_ffffafac = (fVar5 - fVar7) * *pfVar1 * DAT_ffffafa8;
    DAT_ffffafb0 = rx8_clamp_float(DAT_ffffafac + DAT_ffffafb0,-1.0,fVar6);
    DAT_ffffafb4 = DAT_ffffafb0 * 0.12;
    DAT_ffffafb8 = (DAT_ffffafb0 - DAT_ffffb0a8) * 1.0;
    fVar5 = DAT_ffffafbc + DAT_ffffafb0 * 0.0001;
    fVar7 = DAT_ffffafb4 + DAT_ffffafb8 + fVar5;
    if ((0.03 < fVar7) || (fVar7 < -0.03)) {
      fVar7 = rx8_clamp_float(fVar7,-0.03,0.03);
      fVar5 = (fVar7 - DAT_ffffafb4) - DAT_ffffafb8;
    }
  }
  DAT_ffffafbc = fVar5;
  DAT_ffffafa4 = fVar7;
  fVar6 = (float)FUN_0003ea74(fVar6,DAT_ffffae74);
  cVar4 = '\x14';
  uVar3 = 0x13;
  iVar2 = 0x50;
  DAT_ffffafa0 = DAT_ffffafa4 + fVar6;
  do {
    cVar4 = cVar4 + -1;
    *(undefined4 *)((int)&DAT_ffffafc0 + iVar2) = (&DAT_ffffafc0)[uVar3 & 0xff];
    *(undefined4 *)((int)&DAT_ffffb014 + iVar2) = (&DAT_ffffb014)[uVar3 & 0xff];
    iVar2 = iVar2 + -4;
    uVar3 = uVar3 + 0xff;
  } while (cVar4 != '\0');
  DAT_ffffb0a8 = DAT_ffffafb0;
  return;
}


