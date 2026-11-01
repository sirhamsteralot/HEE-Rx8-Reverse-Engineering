/* ROM address: 0x00033010; body bytes: 440; decompiled */

void FUN_00033010(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  
  if ((DAT_ffffc02e == '\x01') && (DAT_ffffbca1 == '\0')) {
    DAT_ffffc02d = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffc02d = 0;
    bVar1 = false;
  }
  if ((DAT_ffffbca1 == '\x01') &&
     (((DAT_ffffc02f == '\0' && (DAT_ffffbd58 == '\x01')) ||
      ((DAT_ffffc030 == '\x01' && (DAT_ffffbd59 == '\0')))))) {
    DAT_ffffc025 = '\x01';
  }
  if ((((DAT_ffffbd58 == '\x01') && (DAT_ffffbd59 == '\0')) && (DAT_ffffc025 == '\0')) && (bVar1)) {
    DAT_ffffc018 = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffc018 = 0;
    bVar2 = false;
  }
  if ((DAT_ffffc025 == '\x01') && (bVar1)) {
    DAT_ffffc025 = '\0';
  }
  if (((DAT_ffffbd59 != '\x01') || (DAT_ffffc008 - DAT_ffffc00c <= 2.0)) ||
     ((DAT_ffffc01f != '\0' || (((DAT_ffffc031 != '\0' || (DAT_ffffc022 != '\0')) || (!bVar1)))))) {
    DAT_ffffc019 = 0;
    bVar3 = false;
  }
  else {
    DAT_ffffc019 = 1;
    bVar3 = true;
  }
  if ((DAT_ffffc01d == '\x01') && (bVar1)) {
    DAT_ffffc01a = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffc01a = 0;
    bVar1 = false;
  }
  if ((DAT_ffffbd59 == '\x01') &&
     (((DAT_ffffc031 == '\x01' && (DAT_ffffc022 == '\0')) ||
      ((DAT_ffffc032 == '\x01' && (DAT_ffffc021 == '\0')))))) {
    DAT_ffffc01b = 1;
    bVar4 = true;
  }
  else {
    DAT_ffffc01b = 0;
    bVar4 = false;
  }
  if ((((bVar2) || (bVar3)) || (bVar1)) || (bVar4)) {
    DAT_ffffc01c = 1;
  }
  else {
    DAT_ffffc01c = 0;
  }
  DAT_ffffc02f = DAT_ffffbd58;
  DAT_ffffc030 = DAT_ffffbd59;
  DAT_ffffc02e = DAT_ffffbca1;
  DAT_ffffc031 = DAT_ffffc022;
  DAT_ffffc032 = DAT_ffffc021;
  return;
}


