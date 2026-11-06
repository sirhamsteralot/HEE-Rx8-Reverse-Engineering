/* [ADDITIONAL SOURCE REVIEW]
 * adc_eoc_isr_bank1 [high]: IVT 0x308 (vec 194): clears ADCSR1 bit7, calls 0x6b60.
 */
/* ROM address: 0x00005cfe; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005cfe (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void adc_eoc_isr_bank1(void)

{
  byte bVar1;
  
  bVar1 = ADCSR1_B;
  ADCSR1_B = bVar1 & 0x7f;
  FUN_00006b60();
  return;
}


