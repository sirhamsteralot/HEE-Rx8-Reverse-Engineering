/* ROM address: 0x0002c774; body bytes: 328; decompiled */

char FUN_0002c774(void)

{
  if (engine_load_ffffc0b4 < 0.25) {
    if (engine_load_ffffc0b4 < 0.21000001) {
      DAT_ffffbc88 = '\0';
    }
  }
  else {
    DAT_ffffbc88 = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 0.0) {
    if (inferred_coolant_temperature_ffffa98c < -5.0) {
      DAT_ffffbc89 = '\0';
    }
  }
  else {
    DAT_ffffbc89 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 4800.0) {
    if (engine_speed_rpm_ffffb548 < 4700.0) {
      DAT_ffffbc8b = '\0';
    }
  }
  else {
    DAT_ffffbc8b = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 9500.0) {
    if (engine_speed_rpm_ffffb548 < 9400.0) {
      DAT_ffffbc8c = '\0';
    }
  }
  else {
    DAT_ffffbc8c = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 10000.0) {
    if (engine_speed_rpm_ffffb548 < 9900.0) {
      DAT_ffffbc8d = '\0';
    }
  }
  else {
    DAT_ffffbc8d = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 11000.0) {
    if (engine_speed_rpm_ffffb548 < 10900.0) {
      DAT_ffffbc8e = '\0';
    }
  }
  else {
    DAT_ffffbc8e = '\x01';
  }
  if (DAT_ffffbc88 == '\x01') {
    if (DAT_ffffbc89 == '\x01') {
      DAT_ffffbc82 = '\x0f';
    }
    else {
      DAT_ffffbc82 = '\n';
    }
  }
  else if (DAT_ffffbc89 == '\x01') {
    DAT_ffffbc82 = '\x05';
  }
  else {
    DAT_ffffbc82 = '\0';
  }
  if (DAT_ffffbc8b != '\0') {
    if (DAT_ffffbc8c == '\0') {
      DAT_ffffbc82 = DAT_ffffbc82 + '\x01';
    }
    else if (DAT_ffffbc8d == '\0') {
      DAT_ffffbc82 = DAT_ffffbc82 + '\x02';
    }
    else if (DAT_ffffbc8e == '\0') {
      DAT_ffffbc82 = DAT_ffffbc82 + '\x03';
    }
    else {
      DAT_ffffbc82 = DAT_ffffbc82 + '\x04';
    }
  }
  return DAT_ffffbc89;
}


