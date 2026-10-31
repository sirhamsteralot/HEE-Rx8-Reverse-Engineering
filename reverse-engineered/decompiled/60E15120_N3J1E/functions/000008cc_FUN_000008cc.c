/* ROM address: 0x000008cc; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000008cc (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000008cc(void)

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


