/* ROM address: 0x000081a8; body bytes: 192; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000081a8 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000081a8(void)

{
  ushort uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  
  bVar2 = 0;
  ppuVar4 = &PTR_ATUII_DCNT8A_W_0000d7d4;
  puVar3 = &DAT_ffffa004;
  do {
    puVar3[0x13] = 0;
    puVar3[0x14] = 0;
    uVar1 = ATUII_TIER8_W;
    ATUII_TIER8_W = ~*(ushort *)(ppuVar4 + 2) & uVar1;
    FUN_0000a8a4(*ppuVar4,0);
    bVar2 = bVar2 + 1;
    ppuVar4 = ppuVar4 + 3;
    puVar3 = puVar3 + 0x18;
  } while (bVar2 < 6);
  bVar2 = ATUII_TIOR1A_B;
  ATUII_TIOR1A_B = bVar2 & 0xf8 | 1;
  bVar2 = ATUII_TIOR1A_B;
  ATUII_TIOR1A_B = bVar2 & 0x8f | 0x10;
  bVar2 = ATUII_TIOR1B_B;
  ATUII_TIOR1B_B = bVar2 & 0xf8 | 1;
  bVar2 = ATUII_TIOR1B_B;
  ATUII_TIOR1B_B = bVar2 & 0x8f | 0x10;
  bVar2 = ATUII_TIOR1C_B;
  ATUII_TIOR1C_B = bVar2 & 0xf8 | 1;
  bVar2 = ATUII_TIOR1C_B;
  ATUII_TIOR1C_B = bVar2 & 0x8f | 0x10;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xfffe;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xfffd;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xfffb;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xfff7;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xffef;
  uVar1 = ATUII_TIER1A_W;
  ATUII_TIER1A_W = uVar1 & 0xffdf;
  return;
}


