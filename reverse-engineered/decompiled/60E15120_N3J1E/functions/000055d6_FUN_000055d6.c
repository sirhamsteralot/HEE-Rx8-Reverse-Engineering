/* ROM address: 0x000055d6; body bytes: 18; decompiled */

void FUN_000055d6(void)

{
  ATUII_TSR2A_W = 0x1ef;
  ATUII_TSR2B_W = 0x1ef;
  fatal_interrupt_trap(0x70);
  return;
}


