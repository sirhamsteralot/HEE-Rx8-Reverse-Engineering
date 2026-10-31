/* [ADDITIONAL SOURCE REVIEW]
 * can201_encode_rpm_u16 [high]: Reads 0xffffbb04, quantizes at 0.25 RPM/count into 0xffffbafc; fault produces 0xffff, normal output capped at 0xfffe. Conversion 0x2490 divides by scalar.
 * RAM 0xffffbafc can201_encoded_rpm (uint16): 0.25 RPM/count; 0xffff fault sentinel.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): can201_prepared_engine_rpm_ffffbb04; decode = raw * 0.25 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00029236; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029bde (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint can201_encode_rpm_u16(void)

{
  uint uVar1;
  
  if (DAT_ffffcdbc == '\x01') {
    can201_encoded_rpm_ffffbafc = 0xffff;
    uVar1 = 1;
  }
  else {
    uVar1 = rx8_encode_u16_affine_saturate(can201_prepared_engine_rpm_ffffbb04,0x3e800000,0);
    if ((uVar1 & 0xffff) < 0xffff) {
      can201_encoded_rpm_ffffbafc = (undefined2)uVar1;
    }
    else {
      can201_encoded_rpm_ffffbafc = 0xfffe;
    }
  }
  return uVar1;
}


