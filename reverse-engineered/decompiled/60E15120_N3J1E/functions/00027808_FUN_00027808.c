/* ROM address: 0x00027808; body bytes: 412; decompiled */

uint FUN_00027808(void)

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
  
  if (DAT_ffffba04 == 0) {
    DAT_ffffba04 = 0xb;
    fVar16 = 0.0;
    if (DAT_ffffba09 == '\x01') {
      bVar12 = 0;
      puVar13 = &DAT_ffffb8f4;
      puVar7 = &DAT_ffffb6cc;
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
      DAT_ffffba09 = '\0';
    }
    else {
      bVar12 = 0;
      arg3 = 1e-05;
      do {
        bVar6 = 0;
        uVar14 = (uint)bVar12;
        pfVar4 = (float *)(&DAT_ffffb6cc + (uint)bVar12 * 0x44);
        pfVar8 = pfVar4;
        puVar13 = &DAT_ffffb8f4 + uVar14 * 0x44;
        pfVar9 = pfVar4;
        do {
          iVar10 = (uint)bVar6 * 2;
          if (0x1d < (ushort)(&DAT_ffffb8f4 + uVar14 * 0x44)[bVar6]) {
            cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8548 + iVar10 + uVar14 * 0x88,0);
            if (cVar2 == '\0') {
              ref_updateMemoryAtAddress_float_VAL_ADDR
                        (pfVar4[bVar6],&DAT_ffff8108 + (uint)bVar6 * 8 + (uint)bVar12 * 0x220);
              ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8548 + iVar10 + uVar14 * 0x88,1);
            }
            else {
              puVar11 = &DAT_ffff8108 + (uint)bVar6 * 8 + (uint)bVar12 * 0x220;
              fVar15 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar16,puVar11);
              fVar15 = rx8_first_order_filter(*pfVar9,fVar15,0.125,arg3);
              ref_updateMemoryAtAddress_float_VAL_ADDR(fVar15,puVar11);
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
      uVar1 = FUN_00027eec(uVar14);
    }
    uVar14 = uVar14 + 1;
  } while ((uVar14 & 0xff) < 8);
  return uVar1;
}


