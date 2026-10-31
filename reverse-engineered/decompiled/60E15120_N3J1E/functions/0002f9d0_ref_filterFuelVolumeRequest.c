/* ROM address: 0x0002f9d0; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fe88 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_filterFuelVolumeRequest(void)

{
  DAT_ffffbdc0 = rx8_first_order_filter(engine_speed_rpm_ffffb548 * fuel_volume_final_ffffbeb0 * 0.12,DAT_ffffbdc0,0.75,1e-05);
  return;
}


