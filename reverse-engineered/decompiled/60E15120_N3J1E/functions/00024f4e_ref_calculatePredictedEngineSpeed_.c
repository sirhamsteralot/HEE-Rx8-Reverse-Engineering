/* ROM address: 0x00024f4e; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000257d6 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculatePredictedEngineSpeed_(void)

{
  inferred_predicted_engine_speed_ffffb55c = rx8_clamp_float(engine_speed_rpm_ffffb548 + (engine_speed_rpm_ffffb548 - DAT_ffffb564) * 2.0,0.0,9000.0);
  DAT_ffffb564 = engine_speed_rpm_ffffb548;
  return;
}


