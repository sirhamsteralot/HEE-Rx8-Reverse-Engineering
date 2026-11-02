/* ROM address: 0x0000561e; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000561e (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000561e(void)

{
  ATUII_TSR2A_W = 0xff;
  ATUII_TSR2B_W = 0xff;
  fatal_interrupt_trap(0x74);
  return;
}


