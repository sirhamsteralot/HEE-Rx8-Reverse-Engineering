/* ROM address: 0x00029bf2; body bytes: 52; decompiled */

void FUN_00029bf2(void)

{
  if (((DAT_ffffb418 < inferred_throttle_position_ffffad44) || (engine_running_ffffa428 != '\x01')) || (DAT_ffffaa62 != '\0')) {
    DAT_ffffbb27 = 0;
  }
  else {
    DAT_ffffbb27 = 1;
  }
  return;
}


