/* ROM address: 0x000059f8; body bytes: 14; decompiled */

void FUN_000059f8(void)

{
  ATUII_TSR8_W = 0xffbf;
  fatal_interrupt_trap(0x9e);
  return;
}


