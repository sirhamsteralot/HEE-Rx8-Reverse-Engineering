/* [ADDITIONAL SOURCE REVIEW]
 * misfire_sustained_gate [medium]: DAT_ffffba09 = 1 when (DAT_ffffba80 <= DAT_ffffba50 || ba08==1 || 1 < DAT_ffffcb60) && (1 < DAT_ffffb688 || 1 < DAT_ffffb68a || (DAT_ffffc928 < 0.85 || 1.15 < DAT_ffffc928)) && DAT_ffffba04 != 0. Called from 0x287aa.
 */
/* ROM address: 0x000273d4; body bytes: 112; decompiled */

void candidate_misfire_sustained_gate(void)

{
  if (((((misfire_threshold_b_ffffba80 <= misfire_deviation_now_ffffba50) || (DAT_ffffba08 == '\x01')) || (1 < misfire_sustained_counter_a_ffffcb60)) ||
      (((1 < misfire_counter_bank1_a_ffffb688 || (1 < misfire_counter_bank0_a_ffffb68a)) || ((DAT_ffffc928 < 0.85 || (1.15 < DAT_ffffc928)))
       ))) && (misfire_learn_hold_ffffba04 != 0)) {
    DAT_ffffba09 = 1;
  }
  return;
}


