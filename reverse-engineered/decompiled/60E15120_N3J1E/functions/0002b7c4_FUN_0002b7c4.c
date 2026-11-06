/* [ADDITIONAL SOURCE REVIEW]
 * can212_timeout_flag [medium]: 0xffffbbd0 = (0x1e < 0xffffbbf0) — 0x212 RX timeout flag from the failure counter. Pool 0x2a488.
 */
/* ROM address: 0x0002b7c4; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bf18 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * candidate_can212_timeout_flag(void)

{
  DAT_ffffbbd0 = 0x1e < can212_timeout_counter_ffffbbf0;
  return &DAT_0007bc56;
}


