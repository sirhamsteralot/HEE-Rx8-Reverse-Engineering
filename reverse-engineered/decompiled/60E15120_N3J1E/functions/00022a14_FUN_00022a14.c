/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a354: Throttle Pedal Percent Decreasing Filter Factor (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a368: Table 2D - 132 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a37c: Table 2D - 133 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a390: Table 2D - 134 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a3a4: Table 2D - 135 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a3b8: Table 2D - 136 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a3cc: Table 2D - 137 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a3e0: Table 2D - 138 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a3f4: Table 2D - 139 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a408: Table 2D - 140 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a41c: Table 2D - 141 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a430: Table 2D - 142 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a444: Table 2D - 143 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [RX8DEFS 2026-09-30 00022a14]
 * Suggested interpretation: inferred_update_throttle_plate_request_filter.
 * Confidence: filter mechanics verified; throttle and gear meanings partly upstream.
 * Descriptors 6a354, 6a3cc, 6a3e0, 6a3f4, 6a408 are RPM-indexed in this function, including indirect puVar5 selection missed by the old direct-call inventory. 6a3cc/6a3e0 set ffffb3dc, compared to ffffb38c with 2.0 hysteresis. 6a3f4/6a408 supply ffffb3f0; ffffb3e0 sums it with coolant correction ffffb3d8. Final coefficient ffffb3d0 is clamped and used by rx8_first_order_filter(ffffb3cc, ffffb38c, coefficient, tolerance), then bounded by ffffb2c4. Exact gear-flag identities and increase/decrease naming are not independently established.
 */
/* ROM address: 0x00022a14; body bytes: 646; decompiled */

undefined4 FUN_00022a14(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined4 extraout_r0;
  undefined4 uVar4;
  undefined *puVar5;
  float arg0;
  float arg1;
  float arg3;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  float fVar7;
  
  cVar3 = DAT_ffffb2ce;
  cVar2 = DAT_ffffb2cd;
  cVar1 = DAT_ffffb2cc;
  arg3 = 1e-05;
  fVar7 = DAT_ffffa9bc;
  uVar4 = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffb3d4 = rx8_first_order_filter(DAT_ffffa9bc,DAT_ffffb3d4,0.1,1e-05);
  if (DAT_ffffb3d4 - fVar7 < 2.0) {
    if (DAT_ffffb3d4 - fVar7 < -2.0) {
      DAT_ffffb3ed = '\0';
    }
  }
  else {
    DAT_ffffb3ed = '\x01';
  }
  if (DAT_ffffb534 == '\x01') {
    if (cVar1 == '\x01') {
      puVar5 = &tbl_throttle_pedal_percent_decreasing_filter_factor_0006a354;
    }
    else {
      if (cVar2 != '\x01') {
        if (cVar3 == '\x01') {
          puVar5 = &tbl_table_2d_133_0006a37c;
        }
        else {
          puVar5 = &tbl_table_2d_134_0006a390;
        }
        DAT_ffffb3e4 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
        goto LAB_00022b5c;
      }
      puVar5 = &tbl_table_2d_132_0006a368;
    }
    DAT_ffffb3e4 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
  }
  else if (DAT_ffffb53a == '\0') {
    if (DAT_ffffca4c == '\x01') {
      puVar5 = &tbl_throttle_pedal_percent_decreasing_filter_factor_0006a354;
    }
    else {
      puVar5 = &tbl_table_2d_132_0006a368;
    }
    DAT_ffffb3e4 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
  }
  else {
    DAT_ffffb3e4 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_134_0006a390);
  }
LAB_00022b5c:
  DAT_ffffb3e8 = (float)lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_135_0006a3a4);
  DAT_ffffb3d8 = (float)lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_136_0006a3b8);
  if (((cVar1 == '\x01') || (cVar2 == '\x01')) || (cVar3 == '\x01')) {
    puVar5 = &tbl_table_2d_137_0006a3cc;
  }
  else {
    puVar5 = &tbl_table_2d_138_0006a3e0;
  }
  DAT_ffffb3dc = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
  if (DAT_ffffb38c <= DAT_ffffb3dc) {
    if (DAT_ffffb38c <= DAT_ffffb3dc - 2.0) {
      DAT_ffffb3ee = '\x01';
    }
  }
  else {
    DAT_ffffb3ee = '\0';
  }
  if (DAT_ffffb3ee != '\x01') {
    DAT_ffffb3e0 = 0.25;
    goto LAB_00022c9a;
  }
  if (DAT_ffffb534 == '\x01') {
    if (cVar1 == '\x01') {
      puVar5 = &tbl_table_2d_139_0006a3f4;
    }
    else {
      if (cVar2 != '\x01') {
        if (cVar3 == '\x01') {
          puVar5 = &tbl_table_2d_141_0006a41c;
        }
        else {
          puVar5 = &tbl_table_2d_142_0006a430;
        }
        DAT_ffffb3f0 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
        goto LAB_00022c84;
      }
      puVar5 = &tbl_table_2d_140_0006a408;
    }
    DAT_ffffb3f0 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
  }
  else if (DAT_ffffb53a == '\0') {
    if (DAT_ffffca4c == '\x01') {
      puVar5 = &tbl_table_2d_139_0006a3f4;
    }
    else {
      puVar5 = &tbl_table_2d_140_0006a408;
    }
    DAT_ffffb3f0 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,puVar5);
  }
  else {
    DAT_ffffb3f0 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_142_0006a430);
  }
LAB_00022c84:
  DAT_ffffb3e0 = DAT_ffffb3d8 + DAT_ffffb3f0;
LAB_00022c9a:
  fVar7 = 1.0;
  if (DAT_ffffb3ed == '\0') {
    fVar7 = 1.0;
    arg0 = DAT_ffffb3e4 + DAT_ffffb3e8;
    arg1 = 0.0;
  }
  else {
    arg0 = DAT_ffffb3e0;
    arg1 = (float)lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_143_0006a444);
    DAT_ffffb3f4 = arg1;
  }
  DAT_ffffb3d0 = rx8_clamp_float(arg0,arg1,fVar7);
  if ((DAT_ffffcc9b == '\x01') && (DAT_ffffcc9c == '\x01')) {
    DAT_ffffb38c = 5.0;
    uVar4 = 1;
  }
  else {
    fVar7 = rx8_first_order_filter(DAT_ffffb3cc,DAT_ffffb38c,DAT_ffffb3d0,arg3);
    DAT_ffffb38c = rx8_min_float(DAT_ffffb2c4,fVar7);
    uVar4 = extraout_r0;
  }
  return uVar4;
}


