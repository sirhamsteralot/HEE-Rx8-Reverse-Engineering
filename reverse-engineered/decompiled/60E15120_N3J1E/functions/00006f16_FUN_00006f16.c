/* ROM address: 0x00006f16; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006f16 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00006f16(int param_1)

{
  byte bVar1;
  
  if (param_1 == 0) {
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xdf;
    ADCSR0_B = 0xb;
    bVar1 = ADTRG0_B;
    ADTRG0_B = bVar1 & 0x7f | 0x80;
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xaf | 0x80;
    bVar1 = ADCR1_B;
    ADCR1_B = bVar1 & 0xdf;
    ADCSR1_B = 0x4b;
  }
  else {
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xdf;
    ADCSR0_B = 10;
    bVar1 = ADTRG0_B;
    ADTRG0_B = bVar1 & 0x7f | 0x80;
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xaf | 0x80;
    bVar1 = ADCR1_B;
    ADCR1_B = bVar1 & 0xdf;
    ADCSR1_B = 0x4a;
  }
  bVar1 = ADTRGR1_B;
  ADTRGR1_B = bVar1 & 0x7f | 0x80;
  bVar1 = ADCR1_B;
  ADCR1_B = bVar1 & 0xaf | 0x80;
  DAT_ffff9f27 = 1;
  return;
}


