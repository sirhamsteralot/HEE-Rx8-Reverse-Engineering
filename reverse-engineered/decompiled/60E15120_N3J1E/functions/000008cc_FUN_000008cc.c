/* [ADDITIONAL SOURCE REVIEW]
 * boot_wait_nmi_pin_high [high]: Contains the poll at 0x8ea: mov.w @(0xffffed18) & 0x8000 (ICR_W bit15 = NMI pin level, Sh7055h.pdf 7.3.2) until set. Emulator: with NMI modeled low, boot hangs exactly here (pc 0x8ea, 1 mmio write); with SYSC nmi_level=1 boot reaches idle 0x3dac.
 */
/* ROM address: 0x000008cc; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000008cc (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 boot_wait_nmi_pin_high(void)

{
  ushort uVar1;
  
  BSC_BCR1_W = 0xf;
  BSC_BCR2_W = 0xffff;
  BSC_WCR_W = 0xffff;
  BSC_RAMER_W = 0;
  MSTCR__W__W = 0x3c04;
  ICR_W = 0;
  do {
    uVar1 = ICR_W;
  } while ((uVar1 & 0x8000) == 0);
  return 0;
}


