/* ROM address: 0x0000e910; body bytes: 946; decompiled */

uint FUN_0000e910(void)

{
  undefined4 uVar1;
  byte bVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar5 = DAT_ffffc12c;
  cVar4 = DAT_ffffb5aa;
  fVar3 = DAT_ffffb48c;
  bVar2 = DAT_ffffaada;
  uVar1 = DAT_ffffaa10;
  fVar12 = DAT_ffffa448;
  fVar13 = DAT_ffffb5cc;
  fVar14 = DAT_ffffb5b8;
  DAT_ffffa470 = (float)FUN_00002068(DAT_ffffb5cc,&DAT_0006aa4c);
  DAT_ffffa474 = (float)FUN_00002068(DAT_ffffae54,&DAT_0006aa60);
  DAT_ffffa478 = DAT_ffffa470 * DAT_ffffa474;
  DAT_ffffa47c = (float)FUN_00002068(fVar14,&DAT_000696d8);
  fVar10 = DAT_ffffa47c + 0.015;
  fVar11 = DAT_ffffa44c + fVar12;
  uVar9 = FUN_00002500(0x3f800000,0,(int)DAT_ffffa461);
  DAT_ffffa484 = (float)FUN_000020dc(uVar1,uVar9,&DAT_00069784);
  DAT_ffffa488 = (float)FUN_000020dc(uVar1,uVar9,&DAT_000697a0);
  if (DAT_ffffa47c <= fVar5) {
    if (fVar10 <= fVar5) {
      DAT_ffffa450 = '\0';
    }
  }
  else {
    DAT_ffffa450 = '\x01';
  }
  if (fVar14 < fVar11) {
    if (fVar14 < fVar12) {
      DAT_ffffa49a = '\0';
    }
  }
  else {
    DAT_ffffa49a = '\x01';
  }
  if (fVar13 < fVar11) {
    if (fVar13 < fVar12) {
      DAT_ffffa49b = '\0';
    }
  }
  else {
    DAT_ffffa49b = '\x01';
  }
  if (fVar14 < fVar11 - DAT_ffffa484) {
    if (fVar14 < fVar12 - DAT_ffffa484) {
      DAT_ffffa49c = '\0';
    }
  }
  else {
    DAT_ffffa49c = '\x01';
  }
  if (fVar13 < fVar11 - DAT_ffffa488) {
    if (fVar13 < fVar12 - DAT_ffffa488) {
      DAT_ffffa49d = '\0';
    }
  }
  else {
    DAT_ffffa49d = '\x01';
  }
  if (fVar3 <= DAT_ffffa478) {
    if (fVar3 <= DAT_ffffa478 - 0.5) {
      DAT_ffffa49e = '\0';
    }
  }
  else {
    DAT_ffffa49e = '\x01';
  }
  if (fVar14 < 3000.0) {
    if (fVar14 < 2800.0) {
      DAT_ffffa49f = '\0';
    }
  }
  else {
    DAT_ffffa49f = '\x01';
  }
  if (fVar14 < 3000.0) {
    if (fVar14 < 2800.0) {
      DAT_ffffa4a0 = '\0';
    }
  }
  else {
    DAT_ffffa4a0 = '\x01';
  }
  if (((DAT_ffffa428 == '\x01') && (DAT_ffffd2a6 == '\0')) &&
     ((bVar2 == 1 || (DAT_ffffa450 == '\x01')))) {
    DAT_ffffa463 = '\x01';
  }
  else {
    DAT_ffffa463 = '\0';
  }
  iVar8 = 0;
  if ((DAT_ffffa463 == '\0') || (DAT_ffffa49b == '\0')) {
    iVar8 = 2;
  }
  else if (DAT_ffffa49a == '\x01') {
    iVar8 = 1;
  }
  if ((DAT_ffffb5a4 == '\0') && (DAT_ffffcabc == '\x01')) {
    if (DAT_ffffa49f != '\x01') {
      DAT_ffffa48e = 0;
      goto LAB_0000ebd0;
    }
    puVar7 = &DAT_0006d09a;
  }
  else {
    if (DAT_ffffa4a0 != '\x01') {
      DAT_ffffa48e = 0;
      goto LAB_0000ebd0;
    }
    puVar7 = &DAT_0006d09e;
  }
  DAT_ffffa48e = *puVar7;
LAB_0000ebd0:
  if ((((iVar8 == 2) &&
       (((cVar4 == '\x01' || (DAT_ffffa49d == '\0')) ||
        ((DAT_ffffa49e == '\x01' && ((bVar2 == 0 || (DAT_ffffa49b == '\x01')))))))) ||
      (DAT_ffffa9e8 == '\x01')) || ((DAT_ffffccb1 == '\x01' || (DAT_ffffb33f == '\x01')))) {
    DAT_ffffa465 = '\0';
  }
  else if (((iVar8 == 1) && (DAT_ffffa48e <= DAT_ffffa490)) ||
          ((cVar4 == '\0' &&
           ((((DAT_ffffa49e == '\0' && (DAT_ffffa48e <= DAT_ffffa492)) ||
             ((bVar2 == 1 && ((DAT_ffffa48e <= DAT_ffffa494 && (DAT_ffffa49a == '\0')))))) &&
            (DAT_ffffa49c == '\x01')))))) {
    DAT_ffffa465 = '\x01';
  }
  if (iVar8 == 2) {
    DAT_ffffa464 = 0;
  }
  else if (((iVar8 == 1) && (DAT_ffffa465 == '\x01')) && (DAT_ffffa460 <= DAT_ffffa498)) {
    DAT_ffffa464 = 1;
  }
  if (DAT_ffffa465 == '\x01') {
    DAT_ffffa498 = FUN_00002478((int)(char)DAT_ffffa498,1);
  }
  else {
    DAT_ffffa498 = 0;
  }
  if (iVar8 == 1) {
    DAT_ffffa490 = FUN_00002460((int)(short)DAT_ffffa490,1);
  }
  else {
    DAT_ffffa490 = 0;
  }
  if (DAT_ffffa49e == '\0') {
    DAT_ffffa492 = FUN_00002460((int)(short)DAT_ffffa492,1);
  }
  else {
    DAT_ffffa492 = 0;
  }
  uVar6 = (uint)bVar2;
  if (uVar6 == 1) {
    uVar6 = FUN_00002460((int)(short)DAT_ffffa494,1);
    DAT_ffffa494 = (ushort)uVar6;
  }
  else {
    DAT_ffffa494 = 0;
  }
  return uVar6;
}


