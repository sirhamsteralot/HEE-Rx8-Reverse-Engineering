/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ab98: Table 2D - 347 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006abc8: Table 2D - 350 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030f5c; body bytes: 716; decompiled */

int FUN_00030f5c(void)

{
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  byte snapshot_DAT_ffffbf0c;
  char cVar3;
  char cVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fStack_38;
  float fStack_34;
  
  snapshot_DAT_ffffbf0c = DAT_ffffbf0c;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  fVar10 = 0.0;
  fVar11 = 6e+07;
  fVar7 = fuel_amount_per_rotation_a_ffffbec8;
  if (DAT_ffffbece == '\0') {
    fStack_38 = (float)rx8_divide_with_zero_fallback(DAT_ffffbef0 * 1.0 * 6e+07);
    fStack_34 = fVar10;
  }
  else {
    if (DAT_ffffbf10 == '\0') {
      if (fuel_amount_per_rotation_a_ffffbec8 + fuel_ratio_b_ffffbee8 <= DAT_ffffbef0) {
        fVar9 = fuel_amount_per_rotation_a_ffffbec8 * 1.0;
        fVar6 = (DAT_ffffbef0 - fuel_amount_per_rotation_a_ffffbec8) * 1.0;
        fVar8 = fVar6;
      }
      else {
        fVar6 = (DAT_ffffbef0 - fuel_ratio_b_ffffbee8) * 1.0;
        fVar8 = fuel_ratio_b_ffffbee8 * 1.0;
        fVar9 = fVar6;
      }
      fVar9 = fVar9 * 6e+07;
      fVar8 = fVar8 * 6e+07;
    }
    else if (DAT_ffffbf11 == '\0') {
      fVar6 = (DAT_ffffbef0 - fuel_amount_per_rotation_b_ffffbeec) * 1.0;
      fVar9 = fVar6 * 6e+07;
      fVar8 = fuel_amount_per_rotation_b_ffffbeec * 1.0 * 6e+07;
    }
    else {
      fVar6 = DAT_ffffbef0;
      fVar8 = fuel_amount_per_rotation_e_ffffbee0;
      fVar9 = fuel_amount_per_rotation_c_ffffbed8;
      if (DAT_ffffbef0 < fuel_amount_per_rotation_c_ffffbed8 + fuel_amount_per_rotation_e_ffffbee0) {
        fVar6 = (DAT_ffffbef0 - fuel_amount_per_rotation_c_ffffbed8) * 1.0;
        fVar8 = fVar6;
        fVar9 = fuel_amount_per_rotation_c_ffffbed8 * 1.0;
      }
      fVar9 = fVar9 * 6e+07;
      fVar8 = fVar8 * 6e+07;
    }
    fStack_38 = (float)rx8_divide_with_zero_fallback(fVar9,0x43b8bc6a,fVar6);
    fStack_34 = (float)rx8_divide_with_zero_fallback(fVar8,0x43edf70a);
  }
  fVar9 = 1e-05;
  cVar3 = rx8_is_outside_tolerance_band(0x43b8bc6a,fVar10,0x3727c5ac);
  DAT_ffffbf00 = fVar10;
  if (cVar3 != '\0') {
    DAT_ffffbf00 = fStack_38;
  }
  cVar4 = rx8_is_outside_tolerance_band(0x43edf70a,fVar10,fVar9);
  iVar5 = 0;
  DAT_ffffbec4 = fVar10;
  if (cVar4 != '\0') {
    DAT_ffffbec4 = fStack_34;
  }
  DAT_ffffbf34 = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_347_check_datatype_0006ab98);
  DAT_ffffbf35 = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_350_check_datatype_0006abc8);
  if (snapshot_DAT_ffffbf0c == 0) {
    if (((DAT_ffffbf0d == '\0') && (DAT_ffffbf0e == '\0')) && (DAT_ffffbf0f == '\0')) {
      iVar5 = 1;
    }
  }
  else if ((DAT_ffffbf34 < DAT_ffffbf35) || ((byte)(DAT_ffffbf34 - DAT_ffffbf35) < snapshot_DAT_ffffbf0c)) {
    iVar5 = 2;
  }
  else if (snapshot_DAT_ffffbf0c != (byte)(DAT_ffffbf34 - DAT_ffffbf35)) {
    iVar5 = 3;
  }
  if (iVar5 == 0) {
    DAT_ffffbf30 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c);
    fVar6 = rx8_first_order_filter(DAT_ffffbf00,DAT_ffffbebc,DAT_ffffbf30,fVar9);
  }
  else if (iVar5 == 1) {
    DAT_ffffbebc = DAT_ffffbf00;
    fVar6 = DAT_ffffbebc;
  }
  else if (iVar5 == 3) {
    DAT_ffffbf30 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c);
    fVar7 = rx8_first_order_filter(DAT_ffffbf00,DAT_ffffbebc,DAT_ffffbf30,fVar9);
    fVar6 = rx8_max_float(DAT_ffffbf00,fVar7);
  }
  else {
    fVar6 = fVar10;
    if (cVar3 != '\0') {
      fVar7 = rx8_min_float(fuel_volume_final_ffffbeb0,fVar7);
      fVar6 = (float)rx8_divide_with_zero_fallback(fVar7 * fVar11,0x43b8bc6a);
    }
  }
  DAT_ffffbebc = fVar6;
  cVar3 = rx8_is_outside_tolerance_band(0x43edf70a,fVar10,fVar9);
  cVar4 = rx8_is_outside_tolerance_band(DAT_ffffbec4,fVar10,fVar9);
  if (cVar3 != 0) {
    if (cVar4 == '\0') {
      fVar10 = (DAT_ffffbef4 * 1.0 * fVar11) / 475.93;
    }
    else {
      fVar10 = DAT_ffffbec0;
      if (0.0 < DAT_ffffbec4) {
        fVar10 = (DAT_ffffbef4 * 1.0 * fVar11) / 475.93;
      }
    }
  }
  DAT_ffffbec0 = fVar10;
  return (int)cVar3;
}


