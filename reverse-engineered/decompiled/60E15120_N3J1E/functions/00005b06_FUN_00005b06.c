/* ROM address: 0x00005b06; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005b06 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005b06(void)

{
  ATUII_TSR9_W = 0x37;
  fatal_interrupt_trap(0xab);
  return;
}


