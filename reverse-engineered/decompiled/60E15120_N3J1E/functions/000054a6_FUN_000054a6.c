/* ROM address: 0x000054a6; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000054a6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000054a6(void)

{
  ATUII_TSR0_W = 0xfd;
  fatal_interrupt_trap(0x56);
  return;
}


