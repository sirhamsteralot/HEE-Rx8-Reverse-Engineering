/* ROM address: 0x0001d3da; body bytes: 402; decompiled */

void FUN_0001d3da(void)

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
  DAT_ffffaf48 = mass_air_flow_ffffa9ec;
  DAT_ffffaf9c = engine_speed_rpm_ffffb548;
  if ((inferred_coolant_temperature_ffffa98c < 150.0) || (DAT_ffffb07d != '\x01')) {
    DAT_ffffb01e = 0;
    DAT_ffffaf2c = 0.0;
    DAT_ffffaf38 = 0.0;
    DAT_ffffaf34 = 0.0;
    DAT_ffffaf3c = 0.0;
    DAT_ffffaf40 = 0.0;
    DAT_ffffaf44 = 0.0;
    fVar7 = DAT_ffffaf2c;
    fVar5 = DAT_ffffaf44;
  }
  else {
    DAT_ffffb01e = 1;
    fVar7 = DAT_ffffadf8;
    fVar5 = DAT_ffffaf28;
    arg0 = (float)rx8_divide_with_zero_fallback
                            ((float)(&DAT_ffffaf48)[DAT_ffffb01a] * 30.0,
                             (&DAT_ffffaf9c)[DAT_ffffb01a]);
    DAT_ffffaf30 = rx8_min_float(arg0,200.0);
    if (fVar7 - fVar5 < 0.0) {
      pfVar1 = (float *)&DAT_0006f68c;
    }
    else {
      pfVar1 = (float *)&DAT_0006f688;
    }
    DAT_ffffaf34 = (fVar5 - fVar7) * *pfVar1 * DAT_ffffaf30;
    DAT_ffffaf38 = rx8_clamp_float(DAT_ffffaf34 + DAT_ffffaf38,-1.0,fVar6);
    DAT_ffffaf3c = DAT_ffffaf38 * 0.12;
    DAT_ffffaf40 = (DAT_ffffaf38 - DAT_ffffb038) * 1.0;
    fVar5 = DAT_ffffaf44 + DAT_ffffaf38 * 0.0001;
    fVar7 = DAT_ffffaf3c + DAT_ffffaf40 + fVar5;
    if ((0.03 < fVar7) || (fVar7 < -0.03)) {
      fVar7 = rx8_clamp_float(fVar7,-0.03,0.03);
      fVar5 = (fVar7 - DAT_ffffaf3c) - DAT_ffffaf40;
    }
  }
  DAT_ffffaf44 = fVar5;
  DAT_ffffaf2c = fVar7;
  fVar6 = (float)rx8_divide_with_zero_fallback(fVar6,lambda_target_ffffadfc);
  cVar4 = '\x14';
  uVar3 = 0x13;
  iVar2 = 0x50;
  DAT_ffffaf28 = DAT_ffffaf2c + fVar6;
  do {
    cVar4 = cVar4 + -1;
    *(undefined4 *)((int)&DAT_ffffaf48 + iVar2) = (&DAT_ffffaf48)[uVar3 & 0xff];
    *(undefined4 *)((int)&DAT_ffffaf9c + iVar2) = (&DAT_ffffaf9c)[uVar3 & 0xff];
    iVar2 = iVar2 + -4;
    uVar3 = uVar3 + 0xff;
  } while (cVar4 != '\0');
  DAT_ffffb038 = DAT_ffffaf38;
  return;
}


