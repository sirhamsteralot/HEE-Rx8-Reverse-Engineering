/* ROM address: 0x000054b2; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000054b2 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000054b2(void)

{
  ATUII_TSR0_W = 0xfb;
  fatal_interrupt_trap(0x58);
  return;
}


