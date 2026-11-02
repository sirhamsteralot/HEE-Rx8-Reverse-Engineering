/* ROM address: 0x00005a22; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005a22 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005a22(void)

{
  ATUII_TSR8_W = 0xfdff;
  fatal_interrupt_trap(0xa1);
  return;
}


