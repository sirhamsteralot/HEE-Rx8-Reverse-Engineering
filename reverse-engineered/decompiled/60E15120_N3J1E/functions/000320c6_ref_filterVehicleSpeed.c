/* ROM address: 0x000320c6; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003256e (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_filterVehicleSpeed(void)

{
  DAT_ffffbfa0 = rx8_first_order_filter(DAT_ffffbfa0,vehicle_speed_ffffbbb4,0.7,1e-05);
  return;
}


