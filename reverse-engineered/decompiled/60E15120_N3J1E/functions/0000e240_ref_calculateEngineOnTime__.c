/* ROM address: 0x0000e240; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e244 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineOnTime__(void)

{
  if (engine_running_ffffa428 == '\0') {
    engine_on_time_counter_ffffa426 = 0;
  }
  else {
    engine_on_time_counter_ffffa426 = rx8_add_u16_saturate((int)engine_on_time_counter_ffffa426,1);
  }
  return;
}


