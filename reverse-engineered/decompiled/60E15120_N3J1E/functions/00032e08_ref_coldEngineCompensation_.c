/* [ADDITIONAL SOURCE REVIEW]
 * warmup_fueling_compensation [high]: c014 = tbl 0x6ae28 'Warmup Fueling - Load Based Multiplier'(load) * 3D tbl 0x6ae3c 'Warmup Fueling'(coolant, catalyst-temp model); c018 = 3D tbl 0x6ae58 (or coolant-fault variant 0x6ae74)(rpm, coolant); c00c = c014 + c018; c010 = warmup-complete flag (catalyst-temp model >= 5 C, or >= 200 C when ce33).
 * RAM 0xffffc010 warmup_complete_flag (uint8): c010 = 1 when catalyst-temp model >= 5 C (or >= 200 C when ce33 set); selects warmup vs fault speed-based tables and tip-in table pair.
 * RAM 0xffffc014 warmup_load_multiplier (float): c014 = tbl 0x6ae28 'Warmup - Load Based Multiplier'(load) * 3D tbl 0x6ae3c 'Warmup Fueling'(coolant, cat model).
 * RAM 0xffffc018 warmup_rpm_multiplier (float): c018 = 3D tbl 0x6ae58 (or coolant-fault 0x6ae74)(rpm, coolant).
 * RAM 0xffffc00c warmup_enrichment_total (float): c00c = c014 + c018; feeds calc_fuel_volume_request (0x306e8: min(bf1c, c00c + b120)) and closed_loop_fuel_trim (0x307e0).
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ae28: Fuel Injection - Warmup Fueling - Load Based Multiplier (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ae3c: Fuel Injection - Warmup Fueling (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ae58: Fuel Injection - Warmup Fueling - Engine Speed Based (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ae74: Fuel Injection - Warmup Fueling - Engine Speed Based (Coolant Temp Fault) (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00032e08; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033124 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

void warmup_fueling_compensation(void)

{
  char cVar1;
  undefined **ppuVar2;
  float fVar3;
  float fVar4;
  float snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar1 = DAT_ffffce33;
  snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  fVar3 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_fuel_injection_warmup_fueling_load_based_multiplier_0006ae28);
  fVar4 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_fuel_injection_warmup_fueling_0006ae3c);
  if (((cVar1 == '\0') && (5.0 <= snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998)) || ((cVar1 == '\x01' && (200.0 <= snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998)))) {
    warmup_complete_flag_ffffc010 = '\x01';
  }
  else {
    warmup_complete_flag_ffffc010 = '\0';
  }
  warmup_load_multiplier_ffffc014 = fVar3 * fVar4;
  if (warmup_complete_flag_ffffc010 == '\x01') {
    ppuVar2 = (undefined **)&tbl_fuel_injection_warmup_fueling_engine_speed_based_0006ae58;
  }
  else {
    ppuVar2 = &tbl_fuel_injection_warmup_fueling_engine_speed_based_coolant_temp_fault_0006ae74;
  }
  warmup_rpm_multiplier_ffffc018 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,snapshot_inferred_coolant_temperature_ffffa98c,ppuVar2);
  warmup_enrichment_total_ffffc00c = warmup_load_multiplier_ffffc014 + warmup_rpm_multiplier_ffffc018;
  return;
}


