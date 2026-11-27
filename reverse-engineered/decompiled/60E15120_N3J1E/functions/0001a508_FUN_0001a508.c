/* [ADDITIONAL SOURCE REVIEW]
 * candidate_start_flags_prime [high]: Writes u16 0xffffaa60 = 0x13 and sets bytes 0xffffaa63 and 0xffffaa62 = 1, i.e. primes the closed-throttle dwell gate to its satisfied state; called from 0x19640 inside the 0x1102a init fan-out.
 */
/* ROM address: 0x0001a508; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001afb8 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_start_flags_prime(void)

{
  candidate_closed_throttle_dwell_ffffaa60 = 0x13;
  candidate_closed_throttle_flag_ffffaa63 = 1;
  cranking_active_ffffaa62_ffffaa62 = 1;
  return;
}


