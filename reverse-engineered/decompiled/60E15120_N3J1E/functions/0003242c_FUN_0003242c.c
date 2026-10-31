/* ROM address: 0x0003242c; body bytes: 440; decompiled */

void FUN_0003242c(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  
  if ((DAT_ffffbfc6 == '\x01') && (DAT_ffffbc35 == '\0')) {
    DAT_ffffbfc5 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffbfc5 = 0;
    bVar1 = false;
  }
  if ((DAT_ffffbc35 == '\x01') &&
     (((DAT_ffffbfc7 == '\0' && (DAT_ffffbcec == '\x01')) ||
      ((DAT_ffffbfc8 == '\x01' && (DAT_ffffbced == '\0')))))) {
    DAT_ffffbfbd = '\x01';
  }
  if ((((DAT_ffffbcec == '\x01') && (DAT_ffffbced == '\0')) && (DAT_ffffbfbd == '\0')) && (bVar1)) {
    DAT_ffffbfb0 = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffbfb0 = 0;
    bVar2 = false;
  }
  if ((DAT_ffffbfbd == '\x01') && (bVar1)) {
    DAT_ffffbfbd = '\0';
  }
  if (((DAT_ffffbced != '\x01') || (DAT_ffffbfa0 - DAT_ffffbfa4 <= 2.0)) ||
     ((DAT_ffffbfb7 != '\0' || (((DAT_ffffbfc9 != '\0' || (DAT_ffffbfba != '\0')) || (!bVar1)))))) {
    DAT_ffffbfb1 = 0;
    bVar3 = false;
  }
  else {
    DAT_ffffbfb1 = 1;
    bVar3 = true;
  }
  if ((DAT_ffffbfb5 == '\x01') && (bVar1)) {
    DAT_ffffbfb2 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffbfb2 = 0;
    bVar1 = false;
  }
  if ((DAT_ffffbced == '\x01') &&
     (((DAT_ffffbfc9 == '\x01' && (DAT_ffffbfba == '\0')) ||
      ((DAT_ffffbfca == '\x01' && (DAT_ffffbfb9 == '\0')))))) {
    DAT_ffffbfb3 = 1;
    bVar4 = true;
  }
  else {
    DAT_ffffbfb3 = 0;
    bVar4 = false;
  }
  if ((((bVar2) || (bVar3)) || (bVar1)) || (bVar4)) {
    DAT_ffffbfb4 = 1;
  }
  else {
    DAT_ffffbfb4 = 0;
  }
  DAT_ffffbfc7 = DAT_ffffbcec;
  DAT_ffffbfc8 = DAT_ffffbced;
  DAT_ffffbfc6 = DAT_ffffbc35;
  DAT_ffffbfc9 = DAT_ffffbfba;
  DAT_ffffbfca = DAT_ffffbfb9;
  return;
}


