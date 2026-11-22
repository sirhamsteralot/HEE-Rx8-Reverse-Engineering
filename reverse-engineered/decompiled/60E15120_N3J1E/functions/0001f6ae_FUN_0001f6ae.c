/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffb180 cl_load_threshold_2d_c (float): b180 = tbl 0x69db0(rpm); throttle/load band compares -> b1be/b1c2 in 0x1f6ae.
 * RAM 0xffffb184 cl_load_threshold_2d_d (float): b184 = tbl 0x69dc4(rpm).
 * RAM 0xffffb188 cl_load_threshold_2d_e (float): b188 = tbl 0x69dd8(rpm) -> b1c6.
 * RAM 0xffffb18c cl_load_threshold_2d_f (float): b18c = tbl 0x69dec(rpm) -> b1ca.
 * RAM 0xffffb1c6 load_above_thresh_c (uint8): b1c6 = load >= b188 (hysteresis) in 0x1f6ae.
 * RAM 0xffffb1ca load_above_thresh_d (uint8): b1ca = load > b18c (hysteresis) in 0x1f6ae.
 * RAM 0xffffb1c7 rpm_above_5300_flag_b (uint8): b1c7 = rpm > 5500 (clear below 5300); second copy in 0x1f6ae.
 * RAM 0xffffb1cb rpm_above_9800_flag (uint8): b1cb = rpm > 10000 (clear below 9800) in 0x1f6ae.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069db0: Table 2D - 99 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069dc4: Table 2D - 100 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069dd8: Table 2D - 101 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069dec: Table 2D - 102 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001f6ae; body bytes: 892; decompiled */

char FUN_0001f6ae(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  float snapshot_inferred_throttle_position_ffffad44;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_inferred_throttle_position_ffffad44 = inferred_throttle_position_ffffad44;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cl_load_threshold_2d_e_ffffb188 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_101_00069dd8);
  cl_load_threshold_2d_f_ffffb18c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_102_00069dec);
  if (snapshot_inferred_throttle_position_ffffad44 < 78.0) {
    if (snapshot_inferred_throttle_position_ffffad44 < 75.0) {
      DAT_ffffb1c5 = '\0';
    }
  }
  else {
    DAT_ffffb1c5 = '\x01';
  }
  if (snapshot_inferred_throttle_position_ffffad44 <= 100.0) {
    if (snapshot_inferred_throttle_position_ffffad44 <= 97.0) {
      DAT_ffffb1c9 = '\0';
    }
  }
  else {
    DAT_ffffb1c9 = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_e_ffffb188) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_e_ffffb188 - 0.04) {
      load_above_thresh_c_ffffb1c6 = '\0';
    }
  }
  else {
    load_above_thresh_c_ffffb1c6 = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_f_ffffb18c) {
    if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_f_ffffb18c - 0.04) {
      load_above_thresh_d_ffffb1ca = '\0';
    }
  }
  else {
    load_above_thresh_d_ffffb1ca = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 5500.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5300.0) {
      rpm_above_5300_flag_b_ffffb1c7 = '\0';
    }
  }
  else {
    rpm_above_5300_flag_b_ffffb1c7 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 <= 10000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 <= 9800.0) {
      rpm_above_9800_flag_ffffb1cb = '\0';
    }
  }
  else {
    rpm_above_9800_flag_ffffb1cb = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 5500.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5300.0) {
      DAT_ffffb1c8 = '\0';
    }
  }
  else {
    DAT_ffffb1c8 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 <= 10000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 <= 9800.0) {
      DAT_ffffb1cc = '\0';
    }
  }
  else {
    DAT_ffffb1cc = '\x01';
  }
  cl_load_threshold_2d_c_ffffb180 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_99_00069db0);
  cl_load_threshold_2d_d_ffffb184 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_100_00069dc4);
  if (snapshot_inferred_throttle_position_ffffad44 < 78.0) {
    if (snapshot_inferred_throttle_position_ffffad44 < 75.0) {
      DAT_ffffb1bd = '\0';
    }
  }
  else {
    DAT_ffffb1bd = '\x01';
  }
  if (snapshot_inferred_throttle_position_ffffad44 <= 100.0) {
    if (snapshot_inferred_throttle_position_ffffad44 <= 97.0) {
      DAT_ffffb1c1 = '\0';
    }
  }
  else {
    DAT_ffffb1c1 = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_c_ffffb180) {
    if (snapshot_engine_load_ffffc0b4 < cl_load_threshold_2d_c_ffffb180 - 0.04) {
      DAT_ffffb1be = '\0';
    }
  }
  else {
    DAT_ffffb1be = '\x01';
  }
  if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_d_ffffb184) {
    if (snapshot_engine_load_ffffc0b4 <= cl_load_threshold_2d_d_ffffb184 - 0.04) {
      DAT_ffffb1c2 = '\0';
    }
  }
  else {
    DAT_ffffb1c2 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 5500.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5300.0) {
      DAT_ffffb1bf = '\0';
    }
  }
  else {
    DAT_ffffb1bf = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 <= 10000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 <= 9800.0) {
      DAT_ffffb1c3 = '\0';
    }
  }
  else {
    DAT_ffffb1c3 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 5500.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 5300.0) {
      DAT_ffffb1c0 = '\0';
    }
  }
  else {
    DAT_ffffb1c0 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 <= 10000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 <= 9800.0) {
      DAT_ffffb1c4 = '\0';
    }
  }
  else {
    DAT_ffffb1c4 = '\x01';
  }
  if (((((DAT_ffffb1c5 == '\x01') && (DAT_ffffb1c9 == '\0')) && (rpm_above_5300_flag_b_ffffb1c7 == '\x01')) &&
      (rpm_above_9800_flag_ffffb1cb == '\0')) ||
     (((load_above_thresh_c_ffffb1c6 == '\x01' && (load_above_thresh_d_ffffb1ca == '\0')) &&
      ((DAT_ffffb1c8 == '\x01' && (DAT_ffffb1cc == '\0')))))) {
    DAT_ffffb156 = 1;
    bVar2 = true;
    DAT_ffffb155 = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffb156 = 0;
    bVar2 = false;
    if ((((DAT_ffffb1bd == '\x01') && (DAT_ffffb1c1 == '\0')) &&
        ((DAT_ffffb1bf == '\x01' && (DAT_ffffb1c3 == '\0')))) ||
       ((((DAT_ffffb1be == '\x01' && (DAT_ffffb1c2 == '\0')) && (DAT_ffffb1c0 == '\x01')) &&
        (DAT_ffffb1c4 == '\0')))) {
      DAT_ffffb155 = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffb155 = 0;
      bVar1 = false;
    }
  }
  if ((bVar1) || (bVar2)) {
    ol_decay_enable_b_ffffb152 = 1;
  }
  else {
    ol_decay_enable_b_ffffb152 = 0;
  }
  if (snapshot_engine_load_ffffc0b4 < 0.6) {
    if (snapshot_engine_load_ffffc0b4 < 0.56) {
      DAT_ffffb1cd = '\0';
    }
  }
  else {
    DAT_ffffb1cd = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 10000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 9800.0) {
      DAT_ffffb1ce = '\0';
    }
  }
  else {
    DAT_ffffb1ce = '\x01';
  }
  cVar3 = '\x01';
  if ((DAT_ffffb1cd == '\x01') || (cVar3 = DAT_ffffb1ce, DAT_ffffb1ce == '\x01')) {
    DAT_ffffb153 = 1;
  }
  else {
    DAT_ffffb153 = 0;
  }
  return cVar3;
}


