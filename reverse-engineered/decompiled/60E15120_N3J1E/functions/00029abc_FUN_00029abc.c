/* ROM address: 0x00029abc; body bytes: 86; decompiled */

void FUN_00029abc(void)

{
  if (((((leading_ignition_timing_ffffa630 <= DAT_ffffa928) && (DAT_ffffa93c == '\x01')) && (engine_running_ffffa428 == '\x01')) &&
      (DAT_ffffaa62 == '\0')) || ((DAT_ffffa938 == 0 && (DAT_ffffa93a != 0)))) {
    DAT_ffffbb25 = 1;
  }
  else {
    DAT_ffffbb25 = 0;
  }
  return;
}


