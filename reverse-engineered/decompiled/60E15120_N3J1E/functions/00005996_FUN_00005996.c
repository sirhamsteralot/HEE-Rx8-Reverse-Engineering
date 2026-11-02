/* ROM address: 0x00005996; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005996 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005996(void)

{
  ATUII_TSR7_W = 7;
  fatal_interrupt_trap(0x97);
  return;
}


