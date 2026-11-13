/* [ADDITIONAL SOURCE REVIEW]
 * knock_threshold_setup [high]: 3D load/RPM level tables 0x6b2b8/0x6b2f0/0x6b2d4/0x6b304 -> a328; raw u16 thresholds 0x6b270/0x6b27c and 0x6b288/0x6b294 -> c090/c092 -> a37e/a37c (defaults 94/193); stability check -> c05d and c0ac hold counter; latches c078 = a324.
 * RAM 0xffffa324 knock_detected (uint8): Set by 0xc486: a364 <= a330 (integrated knock level over threshold); latched into c078 by 0x336c4.
 * RAM 0xffffc092 knock_threshold_b_raw (uint16): Raw u16 threshold B from tbl 0x6b288 (or alt 0x6b294 when cd60 set); moved to a37c.
 * RAM 0xffffc0ac knock_transient_hold_counter (uint16): Counts down tbl 0x6b264 (raw u8 << 1 = 20 cycles) while conditions are stable; expiry sets c05d=1.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b270: Ignition Timing Threshold A - Knock Retard Reset Off (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b288: Ignition Timing Threshold B - Knock Retard Reset Off (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000336c4; body bytes: 510; decompiled */

char knock_threshold_setup(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float snapshot_coolant_timing_derate_leading_ffffa750;
  float snapshot_coolant_timing_derate_trailing_ffffa754;
  float arg0;
  
  cVar3 = safe_mode_ffffcd60;
  cVar2 = DAT_ffffc094;
  cVar1 = DAT_ffffa415;
  arg0 = engine_speed_rpm_ffffb548;
  DAT_ffffc07c = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_knock_level_3d_a_0006b2b8);
  DAT_ffffc080 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,arg0,&tbl_knock_level_3d_c_0006b2f0);
  DAT_ffffc084 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,arg0,&tbl_knock_level_3d_b_0006b2d4);
  DAT_ffffc088 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,arg0,&tbl_knock_level_3d_d_0006b304);
  if ((cVar1 == '\0') || (cVar1 == '\f')) {
    DAT_ffffc08c = DAT_ffffc07c;
    if (cVar3 == '\x01') {
      DAT_ffffc08c = DAT_ffffc080;
    }
  }
  else {
    DAT_ffffc08c = DAT_ffffc084;
    if (cVar3 == '\x01') {
      DAT_ffffc08c = DAT_ffffc088;
    }
  }
  knock_level_threshold_ffffa328 = DAT_ffffc08c;
  if (cVar3 == '\0') {
    ppuVar6 = (undefined **)&tbl_ignition_timing_threshold_a_knock_retard_reset_off_0006b270;
  }
  else {
    ppuVar6 = &tbl_ignition_timing_threshold_a_alt_0006b27c;
  }
  knock_threshold_a_raw_ffffc090 = rx8_lookup_2d_raw_u16(arg0,ppuVar6);
  if (cVar3 == '\0') {
    ppuVar6 = (undefined **)&tbl_ignition_timing_threshold_b_knock_retard_reset_off_0006b288;
  }
  else {
    ppuVar6 = &tbl_ignition_timing_threshold_b_alt_0006b294;
  }
  knock_threshold_b_raw_ffffc092 = rx8_lookup_2d_raw_u16(arg0,ppuVar6);
  ref_knockLearn_Something__((int)knock_threshold_a_raw_ffffc090,(int)knock_threshold_b_raw_ffffc092);
  snapshot_coolant_timing_derate_leading_ffffa750 = coolant_timing_derate_leading_ffffa750;
  snapshot_coolant_timing_derate_trailing_ffffa754 = coolant_timing_derate_trailing_ffffa754;
  fVar7 = rx8_absolute_difference(arg0,DAT_ffffc06c);
  fVar8 = rx8_absolute_difference(engine_load_ffffc0b4,DAT_ffffc070);
  fVar9 = rx8_absolute_difference(inferred_ram_ad48_ffffad48_ffffad48,DAT_ffffc074);
  if ((((DAT_ffffc0a4 == 0.0) && (snapshot_coolant_timing_derate_leading_ffffa750 != 0.0)) || ((DAT_ffffc0a8 == 0.0 && (snapshot_coolant_timing_derate_trailing_ffffa754 != 0.0)))) ||
     (((60.0 <= fVar7 || (0.08 <= fVar8)) || (8.0 <= fVar9)))) {
    DAT_ffffc094 = '\x01';
  }
  else {
    DAT_ffffc094 = '\0';
  }
  DAT_ffffc0a4 = snapshot_coolant_timing_derate_leading_ffffa750;
  DAT_ffffc0a8 = snapshot_coolant_timing_derate_trailing_ffffa754;
  if (DAT_ffffc094 == '\0') {
    if (cVar2 != '\0') {
      uVar4 = rx8_lookup_2d_raw_u8(arg0,&tbl_knock_transient_hold_0006b264);
      knock_transient_hold_counter_ffffc0ac = (uVar4 & 0xff) << 1;
    }
    if (knock_transient_hold_counter_ffffc0ac == 0) {
      knock_transient_flag_ffffc05d = '\0';
    }
    else {
      knock_transient_hold_counter_ffffc0ac = knock_transient_hold_counter_ffffc0ac + -1;
    }
  }
  else {
    knock_transient_flag_ffffc05d = '\x01';
  }
  if (knock_transient_flag_ffffc05d == '\x01') {
    knock_filter_coeff_a_ffffc060 = 0x3e400000;
    puVar5 = &DAT_0007a23c;
  }
  else {
    knock_filter_coeff_a_ffffc060 = 0x3d800000;
    puVar5 = &DAT_0007a248;
  }
  knock_filter_coeff_b_ffffc064 = 0x3e004ea5;
  knock_filter_coeff_c_ffffc068 = *puVar5;
  knock_detected_latched_ffffc078 = knock_detected_ffffa324 != '\0';
  return knock_transient_flag_ffffc05d;
}


