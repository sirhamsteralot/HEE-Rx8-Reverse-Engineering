/* [ADDITIONAL SOURCE REVIEW]
 * rev_limit_conditionals [medium]: a4a6 = coolant < 18 C (set below 18, clear at 20); when b534==0 && baec active && mode changed: a4ae = 0x0f countdown (a4aa active flag, a4ad = previous baec).
 * RAM 0xffffa4a6 coolant_below_18c_flag (uint8): a4a6 = coolant < 18 C (clear at 20) - cold-engine rev-limit derate condition.
 * RAM 0xffffa4aa rev_limit_countdown_active (uint8): a4aa = (a4ae != 0); set by rev_limit_conditionals (0xee82).
 * RAM 0xffffa4ad rev_limit_mode_previous (uint8): a4ad = previous DAT_ffffbaec (mode) for change detection.
 * RAM 0xffffa4ae rev_limit_countdown (uint8): a4ae = 0x0f on mode change (b534==0 && baec active && a4ad==0 && baec != 7), decremented while a4aa.
 */
/* ROM address: 0x0000ee82; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ee86 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_rev_limit_conditionals(void)

{
  if (18.0 <= inferred_coolant_temperature_ffffa98c) {
    if (20.0 <= inferred_coolant_temperature_ffffa98c) {
      coolant_below_18c_flag_ffffa4a6 = 0;
    }
  }
  else {
    coolant_below_18c_flag_ffffa4a6 = 1;
  }
  if ((((automatic_transmission_ffffb534 == '\0') && (DAT_ffffbaec != '\0')) && (rev_limit_mode_previous_ffffa4ad == '\0')) &&
     (DAT_ffffbaec != '\a')) {
    rev_limit_countdown_ffffa4ae = '\f';
  }
  rev_limit_countdown_active_ffffa4aa = rev_limit_countdown_ffffa4ae != '\0';
  if (rev_limit_countdown_active_ffffa4aa) {
    rev_limit_countdown_ffffa4ae = rev_limit_countdown_ffffa4ae + -1;
  }
  rev_limit_mode_previous_ffffa4ad = DAT_ffffbaec;
  return;
}


