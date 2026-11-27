/* [ADDITIONAL SOURCE REVIEW]
 * ref_getDriverOffThrottleInstatanious [high]: Same 2.5/0.5 % hysteresis on 0xffffa9bc (pools 0x1a5be/0x1a5c4/0x1a5c8) producing latch 0xffffaa65 (pool 0x1a5d4); with the latch clear it sets 0xffffaa63 = 1 and 0xffffaa62 = (u16 0xffffaa60 >= ROM 0x6f180 = 0x13) (pools 0x1a5b8/0x1a5ba/0x1a5bc, cmp/hs at 0x1a59e), with the latch set it clears both.
 * RAM 0xffffaa63 candidate_closed_throttle_flag (uint8): Set to 1 whenever the throttle latch 0xffffaa65 is clear (0x1a5a4/0x1a5aa), 0 when it is set (0x1a5b0); primed to 1 by 0x1a508.
 * RAM 0xffffaa65 candidate_throttle_open_latch (uint8): Hysteresis latch on 0xffffa9bc: set to 1 at >= 2.5 % (f32 0x6f184, 0x1a57e/0x1a580), cleared below 2.0 % (= 2.5 - 0.5 from f32 0x6f188, 0x1a588), unchanged in between.
 */
/* ROM address: 0x0001a564; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b014 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDriverOffThrottleInstatanious(void)

{
  if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.5) {
    if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.0) {
      candidate_throttle_open_latch_ffffaa65 = '\0';
    }
  }
  else {
    candidate_throttle_open_latch_ffffaa65 = '\x01';
  }
  if (candidate_throttle_open_latch_ffffaa65 == '\0') {
    if (candidate_closed_throttle_dwell_ffffaa60 < 0x13) {
      candidate_closed_throttle_flag_ffffaa63 = 1;
      cranking_active_ffffaa62_ffffaa62 = 0;
    }
    else {
      candidate_closed_throttle_flag_ffffaa63 = 1;
      cranking_active_ffffaa62_ffffaa62 = 1;
    }
  }
  else {
    candidate_closed_throttle_flag_ffffaa63 = 0;
    cranking_active_ffffaa62_ffffaa62 = 0;
  }
  return;
}


