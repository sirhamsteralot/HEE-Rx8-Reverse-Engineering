/* [ADDITIONAL SOURCE REVIEW]
 * leading_timing_cranking_blend [high]: Latch 0xffffa668 (pool 0x12450) from rpm 0xffffb548 (pool 0x123fc) against f32 0xffffa7ac (pool 0x12412) + f32 0x6d778 = 10000.0 (fcmp/gt at 0x123f0), cleared below that sum minus f32 0x6d77c = 100.0 (0x12544, fcmp/gt at 0x1245a), untouched in between. Multiplier 0xffffa644 (pool 0x12548) = max(a644 - f32 0x6d764 = 0.05, 0) when 0xffffaa62 == 1 (cmp/eq at 0x1246e) and the latch is clear, else min(a644 + f32 0x6d768 = 1.0, 1.0). Output 0xffffa640 (pool 0x12560) = a5e8*m + (1-m)*(a5f0 + a718 + ca9c) + a780 - a778.
 * RAM 0xffffa5e8 leading_base_timing_final (float): Written by 0x11f00 leading_base_timing_calc (fmov.s fr2,@r2 0x11fe8 via mov.w pool 0x12010=0xa5e8 @0x11fdc, sign-extends to 0xffffa5e8); read by 0x123da leading_timing_cranking_blend (mov.w pool 0x1253a @0x124b0).
 * RAM 0xffffa644 cranking_timing_multiplier_leading (float): Written by 0x123da leading_timing_cranking_blend (fmov.s fr0,@r14 0x1249c via mov.l pool 0x12548=0xffffa644 @0x12464).
 * RAM 0xffffa640 leading_timing_after_cranking_blend (float): Output of the fade: a5e8*m + (1-m)*(a5f0 + a718 + ca9c) + a780 - a778 (store at 0x124cc).
 * RAM 0xffffa668 candidate_timing_fade_latch_leading (uint8): Rpm latch: set at 0x123fa when rpm >= 0xffffa7ac + 10000.0, cleared at 0x12462 when rpm < that sum - 100.0, held in between; the fade-down is suppressed while it is set (tst at 0x12478).
 */
/* ROM address: 0x000123da; body bytes: 164; decompiled */

undefined4 leading_timing_cranking_blend(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  
  if (engine_speed_rpm_ffffb548 < inferred_ram_a7ac_ffffa7ac_ffffa7ac + 10000.0) {
    if (engine_speed_rpm_ffffb548 < (inferred_ram_a7ac_ffffa7ac_ffffa7ac + 10000.0) - 100.0) {
      candidate_timing_fade_latch_leading_ffffa668 = '\0';
    }
  }
  else {
    candidate_timing_fade_latch_leading_ffffa668 = '\x01';
  }
  fVar2 = 1.0;
  if ((cranking_active_ffffaa62_ffffaa62 == '\x01') && (candidate_timing_fade_latch_leading_ffffa668 == '\0')) {
    cranking_timing_multiplier_leading_ffffa644 = rx8_max_float(cranking_timing_multiplier_leading_ffffa644 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    cranking_timing_multiplier_leading_ffffa644 = rx8_min_float(cranking_timing_multiplier_leading_ffffa644 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  leading_timing_after_cranking_blend_ffffa640 = (leading_base_timing_final_ffffa5e8 * cranking_timing_multiplier_leading_ffffa644 +
                  (leading_coolant_scaled_advance_term_ffffa5f0 + idle_leading_timing_error_correction_ffffa718 + cranking_angle_timing_leading_filtered_ffffca9c) * (fVar2 - cranking_timing_multiplier_leading_ffffa644) +
                 idle_base_timing_leading_ffffa780) - iat_timing_compensation_leading_ffffa778;
  return uVar1;
}


