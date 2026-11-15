/* [ADDITIONAL SOURCE REVIEW]
 * key_voltage_timer_update [medium]: 0xffffccca held at 0x19 while (battery voltage 0xffffb590 < 6.0 and 0xffffcbd0 == 1), else counts down to 0; read by 0x48d70 into 0xffffccc4. Candidate START/crank correlation (PF15 active + low voltage); terminal routing unresolved.
 * RAM 0xffffccca key_voltage_timer (uint8): Held at 0x19 while voltage 0xffffb590 < 6.0 and 0xffffcbd0 == 1, else counts down (0x48d38); read by 0x48d70 into 0xffffccc4.
 */
/* ROM address: 0x00048d38; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00047dc4 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_key_voltage_timer_update(void)

{
  if ((6.0 <= DAT_ffffb4b8) || (key_input_pf15_edge_latch_ffffcbd0 != '\x01')) {
    if (key_voltage_timer_ffffccca != 0) {
      key_voltage_timer_ffffccca = key_voltage_timer_ffffccca + -1;
    }
  }
  else {
    key_voltage_timer_ffffccca = 0x19;
  }
  return;
}


