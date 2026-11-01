/* [ADDITIONAL SOURCE REVIEW]
 * leading_base_timing_calc [high]: RX8Defs 'Ignition Leading - Base Timing' plate; blends calibrated base with open-loop cap by weight b118; safe-mode cap via b12d.
 * RAM 0xffffb12d safe_mode (uint8): 0x1ee4a: 1 unless (b534==1 && 4<bc3d) or (b534==0 && 3<baed); selects Safe Mode CAL tables and the base-timing cap in 0x11f00/0x1206c.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069078: Ignition Leading - Base Timing (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000690cc: Ignition Timing Leading Advance (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00011f00; body bytes: 254; decompiled */

void leading_base_timing_calc(void)

{
  float *pfVar1;
  float fVar2;
  float snapshot_timing_blend_weight_ffffb118;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_timing_blend_weight_ffffb118 = timing_blend_weight_ffffb118;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffa608 = (float)lookup_3d_descriptor_scaled(inferred_ram_a7ac_ffffa7ac_ffffa7ac,inferred_ram_a834_ffffa834_ffffa834,&candidate_tbl_offthrottle_leading_3d_00069040);
  DAT_ffffa60c = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_leading_advance_3d_alt_0006905c);
  DAT_ffffa618 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&candidate_tbl_coolant_timing_multiplier_leading_00069018);
  leading_coolant_scaled_advance_term_ffffa5f0 = (0.0 - DAT_ffffa60c * DAT_ffffa618) + DAT_ffffa608;
  if (safe_mode_ffffcd60 == '\0') {
    DAT_ffffa5f8 = 80.0;
  }
  else {
    DAT_ffffa5f8 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_safe_mode_cap_single_00069094);
  }
  if (safe_mode_ffffb12d == '\x01') {
    DAT_ffffa610 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_safe_mode_advance_cap_000690b0);
    fVar2 = rx8_min_float(DAT_ffffa610,DAT_ffffa5f8);
    pfVar1 = (float *)&DAT_0006c760;
  }
  else {
    DAT_ffffa610 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_ignition_timing_leading_advance_000690cc);
    fVar2 = rx8_min_float(DAT_ffffa610,DAT_ffffa5f8);
    pfVar1 = (float *)&DAT_0006c764;
  }
  DAT_ffffa5fc = *pfVar1 + fVar2;
  DAT_ffffa614 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_ignition_leading_base_timing_00069078);
  fVar2 = rx8_min_float(DAT_ffffa614,DAT_ffffa5f8);
  leading_base_timing_final_ffffa5e8 = DAT_ffffa5fc * snapshot_timing_blend_weight_ffffb118 + (fVar2 + 0.0) * (1.0 - snapshot_timing_blend_weight_ffffb118);
  return;
}


