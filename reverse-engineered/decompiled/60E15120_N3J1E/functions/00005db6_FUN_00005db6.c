/* ROM address: 0x00005db6; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005db6 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005db6(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR2_B;
  SCI_SSR2_B = bVar1 & 7 | 0xc0;
  FUN_00005348(0xd0);
  return;
}


