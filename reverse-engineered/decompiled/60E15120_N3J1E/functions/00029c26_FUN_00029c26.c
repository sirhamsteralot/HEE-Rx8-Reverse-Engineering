/* ROM address: 0x00029c26; body bytes: 52; decompiled */

void FUN_00029c26(void)

{
  if (((0.0 < inferred_coolant_temperature_ffffa98c) || (engine_running_ffffa428 != '\x01')) || (cranking_active_ffffaa62_ffffaa62 != '\0')) {
    DAT_ffffbb28 = 0;
  }
  else {
    DAT_ffffbb28 = 1;
  }
  return;
}


