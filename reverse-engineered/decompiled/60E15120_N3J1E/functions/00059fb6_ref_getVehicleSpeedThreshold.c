/* ROM address: 0x00059fb6; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005876e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getVehicleSpeedThreshold(void)

{
  if (vehicle_speed_ffffbbb4 < 3.768) {
    if (vehicle_speed_ffffbbb4 < 1.884) {
      DAT_ffffd271 = 0;
    }
  }
  else {
    DAT_ffffd271 = 1;
  }
  return;
}


