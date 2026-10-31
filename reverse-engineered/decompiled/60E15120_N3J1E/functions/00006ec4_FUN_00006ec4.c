/* ROM address: 0x00006ec4; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006ec4 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_00006ec4(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_ffff9f31 == 8) {
    bVar1 = ADCR2_B;
    ADCR2_B = bVar1 & 0xdf;
    uVar2 = 0x2b;
  }
  else {
    if (DAT_ffff9f31 == 4) {
      bVar1 = ADCR2_B;
      ADCR2_B = bVar1 & 0xdf;
      ADCSR2_B = 0x1b;
      goto LAB_00006f0a;
    }
    if (DAT_ffff9f31 != 1) {
      return DAT_ffff9f31;
    }
    bVar1 = ADCR2_B;
    ADCR2_B = bVar1 & 0xdf;
    uVar2 = 0x18;
  }
  ADCSR2_B = uVar2;
LAB_00006f0a:
  bVar1 = ADCR2_B;
  bVar1 = bVar1 & 0x2f | 0x20;
  ADCR2_B = bVar1;
  return bVar1;
}


