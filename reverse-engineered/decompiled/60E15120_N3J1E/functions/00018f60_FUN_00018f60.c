/* [ADDITIONAL SOURCE REVIEW]
 * pedal_volts_clamp_latch [high]: a9c4 = DAT_ffff9eec (pool 0x19058=0xffff9eec, 0x1904a=0x0000a9c4), a9c8 = 0xffffa112, a99c = rx8_min_float(25.0f @0x6eed0 via pool 0x19068, a108 @0xffffa108 pool 0x19064) via 0x23f4 (pool 0x1906c); called from 0x199d4.
 * RAM 0xffffa99c pedal_1_volts_clamped25 (float): a99c = rx8_min_float(25.0f, a108) in 0x18f60 (pools 0x19064=0xffffa108, 0x19068=0x6eed0, 0x1906c=0x23f4, store 0x19042=0xa99c).
 */
/* ROM address: 0x00018f60; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019b5c (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void pedal_volts_clamp_latch(void)

{
  inferred_pedal_volts_ffffa9c4_ffffa9c4 = adc_an4_pedal_raw_ffff9eec;
  DAT_ffffa9c8 = DAT_ffffa112;
  pedal_1_volts_clamped25_ffffa99c = rx8_min_float(25.0,pedal_1_scaled_volts_ffffa108);
  return;
}


