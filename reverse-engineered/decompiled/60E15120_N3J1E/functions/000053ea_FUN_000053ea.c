/* ROM address: 0x000053ea; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053ea (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053ea(void)

{
  ISR_W = 0xef;
  fatal_interrupt_trap(0x43);
  return;
}


