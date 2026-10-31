/* ROM address: 0x0000d5ac; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d5ac (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

ulonglong FUN_0000d5ac(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = DMAC_DMAOR_W;
  DMAC_DMAOR_W = uVar1 & 0xfff8 | 1;
  DAT_ffff9300 = 0;
  DMAC_SAR0_L = &DAT_ffff9300;
  DMAC_DAR0_L = &DAT_ffff9300;
  DMAC_CHCR0_L._2_2_ = 0x128;
  DMAC_CHCR0_L = 0x1f0128;
  DMAC_DMATCR0_L = 0x133f;
  uVar2 = DMAC_CHCR0_L;
  DMAC_CHCR0_L = uVar2 & 0xfffffff9 | 1;
  do {
    uVar3 = DMAC_CHCR0_L;
  } while ((uVar3 & 2) == 0);
  uVar4 = DMAC_CHCR0_L;
  uVar3 = DMAC_CHCR0_L;
  DMAC_CHCR0_L = uVar3 & 0xfffffffc;
  return CONCAT44(uVar4,uVar2) & 0xfffffffffffffff9 | 1;
}


