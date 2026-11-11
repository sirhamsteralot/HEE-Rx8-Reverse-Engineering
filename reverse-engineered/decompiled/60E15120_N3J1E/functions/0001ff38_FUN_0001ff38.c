/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069d88: Table 2D - 97 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069d9c: Table 2D - 98 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffb178 cl_load_threshold_2d_a (float): b178 = tbl 0x69d88(rpm); load compare with hysteresis -> b1b9.
 * RAM 0xffffb17c cl_load_threshold_2d_b (float): b17c = tbl 0x69d9c(rpm) -> b1bb.
 * RAM 0xffffb1b9 load_above_thresh_a (uint8): b1b9 = load >= b178 (hysteresis -0.04); part of OL band condition in 0x1ff38.
 * RAM 0xffffb1bb load_above_thresh_b (uint8): b1bb = load > b17c (hysteresis) in 0x1ff38.
 * RAM 0xffffb1ba rpm_above_800_flag (uint8): b1ba = rpm >= 1000 (clear below 800) in 0x1ff38.
 * RAM 0xffffb1bc rpm_above_5300_flag (uint8): b1bc = rpm > 5500 (clear below 5300) in 0x1ff38.
 * RAM 0xffffb1d8 coolant_above_97_flag (uint8): b1d8 = coolant >= 100 (clear below 97) in 0x1ff38.
 * RAM 0xffffb144 ol_condition_timer (uint16): b144 decremented when band condition (b154) holds; set to 0x493e (18750) when coolant < 97; b159 = timer-expired flag.
 * RAM 0xffffb154 ol_band_condition (uint8): b154 = b1b9 && !b1bb && b1ba && !b1bc (load/RPM band); feeds b144 countdown and blend_weight_update (0x200c6).
 * RAM 0xffffb159 ol_timer_expired (uint8): b159 = (b144 == 0 && b1d8); checked in 0x200c6 decay condition.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001ff38; body bytes: 334; decompiled */

uint FUN_0001ff38(void)

{
  bool bVar1;
  uint uVar2;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cl_load_threshold_2d_a_ffffb178 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_97_00069d88);
  cl_load_threshold_2d_b_ffffb17c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_98_00069d9c);
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_a_ffffb178) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_a_ffffb178 - 0.04) {
      load_above_thresh_a_ffffb1b9 = 0;
    }
  }
  else {
    load_above_thresh_a_ffffb1b9 = 1;
  }
  if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_b_ffffb17c) {
    if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_b_ffffb17c - 0.04) {
      load_above_thresh_b_ffffb1bb = '\0';
    }
  }
  else {
    load_above_thresh_b_ffffb1bb = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 1000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 800.0) {
      rpm_above_800_flag_ffffb1ba = 0;
    }
  }
  else {
    rpm_above_800_flag_ffffb1ba = 1;
  }
  if (snapshot_engine_speed_rpm_ffffb548 <= 5500.0) {
    if (snapshot_engine_speed_rpm_ffffb548 <= 5300.0) {
      rpm_above_5300_flag_ffffb1bc = '\0';
    }
  }
  else {
    rpm_above_5300_flag_ffffb1bc = '\x01';
  }
  uVar2 = (uint)load_above_thresh_a_ffffb1b9;
  if ((((uVar2 == 1) && (load_above_thresh_b_ffffb1bb == '\0')) && (uVar2 = (uint)rpm_above_800_flag_ffffb1ba, uVar2 == 1)) &&
     (uVar2 = (uint)rpm_above_5300_flag_ffffb1bc, uVar2 == 0)) {
    ol_band_condition_ffffb154 = 1;
    bVar1 = true;
  }
  else {
    ol_band_condition_ffffb154 = 0;
    bVar1 = false;
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 100.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 97.0) {
      coolant_above_97_flag_ffffb1d8 = 0;
    }
  }
  else {
    coolant_above_97_flag_ffffb1d8 = 1;
  }
  if (bVar1) {
    uVar2 = (uint)ol_condition_timer_ffffb144;
    if (uVar2 != 0) {
      ol_condition_timer_ffffb144 = ol_condition_timer_ffffb144 - 1;
    }
  }
  else if (coolant_above_97_flag_ffffb1d8 == 0) {
    ol_condition_timer_ffffb144 = 0x493e;
  }
  if ((ol_condition_timer_ffffb144 == 0) && (uVar2 = (uint)coolant_above_97_flag_ffffb1d8, uVar2 == 1)) {
    ol_timer_expired_ffffb159 = 0;
  }
  else {
    ol_timer_expired_ffffb159 = 1;
  }
  return uVar2;
}


