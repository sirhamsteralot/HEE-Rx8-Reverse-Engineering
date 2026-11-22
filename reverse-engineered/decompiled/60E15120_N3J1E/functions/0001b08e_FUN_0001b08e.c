/* [ADDITIONAL SOURCE REVIEW]
 * plate_tp1_volts_latch [high]: ad5c = DAT_ffff9f08 (AN18 raw; pools 0x1b12c=0xffff9f08, 0x1b0e6=0xad5c), ad30/ad54 from 0xffffa218/0xffffa222 (pools 0x1b138=0xffffa218, 0x1b130=0xffffa222, 0x1b0f0=0xad30/0xad54); filter 0x23b0 via pool 0x1b148. Called from 0x199d4.
 * RAM 0xffff9f08 adc_an18_plate_tp1_raw (uint16): ADDR18H latched here by the 0x6884 sweep; read by 0x1b08e (pool 0x1b12c=0xffff9f08) into ad5c (pool 0x1b0e6) — throttle PLATE TP1 volts (PID 0x0011 via 0x5553e, PID 0x1154 raw). Harness: throttle body TP signal 1J (B1-19 A).
 * RAM 0xffffa218 plate_tp1_volts (float): TP1 volts: written by 0xb398 (indexed float store at 0xffffa218+4i) = base (0x6f3ec, 0.0f) + AN18 raw * scale 0x6f3e4 (25.0f) * 7.6294e-5; read by 0x1b08e (pool 0x1b138=0xffffa218) into ad30/ad54, then 0x1b940.
 */
/* ROM address: 0x0001b08e; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001bb3e (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void plate_tp1_volts_latch(void)

{
  inferred_throttle_sensor_volts_ffffad5c_ffffad5c = adc_an18_plate_tp1_raw_ffff9f08;
  DAT_ffffad84 = DAT_ffffa222;
  DAT_ffffad30 = plate_tp1_volts_ffffa218;
  if (DAT_ffffadd2 == '\0') {
    DAT_ffffad54 = plate_tp1_volts_ffffa218;
    DAT_ffffadd2 = '\x01';
  }
  else {
    DAT_ffffad54 = rx8_first_order_filter(plate_tp1_volts_ffffa218,DAT_ffffad54,0.25,1e-05);
  }
  return;
}


