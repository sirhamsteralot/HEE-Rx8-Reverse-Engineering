/* [ADDITIONAL SOURCE REVIEW]
 * atu_ch8_cmp_isr_ch2 [high]: IVT 0x270 (vec 156): TSR8=0xffef, candidate_injector_pulse_set_dispatch(2).
 */
/* ROM address: 0x000059dc; body bytes: 14; decompiled */

void atu_ch8_cmp_isr_ch2(void)

{
  ATUII_TSR8_W = 0xffef;
  candidate_injector_pulse_set_dispatch(2);
  return;
}


