/* ROM address: 0x000076b8; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000076b8 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000076b8(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = ATUII_TIOR0_B;
  ATUII_TIOR0_B = bVar1 & 0xfc | 1;
  uVar2 = ATUII_TIER0_W;
  ATUII_TIER0_W = uVar2 & 0xfffe;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xfc | 1;
  uVar2 = ATUII_TIER10_W;
  ATUII_TIER10_W = uVar2 & 0xfffd;
  uVar2 = ATUII_TIER10_W;
  ATUII_TIER10_W = uVar2 & 0xfffe;
  uVar2 = ATUII_TIER10_W;
  ATUII_TIER10_W = uVar2 & 0xfff7;
  ATUII_NCR10_B = 200;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xfb | 4;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xf7;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xef;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xbf;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0xdf;
  bVar1 = ATUII_TCR10_B;
  ATUII_TCR10_B = bVar1 & 0x7f;
  ATUII_OCR10AH_W = 0xfa000;
  return;
}


