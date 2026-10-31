/* ROM address: 0x00010390; body bytes: 664; decompiled */

uint FUN_00010390(byte param_1)

{
  byte bVar2;
  uint uVar1;
  char cVar3;
  char *pcVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  char cStack_28;
  
  uVar6 = (uint)param_1;
  iVar7 = uVar6 - DAT_ffffa5d4;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0x18;
  }
  if (0xb < uVar6) {
    uVar6 = uVar6 - 0xc;
  }
  pcVar9 = &DAT_ffffa578;
  iVar11 = uVar6 * 0x1e0000;
  DAT_ffffa5d4 = param_1;
  if (DAT_ffffa5d5 == '\x01') {
    DAT_ffffa5d5 = '\0';
    DAT_ffffa5d0 = 1;
    DAT_ffffa5d2 = 0;
    for (pcVar10 = pcVar9; pcVar4 = pcVar9, pcVar10 < &DAT_ffffa5d0; pcVar10 = pcVar10 + 0x2c) {
      *pcVar10 = '\0';
      pcVar10[2] = '\0';
      pcVar10[1] = '\0';
      for (pcVar4 = pcVar10 + 0xc; pcVar4 < pcVar10 + 0x2c; pcVar4 = pcVar4 + 0x10) {
        pcVar4[4] = '\0';
        *(undefined4 *)(pcVar4 + 8) = DAT_ffffbc24;
        *(undefined4 *)(pcVar4 + 0xc) = DAT_ffffbc24;
        pcVar4[3] = '\0';
      }
    }
    for (; pcVar4 < &DAT_ffffa5d0; pcVar4 = pcVar4 + 0x2c) {
      iVar7 = FUN_00010800(iVar11,*(undefined4 *)(pcVar4 + 4));
      iVar8 = FUN_000107d4(0x1680000 - iVar7);
      pcVar4[9] = 0x167ffff < iVar8;
      for (pcVar10 = pcVar4 + 0xc; pcVar10 < pcVar4 + 0x2c; pcVar10 = pcVar10 + 0x10) {
        *pcVar10 = pcVar10[(byte)pcVar4[9] + 1];
        pcVar10[3] = '\0';
      }
      FUN_00010ec0(pcVar4);
      cVar3 = (*(code *)(&PTR_LAB_0004e304)[*pcVar4 * 4])(pcVar4,iVar7);
      if (cVar3 == '\x01') {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x02';
      }
      pcVar4[1] = cVar3;
    }
    FUN_00010a8e(iVar11);
  }
  else if (iVar7 != 1) {
    FUN_0001065c();
  }
  bVar2 = FUN_00010e8e();
  if (bVar2 != DAT_ffffa5d0) {
    FUN_00010816(iVar11,(int)(char)(&DAT_0004e2f4)[bVar2]);
    DAT_ffffa5d0 = bVar2;
  }
  uVar1 = FUN_00010e88();
  uVar6 = uVar1;
  if ((uVar1 & 0xffff) != (uint)DAT_ffffa5d2) {
    uVar6 = FUN_0001090e(iVar11,uVar1);
    DAT_ffffa5d2 = (ushort)uVar1;
  }
  do {
    if ((char *)0xffffa5cf < pcVar9) {
      return uVar6;
    }
    iVar7 = FUN_00010800(iVar11,*(undefined4 *)(pcVar9 + 4));
    if (0x149ffff < iVar7) {
      pcVar9[9] = 0xb < DAT_ffffa5d4;
      for (pbVar5 = (byte *)(pcVar9 + 0xc); pbVar5 < pcVar9 + 0x2c; pbVar5 = pbVar5 + 0x10) {
        pbVar5[3] = 0;
        *pbVar5 = pbVar5[(byte)pcVar9[9] + 1];
        pbVar5[4] = (*(ushort *)((int)&PTR_DAT_0004e2d4 + (uint)*pbVar5 * 2) & DAT_ffffa5d2) != 0;
      }
      pcVar9[1] = '\0';
      *pcVar9 = (&DAT_0004e2f4)[DAT_ffffa5d0];
    }
    iVar8 = (int)*pcVar9;
    uVar6 = (uint)pcVar9[1];
    if (uVar6 == 0) {
      cStack_28 = '\x01';
      for (pcVar10 = pcVar9 + 0xc; pcVar10 < pcVar9 + 0x2c; pcVar10 = pcVar10 + 0x10) {
        cVar3 = FUN_00008ee6((int)*pcVar10);
        if (cVar3 != '\0') {
          cStack_28 = '\0';
          break;
        }
      }
      uVar6 = (uint)cStack_28;
      if (uVar6 == 1) {
        if (*(int *)(&DAT_0004e2fc + iVar8 * 0x10) < iVar7) {
          if (iVar7 <= *(int *)(&DAT_0004e2f8 + iVar8 * 0x10)) {
            FUN_00010ec0(pcVar9);
            uVar6 = (*(code *)(&PTR_FUN_0004e300)[iVar8 * 4])(pcVar9,iVar7);
          }
        }
        else {
          uVar6 = 2;
          pcVar9[1] = '\x02';
        }
      }
    }
    else if ((uVar6 == 1) && (uVar6 = (uint)(byte)pcVar9[2], uVar6 == 1)) {
      FUN_00010ec0(pcVar9);
      uVar6 = (*(code *)(&PTR_FUN_0004e300)[iVar8 * 4])(pcVar9,iVar7);
    }
    pcVar9 = pcVar9 + 0x2c;
  } while( true );
}


