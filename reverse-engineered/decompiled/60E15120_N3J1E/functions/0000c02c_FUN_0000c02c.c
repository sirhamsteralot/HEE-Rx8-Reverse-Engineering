/* [ADDITIONAL SOURCE REVIEW]
 * sci4_read_u16 [high]: SCI4 receive of 2 bytes assembled into a u16: PLIR_W 0xfffff75c |= 0x200, SCI_SCR4_B |= 0x30 (TE|RE), dummy write SCI_TDR4_B = 0, wait SCI_SSR4_B bit 0x40 (RDRF), read SCI_RDR4_B 0xfffff025, repeat for second byte. Register names from symbols.tsv.
 */
/* ROM address: 0x0000c02c; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c02c (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

int sci4_read_u16(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 local_10 [2];
  
  ref_setSR_PARAM(local_10,0xe0);
  uVar4 = PLIR_W;
  PLIR_W = uVar4 & 0xfdff | 0x200;
  FUN_00002064(local_10[0]);
  bVar1 = SCI_SCR4_B;
  SCI_SCR4_B = bVar1 & 0xb | 0x30;
  SCI_TDR4_B = 0;
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 0x7f | 0x78;
  do {
    bVar1 = SCI_SSR4_B;
  } while ((bVar1 & 0x40) == 0);
  bVar2 = SCI_RDR4_B;
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 0xbf | 0xb8;
  SCI_TDR4_B = 0;
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 0x7f | 0x78;
  do {
    bVar1 = SCI_SSR4_B;
  } while ((bVar1 & 0x40) == 0);
  bVar3 = SCI_RDR4_B;
  bVar1 = SCI_SSR4_B;
  SCI_SSR4_B = bVar1 & 0xbf | 0xb8;
  bVar1 = SCI_SCR4_B;
  SCI_SCR4_B = bVar1 & 0xb;
  ref_setSR_PARAM(local_10,0xe0);
  uVar4 = PLIR_W;
  PLIR_W = uVar4 & 0xfdff;
  FUN_00002064(local_10[0]);
  return (uint)bVar2 * 0x100 + (uint)bVar3;
}


