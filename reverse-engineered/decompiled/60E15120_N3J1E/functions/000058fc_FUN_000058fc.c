/* ROM address: 0x000058fc; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000058fc (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000058fc(void)

{
  ATUII_TSR3_W = 0x3fff;
  fatal_interrupt_trap(0x8c);
  return;
}


