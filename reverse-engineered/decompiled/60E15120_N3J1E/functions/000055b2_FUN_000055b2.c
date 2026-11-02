/* ROM address: 0x000055b2; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000055b2 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000055b2(void)

{
  ATUII_TSR2A_W = 0x1fb;
  ATUII_TSR2B_W = 0x1fb;
  fatal_interrupt_trap(0x6e);
  return;
}


