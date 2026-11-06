/* [ADDITIONAL SOURCE REVIEW]
 * cruise_switch_code_decode [high]: Decodes cruise switch code 0xffffbaed (values 1-6) into individual flags 0xffffcf47-0xffffcf4c; first call of cruise batch 0x2e692 (jsr at 0x2e698).
 * RAM 0xffffbaed cruise_switch_code (uint8): Cruise switch enum (1-6) decoded into flags 0xffffcf47-0xffffcf4c by 0x4c828; written near ref_calculateCruiseControlSwitchVolt 0x2be18 / 0x2c15a.
 */
/* ROM address: 0x0004c828; body bytes: 110; decompiled */

char cruise_switch_code_decode(void)

{
  DAT_ffffcf47 = cruise_switch_code_ffffbaed == '\x01';
  DAT_ffffcf48 = cruise_switch_code_ffffbaed == '\x02';
  DAT_ffffcf49 = cruise_switch_code_ffffbaed == '\x03';
  DAT_ffffcf4a = cruise_switch_code_ffffbaed == '\x04';
  DAT_ffffcf4b = cruise_switch_code_ffffbaed == '\x05';
  DAT_ffffcf4c = cruise_switch_code_ffffbaed == '\x06';
  return cruise_switch_code_ffffbaed;
}


