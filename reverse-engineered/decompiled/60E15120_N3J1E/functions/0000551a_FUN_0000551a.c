/* ROM address: 0x0000551a; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000551a (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000551a(void)

{
  ATUII_TSR1A_W = 0x1df;
  fatal_interrupt_trap(0x65);
  return;
}


