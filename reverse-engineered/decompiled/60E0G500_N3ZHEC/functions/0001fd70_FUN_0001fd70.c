/* ROM address: 0x0001fd70; body bytes: 1166; decompiled */

uint FUN_0001fd70(void)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  short sVar4;
  uint uVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar3 = DAT_ffffc6b4;
  bVar2 = DAT_ffffbf38;
  fVar10 = DAT_ffffbf34;
  fVar1 = DAT_ffffadbc;
  fVar12 = DAT_ffffad8c;
  fVar8 = DAT_ffffbf1c;
  fVar9 = DAT_ffffaa10;
  fVar11 = DAT_ffffc12c;
  fVar13 = DAT_ffffb5b8;
  DAT_ffffb1cc = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006a3b0);
  DAT_ffffb1d0 = (float)FUN_00002068(fVar13,&DAT_0006a360);
  DAT_ffffb1d4 = (float)FUN_00002068(fVar13,&DAT_0006a374);
  DAT_ffffb1d8 = (float)FUN_00002068(fVar13,&DAT_0006a388);
  DAT_ffffb1dc = (float)FUN_00002068(fVar13,&DAT_0006a39c);
  if (fVar11 < DAT_ffffb1d0) {
    if (fVar11 < DAT_ffffb1d0 + -0.04) {
      DAT_ffffb226 = '\0';
    }
  }
  else {
    DAT_ffffb226 = '\x01';
  }
  if (fVar11 < DAT_ffffb1d4) {
    if (fVar11 < DAT_ffffb1d4 + -0.04) {
      DAT_ffffb227 = '\0';
    }
  }
  else {
    DAT_ffffb227 = '\x01';
  }
  if (fVar11 < DAT_ffffb1d8) {
    if (fVar11 < DAT_ffffb1d8 + -0.04) {
      DAT_ffffb228 = '\0';
    }
  }
  else {
    DAT_ffffb228 = '\x01';
  }
  if (fVar3 < 950.0) {
    if (fVar3 < 900.0) {
      DAT_ffffb220 = '\0';
    }
  }
  else {
    DAT_ffffb220 = '\x01';
  }
  if (fVar9 < 80.0) {
    if (fVar9 < 78.0) {
      DAT_ffffb221 = '\0';
    }
  }
  else {
    DAT_ffffb221 = '\x01';
  }
  if (fVar9 < -40.0) {
    if (fVar9 < -42.0) {
      DAT_ffffb222 = '\0';
    }
  }
  else {
    DAT_ffffb222 = '\x01';
  }
  if (fVar9 < 200.0) {
    if (fVar9 < 197.0) {
      DAT_ffffb223 = 0;
    }
  }
  else {
    DAT_ffffb223 = 1;
  }
  if (fVar8 < DAT_ffffbf34 * 0.7) {
    if (fVar8 < DAT_ffffbf34 * 0.7 - 0.005) {
      DAT_ffffb224 = '\0';
    }
  }
  else {
    DAT_ffffb224 = '\x01';
  }
  if (fVar13 < 6000.0) {
    if (fVar13 < 5750.0) {
      DAT_ffffb225 = '\0';
    }
  }
  else {
    DAT_ffffb225 = '\x01';
  }
  if (fVar1 < DAT_ffffb1cc) {
    if (fVar1 < DAT_ffffb1cc + -3.0) {
      DAT_ffffb21e = '\0';
    }
  }
  else {
    DAT_ffffb21e = '\x01';
  }
  if (fVar12 < 10.0) {
    if (fVar12 < 0.0) {
      DAT_ffffb21f = '\0';
    }
  }
  else {
    DAT_ffffb21f = '\x01';
  }
  if (DAT_ffffcda0 == '\0') {
    ppuVar6 = (undefined **)&DAT_0006a450;
  }
  else {
    ppuVar6 = &PTR_DAT_0006a45c;
  }
  DAT_ffffb1b8 = FUN_000020c4(fVar13,ppuVar6);
  if (DAT_ffffb21f == '\x01') {
    puVar7 = &DAT_0006a468;
  }
  else {
    puVar7 = &DAT_0006a474;
  }
  DAT_ffffb1ba = FUN_000020c4(fVar13,puVar7);
  sVar4 = DAT_ffffb1ba;
  if ((DAT_ffffb21e == '\x01') && (sVar4 = DAT_ffffb1bc, DAT_ffffb1bc != 0)) {
    sVar4 = DAT_ffffb1bc + -1;
  }
  DAT_ffffb1bc = sVar4;
  if ((((DAT_ffffb1dc <= fVar11) || (DAT_ffffb220 == '\x01')) ||
      ((DAT_ffffb221 == '\0' && ((DAT_ffffb222 == '\x01' && (DAT_ffffb224 == '\x01')))))) ||
     ((DAT_ffffb1cc <= fVar1 && (DAT_ffffb1bc == 0)))) {
    DAT_ffffb1be = 0;
  }
  else if (DAT_ffffb226 == '\x01') {
    if (DAT_ffffb1be != 0) {
      DAT_ffffb1be = DAT_ffffb1be + -1;
    }
  }
  else {
    DAT_ffffb1be = DAT_ffffb1b8;
  }
  if ((DAT_ffffb1be == 0) || ((DAT_ffffb226 != '\x01' && (DAT_ffffb21e != '\x01')))) {
    DAT_ffffb19b = 0;
  }
  else {
    DAT_ffffb19b = 1;
  }
  if (((DAT_ffffb1be == 0) &&
      (((DAT_ffffb1c8 == '\0' && (DAT_ffffb226 == '\x01')) ||
       (((DAT_ffffb1c8 == '\x01' && (DAT_ffffb227 == '\x01')) || (DAT_ffffb21e == '\x01')))))) ||
     ((DAT_ffffb225 == '\x01' || ((DAT_ffffb228 == '\x01' && (DAT_ffffb1c9 == '\0')))))) {
    DAT_ffffb19a = 1;
  }
  else {
    DAT_ffffb19a = 0;
  }
  fVar12 = fVar10 * 0.95;
  if (((DAT_ffffb221 != '\x01') || (fVar13 < 2000.0)) ||
     (((fVar8 < fVar12 || ((DAT_ffffb214 <= DAT_ffffb210 || (DAT_ffffb198 != 0)))) &&
      ((bVar2 != 1 || (DAT_ffffb24b != '\0')))))) {
    if (DAT_ffffb198 != 0) {
      DAT_ffffb198 = DAT_ffffb198 + -1;
    }
  }
  else {
    DAT_ffffb198 = FUN_000020c4(fVar13,&PTR_DAT_0006a4a4);
  }
  uVar5 = (uint)DAT_ffffb223;
  fVar10 = fVar10 * (float)0x3f733333;
  if (((uVar5 != 1) || (fVar13 < 2000.0)) ||
     (((fVar8 < fVar10 || ((DAT_ffffb218 <= DAT_ffffb210 || (DAT_ffffb1b6 != 0)))) &&
      ((uVar5 = (uint)bVar2, uVar5 != 1 || (DAT_ffffb24b != '\0')))))) {
    if (DAT_ffffb1b6 != 0) {
      DAT_ffffb1b6 = DAT_ffffb1b6 + -1;
    }
  }
  else {
    uVar5 = FUN_000020c4(fVar13,&PTR_DAT_0006a4b0);
    DAT_ffffb1b6 = (short)uVar5;
  }
  DAT_ffffb210 = fVar8;
  DAT_ffffb214 = fVar12;
  DAT_ffffb218 = fVar10;
  DAT_ffffb24b = bVar2;
  return uVar5;
}


