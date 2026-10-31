/* ROM address: 0x0004c6a4; body bytes: 256; decompiled */

void FUN_0004c6a4(void)

{
  if (inferred_battery_voltage_ffffb590 <= 14.2) {
    if (inferred_battery_voltage_ffffb590 <= 14.0) {
      DAT_ffffceb0 = '\0';
    }
  }
  else {
    DAT_ffffceb0 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 7900.0) {
    if (engine_speed_rpm_ffffb548 < 7850.0) {
      DAT_ffffceb1 = '\0';
    }
  }
  else {
    DAT_ffffceb1 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 <= 8300.0) {
    if (engine_speed_rpm_ffffb548 <= 8250.0) {
      DAT_ffffceb2 = '\0';
    }
  }
  else {
    DAT_ffffceb2 = '\x01';
  }
  if (engine_load_ffffc0b4 < 0.85) {
    if (engine_load_ffffc0b4 < 0.8) {
      DAT_ffffceb3 = '\0';
    }
  }
  else {
    DAT_ffffceb3 = '\x01';
  }
  if ((((((DAT_ffffceb0 != '\0') || (inferred_coolant_temperature_ffffa98c < 90.0)) || (102.0 < inferred_coolant_temperature_ffffa98c)) ||
       ((intake_air_temperature_ffffaddc < 25.0 || (32.0 < intake_air_temperature_ffffaddc)))) ||
      ((DAT_ffffceb1 != '\x01' || ((DAT_ffffceb2 != '\0' || (DAT_ffffceb3 != '\x01')))))) ||
     (fuel_blend_weight_ffffb11c < 0.9899999)) {
    DAT_ffffa0d6 = 0;
  }
  else {
    DAT_ffffa0d6 = 0x7d;
  }
  return;
}


