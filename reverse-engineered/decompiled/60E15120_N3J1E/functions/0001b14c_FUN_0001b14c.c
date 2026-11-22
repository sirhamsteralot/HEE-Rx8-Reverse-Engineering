/* [ADDITIONAL SOURCE REVIEW]
 * plate_tp2_volts_latch [high]: ad5e = DAT_ffff9f0a (AN19 raw; pools 0x1b1d0=0xffff9f0a, 0x1b1c0=0xad5e/0xad34), ad34 from 0xffffa21c/0xffffa224 (pools 0x1b1dc=0xffffa21c, 0x1b1d4=0xffffa224). Called from 0x199d4.
 * RAM 0xffff9f0a adc_an19_plate_tp2_raw (uint16): ADDR19H latched here by the 0x6884 sweep; read by 0x1b14c (pool 0x1b1d0=0xffff9f0a) into ad5e (pool 0x1b1c0) — throttle PLATE TP2 volts. Harness: TP signal 1M (B1-19 D).
 * RAM 0xffffa21c plate_tp2_volts (float): TP2 volts: written by 0xb398 (AN19 raw, scale 0x6f3e8=31.25f); read by 0x1b14c (pool 0x1b1dc=0xffffa21c) into ad34/ad86, then 0x1b940.
 */
/* ROM address: 0x0001b14c; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001bbfc (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void plate_tp2_volts_latch(void)

{
  inferred_throttle_sensor_2_volts_ffffad5e_ffffad5e = adc_an19_plate_tp2_raw_ffff9f0a;
  DAT_ffffad86 = DAT_ffffa224;
  DAT_ffffad34 = plate_tp2_volts_ffffa21c;
  return;
}


