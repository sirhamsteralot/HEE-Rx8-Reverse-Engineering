/* ROM address: 0x000053c6; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053c6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053c6(void)

{
  ISR_W = 0x7f;
  fatal_interrupt_trap(0x40);
  return;
}


