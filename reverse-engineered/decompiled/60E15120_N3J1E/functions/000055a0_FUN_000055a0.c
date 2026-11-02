/* ROM address: 0x000055a0; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000055a0 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000055a0(void)

{
  ATUII_TSR2A_W = 0x1fd;
  ATUII_TSR2B_W = 0x1fd;
  fatal_interrupt_trap(0x6d);
  return;
}


