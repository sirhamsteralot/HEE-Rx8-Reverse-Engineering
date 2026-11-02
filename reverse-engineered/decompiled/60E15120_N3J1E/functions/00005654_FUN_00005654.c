/* ROM address: 0x00005654; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005654 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005654(void)

{
  ATUII_TSR3_W = 0x7ff7;
  fatal_interrupt_trap(0x7b);
  return;
}


