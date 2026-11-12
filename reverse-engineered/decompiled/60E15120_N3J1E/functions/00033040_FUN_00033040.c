/* ROM address: 0x00033040; body bytes: 198; decompiled */

char FUN_00033040(void)

{
  char cVar1;
  float *pfVar2;
  
  cVar1 = DAT_ffffbff3;
  if (DAT_ffffbff3 == '\x01') {
    pfVar2 = (float *)&DAT_000793e0;
  }
  else {
    if ((DAT_ffffbff3 != '\x05') && (DAT_ffffbff3 != '\x06')) {
      DAT_ffffc02c = 500.0;
      goto LAB_000330a0;
    }
    if (DAT_ffffbfe4 == 'j') {
      pfVar2 = (float *)&DAT_000793e4;
    }
    else {
      cVar1 = 'h';
      if (DAT_ffffbfe4 != 'h') {
        DAT_ffffc02c = 500.0;
        goto LAB_000330a0;
      }
      pfVar2 = (float *)&DAT_000793e8;
    }
  }
  DAT_ffffc02c = *pfVar2;
LAB_000330a0:
  if (DAT_ffffbfa0 < DAT_ffffc02c) {
    if (DAT_ffffbfa0 < DAT_ffffc02c - 5.0) {
      DAT_ffffc042 = '\0';
    }
  }
  else {
    DAT_ffffc042 = '\x01';
  }
  if (((DAT_ffffc042 == '\0') || (cVar1 = '\x01', DAT_ffffb53a == '\x01')) ||
     ((DAT_ffffc030 == '\x01' && (cVar1 = '\x01', throttle_position_1_percent_ffffa9b4 < DAT_ffffc028)))) {
    DAT_ffffc030 = '\0';
  }
  else {
    cVar1 = DAT_ffffc042;
    if (DAT_ffffc042 == '\x01') {
      DAT_ffffc030 = '\x01';
    }
  }
  return cVar1;
}


