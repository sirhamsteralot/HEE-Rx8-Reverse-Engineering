/* ROM address: 0x00024ea6; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002572e (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getEngineSpeed(void)

{
  DAT_ffffb558 = rx8_divide_with_zero_fallback((float)crank_period_accumulator_ffff9f88,0x457a0000);
  engine_speed_rpm_ffffb548 = engine_speed_rpm_raw_ffff9f80;
  return;
}


