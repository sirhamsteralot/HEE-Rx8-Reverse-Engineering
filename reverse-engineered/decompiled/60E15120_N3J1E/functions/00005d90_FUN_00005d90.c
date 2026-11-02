/* ROM address: 0x00005d90; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005d90 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005d90(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR1_B;
  SCI_SSR1_B = bVar1 & 7 | 0xb8;
  fatal_interrupt_trap(0xcd);
  return;
}


