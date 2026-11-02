/* ROM address: 0x00005a14; body bytes: 14; decompiled */

void FUN_00005a14(void)

{
  ATUII_TSR8_W = 0xfeff;
  fatal_interrupt_trap(0xa0);
  return;
}


