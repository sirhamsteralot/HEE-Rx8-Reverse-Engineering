/* ROM address: 0x0001bf94; body bytes: 188; decompiled */

void FUN_0001bf94(void)

{
  float arg0;
  
  if (engine_load_ffffc0b4 < 2.0) {
    if (engine_load_ffffc0b4 < 1.96) {
      DAT_ffffadea = '\0';
    }
  }
  else {
    DAT_ffffadea = '\x01';
  }
  if ((engine_running_ffffa428 == '\x01') && (DAT_ffffadea == '\x01')) {
    DAT_ffffadeb = '\x01';
  }
  else if ((engine_running_ffffa428 == '\0') || ((DAT_ffffadea == '\0' && (0xe9 < DAT_ffffade8)))) {
    DAT_ffffadeb = '\0';
  }
  if (DAT_ffffadea == '\0') {
    DAT_ffffade8 = rx8_add_u16_saturate((int)(short)DAT_ffffade8,1);
  }
  else {
    DAT_ffffade8 = 0;
  }
  arg0 = rx8_first_order_filter(intake_air_temperature_ffffaddc,DAT_ffffade4,0.996,1e-05);
  if (DAT_ffffadeb != '\0') {
    arg0 = rx8_min_float(arg0,DAT_ffffade4);
  }
  DAT_ffffade4 = arg0;
  return;
}


