/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffb558; decode = raw * 0.003999999724 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00044dc8; body bytes: 24; decompiled */

void FUN_00044dc8(void)

{
  DAT_ffffcba8 = rx8_encode_u16_affine_saturate(DAT_ffffb558,0x3b83126e,0);
  return;
}


