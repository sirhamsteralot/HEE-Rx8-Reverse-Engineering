/* ROM address: 0x00005d16; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005d16 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005d16(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR0_B;
  SCI_SSR0_B = bVar1 & 7 | 0xc0;
  FUN_00005348(200);
  return;
}


