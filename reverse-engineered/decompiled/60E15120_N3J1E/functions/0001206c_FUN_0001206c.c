/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069120: Ignition Timing Trailing Base (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069174: Ignition Timing Trailing Advance (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * trailing_base_timing_calc [high]: RX8Defs 'Ignition Timing Trailing Base' plate; same blend structure as 0x11f00.
 * RAM 0xffffa5f4 trailing_coolant_scaled_advance_term (float): Written by 0x1206c trailing_base_timing_calc (fmov.s fr2,@r1 0x120cc via mov.w pool 0x12176=0xa5f4 @0x120c4); read by 0x124d6 (mov.w pool 0x12684 @0x12588).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001206c; body bytes: 254; decompiled */

void trailing_base_timing_calc(void)

{
  float *pfVar1;
  float fVar2;
  float snapshot_timing_blend_weight_ffffb118;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_timing_blend_weight_ffffb118 = timing_blend_weight_ffffb118;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffa61c = (float)lookup_3d_descriptor_scaled(inferred_ram_a7ac_ffffa7ac_ffffa7ac,inferred_ram_a834_ffffa834_ffffa834,&candidate_tbl_offthrottle_trailing_3d_000690e8);
  DAT_ffffa620 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_trailing_advance_3d_alt_00069104);
  DAT_ffffa62c = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&candidate_tbl_coolant_timing_multiplier_trailing_0006902c);
  trailing_coolant_scaled_advance_term_ffffa5f4 = (0.0 - DAT_ffffa620 * DAT_ffffa62c) + DAT_ffffa61c;
  if (safe_mode_ffffcd60 == '\0') {
    DAT_ffffa600 = 80.0;
  }
  else {
    DAT_ffffa600 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_safe_mode_cap_single_trailing_0006913c);
  }
  if (safe_mode_ffffb12d == '\x01') {
    DAT_ffffa624 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_safe_mode_advance_cap_trailing_00069158);
    fVar2 = rx8_min_float(DAT_ffffa624,DAT_ffffa600);
    pfVar1 = (float *)&DAT_0006c774;
  }
  else {
    DAT_ffffa624 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_ignition_timing_trailing_advance_00069174);
    fVar2 = rx8_min_float(DAT_ffffa624,DAT_ffffa600);
    pfVar1 = (float *)&DAT_0006c778;
  }
  DAT_ffffa604 = *pfVar1 + fVar2;
  DAT_ffffa628 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_ignition_timing_trailing_base_00069120);
  fVar2 = rx8_min_float(DAT_ffffa628,DAT_ffffa600);
  trailing_base_timing_final_ffffa5ec = DAT_ffffa604 * snapshot_timing_blend_weight_ffffb118 + (fVar2 + 0.0) * (1.0 - snapshot_timing_blend_weight_ffffb118);
  return;
}


