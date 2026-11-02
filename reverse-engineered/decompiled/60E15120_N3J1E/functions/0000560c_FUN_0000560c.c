/* ROM address: 0x0000560c; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000560c (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000560c(void)

{
  ATUII_TSR2A_W = 0x17f;
  ATUII_TSR2B_W = 0x17f;
  fatal_interrupt_trap(0x73);
  return;
}


