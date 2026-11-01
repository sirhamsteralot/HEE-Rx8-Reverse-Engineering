/* ROM address: 0x0002590a; body bytes: 226; decompiled */

void FUN_0002590a(void)

{
  if (inferred_battery_voltage_ffffb590 < 10.0) {
    if (inferred_battery_voltage_ffffb590 < 9.0) {
      DAT_ffffb646 = '\0';
    }
  }
  else {
    DAT_ffffb646 = '\x01';
  }
  if (((((inferred_ram_b654_ffffb654_ffffb654 <= 16.973) || (10.938 <= DAT_ffffb658)) || (engine_running_ffffa428 == '\0')) ||
      ((engine_running_ffffa428 == '\x01' && (DAT_ffffb63c < 0x3f)))) ||
     ((DAT_ffffb646 == '\0' || ((DAT_ffffb646 == '\x01' && (DAT_ffffb63e < 0x3f)))))) {
    DAT_ffffb60a = 0x138;
  }
  else if (DAT_ffffb60a != 0) {
    DAT_ffffb60a = DAT_ffffb60a + -1;
  }
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffb63c = 0;
  }
  else {
    DAT_ffffb63c = rx8_add_u16_saturate((int)(short)DAT_ffffb63c,1);
  }
  if (DAT_ffffb646 == '\0') {
    DAT_ffffb63e = 0;
  }
  else {
    DAT_ffffb63e = rx8_add_u16_saturate((int)(short)DAT_ffffb63e,1);
  }
  return;
}


