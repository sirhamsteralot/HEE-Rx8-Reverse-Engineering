/* ROM address: 0x0002835c; body bytes: 412; decompiled */

uint FUN_0002835c(void)

{
  char cVar2;
  uint uVar1;
  undefined2 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float *pfVar9;
  byte bVar12;
  int iVar10;
  undefined *puVar11;
  undefined2 *puVar13;
  uint uVar14;
  float fVar15;
  float arg3;
  float fVar16;
  
  if (DAT_ffffba74 == 0) {
    DAT_ffffba74 = 0xb;
    fVar16 = 0.0;
    if (DAT_ffffba79 == '\x01') {
      bVar12 = 0;
      puVar13 = &DAT_ffffb964;
      puVar7 = &DAT_ffffb73c;
      do {
        bVar6 = 0;
        puVar3 = puVar13;
        puVar5 = puVar7;
        do {
          bVar6 = bVar6 + 1;
          *puVar3 = 0;
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
          puVar3 = puVar3 + 1;
        } while (bVar6 < 0x44);
        bVar12 = bVar12 + 1;
        puVar13 = puVar13 + 0x44;
        puVar7 = puVar7 + 0x44;
      } while (bVar12 < 2);
      DAT_ffffba79 = '\0';
    }
    else {
      bVar12 = 0;
      arg3 = 1e-05;
      do {
        bVar6 = 0;
        uVar14 = (uint)bVar12;
        pfVar4 = (float *)(&DAT_ffffb73c + (uint)bVar12 * 0x44);
        pfVar8 = pfVar4;
        puVar13 = &DAT_ffffb964 + uVar14 * 0x44;
        pfVar9 = pfVar4;
        do {
          iVar10 = (uint)bVar6 * 2;
          if (0x1d < (ushort)(&DAT_ffffb964 + uVar14 * 0x44)[bVar6]) {
            cVar2 = FUN_0003eaa4(&DAT_ffff8570 + iVar10 + uVar14 * 0x88,0);
            if (cVar2 == '\0') {
              FUN_0003ec20(pfVar4[bVar6],&DAT_ffff8130 + (uint)bVar6 * 8 + (uint)bVar12 * 0x220);
              FUN_0003ebc0(&DAT_ffff8570 + iVar10 + uVar14 * 0x88,1);
            }
            else {
              puVar11 = &DAT_ffff8130 + (uint)bVar6 * 8 + (uint)bVar12 * 0x220;
              fVar15 = (float)FUN_0003eb72(fVar16,puVar11);
              fVar15 = rx8_first_order_filter(*pfVar9,fVar15,0.125,arg3);
              FUN_0003ec20(fVar15,puVar11);
            }
            *puVar13 = 0;
            *pfVar8 = fVar16;
          }
          bVar6 = bVar6 + 1;
          pfVar8 = pfVar8 + 1;
          puVar13 = puVar13 + 1;
          pfVar9 = pfVar9 + 1;
        } while (bVar6 < 0x44);
        bVar12 = bVar12 + 1;
      } while (bVar12 < 2);
    }
  }
  uVar14 = 0;
  do {
    uVar1 = FUN_000043c8();
    uVar1 = uVar1 & 1;
    if (uVar1 == 1) {
      uVar1 = FUN_00028a40(uVar14);
    }
    uVar14 = uVar14 + 1;
  } while ((uVar14 & 0xff) < 8);
  return uVar1;
}


