/* ROM address: 0x0003194a; body bytes: 164; decompiled */

uint FUN_0003194a(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = DAT_ffffc4c0;
  if (((DAT_ffffbf7f == '\0') && (DAT_ffffc4c0 == '\x01')) && (DAT_ffffbf7e == '\0')) {
    FUN_000317a8();
    uVar2 = 1;
    DAT_ffffbf7e = '\x01';
  }
  else if ((engine_stopped_latch_ffffa41c != '\x01') || (fuel_correction_sum_ffffc644_ffffc644 <= 350.0)) {
    if ((350.0 <= fuel_correction_sum_ffffc644_ffffc644) || (DAT_ffffbf6e < 0x5267)) {
      uVar2 = (uint)secondary_air_pump_request_ffffbf6c;
      if ((uVar2 == 1) && (DAT_ffffbf70 != 0)) {
        DAT_ffffbf70 = DAT_ffffbf70 + -1;
      }
    }
    else {
      uVar2 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_ffffa98c,&PTR_CAL_table_845_0006ad94);
      DAT_ffffbf70 = (short)uVar2;
    }
  }
  else {
    DAT_ffffbf70 = 0;
    uVar2 = 1;
  }
  DAT_ffffbf7f = cVar1;
  return uVar2;
}


