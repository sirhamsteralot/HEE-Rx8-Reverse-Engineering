/* ROM address: 0x00005af8; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005af8 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005af8(void)

{
  ATUII_TSR9_W = 0x3b;
  fatal_interrupt_trap(0xaa);
  return;
}


