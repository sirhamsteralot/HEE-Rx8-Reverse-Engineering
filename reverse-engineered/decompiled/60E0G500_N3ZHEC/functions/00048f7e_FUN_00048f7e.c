/* ROM address: 0x00048f7e; body bytes: 960; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049186) */
/* WARNING: Removing unreachable block (ram,0x0004918e) */
/* WARNING: Removing unreachable block (ram,0x0004919c) */
/* WARNING: Removing unreachable block (ram,0x000491a6) */
/* WARNING: Removing unreachable block (ram,0x000491b0) */
/* WARNING: Removing unreachable block (ram,0x000491ba) */
/* WARNING: Removing unreachable block (ram,0x000491c6) */
/* WARNING: Removing unreachable block (ram,0x000491d0) */
/* WARNING: Removing unreachable block (ram,0x000491d8) */
/* WARNING: Removing unreachable block (ram,0x000491e0) */

uint FUN_00048f7e(void)

{
  bool bVar1;
  char cVar2;
  char cVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  uint uVar3;
  float fVar11;
  float fVar12;
  float fVar13;
  float arg0;
  
  cVar10 = DAT_ffffb55d;
  fVar11 = DAT_ffffb600;
  fVar13 = DAT_ffffb5b8;
  arg0 = DAT_ffffaa10;
  cVar4 = FUN_0003eaa4(&DAT_ffff8764,0);
  cVar2 = DAT_ffffaae0;
  bVar5 = FUN_0003eaa4(&DAT_ffff80c6,0);
  cVar6 = FUN_0003eaa4(&DAT_ffff80c4,0);
  cVar7 = FUN_0003eaa4(&DAT_ffff812c,0);
  cVar8 = FUN_0003eaa4(&DAT_ffff80c8,0);
  cVar9 = FUN_0003eaa4(&DAT_ffff80ca,1);
  fVar12 = -2.0;
  if (fVar13 < 300.0) {
    if (fVar13 < 200.0) {
      DAT_ffffcd2c = '\0';
    }
  }
  else {
    DAT_ffffcd2c = '\x01';
  }
  if (fVar11 < 6.0) {
    if (fVar11 < 5.8) {
      DAT_ffffcd2d = '\0';
    }
  }
  else {
    DAT_ffffcd2d = '\x01';
  }
  if (arg0 < 100.0) {
    if (arg0 < 98.0) {
      DAT_ffffcd2e = '\0';
    }
  }
  else {
    DAT_ffffcd2e = '\x01';
  }
  if (arg0 < 100.0) {
    if (arg0 < 98.0) {
      DAT_ffffcd2f = '\0';
    }
  }
  else {
    DAT_ffffcd2f = '\x01';
  }
  fVar11 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
  fVar11 = rx8_absolute_difference(arg0,fVar11);
  if (fVar11 < 0.0) {
    if (fVar11 < fVar12) {
      DAT_ffffcd30 = '\0';
    }
  }
  else {
    DAT_ffffcd30 = '\x01';
  }
  if ((((((DAT_ffffcd2c == '\0') && (DAT_ffffcd2d == '\x01')) && (DAT_ffffcd01 == '\x01')) &&
       ((cVar10 == '\x01' && (cVar4 == '\0')))) && (DAT_ffffccd8 == '\0')) &&
     ((DAT_ffffccd9 == '\0' && (DAT_ffffc6ac == '\0')))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((((cVar2 == '\0') && (DAT_ffffccf6 < 0x271)) && (DAT_ffffccfa == 1)) &&
     ((bVar5 == 0 && (bVar1)))) {
    DAT_ffffccfc = 1;
    DAT_ffffccfd = 0;
    DAT_ffffccfe = 0;
    DAT_ffffccff = 0;
    DAT_ffffcd00 = 0;
  }
  else if ((((((cVar2 == '\x01') && (DAT_ffffa42c == '\0')) &&
             ((DAT_ffffcd2e == '\0' || (DAT_ffffcd2f == '\x01')))) &&
            (((DAT_ffffcd30 == '\x01' && (cVar6 == '\0')) && (cVar7 == '\x01')))) || (cVar8 == '\0')
           ) && ((((DAT_ffffadd8 == '\x01' || (DAT_ffffadd9 == '\x01')) || (cVar9 == '\x01')) &&
                 ((DAT_ffffccf4 < 0x271 && (bVar1)))))) {
    DAT_ffffccfc = 1;
    DAT_ffffccfd = 0;
    DAT_ffffccfe = 0;
    DAT_ffffccff = 0;
    DAT_ffffcd00 = 1;
  }
  else {
    if (((cVar2 == '\x01') && (cVar10 = FUN_0003eaa4(&DAT_ffff878c,0), cVar10 == '\0')) &&
       (cVar6 == '\x01')) {
      DAT_ffffccfd = 1;
      DAT_ffffccfe = 0;
    }
    else {
      if ((cVar2 == '\0') &&
         ((((bVar5 == 1 && (DAT_ffffccfa == 1)) && (1 < DAT_ffffcd2a)) || (0x4e1 < DAT_ffffccf6))))
      {
        DAT_ffffcd09 = 1;
      }
      if (DAT_ffffcce2 != '\x01') {
        DAT_ffffccfc = 0;
        DAT_ffffccfd = 0;
        DAT_ffffccfe = 0;
        DAT_ffffccff = 1;
        goto LAB_000493e2;
      }
      DAT_ffffccfd = 0;
      DAT_ffffccfe = 1;
    }
    DAT_ffffccfc = 0;
    DAT_ffffccff = 0;
  }
LAB_000493e2:
  DAT_ffffccfb = 0;
  uVar3 = (uint)bVar5;
  if ((uVar3 == 1) && (uVar3 = (uint)DAT_ffffccfa, uVar3 == 1)) {
    uVar3 = FUN_00002460((int)(short)DAT_ffffcd2a,1);
    DAT_ffffcd2a = (ushort)uVar3;
  }
  else {
    DAT_ffffcd2a = 0;
  }
  return uVar3;
}


