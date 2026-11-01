/* ROM address: 0x00019e30; body bytes: 652; decompiled */

uint FUN_00019e30(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar8 = DAT_ffffaa44;
  fVar5 = rx8_absolute_difference(DAT_ffffaa44,0.0);
  cVar3 = DAT_ffffccdc;
  cVar2 = DAT_ffffccdb;
  if ((DAT_ffffaa5e == 0) && (DAT_ffffaa7a == '\x01')) {
    DAT_ffffaa5c = '\0';
  }
  else if ((-0.5 <= fVar8) && (fVar8 < -0.3)) {
    DAT_ffffaa5c = '\x01';
  }
  if ((40.0 <= DAT_ffffaa38) || ((DAT_ffffaa5e == 0 && (DAT_ffffaa7a == '\x01')))) {
    DAT_ffffaa5d = '\0';
  }
  else if (5.0 <= DAT_ffffaa38) {
    DAT_ffffaa5d = '\x01';
  }
  DAT_ffffaa7a = DAT_ffffaa5e;
  if ((((DAT_ffffaa5e == 1) && (DAT_ffffaa74 == 0x177)) || (DAT_ffffaa38 < 0.0)) ||
     (((5.0 <= DAT_ffffaa38 || (DAT_ffffccdb == '\x01')) || (DAT_ffffccdc == '\x01')))) {
    DAT_ffffaa5e = 0;
  }
  else if ((DAT_ffffaa5c == '\x01') && (DAT_ffffaa5d == '\x01')) {
    DAT_ffffaa5e = 1;
  }
  fVar8 = DAT_ffffaa24;
  fVar9 = DAT_ffffaa2c;
  if (DAT_ffffaa5e == 1) {
    DAT_ffffaa74 = FUN_00002460((int)DAT_ffffaa74,1);
  }
  else {
    DAT_ffffaa74 = 0;
  }
  if ((cVar2 == '\x01') || (cVar3 == '\x01')) {
    FUN_0003ec20(&DAT_ffff8090);
    FUN_0003ec20(0x412db22d,&DAT_ffff8098);
    uVar4 = FUN_0003ebc0(&DAT_ffff80a0,0);
  }
  else {
    uVar4 = (uint)DAT_ffffaa5e;
    if (uVar4 == 1) {
      fVar6 = (float)FUN_0003eb72(0x412db22d,&DAT_ffff8090);
      fVar7 = (float)FUN_0003eb72(0x412db22d,&DAT_ffff8098);
      if ((DAT_ffffaa7a == 0) && (0x176 < DAT_ffffaa76)) {
        fVar8 = rx8_min_float(10.856,fVar6 + 0.01);
        FUN_0003ec20(fVar8,&DAT_ffff8090);
        fVar8 = rx8_min_float(10.856,fVar7 + 0.01);
        uVar4 = FUN_0003ec20(fVar8,&DAT_ffff8098);
      }
      else {
        bVar1 = fVar8 <= fVar6;
        if (bVar1) {
          fVar6 = rx8_max_float(fVar8,fVar6 - 0.005);
          fVar6 = rx8_max_float(9.626,fVar6);
          FUN_0003ec20(fVar6,&DAT_ffff8090);
        }
        uVar4 = (uint)bVar1;
        if (fVar9 <= fVar7) {
          fVar7 = rx8_max_float(fVar9,fVar7 - 0.005);
          fVar7 = rx8_max_float(9.626,fVar7);
          FUN_0003ec20(fVar7,&DAT_ffff8098);
          uVar4 = 1;
        }
        if ((((uVar4 == 1) && (fVar6 - fVar8 < 0.032)) && (fVar7 - fVar9 < 0.032)) &&
           ((fVar5 <= 0.3 && (uVar4 = 0x19, 0x18 < DAT_ffffaa78)))) {
          uVar4 = FUN_0003ebc0(&DAT_ffff80a0,1);
        }
      }
    }
  }
  if (DAT_ffffaa5e == 0) {
    uVar4 = FUN_00002460((int)(short)DAT_ffffaa76,1);
    DAT_ffffaa76 = (ushort)uVar4;
  }
  else {
    DAT_ffffaa76 = 0;
  }
  if (0.3 < fVar5) {
    DAT_ffffaa78 = 0;
  }
  else {
    uVar4 = FUN_00002460((int)(short)DAT_ffffaa78,1);
    DAT_ffffaa78 = (ushort)uVar4;
  }
  return uVar4;
}


