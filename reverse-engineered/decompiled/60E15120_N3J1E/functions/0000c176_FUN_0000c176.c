/* ROM address: 0x0000c176; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c176 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000c176(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  bVar1 = ATUII_TIOR2C_B;
  ATUII_TIOR2C_B = bVar1 & 0xf8 | 1;
  uVar2 = ATUII_TIER2B_W;
  ATUII_TIER2B_W = uVar2 & 0xffef;
  uVar2 = ATUII_TIER2A_W;
  ATUII_TIER2A_W = uVar2 & 0xffef;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


