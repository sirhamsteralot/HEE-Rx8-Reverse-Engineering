/* ROM address: 0x0000590a; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000590a (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000590a(void)

{
  ATUII_TSR6_W = 0xe;
  fatal_interrupt_trap(0x90);
  return;
}


