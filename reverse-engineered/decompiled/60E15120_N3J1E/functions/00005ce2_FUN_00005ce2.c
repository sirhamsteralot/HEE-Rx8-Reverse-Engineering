/* ROM address: 0x00005ce2; body bytes: 16; decompiled */

byte adc_eoc_isr_bank0(void)

{
  byte bVar1;
  
  bVar1 = ADCSR0_B;
  ADCSR0_B = bVar1 & 0x7f;
  return bVar1 & 0x7f;
}


