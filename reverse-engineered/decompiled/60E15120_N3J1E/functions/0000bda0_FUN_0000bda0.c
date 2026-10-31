/* ROM address: 0x0000bda0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bda0 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000bda0(void)

{
  byte bVar1;
  
  SCI_SMR4_B = 0x80;
  bVar1 = SCI_SCR4_B;
  SCI_SCR4_B = bVar1 & 0xfc;
  SCI_SDCR4_B = 0xf8;
  SCI_BRR4_B = 6;
  return;
}


