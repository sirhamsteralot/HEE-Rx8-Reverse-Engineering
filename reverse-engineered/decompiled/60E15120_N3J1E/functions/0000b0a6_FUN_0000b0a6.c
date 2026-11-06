/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa1fa adc_an23_sample_a (uint16): Word @0xfffff836 (ADDR23H, ADC AN23) sampled in the ADC EOC bank1 chain (0x6b60 -> 0xb0a6).
 * RAM 0xffffa1fe adc_an11_sample_a (uint16): Word @0xfffff816 (ADDR11H, ADC AN11; pool word 0xfffff836 + add -0x20, ROM-verified at 0xb0d2).
 */
/* ROM address: 0x0000b0a6; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b0a6 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b0a6(void)

{
  DAT_ffffa206 = DAT_ffffa206 + 1;
  if (1 < DAT_ffffa206) {
    DAT_ffffa206 = 0;
  }
  if (DAT_ffffa206 == 0) {
    adc_an23_sample_a_ffffa1fa = ADDR23H_B;
    adc_an11_sample_a_ffffa1fe = ADDR11H_B;
    if (1000.0 < adc_pair_ratio_raw_ffffa1d8) {
      if (1050.0 < adc_pair_ratio_raw_ffffa1d8) {
        DAT_ffffa204 = '\0';
      }
    }
    else {
      DAT_ffffa204 = '\x01';
    }
    FUN_00006f16(0);
    FUN_0000b114((int)DAT_ffffa204);
    DAT_ffffa205 = 0;
  }
  return;
}


