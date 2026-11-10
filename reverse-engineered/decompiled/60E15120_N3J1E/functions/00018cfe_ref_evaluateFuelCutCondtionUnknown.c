/* [ADDITIONAL SOURCE REVIEW]
 * fuel_cut_rpm_condition [medium]: a97c = rpm >= 2500 (clear below 1700), a97d = rpm >= 1700 (clear below 1100); a964 fuel_cut_allowed = (a96a && a97c) || (a96c && a97d).
 * RAM 0xffffa964 fuel_cut_allowed (uint8): a964 = (a96a && rpm>=2500) || (a96c && rpm>=1700); set by fuel_cut_rpm_condition (0x18cfe).
 * RAM 0xffffa97c rpm_above_2500_flag (uint8): a97c = rpm >= 2500 (clear below 1700) - hysteresis.
 * RAM 0xffffa97d rpm_above_1700_flag (uint8): a97d = rpm >= 1700 (clear below 1100) - hysteresis.
 * RAM 0xffffa96a decel_cut_request_a (uint8): a96a: decel/overrun cut request input to fuel_cut_rpm_condition (0x18cfe).
 * RAM 0xffffa96c decel_cut_request_b (uint8): a96c: second request input; pairs with a96a in the a964 OR.
 */
/* ROM address: 0x00018cfe; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000198fa (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

char fuel_cut_rpm_condition(void)

{
  char cVar1;
  
  if (engine_speed_rpm_ffffb548 < 2500.0) {
    if (engine_speed_rpm_ffffb548 < 1700.0) {
      rpm_above_2500_flag_ffffa97c = '\0';
    }
  }
  else {
    rpm_above_2500_flag_ffffa97c = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 1700.0) {
    if (engine_speed_rpm_ffffb548 < 1100.0) {
      rpm_above_1700_flag_ffffa97d = '\0';
    }
  }
  else {
    rpm_above_1700_flag_ffffa97d = '\x01';
  }
  if (((decel_cut_request_a_ffffa96a == '\x01') && (cVar1 = '\x01', rpm_above_2500_flag_ffffa97c == '\x01')) ||
     ((cVar1 = decel_cut_request_b_ffffa96c, decel_cut_request_b_ffffa96c == '\x01' &&
      (cVar1 = rpm_above_1700_flag_ffffa97d, rpm_above_1700_flag_ffffa97d == '\x01')))) {
    fuel_cut_allowed_ffffa964 = 1;
  }
  else {
    fuel_cut_allowed_ffffa964 = 0;
  }
  return cVar1;
}


