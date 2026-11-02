/* ROM address: 0x00005a06; body bytes: 14; decompiled */

void FUN_00005a06(void)

{
  ATUII_TSR8_W = 0xff7f;
  fatal_interrupt_trap(0x9f);
  return;
}


