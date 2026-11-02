/* ROM address: 0x000054ca; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000054ca (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000054ca(void)

{
  ATUII_TSR0_W = 0xef;
  fatal_interrupt_trap(0x5c);
  return;
}


