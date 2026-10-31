/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ab70: Table 2D - 177 Might be Primary/Secondary Ratio (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ab84: Primary Injector Max Barometric Pressure Correction (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ac60: Secondary Injectors Allowed Threshold - Coolant Temperature Based (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ab98: Table 2D - 347 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030b08; body bytes: 880; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00030ea8) */

uint FUN_00030b08(void)

{
  char cVar1;
  byte snapshot_DAT_ffffbece;
  float snapshot_fuel_ratio_a_ffffbee4;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_fuel_volume_final_ffffbeb0;
  
  fVar8 = fuel_amount_per_rotation_b_ffffbeec;
  snapshot_fuel_ratio_a_ffffbee4 = fuel_ratio_a_ffffbee4;
  fVar6 = fuel_amount_per_rotation_d_ffffbedc;
  snapshot_DAT_ffffbece = DAT_ffffbece;
  cVar1 = DAT_ffffbecc;
  if (inferred_coolant_temperature_ffffa98c < 40.0) {
    DAT_ffffbf08 = 0.02;
  }
  else {
    DAT_ffffbf08 = 0.007;
  }
  fVar5 = engine_speed_rpm_ffffb548;
  fVar7 = fuel_amount_per_rotation_a_ffffbec8;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_fuel_volume_final_ffffbeb0 = fuel_volume_final_ffffbeb0;
  DAT_ffffbf24 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_0006ac74);
  if (fVar5 < DAT_ffffbf24) {
    if (fVar5 < DAT_ffffbf24 - 188.0) {
      DAT_ffffbf36 = '\0';
    }
  }
  else {
    DAT_ffffbf36 = '\x01';
  }
  DAT_ffffbf28 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_secondary_injectors_allowed_threshold_coolant_temperature_based_0006ac60);
  if (fVar5 < DAT_ffffbf28) {
    if (fVar5 < DAT_ffffbf28 - 188.0) {
      DAT_ffffbf37 = '\0';
    }
  }
  else {
    DAT_ffffbf37 = '\x01';
  }
  DAT_ffffbf2c = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_primary_injector_max_barometric_pressure_correction_0006ab84);
  DAT_ffffbf04 = fVar7;
  if (60.0 <= inferred_throttle_position_ffffad44) {
    DAT_ffffbf04 = DAT_ffffbf2c * fVar7;
  }
  if (snapshot_fuel_volume_final_ffffbeb0 < DAT_ffffbf04) {
    if (snapshot_fuel_volume_final_ffffbeb0 < DAT_ffffbf04 - DAT_ffffbf08) {
      DAT_ffffbf38 = '\0';
    }
  }
  else {
    DAT_ffffbf38 = '\x01';
  }
  if (snapshot_fuel_volume_final_ffffbeb0 < fVar7) {
    if (snapshot_fuel_volume_final_ffffbeb0 < fVar7 - DAT_ffffbf08) {
      DAT_ffffbf39 = '\0';
    }
  }
  else {
    DAT_ffffbf39 = '\x01';
  }
  if ((DAT_ffffbf36 == '\x01') || ((DAT_ffffbf37 == '\x01' && (DAT_ffffbf38 == '\x01')))) {
    DAT_ffffbecd = '\x01';
  }
  else {
    DAT_ffffbecd = '\0';
  }
  if ((DAT_ffffbf36 == '\x01') || ((DAT_ffffbf37 == '\x01' && (DAT_ffffbf39 == '\x01')))) {
    DAT_ffffbecc = '\x01';
  }
  else {
    DAT_ffffbecc = '\0';
  }
  if (DAT_ffffbecc == '\0') {
    DAT_ffffbef8 = 0.0;
    DAT_ffffbefc = 0.0;
    DAT_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0;
    DAT_ffffbef4 = 0.0;
  }
  else {
    fVar5 = (float)lookup_2d_descriptor_scaled(fVar5,&tbl_table_2d_177_might_be_primary_secondary_ratio_0006ab70);
    DAT_ffffbef8 = rx8_clamp_float(fVar5,0.0,1.0);
    DAT_ffffbefc = DAT_ffffbef8 * snapshot_fuel_volume_final_ffffbeb0;
    if (snapshot_fuel_ratio_a_ffffbee4 <= DAT_ffffbefc) {
      if (DAT_ffffbefc < fVar6) {
        fVar6 = DAT_ffffbefc;
      }
      DAT_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0 - fVar6;
      DAT_ffffbef4 = fVar6;
    }
    else {
      DAT_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0 - snapshot_fuel_ratio_a_ffffbee4;
      DAT_ffffbef4 = snapshot_fuel_ratio_a_ffffbee4;
    }
  }
  if ((DAT_ffffbef0 < fVar7) || ((DAT_ffffbecd != '\0' && (DAT_ffffbecc != '\x01')))) {
    if (DAT_ffffbef0 < fVar7 - 0.005) {
      DAT_ffffbece = 0;
    }
  }
  else {
    DAT_ffffbece = 1;
  }
  fVar7 = fVar7 + fVar8;
  if (DAT_ffffbef0 < fVar7) {
    if (DAT_ffffbef0 < fVar7 - 0.005) {
      DAT_ffffbf10 = 0;
    }
  }
  else {
    DAT_ffffbf10 = 1;
  }
  fVar8 = fuel_amount_per_rotation_c_ffffbed8 + fVar8;
  if (DAT_ffffbef0 < fVar8) {
    if (DAT_ffffbef0 < fVar8 - 0.005) {
      DAT_ffffbf11 = 0;
    }
  }
  else {
    DAT_ffffbf11 = 1;
  }
  if (DAT_ffffbecc == '\x01') {
    if (cVar1 == '\0') {
      DAT_ffffbf0c = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_347_check_datatype_0006ab98);
    }
    else if (DAT_ffffbf0c < 2) {
      DAT_ffffbf0c = '\0';
    }
    else {
      DAT_ffffbf0c = DAT_ffffbf0c - 1;
    }
    DAT_ffffbf0d = '\0';
  }
  else {
    if (cVar1 == '\x01') {
      DAT_ffffbf0d = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006aba4);
    }
    else if (DAT_ffffbf0d < 2) {
      DAT_ffffbf0d = '\0';
    }
    else {
      DAT_ffffbf0d = DAT_ffffbf0d - 1;
    }
    DAT_ffffbf0c = '\0';
  }
  uVar4 = (uint)snapshot_DAT_ffffbece;
  if (DAT_ffffbece == 1) {
    if (uVar4 == 0) {
      uVar4 = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006abb0);
      DAT_ffffbf0e = (byte)uVar4;
    }
    else {
      uVar4 = 1;
      if (DAT_ffffbf0e < 2) {
        DAT_ffffbf0e = '\0';
      }
      else {
        DAT_ffffbf0e = DAT_ffffbf0e - 1;
      }
    }
    DAT_ffffbf0f = '\0';
  }
  else {
    if (uVar4 == 1) {
      uVar4 = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006abbc);
      DAT_ffffbf0f = (byte)uVar4;
    }
    else if (DAT_ffffbf0f < 2) {
      DAT_ffffbf0f = '\0';
    }
    else {
      DAT_ffffbf0f = DAT_ffffbf0f - 1;
    }
    DAT_ffffbf0e = '\0';
  }
  return uVar4;
}


