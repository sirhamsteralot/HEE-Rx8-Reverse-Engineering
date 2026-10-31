/* ROM address: 0x0000e274; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e278 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineRunning(void)

{
  if (250.0 <= engine_speed_rpm_ffffb548) {
    if (500.0 <= engine_speed_rpm_ffffb548) {
      engine_running_ffffa428 = 1;
    }
  }
  else {
    engine_running_ffffa428 = 0;
  }
  return;
}


