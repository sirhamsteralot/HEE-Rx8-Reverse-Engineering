/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069880: Table 2D - 64 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069950: Table 2D - 308 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006995c: Table 2D - 309 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069968: Table 2D - 310 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069974: Table 2D - 311 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000699d4: Table 3D - 24 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000699f0: Table 3D - 25 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001c384; body bytes: 986; decompiled */

uint FUN_0001c384(void)

{
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint uVar5;
  float arg0;
  undefined4 uVar6;
  float fVar7;
  undefined4 extraout_fr0;
  undefined4 snapshot_mass_air_flow_ffffa9ec;
  undefined4 uVar9;
  float arg1;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if (engine_speed_rpm_ffffb548 < 5500.0) {
    if (engine_speed_rpm_ffffb548 < 5400.0) {
      DAT_ffffb068 = '\0';
    }
  }
  else {
    DAT_ffffb068 = '\x01';
  }
  uVar5 = (uint)closed_loop_active_ffffae1f;
  arg1 = 1.0;
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  fVar7 = engine_speed_rpm_ffffb548;
  if ((uVar5 == 1) || (DAT_ffffb068 == '\0')) {
    arg0 = (float)rx8_divide_with_zero_fallback(0x41f00000,engine_speed_rpm_ffffb548);
    DAT_ffffae24 = rx8_min_float(arg0,arg1);
    DAT_ffffae2c = (float)lookup_3d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,fVar7,&tbl_table_3d_24_000699d4);
    DAT_ffffb020 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_64_00069880);
    DAT_ffffb024 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_00069894);
    DAT_ffffae30 = DAT_ffffb020 * DAT_ffffb024;
  }
  if (uVar5 == 0) {
    DAT_ffffaff0 = 0.09999999;
  }
  else {
    DAT_ffffaff0 = rx8_min_float(DAT_ffffaff0 + 0.05,arg1);
  }
  uVar9 = 0;
  uVar6 = rx8_decode_u16_affine(0x41000000,0,(int)engine_running_timer_ffffa424);
  DAT_ffffb008 = (float)lookup_3d_descriptor_scaled(uVar6,inferred_coolant_temperature_catalyst_temp_model_ffffa998,&DAT_00069980);
  if ((uVar5 == 1) || (DAT_ffffb068 == '\0')) {
    DAT_ffffb028 = (float)lookup_3d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,fVar7,&tbl_table_3d_25_000699f0);
    DAT_ffffb02c = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_000698a8);
    DAT_ffffae34 = DAT_ffffaff0 * DAT_ffffb008 * DAT_ffffb028 * DAT_ffffb02c;
    DAT_ffffae38 = DAT_ffffae24 * DAT_ffffae34;
    DAT_ffffae3c = rx8_divide_with_zero_fallback(DAT_ffffae24,DAT_ffffae30);
    DAT_ffffae40 = (float)lookup_2d_descriptor_scaled(DAT_ffffae3c,&tbl_table_2d_308_00069950);
    fVar7 = (float)rx8_divide_with_zero_fallback(DAT_ffffae2c,DAT_ffffae24);
    DAT_ffffae28 = rx8_min_float(fVar7,20.0);
    DAT_ffffb01a = rx8_encode_u8_affine_saturate(DAT_ffffae28 + -0.5,arg1,uVar9);
    if (DAT_ffffb01a == 0) {
      DAT_ffffb01a = 1;
    }
    else if (0x13 < DAT_ffffb01a) {
      DAT_ffffb01a = 0x13;
    }
    fVar7 = (float)rx8_decode_u8_affine(arg1,uVar9,(int)(char)DAT_ffffb01a);
    DAT_ffffae44 = DAT_ffffae2c - DAT_ffffae24 * fVar7;
    DAT_ffffae48 = rx8_divide_with_zero_fallback(DAT_ffffae24 - DAT_ffffae44,DAT_ffffae30)
    ;
    DAT_ffffb030 = (float)lookup_2d_descriptor_scaled(DAT_ffffae48,&tbl_table_2d_309_0006995c);
    DAT_ffffae4c = arg1 - DAT_ffffb030;
    DAT_ffffae50 = (arg1 - DAT_ffffae40) - DAT_ffffae4c;
    DAT_ffffae54 = DAT_ffffae38 * 0.9;
    fVar7 = 2.0;
    DAT_ffffae58 = DAT_ffffae54 * 2.0;
    DAT_ffffb034 = (float)lookup_2d_descriptor_scaled(DAT_ffffae54,&tbl_table_2d_310_00069968);
    DAT_ffffae5c = -((arg1 - (arg1 - 0.80999994) * DAT_ffffae38 * DAT_ffffae38 * 0.5) * DAT_ffffb034
                    * fVar7);
    DAT_ffffae60 = (float)lookup_2d_descriptor_scaled(DAT_ffffae58,&tbl_table_2d_311_00069974);
    DAT_ffffae64 = (float)rx8_divide_with_zero_fallback
                                    (DAT_ffffae5c + DAT_ffffae60 + arg1,DAT_ffffae4c + DAT_ffffae50)
    ;
    DAT_ffffae6c = (-1.0 - DAT_ffffae40) - DAT_ffffae5c;
    fVar7 = DAT_ffffae50 + DAT_ffffae40 * DAT_ffffae4c;
    if (DAT_ffffb01a == 1) {
      fVar7 = (float)rx8_divide_with_zero_fallback();
      DAT_ffffaec4 = fVar7 * (DAT_ffffae6c * DAT_ffffae40 - DAT_ffffae50 * DAT_ffffae64);
      DAT_ffffae70 = (float)rx8_divide_with_zero_fallback
                                      (DAT_ffffae50 * DAT_ffffaec4,DAT_ffffae40);
      bVar2 = 3;
      puVar4 = &DAT_ffffae74;
      do {
        bVar2 = bVar2 + 1;
        *puVar4 = uVar9;
        puVar4 = puVar4 + 1;
      } while (bVar2 < 0x16);
      uVar5 = 8;
    }
    else if (DAT_ffffb01a == 2) {
      DAT_ffffae70 = (DAT_ffffae40 + DAT_ffffae6c * (DAT_ffffae40 + arg1)) - DAT_ffffae60;
      fVar7 = (float)rx8_divide_with_zero_fallback(DAT_ffffae40);
      DAT_ffffaec4 = fVar7 * (DAT_ffffae70 * DAT_ffffae40 - DAT_ffffae50 * DAT_ffffae64);
      DAT_ffffae74 = rx8_divide_with_zero_fallback
                               (DAT_ffffae50 * DAT_ffffaec4,DAT_ffffae40);
      bVar2 = 4;
      puVar4 = &DAT_ffffae78;
      do {
        bVar2 = bVar2 + 1;
        *puVar4 = uVar9;
        puVar4 = puVar4 + 1;
      } while (bVar2 < 0x16);
      uVar5 = 0xc;
    }
    else {
      DAT_ffffae70 = (DAT_ffffae40 + DAT_ffffae6c * (DAT_ffffae40 + arg1)) - DAT_ffffae60;
      for (bVar2 = 3; bVar2 <= DAT_ffffb01a; bVar2 = bVar2 + 1) {
        *(float *)(&DAT_ffffae68 + (uint)bVar2 * 4) =
             *(float *)(&DAT_ffffae68 + (bVar2 - 1) * 4) * (DAT_ffffae40 + arg1) -
             *(float *)(&DAT_ffffae68 + (bVar2 - 2) * 4) * DAT_ffffae40;
      }
      bVar2 = DAT_ffffb01a + 1;
      bVar3 = DAT_ffffb01a + 2;
      DAT_ffffaec0 = *(float *)(&DAT_ffffae68 + (uint)DAT_ffffb01a * 4);
      fVar7 = (float)rx8_divide_with_zero_fallback(DAT_ffffae40,fVar7);
      DAT_ffffaec4 = fVar7 * (DAT_ffffae40 * DAT_ffffaec0 - DAT_ffffae50 * DAT_ffffae64);
      uVar5 = rx8_divide_with_zero_fallback(DAT_ffffae50 * DAT_ffffaec4,DAT_ffffae40);
      *(undefined4 *)(&DAT_ffffae68 + (uint)bVar2 * 4) = extraout_fr0;
      puVar4 = (undefined4 *)(&DAT_ffffae68 + (uint)bVar3 * 4);
      for (; bVar3 < 0x16; bVar3 = bVar3 + 1) {
        *puVar4 = uVar9;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return uVar5;
}


