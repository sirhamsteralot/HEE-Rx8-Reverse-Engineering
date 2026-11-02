/* ROM address: 0x00005532; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005532 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005532(void)

{
  ATUII_TSR1A_W = 0x17f;
  fatal_interrupt_trap(0x67);
  return;
}


