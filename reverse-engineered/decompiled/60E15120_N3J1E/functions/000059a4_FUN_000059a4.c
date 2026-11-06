/* [ADDITIONAL SOURCE REVIEW]
 * atu_ch8_cmp_isr_ch0 [high]: IVT 0x260 (vec 152): TSR8=0xfffe, candidate_injector_pulse_set_dispatch(0).
 */
/* ROM address: 0x000059a4; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000059a4 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void atu_ch8_cmp_isr_ch0(void)

{
  ATUII_TSR8_W = 0xfffe;
  candidate_injector_pulse_set_dispatch(0);
  return;
}


