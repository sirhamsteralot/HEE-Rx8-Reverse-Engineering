/* ROM address: 0x00001364; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001364 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_resetWatchdog_00001364(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0x5a00;
  Ramffffec10 = 0xa53c;
  return;
}


