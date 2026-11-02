/* ROM address: 0x000059ea; body bytes: 14; decompiled */

void atu_ch8_cmp_isr_ch5(void)

{
  ATUII_TSR8_W = 0xffdf;
  candidate_injector_pulse_set_dispatch(5);
  return;
}


