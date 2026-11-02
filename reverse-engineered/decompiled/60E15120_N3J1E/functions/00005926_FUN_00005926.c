/* ROM address: 0x00005926; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005926 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005926(void)

{
  ATUII_TSR6_W = 0xb;
  fatal_interrupt_trap(0x92);
  return;
}


