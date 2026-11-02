/* ROM address: 0x000055c4; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000055c4 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000055c4(void)

{
  ATUII_TSR2A_W = 0x1f7;
  ATUII_TSR2B_W = 0x1f7;
  fatal_interrupt_trap(0x6f);
  return;
}


