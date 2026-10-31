/* ROM address: 0x00005dec; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005dec (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005dec(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR3_B;
  SCI_SSR3_B = bVar1 & 7 | 0xc0;
  FUN_00005348(0xd4);
  return;
}


