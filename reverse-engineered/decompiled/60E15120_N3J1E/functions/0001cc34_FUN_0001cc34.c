/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000699b8: Closed Loop WOT Enrichment?? (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069a60: Table 3D - 29 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069a7c: Table 3D - 30 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001cc34; body bytes: 412; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001cda6) */

void FUN_0001cc34(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  cVar2 = DAT_ffffcac8;
  cVar1 = closed_loop_active_ffffae1f;
  fVar6 = DAT_ffffb21c;
  fVar5 = DAT_ffffaa70;
  fVar4 = rx8_absolute_difference(DAT_ffffaa70,lambda_target_ffffadfc);
  fVar7 = 0.0;
  if (cVar1 == '\x01') {
    if ((DAT_ffffb06a != '\0') || (fVar4 < 1.0)) {
      if (DAT_ffffaf20 < 0.02) {
        if (-0.02 <= DAT_ffffaf20) {
          DAT_ffffaf20 = 0.0;
        }
        else {
          DAT_ffffaf20 = DAT_ffffaf20 + 0.0005;
        }
      }
      else {
        DAT_ffffaf20 = DAT_ffffaf20 - 0.0005;
      }
    }
    else {
      DAT_ffffaf20 = fVar5 - lambda_target_ffffadfc;
    }
  }
  else {
    DAT_ffffaf20 = 0.0;
  }
  if (cVar2 == '\0') {
    puVar3 = &tbl_table_3d_29_00069a60;
  }
  else {
    puVar3 = &tbl_table_3d_30_00069a7c;
  }
  DAT_ffffae0c = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,puVar3);
  fVar5 = fVar7;
  if (1.0 <= fVar6) {
    fVar5 = rx8_min_float(fVar6 * 0.0,0.015);
  }
  DAT_ffffaf24 = fVar5;
  DAT_ffffae04 = rx8_first_order_filter(DAT_ffffaf24,DAT_ffffae04,0.0,1e-05);
  if (cVar1 == '\x01') {
    fVar7 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_throttle_position_ffffad44,&tbl_closed_loop_wot_enrichment_000699b8);
  }
  DAT_ffffae10 = fVar7;
  DAT_ffffae08 = ((DAT_ffffae0c - DAT_ffffae00) + DAT_ffffaf1c + DAT_ffffaf20) - DAT_ffffb000;
  fVar6 = rx8_max_float(DAT_ffffae10,DAT_ffffb00c);
  lambda_target_ffffadfc = rx8_clamp_float((((((DAT_ffffae0c - DAT_ffffae00) - DAT_ffffae04) + DAT_ffffb074 +
                                    0.0 + DAT_ffffaf1c + DAT_ffffaf20 + DAT_ffffaff8) - DAT_ffffb000
                                  ) - fVar6) + 1.0,0.85,1.05);
  DAT_ffffb06a = cVar1;
  return;
}


