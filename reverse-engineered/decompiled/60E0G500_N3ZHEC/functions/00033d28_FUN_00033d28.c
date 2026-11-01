/* ROM address: 0x00033d28; body bytes: 444; decompiled */

void FUN_00033d28(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  float arg0;
  float fVar5;
  float fVar6;
  float fVar7;
  float arg2;
  
  cVar4 = DAT_ffffc098;
  cVar3 = DAT_ffffbc33;
  bVar2 = DAT_ffffbc31;
  bVar1 = DAT_ffffbc30;
  fVar6 = DAT_ffffc008 - DAT_ffffc094;
  fVar7 = DAT_ffffc094 - DAT_ffffc008;
  arg2 = 100.0;
  if (DAT_ffffc098 == '\x01') {
    if ((DAT_ffffc0a8 == 0) || (DAT_ffffc0ab == '\0')) {
      fVar5 = DAT_ffffaa38;
      if ((DAT_ffffbc33 != '\x01') ||
         ((arg0 = DAT_ffffc09c, 0xfd < DAT_ffffbc30 && (0xfd < DAT_ffffbc31)))) {
        arg0 = (float)FUN_00002068(fVar6,&DAT_0006b368);
      }
      DAT_ffffc09c = rx8_clamp_float(arg0,0.0,100.0);
      if (DAT_ffffc0ab == '\0') {
        fVar5 = fVar5 - 10.0;
      }
      else {
        fVar5 = DAT_ffffc0a0;
        if (((((fVar7 < -0.25) || (0.25 <= fVar7)) && (0.0 <= DAT_ffffc090)) &&
            (DAT_ffffc090 < 100.0)) && ((cVar3 != '\x01' || ((0xfd < bVar1 && (0xfd < bVar2)))))) {
          DAT_ffffc0a4 = (float)FUN_00002068(fVar6,&DAT_0006b37c);
          fVar5 = DAT_ffffc0a0 + DAT_ffffc0a4;
        }
      }
      DAT_ffffc0a0 = rx8_clamp_float(fVar5,0.0,100.0);
      DAT_ffffc090 = rx8_clamp_float(DAT_ffffc09c + DAT_ffffc0a0,25.0,arg2);
      DAT_ffffc0a8 = 0x10;
    }
    if (DAT_ffffc0a8 != 0) {
      DAT_ffffc0a8 = DAT_ffffc0a8 + -1;
    }
  }
  else {
    if (DAT_ffffaa38 <= DAT_ffffc090) {
      DAT_ffffc09c = 0.0;
      DAT_ffffc0a0 = 100.0;
      DAT_ffffc090 = 100.0;
    }
    else {
      DAT_ffffc09c = rx8_clamp_float(DAT_ffffc09c + 0.3,0.0,100.0);
      DAT_ffffc0a0 = rx8_clamp_float(DAT_ffffc0a0 + 0.3,0.0,100.0);
      DAT_ffffc090 = rx8_clamp_float(DAT_ffffc09c + DAT_ffffc0a0,25.0,arg2);
    }
    DAT_ffffc0a8 = 0;
  }
  DAT_ffffc0ab = cVar4;
  return;
}


