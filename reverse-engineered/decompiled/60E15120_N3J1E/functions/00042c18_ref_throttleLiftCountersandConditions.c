/* ROM address: 0x00042c18; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004244c (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_throttleLiftCountersandConditions(void)

{
  if (DAT_ffffca46 == '\0') {
    DAT_ffffca3f = '\0';
    DAT_ffffca44 = 0;
  }
  else if (DAT_ffffca3f < 100) {
    DAT_ffffca3f = DAT_ffffca3f + 1;
    if (((engine_speed_rpm_ffffb548 <= 700.0) || (6500.0 <= engine_speed_rpm_ffffb548)) || (inferred_coolant_temperature_ffffa98c <= 20.0)) {
      DAT_ffffca44 = 0;
    }
    else {
      DAT_ffffca44 = 1;
    }
  }
  else {
    DAT_ffffca3f = 'd';
    DAT_ffffca44 = 0;
  }
  return;
}


