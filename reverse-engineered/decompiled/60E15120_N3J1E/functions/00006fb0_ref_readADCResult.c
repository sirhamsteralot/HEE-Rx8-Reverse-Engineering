/* ROM address: 0x00006fb0; body bytes: 174; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006fb0 (174 bytes). Names prefixed ref_
   are inherited hypotheses. */

int adc_read_result_bank2(void)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  
  bVar1 = false;
  uVar6 = sh_raise_interrupt_mask_return_previous(0x90);
  bVar4 = ADCSR2_B;
  bVar5 = ADCR2_B;
  bVar2 = (bVar5 & 0x20) == 0;
  if (bVar2) {
    bVar5 = ADCSR2_B;
    bVar1 = (bVar5 & 0x80) != 0;
  }
  else {
    bVar5 = ADCR2_B;
    ADCR2_B = bVar5 & 0xdf;
    bVar5 = ADCSR2_B;
    ADCSR2_B = bVar5 & 0x7f;
  }
  bVar5 = ADCR2_B;
  ADCR2_B = bVar5 & 0xdf;
  ADCSR2_B = 0x18;
  bVar5 = ADCR2_B;
  ADCR2_B = bVar5 & 0x2f | 0x20;
  do {
    bVar5 = ADCSR2_B;
  } while ((bVar5 & 0x80) == 0);
  sVar3 = ADDR24H_B;
  ADCSR2_B = bVar4 | 0x80;
  if (bVar2) {
    if (!bVar1) {
      bVar4 = ADCSR2_B;
      ADCSR2_B = bVar4 & 0x7f;
    }
  }
  else {
    bVar4 = ADCR2_B;
    ADCR2_B = bVar4 & 0xdf;
    bVar4 = ADCSR2_B;
    ADCSR2_B = bVar4 & 0x7f;
    bVar4 = ADCR2_B;
    ADCR2_B = bVar4 | 0x20;
  }
  ref_setSR(uVar6);
  return (int)sVar3;
}


