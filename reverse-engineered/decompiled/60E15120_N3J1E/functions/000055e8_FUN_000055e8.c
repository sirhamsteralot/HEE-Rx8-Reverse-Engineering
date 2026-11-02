/* ROM address: 0x000055e8; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000055e8 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000055e8(void)

{
  ATUII_TSR2A_W = 0x1df;
  ATUII_TSR2B_W = 0x1df;
  fatal_interrupt_trap(0x71);
  return;
}


