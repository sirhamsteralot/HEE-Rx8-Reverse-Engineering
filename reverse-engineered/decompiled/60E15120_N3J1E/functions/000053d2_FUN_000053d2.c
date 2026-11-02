/* ROM address: 0x000053d2; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053d2 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053d2(void)

{
  ISR_W = 0xbf;
  fatal_interrupt_trap(0x41);
  return;
}


