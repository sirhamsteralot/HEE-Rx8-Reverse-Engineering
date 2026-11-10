/* [ADDITIONAL SOURCE REVIEW]
 * apv_position_voltage_scale [medium]: cab0 = (float)(u16 9ef0) * 5/65536 (0x38a00000): APV position feedback ADC6 (reg 0xfffff80c, AN6 = pkg pin 92) scaled to volts. PCM 3B->AN6 not board-verified.
 * RAM 0xffffcab0 apv_position_voltage (float): APV feedback volts = ADC6 raw 9ef0 * 5/65536.
 * RAM 0xffff9ef0 adc6_raw_apv_position (uint16): ADC6 (0xfffff80c, AN6 pkg pin 92) sample; candidate APV position input.
 */
/* ROM address: 0x00043a86; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000432ba (24 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Firmware fact: ADC6 raw 0xffff9ef0 * 5/65536 -> float 0xffffcab0. pinout v3: APV opening-angle signal at PCM 3B (wire R/G, HP ³) — candidate APV feedback; PCM 3B -> AN6 (pkg pin 92) not board-verified. See reconstructed/rx8_apv.c. */

void apv_position_voltage_scale(void)

{
  apv_position_voltage_ffffcab0 = rx8_decode_u16_affine(0x38a00000,0,(int)adc6_raw_apv_position_ffff9ef0);
  return;
}


