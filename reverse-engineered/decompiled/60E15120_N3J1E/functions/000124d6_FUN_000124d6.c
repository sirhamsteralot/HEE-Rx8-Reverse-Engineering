/* [ADDITIONAL SOURCE REVIEW]
 * trailing_timing_cranking_blend [high]: Trailing mirror: latch 0xffffa669, multiplier 0xffffa654, terms a5f4 + a71c + caa0, output 0xffffa650, same 0.05 step and 1.0 ceiling.
 * RAM 0xffffa5ec trailing_base_timing_final (float): Written by 0x1206c trailing_base_timing_calc (fmov.s fr2,@r2 0x12154 via mov.w pool 0x1217c=0xa5ec @0x12148); read by 0x124d6 trailing_timing_cranking_blend (mov.w pool 0x12688 @0x12594).
 * RAM 0xffffa654 cranking_timing_multiplier_trailing (float): Written by 0x124d6 trailing_timing_cranking_blend (fmov.s fr0,@r14 0x12582 via mov.l pool 0x1256c=0xffffa654 @0x12508).
 * RAM 0xffffa650 trailing_timing_after_cranking_blend (float): Trailing output of the fade (0x124d6).
 * RAM 0xffffa669 candidate_timing_fade_latch_trailing (uint8): Trailing mirror of 0xffffa668 (0x124f4/0x12506).
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
      candidate_timing_fade_latch_trailing_ffffa669 = '\0';
    }
  }
  else {
    candidate_timing_fade_latch_trailing_ffffa669 = '\x01';
  }
  fVar2 = 1.0;
  if ((cranking_active_ffffaa62_ffffaa62 == '\x01') && (candidate_timing_fade_latch_trailing_ffffa669 == '\0')) {
    cranking_timing_multiplier_trailing_ffffa654 = rx8_max_float(cranking_timing_multiplier_trailing_ffffa654 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    cranking_timing_multiplier_trailing_ffffa654 = rx8_min_float(cranking_timing_multiplier_trailing_ffffa654 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  trailing_timing_after_cranking_blend_ffffa650 = (trailing_base_timing_final_ffffa5ec * cranking_timing_multiplier_trailing_ffffa654 +
                  (trailing_coolant_scaled_advance_term_ffffa5f4 + idle_trailing_timing_error_correction_ffffa71c + cranking_angle_timing_trailing_filtered_ffffcaa0) * (fVar2 - cranking_timing_multiplier_trailing_ffffa654) +
                 idle_base_timing_trailing_ffffa784) - iat_timing_compensation_trailing_ffffa77c;
  return uVar1;
}


