/* ROM address: 0x0005339a; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005131e (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_IATTimerOperation__(void)

{
  if (78.96 < vehicle_speed_ffffbbb4) {
    DAT_ffffd164 = rx8_add_u16_saturate((int)(short)DAT_ffffd164,1);
  }
  else {
    DAT_ffffd164 = 0;
  }
  if (DAT_ffffd164 < 0x2f9) {
    DAT_ffffd160 = rx8_min_float(intake_air_temperature_ffffaddc,DAT_ffffd160);
  }
  else {
    DAT_ffffd160 = intake_air_temperature_ffffaddc;
  }
  return;
}


