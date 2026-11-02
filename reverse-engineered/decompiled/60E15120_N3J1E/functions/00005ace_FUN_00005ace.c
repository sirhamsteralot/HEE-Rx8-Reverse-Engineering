/* ROM address: 0x00005ace; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005ace (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005ace(void)

{
  ATUII_TSR8_W = 0x7fff;
  fatal_interrupt_trap(0xa7);
  return;
}


