/* ROM address: 0x00005434; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005434 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005434(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR1_L;
  DMAC_CHCR1_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x4a);
  return;
}


