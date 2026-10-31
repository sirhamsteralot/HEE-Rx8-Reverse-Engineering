/* [ADDITIONAL SOURCE REVIEW]
 * apv_command_calc [medium]: Sets command bf84: 0 in low-RPM/closed conditions; else staged float literals 100.0 (0x42c80000) / 12.5 (0x41480000) from 0x31f32's own literal pool (verified in ROM), selected by counter bf88 against u16 band thresholds referenced from ROM 0x78bb2-0x78bc0 (incl. 0x78bb8=0x32); RPM hysteresis 2800/3000 (bf98; binary encodes lower bound as 3000.0 minus 200 offset).
 * RAM 0xffffbf98 apv_rpm_high_flag (uint8): RPM > 3000 (hyst 2800).
 */
/* ROM address: 0x00031f32; body bytes: 230; decompiled */

undefined2 * candidate_apv_command_calc(void)

{
  undefined2 *puVar1;
  
  if (engine_speed_rpm_ffffb548 <= 3000.0) {
    if (engine_speed_rpm_ffffb548 <= 2800.0) {
      apv_rpm_high_flag_ffffbf98 = '\0';
    }
  }
  else {
    apv_rpm_high_flag_ffffbf98 = '\x01';
  }
  if (((apv_rpm_high_flag_ffffbf98 == '\0') && (puVar1 = &DAT_00078bbe, 0x752 < apv_position_dwell_counter_ffffbf88)) ||
     ((DAT_ffffaa68 == '\0' &&
      ((apv_target_state_ffffbf8d == '\0' && (puVar1 = &apv_position_dwell_counter_ffffbf88, 0x58 < apv_position_dwell_counter_ffffbf88)))))) {
    apv_command_percent_ffffbf84 = 0;
  }
  else if (apv_direction_flag_ffffbf8b == '\x01') {
    puVar1 = &DAT_00078bb8;
    if (apv_position_dwell_counter_ffffbf88 < 0x32) {
      apv_command_percent_ffffbf84 = 0x42c80000;
    }
    else if (apv_position_dwell_counter_ffffbf88 < 0x59) {
      apv_command_percent_ffffbf84 = 0x41480000;
    }
    else {
      apv_command_percent_ffffbf84 = 0x41480000;
    }
  }
  else {
    puVar1 = (undefined2 *)&DAT_00078bb0;
    if (apv_drive_counter_ffffbf8a < 0x32) {
      apv_command_percent_ffffbf84 = 0x42c80000;
    }
    else if (apv_drive_counter_ffffbf8a < 0x59) {
      apv_command_percent_ffffbf84 = 0x41480000;
    }
    else {
      apv_command_percent_ffffbf84 = 0x41480000;
    }
  }
  return puVar1;
}


