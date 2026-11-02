/* ROM address: 0x00005426; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005426 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005426(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR0_L;
  DMAC_CHCR0_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x48);
  return;
}


