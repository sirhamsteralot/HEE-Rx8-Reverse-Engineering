/* ROM address: 0x00005cc4; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005cc4 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005cc4(void)

{
  ATUII_TSR11_W = 3;
  fatal_interrupt_trap(0xbb);
  return;
}


