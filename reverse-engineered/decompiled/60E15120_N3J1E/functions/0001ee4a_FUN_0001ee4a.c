/* [ADDITIONAL SOURCE REVIEW]
 * open_loop_fueling_targets [high]: When b12c==1: open-loop base/tip-in/target/rich-limit lookups (0x69cac/0x69cc0, 0x69e80/0x69e9c, 0x69cd4/0x69d10, safe-mode variants via b12d) -> b120; zeroes b120 in closed loop.
 * RAM 0xffffcd60 safe_mode (uint8): 0 = safe mode active: selects the knock threshold table pair in 0x336c4 (0x6b270/0x6b288 vs alts) and is checked in 0x200c6.
 * RAM 0xffffb170 ol_baro_base_correction (float): b170 = tbl 0x69cac/0x69cc0 'Open Loop Fuelling Base Correction (Throttle)'(baro) (safe-mode variant selected by cd60==0).
 * RAM 0xffffb174 ol_rich_limit (float): b174 = tbl 0x69ce8/0x69cfc 'Open Loop Fuelling Rich Limit'(baro) (safe-mode pair).
 * RAM 0xffffb190 ol_tip_in_target (float): b190 = 3D tbl 0x69e80/0x69eb8 'Open Loop Target - Throttle Tip In'(rpm, throttle).
 * RAM 0xffffb194 ol_target_3d (float): b194 = 3D tbl 0x69e9c/0x69ed4 'Open Loop Target'(load, rpm).
 * RAM 0xffffb198 ol_tip_in_implausible (float): b198 = 3D tip-in vs coolant-implausible tables 0x69ef0/0x69f28 (gear 5-6 vs 1-4 select by safe_mode b12d).
 * RAM 0xffffb19c ol_target_implausible_3d (float): b19c = 3D 'Open Loop Target - Coolant Temp Implausible'(load, rpm) 0x69f0c/0x69f44.
 * RAM 0xffffb130 ol_fuel_target_main (float): b130 = max(b170*b190, b194); normal OL target product.
 * RAM 0xffffb134 ol_coolant_correction (float): b134 = tbl 0x69cd4 'Open Loop Target - Coolant Temperature Correction'(coolant).
 * RAM 0xffffb138 ol_fuel_target_implausible (float): b138 = max(b174*b198, b19c); coolant-implausible OL target product.
 * RAM 0xffffb13c ol_temperature_correction_b (float): b13c = tbl 0x69d10 'Open Loop Temperature Correction #B'(coolant).
 * RAM 0xffffb150 ol_target_select (uint8): b150 != 0 (with coolant plausible b1d9) selects b120 = b130*b134; else blended implausible branch weighted by b11c.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069cac: Open Loop Fuelling Base Correction (Throttle) - Safe Mode (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069cc0: Open Loop Fuelling Base Correction (Throttle) (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069cd4: Open Loop Target - Coolant Temperature Correction (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069ce8: Open Loop Fuelling Rich Limit - Safe Mode (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069cfc: Open Loop Fuelling Rich Limit (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069d10: Open Loop Temperature Correction #B (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e80: Open Loop Target - Throttle Tip In (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069e9c: Open Loop Target (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069eb8: Open Loop Target - Throttle Tip In (Safe Mode) (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069ed4: Open Loop Target (Safe Mode) (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069ef0: Open Loop Target - Throttle Tip in - Coolant Temp Implausible B (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069f0c: Open Loop Target - Coolant Temp Implausible - Gear 5-6 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069f28: Open Loop Target - Throttle Tip in - Coolant Temp Implausible A (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069f44: Open Loop Target - Coolant Temp Implausible - Gear 1-4 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001ee4a; body bytes: 458; decompiled */

ushort open_loop_fueling_targets(void)

