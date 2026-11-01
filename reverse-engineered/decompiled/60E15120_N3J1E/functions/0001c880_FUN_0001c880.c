/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000698bc: Table 2D - 65 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000698d0: Table 2D - 66 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000698e4: Table 2D - 67 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006999c: Table 3D - 22 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001c880; body bytes: 728; decompiled */

void FUN_0001c880(void)

{
  undefined4 snapshot_DAT_ffffaa78;
  float snapshot_DAT_ffffb21c;
  undefined4 snapshot_DAT_ffffb220;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  float *pfVar9;
  undefined4 *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_DAT_ffffb0d0;
  float snapshot_engine_speed_rpm_ffffb548;
  float arg3;
  
  fVar12 = vehicle_speed_ffffbbb4;
  snapshot_DAT_ffffb220 = DAT_ffffb220;
  snapshot_DAT_ffffb21c = DAT_ffffb21c;
  snapshot_DAT_ffffaa78 = DAT_ffffaa78;
  fVar11 = inferred_coolant_temperature_ffffa98c;
  arg3 = 1e-05;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_DAT_ffffb0d0 = inferred_ltft_bank1_ffffb0d0_ffffb0d0;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cVar4 = rx8_is_outside_tolerance_band(DAT_ffffb220,DAT_ffffb050,0x3727c5ac);
  cVar5 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffb0d0,DAT_ffffb054,arg3);
  DAT_ffffadf8 = (float)rx8_divide_with_zero_fallback(0x3f800000,diag_afr_word_a_ffffaa6c);
  pfVar9 = &DAT_ffffaec8;
  if (closed_loop_active_ffffae1f == '\0') {
    bVar8 = 1;
    inferred_lambda_actual_ffffadec_ffffadec = 1.0;
    DAT_ffffadf0 = 1.0;
    DAT_ffffadf4 = 1.0;
    do {
      pfVar9 = pfVar9 + 1;
      bVar8 = bVar8 + 1;
      *pfVar9 = 0.0;
    } while (bVar8 < 0x15);
  }
  else {
    if ((cVar4 == '\0') && (cVar5 == '\0')) {
      DAT_ffffaffc = 0.0;
    }
    else {
      DAT_ffffaffc = (((snapshot_DAT_ffffb0d0 - DAT_ffffb054) - DAT_ffffb058) + snapshot_DAT_ffffb21c) * 0.0;
    }
    fVar13 = 0.0;
    bVar8 = 1;
    iVar6 = 4;
    do {
      bVar8 = bVar8 + 1;
      fVar13 = fVar13 + *(float *)((int)&DAT_ffffaec8 + iVar6) * *(float *)(&DAT_ffffae68 + iVar6);
      iVar6 = iVar6 + 4;
    } while (bVar8 < 0x15);
    bVar8 = 1;
    DAT_ffffaec8 = (((DAT_ffffaf28 - DAT_ffffadf8) * DAT_ffffae64 +
                    (DAT_ffffadf8 - DAT_ffffb04c) * DAT_ffffaec4) - DAT_ffffaffc) + fVar13;
    do {
      pfVar9 = pfVar9 + 1;
      bVar8 = bVar8 + 1;
      *pfVar9 = *pfVar9 - DAT_ffffaffc;
    } while (bVar8 < 0x15);
    fVar13 = DAT_ffffaec8 + inferred_lambda_actual_ffffadec_ffffadec;
    if (fVar12 < 5.0) {
      if (fVar12 < 2.0) {
        DAT_ffffb070 = '\0';
      }
    }
    else {
      DAT_ffffb070 = '\x01';
    }
    if (snapshot_engine_speed_rpm_ffffb548 < 1500.0) {
      if (snapshot_engine_speed_rpm_ffffb548 < 1400.0) {
        DAT_ffffb071 = '\0';
      }
    }
    else {
      DAT_ffffb071 = '\x01';
    }
    if (snapshot_engine_load_ffffc0b4 <= 0.3) {
      if (snapshot_engine_load_ffffc0b4 <= 0.28) {
        DAT_ffffb072 = '\0';
      }
    }
    else {
      DAT_ffffb072 = '\x01';
    }
    if ((((DAT_ffffb070 != '\0') || (DAT_ffffb071 != '\0')) || (DAT_ffffb072 != '\x01')) ||
       ((-40.0 <= fVar11 || (DAT_ffffb53a != '\0')))) {
      DAT_ffffae14 = 0.0;
    }
    else {
      DAT_ffffae14 = (float)lookup_2d_descriptor_scaled(fVar11,&tbl_table_2d_66_000698d0);
    }
    DAT_ffffb03c = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_engine_load_ffffc0b4,&tbl_table_3d_22_0006999c);
    DAT_ffffb040 = (float)lookup_2d_descriptor_scaled(snapshot_DAT_ffffaa78,&tbl_table_2d_65_000698bc);
    fVar11 = rx8_max_float(DAT_ffffb040,DAT_ffffb03c);
    DAT_ffffb048 = rx8_max_float(fVar11,DAT_ffffae14);
    DAT_ffffb044 = (float)lookup_2d_descriptor_scaled(snapshot_DAT_ffffaa78,&tbl_table_2d_67_000698e4);
    inferred_lambda_actual_ffffadec_ffffadec = rx8_clamp_float(fVar13,DAT_ffffb048,DAT_ffffb044);
    fVar11 = rx8_first_order_filter(inferred_lambda_actual_ffffadec_ffffadec,DAT_ffffadf0,0.015325,arg3);
    fVar12 = rx8_first_order_filter(inferred_lambda_actual_ffffadec_ffffadec,DAT_ffffadf4,0.0078125,arg3);
    cVar4 = '\x14';
    uVar7 = 0x13;
    DAT_ffffadf0 = fVar11 - DAT_ffffaffc;
    puVar10 = &DAT_ffffaf1c;
    DAT_ffffadf4 = fVar12 - DAT_ffffaffc;
    do {
      cVar4 = cVar4 + -1;
      puVar10 = puVar10 + -1;
      *puVar10 = (&DAT_ffffaec8)[uVar7 & 0xff];
      uVar7 = uVar7 + 0xff;
    } while (cVar4 != '\0');
  }
  DAT_ffffb04c = DAT_ffffadf8;
  DAT_ffffb050 = snapshot_DAT_ffffb220;
  DAT_ffffb054 = snapshot_DAT_ffffb0d0;
  DAT_ffffb058 = snapshot_DAT_ffffb21c;
  return;
}


