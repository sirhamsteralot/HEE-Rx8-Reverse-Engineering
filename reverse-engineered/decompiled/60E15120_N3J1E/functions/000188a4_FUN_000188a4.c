/* ROM address: 0x000188a4; body bytes: 284; decompiled */

void FUN_000188a4(void)

{
  if (vehicle_speed_ffffbbb4 < 3.0) {
    if (vehicle_speed_ffffbbb4 < 1.0) {
      DAT_ffffa978 = '\0';
    }
  }
  else {
    DAT_ffffa978 = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 105.0) {
    if (inferred_coolant_temperature_ffffa98c < 101.0) {
      DAT_ffffa979 = '\0';
    }
  }
  else {
    DAT_ffffa979 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 5000.0) {
    if (engine_speed_rpm_ffffb548 < 5000.0) {
      DAT_ffffa97a = '\0';
    }
  }
  else {
    DAT_ffffa97a = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 1000.0) {
    if (engine_speed_rpm_ffffb548 < 1000.0) {
      DAT_ffffa97b = '\0';
    }
  }
  else {
    DAT_ffffa97b = '\x01';
  }
  if ((((DAT_ffffb53a == '\0') || (DAT_ffffa978 == '\x01')) || (DAT_ffffa979 == '\0')) ||
     (((DAT_ffffa97b == '\0' || (DAT_ffffc590 == '\x01')) ||
      ((DAT_ffffc5e6 == '\x01' || (DAT_ffffc61e == '\x01')))))) {
    decel_cut_request_a_ffffa96a = 0;
    DAT_ffffa96e = 0;
  }
  else if (DAT_ffffa97a == '\x01') {
    if (0x9b < DAT_ffffa96e) {
      decel_cut_request_a_ffffa96a = 1;
    }
    DAT_ffffa96e = rx8_add_u16_saturate((int)(short)DAT_ffffa96e,1);
  }
  else {
    DAT_ffffa96e = 0;
  }
  return;
}


