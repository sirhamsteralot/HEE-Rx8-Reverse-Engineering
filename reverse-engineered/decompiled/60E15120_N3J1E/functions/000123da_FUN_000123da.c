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
  
  if (engine_speed_rpm_ffffb548 < DAT_ffffa7ac + 10000.0) {
    if (engine_speed_rpm_ffffb548 < (DAT_ffffa7ac + 10000.0) - 100.0) {
      DAT_ffffa668 = '\0';
    }
  }
  else {
    DAT_ffffa668 = '\x01';
  }
  fVar2 = 1.0;
  if ((DAT_ffffaa62 == '\x01') && (DAT_ffffa668 == '\0')) {
    DAT_ffffa644 = rx8_max_float(DAT_ffffa644 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa644 = rx8_min_float(DAT_ffffa644 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa640 = (DAT_ffffa5e8 * DAT_ffffa644 +
                  (DAT_ffffa5f0 + DAT_ffffa718 + DAT_ffffca9c) * (fVar2 - DAT_ffffa644) +
                 DAT_ffffa780) - DAT_ffffa778;
  return uVar1;
}


