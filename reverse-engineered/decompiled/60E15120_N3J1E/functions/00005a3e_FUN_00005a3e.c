/* ROM address: 0x00005a3e; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005a3e (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005a3e(void)

{
  ATUII_TSR8_W = 0xf7ff;
  fatal_interrupt_trap(0xa3);
  return;
}


