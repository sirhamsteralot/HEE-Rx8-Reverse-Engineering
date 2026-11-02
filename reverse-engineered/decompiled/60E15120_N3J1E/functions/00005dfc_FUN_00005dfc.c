/* ROM address: 0x00005dfc; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005dfc (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005dfc(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR3_B;
  SCI_SSR3_B = bVar1 & 7 | 0xb8;
  fatal_interrupt_trap(0xd5);
  return;
}


