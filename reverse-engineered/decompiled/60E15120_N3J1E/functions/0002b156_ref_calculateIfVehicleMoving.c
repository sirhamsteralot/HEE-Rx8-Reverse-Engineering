/* ROM address: 0x0002b156; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b8aa (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateIfVehicleMoving(void)

{
  if (4.0 < vehicle_speed_ffffbbb4) {
    if (5.0 <= vehicle_speed_ffffbbb4) {
      DAT_ffffbbb8 = 0;
    }
  }
  else {
    DAT_ffffbbb8 = 1;
  }
  return;
}


