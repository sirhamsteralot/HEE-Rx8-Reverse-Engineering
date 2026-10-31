/* ROM address: 0x00043870; body bytes: 42; decompiled */

void FUN_00043870(void)

{
  if (inferred_coolant_temperature_ffffa98c < 70.0) {
    if (inferred_coolant_temperature_ffffa98c < 65.0) {
      DAT_ffffca4d = 0;
    }
  }
  else {
    DAT_ffffca4d = 1;
  }
  return;
}


