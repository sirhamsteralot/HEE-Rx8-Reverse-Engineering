/* ROM address: 0x0002035a; body bytes: 892; decompiled */

char FUN_0002035a(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar4 = DAT_ffffadbc;
  fVar5 = DAT_ffffc12c;
  fVar6 = DAT_ffffb5b8;
  DAT_ffffb1f8 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006a414);
  DAT_ffffb1fc = (float)FUN_00002068(fVar6,&DAT_0006a428);
  if (fVar4 < 78.0) {
    if (fVar4 < 75.0) {
      DAT_ffffb235 = '\0';
    }
  }
  else {
    DAT_ffffb235 = '\x01';
  }
  if (fVar4 <= 100.0) {
    if (fVar4 <= 97.0) {
      DAT_ffffb239 = '\0';
    }
  }
  else {
    DAT_ffffb239 = '\x01';
  }
  if (fVar5 < DAT_ffffb1f8) {
    if (fVar5 < DAT_ffffb1f8 - 0.04) {
      DAT_ffffb236 = '\0';
    }
  }
  else {
    DAT_ffffb236 = '\x01';
  }
  if (fVar5 <= DAT_ffffb1fc) {
    if (fVar5 <= DAT_ffffb1fc - 0.04) {
      DAT_ffffb23a = '\0';
    }
  }
  else {
    DAT_ffffb23a = '\x01';
  }
  if (fVar6 < 5500.0) {
    if (fVar6 < 5300.0) {
      DAT_ffffb237 = '\0';
    }
  }
  else {
    DAT_ffffb237 = '\x01';
  }
  if (fVar6 <= 10000.0) {
    if (fVar6 <= 9800.0) {
      DAT_ffffb23b = '\0';
    }
  }
  else {
    DAT_ffffb23b = '\x01';
  }
  if (fVar6 < 5500.0) {
    if (fVar6 < 5300.0) {
      DAT_ffffb238 = '\0';
    }
  }
  else {
    DAT_ffffb238 = '\x01';
  }
  if (fVar6 <= 10000.0) {
    if (fVar6 <= 9800.0) {
      DAT_ffffb23c = '\0';
    }
  }
  else {
    DAT_ffffb23c = '\x01';
  }
  DAT_ffffb1f0 = (float)FUN_00002068(fVar6,&DAT_0006a3ec);
  DAT_ffffb1f4 = (float)FUN_00002068(fVar6,&DAT_0006a400);
  if (fVar4 < 78.0) {
    if (fVar4 < 75.0) {
      DAT_ffffb22d = '\0';
    }
  }
  else {
    DAT_ffffb22d = '\x01';
  }
  if (fVar4 <= 100.0) {
    if (fVar4 <= 97.0) {
      DAT_ffffb231 = '\0';
    }
  }
  else {
    DAT_ffffb231 = '\x01';
  }
  if (fVar5 < DAT_ffffb1f0) {
    if (fVar5 < DAT_ffffb1f0 - 0.04) {
      DAT_ffffb22e = '\0';
    }
  }
  else {
    DAT_ffffb22e = '\x01';
  }
  if (fVar5 <= DAT_ffffb1f4) {
    if (fVar5 <= DAT_ffffb1f4 - 0.04) {
      DAT_ffffb232 = '\0';
    }
  }
  else {
    DAT_ffffb232 = '\x01';
  }
  if (fVar6 < 5500.0) {
    if (fVar6 < 5300.0) {
      DAT_ffffb22f = '\0';
    }
  }
  else {
    DAT_ffffb22f = '\x01';
  }
  if (fVar6 <= 10000.0) {
    if (fVar6 <= 9800.0) {
      DAT_ffffb233 = '\0';
    }
  }
  else {
    DAT_ffffb233 = '\x01';
  }
  if (fVar6 < 5500.0) {
    if (fVar6 < 5300.0) {
      DAT_ffffb230 = '\0';
    }
  }
  else {
    DAT_ffffb230 = '\x01';
  }
  if (fVar6 <= 10000.0) {
    if (fVar6 <= 9800.0) {
      DAT_ffffb234 = '\0';
    }
  }
  else {
    DAT_ffffb234 = '\x01';
  }
  if (((((DAT_ffffb235 == '\x01') && (DAT_ffffb239 == '\0')) && (DAT_ffffb237 == '\x01')) &&
      (DAT_ffffb23b == '\0')) ||
     (((DAT_ffffb236 == '\x01' && (DAT_ffffb23a == '\0')) &&
      ((DAT_ffffb238 == '\x01' && (DAT_ffffb23c == '\0')))))) {
    DAT_ffffb1c6 = 1;
    bVar2 = true;
    DAT_ffffb1c5 = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffb1c6 = 0;
    bVar2 = false;
    if ((((DAT_ffffb22d == '\x01') && (DAT_ffffb231 == '\0')) &&
        ((DAT_ffffb22f == '\x01' && (DAT_ffffb233 == '\0')))) ||
       ((((DAT_ffffb22e == '\x01' && (DAT_ffffb232 == '\0')) && (DAT_ffffb230 == '\x01')) &&
        (DAT_ffffb234 == '\0')))) {
      DAT_ffffb1c5 = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffb1c5 = 0;
      bVar1 = false;
    }
  }
  if ((bVar1) || (bVar2)) {
    DAT_ffffb1c2 = 1;
  }
  else {
    DAT_ffffb1c2 = 0;
  }
  if (fVar5 < 0.6) {
    if (fVar5 < 0.56) {
      DAT_ffffb23d = '\0';
    }
  }
  else {
    DAT_ffffb23d = '\x01';
  }
  if (fVar6 < 6000.0) {
    if (fVar6 < 5800.0) {
      DAT_ffffb23e = '\0';
    }
  }
  else {
    DAT_ffffb23e = '\x01';
  }
  cVar3 = '\x01';
  if ((DAT_ffffb23d == '\x01') || (cVar3 = DAT_ffffb23e, DAT_ffffb23e == '\x01')) {
    DAT_ffffb1c3 = 1;
  }
  else {
    DAT_ffffb1c3 = 0;
  }
  return cVar3;
}


