/* ROM address: 0x00008f94; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008f94 (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00008f94(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  bVar1 = ATUII_TIOR2A_B;
  ATUII_TIOR2A_B = bVar1 & 0xf8 | 1;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xfffe;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xfeff;
  bVar1 = ATUII_TIOR2B_B;
  ATUII_TIOR2B_B = bVar1 & 0xf8 | 1;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xfffb;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xfbff;
  bVar1 = ATUII_TIOR2A_B;
  ATUII_TIOR2A_B = bVar1 & 0x8f | 0x10;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xfffd;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xfdff;
  bVar1 = ATUII_TIOR2B_B;
  ATUII_TIOR2B_B = bVar1 & 0x8f | 0x10;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xfff7;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xf7ff;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


