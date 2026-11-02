/* ROM address: 0x00005402; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005402 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005402(void)

{
  ISR_W = 0xfb;
  fatal_interrupt_trap(0x45);
  return;
}


