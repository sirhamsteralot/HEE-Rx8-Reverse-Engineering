/* ROM address: 0x00005d0a; body bytes: 16; decompiled */

byte adc_eoc_isr_bank2(void)

{
  byte bVar1;
  
  bVar1 = ADCSR2_B;
  ADCSR2_B = bVar1 & 0x7f;
  return bVar1 & 0x7f;
}


