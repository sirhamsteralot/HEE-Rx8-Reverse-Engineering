/* ROM address: 0x00005918; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005918 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005918(void)

{
  ATUII_TSR6_W = 0xd;
  fatal_interrupt_trap(0x91);
  return;
}


