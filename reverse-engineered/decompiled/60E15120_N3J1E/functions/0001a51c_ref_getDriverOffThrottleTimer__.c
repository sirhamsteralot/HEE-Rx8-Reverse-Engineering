/* [ADDITIONAL SOURCE REVIEW]
 * ref_getDriverOffThrottleTimer__ [high]: Latches 0xffffaa64 from the throttle demand 0xffffa9bc against f32 0x6f184 = 2.5 and f32 0x6f188 = 0.5 (0.5-wide hysteresis), then increments the u16 0xffffaa60 (saturating, 0x2460) while the latch is clear and resets it to 0 otherwise.
 * RAM 0xffffaa60 candidate_closed_throttle_dwell (uint16): Saturating u16 counter: incremented by 0x1a51c while the throttle demand 0xffffa9bc stays below 2.0 %, reset to 0 above 2.5 %; primed to 0x13 by 0x1a508.
 */
/* ROM address: 0x0001a51c; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001afcc (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDriverOffThrottleTimer__(void)

{
  if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.5) {
    if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.0) {
      DAT_ffffaa64 = '\0';
    }
  }
  else {
    DAT_ffffaa64 = '\x01';
  }
  if (DAT_ffffaa64 == '\0') {
    candidate_closed_throttle_dwell_ffffaa60 = rx8_add_u16_saturate((int)candidate_closed_throttle_dwell_ffffaa60,1);
  }
  else {
    candidate_closed_throttle_dwell_ffffaa60 = 0;
  }
  return;
}


