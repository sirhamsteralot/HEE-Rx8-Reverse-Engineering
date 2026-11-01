/* ROM address: 0x0001d52c; body bytes: 728; decompiled */

void FUN_0001d52c(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  float *pfVar9;
  undefined4 *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float arg3;
  
  fVar12 = DAT_ffffbc1c;
  uVar3 = DAT_ffffb290;
  fVar2 = DAT_ffffb28c;
  uVar1 = DAT_ffffaaf0;
  fVar11 = DAT_ffffaa10;
  arg3 = 1e-05;
  fVar14 = DAT_ffffc12c;
  fVar15 = DAT_ffffb140;
  fVar16 = DAT_ffffb5b8;
  cVar4 = FUN_00002440(DAT_ffffb290,DAT_ffffb0c0,0x3727c5ac);
  cVar5 = FUN_00002440(fVar15,DAT_ffffb0c4,arg3);
  DAT_ffffae70 = (float)FUN_0003ea74(0x3f800000,DAT_ffffaae4);
  pfVar9 = &DAT_ffffaf40;
  if (DAT_ffffae97 == '\0') {
    bVar8 = 1;
    DAT_ffffae64 = 1.0;
    DAT_ffffae68 = 1.0;
    DAT_ffffae6c = 1.0;
    do {
      pfVar9 = pfVar9 + 1;
      bVar8 = bVar8 + 1;
      *pfVar9 = 0.0;
    } while (bVar8 < 0x15);
  }
  else {
    if ((cVar4 == '\0') && (cVar5 == '\0')) {
      DAT_ffffb074 = 0.0;
    }
    else {
      DAT_ffffb074 = (((fVar15 - DAT_ffffb0c4) - DAT_ffffb0c8) + fVar2) * 0.0;
    }
    fVar13 = 0.0;
    bVar8 = 1;
    iVar6 = 4;
    do {
      bVar8 = bVar8 + 1;
      fVar13 = fVar13 + *(float *)((int)&DAT_ffffaf40 + iVar6) * *(float *)(&DAT_ffffaee0 + iVar6);
      iVar6 = iVar6 + 4;
    } while (bVar8 < 0x15);
    bVar8 = 1;
    DAT_ffffaf40 = (((DAT_ffffafa0 - DAT_ffffae70) * DAT_ffffaedc +
                    (DAT_ffffae70 - DAT_ffffb0bc) * DAT_ffffaf3c) - DAT_ffffb074) + fVar13;
    do {
      pfVar9 = pfVar9 + 1;
      bVar8 = bVar8 + 1;
      *pfVar9 = *pfVar9 - DAT_ffffb074;
    } while (bVar8 < 0x15);
    fVar13 = DAT_ffffaf40 + DAT_ffffae64;
    if (fVar12 < 5.0) {
      if (fVar12 < 2.0) {
        DAT_ffffb0e0 = '\0';
      }
    }
    else {
      DAT_ffffb0e0 = '\x01';
    }
    if (fVar16 < 1500.0) {
      if (fVar16 < 1400.0) {
        DAT_ffffb0e1 = '\0';
      }
    }
    else {
      DAT_ffffb0e1 = '\x01';
    }
    if (fVar14 <= 0.3) {
      if (fVar14 <= 0.28) {
        DAT_ffffb0e2 = '\0';
      }
    }
    else {
      DAT_ffffb0e2 = '\x01';
    }
    if ((((DAT_ffffb0e0 != '\0') || (DAT_ffffb0e1 != '\0')) || (DAT_ffffb0e2 != '\x01')) ||
       ((-40.0 <= fVar11 || (DAT_ffffb5aa != '\0')))) {
      DAT_ffffae8c = 0.0;
    }
    else {
      DAT_ffffae8c = (float)FUN_00002068(fVar11,&PTR_DAT_00069f38);
    }
    DAT_ffffb0ac = (float)FUN_000020dc(fVar16,fVar14,&DAT_0006a000);
    DAT_ffffb0b0 = (float)FUN_00002068(uVar1,&DAT_00069f24);
    fVar11 = rx8_max_float(DAT_ffffb0b0,DAT_ffffb0ac);
    DAT_ffffb0b8 = rx8_max_float(fVar11,DAT_ffffae8c);
    DAT_ffffb0b4 = (float)FUN_00002068(uVar1,&DAT_00069f4c);
    DAT_ffffae64 = rx8_clamp_float(fVar13,DAT_ffffb0b8,DAT_ffffb0b4);
    fVar11 = rx8_first_order_filter(DAT_ffffae64,DAT_ffffae68,0.015325,arg3);
    fVar12 = rx8_first_order_filter(DAT_ffffae64,DAT_ffffae6c,0.0078125,arg3);
    cVar4 = '\x14';
    uVar7 = 0x13;
    DAT_ffffae68 = fVar11 - DAT_ffffb074;
    puVar10 = &DAT_ffffaf94;
    DAT_ffffae6c = fVar12 - DAT_ffffb074;
    do {
      cVar4 = cVar4 + -1;
      puVar10 = puVar10 + -1;
      *puVar10 = (&DAT_ffffaf40)[uVar7 & 0xff];
      uVar7 = uVar7 + 0xff;
    } while (cVar4 != '\0');
  }
  DAT_ffffb0bc = DAT_ffffae70;
  DAT_ffffb0c0 = uVar3;
  DAT_ffffb0c4 = fVar15;
  DAT_ffffb0c8 = fVar2;
  return;
}


