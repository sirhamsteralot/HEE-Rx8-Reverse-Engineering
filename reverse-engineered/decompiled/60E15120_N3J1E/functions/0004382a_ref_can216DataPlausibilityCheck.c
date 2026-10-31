/* ROM address: 0x0004382a; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004305e (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can216DataPlausibilityCheck(void)

{
  if ((DAT_ffffbacc <= engine_speed_rpm_ffffb548 * 0.9) || (engine_speed_rpm_ffffb548 * 1.1 <= DAT_ffffbacc)) {
    DAT_ffffca43 = '\x04';
  }
  else if (DAT_ffffca43 != '\0') {
    DAT_ffffca43 = DAT_ffffca43 + -1;
  }
  return;
}


