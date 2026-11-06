/* [ADDITIONAL SOURCE REVIEW]
 * adc_eoc_isr_bank2 [high]: IVT 0x310 (vec 196): clears ADCSR2 bit7, returns.
 */
/* ROM address: 0x00005d0a; body bytes: 16; decompiled */

byte adc_eoc_isr_bank2(void)

{
  byte bVar1;
  
  bVar1 = ADCSR2_B;
  ADCSR2_B = bVar1 & 0x7f;
  return bVar1 & 0x7f;
}


