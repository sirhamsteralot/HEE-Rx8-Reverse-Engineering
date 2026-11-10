/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b978: Table 2D - 379 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b998: Table 3D - 125 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00043e64; body bytes: 1054; decompiled */

undefined4 * FUN_00043e64(void)

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
  
  cVar2 = DAT_ffffcac9;
  DAT_ffffcad4 = rx8_first_order_filter(diag_afr_word_a_ffffaa6c,DAT_ffffcad4,0.25,1e-05);
  DAT_ffffcae0 = rx8_first_order_filter(DAT_ffffad20,DAT_ffffcae0,0.25,1e-05);
  uVar3 = DAT_ffffcb1e;
  fVar20 = 0.0;
  if (DAT_ffffd1c5 == '\x01') {
    bVar8 = 0;
    puVar6 = &DAT_ffffcb20;
    DAT_ffffcac4 = 0.0;
    DAT_ffffcad8 = 0.0;
    DAT_ffffcae8 = 0.0;
    DAT_ffffcb18 = 0.0;
    DAT_ffffcb36 = 0;
    DAT_ffffcb1c = 0;
    DAT_ffffcb1e = 0;
    DAT_ffffcb39 = 0;
    DAT_ffffcacc = '\0';
    DAT_ffffcacb = '\0';
    puVar7 = &DAT_ffffcaf0;
    DAT_ffffcaca = 0;
    do {
      *puVar7 = 0;
      bVar8 = bVar8 + 1;
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (bVar8 < 10);
    DAT_ffffcb5c = 0;
    puVar7 = (undefined4 *)rx8_add_u16_saturate((int)(short)DAT_ffffcb5a,1);
    DAT_ffffcb5a = (ushort)puVar7;
    fVar17 = DAT_ffffcad8;
    fVar18 = DAT_ffffcae8;
    fVar15 = DAT_ffffcb18;
    uVar3 = DAT_ffffcb1e;
    uVar10 = DAT_ffffcb36;
    if (1 < DAT_ffffcb5a) {
      DAT_ffffcb48 = DAT_ffffcad4;
      puVar7 = &DAT_ffffcb4c;
      DAT_ffffcb4c = DAT_ffffcae0;
      DAT_ffffcb5a = 0;
    }
  }
  else {
    iVar12 = (int)(short)DAT_ffffcb1e;
    iVar9 = (int)DAT_ffffcb36;
    fVar15 = DAT_ffffcb18;
    fVar18 = DAT_ffffcae8;
    fVar17 = DAT_ffffcad8;
    uVar14 = rx8_decode_u16_affine(0x42000000,0,iVar12);
    DAT_ffffcb44 = (float)lookup_2d_descriptor_scaled(uVar14,&PTR_CAL_table_845_0006b96c);
    DAT_ffffcaec = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_125_0006b998);
    if ((DAT_ffffcb5f == '\0') && (cVar2 == '\x01')) {
      DAT_ffffcb34 = DAT_ffffcb1c;
      DAT_ffffcb5c = 0x9c;
    }
    else if (DAT_ffffcb5c != 0) {
      DAT_ffffcb5c = DAT_ffffcb5c + -1;
    }
    if (cVar2 == '\x01') {
      if (DAT_ffffcb1c < 0xf424) {
        DAT_ffffcb1c = rx8_add_u16_saturate((int)(short)DAT_ffffcb1c,1);
      }
      if (uVar3 < 0xf424) {
        uVar3 = rx8_add_u16_saturate(iVar12,1);
      }
      fVar15 = rx8_min_float(100000.0,DAT_ffffcaec + fVar15);
      iVar9 = rx8_add_u16_saturate(iVar9,1);
      fVar16 = (float)rx8_decode_u16_affine(0x3f800000,fVar20,iVar9);
      DAT_ffffcac0 = fVar15 / fVar16;
    }
    else if ((DAT_ffffcb5f == '\x01') && ((fVar17 <= DAT_ffffcb44 || (DAT_ffffcb5c != 0)))) {
      uVar3 = 0;
      DAT_ffffcb1c = DAT_ffffcb34;
      iVar9 = 0;
      fVar15 = fVar20;
      fVar18 = fVar20;
      fVar17 = fVar20;
    }
    uVar10 = (undefined2)iVar9;
    DAT_ffffcb5a = rx8_add_u16_saturate((int)(short)DAT_ffffcb5a,1);
    if (1 < DAT_ffffcb5a) {
      if (cVar2 == '\x01') {
        fVar16 = rx8_absolute_difference(DAT_ffffcb48,DAT_ffffcad4);
        DAT_ffffcadc = rx8_min_float(fVar16,0.4);
        fVar17 = rx8_min_float(DAT_ffffcadc + fVar17,1000.0);
        fVar16 = rx8_absolute_difference(DAT_ffffcb4c,DAT_ffffcae0);
        DAT_ffffcae4 = rx8_min_float(fVar16,1.0);
        fVar18 = rx8_min_float(DAT_ffffcae4 + fVar18,2500.0);
      }
      DAT_ffffcb48 = DAT_ffffcad4;
      DAT_ffffcb4c = DAT_ffffcae0;
      DAT_ffffcb5a = 0;
    }
    cVar4 = rx8_is_outside_tolerance_band(fVar17,fVar20,0x3727c5ac);
    cVar5 = rx8_is_outside_tolerance_band(DAT_ffffcac0,fVar20,0x3727c5ac);
    if ((0x3a9 < DAT_ffffcb1c) || (((DAT_ffffcb5f == '\x01' && (cVar2 == '\0')) && (cVar4 != '\0')))
       ) {
      fVar15 = fVar20;
      if ((cVar4 == '\0') || (cVar5 == '\0')) {
        (&DAT_ffffcaf0)[DAT_ffffcb39] = fVar20;
        (&DAT_ffffcb20)[DAT_ffffcb39] = uVar3;
      }
      else {
        (&DAT_ffffcaf0)[DAT_ffffcb39] = fVar18 / (DAT_ffffcac0 * fVar17);
        (&DAT_ffffcb20)[DAT_ffffcb39] = uVar3;
        if (DAT_ffffcb39 < 9) {
          DAT_ffffcb39 = rx8_add_u8_saturate((int)(char)DAT_ffffcb39,1);
          fVar15 = fVar20;
        }
      }
      uVar10 = 0;
      uVar3 = 0;
      fVar18 = fVar15;
      fVar17 = fVar15;
      fVar20 = fVar15;
    }
    fVar16 = DAT_ffffcac4;
    if (((0x3a9 < DAT_ffffcb1c) && (DAT_ffffcacc == '\0')) && (fVar16 = fVar20, DAT_ffffcb1c != 0))
    {
      pfVar11 = (float *)&DAT_ffffcaf0;
      bVar8 = 0;
      psVar13 = &DAT_ffffcb20;
      fStack_38 = fVar20;
      do {
        sVar1 = *psVar13;
        psVar13 = psVar13 + 1;
        fVar16 = (float)rx8_decode_u16_affine(0x42000000,fVar20,(int)sVar1);
        fVar19 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        bVar8 = bVar8 + 1;
        fStack_38 = fStack_38 + fVar19 * fVar16;
      } while (bVar8 < 10);
      uVar14 = rx8_decode_u16_affine(0x42000000,fVar20,(int)(short)DAT_ffffcb1c);
      fVar16 = (float)rx8_divide_with_zero_fallback(fStack_38,uVar14);
      DAT_ffffcacc = '\x01';
    }
    DAT_ffffcac4 = fVar16;
    if (DAT_ffffcacc == '\x01') {
      DAT_ffffcb50 = (float)lookup_2d_descriptor_scaled(DAT_ffffc6ec,&PTR_PTR_0006b978);
      if (DAT_ffffcac4 < DAT_ffffcb50) {
        DAT_ffffcaca = 1;
      }
      else {
        DAT_ffffcacb = '\x01';
      }
    }
    if (DAT_ffffcacb == '\x01') {
      puVar7 = (undefined4 *)dtc_set_fault_x0(0x2c,1);
    }
    else {
      puVar7 = (undefined4 *)(uint)DAT_ffffcaca;
      if (puVar7 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
        puVar7 = (undefined4 *)dtc_set_fault_x0(0x2c,2);
      }
    }
  }
  DAT_ffffcb36 = uVar10;
  DAT_ffffcb1e = uVar3;
  DAT_ffffcb18 = fVar15;
  DAT_ffffcae8 = fVar18;
  DAT_ffffcad8 = fVar17;
  DAT_ffffcb5f = cVar2;
  return puVar7;
}


