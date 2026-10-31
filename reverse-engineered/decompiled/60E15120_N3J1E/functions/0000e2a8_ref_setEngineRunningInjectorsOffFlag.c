/* [ADDITIONAL SOURCE REVIEW]
 * update_injectors_off_flag [high]: engine_injectors_off a42c = 1 iff !engine_running (a428) && !a41c.
 * RAM 0xffffa41c engine_stopped_latch (uint8): a41c blocks the injectors-off flag a42c; also forces load 0.525 in calculate_engine_load (0x33ad2).
 */
/* ROM address: 0x0000e2a8; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e2ac (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void update_injectors_off_flag(void)

{
  if ((engine_running_ffffa428 == '\0') && (engine_stopped_latch_ffffa41c == '\0')) {
    engine_injectors_off_ffffa42c = 1;
  }
  else {
    engine_injectors_off_ffffa42c = 0;
  }
  return;
}


