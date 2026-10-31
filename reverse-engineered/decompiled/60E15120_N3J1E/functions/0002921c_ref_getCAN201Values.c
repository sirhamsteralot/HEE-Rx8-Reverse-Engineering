/* ROM address: 0x0002921c; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029bc4 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getCAN201Values(void)

{
  can201_prepare_rpm_with_conditional_filter();
  can201_encode_rpm_u16();
  FUN_00029274();
  can201_encode_vehicle_speed_u16();
  FUN_000292f8();
  FUN_00029338();
  return;
}


