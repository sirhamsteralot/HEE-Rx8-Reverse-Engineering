/* ROM address: 0x0001c3f8; body bytes: 438; decompiled */

void FUN_0001c3f8(void)

{
  short sVar1;
  char cVar3;
  ushort uVar2;
  char cVar4;
  float fVar5;
  float fVar6;
  float arg0;
  float fVar7;
  float fVar8;
  
  sVar1 = DAT_ffffae02;
  if (DAT_ffffae4b == '\0') {
    DAT_ffffae18 = DAT_ffffade8;
    DAT_ffffae1c = DAT_ffffadec;
    DAT_ffffae4b = '\x01';
  }
  fVar7 = DAT_ffffade8 - 10.0;
  arg0 = DAT_ffffadec;
  fVar8 = DAT_ffffade8;
  fVar5 = rx8_absolute_difference(DAT_ffffade8,DAT_ffffae18);
  fVar6 = rx8_absolute_difference(arg0,DAT_ffffae1c);
  if ((((((DAT_ffffb52c < 80.0) || (DAT_ffffccd8 != '\0')) || (DAT_ffffccd9 != '\0')) ||
       (((DAT_ffffb569 != '\0' || (0.244 <= fVar5)) ||
        ((0.244 <= fVar6 || ((DAT_ffffcd01 != '\x01' || (DAT_ffffb55d != '\x01')))))))) ||
      (DAT_ffffccfc != '\0')) ||
     ((((cVar3 = FUN_0003eaa4(&DAT_ffff8766,0), cVar3 != '\0' || (DAT_ffffb480 <= 90.0)) ||
       (DAT_ffffada8 <= 5.0)) || (DAT_ffffb47c <= fVar7)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00002460((int)sVar1,1);
  }
  fVar5 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
  cVar3 = FUN_0003eaa4(&DAT_ffff80c4,0);
  cVar4 = FUN_0003eaa4(&DAT_ffff80c6,0);
  if (uVar2 < 0x26) {
    if (((cVar3 == '\x01') && (DAT_ffffae45 == '\0')) ||
       ((cVar4 == '\x01' && (DAT_ffffae46 == '\0')))) {
      fVar5 = rx8_min_float(111.0,fVar5 + 1.0);
      uVar2 = 0;
    }
  }
  else {
    fVar5 = rx8_max_float(fVar8 - 10.0,fVar5 - 10.0);
    fVar5 = rx8_max_float(-10.0,fVar5);
    uVar2 = 0;
  }
  FUN_0003ec20(fVar5,&DAT_ffff80b4);
  DAT_ffffae45 = cVar3;
  DAT_ffffae46 = cVar4;
  DAT_ffffae18 = fVar8;
  DAT_ffffae1c = arg0;
  DAT_ffffae02 = uVar2;
  return;
}


