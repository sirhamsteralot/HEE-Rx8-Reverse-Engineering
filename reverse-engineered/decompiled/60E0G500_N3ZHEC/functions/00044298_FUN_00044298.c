/* ROM address: 0x00044298; body bytes: 122; decompiled */

char FUN_00044298(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (DAT_ffffcab4 == '\x01') {
    DAT_ffffca40 = (DAT_ffffca44 + DAT_ffffca60) - DAT_ffffca84;
    DAT_ffffca3c = DAT_ffffca40 - 0.01;
    DAT_ffffca38 = rx8_clamp_float(DAT_ffffca3c,0.0,1.0);
    DAT_ffffca34 = DAT_ffffca38 - DAT_ffffca2c;
    cVar1 = '\x01';
    if (1 < DAT_ffffcaaf) {
      fVar2 = DAT_ffffca30 + DAT_ffffca34;
    }
  }
  else {
    cVar1 = DAT_ffffcab4;
    fVar2 = DAT_ffffca30;
    if (DAT_ffffcaad == '\0') {
      DAT_ffffca3c = 0.0;
    }
  }
  DAT_ffffca30 = fVar2;
  return cVar1;
}


