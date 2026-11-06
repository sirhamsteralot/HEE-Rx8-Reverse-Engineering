/* [ADDITIONAL SOURCE REVIEW]
 * trailing_timing_cranking_blend [high]: Trailing mirror: a650 = a5ec*a654 + (a5f4 + a71c + caa0)*(1-a654) + a784 - a77c. Dynamically verified bit-exact in the emulator (a650=18.115 for scripted inputs).
 * RAM 0xffffa5ec trailing_base_timing_final (float): 
 * RAM 0xffffa654 cranking_timing_multiplier_trailing (float): 
 */
/* ROM address: 0x000124d6; body bytes: 164; decompiled */

undefined4 trailing_timing_cranking_blend(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  
  if (engine_speed_rpm_ffffb548 < inferred_ram_a7ac_ffffa7ac_ffffa7ac + 10000.0) {
    if (engine_speed_rpm_ffffb548 < (inferred_ram_a7ac_ffffa7ac_ffffa7ac + 10000.0) - 100.0) {
      DAT_ffffa669 = '\0';
    }
  }
  else {
    DAT_ffffa669 = '\x01';
  }
  fVar2 = 1.0;
  if ((cranking_active_ffffaa62_ffffaa62 == '\x01') && (DAT_ffffa669 == '\0')) {
    cranking_timing_multiplier_trailing_ffffa654 = rx8_max_float(cranking_timing_multiplier_trailing_ffffa654 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    cranking_timing_multiplier_trailing_ffffa654 = rx8_min_float(cranking_timing_multiplier_trailing_ffffa654 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa650 = (trailing_base_timing_final_ffffa5ec * cranking_timing_multiplier_trailing_ffffa654 +
                  (trailing_coolant_scaled_advance_term_ffffa5f4 + idle_trailing_timing_error_correction_ffffa71c + cranking_angle_timing_trailing_filtered_ffffcaa0) * (fVar2 - cranking_timing_multiplier_trailing_ffffa654) +
                 idle_base_timing_trailing_ffffa784) - iat_timing_compensation_trailing_ffffa77c;
  return uVar1;
}


