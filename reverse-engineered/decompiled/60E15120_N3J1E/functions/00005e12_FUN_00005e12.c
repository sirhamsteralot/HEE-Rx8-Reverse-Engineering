/* ROM address: 0x00005e12; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005e12 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005e12(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR3_B;
  SCI_SSR3_B = bVar1 & 7 | 0xf8;
  fatal_interrupt_trap(0xd7);
  return;
}


