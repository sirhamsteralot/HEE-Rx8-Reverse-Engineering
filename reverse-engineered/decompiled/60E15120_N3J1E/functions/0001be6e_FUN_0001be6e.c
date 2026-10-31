/* ROM address: 0x0001be6e; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001c91e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001be6e(void)

{
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffade0 = rx8_first_order_filter(intake_air_temperature_ffffaddc,DAT_ffffade0,0.25,1e-05);
  }
  return;
}


