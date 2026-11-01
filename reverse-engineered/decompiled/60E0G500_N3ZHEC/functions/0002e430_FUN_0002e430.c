/* ROM address: 0x0002e430; body bytes: 1444; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002e6f8) */
/* WARNING: Removing unreachable block (ram,0x0002e704) */

void FUN_0002e430(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  float *pfVar17;
  undefined *puVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float arg2;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  
  cVar11 = DAT_ffffc022;
  cVar10 = DAT_ffffc021;
  cVar9 = DAT_ffffc020;
  cVar8 = DAT_ffffc01e;
  cVar7 = DAT_ffffc01d;
  cVar6 = DAT_ffffc01a;
  cVar5 = DAT_ffffc019;
  cVar4 = DAT_ffffc018;
  fVar20 = DAT_ffffc00c;
  cVar15 = DAT_ffffbd59;
  cVar14 = DAT_ffffbd57;
  cVar13 = DAT_ffffbc33;
  bVar3 = DAT_ffffbc31;
  bVar2 = DAT_ffffbc30;
  DAT_ffffbd88 = DAT_ffffc008 - DAT_ffffc00c;
  fVar21 = DAT_ffffc00c - DAT_ffffc008;
  fVar22 = DAT_ffffaa38;
  fVar23 = DAT_ffffc008;
  fVar24 = DAT_ffffbd64;
  uVar25 = DAT_ffffcf58;
  if ((((DAT_ffffbd59 == '\0') && (DAT_ffffc01d == '\0')) && (DAT_ffffc022 == '\0')) &&
     (DAT_ffffc021 == '\0')) {
    DAT_ffffbd7c = 0;
  }
  else if (DAT_ffffbdaa == '\x01') {
    if (((8.0 <= DAT_ffffbd88) && (DAT_ffffbd38 < 1.0)) ||
       ((8.0 <= fVar21 && (-1.0 <= DAT_ffffbd38)))) {
      DAT_ffffbd7c = FUN_00002460((int)DAT_ffffbd7c,1);
    }
    else if ((DAT_ffffaa38 <= DAT_ffffbd64) &&
            ((DAT_ffffbc33 == '\0' || ((0xfd < DAT_ffffbc30 && (0xfd < DAT_ffffbc31)))))) {
      DAT_ffffbd7c = 0;
    }
  }
  DAT_ffffbd8c = FUN_000024c0(0x3f800000,0,(int)DAT_ffffbd7c);
  DAT_ffffbd90 = (float)FUN_000020dc(fVar23,uVar25,&DAT_0006adcc);
  DAT_ffffbd94 = (float)FUN_000020dc(fVar20,uVar25,&PTR_DAT_00020004_1_0006ade0);
  DAT_ffffbd98 = (float)FUN_000020dc(fVar20,uVar25,&PTR_DAT_00020004_1_0006adf4);
  DAT_ffffbd9c = (float)FUN_000020dc(fVar23,uVar25,&DAT_0006ae08);
  DAT_ffffbda0 = (float)FUN_000020dc(DAT_ffffbd8c,uVar25,&DAT_0006ae1c);
  cVar12 = FUN_00002440(fVar24,0,0x3727c5ac);
  if ((((DAT_ffffbdb0 == '\0') && (cVar4 == '\x01')) ||
      (((DAT_ffffbdb1 == '\0' && (cVar5 == '\x01')) || ((DAT_ffffbdb2 == '\0' && (cVar6 == '\x01')))
       ))) || ((DAT_ffffbdac == '\x01' && ((cVar11 == '\0' && (27.5 < fVar23)))))) {
    fVar19 = rx8_max_float(fVar22,DAT_ffffbd90);
    arg2 = DAT_ffffbd90 * 10000.0;
LAB_0002e828:
    DAT_ffffbd74 = rx8_clamp_float(fVar19,0.0,arg2);
    goto LAB_0002ea70;
  }
  if ((DAT_ffffbdb3 == '\0') && (cVar7 == '\x01')) {
    fVar20 = (float)FUN_0003eb72(0,&DAT_ffff8694);
    if (fVar20 - fVar23 <= 0.5) {
      fVar20 = rx8_max_float(fVar22,DAT_ffffbd90);
      pfVar17 = (float *)&DAT_00076ba0;
    }
    else {
      DAT_ffffbd90 = DAT_ffffbd90 * 1.0;
      fVar20 = rx8_max_float(fVar22,DAT_ffffbd90);
      pfVar17 = (float *)&DAT_00076ba4;
    }
    DAT_ffffbd74 = rx8_clamp_float(fVar20,0.0,*pfVar17 * DAT_ffffbd90);
    goto LAB_0002ea70;
  }
  arg2 = 100.0;
  if (((DAT_ffffbdaa == '\x01') && (cVar15 == '\x01')) &&
     ((((fVar19 = DAT_ffffbd74, 0.0 <= fVar21 && (fVar21 < 0.0)) ||
       ((((cVar11 == '\0' && (fVar20 < fVar23)) && (cVar12 == '\0')) ||
        ((fVar24 < fVar22 || (cVar14 == '\x01')))))) ||
      ((cVar13 == '\x01' && ((bVar2 < 0xfe || (bVar3 < 0xfe)))))))) goto LAB_0002e828;
  if ((cVar15 == '\0') && (cVar14 == '\x01')) {
    DAT_ffffbd74 = 0.0;
    goto LAB_0002ea70;
  }
  if ((((cVar15 != '\x01') || (fVar24 < 0.0)) || (100.0 <= fVar24)) ||
     (((DAT_ffffbdae != '\0' || (cVar8 != '\x01')) || (DAT_ffffbd68 != '\0')))) {
    if (((cVar15 != '\x01') || (fVar24 < 0.0)) ||
       ((100.0 <= fVar24 ||
        (((DAT_ffffbdaf != '\0' || (cVar9 != '\x01')) || (DAT_ffffbd69 != '\0')))))) {
      if ((DAT_ffffbdaa != '\x01') || (cVar15 != '\x01')) {
        if (cVar15 == '\0') {
          DAT_ffffbd74 = 0.0;
        }
        goto LAB_0002ea70;
      }
      cVar13 = FUN_00002440(uVar25,0x40000000,0x3727c5ac);
      cVar14 = FUN_00002440(uVar25,0x40400000,0x3727c5ac);
      cVar15 = FUN_00002440(uVar25,0x40800000,0x3727c5ac);
      cVar12 = FUN_00002440(uVar25,0x40a00000,0x3727c5ac);
      cVar16 = FUN_00002440(uVar25,0x40c00000,0x3727c5ac);
      if (cVar13 == '\0') {
        puVar18 = &DAT_0006ad7c;
LAB_0002ea12:
        DAT_ffffbd78 = (float)FUN_00002068(DAT_ffffbd88,puVar18);
      }
      else {
        if (cVar14 == '\0') {
          puVar18 = &DAT_0006ad88;
          goto LAB_0002ea12;
        }
        if (cVar15 == '\0') {
          puVar18 = &DAT_0006ad94;
          goto LAB_0002ea12;
        }
        if (cVar12 == '\0') {
          puVar18 = &DAT_0006ada0;
          goto LAB_0002ea12;
        }
        if (cVar16 == '\0') {
          puVar18 = &DAT_0006adac;
        }
        else {
          puVar18 = &DAT_0006ad7c;
        }
        DAT_ffffbd78 = (float)FUN_00002068(DAT_ffffbd88,puVar18);
      }
      fVar20 = DAT_ffffbd74;
      if ((0.0 <= fVar24) && (fVar24 < 100.0)) {
        fVar20 = DAT_ffffbd74 + DAT_ffffbd78 * DAT_ffffbd9c * DAT_ffffbda0 * 0.0001;
      }
      DAT_ffffbd74 = rx8_clamp_float(fVar20,0.0,100.0);
      goto LAB_0002ea70;
    }
    DAT_ffffbd74 = rx8_clamp_float(DAT_ffffbd74 + DAT_ffffbd98,0.0,100.0);
    sVar1 = -0x4297;
  }
  else {
    DAT_ffffbd74 = rx8_clamp_float(DAT_ffffbd74 - DAT_ffffbd94,0.0,100.0);
    sVar1 = -0x4298;
  }
  *(undefined1 *)(int)sVar1 = 1;
LAB_0002ea70:
  if (DAT_ffffbd68 == '\x01') {
    if (0x176 < DAT_ffffbda6) {
      DAT_ffffbd68 = '\0';
    }
    DAT_ffffbda6 = FUN_00002460((int)(short)DAT_ffffbda6,1);
  }
  else {
    DAT_ffffbda6 = 0;
  }
  if (DAT_ffffbd69 == '\x01') {
    if (0x176 < DAT_ffffbda8) {
      DAT_ffffbd69 = '\0';
    }
    DAT_ffffbda8 = FUN_00002460((int)(short)DAT_ffffbda8,1);
  }
  else {
    DAT_ffffbda8 = 0;
  }
  DAT_ffffbdb0 = cVar4;
  DAT_ffffbdb1 = cVar5;
  DAT_ffffbdb2 = cVar6;
  DAT_ffffbdac = cVar11;
  DAT_ffffbdad = cVar10;
  DAT_ffffbdb3 = cVar7;
  DAT_ffffbdae = cVar8;
  DAT_ffffbdaf = cVar9;
  return;
}


