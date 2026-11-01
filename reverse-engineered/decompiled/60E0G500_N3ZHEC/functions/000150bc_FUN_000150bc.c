/* ROM address: 0x000150bc; body bytes: 1530; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00015532) */
/* WARNING: Removing unreachable block (ram,0x0001544c) */
/* WARNING: Removing unreachable block (ram,0x00015678) */
/* WARNING: Removing unreachable block (ram,0x0001560c) */
/* WARNING: Removing unreachable block (ram,0x0001572c) */
/* WARNING: Removing unreachable block (ram,0x0001576e) */
/* WARNING: Removing unreachable block (ram,0x0001577c) */
/* WARNING: Removing unreachable block (ram,0x000157ac) */

void FUN_000150bc(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  float *pfVar10;
  undefined **ppuVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  float arg3;
  float fVar15;
  
  cVar9 = DAT_ffffc68e;
  cVar8 = DAT_ffffbe24;
  cVar7 = DAT_ffffbdd5;
  cVar6 = DAT_ffffbb38;
  cVar5 = DAT_ffffb623;
  cVar4 = DAT_ffffb5ac;
  cVar3 = DAT_ffffb5a4;
  cVar1 = DAT_ffffa42c;
  cVar2 = DAT_ffffa428;
  arg3 = 1e-05;
  fVar13 = DAT_ffffbc1c;
  uVar14 = DAT_ffffaa14;
  fVar15 = DAT_ffffc71c;
  DAT_ffffa7d8 = rx8_first_order_filter(DAT_ffffb600,DAT_ffffa7d8,0.03125,1e-05);
  if ((((DAT_ffffa7c7 == '\x01') && (0x493d < DAT_ffffa816)) && (13.016 <= DAT_ffffa7d8)) ||
     ((cVar2 == '\0' || (cVar1 == '\x01')))) {
    DAT_ffffa7c7 = '\0';
    DAT_ffffa818 = 0;
  }
  else if (((DAT_ffffa424 < 0x4e2) || (cVar1 != '\0')) ||
          ((DAT_ffffa814 < 0x271 || (12.0 <= DAT_ffffa7d8)))) {
    DAT_ffffa818 = 0;
  }
  else {
    if (0x270 < DAT_ffffa818) {
      DAT_ffffa7c7 = '\x01';
    }
    DAT_ffffa818 = FUN_00002460((int)(short)DAT_ffffa818,1);
  }
  if (cVar1 == '\0') {
    DAT_ffffa814 = FUN_00002460((int)(short)DAT_ffffa814,1);
  }
  else {
    DAT_ffffa814 = 0;
  }
  if (DAT_ffffa7c7 == '\x01') {
    DAT_ffffa816 = FUN_00002460((int)(short)DAT_ffffa816,1);
  }
  else {
    DAT_ffffa816 = 0;
  }
  if (fVar15 <= 0.9) {
    if (fVar15 <= 0.752) {
      DAT_ffffa802 = 1;
    }
  }
  else {
    DAT_ffffa802 = 0;
  }
  if ((cVar2 == '\x01') && (DAT_ffffa83c == '\0')) {
    DAT_ffffa828 = 0x753;
    DAT_ffffa82a = 0x271;
  }
  else {
    if (DAT_ffffa828 != 0) {
      DAT_ffffa828 = DAT_ffffa828 + -1;
    }
    if (DAT_ffffa82a != 0) {
      DAT_ffffa82a = DAT_ffffa82a + -1;
    }
  }
  fVar15 = 500.0;
  if (cVar3 == '\x01') {
    FUN_00015868(uVar14);
    if (DAT_ffffa6b9 == '\x01') {
      pfVar10 = &DAT_ffffa7f0;
    }
    else {
      if (DAT_ffffa6b7 != '\x01') {
        fVar12 = DAT_ffffa7ec;
        if (DAT_ffffa6b8 != '\x01') {
          cVar1 = DAT_ffffb5ab;
          if (DAT_ffffa828 != 0) goto LAB_000153cc;
          fVar12 = rx8_max_float(0.0,fVar15);
          DAT_ffffa7c8 = 0;
        }
        goto LAB_000153e8;
      }
      pfVar10 = &DAT_ffffa7e8;
    }
    fVar12 = *pfVar10;
  }
  else {
    FUN_00015868(uVar14);
    fVar12 = DAT_ffffa7f0;
    if (((DAT_ffffa6b9 != '\x01') && (fVar12 = DAT_ffffa7e8, DAT_ffffa6b7 != '\x01')) &&
       (fVar12 = DAT_ffffa7ec, DAT_ffffa6b8 != '\x01')) {
      cVar1 = cVar4;
      if (DAT_ffffa828 == 0) {
        fVar12 = rx8_max_float(DAT_ffffa7dc - 0.32,fVar15);
        DAT_ffffa7c8 = 0;
      }
      else {
LAB_000153cc:
        FUN_00015984((int)cVar1);
        fVar12 = DAT_ffffa7dc;
      }
    }
  }
LAB_000153e8:
  DAT_ffffa7dc = fVar12;
  DAT_ffffa83c = cVar2;
  if (fVar13 < 120.0) {
    if (fVar13 < 115.0) {
      DAT_ffffa83d = '\0';
    }
  }
  else {
    DAT_ffffa83d = '\x01';
  }
  if (cVar3 == '\x01') {
    fVar15 = 820.0;
    if (cVar7 == '\x01') {
      if (cVar8 == '\x01') {
        fVar15 = 840.0;
      }
      else if (cVar5 == '\x01') {
        fVar15 = 840.0;
      }
      else {
        fVar15 = 810.0;
      }
    }
    else if (cVar5 == '\x01') {
      fVar15 = 810.0;
    }
    ppuVar11 = &PTR_DAT_00069a54;
  }
  else {
    if (cVar4 != '\0') {
      if (DAT_ffffb5ae == '\x01') {
        fVar15 = 790.0;
        if (cVar7 == '\x01') {
          if (cVar8 == '\x01') {
            fVar15 = 830.0;
          }
          else if (cVar5 == '\x01') {
            fVar15 = 800.0;
          }
          else {
            fVar15 = 800.0;
          }
        }
        else if (cVar5 == '\x01') {
          fVar15 = 790.0;
        }
        DAT_ffffa810 = (float)FUN_00002068(uVar14,&PTR_DAT_00069af4);
      }
      else {
        fVar15 = DAT_ffffa7e4;
        if (DAT_ffffb5b0 == '\x01') {
          fVar15 = 810.0;
          if (cVar7 == '\x01') {
            if (cVar8 == '\x01') {
              fVar15 = 830.0;
            }
            else if (cVar5 == '\x01') {
              fVar15 = 810.0;
            }
            else {
              fVar15 = 810.0;
            }
          }
          else if (cVar5 == '\x01') {
            fVar15 = 810.0;
          }
          DAT_ffffa810 = (float)FUN_00002068(uVar14,&PTR_DAT_00069acc);
        }
      }
      goto LAB_000156f2;
    }
    fVar15 = 810.0;
    if (((DAT_ffffa83d == '\x01') && (cVar6 == '\x01')) && (cVar9 == '\0')) {
      fVar15 = (float)FUN_00002068(fVar13,&PTR_DAT_00069ae0);
    }
    else if (((DAT_ffffa83d == '\0') && (cVar6 == '\x01')) && (cVar9 == '\0')) {
      pfVar10 = (float *)&DAT_0006e6b0;
LAB_00015576:
      fVar15 = *pfVar10;
    }
    else if (cVar7 == '\x01') {
      if (cVar8 == '\x01') {
        pfVar10 = (float *)&DAT_0006e684;
        goto LAB_00015576;
      }
      if (cVar5 == '\x01') {
        fVar15 = 830.0;
      }
      else {
        fVar15 = 830.0;
      }
    }
    else if (cVar5 == '\x01') {
      fVar15 = 830.0;
    }
    ppuVar11 = &PTR_DAT_00069ab8;
  }
  DAT_ffffa810 = (float)FUN_00002068(uVar14,ppuVar11);
LAB_000156f2:
  DAT_ffffa7e4 = fVar15;
  fVar13 = rx8_max_float(DAT_ffffa810,DAT_ffffa7dc);
  DAT_ffffa7c0 = rx8_max_float(fVar13,DAT_ffffa7e4);
  if ((DAT_ffffa83a == '\0') && (cVar4 == '\x01')) {
    DAT_ffffa82c = 0;
  }
  else if (DAT_ffffa82c != 0) {
    DAT_ffffa82c = DAT_ffffa82c + -1;
  }
  if (DAT_ffffa82c == 0) {
    DAT_ffffa7cc = (float)FUN_00002068(DAT_ffffa7c0 - DAT_ffffa7bc,&DAT_00069a40);
  }
  else {
    DAT_ffffa7cc = 1.0;
  }
  DAT_ffffa82e = 0;
  DAT_ffffa83a = cVar4;
  if (DAT_ffffd2a6 == '\x01') {
    DAT_ffffa804 = DAT_ffffd280;
    fVar13 = DAT_ffffa804;
  }
  else {
    fVar13 = rx8_first_order_filter(DAT_ffffa7c0,DAT_ffffa7bc,DAT_ffffa7cc,arg3);
    if (DAT_ffffa7c7 != '\0') {
      fVar13 = rx8_max_float(fVar13,850.0);
    }
  }
  DAT_ffffa804 = fVar13;
  DAT_ffffa7bc = (float)FUN_0005d238(DAT_ffffa804);
  return;
}


