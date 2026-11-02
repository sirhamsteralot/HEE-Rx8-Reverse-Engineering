/* ROM address: 0x0000566c; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000566c (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000566c(void)

{
  ATUII_TSR3_W = 0x7fdf;
  fatal_interrupt_trap(0x80);
  return;
}


