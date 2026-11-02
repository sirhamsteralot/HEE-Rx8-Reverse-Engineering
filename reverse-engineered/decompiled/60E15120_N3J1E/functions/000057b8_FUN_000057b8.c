/* ROM address: 0x000057b8; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000057b8 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000057b8(void)

{
  ATUII_TSR3_W = 0x7bff;
  fatal_interrupt_trap(0x88);
  return;
}


