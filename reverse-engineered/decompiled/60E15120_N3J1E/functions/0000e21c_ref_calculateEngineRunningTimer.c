/* ROM address: 0x0000e21c; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e220 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineRunningTimer(void)

{
  if (engine_running_ffffa428 == '\0') {
    engine_running_timer_ffffa424 = 0;
  }
  else {
    engine_running_timer_ffffa424 = rx8_add_u16_saturate((int)engine_running_timer_ffffa424,1);
  }
  return;
}


