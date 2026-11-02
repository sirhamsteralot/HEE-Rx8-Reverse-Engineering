/* ROM address: 0x00005b56; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005b56 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00005b56(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = ATUII_TIER10_W;
  if (((uVar1 & 2) == 2) && (uVar1 = ATUII_TSR10_W, (uVar1 & 2) == 2)) {
    ATUII_TSR10_W = 0xd;
    fatal_interrupt_trap(0xb4);
  }
  uVar1 = ATUII_TIER10_W;
  uVar2 = uVar1 & 8;
  if ((uVar2 == 8) && (uVar1 = ATUII_TSR10_W, uVar2 = uVar1 & 8, uVar2 == 8)) {
    ATUII_TSR10_W = 7;
    uVar2 = fatal_interrupt_trap(0xb4);
    return uVar2;
  }
  return uVar2;
}


