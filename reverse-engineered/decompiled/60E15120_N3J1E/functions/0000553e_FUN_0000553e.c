/* ROM address: 0x0000553e; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000553e (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000553e(void)

{
  ushort uVar1;
  
  uVar1 = ATUII_TSR1B_W;
  if ((uVar1 & 0x100) == 0x100) {
    ATUII_TSR1B_W = 1;
    ATUII_TSR1A_W = 0xff;
    fatal_interrupt_trap(0x68);
    return;
  }
  return;
}


