/* ROM address: 0x0000b5a0; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b5a0 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000b5a0(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  SCI_SMR1_B = 0x80;
  bVar2 = SCI_SCR1_B;
  SCI_SCR1_B = bVar2 & 0xfc;
  SCI_SDCR1_B = 0xf8;
  cVar1 = SCI_BRR1_B;
  if (cVar1 != '\x04') {
    SCI_BRR1_B = 4;
  }
  bVar2 = ATUII_TCR9C_B;
  ATUII_TCR9C_B = bVar2 & 0xfc | 2;
  ATUII_GR9E_B = 0;
  uVar3 = ATUII_TIER9_W;
  ATUII_TIER9_W = uVar3 & 0xffef | 0x10;
  uVar4 = FUN_00002064(local_8[0]);
  return uVar4;
}


