/* [ADDITIONAL SOURCE REVIEW]
 * apv_position_voltage_counter [medium]: bf88: reset to 0 when bf8b==0 or (bf88 > 0x4e1 && cab4==0); else saturating increment — position-voltage dwell counter.
 * RAM 0xffffbf88 apv_position_dwell_counter (uint16): Incremented unless bf8b==0 or (bf88>0x4e1 && cab4==0); bands in 0x31f32.
 */
/* ROM address: 0x00031ece; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032376 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_apv_position_voltage_counter(void)

{
  if ((apv_direction_flag_ffffbf8b == '\0') || ((0x4e1 < apv_position_dwell_counter_ffffbf88 && (DAT_ffffcab4 == '\0')))) {
    apv_position_dwell_counter_ffffbf88 = 0;
  }
  else {
    apv_position_dwell_counter_ffffbf88 = rx8_add_u16_saturate((int)(short)apv_position_dwell_counter_ffffbf88,1);
  }
  return;
}


