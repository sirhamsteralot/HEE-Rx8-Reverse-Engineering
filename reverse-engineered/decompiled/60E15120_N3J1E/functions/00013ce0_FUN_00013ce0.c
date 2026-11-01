/* ROM address: 0x00013ce0; body bytes: 128; decompiled */

uint FUN_00013ce0(void)

{
  uint uVar1;
  
  if (engine_speed_rpm_ffffb548 < 8000.0) {
    if (engine_speed_rpm_ffffb548 < 7800.0) {
      DAT_ffffa776 = '\0';
    }
  }
  else {
    DAT_ffffa776 = '\x01';
  }
  uVar1 = 1;
  if (((DAT_ffffa776 == '\x01') || (uVar1 = (uint)cranking_active_ffffaa62_ffffaa62, uVar1 == 1)) || (engine_load_ffffc0b4 < 0.1)
     ) {
    DAT_ffffa760 = 0;
  }
  else {
    uVar1 = rx8_is_outside_tolerance_band(coolant_timing_derate_leading_ffffa750,0,0x3727c5ac);
    if (((uVar1 & 0xff) == 0) && (DAT_ffffa760 != 0)) {
      DAT_ffffa760 = DAT_ffffa760 + -1;
    }
  }
  return uVar1;
}


