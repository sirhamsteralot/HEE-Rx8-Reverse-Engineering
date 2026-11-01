/* ROM address: 0x0003836a; body bytes: 110; decompiled */

void FUN_0003836a(void)

{
  if ((inferred_temp_c4c8_ffffc4c8_ffffc4c8 <= 40.0) || (vehicle_speed_ffffbbb4 <= 40.0)) {
    DAT_ffffc503 = '\0';
  }
  else {
    DAT_ffffc503 = '\x01';
  }
  if (DAT_ffffc503 == '\x01') {
    DAT_ffffc4e8 = DAT_ffffc4d8 + DAT_ffffc4e8;
  }
  DAT_ffffc4f4 = rx8_max_float(DAT_ffffc4f4 + (inferred_temp_c4c8_ffffc4c8_ffffc4c8 - inferred_coolant_temperature_ffffa98c) * DAT_ffffc518,0.0);
  return;
}


