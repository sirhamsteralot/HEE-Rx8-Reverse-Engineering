/* ROM address: 0x00005482; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005482 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005482(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR3_L;
  DMAC_CHCR3_L = uVar1 & 0xfffffffd;
  FUN_00005348(0x4e);
  return;
}


