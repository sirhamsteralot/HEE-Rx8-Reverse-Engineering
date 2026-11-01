/* [ADDITIONAL SOURCE REVIEW]
 * leading_timing_cranking_blend [high]: Leading final blend. ROM equation: a640 = a5e8*a644 + (a5f0 + a718 + ca9c)*(1-a644) + a780 - a778. a644 = cranking multiplier: decays max(a644-0.05,0) per call while cranking (DAT_ffffaa62==1) and rpm < a7ac+10000-100, else min(a644+1,1). Dynamically verified in the emulator bit-exact (cranking: a640=25.775 for scripted inputs; non-cranking a644->1: a640=36.5).
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
      DAT_ffffa668 = '\0';
    }
  }
  else {
    DAT_ffffa668 = '\x01';
  }
  fVar2 = 1.0;
  if ((cranking_active_ffffaa62_ffffaa62 == '\x01') && (DAT_ffffa668 == '\0')) {
    cranking_timing_multiplier_leading_ffffa644 = rx8_max_float(cranking_timing_multiplier_leading_ffffa644 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    cranking_timing_multiplier_leading_ffffa644 = rx8_min_float(cranking_timing_multiplier_leading_ffffa644 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa640 = (leading_base_timing_final_ffffa5e8 * cranking_timing_multiplier_leading_ffffa644 +
                  (leading_coolant_scaled_advance_term_ffffa5f0 + idle_leading_timing_error_correction_ffffa718 + cranking_angle_timing_leading_filtered_ffffca9c) * (fVar2 - cranking_timing_multiplier_leading_ffffa644) +
                 idle_base_timing_leading_ffffa780) - iat_timing_compensation_leading_ffffa778;
  return uVar1;
}


