/* ROM address: 0x0002fcf8; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000301b0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineTemperatures(void)

{
  inferred_weighted_engine_temperature_ffffbdf0 = inferred_coolant_temperature_ffffa98c * 0.24 + intake_air_temperature_ffffaddc * 0.76;
  DAT_ffffbdf4 = inferred_coolant_temperature_ffffa98c * 0.24 + intake_air_temperature_ffffaddc * 0.76;
  DAT_ffffbdf8 = inferred_coolant_temperature_ffffa98c * 0.24 + intake_air_temperature_ffffaddc * 0.76;
  return;
}


