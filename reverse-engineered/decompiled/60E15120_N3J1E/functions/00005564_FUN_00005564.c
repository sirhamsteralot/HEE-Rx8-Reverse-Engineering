/* ROM address: 0x00005564; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005564 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005564(void)

{
  ATUII_TSR2A_W = 0x1fe;
  ATUII_TSR2B_W = 0x1fe;
  fatal_interrupt_trap(0x6c);
  return;
}


