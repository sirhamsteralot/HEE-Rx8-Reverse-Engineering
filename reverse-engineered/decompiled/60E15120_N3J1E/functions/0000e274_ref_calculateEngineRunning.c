/* [ADDITIONAL SOURCE REVIEW]
 * engine_running_from_rpm [high]: Was ref_calculateEngineRunning: engine_running 0xffffa428 = 1 when rpm 0xffffb548 >= 500.0 (pools 0xe29c=0xb548, 0xe29e=0xa428, float consts via pools 0xe2a0/0xe2a4 -> 0x6c190/0x6c194), cleared below 250.0; distinct from the key-on flag 0xffffaa68 (PFDR bit0 via 0xffff9ec8).
 */
/* ROM address: 0x0000e274; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e278 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void engine_running_from_rpm(void)

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


