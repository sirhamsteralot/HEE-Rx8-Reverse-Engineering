/* ROM address: 0x00006d7c; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006d7c (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_00006d7c(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_ffff9f2b == 0xc) {
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xdf;
    uVar2 = 0x33;
  }
  else {
    if (DAT_ffff9f2b == 8) {
      bVar1 = ADCR0_B;
      ADCR0_B = bVar1 & 0xdf;
      ADCSR0_B = 0x23;
      goto LAB_00006dd6;
    }
    if (DAT_ffff9f2b != 4) {
      if (DAT_ffff9f2b != 1) {
        return DAT_ffff9f2b;
      }
      bVar1 = ADCR0_B;
      ADCR0_B = bVar1 & 0xdf;
      ADCSR0_B = 0x10;
      goto LAB_00006dd6;
    }
    bVar1 = ADCR0_B;
    ADCR0_B = bVar1 & 0xdf;
    uVar2 = 0x13;
  }
  ADCSR0_B = uVar2;
LAB_00006dd6:
  bVar1 = ADCR0_B;
  bVar1 = bVar1 & 0x2f | 0x20;
  ADCR0_B = bVar1;
  return bVar1;
}


