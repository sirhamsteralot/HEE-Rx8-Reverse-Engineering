/* [ADDITIONAL SOURCE REVIEW]
 * wdt_keyed_reset [high]: Was ref_resetWatchdog_: RSTCSR_W 0xffffec12 = 0x5a1f (pools 0x596=0x5a1f, 0x598=0xec12), then TCSR 0xffffec10 = 0x5a00 and keyed write 0xa53c (pools 0x59a=0xec10, 0x5ac=0xa53c) - SH keyed WDT/RSTCSR write idiom (0x5a/0xa5 upper bytes).
 */
/* ROM address: 0x00000572; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000572 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void wdt_keyed_reset(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0x5a00;
  Ramffffec10 = 0xa53c;
  return;
}


