/* [ADDITIONAL SOURCE REVIEW]
 * catalyst_temp_monitor_batch [high]: 4-call batch, pool 0x11cc4-0x11cd0 ROM-verified: 0x39ca8, 0x146a6, ref_catTempRelated 0x3eb3a, 0x16fb6. Called only from task[15] 0x65da.
 */
/* ROM address: 0x00011b08; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011b80 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void catalyst_temp_monitor_batch(void)

{
  FUN_00039ca8();
  FUN_000146a6();
  ref_catTempRelated();
  FUN_00016fb6();
  return;
}


