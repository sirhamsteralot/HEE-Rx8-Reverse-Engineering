/* ROM address: 0x00005032; body bytes: 4; decompiled */

void ref_writeWatchdog_disable_00005032(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0xa518;
  return;
}


