/* [ADDITIONAL SOURCE REVIEW]
 * primary_secondary_fuel_split [high]: Computes the primary/secondary split in the fuel task 0x20e40 (called between 0x30948 calculate_fuel_amount_per_rotation and 0x30f5c): rpm gates bf36/bf37 from coolant lookups tbl 0x6ac74 (flat 6250) / tbl 0x6ac60 (Secondary Injectors Allowed Threshold), fuel gates bf38/bf39 vs bec8/beb0 (WOT baro correction tbl 0x6ab84), then becd/becc flags and split volumes bef0/bef4/bef8/befc by ratio tbl 0x6ab70 when becc==1. becd is OR-ed into the SSV on-condition by 0x2178c; becc is read by open-loop logic 0x1f0c4/0x1fd48. Dynamically verified in the SH-2E emulator: docs/investigations/60E15120_N3J1E/reviews/intake_solenoids/ssv_secondary_injector_link.py.
 * RAM 0xffffbecc secondary_split_gate_flag (uint8): becc = bf36 || (bf37 && bf39), computed in 0x30b08: 0 => all fuel to primaries (bef0=beb0, bef4=0), 1 => split by ratio tbl 0x6ab70; also read by open-loop request logic 0x1f0c4/0x1fd48 (b1db/b1da latches). Emulator-verified: set above the rpm/coolant gate with fuel demand, clear below (ssv_secondary_injector_link_log.txt).
 * RAM 0xffffbecd secondary_injectors_active_flag (uint8): becd = bf36 || (bf37 && bf38) in 0x30b08 (bf38 uses the WOT baro-corrected fuel gate); OR-ed into the SSV on-condition by 0x2178c (mov.w pool word 0xbecd at ROM 0x2188a). Emulator: becd=1 drives PEDR_W PE7 high with engine running and even at 250 C coolant.
 * RAM 0xffffbece primary_split_sufficient_flag (uint8): bece = (bef0 >= bec8) && !(becd && !becc) with 0.005 hysteresis, in 0x30b08; read by 0x30f5c to choose the all-primary pulse path when 0.
 * RAM 0xffffbf08 split_fuel_gate_hysteresis (float): Hysteresis band for the bf38/bf39 fuel gates in 0x30b08: 0.007 when coolant >= 40 C, else 0.02 (inline float compares); 32-bit pool value present in ROM.
 * RAM 0xffffbf0c secondary_split_on_delay_counter (uint8): Loaded from raw-u8 lookup tbl 0x6ab98(coolant) on the becc 0->1 edge, decrements while becc==1, cleared when becc==1 and prev was 1; consumed by 0x30f5c delay logic.
 * RAM 0xffffbf0d secondary_split_off_delay_counter (uint8): Loaded from raw-u8 lookup tbl 0x6aba4(coolant) on the becc 1->0 edge, decrements while becc==0; consumed by 0x30f5c delay logic.
 * RAM 0xffffbf10 split_covers_amounts_ab_flag (uint8): bf10 = bef0 >= bec8+beec (0.005 hysteresis) in 0x30b08.
 * RAM 0xffffbf11 split_covers_amounts_bc_flag (uint8): bf11 = bef0 >= bed8+beec (0.005 hysteresis) in 0x30b08.
 * RAM 0xffffbf24 split_high_rpm_threshold (float): lookup_2d_descriptor_scaled(coolant, tbl 0x6ac74) in 0x30b08; table data 0x78548 is flat u16 0x186a = 6250 rpm (scale 1.0) — the high-RPM override threshold.
 * RAM 0xffffbf28 secondary_allowed_rpm_threshold (float): lookup_2d_descriptor_scaled(coolant, tbl 0x6ac60 'Secondary Injectors Allowed Threshold - Coolant Temperature Based', data 0x78510, axis 0x784ec): u16 cells 3000 rpm at <= 0 C, 0 above ~20 C; confirmed by ROM cell dump and emulator lookup in 0x30b08.
 * RAM 0xffffbf2c primary_baro_correction (float): lookup_2d_descriptor_scaled(baro, tbl 0x6ab84 'Primary Injector Max Barometric Pressure Correction') in 0x30b08; scales bec8 into bf04 at throttle >= 60%.
 * RAM 0xffffbf04 split_fuel_gate_threshold (float): bf04 = bec8 (fuel_amount_per_rotation_a), or bec8*bf2c when throttle >= 60% WOT; beb0 is compared against it for bf38 in 0x30b08.
 * RAM 0xffffbf36 high_rpm_override_flag (uint8): bf36 = rpm >= bf24 (tbl 0x6ac74) with a 188 rpm hysteresis band, in 0x30b08; forces the secondary split (and SSV) at very high rpm.
 * RAM 0xffffbf37 secondary_allowed_rpm_flag (uint8): bf37 = rpm >= bf28 (tbl 0x6ac60 coolant-based Secondary Injectors Allowed Threshold) with 188 rpm hysteresis, in 0x30b08.
 * RAM 0xffffbf38 split_fuel_gate_wot_flag (uint8): bf38 = beb0 >= bf04 (WOT-aware threshold) with bf08 hysteresis, in 0x30b08; part of becd.
 * RAM 0xffffbf39 split_fuel_gate_flag (uint8): bf39 = beb0 >= bec8 with bf08 hysteresis, in 0x30b08; part of becc.
 * RAM 0xffffbef0 fuel_volume_primary_split (float): Primary-side fuel volume after the 0x30b08 split: beb0 when becc==0, else beb0 minus the secondary share; converted to pulse time in 0x30f5c (x6e7 / 250.0).
 * RAM 0xffffbef4 fuel_volume_secondary_split (float): Secondary-side fuel volume from the 0x30b08 split (0 when becc==0); converted to pulse time in 0x30f5c (x6e7 / 475.93).
 * RAM 0xffffbef8 primary_secondary_split_ratio (float): Ratio lookup_2d_descriptor_scaled(rpm, tbl 0x6ab70) clamped to [0,1] in 0x30b08; used to split beb0 into bef0/bef4 when becc==1.
 * RAM 0xffffbefc fuel_volume_secondary_amount (float): befc = bef8 * beb0, the uncapped secondary amount in 0x30b08 (capped against bec8/bedc when computing bef4).
 */
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

