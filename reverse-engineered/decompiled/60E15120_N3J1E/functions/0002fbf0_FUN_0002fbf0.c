/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_request_set [medium]: 8-byte body: DAT_ffffbdd8 = 1. Called from 0x2f948.
 */
/* ROM address: 0x0002fbf0; body bytes: 8; decompiled */

void candidate_fuel_pump_request_set(void)

{
  fuel_pump_relay_request_ffffbdd8 = 1;
  return;
}


