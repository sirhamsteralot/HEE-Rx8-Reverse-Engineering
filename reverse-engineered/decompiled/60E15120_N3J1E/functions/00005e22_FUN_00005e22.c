/* ROM address: 0x00005e22; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005e22 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005e22(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 7 | 0xc0;
  fatal_interrupt_trap(0xd8);
  return;
}


