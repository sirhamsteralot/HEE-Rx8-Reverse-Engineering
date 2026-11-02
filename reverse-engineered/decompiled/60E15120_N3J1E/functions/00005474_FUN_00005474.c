/* ROM address: 0x00005474; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005474 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005474(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR2_L;
  DMAC_CHCR2_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x4c);
  return;
}


