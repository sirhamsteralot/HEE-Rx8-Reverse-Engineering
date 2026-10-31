/* ROM address: 0x00005024; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005024 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeWatchdog_disable_00005024(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0xa518;
  return;
}


