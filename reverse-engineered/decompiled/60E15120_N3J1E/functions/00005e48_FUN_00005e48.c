/* ROM address: 0x00005e48; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005e48 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005e48(void)

{
  byte bVar1;
  
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 7 | 0xf8;
  FUN_00005348(0xdb);
  return;
}