{
  undefined4 snapshot_inferred_throttle_position_ffffad44;
  float snapshot_fuel_blend_weight_ffffb11c;
  ushort uVar3;
  undefined *puVar4;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  undefined4 snapshot_inferred_barometric_pressure_ffffad14;
  
  snapshot_fuel_blend_weight_ffffb11c = fuel_blend_weight_ffffb11c;
  snapshot_inferred_throttle_position_ffffad44 = inferred_throttle_position_ffffad44;
  if (open_loop_active_ffffb12c != 1) {
    open_loop_fuel_target_ffffb120 = 0.0;
    return (ushort)open_loop_active_ffffb12c;
  }
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_inferred_barometric_pressure_ffffad14 = inferred_barometric_pressure_ffffad14;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  if (safe_mode_ffffcd60 == '\0') {
    ol_baro_base_correction_ffffb170 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_open_loop_fuelling_base_correction_throttle_safe_mode_00069cac);
    ol_tip_in_target_ffffb190 = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_inferred_throttle_position_ffffad44,&tbl_open_loop_target_throttle_tip_in_00069e80);
    puVar4 = &tbl_open_loop_target_00069e9c;
  }
  else {
    ol_baro_base_correction_ffffb170 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_open_loop_fuelling_base_correction_throttle_00069cc0);
    ol_tip_in_target_ffffb190 = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_inferred_throttle_position_ffffad44,&tbl_open_loop_target_throttle_tip_in_safe_mode_00069eb8);
    puVar4 = &tbl_open_loop_target_safe_mode_00069ed4;
  }
  ol_target_3d_ffffb194 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,puVar4);
  ol_fuel_target_main_ffffb130 = rx8_max_float(ol_baro_base_correction_ffffb170 * ol_tip_in_target_ffffb190,ol_target_3d_ffffb194);
  ol_coolant_correction_ffffb134 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_open_loop_target_coolant_temperature_correction_00069cd4);
  if (automatic_transmission_ffffb534 == '\x01') {
    if (4 < DAT_ffffbc3d) {
      safe_mode_ffffb12d = '\0';
      goto LAB_0001ef92;
    }
  }
  else if (3 < cruise_switch_code_ffffbaed) {
    safe_mode_ffffb12d = '\0';
    goto LAB_0001ef92;
  }
  safe_mode_ffffb12d = '\x01';
LAB_0001ef92:
  if (safe_mode_ffffb12d == '\x01') {
    ol_rich_limit_ffffb174 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_open_loop_fuelling_rich_limit_safe_mode_00069ce8);
    ol_tip_in_implausible_ffffb198 = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_inferred_throttle_position_ffffad44,&tbl_open_loop_target_throttle_tip_in_coolant_temp_implausible_b_00069ef0);
    puVar4 = &tbl_open_loop_target_coolant_temp_implausible_gear_5_6_00069f0c;
  }
  else {
    ol_rich_limit_ffffb174 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_open_loop_fuelling_rich_limit_00069cfc);
    ol_tip_in_implausible_ffffb198 = (float)lookup_3d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,snapshot_inferred_throttle_position_ffffad44,&tbl_open_loop_target_throttle_tip_in_coolant_temp_implausible_a_00069f28);
    puVar4 = &tbl_open_loop_target_coolant_temp_implausible_gear_1_4_00069f44;
  }
  ol_target_implausible_3d_ffffb19c = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,puVar4);
  ol_fuel_target_implausible_ffffb138 = rx8_max_float(ol_rich_limit_ffffb174 * ol_tip_in_implausible_ffffb198,ol_target_implausible_3d_ffffb19c);
  ol_temperature_correction_b_ffffb13c = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_open_loop_temperature_correction_b_00069d10);
  if (snapshot_inferred_coolant_temperature_ffffa98c < -40.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < -43.0) {
      DAT_ffffb1d9 = '\0';
    }
  }
  else {
    DAT_ffffb1d9 = '\x01';
  }
  if ((DAT_ffffb1d9 == '\x01') && (ol_target_select_ffffb150 != 0)) {
    open_loop_fuel_target_ffffb120 = ol_fuel_target_main_ffffb130 * ol_coolant_correction_ffffb134;
    uVar3 = ol_target_select_ffffb150;
  }
  else {
    uVar3 = 4;
    open_loop_fuel_target_ffffb120 = ol_fuel_target_implausible_ffffb138 * ol_temperature_correction_b_ffffb13c * snapshot_fuel_blend_weight_ffffb11c + (1.0 - snapshot_fuel_blend_weight_ffffb11c) * ol_fuel_target_main_ffffb130 * ol_coolant_correction_ffffb134
    ;
  }
  return uVar3;
}


