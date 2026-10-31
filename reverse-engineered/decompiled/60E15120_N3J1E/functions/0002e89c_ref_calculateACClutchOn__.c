/* ROM address: 0x0002e89c; body bytes: 204; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ed54 (204 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateACClutchOn__(void)

{
  if (engine_speed_rpm_ffffb548 < 600.0) {
    if (engine_speed_rpm_ffffb548 < 400.0) {
      DAT_ffffbd94 = '\0';
    }
  }
  else {
    DAT_ffffbd94 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 7800.0) {
    if (engine_speed_rpm_ffffb548 < 7300.0) {
      DAT_ffffbd95 = '\0';
    }
  }
  else {
    DAT_ffffbd95 = '\x01';
  }
  if (DAT_ffffbd69 == '\0') {
    if ((((4 < DAT_ffffbd86) || (DAT_ffffbd94 == '\0')) || (DAT_ffffbd95 == '\x01')) ||
       ((DAT_ffffbd72 == '\x01' || (DAT_ffffbd73 == '\x01')))) {
      DAT_ffffbd68 = 0;
    }
    DAT_ffffbd84 = 0;
    DAT_ffffbd86 = rx8_add_u16_saturate((int)(short)DAT_ffffbd86,1);
  }
  else {
    if (0xd < DAT_ffffbd84) {
      DAT_ffffbd68 = 1;
    }
    DAT_ffffbd84 = rx8_add_u16_saturate((int)(short)DAT_ffffbd84,1);
    DAT_ffffbd86 = 0;
  }
  return;
}


