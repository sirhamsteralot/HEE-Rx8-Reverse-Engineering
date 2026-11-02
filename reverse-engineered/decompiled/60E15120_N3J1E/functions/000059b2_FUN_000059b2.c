/* ROM address: 0x000059b2; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000059b2 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void atu_ch8_cmp_isr_ch3(void)

{
  ATUII_TSR8_W = 0xfffd;
  candidate_injector_pulse_set_dispatch(3);
  return;
}


