/* ROM address: 0x00005aea; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005aea (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005aea(void)

{
  ATUII_TSR9_W = 0x3d;
  fatal_interrupt_trap(0xa9);
  return;
}


