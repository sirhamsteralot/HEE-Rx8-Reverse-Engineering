/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069918: Table 2D - 69 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006992c: Table 2D - 305 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069938: Table 2D - 306 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069944: Table 2D - 307 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069a0c: Table 3D - 26 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069a28: Table 3D - 27 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069a44: Table 3D - 28 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069af8: Table 3D - 108 (RX8Defs data pointer, axes and dimensions match).
 */
/* [RX8DEFS 2026-09-30 0001ce6c]
 * Suggested interpretation: inferred_update_fueling_corrections_and_enrichment_floor.
 * Confidence: RPM input and gated assignment verified; minimum/enrichment purpose upstream.
 * Descriptor 69918 (data 6f858, seven uint16 values, RPM axis 6f83c) is evaluated only when ffffb128 is nonzero; result is written to ffffb00c. The local routine does not itself apply a minimum operation to this value. Do not infer a complete function purpose from this single lookup.
 */
/* ROM address: 0x0001ce6c; body bytes: 712; decompiled */

undefined4 FUN_0001ce6c(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar7;
  float fVar8;
  
  sVar2 = DAT_ffffae18;
  cVar1 = engine_stopped_latch_ffffa41c;
  iVar5 = (int)DAT_ffffb010;
  if (DAT_ffffaa70 < 1.25) {
    if (DAT_ffffaa70 < 1.33) {
      DAT_ffffb069 = '\0';
    }
  }
  else {
    DAT_ffffb069 = '\x01';
  }
  uVar6 = mass_air_flow_ffffa9ec;
  fVar7 = DAT_ffffad20;
  fVar8 = inferred_coolant_temperature_ffffa98c;
  if (cranking_active_ffffaa62_ffffaa62 == '\x01') {
    if (DAT_ffffb53a == '\x01') {
      puVar4 = &tbl_table_3d_26_00069a0c;
    }
    else {
      puVar4 = &tbl_table_3d_27_00069a28;
    }
    DAT_ffffae00 = lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,puVar4);
  }
  else {
    DAT_ffffae00 = lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,engine_load_ffffc0b4,&tbl_table_3d_28_00069a44);
  }
  if ((DAT_ffffaa81 == '\0') || (cVar1 == '\x01')) {
    DAT_ffffb01b = '\0';
    iVar5 = 0;
  }
  else if (DAT_ffffb069 == '\x01') {
    DAT_ffffb01b = '\x01';
    iVar5 = rx8_add_u16_saturate(iVar5,1);
    DAT_ffffb06c = '\x01';
  }
  else {
    DAT_ffffb01b = '\0';
  }
  if ((((DAT_ffffb06c == '\x01') && (DAT_ffffb01b == '\0')) && (DAT_ffffb060 < 3)) && (fVar7 < 0.5))
  {
    DAT_ffffb018 = 1;
  }
  uVar3 = rx8_lookup_2d_raw_u16(uVar6,&tbl_table_2d_306_00069938);
  if (0.5 <= fVar7) {
    if (uVar3 < DAT_ffffb018) {
      DAT_ffffb018 = DAT_ffffb018 - uVar3;
    }
    else {
      DAT_ffffb018 = 0;
    }
  }
  fVar7 = 0.0;
  if (((fVar8 < 65.0) || (cVar1 == '\x01')) ||
     (((DAT_ffffb06c == '\x01' && ((DAT_ffffb01b == '\0' && (2 < DAT_ffffb060)))) &&
      (DAT_ffffb018 == 0)))) {
    DAT_ffffb012 = 0;
  }
  else {
    if ((DAT_ffffb06b != '\x01') || (DAT_ffffb01b != '\0')) {
      if ((DAT_ffffb01b == '\0') && (sVar2 == 0)) {
        DAT_ffffb014 = rx8_lookup_2d_raw_u16(uVar6,&tbl_table_2d_307_00069944);
        if (DAT_ffffb014 < DAT_ffffb012) {
          DAT_ffffb012 = DAT_ffffb012 - DAT_ffffb014;
        }
        else {
          DAT_ffffb012 = 0;
        }
      }
      goto LAB_0001d10e;
    }
    uVar6 = rx8_decode_u16_affine(0x42000000,0,iVar5);
    uVar6 = rx8_lookup_2d_raw_u16(uVar6,&tbl_table_2d_305_0006992c);
    DAT_ffffb05c = (undefined2)uVar6;
    DAT_ffffb012 = rx8_add_u16_saturate((int)(short)DAT_ffffb012,uVar6);
    if (0x124f < DAT_ffffb012) {
      DAT_ffffb012 = 0x1250;
    }
  }
  iVar5 = 0;
LAB_0001d10e:
  if ((sVar2 == 0) && (DAT_ffffb012 != 0)) {
    DAT_ffffae20 = 1;
    DAT_ffffaf1c = -0.002;
  }
  else {
    DAT_ffffae20 = 0;
    DAT_ffffaf1c = fVar7;
  }
  if ((DAT_ffffb06c == '\x01') && (DAT_ffffb01b == '\0')) {
    DAT_ffffb060 = rx8_add_u16_saturate((int)(short)DAT_ffffb060,1);
  }
  else {
    DAT_ffffb060 = 0;
  }
  DAT_ffffb010 = (short)iVar5;
  DAT_ffffb06b = DAT_ffffb01b;
  uVar6 = rx8_decode_u16_affine(0x41000000,fVar7,(int)engine_running_timer_ffffa424);
  uVar6 = lookup_3d_descriptor_scaled(uVar6,fVar8,&tbl_table_3d_108_00069af8);
  fVar8 = fVar7;
  if (extraout_fr0 <= DAT_ffffb000) {
    fVar8 = DAT_ffffb000 - extraout_fr0;
  }
  DAT_ffffb000 = fVar8;
  DAT_ffffb004 = extraout_fr0;
  if (DAT_ffffb128 != 0) {
    uVar6 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_69_00069918);
    fVar7 = extraout_fr0_00;
  }
  DAT_ffffb00c = fVar7;
  return uVar6;
}


