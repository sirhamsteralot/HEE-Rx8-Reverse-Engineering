/* ROM address: 0x00042e8e; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000426c2 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setLoadandRPM(void)

{
  DAT_ffffc9ec = rx8_clamp_float(engine_load_ffffc0b4,0.099999994,2.0);
  DAT_ffffc9e8 = engine_speed_rpm_ffffb548 * 1.0;
  return;
}


