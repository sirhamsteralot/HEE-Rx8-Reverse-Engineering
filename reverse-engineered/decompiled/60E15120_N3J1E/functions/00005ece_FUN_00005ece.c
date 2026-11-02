/* ROM address: 0x00005ece; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005ece (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005ece(void)

{
  ushort uVar1;
  
  uVar1 = HCAN1_IRR_W;
  HCAN1_IRR_W = uVar1 | 0x6000;
  fatal_interrupt_trap(0xe4);
  return;
}


