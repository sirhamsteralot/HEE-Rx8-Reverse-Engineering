/* ROM address: 0x000054f6; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000054f6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000054f6(void)

{
  ATUII_TSR1A_W = 0x1fb;
  fatal_interrupt_trap(0x62);
  return;
}


