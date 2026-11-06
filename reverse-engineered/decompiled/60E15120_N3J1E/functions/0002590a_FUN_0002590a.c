/* [ADDITIONAL SOURCE REVIEW]
 * charging_dtc_timer_b [medium]: 0xffffb60a = 0x138 when (b654 <= 16.973 (pool 0x74980) || b658 >= 10.938 (pool 0x74984) || engine stopped || b63c < 0x3f || b646==0 || (b646==1 && b63e < 0x3f)), else counts down. Called from 0x2680e via pool 0x268b8.
 */
/* ROM address: 0x0002590a; body bytes: 226; decompiled */

void candidate_charging_dtc_timer_b(void)

{
  if (inferred_battery_voltage_ffffb590 < 10.0) {
    if (inferred_battery_voltage_ffffb590 < 9.0) {
      DAT_ffffb646 = '\0';
    }
  }
  else {
    DAT_ffffb646 = '\x01';
  }
  if (((((inferred_ram_b654_ffffb654_ffffb654 <= 16.973) || (10.938 <= system_voltage_alt_ffffb658)) || (engine_running_ffffa428 == '\0')) ||
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


