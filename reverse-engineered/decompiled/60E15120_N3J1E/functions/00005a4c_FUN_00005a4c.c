/* [ADDITIONAL SOURCE REVIEW]
 * knock_adc_trigger_isr [high]: IVT 0x290 (vec 164): TSR8=0xefff, knock_reference_adc_read() - knock reference ADC sampling trigger.
 */
/* ROM address: 0x00005a4c; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005a4c (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void knock_adc_trigger_isr(void)

{
  ATUII_TSR8_W = 0xefff;
  knock_reference_adc_read();
  return;
}


