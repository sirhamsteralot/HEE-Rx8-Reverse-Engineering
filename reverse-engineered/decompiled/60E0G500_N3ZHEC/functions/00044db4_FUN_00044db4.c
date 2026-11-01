/* ROM address: 0x00044db4; body bytes: 1054; decompiled */

undefined4 * FUN_00044db4(void)

{
  short sVar1;
  char cVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  undefined2 uVar10;
  float *pfVar11;
  int iVar12;
  short *psVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fStack_38;
  
  cVar2 = DAT_ffffcb39;
  DAT_ffffcb44 = rx8_first_order_filter(DAT_ffffaae4,DAT_ffffcb44,0.25,1e-05);
  DAT_ffffcb50 = rx8_first_order_filter(DAT_ffffad98,DAT_ffffcb50,0.25,1e-05);
  uVar3 = DAT_ffffcb8e;
  fVar20 = 0.0;
  if (DAT_ffffd201 == '\x01') {
    bVar8 = 0;
    puVar6 = &DAT_ffffcb90;
    DAT_ffffcb34 = 0.0;
    DAT_ffffcb48 = 0.0;
    DAT_ffffcb58 = 0.0;
    DAT_ffffcb88 = 0.0;
    DAT_ffffcba6 = 0;
    DAT_ffffcb8c = 0;
    DAT_ffffcb8e = 0;
    DAT_ffffcba9 = 0;
    DAT_ffffcb3c = '\0';
    DAT_ffffcb3b = '\0';
    puVar7 = &DAT_ffffcb60;
    DAT_ffffcb3a = 0;
    do {
      *puVar7 = 0;
      bVar8 = bVar8 + 1;
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (bVar8 < 10);
    DAT_ffffcbcc = 0;
    puVar7 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffcbca,1);
    DAT_ffffcbca = (ushort)puVar7;
    fVar17 = DAT_ffffcb48;
    fVar18 = DAT_ffffcb58;
    fVar15 = DAT_ffffcb88;
    uVar3 = DAT_ffffcb8e;
    uVar10 = DAT_ffffcba6;
    if (1 < DAT_ffffcbca) {
      DAT_ffffcbb8 = DAT_ffffcb44;
      puVar7 = &DAT_ffffcbbc;
      DAT_ffffcbbc = DAT_ffffcb50;
      DAT_ffffcbca = 0;
    }
  }
  else {
    iVar12 = (int)(short)DAT_ffffcb8e;
    iVar9 = (int)DAT_ffffcba6;
    fVar15 = DAT_ffffcb88;
    fVar18 = DAT_ffffcb58;
    fVar17 = DAT_ffffcb48;
    uVar14 = FUN_000024c0(0x42000000,0,iVar12);
    DAT_ffffcbb4 = (float)FUN_00002068(uVar14,&PTR_DAT_0006bd0c);
    DAT_ffffcb5c = (float)FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006bd38);
    if ((DAT_ffffcbcf == '\0') && (cVar2 == '\x01')) {
      DAT_ffffcba4 = DAT_ffffcb8c;
      DAT_ffffcbcc = 0x9c;
    }
    else if (DAT_ffffcbcc != 0) {
      DAT_ffffcbcc = DAT_ffffcbcc + -1;
    }
    if (cVar2 == '\x01') {
      if (DAT_ffffcb8c < 0xf424) {
        DAT_ffffcb8c = FUN_00002460((int)(short)DAT_ffffcb8c,1);
      }
      if (uVar3 < 0xf424) {
        uVar3 = FUN_00002460(iVar12,1);
      }
      fVar15 = rx8_min_float(100000.0,DAT_ffffcb5c + fVar15);
      iVar9 = FUN_00002460(iVar9,1);
      fVar16 = (float)FUN_000024c0(0x3f800000,fVar20,iVar9);
      DAT_ffffcb30 = fVar15 / fVar16;
    }
    else if ((DAT_ffffcbcf == '\x01') && ((fVar17 <= DAT_ffffcbb4 || (DAT_ffffcbcc != 0)))) {
      uVar3 = 0;
      DAT_ffffcb8c = DAT_ffffcba4;
      iVar9 = 0;
      fVar15 = fVar20;
      fVar18 = fVar20;
      fVar17 = fVar20;
    }
    uVar10 = (undefined2)iVar9;
    DAT_ffffcbca = FUN_00002460((int)(short)DAT_ffffcbca,1);
    if (1 < DAT_ffffcbca) {
      if (cVar2 == '\x01') {
        fVar16 = rx8_absolute_difference(DAT_ffffcbb8,DAT_ffffcb44);
        DAT_ffffcb4c = rx8_min_float(fVar16,0.4);
        fVar17 = rx8_min_float(DAT_ffffcb4c + fVar17,1000.0);
        fVar16 = rx8_absolute_difference(DAT_ffffcbbc,DAT_ffffcb50);
        DAT_ffffcb54 = rx8_min_float(fVar16,1.0);
        fVar18 = rx8_min_float(DAT_ffffcb54 + fVar18,2500.0);
      }
      DAT_ffffcbb8 = DAT_ffffcb44;
      DAT_ffffcbbc = DAT_ffffcb50;
      DAT_ffffcbca = 0;
    }
    cVar4 = FUN_00002440(fVar17,fVar20,0x3727c5ac);
    cVar5 = FUN_00002440(DAT_ffffcb30,fVar20,0x3727c5ac);
    if ((0x3a9 < DAT_ffffcb8c) || (((DAT_ffffcbcf == '\x01' && (cVar2 == '\0')) && (cVar4 != '\0')))
       ) {
      fVar15 = fVar20;
      if ((cVar4 == '\0') || (cVar5 == '\0')) {
        (&DAT_ffffcb60)[DAT_ffffcba9] = fVar20;
        (&DAT_ffffcb90)[DAT_ffffcba9] = uVar3;
      }
      else {
        (&DAT_ffffcb60)[DAT_ffffcba9] = fVar18 / (DAT_ffffcb30 * fVar17);
        (&DAT_ffffcb90)[DAT_ffffcba9] = uVar3;
        if (DAT_ffffcba9 < 9) {
          DAT_ffffcba9 = FUN_00002478((int)(char)DAT_ffffcba9,1);
          fVar15 = fVar20;
        }
      }
      uVar10 = 0;
      uVar3 = 0;
      fVar18 = fVar15;
      fVar17 = fVar15;
      fVar20 = fVar15;
    }
    fVar16 = DAT_ffffcb34;
    if (((0x3a9 < DAT_ffffcb8c) && (DAT_ffffcb3c == '\0')) && (fVar16 = fVar20, DAT_ffffcb8c != 0))
    {
      pfVar11 = (float *)&DAT_ffffcb60;
      bVar8 = 0;
      psVar13 = &DAT_ffffcb90;
      fStack_38 = fVar20;
      do {
        sVar1 = *psVar13;
        psVar13 = psVar13 + 1;
        fVar16 = (float)FUN_000024c0(0x42000000,fVar20,(int)sVar1);
        fVar19 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        bVar8 = bVar8 + 1;
        fStack_38 = fStack_38 + fVar19 * fVar16;
      } while (bVar8 < 10);
      uVar14 = FUN_000024c0(0x42000000,fVar20,(int)(short)DAT_ffffcb8c);
      fVar16 = (float)FUN_0003ea74(fStack_38,uVar14);
      DAT_ffffcb3c = '\x01';
    }
    DAT_ffffcb34 = fVar16;
    if (DAT_ffffcb3c == '\x01') {
      DAT_ffffcbc0 = (float)FUN_00002068(DAT_ffffc75c,&DAT_0006bd18);
      if (DAT_ffffcb34 < DAT_ffffcbc0) {
        DAT_ffffcb3a = 1;
      }
      else {
        DAT_ffffcb3b = '\x01';
      }
    }
    if (DAT_ffffcb3b == '\x01') {
      puVar7 = (undefined4 *)FUN_000604dc(0x2c,1);
    }
    else {
      puVar7 = (undefined4 *)(uint)DAT_ffffcb3a;
      if (puVar7 == (undefined4 *)&UNK_00000001) {
        puVar7 = (undefined4 *)FUN_000604dc(0x2c,2);
      }
    }
  }
  DAT_ffffcba6 = uVar10;
  DAT_ffffcb8e = uVar3;
  DAT_ffffcb88 = fVar15;
  DAT_ffffcb58 = fVar18;
  DAT_ffffcb48 = fVar17;
  DAT_ffffcbcf = cVar2;
  return puVar7;
}


