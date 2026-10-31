/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffce28; decode = raw * 0.0003924646589 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0004b534; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a6ec (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_vehicleDistanceCalc_(void)

{
  DAT_ffffce2c = vehicle_speed_ffffbbb4 / 112500.0;
  DAT_ffffce28 = DAT_ffffce28 + DAT_ffffce2c;
  if (0.100078486 <= DAT_ffffce28) {
    DAT_ffffce28 = DAT_ffffce28 + -0.09968603;
  }
  DAT_ffffce24 = rx8_encode_u8_affine_saturate(DAT_ffffce28,0x39cdc3b7,0);
  return;
}


