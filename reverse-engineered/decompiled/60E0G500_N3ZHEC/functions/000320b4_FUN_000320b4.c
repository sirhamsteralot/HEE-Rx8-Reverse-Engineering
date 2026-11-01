/* ROM address: 0x000320b4; body bytes: 252; decompiled */

void calculate_air_charge(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = 60.0;
  DAT_ffffbfd0 = (DAT_ffffb5b8 * DAT_ffffc12c) / 38.07;
  fVar4 = DAT_ffffc12c;
  fVar7 = DAT_ffffb5b8;
  fVar2 = (float)FUN_00002068(DAT_ffffbfd0,&DAT_0006b16c);
  fVar3 = (float)FUN_00002068(DAT_ffffb600,&DAT_0006b158);
  DAT_ffffbfac = fVar2 * fVar3;
  DAT_ffffbfb4 = (DAT_ffffad8c * 353.0163) / ((DAT_ffffae54 + 273.0) * 101.32);
  fVar7 = fVar7 * fVar6;
  uVar5 = 0;
  fVar2 = 1e-05;
  cVar1 = FUN_00002440(fVar7,0,0x3727c5ac);
  if (cVar1 == '\0') {
    DAT_ffffbfb8 = 2.0;
  }
  else {
    DAT_ffffbfb8 = rx8_min_float((DAT_ffffbfac * 0.6345 * DAT_ffffbfb4) / fVar7,2.0);
  }
  cVar1 = FUN_00002440(fVar4,uVar5,fVar2);
  fVar7 = 50.0;
  if (cVar1 == '\0') {
    DAT_ffffbfbc = 50.0;
  }
  else {
    fVar4 = rx8_first_order_filter(DAT_ffffbfb8 / fVar4,DAT_ffffbfbc,1.0,fVar2);
    DAT_ffffbfbc = rx8_min_float(fVar4,fVar7);
  }
  return;
}


