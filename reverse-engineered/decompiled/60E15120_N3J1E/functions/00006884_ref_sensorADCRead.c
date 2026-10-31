/* ROM address: 0x00006884; body bytes: 350; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006884 (350 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Firmware fact: ADC sample at 0xfffff80c (reference register label ADDR6H_B; inspect mov.w width)
   is copied to RAM 0xffff9ef0. Candidate APV feedback chain, via 0x43a86. Harness APV signal is PCM
   3B (13Electrical.pdf p16); MCU-to-connector link is not electrically verified. */

void ref_sensorADCRead(void)

{
  byte bVar1;
  
  bVar1 = ADCR0_B;
  ADCR0_B = bVar1 & 0xdf;
  ADCSR0_B = 0x33;
  bVar1 = ADCR0_B;
  ADCR0_B = bVar1 & 0x2f | 0x20;
  bVar1 = ADCR1_B;
  ADCR1_B = bVar1 & 0xdf;
  ADCSR1_B = 0x33;
  bVar1 = ADCR1_B;
  ADCR1_B = bVar1 & 0x2f | 0x20;
  bVar1 = ADCR2_B;
  ADCR2_B = bVar1 & 0xdf;
  ADCSR2_B = 0x2b;
  bVar1 = ADCR2_B;
  ADCR2_B = bVar1 & 0x2f | 0x20;
  DAT_ffff9f27 = 0;
  DAT_ffff9f28 = 0xff;
  DAT_ffff9f2a = 0;
  DAT_ffff9f2d = 0;
  DAT_ffff9f30 = 0;
  do {
    bVar1 = ADCSR0_B;
  } while ((bVar1 & 0x80) == 0);
  do {
    bVar1 = ADCSR1_B;
  } while ((bVar1 & 0x80) == 0);
  do {
    bVar1 = ADCSR2_B;
  } while ((bVar1 & 0x80) == 0);
  DAT_ffff9ee4 = ADDR0H_B;
  DAT_ffff9ee6 = ADDR1H_B;
  DAT_ffff9ee8 = ADDR2H_B;
  maf_adc_raw_ffff9eea = ADDR3H_B;
  DAT_ffff9eec = ADDR4H_B;
  DAT_ffff9eee = ADDR5H_B;
  adc6_raw_apv_position_ffff9ef0 = ADDR6H_B;
  DAT_ffff9ef2 = ADDR7H_B;
  DAT_ffff9ef4 = ADDR8H_B;
  DAT_ffff9ef6 = ADDR9H_B;
  knock_sensor_adc_raw_ffff9ef8 = ADDR10H_B;
  DAT_ffff9efa = ADDR11H_B;
  DAT_ffff9efc = ADDR12H_B;
  DAT_ffff9efe = ADDR13H_B;
  DAT_ffff9f00 = ADDR14H_B;
  DAT_ffff9f02 = ADDR15H_B;
  DAT_ffff9f04 = ADDR16H_B;
  DAT_ffff9f06 = ADDR17H_B;
  DAT_ffff9f08 = ADDR18H_B;
  DAT_ffff9f0a = ADDR19H_B;
  DAT_ffff9f0c = ADDR20H_B;
  DAT_ffff9f0e = ADDR21H_B;
  DAT_ffff9f10 = ADDR22H_B;
  DAT_ffff9f12 = ADDR23H_B;
  DAT_ffff9f14 = ADDR24H_B;
  DAT_ffff9f16 = ADDR25H_B;
  DAT_ffff9f18 = ADDR26H_B;
  DAT_ffff9f1a = ADDR27H_B;
  DAT_ffff9f1c = ADDR28H_B;
  DAT_ffff9f1e = ADDR29H_B;
  DAT_ffff9f20 = ADDR30H_B;
  DAT_ffff9f22 = ADDR31H_B;
  return;
}


