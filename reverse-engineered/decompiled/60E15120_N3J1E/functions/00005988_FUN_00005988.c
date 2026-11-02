/* ROM address: 0x00005988; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005988 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005988(void)

{
  ATUII_TSR7_W = 0xb;
  fatal_interrupt_trap(0x96);
  return;
}


