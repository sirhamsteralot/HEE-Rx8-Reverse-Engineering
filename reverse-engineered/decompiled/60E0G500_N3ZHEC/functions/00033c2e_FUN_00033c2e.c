/* ROM address: 0x00033c2e; body bytes: 198; decompiled */

char FUN_00033c2e(void)

{
  char cVar1;
  float *pfVar2;
  
  cVar1 = DAT_ffffc05b;
  if (DAT_ffffc05b == '\x01') {
    DAT_ffffc094 = 180.0;
  }
  else if ((DAT_ffffc05b == '\x05') || (DAT_ffffc05b == '\x06')) {
    if (DAT_ffffc04c == 'j') {
      pfVar2 = (float *)&DAT_00079680;
    }
    else {
      cVar1 = 'h';
      if (DAT_ffffc04c != 'h') {
        DAT_ffffc094 = 500.0;
        goto LAB_00033c8e;
      }
      pfVar2 = (float *)&DAT_00079684;
    }
    DAT_ffffc094 = *pfVar2;
  }
  else {
    DAT_ffffc094 = 500.0;
  }
LAB_00033c8e:
  if (DAT_ffffc008 < DAT_ffffc094) {
    if (DAT_ffffc008 < DAT_ffffc094 - 5.0) {
      DAT_ffffc0aa = '\0';
    }
  }
  else {
    DAT_ffffc0aa = '\x01';
  }
  if (((DAT_ffffc0aa == '\0') || (cVar1 = '\x01', DAT_ffffb5aa == '\x01')) ||
     ((DAT_ffffc098 == '\x01' && (cVar1 = '\x01', DAT_ffffaa38 < DAT_ffffc090)))) {
    DAT_ffffc098 = '\0';
  }
  else {
    cVar1 = DAT_ffffc0aa;
    if (DAT_ffffc0aa == '\x01') {
      DAT_ffffc098 = '\x01';
    }
  }
  return cVar1;
}


