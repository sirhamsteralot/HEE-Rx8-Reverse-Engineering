/* ROM address: 0x0002b618; body bytes: 792; decompiled */

void FUN_0002b618(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  float fVar7;
  
  cVar6 = DAT_ffffbc6c;
  cVar5 = DAT_ffffbc03;
  cVar4 = DAT_ffffad90;
  cVar3 = DAT_ffffaae0;
  cVar2 = DAT_ffffa428;
  cVar1 = DAT_ffffa41c;
  if (DAT_ffffb5b8 <= 7000.0) {
    if (DAT_ffffb5b8 <= 6900.0) {
      DAT_ffffbc02 = '\0';
    }
  }
  else {
    DAT_ffffbc02 = '\x01';
  }
  if ((DAT_ffffbc05 == '\x01') && (DAT_ffffa41c == '\0')) {
    DAT_ffffbbf0 = 0x1f;
  }
  else if (DAT_ffffbbf0 != 0) {
    DAT_ffffbbf0 = DAT_ffffbbf0 + -1;
  }
  if (DAT_ffffbc1c < 3.0) {
    if (DAT_ffffbc1c < 1.0) {
      DAT_ffffbc03 = '\0';
    }
  }
  else {
    DAT_ffffbc03 = '\x01';
    DAT_ffffbc00 = '\x01';
  }
  if (DAT_ffffbbd0 - DAT_ffffbbd4 < 5.0) {
    if (DAT_ffffbbd0 - DAT_ffffbbd4 < 3.0) {
      DAT_ffffbc04 = '\0';
    }
  }
  else {
    DAT_ffffbc04 = '\x01';
  }
  fVar7 = DAT_ffffbc1c;
  if ((cVar5 == '\x01') && (DAT_ffffbc03 == '\0')) {
    DAT_ffffbc01 = '\x01';
    DAT_ffffbbf2 = 0;
  }
  else {
    DAT_ffffbbf2 = FUN_00002460((int)(short)DAT_ffffbbf2,1);
  }
  if ((DAT_ffffbc06 == '\x01') && (cVar4 == '\0')) {
    DAT_ffffbbf6 = 0x9c;
  }
  else if (DAT_ffffbbf6 != 0) {
    DAT_ffffbbf6 = DAT_ffffbbf6 + -1;
  }
  if ((DAT_ffffbbf0 == 0) && (DAT_ffffbc00 != '\x01')) {
    if ((cVar3 == '\x01') && (fVar7 < 3.0)) {
      DAT_ffffbbda = '\x01';
    }
  }
  else {
    DAT_ffffbbda = '\0';
  }
  if (DAT_ffffbc03 == '\x01') {
    DAT_ffffbbdb = '\0';
  }
  else if ((DAT_ffffbc01 == '\x01') && (0x7c < DAT_ffffbbf2)) {
    DAT_ffffbbdb = '\x01';
  }
  if ((((cVar4 == '\x01') || (DAT_ffffbbf6 != 0)) || (DAT_ffffbc03 == '\0')) ||
     (DAT_ffffbc04 == '\x01')) {
    DAT_ffffbbdc = '\0';
  }
  else if (0x3a9 < DAT_ffffbbf4) {
    DAT_ffffbbdc = '\x01';
  }
  if (cVar6 == '\x01') {
    if (DAT_ffffbc02 == '\0') {
      if (DAT_ffffc68e == '\0') {
        if ((((DAT_ffffbbda == '\x01') && (DAT_ffffbbf8 != 0)) ||
            ((DAT_ffffbbdb == '\x01' && (DAT_ffffbbf8 != 0)))) ||
           ((DAT_ffffbbdc == '\x01' && (0x4e1 < DAT_ffffbbf8)))) {
          DAT_ffffbbd8 = '\x01';
        }
      }
      else if (0x57d < DAT_ffffbbf8) {
        DAT_ffffbbd8 = '\x01';
      }
    }
  }
  else {
    DAT_ffffbbd8 = '\0';
  }
  if (((cVar3 == '\x01') && (((cVar2 == '\0' && (DAT_ffffbbfe < 0x1f)) || (DAT_ffffbbd8 == '\x01')))
      ) || ((DAT_ffffbc7c == '\x01' && (DAT_ffffbc02 == '\x01')))) {
    DAT_ffffbbce = 1;
  }
  else {
    DAT_ffffbbce = 0;
  }
  if (DAT_ffffbc04 == '\x01') {
    DAT_ffffbbf4 = 0;
  }
  else {
    DAT_ffffbbf4 = FUN_00002460((int)(short)DAT_ffffbbf4,1);
  }
  if (cVar6 == '\0') {
    DAT_ffffbbf8 = 0;
  }
  else {
    DAT_ffffbbf8 = FUN_00002460((int)(short)DAT_ffffbbf8,1);
  }
  if ((cVar3 == '\x01') && (cVar2 == '\0')) {
    DAT_ffffbbfe = FUN_00002460((int)(short)DAT_ffffbbfe,1);
  }
  else {
    DAT_ffffbbfe = 0;
  }
  DAT_ffffbc05 = cVar1;
  DAT_ffffbc06 = cVar4;
  return;
}


