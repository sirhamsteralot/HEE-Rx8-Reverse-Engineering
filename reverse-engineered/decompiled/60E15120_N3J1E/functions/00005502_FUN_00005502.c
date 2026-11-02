/* ROM address: 0x00005502; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005502 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005502(void)

{
  ATUII_TSR1A_W = 0x1f7;
  fatal_interrupt_trap(99);
  return;
}


