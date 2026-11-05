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


