/* ROM address: 0x00005da6; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005da6 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005da6(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR1_B;
  SCI_SSR1_B = bVar1 & 7 | 0xf8;
  FUN_00005348(0xcf);
  return;
}


