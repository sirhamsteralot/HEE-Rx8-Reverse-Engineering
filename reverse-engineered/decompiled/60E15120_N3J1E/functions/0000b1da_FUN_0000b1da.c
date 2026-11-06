/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa1fc adc_an23_sample_b (uint16): Second AN23 sample (0xb1da, same pool word 0xfffff836).
 * RAM 0xffffa200 adc_an11_sample_b (uint16): Second AN11 sample.
 */
/* ROM address: 0x0000b1da; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b1da (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b1da(void)

{
  if (DAT_ffffa205 == '\0') {
    adc_an23_sample_b_ffffa1fc = ADDR23H_B;
    adc_an11_sample_b_ffffa200 = ADDR11H_B;
    adc_pair_second_sample_ready_ffffa202 = 1;
  }
  DAT_ffffa207 = 0;
  return;
}


