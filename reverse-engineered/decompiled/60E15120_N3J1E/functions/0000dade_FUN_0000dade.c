/* ROM address: 0x0000dade; body bytes: 10; decompiled */

void can_error_full_reset(void)

{
  ref_canSetup();
  ref_resetCANTimers();
  return;
}


