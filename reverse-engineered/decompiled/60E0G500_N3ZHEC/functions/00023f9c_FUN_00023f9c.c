/* ROM address: 0x00023f9c; body bytes: 300; decompiled */

void FUN_00023f9c(void)

{
  float *pfVar1;
  undefined1 uVar2;
  float fVar3;
  undefined4 uVar4;
  float arg0;
  
  arg0 = DAT_ffffb3fc + DAT_ffffb314;
  fVar3 = DAT_ffffb314;
  uVar4 = DAT_ffffae54;
  DAT_ffffb488 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006aa38);
  uVar2 = 0;
  if (DAT_ffffb33f == '\x01') {
    if (DAT_ffffa9ea == '\0') {
      pfVar1 = (float *)&DAT_ffffb328;
      fVar3 = DAT_ffffb488;
    }
    else {
      pfVar1 = (float *)&DAT_00075018;
    }
    DAT_ffffb494 = rx8_clamp_float(*pfVar1,fVar3,arg0);
  }
  else if (DAT_ffffb340 == '\x01') {
    DAT_ffffb494 = rx8_max_float(arg0,DAT_ffffb32c);
  }
  else {
    DAT_ffffb48c = rx8_clamp_float(arg0,0.0,84.0);
    fVar3 = (float)FUN_00002068(DAT_ffffb5cc,&DAT_0006aa4c);
    DAT_ffffb49c = (float)FUN_00002068(uVar4,&DAT_0006aa60);
    DAT_ffffb4a0 = (float)FUN_00002068(uVar4,&DAT_0006aa74);
    if (DAT_ffffb48c <= DAT_ffffb49c * fVar3) {
      if (DAT_ffffb48c <= DAT_ffffb49c * fVar3 - 0.5) {
        DAT_ffffb4a4 = '\0';
      }
    }
    else {
      DAT_ffffb4a4 = '\x01';
    }
    if (((DAT_ffffb4a4 == '\0') && (DAT_ffffb5aa == '\0')) &&
       ((DAT_ffffa444 == '\x01' || (DAT_ffffa445 == '\x01')))) {
      DAT_ffffb494 = (fVar3 + 0.0) * DAT_ffffb4a0;
      uVar2 = 1;
    }
    else {
      DAT_ffffb494 = DAT_ffffb48c;
    }
  }
  DAT_ffffb480 = FUN_0005d458(DAT_ffffb494);
  DAT_ffffb492 = uVar2;
  return;
}


