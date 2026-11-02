/* ROM address: 0x00005490; body bytes: 10; decompiled */

void FUN_00005490(void)

{
  ATUII_TSR0_W = 0x1f;
  fatal_interrupt_trap(0x50);
  return;
}


