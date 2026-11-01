/* ROM address: 0x0000f4d8; body bytes: 718; decompiled */

uint FUN_0000f4d8(byte param_1)

{
  short sVar2;
  char cVar3;
  byte bVar4;
  uint uVar1;
  char *pcVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  
  uVar8 = (uint)param_1;
  iVar9 = uVar8 - DAT_ffffa570;
  if (iVar9 < 0) {
    iVar9 = iVar9 + 0x18;
  }
  if (0xb < uVar8) {
    uVar8 = uVar8 - 0xc;
  }
  pcVar10 = &DAT_ffffa4b4;
  iVar12 = uVar8 * 0x1e0000;
  DAT_ffffa570 = param_1;
  if (DAT_ffffa571 == '\x01') {
    DAT_ffffa571 = '\0';
    DAT_ffffa56d = 0;
    DAT_ffffa56e = 0;
    DAT_ffffa564 = 0;
    DAT_ffffa568 = 0;
    for (pcVar6 = pcVar10; pcVar5 = pcVar10, pcVar6 < &DAT_ffffa564; pcVar6 = pcVar6 + 0x58) {
      *pcVar6 = '\0';
      pcVar6[1] = '\0';
      pcVar6[6] = '\0';
      pcVar6[7] = '\0';
      pcVar6[4] = '\0';
      pcVar6[5] = '\0';
      pcVar6[3] = '\0';
      pcVar6[2] = '\0';
      for (pcVar5 = pcVar6 + 0x10; pcVar5 < pcVar6 + 0x58; pcVar5 = pcVar5 + 0x18) {
        pcVar5[4] = '\0';
        pcVar5[5] = '\0';
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        pcVar5[8] = '\0';
        pcVar5[9] = '\0';
        pcVar5[10] = '\0';
        pcVar5[0xb] = '\0';
        pcVar5[0xc] = '\x01';
        pcVar5[0xd] = 'h';
        pcVar5[0xe] = '\0';
        pcVar5[0xf] = '\0';
        pcVar5[0x10] = '\x01';
        pcVar5[0x11] = 'h';
        pcVar5[0x12] = '\0';
        pcVar5[0x13] = '\0';
        pcVar5[0x14] = '\0';
        pcVar5[1] = '\0';
      }
    }
    for (; pcVar5 < &DAT_ffffa564; pcVar5 = pcVar5 + 0x58) {
      iVar9 = FUN_0000fa3a(iVar12,*(undefined4 *)(pcVar5 + 8));
      FUN_0000ff32(pcVar5);
      iVar11 = 0;
      for (pcVar6 = pcVar5 + 0x10; pcVar6 < pcVar5 + 0x58; pcVar6 = pcVar6 + 0x18) {
        if (iVar11 < *(int *)(pcVar6 + 0x10)) {
          iVar11 = *(int *)(pcVar6 + 0x10);
        }
      }
      if (iVar9 < iVar11) {
        pcVar5[4] = '\0';
        pcVar5[5] = '\0';
        pcVar5[3] = '\0';
        cVar3 = '\x02';
      }
      else {
        DAT_ffffa564 = FUN_00002460((int)DAT_ffffa564,1);
        sVar2 = FUN_00003fe8();
        *(short *)(pcVar5 + 4) = sVar2 + 1;
        pcVar5[3] = '\x01';
        cVar3 = '\0';
      }
      pcVar5[2] = cVar3;
    }
  }
  else if (iVar9 != 1) {
    FUN_0000f7f8();
  }
  bVar4 = FUN_0000ff0a();
  if (bVar4 != DAT_ffffa56d) {
    FUN_0000fa4e(iVar12,(int)(char)(&DAT_0004ea48)[bVar4]);
    DAT_ffffa56d = bVar4;
  }
  uVar1 = FUN_0000ff04();
  uVar8 = uVar1;
  if ((uVar1 & 0xffff) != (uint)DAT_ffffa56e) {
    uVar8 = FUN_0000fb8c(iVar12,uVar1);
    DAT_ffffa56e = (ushort)uVar1;
  }
  do {
    if ((char *)0xffffa563 < pcVar10) {
      return uVar8;
    }
    iVar9 = FUN_0000fa3a(iVar12,*(undefined4 *)(pcVar10 + 8));
    if (0x167ffff < iVar9) {
      for (pcVar6 = pcVar10 + 0x10; pcVar6 < pcVar10 + 0x58; pcVar6 = pcVar6 + 0x18) {
        pcVar6[1] = '\0';
      }
      pcVar10[2] = '\0';
      pcVar10[7] = '\0';
      *pcVar10 = (&DAT_0004ea48)[DAT_ffffa56d];
      pcVar10[1] = (*(ushort *)((int)&PTR_DAT_0004ea28 + (uint)(byte)pcVar10[0xc] * 2) &
                   DAT_ffffa56e) != 0;
      pcVar10[3] = '\0';
    }
    iVar11 = (int)*pcVar10;
    uVar8 = (uint)pcVar10[2];
    if (uVar8 == 0) {
      cVar3 = '\x01';
      for (pbVar7 = (byte *)(pcVar10 + 0x10); pbVar7 < pcVar10 + 0x58; pbVar7 = pbVar7 + 0x18) {
        if ((&DAT_ffffa017)[(uint)*pbVar7 * 0x18] != '\0') {
          cVar3 = '\0';
          break;
        }
      }
      uVar8 = (uint)cVar3;
      if (uVar8 == 1) {
        if (*(int *)(&DAT_0004ea50 + iVar11 * 0x10) < iVar9) {
          if (iVar9 <= *(int *)(&DAT_0004ea4c + iVar11 * 0x10)) {
            if (pcVar10[3] == '\0') {
              DAT_ffffa564 = FUN_00002460((int)DAT_ffffa564,1);
              *(short *)(pcVar10 + 4) = DAT_ffffa564;
              pcVar10[3] = '\x01';
            }
            uVar8 = (uint)pcVar10[1];
            if (uVar8 == 0) {
              FUN_0000ff32(pcVar10);
              for (pcVar6 = pcVar10 + 0x10; pcVar6 < pcVar10 + 0x58; pcVar6 = pcVar6 + 0x18) {
                *(undefined4 *)(pcVar6 + 0xc) = *(undefined4 *)(pcVar6 + 0x10);
              }
              FUN_0000ffd6(pcVar10);
              uVar8 = (*(code *)(&PTR_LAB_0004ea54)[iVar11 * 4])(pcVar10,iVar9);
            }
          }
        }
        else {
          uVar8 = 2;
          pcVar10[2] = '\x02';
        }
      }
    }
    else if (((uVar8 == 1) && (uVar8 = (uint)pcVar10[1], uVar8 == 0)) &&
            (uVar8 = (uint)(byte)pcVar10[6], uVar8 == 1)) {
      FUN_0000ffd6(pcVar10);
      uVar8 = (*(code *)(&PTR_LAB_0004ea54)[iVar11 * 4])(pcVar10,iVar9);
    }
    pcVar10 = pcVar10 + 0x58;
  } while( true );
}