uint primary_secondary_fuel_split(void)

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
  snapshot_DAT_ffffbece = primary_split_sufficient_flag_ffffbece;
  cVar1 = secondary_split_gate_flag_ffffbecc;
  if (inferred_coolant_temperature_ffffa98c < 40.0) {
    split_fuel_gate_hysteresis_ffffbf08 = 0.02;
  }
  else {
    split_fuel_gate_hysteresis_ffffbf08 = 0.007;
  }
  fVar5 = engine_speed_rpm_ffffb548;
  fVar7 = fuel_amount_per_rotation_a_ffffbec8;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_fuel_volume_final_ffffbeb0 = fuel_volume_final_ffffbeb0;
  split_high_rpm_threshold_ffffbf24 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_0006ac74);
  if (fVar5 < split_high_rpm_threshold_ffffbf24) {
    if (fVar5 < split_high_rpm_threshold_ffffbf24 - 188.0) {
      high_rpm_override_flag_ffffbf36 = '\0';
    }
  }
  else {
    high_rpm_override_flag_ffffbf36 = '\x01';
  }
  secondary_allowed_rpm_threshold_ffffbf28 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_secondary_injectors_allowed_threshold_coolant_temperature_based_0006ac60);
  if (fVar5 < secondary_allowed_rpm_threshold_ffffbf28) {
    if (fVar5 < secondary_allowed_rpm_threshold_ffffbf28 - 188.0) {
      secondary_allowed_rpm_flag_ffffbf37 = '\0';
    }
  }
  else {
    secondary_allowed_rpm_flag_ffffbf37 = '\x01';
  }
  primary_baro_correction_ffffbf2c = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_primary_injector_max_barometric_pressure_correction_0006ab84);
  split_fuel_gate_threshold_ffffbf04 = fVar7;
  if (60.0 <= inferred_throttle_position_ffffad44) {
    split_fuel_gate_threshold_ffffbf04 = primary_baro_correction_ffffbf2c * fVar7;
  }
  if (snapshot_fuel_volume_final_ffffbeb0 < split_fuel_gate_threshold_ffffbf04) {
    if (snapshot_fuel_volume_final_ffffbeb0 < split_fuel_gate_threshold_ffffbf04 - split_fuel_gate_hysteresis_ffffbf08) {
      split_fuel_gate_wot_flag_ffffbf38 = '\0';
    }
  }
  else {
    split_fuel_gate_wot_flag_ffffbf38 = '\x01';
  }
  if (snapshot_fuel_volume_final_ffffbeb0 < fVar7) {
    if (snapshot_fuel_volume_final_ffffbeb0 < fVar7 - split_fuel_gate_hysteresis_ffffbf08) {
      split_fuel_gate_flag_ffffbf39 = '\0';
    }
  }
  else {
    split_fuel_gate_flag_ffffbf39 = '\x01';
  }
  if ((high_rpm_override_flag_ffffbf36 == '\x01') || ((secondary_allowed_rpm_flag_ffffbf37 == '\x01' && (split_fuel_gate_wot_flag_ffffbf38 == '\x01')))) {
    secondary_injectors_active_flag_ffffbecd = '\x01';
  }
  else {
    secondary_injectors_active_flag_ffffbecd = '\0';
  }
  if ((high_rpm_override_flag_ffffbf36 == '\x01') || ((secondary_allowed_rpm_flag_ffffbf37 == '\x01' && (split_fuel_gate_flag_ffffbf39 == '\x01')))) {
    secondary_split_gate_flag_ffffbecc = '\x01';
  }
  else {
    secondary_split_gate_flag_ffffbecc = '\0';
  }
  if (secondary_split_gate_flag_ffffbecc == '\0') {
    primary_secondary_split_ratio_ffffbef8 = 0.0;
    fuel_volume_secondary_amount_ffffbefc = 0.0;
    fuel_volume_primary_split_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0;
    fuel_volume_secondary_split_ffffbef4 = 0.0;
  }
  else {
    fVar5 = (float)lookup_2d_descriptor_scaled(fVar5,&tbl_table_2d_177_might_be_primary_secondary_ratio_0006ab70);
    primary_secondary_split_ratio_ffffbef8 = rx8_clamp_float(fVar5,0.0,1.0);
    fuel_volume_secondary_amount_ffffbefc = primary_secondary_split_ratio_ffffbef8 * snapshot_fuel_volume_final_ffffbeb0;
    if (snapshot_fuel_ratio_a_ffffbee4 <= fuel_volume_secondary_amount_ffffbefc) {
      if (fuel_volume_secondary_amount_ffffbefc < fVar6) {
        fVar6 = fuel_volume_secondary_amount_ffffbefc;
      }
      fuel_volume_primary_split_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0 - fVar6;
      fuel_volume_secondary_split_ffffbef4 = fVar6;
    }
    else {
      fuel_volume_primary_split_ffffbef0 = snapshot_fuel_volume_final_ffffbeb0 - snapshot_fuel_ratio_a_ffffbee4;
      fuel_volume_secondary_split_ffffbef4 = snapshot_fuel_ratio_a_ffffbee4;
    }
  }
  if ((fuel_volume_primary_split_ffffbef0 < fVar7) || ((secondary_injectors_active_flag_ffffbecd != '\0' && (secondary_split_gate_flag_ffffbecc != '\x01')))) {
    if (fuel_volume_primary_split_ffffbef0 < fVar7 - 0.005) {
      primary_split_sufficient_flag_ffffbece = 0;
    }
  }
  else {
    primary_split_sufficient_flag_ffffbece = 1;
  }
  fVar7 = fVar7 + fVar8;
  if (fuel_volume_primary_split_ffffbef0 < fVar7) {
    if (fuel_volume_primary_split_ffffbef0 < fVar7 - 0.005) {
      split_covers_amounts_ab_flag_ffffbf10 = 0;
    }
  }
  else {
    split_covers_amounts_ab_flag_ffffbf10 = 1;
  }
  fVar8 = fuel_amount_per_rotation_c_ffffbed8 + fVar8;
  if (fuel_volume_primary_split_ffffbef0 < fVar8) {
    if (fuel_volume_primary_split_ffffbef0 < fVar8 - 0.005) {
      split_covers_amounts_bc_flag_ffffbf11 = 0;
    }
  }
  else {
    split_covers_amounts_bc_flag_ffffbf11 = 1;
  }
  if (secondary_split_gate_flag_ffffbecc == '\x01') {
    if (cVar1 == '\0') {
      secondary_split_on_delay_counter_ffffbf0c = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_347_check_datatype_0006ab98);
    }
    else if (secondary_split_on_delay_counter_ffffbf0c < 2) {
      secondary_split_on_delay_counter_ffffbf0c = '\0';
    }
    else {
      secondary_split_on_delay_counter_ffffbf0c = secondary_split_on_delay_counter_ffffbf0c - 1;
    }
    secondary_split_off_delay_counter_ffffbf0d = '\0';
  }
  else {
    if (cVar1 == '\x01') {
      secondary_split_off_delay_counter_ffffbf0d = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006aba4);
    }
    else if (secondary_split_off_delay_counter_ffffbf0d < 2) {
      secondary_split_off_delay_counter_ffffbf0d = '\0';
    }
    else {
      secondary_split_off_delay_counter_ffffbf0d = secondary_split_off_delay_counter_ffffbf0d - 1;
    }
    secondary_split_on_delay_counter_ffffbf0c = '\0';
  }
  uVar4 = (uint)snapshot_DAT_ffffbece;
  if (primary_split_sufficient_flag_ffffbece == 1) {
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


