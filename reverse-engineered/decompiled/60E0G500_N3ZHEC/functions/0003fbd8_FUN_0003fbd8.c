/* ROM address: 0x0003fbd8; body bytes: 484; decompiled */

void FUN_0003fbd8(void)

{
  char cVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  cVar2 = DAT_ffffd201;
  cVar1 = DAT_ffffb0ed;
  fVar3 = DAT_ffffaa88;
  fVar4 = DAT_ffffad98;
  fVar5 = DAT_ffffb140;
  fVar6 = DAT_ffffae64;
  if ((((0.4 <= DAT_ffffad98) || ((DAT_ffffae64 < 0.8 && (0x9b < DAT_ffffc73e)))) ||
      ((1.2 <= DAT_ffffae64 && (0x9b < DAT_ffffc740)))) ||
     (((DAT_ffffb140 < -0.5 || (0.5 <= DAT_ffffb140)) || (DAT_ffffd201 == '\x01')))) {
    DAT_ffffc738 = 0;
  }
  else if (((0.8 <= DAT_ffffae64) && (DAT_ffffae64 < 1.2)) &&
          ((DAT_ffffb0ed == '\x01' &&
           ((10.0 <= DAT_ffffaa88 &&
            (DAT_ffffc738 = FUN_00002460((int)(short)DAT_ffffc738,1), 0xf423 < DAT_ffffc738)))))) {
    DAT_ffffc738 = 0xf424;
  }
  if (((fVar4 < 0.85) || ((fVar6 < 0.8 && (0x9b < DAT_ffffc73e)))) ||
     (((1.2 <= fVar6 && (0x9b < DAT_ffffc740)) ||
      (((fVar5 < -0.5 || (0.5 <= fVar5)) || (cVar2 == '\x01')))))) {
    DAT_ffffc73a = 0;
  }
  else if (((0.8 <= fVar6) && (fVar6 < 1.2)) &&
          ((cVar1 == '\x01' &&
           ((10.0 <= fVar3 &&
            (DAT_ffffc73a = FUN_00002460((int)(short)DAT_ffffc73a,1), 0xf423 < DAT_ffffc73a)))))) {
    DAT_ffffc73a = 0xf424;
  }
  if ((cVar2 != '\0') || (fVar4 < 1.2)) {
    DAT_ffffc73c = 0;
  }
  else {
    DAT_ffffc73c = FUN_00002460((int)(short)DAT_ffffc73c,1);
    if (0xf423 < DAT_ffffc73c) {
      DAT_ffffc73c = 0xf424;
    }
  }
  if (0.8 <= fVar6) {
    DAT_ffffc73e = 0;
  }
  else {
    DAT_ffffc73e = FUN_00002460((int)(short)DAT_ffffc73e,1);
  }
  if (fVar6 < 1.2) {
    DAT_ffffc740 = 0;
  }
  else {
    DAT_ffffc740 = FUN_00002460((int)(short)DAT_ffffc740,1);
  }
  return;
}


