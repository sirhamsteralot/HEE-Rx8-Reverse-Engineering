/* [ADDITIONAL SOURCE REVIEW]
 * vehicle_moving_calc [high]: 0xffffbbb8 = 1 when vehicle_speed 0xffffbbb4 <= 4.0 (clears only at >= 5.0) — vehicle-not-moving flag; read by 0x165d6 (pool 0x166ee at 0x16626) in the idle A/C gate. Pool 0x2a490.
 */
/* ROM address: 0x0002b156; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b8aa (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void vehicle_moving_calc(void)

{
  if (4.0 < vehicle_speed_ffffbbb4) {
    if (5.0 <= vehicle_speed_ffffbbb4) {
      vehicle_not_moving_ffffbbb8 = 0;
    }
  }
  else {
    vehicle_not_moving_ffffbbb8 = 1;
  }
  return;
}


