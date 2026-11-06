/* [ADDITIONAL SOURCE REVIEW]
 * wheelspeed_rr_validity [high]: 0xffffbbba = 1 when 0xffffbbae == -1 or 0xffffbbbe > 0x1e. Pool 0x2a498.
 * RAM 0xffffbbba wheelspeed_rr_invalid (uint8): RR wheelspeed invalid/stale flag from 0x2b1aa (0xffffbbae == -1 || 0xffffbbbe > 0x1e).
 */
/* ROM address: 0x0002b1aa; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b8fe (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void wheelspeed_rr_validity(void)

{
  if ((wheelspeed_rr_raw_ffffbbae == -1) || (0x1e < DAT_ffffbbbe)) {
    wheelspeed_rr_invalid_ffffbbba = 1;
  }
  else {
    wheelspeed_rr_invalid_ffffbbba = 0;
  }
  return;
}


