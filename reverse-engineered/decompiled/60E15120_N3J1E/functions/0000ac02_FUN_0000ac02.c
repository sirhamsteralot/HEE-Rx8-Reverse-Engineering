/* ROM address: 0x0000ac02; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ac02 (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000ac02(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  bVar1 = ATUII_TIOR1D_B;
  ATUII_TIOR1D_B = bVar1 & 0xf8 | 1;
  bVar1 = ATUII_TIOR1D_B;
  ATUII_TIOR1D_B = bVar1 & 0x8f | 0x10;
  bVar1 = ATUII_TIOR2D_B;
  ATUII_TIOR2D_B = bVar1 & 0x8f | 0x10;
  uVar2 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar2 & 0xffbf;
  uVar2 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar2 & 0xff7f;
  uVar2 = ATUII_TIER2B_W;
  ATUII_TIER2B_W = uVar2 & 0xff7f;
  uVar2 = ATUII_TIER1B_W;
  ATUII_TIER1B_W = uVar2 & 0xfffe;
  uVar2 = ATUII_TIER1B_W;
  ATUII_TIER1B_W = uVar2 & 0xfffe;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xff7f;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xffbf;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0xff7f;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar2 & 0x7fff;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


