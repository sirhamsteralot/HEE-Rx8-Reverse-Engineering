/* ROM address: 0x00005d80; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005d80 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005d80(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR1_B;
  SCI_SSR1_B = bVar1 & 7 | 0xc0;
  FUN_00005348(0xcc);
  return;
}


